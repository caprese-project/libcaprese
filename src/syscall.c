#include <libcaprese/syscall.h>
#include <stdlib.h>

uintptr_t unwrap_sysret(sysret_t sysret) {
  if (sysret.error != 0) {
    abort();
  }

  return sysret.result;
}
