#ifndef LIBCAPRESE_ROOT_BOOT_INFO_H_
#define LIBCAPRESE_ROOT_BOOT_INFO_H_

#include <libcaprese/cap.h>
#include <stddef.h>

#if defined(__riscv) && __riscv_xlen == 64
#include <libcaprese/arch/rv64/root_boot_info_rv64.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef struct {
    struct arch_root_boot_info arch_info;
    task_cap_t                 root_task_cap;
    page_table_cap_t           root_page_table_cap;
    page_table_cap_t           cap_space_page_table_caps[3];
    page_table_cap_t           page_table_caps[3];
    page_table_cap_t           stack_page_table_caps[3];
    size_t                     num_mem_caps;
    size_t                     mem_caps_offset;
    size_t                     num_virt_page_caps;
    size_t                     virt_page_caps_offset;
    uintptr_t                  root_task_end_address;
    cap_t                      caps[];
  } root_boot_info_t;

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_ROOT_BOOT_INFO_H_
