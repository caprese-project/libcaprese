#ifndef LIBCAPRESE_ATTRIBUTE_H_
#define LIBCAPRESE_ATTRIBUTE_H_

#ifdef __GNUC__

#define LIBCAPRESE_IF_LIKELY(cond)   if (__builtin_expect(!!(cond), 1))
#define LIBCAPRESE_IF_UNLIKELY(cond) if (__builtin_expect(!!(cond), 0))

#else // ^^^ __GNUC__ ^^^ / vvv !__GNUC__ vvv

#define LIBCAPRESE_IF_LIKELY(cond)   if (cond)
#define LIBCAPRESE_IF_UNLIKELY(cond) if (cond)

#endif // !__GNUC__

#endif // LIBCAPRESE_ATTRIBUTE_H_
