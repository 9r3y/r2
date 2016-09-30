# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/main/R2Config.h.in"
  "${PROJECT_BINARY_DIR}/main/R2Config.h"
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

set(SOURCE_FILES main.cpp main.h)

# add the executable
add_executable(r2 ${SOURCE_FILES})
target_link_libraries (r2 ${EXTRA_LIBS})

# add the install targets
install (TARGETS r2 DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/R2Config.h" DESTINATION include)
