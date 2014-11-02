
cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Yawot-src)
project(${PROJECT_NAME})

# The version number.
set(YAWOT_VERSION_MAJOR 0)
set(YAWOT_VERSION_MINOR 1)
set(YAWOT_VERSION_PATCH 0)

foreach(VERSION_PART YAWOT_VERSION_MAJOR YAWOT_VERSION_MINOR YAWOT_VERSION_PATCH)
  string(LENGTH ${${VERSION_PART}} VERSION_PART_LENGTH)
  if(VERSION_PART_LENGTH EQUAL 1)
    set(${VERSION_PART}_PAD 0)
  endif()
endforeach()
set(LIBRARY_VERSION 0x${YAWOT_VERSION_MAJOR_PAD}${YAWOT_VERSION_MAJOR}${YAWOT_VERSION_MINOR_PAD}${YAWOT_VERSION_MINOR}${YAWOT_VERSION_PATCH_PAD}${YAWOT_VERSION_PATCH})
set(LIBRARY_VERSION_STRING "${YAWOT_VERSION_MAJOR}.${YAWOT_VERSION_MINOR}.${YAWOT_VERSION_PATCH}")
# Configuration variables
# - We namespace the cache variable so the configuration variables are grouped
set(YAWOT_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build: Debug, Release etc.")
if(BUILD_TYPE)
  set(YAWOT_BUILD_TYPE ${BUILD_TYPE} CACHE STRING "Choose the type of build: Debug, Release etc." FORCE)
endif()
set(CMAKE_BUILD_TYPE ${YAWOT_BUILD_TYPE} CACHE INTERNAL "Internalise CMAKE_BUILD_TYPE, manipulate via YAWOT_BUILD_TYPE" FORCE)

set(YAWOT_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}" CACHE STRING "Set the install prefix.")
if(BUILD_TYPE)
  set(YAWOT_INSTALL_PREFIX ${BUILD_TYPE} CACHE STRING "Set the install prefix." FORCE)
endif()
set(CMAKE_INSTALL_PREFIX ${YAWOT_INSTALL_PREFIX} CACHE INTERNAL "Internalise CMAKE_INSTALL_PREFIX, manipulate via YAWOT_INSTALL_PREFIX" FORCE)

# Add the configure version in to the list of source files so it will showup in IDEs.
set(VERSION_CONFIG_IN "${PROJECT_SOURCE_DIR}/configure/version.in.h")
set(HEADER_FILES ${PROJECT_SOURCE_DIR}/api/yawot/version.h ${VERSION_CONFIG_IN})
set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/version.cpp)

include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/api")

set(VERSION_CONFIG "${PROJECT_BINARY_DIR}/configure/version.h")
configure_file (
  ${VERSION_CONFIG_IN}
  ${VERSION_CONFIG}
)

set(LIBRARY_NAME yawot)
add_library(${LIBRARY_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${VERSION_CONFIG})

