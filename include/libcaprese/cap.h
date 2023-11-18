#ifndef LIBCAPRESE_CAP_H_
#define LIBCAPRESE_CAP_H_

#include <libcaprese/syscall.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef uintptr_t cap_t;
  typedef cap_t     memcap_t;
  typedef cap_t     taskcap_t;

  typedef enum {
    CAP_NULL    = 0,
    CAP_MEM     = 1,
    CAP_TASK    = 2,
    CAP_UNKNOWN = -1,
  } cap_type_t;

  static inline sysret_t sys_cap_type(cap_t cap) {
    return syscall1(cap, SYS_CAP_TYPE);
  }

  static inline sysret_t sys_cap_size(cap_type_t cap_type) {
    return syscall1(cap_type, SYS_CAP_SIZE);
  }

  static inline sysret_t sys_memcap_device(memcap_t cap) {
    return syscall1(cap, SYS_MEMCAP_DEVICE);
  }

  static inline sysret_t sys_memcap_readable(memcap_t cap) {
    return syscall1(cap, SYS_MEMCAP_READABLE);
  }

  static inline sysret_t sys_memcap_writable(memcap_t cap) {
    return syscall1(cap, SYS_MEMCAP_WRITABLE);
  }

  static inline sysret_t sys_memcap_executable(memcap_t cap) {
    return syscall1(cap, SYS_MEMCAP_EXECUTABLE);
  }

  static inline sysret_t sys_memcap_phys_addr(memcap_t cap) {
    return syscall1(cap, SYS_MEMCAP_PHYS_ADDR);
  }

  static inline sysret_t sys_memcap_size_bit(memcap_t cap) {
    return syscall1(cap, SYS_MEMCAP_SIZE_BIT);
  }

  static inline sysret_t sys_memcap_used_size(memcap_t cap) {
    return syscall1(cap, SYS_MEMCAP_USED_SIZE);
  }

  static inline sysret_t sys_memcap_create_object(memcap_t cap, cap_type_t cap_type) {
    return syscall2(cap, cap_type, SYS_MEMCAP_CREATE_OBJECT);
  }

  static inline sysret_t sys_taskcap_kill(taskcap_t cap) {
    return syscall1(cap, SYS_TASKCAP_KILL);
  }

  static inline sysret_t sys_taskcap_switch(taskcap_t cap) {
    return syscall1(cap, SYS_TASKCAP_SWITCH);
  }

  static inline sysret_t sys_taskcap_suspend(taskcap_t cap) {
    return syscall1(cap, SYS_TASKCAP_SUSPEND);
  }

  static inline sysret_t sys_taskcap_resume(taskcap_t cap) {
    return syscall1(cap, SYS_TASKCAP_RESUME);
  }

  static inline sysret_t sys_taskcap_get_reg(taskcap_t cap, uintptr_t reg) {
    return syscall2(cap, reg, SYS_TASKCAP_GET_REG);
  }

  static inline sysret_t sys_taskcap_set_reg(taskcap_t cap, uintptr_t reg, uintptr_t val) {
    return syscall3(cap, reg, val, SYS_TASKCAP_SET_REG);
  }

  static inline sysret_t sys_taskcap_transfer_cap(taskcap_t cap, cap_t src) {
    return syscall2(cap, src, SYS_TASKCAP_TRANSFER_CAP);
  }

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_CAP_H_
