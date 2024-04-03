# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-src"
  "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-build"
  "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-subbuild/json-populate-prefix"
  "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/tmp"
  "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src"
  "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/CLion/7-Wonders/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
