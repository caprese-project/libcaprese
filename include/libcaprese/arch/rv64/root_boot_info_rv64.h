#ifndef LIBCAPRESE_ARCH_RV64_ROOT_BOOT_INFO_RV64_H_
#define LIBCAPRESE_ARCH_RV64_ROOT_BOOT_INFO_RV64_H_

#include <libcaprese/cap.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  struct arch_root_boot_info {
    uintptr_t       dtb_start;
    uintptr_t       dtb_end;
    virt_page_cap_t dtb_virt_page_cap;
  };

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_ARCH_RV64_ROOT_BOOT_INFO_RV64_H_
