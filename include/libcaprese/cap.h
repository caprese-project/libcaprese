#ifndef LIBCAPRESE_CAP_H_
#define LIBCAPRESE_CAP_H_

#include <assert.h>
#include <libcaprese/syscall.h>
#include <stdbool.h>
#include <stddef.h>
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

  static inline sysret_t sys_cap_type(cap_t cap) {
    return syscall1(cap, SYS_CAP_TYPE);
  }

  static inline sysret_t sys_mem_cap_device(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_DEVICE);
  }

  static inline sysret_t sys_mem_cap_readable(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_READABLE);
  }

  static inline sysret_t sys_mem_cap_writable(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_WRITABLE);
  }

  static inline sysret_t sys_mem_cap_executable(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_EXECUTABLE);
  }

  static inline sysret_t sys_mem_cap_phys_addr(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_PHYS_ADDR);
  }

  static inline sysret_t sys_mem_cap_size_bit(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_SIZE_BIT);
  }

  static inline sysret_t sys_mem_cap_used_size(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_USED_SIZE);
  }

  static inline sysret_t sys_mem_cap_create_object(mem_cap_t cap, cap_type_t cap_type, uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4) {
    return syscall7(cap, cap_type, arg0, arg1, arg2, arg3, arg4, SYS_MEM_CAP_CREATE_OBJECT);
  }

  static inline sysret_t sys_mem_cap_create_memory_object(mem_cap_t cap, bool readable, bool writable, bool executable, size_t size, size_t alignment) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_MEM, readable, writable, executable, size, alignment);
  }

  static inline sysret_t sys_mem_cap_create_task_object(mem_cap_t        cap,
                                                        cap_space_cap_t  cap_space_cap,
                                                        page_table_cap_t root_page_table,
                                                        page_table_cap_t cap_space_page_table0,
                                                        page_table_cap_t,
                                                        page_table_cap_t cap_space_page_table1,
                                                        page_table_cap_t cap_space_page_table2) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_TASK, cap_space_cap, root_page_table, cap_space_page_table0, cap_space_page_table1, cap_space_page_table2);
  }

  static inline sysret_t sys_mem_cap_create_page_table_object(mem_cap_t cap, uintptr_t level) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_PAGE_TABLE, level, 0, 0, 0, 0);
  }

  static inline sysret_t sys_mem_cap_create_virt_page_object(mem_cap_t cap, bool readable, bool writable, bool executable, uintptr_t level) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_VIRT_PAGE, readable, writable, executable, level, 0);
  }

  static inline sysret_t sys_mem_cap_create_cap_space_object(mem_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_CAP_SPACE, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_task_cap_kill(task_cap_t cap) {
    return syscall1(cap, SYS_TASK_CAP_KILL);
  }

  static inline sysret_t sys_task_cap_switch(task_cap_t cap) {
    return syscall1(cap, SYS_TASK_CAP_SWITCH);
  }

  static inline sysret_t sys_task_cap_suspend(task_cap_t cap) {
    return syscall1(cap, SYS_TASK_CAP_SUSPEND);
  }

  static inline sysret_t sys_task_cap_resume(task_cap_t cap) {
    return syscall1(cap, SYS_TASK_CAP_RESUME);
  }

  static inline sysret_t sys_task_cap_get_reg(task_cap_t cap, uintptr_t reg) {
    return syscall2(cap, reg, SYS_TASK_CAP_GET_REG);
  }

  static inline sysret_t sys_task_cap_set_reg(task_cap_t cap, uintptr_t reg, uintptr_t val) {
    return syscall3(cap, reg, val, SYS_TASK_CAP_SET_REG);
  }

  static inline sysret_t sys_task_cap_transfer_cap(task_cap_t cap, cap_t src) {
    return syscall2(cap, src, SYS_TASK_CAP_TRANSFER_CAP);
  }

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_CAP_H_
