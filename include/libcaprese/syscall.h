#ifndef LIBCAPRESE_SYSCALL_H_
#define LIBCAPRESE_SYSCALL_H_

#include <stdint.h>

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

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_SYSCALL_H_
