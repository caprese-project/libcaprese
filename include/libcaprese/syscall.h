#ifndef LIBCAPRESE_SYSCALL_H_
#define LIBCAPRESE_SYSCALL_H_

#include <assert.h>
#include <libcaprese/cap.h>
#include <libcaprese/ipc.h>
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
#define SYSNS_ID_CAP         (8 << 16)

#define SYS_SYSTEM_NULL               (SYSNS_SYSTEM | 0)
#define SYS_SYSTEM_CORE_ID            (SYSNS_SYSTEM | 1)
#define SYS_SYSTEM_PAGE_SIZE          (SYSNS_SYSTEM | 2)
#define SYS_SYSTEM_USER_SPACE_START   (SYSNS_SYSTEM | 3)
#define SYS_SYSTEM_USER_SPACE_END     (SYSNS_SYSTEM | 4)
#define SYS_SYSTEM_CAPS_PER_CAP_SPACE (SYSNS_SYSTEM | 5)
#define SYS_SYSTEM_YIELD              (SYSNS_SYSTEM | 6)
#define SYS_SYSTEM_CAP_SIZE           (SYSNS_SYSTEM | 7)
#define SYS_SYSTEM_CAP_ALIGN          (SYSNS_SYSTEM | 8)

#define SYS_CAP_TYPE    (SYSNS_CAP | 0)
#define SYS_CAP_COPY    (SYSNS_CAP | 1)
#define SYS_CAP_REVOKE  (SYSNS_CAP | 2)
#define SYS_CAP_DESTROY (SYSNS_CAP | 3)
#define SYS_CAP_SAME    (SYSNS_CAP | 4)

#define SYS_MEM_CAP_DEVICE        (SYSNS_MEM_CAP | 0)
#define SYS_MEM_CAP_PHYS_ADDR     (SYSNS_MEM_CAP | 1)
#define SYS_MEM_CAP_SIZE          (SYSNS_MEM_CAP | 2)
#define SYS_MEM_CAP_USED_SIZE     (SYSNS_MEM_CAP | 3)
#define SYS_MEM_CAP_CREATE_OBJECT (SYSNS_MEM_CAP | 4)

#define SYS_TASK_CAP_TID                     (SYSNS_TASK_CAP | 0)
#define SYS_TASK_CAP_KILLABLE                (SYSNS_TASK_CAP | 1)
#define SYS_TASK_CAP_SWITCHABLE              (SYSNS_TASK_CAP | 2)
#define SYS_TASK_CAP_SUSPENDABLE             (SYSNS_TASK_CAP | 3)
#define SYS_TASK_CAP_RESUMABLE               (SYSNS_TASK_CAP | 4)
#define SYS_TASK_CAP_KILL                    (SYSNS_TASK_CAP | 5)
#define SYS_TASK_CAP_SWITCH                  (SYSNS_TASK_CAP | 6)
#define SYS_TASK_CAP_SUSPEND                 (SYSNS_TASK_CAP | 7)
#define SYS_TASK_CAP_RESUME                  (SYSNS_TASK_CAP | 8)
#define SYS_TASK_CAP_GET_REG                 (SYSNS_TASK_CAP | 9)
#define SYS_TASK_CAP_SET_REG                 (SYSNS_TASK_CAP | 10)
#define SYS_TASK_CAP_TRANSFER_CAP            (SYSNS_TASK_CAP | 11)
#define SYS_TASK_CAP_DELEGATE_CAP            (SYSNS_TASK_CAP | 12)
#define SYS_TASK_CAP_GET_FREE_SLOT_COUNT     (SYSNS_TASK_CAP | 13)
#define SYS_TASK_CAP_GET_CAP_SPACE_COUNT     (SYSNS_TASK_CAP | 14)
#define SYS_TASK_CAP_GET_CAP_SPACE_EXT_COUNT (SYSNS_TASK_CAP | 15)
#define SYS_TASK_CAP_INSERT_CAP_SPACE        (SYSNS_TASK_CAP | 16)
#define SYS_TASK_CAP_EXTEND_CAP_SPACE        (SYSNS_TASK_CAP | 17)
#define SYS_TASK_CAP_SET_KILL_NOTIFY         (SYSNS_TASK_CAP | 18)

#define SYS_ENDPOINT_CAP_SEND_SHORT        (SYSNS_ENDPOINT_CAP | 0)
#define SYS_ENDPOINT_CAP_SEND_LONG         (SYSNS_ENDPOINT_CAP | 1)
#define SYS_ENDPOINT_CAP_RECEIVE           (SYSNS_ENDPOINT_CAP | 2)
#define SYS_ENDPOINT_CAP_REPLY             (SYSNS_ENDPOINT_CAP | 3)
#define SYS_ENDPOINT_CAP_NB_SEND_SHORT     (SYSNS_ENDPOINT_CAP | 4)
#define SYS_ENDPOINT_CAP_NB_SEND_LONG      (SYSNS_ENDPOINT_CAP | 5)
#define SYS_ENDPOINT_CAP_NB_RECEIVE        (SYSNS_ENDPOINT_CAP | 6)
#define SYS_ENDPOINT_CAP_CALL              (SYSNS_ENDPOINT_CAP | 7)
#define SYS_ENDPOINT_CAP_REPLY_AND_RECEIVE (SYSNS_ENDPOINT_CAP | 8)

#define SYS_PAGE_TABLE_CAP_MAPPED         (SYSNS_PAGE_TABLE_CAP | 0)
#define SYS_PAGE_TABLE_CAP_LEVEL          (SYSNS_PAGE_TABLE_CAP | 1)
#define SYS_PAGE_TABLE_CAP_MAP_TABLE      (SYSNS_PAGE_TABLE_CAP | 2)
#define SYS_PAGE_TABLE_CAP_UNMAP_TABLE    (SYSNS_PAGE_TABLE_CAP | 3)
#define SYS_PAGE_TABLE_CAP_MAP_PAGE       (SYSNS_PAGE_TABLE_CAP | 4)
#define SYS_PAGE_TABLE_CAP_UNMAP_PAGE     (SYSNS_PAGE_TABLE_CAP | 5)
#define SYS_PAGE_TABLE_CAP_REMAP_PAGE     (SYSNS_PAGE_TABLE_CAP | 6)
#define SYS_PAGE_TABLE_CAP_VIRT_ADDR_BASE (SYSNS_PAGE_TABLE_CAP | 7)

#define SYS_VIRT_PAGE_CAP_MAPPED     (SYSNS_VIRT_PAGE_CAP | 0)
#define SYS_VIRT_PAGE_CAP_READABLE   (SYSNS_VIRT_PAGE_CAP | 1)
#define SYS_VIRT_PAGE_CAP_WRITABLE   (SYSNS_VIRT_PAGE_CAP | 2)
#define SYS_VIRT_PAGE_CAP_EXECUTABLE (SYSNS_VIRT_PAGE_CAP | 3)
#define SYS_VIRT_PAGE_CAP_LEVEL      (SYSNS_VIRT_PAGE_CAP | 4)
#define SYS_VIRT_PAGE_CAP_PHYS_ADDR  (SYSNS_VIRT_PAGE_CAP | 5)
#define SYS_VIRT_PAGE_CAP_VIRT_ADDR  (SYSNS_VIRT_PAGE_CAP | 6)

#define SYS_ID_CAP_CREATE  (SYSNS_ID_CAP | 0)
#define SYS_ID_CAP_COMPARE (SYSNS_ID_CAP | 1)

#define SYS_S_OK               (0)
#define SYS_E_UNKNOWN          (-1)
#define SYS_E_CAP_TYPE         (-2)
#define SYS_E_CAP_STATE        (-3)
#define SYS_E_ILL_CODE         (-4)
#define SYS_E_ILL_ARGS         (-5)
#define SYS_E_ILL_STATE        (-6)
#define SYS_E_CANCELED         (-7)
#define SYS_E_BLOCKED          (-8)
#define SYS_E_OUT_OF_CAP_SPACE (-9)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef uintptr_t sysret_result_t;
  typedef intptr_t  sysret_error_t;

  typedef struct {
    sysret_result_t result;
    sysret_error_t  error;
  } sysret_t;

  sysret_t syscall0(uintptr_t code);
  sysret_t syscall1(uintptr_t arg0, uintptr_t code);
  sysret_t syscall2(uintptr_t arg0, uintptr_t arg1, uintptr_t code);
  sysret_t syscall3(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t code);
  sysret_t syscall4(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t code);
  sysret_t syscall5(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t code);
  sysret_t syscall6(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t code);
  sysret_t syscall7(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t arg6, uintptr_t code);

  static inline bool sysret_succeeded(sysret_t sysret) {
    return sysret.error >= 0;
  }

  static inline bool sysret_failed(sysret_t sysret) {
    return sysret.error < 0;
  }

  sysret_result_t unwrap_sysret(sysret_t sysret);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#if defined(__riscv) && __riscv_xlen == 64
#include <libcaprese/arch/rv64/syscall_rv64.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

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

  static inline sysret_t sys_system_cap_size(cap_type_t type) {
    return syscall1(type, SYS_SYSTEM_CAP_SIZE);
  }

  static inline sysret_t sys_system_cap_align(cap_type_t type) {
    return syscall1(type, SYS_SYSTEM_CAP_ALIGN);
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

  static inline sysret_t sys_cap_destroy(cap_t cap) {
    return syscall1(cap, SYS_CAP_DESTROY);
  }

  static inline sysret_t sys_cap_same(cap_t cap0, cap_t cap1) {
    return syscall2(cap0, cap1, SYS_CAP_SAME);
  }

  static inline sysret_t sys_mem_cap_device(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_DEVICE);
  }

  static inline sysret_t sys_mem_cap_phys_addr(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_PHYS_ADDR);
  }

  static inline sysret_t sys_mem_cap_size(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_SIZE);
  }

  static inline sysret_t sys_mem_cap_used_size(mem_cap_t cap) {
    return syscall1(cap, SYS_MEM_CAP_USED_SIZE);
  }

  static inline sysret_t sys_mem_cap_create_object(mem_cap_t cap, cap_type_t cap_type, uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4) {
    return syscall7(cap, cap_type, arg0, arg1, arg2, arg3, arg4, SYS_MEM_CAP_CREATE_OBJECT);
  }

  static inline sysret_t sys_mem_cap_create_memory_object(mem_cap_t cap, size_t size, size_t alignment) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_MEM, size, alignment, 0, 0, 0);
  }

  static inline sysret_t sys_mem_cap_create_task_object(mem_cap_t        cap,
                                                        cap_space_cap_t  cap_space_cap,
                                                        page_table_cap_t root_page_table,
                                                        page_table_cap_t cap_space_page_table0,
                                                        page_table_cap_t cap_space_page_table1,
                                                        page_table_cap_t cap_space_page_table2) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_TASK, cap_space_cap, root_page_table, cap_space_page_table0, cap_space_page_table1, cap_space_page_table2);
  }

  static inline sysret_t sys_mem_cap_create_endpoint_object(mem_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_ENDPOINT, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_mem_cap_create_page_table_object(mem_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_PAGE_TABLE, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_mem_cap_create_virt_page_object(mem_cap_t cap, bool readable, bool writable, bool executable, uintptr_t level) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_VIRT_PAGE, readable, writable, executable, level, 0);
  }

  static inline sysret_t sys_mem_cap_create_cap_space_object(mem_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_MEM);
    return sys_mem_cap_create_object(cap, CAP_CAP_SPACE, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_task_cap_tid(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_TID);
  }

  static inline sysret_t sys_task_cap_kill(task_cap_t cap, int exit_status) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall2(cap, exit_status, SYS_TASK_CAP_KILL);
  }

  static inline sysret_t sys_task_cap_switch(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_SWITCH);
  }

  static inline sysret_t sys_task_cap_suspend(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_SUSPEND);
  }

  static inline sysret_t sys_task_cap_resume(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_RESUME);
  }

  static inline sysret_t sys_task_cap_get_reg(task_cap_t cap, uintptr_t reg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall2(cap, reg, SYS_TASK_CAP_GET_REG);
  }

  static inline sysret_t sys_task_cap_set_reg(task_cap_t cap, uintptr_t reg, uintptr_t val) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall3(cap, reg, val, SYS_TASK_CAP_SET_REG);
  }

  static inline sysret_t sys_task_cap_transfer_cap(task_cap_t cap, cap_t src) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    assert(unwrap_sysret(sys_cap_type(src)) != CAP_NULL);
    return syscall2(cap, src, SYS_TASK_CAP_TRANSFER_CAP);
  }

  static inline sysret_t sys_task_cap_delegate_cap(task_cap_t cap, cap_t src) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    assert(unwrap_sysret(sys_cap_type(src)) != CAP_NULL);
    return syscall2(cap, src, SYS_TASK_CAP_DELEGATE_CAP);
  }

  static inline sysret_t sys_task_cap_copy(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return sys_cap_copy(cap, 0, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_task_cap_get_free_slot_count(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_GET_FREE_SLOT_COUNT);
  }

  static inline sysret_t sys_task_cap_get_cap_space_count(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_GET_CAP_SPACE_COUNT);
  }

  static inline sysret_t sys_task_cap_get_cap_space_ext_count(task_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    return syscall1(cap, SYS_TASK_CAP_GET_CAP_SPACE_EXT_COUNT);
  }

  static inline sysret_t sys_task_cap_insert_cap_space(task_cap_t cap, cap_space_cap_t cap_space_cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    assert(unwrap_sysret(sys_cap_type(cap_space_cap)) == CAP_CAP_SPACE);
    return syscall2(cap, cap_space_cap, SYS_TASK_CAP_INSERT_CAP_SPACE);
  }

  static inline sysret_t sys_task_cap_extend_cap_space(task_cap_t cap, page_table_cap_t page_table_cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    assert(unwrap_sysret(sys_cap_type(page_table_cap)) == CAP_PAGE_TABLE);
    return syscall2(cap, page_table_cap, SYS_TASK_CAP_EXTEND_CAP_SPACE);
  }

  static inline sysret_t sys_task_cap_set_kill_notify(task_cap_t cap, endpoint_cap_t endpoint_cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_TASK);
    assert(unwrap_sysret(sys_cap_type(endpoint_cap)) == CAP_ENDPOINT);
    return syscall2(cap, endpoint_cap, SYS_TASK_CAP_SET_KILL_NOTIFY);
  }

  static inline sysret_t sys_endpoint_cap_send_short(endpoint_cap_t cap, uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall7(cap, arg0, arg1, arg2, arg3, arg4, arg5, SYS_ENDPOINT_CAP_SEND_SHORT);
  }

  static inline sysret_t sys_endpoint_cap_send_long(endpoint_cap_t cap, message_t* msg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall2(cap, (uintptr_t)msg, SYS_ENDPOINT_CAP_SEND_LONG);
  }

  static inline sysret_t sys_endpoint_cap_receive(endpoint_cap_t cap, message_t* msg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall2(cap, (uintptr_t)msg, SYS_ENDPOINT_CAP_RECEIVE);
  }

  static inline sysret_t sys_endpoint_cap_reply(endpoint_cap_t cap, message_t* msg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall2(cap, (uintptr_t)msg, SYS_ENDPOINT_CAP_REPLY);
  }

  static inline sysret_t sys_endpoint_cap_nb_send_short(endpoint_cap_t cap, uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall7(cap, arg0, arg1, arg2, arg3, arg4, arg5, SYS_ENDPOINT_CAP_NB_SEND_SHORT);
  }

  static inline sysret_t sys_endpoint_cap_nb_send_long(endpoint_cap_t cap, message_t* msg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall2(cap, (uintptr_t)msg, SYS_ENDPOINT_CAP_NB_SEND_LONG);
  }

  static inline sysret_t sys_endpoint_cap_nb_receive(endpoint_cap_t cap, message_t* msg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall2(cap, (uintptr_t)msg, SYS_ENDPOINT_CAP_NB_RECEIVE);
  }

  static inline sysret_t sys_endpoint_cap_call(endpoint_cap_t cap, message_t* msg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall2(cap, (uintptr_t)msg, SYS_ENDPOINT_CAP_CALL);
  }

  static inline sysret_t sys_endpoint_cap_reply_and_receive(endpoint_cap_t cap, message_t* msg) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return syscall2(cap, (uintptr_t)msg, SYS_ENDPOINT_CAP_REPLY_AND_RECEIVE);
  }

  static inline sysret_t sys_endpoint_cap_copy(endpoint_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ENDPOINT);
    return sys_cap_copy(cap, 0, 0, 0, 0, 0, 0);
  }

  static inline sysret_t sys_page_table_cap_mapped(page_table_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    return syscall1(cap, SYS_PAGE_TABLE_CAP_MAPPED);
  }

  static inline sysret_t sys_page_table_cap_level(page_table_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    return syscall1(cap, SYS_PAGE_TABLE_CAP_LEVEL);
  }

  static inline sysret_t sys_page_table_cap_map_table(page_table_cap_t cap, uintptr_t index, page_table_cap_t child) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    assert(unwrap_sysret(sys_cap_type(child)) == CAP_PAGE_TABLE);
    assert(sys_page_table_cap_level(cap).result > KILO_PAGE);
    return syscall3(cap, index, child, SYS_PAGE_TABLE_CAP_MAP_TABLE);
  }

  static inline sysret_t sys_page_table_cap_unmap_table(page_table_cap_t cap, uintptr_t index, page_table_cap_t child) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    assert(unwrap_sysret(sys_cap_type(child)) == CAP_PAGE_TABLE);
    assert(sys_page_table_cap_level(cap).result > KILO_PAGE);
    return syscall3(cap, index, child, SYS_PAGE_TABLE_CAP_UNMAP_TABLE);
  }

  static inline sysret_t sys_page_table_cap_map_page(page_table_cap_t cap, uintptr_t index, bool readable, bool writable, bool executable, virt_page_cap_t child) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    assert(unwrap_sysret(sys_cap_type(child)) == CAP_VIRT_PAGE);
    return syscall6(cap, index, readable, writable, executable, child, SYS_PAGE_TABLE_CAP_MAP_PAGE);
  }

  static inline sysret_t sys_page_table_cap_unmap_page(page_table_cap_t cap, uintptr_t index, virt_page_cap_t child) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    assert(unwrap_sysret(sys_cap_type(child)) == CAP_VIRT_PAGE);
    return syscall3(cap, index, child, SYS_PAGE_TABLE_CAP_UNMAP_PAGE);
  }

  static inline sysret_t sys_page_table_cap_remap_page(page_table_cap_t cap, uintptr_t index, bool readable, bool writable, bool executable, virt_page_cap_t child, page_table_cap_t old_parent) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    assert(unwrap_sysret(sys_cap_type(child)) == CAP_VIRT_PAGE);
    assert(unwrap_sysret(sys_cap_type(old_parent)) == CAP_PAGE_TABLE);
    return syscall7(cap, index, readable, writable, executable, child, old_parent, SYS_PAGE_TABLE_CAP_REMAP_PAGE);
  }

  static inline sysret_t sys_page_table_cap_virt_addr_base(page_table_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_PAGE_TABLE);
    return syscall1(cap, SYS_PAGE_TABLE_CAP_VIRT_ADDR_BASE);
  }

  static inline sysret_t sys_virt_page_cap_mapped(virt_page_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_MAPPED);
  }

  static inline sysret_t sys_virt_page_cap_readable(virt_page_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_READABLE);
  }

  static inline sysret_t sys_virt_page_cap_writable(virt_page_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_WRITABLE);
  }

  static inline sysret_t sys_virt_page_cap_executable(virt_page_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_EXECUTABLE);
  }

  static inline sysret_t sys_virt_page_cap_level(virt_page_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_LEVEL);
  }

  static inline sysret_t sys_virt_page_cap_phys_addr(virt_page_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_PHYS_ADDR);
  }

  static inline sysret_t sys_virt_page_cap_virt_addr(virt_page_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_VIRT_PAGE);
    return syscall1(cap, SYS_VIRT_PAGE_CAP_VIRT_ADDR);
  }

  static inline sysret_t sys_id_cap_create() {
    return syscall0(SYS_ID_CAP_CREATE);
  }

  static inline sysret_t sys_id_cap_compare(id_cap_t cap0, id_cap_t cap1) {
    assert(unwrap_sysret(sys_cap_type(cap0)) == CAP_ID);
    assert(unwrap_sysret(sys_cap_type(cap1)) == CAP_ID);
    return syscall2(cap0, cap1, SYS_ID_CAP_COMPARE);
  }

  static inline sysret_t sys_id_cap_copy(id_cap_t cap) {
    assert(unwrap_sysret(sys_cap_type(cap)) == CAP_ID);
    return sys_cap_copy(cap, 0, 0, 0, 0, 0, 0);
  }

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_SYSCALL_H_
