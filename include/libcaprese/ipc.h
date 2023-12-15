#ifndef LIBCAPRESE_IPC_H_
#define LIBCAPRESE_IPC_H_

#include <libcaprese/cap.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef struct {
    size_t    cap_part_length;
    size_t    data_part_length;
    uintptr_t data[126];
  } message_buffer_t;

  static inline uintptr_t msg_buf_delegate(cap_t cap) {
    return (uintptr_t)cap | ((uintptr_t)1 << (sizeof(uintptr_t) * 8 - 1));
  }

  static inline uintptr_t msg_buf_transfer(cap_t cap) {
    return (uintptr_t)cap;
  }

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_IPC_H_
