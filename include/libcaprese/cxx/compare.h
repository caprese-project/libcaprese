#ifndef LIBCAPRESE_CXX_COMPARE_H_
#define LIBCAPRESE_CXX_COMPARE_H_

#ifdef __cplusplus

#include <libcaprese/cap.h>
#include <libcaprese/syscall.h>

namespace caprese {
  struct id_cap_compare {
    using first_argument_type  = id_cap_t;
    using second_argument_type = id_cap_t;
    using result_type          = bool;

    bool operator()(const id_cap_t& lhs, const id_cap_t& rhs) const noexcept {
      return static_cast<intptr_t>(unwrap_sysret(sys_id_cap_compare(lhs, rhs))) < 0;
    }
  };
} // namespace caprese

#endif // __cplusplus

#endif // LIBCAPRESE_CXX_COMPARE_H_
