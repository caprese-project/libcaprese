#include <libcaprese/attribute.h>
#include <libcaprese/ipc.h>
#include <libcaprese/syscall.h>
#include <stdlib.h>
#include <string.h>

static uintptr_t round_up(uintptr_t value, uintptr_t alignment) {
  return (value + alignment - 1) / alignment * alignment;
}

message_t* new_ipc_message(uint32_t payload_capacity) {
  payload_capacity = round_up(payload_capacity, sizeof(uintptr_t));

  message_t* msg = (message_t*)malloc(sizeof(message_t) + payload_capacity);
  LIBCAPRESE_IF_UNLIKELY (msg == NULL) {
    return NULL;
  }

  msg->header.msg_type         = MSG_TYPE_IPC;
  msg->header.sender_id        = 0;
  msg->header.receiver_id      = 0;
  msg->header.payload_length   = 0;
  msg->header.payload_capacity = payload_capacity;
  msg->header.data_type_map[0] = 0;
  msg->header.data_type_map[1] = 0;

  return msg;
}

void destroy_ipc_message(message_t* msg) {
  uint32_t length = msg->header.payload_length / sizeof(uintptr_t);
  if (length > 128) {
    length = 128;
  }

  for (uint32_t i = 0; i < length; ++i) {
    if (is_ipc_cap(msg, i)) {
      cap_t cap = get_ipc_cap(msg, i);
      if (!is_ipc_cap_delegate(msg, i)) {
        sys_cap_destroy(cap);
      }
    }
  }

  msg->header.payload_length   = 0;
  msg->header.data_type_map[0] = 0;
  msg->header.data_type_map[1] = 0;
}

void delete_ipc_message(message_t* msg) {
  destroy_ipc_message(msg);
  free(msg);
}

bool set_ipc_data(message_t* msg, uint32_t index, uintptr_t data) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_capacity / sizeof(uintptr_t)) {
    return false;
  }

  msg->payload[index] = data;

  if (index < 128) {
    msg->header.data_type_map[index / 64] &= ~(1ull << (index % 64));
  }

  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    msg->header.payload_length = (index + 1) * sizeof(uintptr_t);
  }

  return true;
}

bool set_ipc_cap(message_t* msg, uint32_t index, cap_t cap, bool delegate) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_capacity / sizeof(uintptr_t)) {
    return false;
  }

  LIBCAPRESE_IF_UNLIKELY (index >= 128) {
    return false;
  }

  msg->payload[index] = cap | ((delegate ? 1ull : 0) << (sizeof(uintptr_t) * 8 - 1));
  msg->header.data_type_map[index / 64] |= (1ull << (index % 64));

  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    msg->header.payload_length = (index + 1) * sizeof(uintptr_t);
  }

  return true;
}

bool set_ipc_data_array(message_t* msg, uint32_t index, const void* data, size_t size) {
  size_t first = index;
  size_t last  = first + round_up(size, sizeof(uintptr_t)) / sizeof(uintptr_t);

  LIBCAPRESE_IF_UNLIKELY (last > msg->header.payload_capacity / sizeof(uintptr_t)) {
    return false;
  }

  memcpy(&msg->payload[first], data, size);

  for (size_t i = first; i < last && i < 128; ++i) {
    msg->header.data_type_map[i / 64] &= ~(1ull << (i % 64));
  }

  if (last > msg->header.payload_length / sizeof(uintptr_t)) {
    msg->header.payload_length = last * sizeof(uintptr_t);
  }

  return true;
}

uintptr_t get_ipc_data(message_t* msg, uint32_t index) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return 0;
  }

  LIBCAPRESE_IF_UNLIKELY (is_ipc_cap(msg, index)) {
    return 0;
  }

  return msg->payload[index];
}

cap_t get_ipc_cap(message_t* msg, uint32_t index) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return 0;
  }

  LIBCAPRESE_IF_UNLIKELY (!is_ipc_cap(msg, index)) {
    return 0;
  }

  return msg->payload[index] & ~(1ull << (sizeof(uintptr_t) * 8 - 1));
}

void* get_ipc_data_ptr(message_t* msg, uint32_t index) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return NULL;
  }

  LIBCAPRESE_IF_UNLIKELY (is_ipc_cap(msg, index)) {
    return NULL;
  }

  return &msg->payload[index];
}

cap_t move_ipc_cap(message_t* msg, uint32_t index) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return 0;
  }

  LIBCAPRESE_IF_UNLIKELY (!is_ipc_cap(msg, index)) {
    return 0;
  }

  cap_t cap = msg->payload[index] & ~(1ull << (sizeof(uintptr_t) * 8 - 1));

  msg->payload[index] = 0;
  msg->header.data_type_map[index / 64] &= ~(1ull << (index % 64));

  return cap;
}

bool is_ipc_cap(message_t* msg, uint32_t index) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return false;
  }

  LIBCAPRESE_IF_UNLIKELY (index >= 128) {
    return false;
  }

  return (msg->header.data_type_map[index / 64] & (1ull << (index % 64))) != 0;
}

bool is_ipc_cap_delegate(message_t* msg, uint32_t index) {
  LIBCAPRESE_IF_UNLIKELY (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return false;
  }

  LIBCAPRESE_IF_UNLIKELY (index >= 128) {
    return false;
  }

  return (msg->payload[index] & (1ull << (sizeof(uintptr_t) * 8 - 1))) != 0;
}

size_t get_message_size(message_t* msg) {
  return sizeof(message_t) + msg->header.payload_length;
}
