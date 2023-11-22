#ifndef LIBCAPRESE_SYSCALL_H_
#define LIBCAPRESE_SYSCALL_H_

#include <assert.h>
#include <libcaprese/cap.h>
#include <stdbool.h>
#include <stddef.h>

#define SYSNS_SYSTEM         (0 << 16)
#define SYSNS_ARCH           (1 << 16)
#define SYSNS_CAP            (2 << 16)
#define SYSNS_MEM_CAP        (3 << 16)
#define SYSNS_TASK_CAP       (4 << 16)
#define SYSNS_ENDPOINT_CAP   (5 << 16)
#define SYSNS_PAGE_TABLE_CAP (6 << 16)
#define SYSNS_VIRT_PAGE_CAP  (7 << 16)

#define SYS_SYSTEM_NULL               (SYSNS_SYSTEM | 0)
#define SYS_SYSTEM_CORE_ID            (SYSNS_SYSTEM | 1)
#define SYS_SYSTEM_PAGE_SIZE          (SYSNS_SYSTEM | 2)
#define SYS_SYSTEM_USER_SPACE_START   (SYSNS_SYSTEM | 3)
#define SYS_SYSTEM_USER_SPACE_END     (SYSNS_SYSTEM | 4)
#define SYS_SYSTEM_CAPS_PER_CAP_SPACE (SYSNS_SYSTEM | 5)
#define SYS_SYSTEM_YIELD              (SYSNS_SYSTEM | 6)

#define SYS_CAP_TYPE   (SYSNS_CAP | 0)
#define SYS_CAP_COPY   (SYSNS_CAP | 1)
#define SYS_CAP_REVOKE (SYSNS_CAP | 2)

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
#define SYS_TASK_CAP_DELEGATE_CAP (SYSNS_TASK_CAP | 11)

#define SYS_PAGE_TABLE_CAP_MAPPED      (SYSNS_PAGE_TABLE_CAP | 0)
#define SYS_PAGE_TABLE_CAP_LEVEL       (SYSNS_PAGE_TABLE_CAP | 1)
#define SYS_PAGE_TABLE_CAP_MAP_TABLE   (SYSNS_PAGE_TABLE_CAP | 2)
#define SYS_PAGE_TABLE_CAP_UNMAP_TABLE (SYSNS_PAGE_TABLE_CAP | 3)
#define SYS_PAGE_TABLE_CAP_MAP_PAGE    (SYSNS_PAGE_TABLE_CAP | 4)
#define SYS_PAGE_TABLE_CAP_UNMAP_PAGE  (SYSNS_PAGE_TABLE_CAP | 5)
#define SYS_PAGE_TABLE_CAP_REMAP_PAGE  (SYSNS_PAGE_TABLE_CAP | 6)

#define SYS_VIRT_PAGE_CAP_MAPPED     (SYSNS_VIRT_PAGE_CAP | 0)
#define SYS_VIRT_PAGE_CAP_READABLE   (SYSNS_VIRT_PAGE_CAP | 1)
#define SYS_VIRT_PAGE_CAP_WRITABLE   (SYSNS_VIRT_PAGE_CAP | 2)
#define SYS_VIRT_PAGE_CAP_EXECUTABLE (SYSNS_VIRT_PAGE_CAP | 3)
#define SYS_VIRT_PAGE_CAP_LEVEL      (SYSNS_VIRT_PAGE_CAP | 4)
#define SYS_VIRT_PAGE_CAP_PHYS_ADDR  (SYSNS_VIRT_PAGE_CAP | 5)
#define SYS_VIRT_PAGE_CAP_VIRT_ADDR  (SYSNS_VIRT_PAGE_CAP | 6)

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

  static inline sysret_t sys_system_caps_per_cap_space() {
    return syscall0(SYS_SYSTEM_CAPS_PER_CAP_SPACE);
  }

  static inline sysret_t sys_system_yield() {
    return syscall0(SYS_SYSTEM_YIELD);
  }

  static inline sysret_t sys_cap_type(cap_t cap) {
    return syscall1(cap, SYS_CAP_TYPE);
  }

  static inline sysret_t sys_cap_copy(cap_t cap, uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5) {
    return syscall7(cap, arg0, arg1, arg2, arg3, arg4, arg5, SYS_CAP_COPY);
  }

  static inline sysret_t sys_cap_revoke(cap_t cap) {
    return syscall1(cap, SYS_CAP_REVOKE);
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

  static inline sysret_t sys_mem_cap_create_page_table_object(mem_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_PAGE_TABLE, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_mem_cap_create_virt_page_object(mem_cap_t cap, uintptr_t level) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_VIRT_PAGE, level, 0, 0, 0, 0);
  }

  static inline sysret_t sys_mem_cap_create_cap_space_object(mem_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_CAP_SPACE, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_task_cap_kill(task_cap_t cap, int exit_status) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    return syscall2(cap, exit_status, SYS_TASK_CAP_KILL);
  }

  static inline sysret_t sys_task_cap_switch(task_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_SWITCH);
  }

  static inline sysret_t sys_task_cap_suspend(task_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_SUSPEND);
  }

  static inline sysret_t sys_task_cap_resume(task_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_RESUME);
  }

  static inline sysret_t sys_task_cap_get_reg(task_cap_t cap, uintptr_t reg) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    return syscall2(cap, reg, SYS_TASK_CAP_GET_REG);
  }

  static inline sysret_t sys_task_cap_set_reg(task_cap_t cap, uintptr_t reg, uintptr_t val) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    return syscall3(cap, reg, val, SYS_TASK_CAP_SET_REG);
  }

  static inline sysret_t sys_task_cap_transfer_cap(task_cap_t cap, cap_t src) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    assert(sys_cap_type(src).result != CAP_NULL);
    return syscall2(cap, src, SYS_TASK_CAP_TRANSFER_CAP);
  }

  static inline sysret_t sys_task_cap_delegate_cap(task_cap_t cap, cap_t src) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    assert(sys_cap_type(src).result != CAP_NULL);
    return syscall2(cap, src, SYS_TASK_CAP_DELEGATE_CAP);
  }

  static inline sysret_t sys_task_cap_copy(task_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_TASK);
    return sys_cap_copy(cap, 0, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_page_table_cap_mapped(page_table_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_PAGE_TABLE);
    return syscall1(cap, SYS_PAGE_TABLE_CAP_MAPPED);
  }

  static inline sysret_t sys_page_table_cap_level(page_table_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_PAGE_TABLE);
    return syscall1(cap, SYS_PAGE_TABLE_CAP_LEVEL);
  }

  static inline sysret_t sys_page_table_cap_map_table(page_table_cap_t cap, uintptr_t index, page_table_cap_t child) {
    assert(sys_cap_type(cap).result == CAP_PAGE_TABLE);
    assert(sys_cap_type(child).result == CAP_PAGE_TABLE);
    assert(sys_page_table_cap_level(cap).result > KILO_PAGE);
    return syscall3(cap, index, child, SYS_PAGE_TABLE_CAP_MAP_TABLE);
  }

  static inline sysret_t sys_page_table_cap_unmap_table(page_table_cap_t cap, uintptr_t index, page_table_cap_t child) {
    assert(sys_cap_type(cap).result == CAP_PAGE_TABLE);
    assert(sys_cap_type(child).result == CAP_PAGE_TABLE);
    assert(sys_page_table_cap_level(cap).result > KILO_PAGE);
    return syscall3(cap, index, child, SYS_PAGE_TABLE_CAP_UNMAP_TABLE);
  }

  static inline sysret_t sys_page_table_cap_map_page(page_table_cap_t cap, uintptr_t index, bool readable, bool writable, bool executable, virt_page_cap_t child) {
    assert(sys_cap_type(cap).result == CAP_PAGE_TABLE);
    assert(sys_cap_type(child).result == CAP_VIRT_PAGE);
    return syscall6(cap, index, readable, writable, executable, child, SYS_PAGE_TABLE_CAP_MAP_PAGE);
  }

  static inline sysret_t sys_page_table_cap_unmap_page(page_table_cap_t cap, uintptr_t index, virt_page_cap_t child) {
    assert(sys_cap_type(cap).result == CAP_PAGE_TABLE);
    assert(sys_cap_type(child).result == CAP_VIRT_PAGE);
    return syscall3(cap, index, child, SYS_PAGE_TABLE_CAP_UNMAP_PAGE);
  }

  static inline sysret_t sys_page_table_cap_remap_page(page_table_cap_t cap, uintptr_t index, bool readable, bool writable, bool executable, virt_page_cap_t child, page_table_cap_t old_parent) {
    assert(sys_cap_type(cap).result == CAP_PAGE_TABLE);
    assert(sys_cap_type(child).result == CAP_VIRT_PAGE);
    assert(sys_cap_type(old_parent).result == CAP_PAGE_TABLE);
    return syscall7(cap, index, readable, writable, executable, child, old_parent, SYS_PAGE_TABLE_CAP_REMAP_PAGE);
  }

  static inline sysret_t sys_virt_page_cap_mapped(virt_page_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_MAPPED);
  }

  static inline sysret_t sys_virt_page_cap_readable(virt_page_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_READABLE);
  }

  static inline sysret_t sys_virt_page_cap_writable(virt_page_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_WRITABLE);
  }

  static inline sysret_t sys_virt_page_cap_executable(virt_page_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_EXECUTABLE);
  }

  static inline sysret_t sys_virt_page_cap_level(virt_page_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_LEVEL);
  }

  static inline sysret_t sys_virt_page_cap_phys_addr(virt_page_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_PHYS_ADDR);
  }

  static inline sysret_t sys_virt_page_cap_virt_addr(virt_page_cap_t cap) {
    assert(sys_cap_type(cap).result == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_VIRT_ADDR);
  }

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined(__riscv) && __riscv_xlen == 64
#include <libcaprese/arch/rv64/syscall_rv64.h>
#endif

#endif // LIBCAPRESE_SYSCALL_H_
