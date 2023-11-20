#ifndef LIBCAPRESE_SYSCALL_H_
#define LIBCAPRESE_SYSCALL_H_

#include <assert.h>
#include <libcaprese/cap.h>
#include <stdbool.h>
#include <stddef.h>

#define SYSNS_SYSTEM   (0 << 16)
#define SYSNS_ARCH     (1 << 16)
#define SYSNS_CAP      (2 << 16)
#define SYSNS_MEM_CAP  (3 << 16)
#define SYSNS_TASK_CAP (4 << 16)

#define SYS_SYSTEM_NULL             (SYSNS_SYSTEM | 0)
#define SYS_SYSTEM_CORE_ID          (SYSNS_SYSTEM | 1)
#define SYS_SYSTEM_PAGE_SIZE        (SYSNS_SYSTEM | 2)
#define SYS_SYSTEM_USER_SPACE_START (SYSNS_SYSTEM | 3)
#define SYS_SYSTEM_USER_SPACE_END   (SYSNS_SYSTEM | 4)

#if defined(__riscv) && __riscv_xlen == 64
#include <libcaprese/arch/rv64/syscall_rv64.h>
#endif

#define SYS_CAP_TYPE (SYSNS_CAP | 0)

#define SYS_MEM_CAP_DEVICE        (SYSNS_MEM_CAP | 0)
#define SYS_MEM_CAP_READABLE      (SYSNS_MEM_CAP | 1)
#define SYS_MEM_CAP_WRITABLE      (SYSNS_MEM_CAP | 2)
#define SYS_MEM_CAP_EXECUTABLE    (SYSNS_MEM_CAP | 3)
#define SYS_MEM_CAP_PHYS_ADDR     (SYSNS_MEM_CAP | 4)
#define SYS_MEM_CAP_SIZE_BIT      (SYSNS_MEM_CAP | 5)
#define SYS_MEM_CAP_USED_SIZE     (SYSNS_MEM_CAP | 6)
#define SYS_MEM_CAP_CREATE_OBJECT (SYSNS_MEM_CAP | 7)

#define SYS_TASK_CAP_KILLABLE     (SYSNS_TASK_CAP | 0)
#define SYS_TASK_CAP_SWITCHABLE   (SYSNS_TASK_CAP | 1)
#define SYS_TASK_CAP_SUSPENDABLE  (SYSNS_TASK_CAP | 2)
#define SYS_TASK_CAP_RESUMABLE    (SYSNS_TASK_CAP | 3)
#define SYS_TASK_CAP_KILL         (SYSNS_TASK_CAP | 4)
#define SYS_TASK_CAP_SWITCH       (SYSNS_TASK_CAP | 5)
#define SYS_TASK_CAP_SUSPEND      (SYSNS_TASK_CAP | 6)
#define SYS_TASK_CAP_RESUME       (SYSNS_TASK_CAP | 7)
#define SYS_TASK_CAP_GET_REG      (SYSNS_TASK_CAP | 8)
#define SYS_TASK_CAP_SET_REG      (SYSNS_TASK_CAP | 9)
#define SYS_TASK_CAP_TRANSFER_CAP (SYSNS_TASK_CAP | 10)

#define SYS_S_OK               (0)
#define SYS_E_INVALID_ARGUMENT (-1)
#define SYS_E_INVALID_CODE     (-2)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef struct {
    uintptr_t result;
    intptr_t  error;
  } sysret_t;

  sysret_t syscall0(uintptr_t code);
  sysret_t syscall1(uintptr_t arg0, uintptr_t code);
  sysret_t syscall2(uintptr_t arg0, uintptr_t arg1, uintptr_t code);
  sysret_t syscall3(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t code);
  sysret_t syscall4(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t code);
  sysret_t syscall5(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t code);
  sysret_t syscall6(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t code);
  sysret_t syscall7(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t arg6, uintptr_t code);

  uintptr_t unwrap_sysret(sysret_t sysret);

  static inline sysret_t sys_system_null() {
    return syscall0(SYS_SYSTEM_NULL);
  }

  static inline sysret_t sys_system_core_id() {
    return syscall0(SYS_SYSTEM_CORE_ID);
  }

  static inline sysret_t sys_system_page_size() {
    return syscall0(SYS_SYSTEM_PAGE_SIZE);
  }

  static inline sysret_t sys_system_user_space_start() {
    return syscall0(SYS_SYSTEM_USER_SPACE_START);
  }

  static inline sysret_t sys_system_user_space_end() {
    return syscall0(SYS_SYSTEM_USER_SPACE_END);
  }

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

#endif // LIBCAPRESE_SYSCALL_H_
