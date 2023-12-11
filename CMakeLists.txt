cmake_minimum_required(VERSION 3.20)

project(
  libcaprese
  VERSION 0.0.1
  HOMEPAGE_URL https://github.com/caprese-project/libcaprese
  LANGUAGES C ASM
)

add_library(libcaprese STATIC)
add_library(libcaprese++ STATIC)

set_target_properties(
  libcaprese PROPERTIES
  OUTPUT_NAME caprese
)

set_target_properties(
  libcaprese++ PROPERTIES
  OUTPUT_NAME caprese++
)

target_compile_options(
  libcaprese PRIVATE
  ${LIBCAPRESE_COMPILE_OPTIONS}
)

target_compile_options(
  libcaprese++ PRIVATE
  ${LIBCAPRESE_COMPILE_OPTIONS}
)

target_sources(
  libcaprese PRIVATE
  src/syscall.c
  src/syscall.S
)

target_sources(
  libcaprese++ PRIVATE
  src/cxx/raii.cpp
)

target_include_directories(
  libcaprese PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(
  libcaprese++ PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(
  TARGETS libcaprese
  EXPORT libcaprese-export
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

install(
  TARGETS libcaprese++
  EXPORT libcaprese-export
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

install(
  EXPORT libcaprese-export
  FILE libcaprese-config.cmake
  NAMESPACE libcaprese::
  DESTINATION lib/cmake/libcaprese
)
