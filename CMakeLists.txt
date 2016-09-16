cmake_minimum_required (VERSION 2.6)
set (CMAKE_C_COMPILER gcc)
set (CMAKE_CXX_COMPILER g++)
set (CMAKE_BUILD_TYPE DEBUG)
set (CMAKE_ECLIPSE_VERSION 4.5)

project (R2)
set (R2_VERSION_MAJOR 1)
set (R2_VERSION_MINOR 0)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/R2Config.h.in"
  "${PROJECT_BINARY_DIR}/R2Config.h"
  )

# add the binary tree to the search path for include files
# so that we will find R2Config.h
include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()

# add the executable
add_executable(r2 main.cxx)
target_link_libraries (r2 ${EXTRA_LIBS})

# add the install targets
install (TARGETS r2 DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/R2Config.h" DESTINATION include)

# enable testing
enable_testing ()

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${R2_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${R2_VERSION_MINOR}")
include (CPack)