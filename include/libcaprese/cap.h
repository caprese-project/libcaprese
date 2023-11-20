#ifndef LIBCAPRESE_CAP_H_
#define LIBCAPRESE_CAP_H_

#include <libcaprese/syscall.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef uintptr_t cap_t;
  typedef cap_t     mem_cap_t;
  typedef cap_t     task_cap_t;
  typedef cap_t     endpoint_cap_t;
  typedef cap_t     page_table_cap_t;
  typedef cap_t     virt_page_cap_t;
  typedef cap_t     cap_space_cap_t;

  typedef enum {
    CAP_NULL       = 0,
    CAP_MEM        = 1,
    CAP_TASK       = 2,
    CAP_ENDPOINT   = 3,
    CAP_PAGE_TABLE = 4,
    CAP_VIRT_PAGE  = 5,
    CAP_CAP_SPACE  = 6,
    CAP_ZOMBIE     = 7,
    CAP_UNKNOWN    = -1,
  } cap_type_t;

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_CAP_H_
