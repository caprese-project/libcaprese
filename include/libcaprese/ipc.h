#ifndef LIBCAPRESE_IPC_H_
#define LIBCAPRESE_IPC_H_

#include <libcaprese/cap.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  enum message_type {
    MSG_TYPE_IPC  = 1,
    MSG_TYPE_KILL = 2,
  };

  struct message_header {
    enum message_type msg_type;
    uint32_t          sender_id;
    uint32_t          receiver_id;
    uint32_t          payload_length;
    uint32_t          payload_capacity;
    uint64_t          data_type_map[2];
  };

  typedef struct message {
    struct message_header header;
    uintptr_t             payload[];
  } message_t;

  message_t* new_ipc_message(uint32_t payload_capacity);
  void       destroy_ipc_message(message_t* msg);
  void       delete_ipc_message(message_t* msg);
  bool       set_ipc_data(message_t* msg, uint32_t index, uintptr_t data);
  bool       set_ipc_cap(message_t* msg, uint32_t index, cap_t cap, bool delegate);
  bool       set_ipc_data_array(message_t* msg, uint32_t index, const void* data, size_t size);
  bool       set_ipc_data_str(message_t* msg, uint32_t index, const char* str);
  bool       set_ipc_data_strn(message_t* msg, uint32_t index, const char* str, size_t size);
  uintptr_t  get_ipc_data(message_t* msg, uint32_t index);
  cap_t      get_ipc_cap(message_t* msg, uint32_t index);
  void*      get_ipc_data_ptr(message_t* msg, uint32_t index);
  cap_t      move_ipc_cap(message_t* msg, uint32_t index);
  bool       is_ipc_cap(message_t* msg, uint32_t index);
  bool       is_ipc_cap_delegate(message_t* msg, uint32_t index);
  size_t     get_message_size(message_t* msg);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_IPC_H_
