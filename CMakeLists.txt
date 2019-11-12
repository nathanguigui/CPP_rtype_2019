cmake_minimum_required(VERSION 3.1.0)

project(CPP_rtype_2019)

include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()
INCLUDE_DIRECTORIES(${CONAN_INCLUDE_DIRS})

include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
INCLUDE_DIRECTORIES(${CONAN_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CLIENT_SRC
        client/src/main.cpp
        client/src/core/WindowManager/WindowManager.cpp client/src/core/WindowManager/WindowManager.hpp client/src/core/Event/Event.cpp client/src/core/Event/Event.hpp client/src/core/CoreObject/CoreObject.cpp client/src/core/CoreObject/CoreObject.hpp)

set(CLIENT_HEADERS
        client/includes/core/game/game.hpp
        )

include_directories("${PROJECT_BINARY_DIR}")

add_executable(rtype_client ${CLIENT_SRC})
target_link_libraries(rtype_client ${CONAN_LIBS})