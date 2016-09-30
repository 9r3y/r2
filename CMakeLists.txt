cmake_minimum_required (VERSION 2.6)
project (R2)
set (R2_VERSION_MAJOR 1)
set (R2_VERSION_MINOR 0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory (main)

# enable testing
enable_testing ()

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${R2_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${R2_VERSION_MINOR}")
include (CPack)