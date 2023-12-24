#ifndef LIBCAPRESE_CXX_RAII_H_
#define LIBCAPRESE_CXX_RAII_H_

#ifdef __cplusplus

#include <libcaprese/cap.h>

namespace caprese {
  class unique_cap {
    cap_t cap;

  public:
    constexpr unique_cap() noexcept: cap(0) { }

    constexpr unique_cap(cap_t cap) noexcept: cap(cap) { }

    unique_cap(const unique_cap&)            = delete;
    unique_cap& operator=(const unique_cap&) = delete;

    unique_cap(unique_cap&& other) noexcept;
    unique_cap& operator=(unique_cap&& other) noexcept;

    ~unique_cap() noexcept;

    cap_t release() noexcept;
    void  reset(cap_t new_cap) noexcept;
    void  swap(unique_cap& other) noexcept;
    cap_t get() const noexcept;

    explicit operator bool() const noexcept;
  };
} // namespace caprese

#endif // __cplusplus

#endif // LIBCAPRESE_CXX_RAII_H_
