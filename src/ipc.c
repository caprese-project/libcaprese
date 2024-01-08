#include <libcaprese/ipc.h>
#include <libcaprese/syscall.h>
#include <stdlib.h>

message_t* new_ipc_message(uint32_t payload_length) {
  payload_length = (payload_length + sizeof(uintptr_t) - 1) / sizeof(uintptr_t) * sizeof(uintptr_t);

  message_t* msg = (message_t*)malloc(sizeof(message_t) + payload_length);
  if (msg == NULL) {
    return NULL;
  }

  msg->header.msg_type         = MSG_TYPE_IPC;
  msg->header.sender_id        = 0;
  msg->header.receiver_id      = 0;
  msg->header.payload_length   = payload_length;
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

  msg->header.data_type_map[0] = 0;
  msg->header.data_type_map[1] = 0;
}

void delete_ipc_message(message_t* msg) {
  destroy_ipc_message(msg);
  free(msg);
}

bool set_ipc_data(message_t* msg, uint32_t index, uintptr_t data) {
  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return false;
  }

  msg->payload[index] = data;

  return true;
}

bool set_ipc_cap(message_t* msg, uint32_t index, cap_t cap, bool delegate) {
  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return false;
  }

  if (index >= 128) {
    return false;
  }

  msg->payload[index] = cap | ((delegate ? 1ull : 0) << (sizeof(uintptr_t) * 8 - 1));
  msg->header.data_type_map[index / 64] |= (1ull << (index % 64));

  return true;
}

uintptr_t get_ipc_data(message_t* msg, uint32_t index) {
  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return 0;
  }

  if (is_ipc_cap(msg, index)) {
    return 0;
  }

  return msg->payload[index];
}

cap_t get_ipc_cap(message_t* msg, uint32_t index) {
  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return 0;
  }

  if (!is_ipc_cap(msg, index)) {
    return 0;
  }

  return msg->payload[index] & ~(1ull << (sizeof(uintptr_t) * 8 - 1));
}

void* get_ipc_data_ptr(message_t* msg, uint32_t index) {
  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return NULL;
  }

  if (is_ipc_cap(msg, index)) {
    return NULL;
  }

  return &msg->payload[index];
}

bool is_ipc_cap(message_t* msg, uint32_t index) {
  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return false;
  }

  if (index >= 128) {
    return false;
  }

  return (msg->header.data_type_map[index / 64] & (1ull << (index % 64))) != 0;
}

bool is_ipc_cap_delegate(message_t* msg, uint32_t index) {
  if (index >= msg->header.payload_length / sizeof(uintptr_t)) {
    return false;
  }

  if (index >= 128) {
    return false;
  }

  return (msg->payload[index] & (1ull << (sizeof(uintptr_t) * 8 - 1))) != 0;
}

size_t get_message_size(message_t* msg) {
  return sizeof(message_t) + msg->header.payload_length;
}
