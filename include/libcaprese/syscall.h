#ifndef LIBCAPRESE_SYSCALL_H_
#define LIBCAPRESE_SYSCALL_H_

#include <stdint.h>

#define SYSNS_SYSTEM  (0 << 16)
#define SYSNS_ARCH    (1 << 16)
#define SYSNS_CAP     (2 << 16)
#define SYSNS_MEMCAP  (3 << 16)
#define SYSNS_TASKCAP (4 << 16)

#define SYS_SYSTEM_NULL             (SYSNS_SYSTEM | 0)
#define SYS_SYSTEM_CORE_ID          (SYSNS_SYSTEM | 1)
#define SYS_SYSTEM_PAGE_SIZE        (SYSNS_SYSTEM | 2)
#define SYS_SYSTEM_USER_SPACE_START (SYSNS_SYSTEM | 3)
#define SYS_SYSTEM_USER_SPACE_END   (SYSNS_SYSTEM | 4)

#if defined(__riscv) && __riscv_xlen == 64
#include <libcaprese/arch/rv64/syscall_rv64.h>
#endif

#define SYS_CAP_TYPE (SYSNS_CAP | 0)

#define SYS_MEMCAP_DEVICE        (SYSNS_MEMCAP | 0)
#define SYS_MEMCAP_READABLE      (SYSNS_MEMCAP | 1)
#define SYS_MEMCAP_WRITABLE      (SYSNS_MEMCAP | 2)
#define SYS_MEMCAP_EXECUTABLE    (SYSNS_MEMCAP | 3)
#define SYS_MEMCAP_PHYS_ADDR     (SYSNS_MEMCAP | 4)
#define SYS_MEMCAP_SIZE_BIT      (SYSNS_MEMCAP | 5)
#define SYS_MEMCAP_USED_SIZE     (SYSNS_MEMCAP | 6)
#define SYS_MEMCAP_CREATE_OBJECT (SYSNS_MEMCAP | 7)

#define SYS_TASKCAP_KILLABLE     (SYSNS_TASKCAP | 0)
#define SYS_TASKCAP_SWITCHABLE   (SYSNS_TASKCAP | 1)
#define SYS_TASKCAP_SUSPENDABLE  (SYSNS_TASKCAP | 2)
#define SYS_TASKCAP_RESUMABLE    (SYSNS_TASKCAP | 3)
#define SYS_TASKCAP_KILL         (SYSNS_TASKCAP | 4)
#define SYS_TASKCAP_SWITCH       (SYSNS_TASKCAP | 5)
#define SYS_TASKCAP_SUSPEND      (SYSNS_TASKCAP | 6)
#define SYS_TASKCAP_RESUME       (SYSNS_TASKCAP | 7)
#define SYS_TASKCAP_GET_REG      (SYSNS_TASKCAP | 8)
#define SYS_TASKCAP_SET_REG      (SYSNS_TASKCAP | 9)
#define SYS_TASKCAP_TRANSFER_CAP (SYSNS_TASKCAP | 10)

#define SYS_S_OK               (0)
#define SYS_E_INVALID_ARGUMENT (-1)
#define SYS_E_INVALID_CODE     (-2)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  typedef struct {
    uintptr_t result;
    intptr_t error;
  } sysret_t;

  sysret_t syscall0(uintptr_t code);
  sysret_t syscall1(uintptr_t arg0, uintptr_t code);
  sysret_t syscall2(uintptr_t arg0, uintptr_t arg1, uintptr_t code);
  sysret_t syscall3(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t code);
  sysret_t syscall4(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t code);
  sysret_t syscall5(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t code);
  sysret_t syscall6(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t code);
  sysret_t syscall7(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t arg6, uintptr_t code);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // LIBCAPRESE_SYSCALL_H_
