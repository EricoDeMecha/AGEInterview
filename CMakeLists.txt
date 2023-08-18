
cmake_minimum_required(VERSION 3.9)
project(AGEInterviewQuiz1 C)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_C_STANDARD 17)

# Conan setup
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES cmocka/1.1.5
        GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${settings})

#Find packages
enable_testing()
include(CTest)
find_package(cmocka REQUIRED)

add_executable(${PROJECT_NAME} src/node/node.c src/node/node.h tests/node_test.c)
target_link_libraries(${PROJECT_NAME} cmocka::cmocka)
