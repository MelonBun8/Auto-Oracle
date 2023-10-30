# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AutoOracle_autogen"
  "CMakeFiles\\AutoOracle_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AutoOracle_autogen.dir\\ParseCache.txt"
  )
endif()
