#ifndef LIBCAPRESE_ROOT_BOOT_INFO_H_
#define LIBCAPRESE_ROOT_BOOT_INFO_H_

#include <libcaprese/cap.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef struct {
    task_cap_t       root_task_cap;
    cap_space_cap_t  first_cap_space_cap;
    page_table_cap_t root_page_table_cap;
    page_table_cap_t cap_space_page_table_caps[3];
    page_table_cap_t page_table_caps[3];
    page_table_cap_t stack_page_table_caps[3];
    size_t           num_mem_caps;
    mem_cap_t        mem_caps[];
  } root_boot_info_t;

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_ROOT_BOOT_INFO_H_
