.section .text

/* sysret_t syscall0(uintptr_t code); */
.global syscall0
.type syscall0, @function
syscall0:
  li a7, a0
  ecall
  ret

/* sysret_t syscall1(uintptr_t arg0, uintptr_t code); */
.global syscall1
.type syscall1, @function
syscall1:
  li a7, a1
  ecall
  ret

/* sysret_t syscall2(uintptr_t arg0, uintptr_t arg1, uintptr_t code); */
.global syscall2
.type syscall2, @function
syscall2:
  li a7, a2
  ecall
  ret

/* sysret_t syscall3(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t code); */
.global syscall3
.type syscall3, @function
syscall3:
  li a7, a3
  ecall
  ret

/* sysret_t syscall4(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t code); */
.global syscall4
.type syscall4, @function
syscall4:
  li a7, a4
  ecall
  ret

/* sysret_t syscall5(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t code); */
.global syscall5
.type syscall5, @function
syscall5:
  li a7, a5
  ecall
  ret

/* sysret_t syscall6(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t code); */
.global syscall6
.type syscall6, @function
syscall6:
  li a7, a6
  ecall
  ret

/* sysret_t syscall7(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t arg6, uintptr_t code); */
.global syscall7
.type syscall7, @function
syscall7:
  ecall
  ret
