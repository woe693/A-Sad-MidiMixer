# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appMidiMixer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appMidiMixer_autogen.dir\\ParseCache.txt"
  "appMidiMixer_autogen"
  )
endif()
