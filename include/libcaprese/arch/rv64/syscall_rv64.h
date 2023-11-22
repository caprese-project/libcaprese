#ifndef LIBCAPRESE_ARCH_RV64_SYSCALL_RV64_H_
#define LIBCAPRESE_ARCH_RV64_SYSCALL_RV64_H_

#define ARCH_REG_RA   0
#define ARCH_REG_SP   1
#define ARCH_REG_GP   2
#define ARCH_REG_TP   3
#define ARCH_REG_T0   4
#define ARCH_REG_T1   5
#define ARCH_REG_T2   6
#define ARCH_REG_S0   7
#define ARCH_REG_S1   8
#define ARCH_REG_A0   9
#define ARCH_REG_A1   10
#define ARCH_REG_A2   11
#define ARCH_REG_A3   12
#define ARCH_REG_A4   13
#define ARCH_REG_A5   14
#define ARCH_REG_A6   15
#define ARCH_REG_A7   16
#define ARCH_REG_S2   17
#define ARCH_REG_S3   18
#define ARCH_REG_S4   19
#define ARCH_REG_S5   20
#define ARCH_REG_S6   21
#define ARCH_REG_S7   22
#define ARCH_REG_S8   23
#define ARCH_REG_S9   24
#define ARCH_REG_S10  25
#define ARCH_REG_S11  26
#define ARCH_REG_T3   27
#define ARCH_REG_T4   28
#define ARCH_REG_T5   29
#define ARCH_REG_T6   30
#define ARCH_REG_SEPC 31

#define LAST_REGISTER 31

#define REG_RETURN_ADDRESS  ARCH_REG_RA
#define REG_STACK_POINTER   ARCH_REG_SP
#define REG_GLOBAL_POINTER  ARCH_REG_GP
#define REG_THREAD_POINTER  ARCH_REG_TP
#define REG_PROGRAM_COUNTER ARCH_REG_SEPC
#define REG_ARG_0           ARCH_REG_A0
#define REG_ARG_1           ARCH_REG_A1
#define REG_ARG_2           ARCH_REG_A2
#define REG_ARG_3           ARCH_REG_A3
#define REG_ARG_4           ARCH_REG_A4
#define REG_ARG_5           ARCH_REG_A5
#define REG_ARG_6           ARCH_REG_A6
#define REG_ARG_7           ARCH_REG_A7
#define REG_RET_0           ARCH_REG_A0
#define REG_RET_1           ARCH_REG_A1
#define REG_SYS_ARG_0       ARCH_REG_A0
#define REG_SYS_ARG_1       ARCH_REG_A1
#define REG_SYS_ARG_2       ARCH_REG_A2
#define REG_SYS_ARG_3       ARCH_REG_A3
#define REG_SYS_ARG_4       ARCH_REG_A4
#define REG_SYS_ARG_5       ARCH_REG_A5
#define REG_SYS_ARG_6       ARCH_REG_A6
#define REG_SYS_ARG_7       ARCH_REG_A7
#define REG_SYS_RET_0       ARCH_REG_A0
#define REG_SYS_RET_1       ARCH_REG_A1

#define REG_NUM_ARGS 7
#define REG_NUM_RETS 2

#define RISCV_MMU_SV39 39
#define RISCV_MMU_SV48 48

#define KILO_PAGE 0
#define MEGA_PAGE 1
#define GIGA_PAGE 2
#define TERA_PAGE 3

#define RISCV_MMU_SV39_MAX_PAGE GIGA_PAGE
#define RISCV_MMU_SV48_MAX_PAGE TERA_PAGE

#define RISCV_MMU_GET_PAGE_TABLE_INDEX(va, level) (((va) >> (9 * (level) + 12)) & 0x1ff)

#endif // LIBCAPRESE_ARCH_RV64_SYSCALL_RV64_H_
