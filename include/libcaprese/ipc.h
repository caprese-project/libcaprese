#ifndef LIBCAPRESE_IPC_H_
#define LIBCAPRESE_IPC_H_

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

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_IPC_H_
