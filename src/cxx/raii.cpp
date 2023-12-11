#include <libcaprese/cxx/raii.h>
#include <libcaprese/syscall.h>

unique_cap::unique_cap(unique_cap&& other) noexcept: cap(other.cap) {
  other.cap = 0;
}

unique_cap& unique_cap::operator=(unique_cap&& other) noexcept {
  if (this != &other) {
    cap       = other.cap;
    other.cap = 0;
  }

  return *this;
}

unique_cap::~unique_cap() noexcept {
  if (cap) {
    unwrap_sysret(sys_cap_revoke(cap));
  }
}

cap_t unique_cap::release() noexcept {
  cap_t ret = cap;
  cap       = 0;
  return ret;
}

void unique_cap::reset(cap_t new_cap) noexcept {
  if (cap != 0) {
    unwrap_sysret(sys_cap_revoke(cap));
  }

  cap = new_cap;
}

void unique_cap::swap(unique_cap& other) noexcept {
  cap_t tmp = cap;
  cap       = other.cap;
  other.cap = tmp;
}

cap_t unique_cap::get() const noexcept {
  return cap;
}

unique_cap::operator bool() const noexcept {
  return cap != 0;
}
