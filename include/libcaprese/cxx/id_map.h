#ifndef LIBCAPRESE_CXX_ID_MAP_H_
#define LIBCAPRESE_CXX_ID_MAP_H_

#ifdef __cplusplus

#include <libcaprese/cxx/compare.h>
#include <map>

namespace caprese {
  template<typename T>
  using id_map = std::map<id_cap_t, T, id_cap_compare>;
} // namespace caprese

#endif // __cplusplus

#endif // LIBCAPRESE_CXX_ID_MAP_H_
