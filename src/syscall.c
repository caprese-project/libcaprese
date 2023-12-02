#include <libcaprese/syscall.h>
#include <stdlib.h>

uintptr_t unwrap_sysret(sysret_t sysret) {
  if (sysret_failed(sysret)) {
    abort();
  }

  return sysret.result;
}
