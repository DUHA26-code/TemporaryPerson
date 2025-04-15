# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\TemporaryPerson_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TemporaryPerson_autogen.dir\\ParseCache.txt"
  "TemporaryPerson_autogen"
  )
endif()
