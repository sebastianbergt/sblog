cmake_minimum_required(VERSION 3.15)
project(sblog)

project(can_interface_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(sblog src/get_html.cpp src/handler.cpp src/sblog.cpp)

find_package(oatpp 1.2 REQUIRED)
find_package(maddy 1.1 REQUIRED)

target_link_libraries(sblog PRIVATE oatpp::oatpp maddy::maddy)

target_include_directories(sblog PUBLIC include)

install(TARGETS sblog)

# install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION
# ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h*")

# if(WITH_TESTS) find_package(Catch2 2.13.4 REQUIRED) find_package(trompeloeil
# 41 REQUIRED)

# add_subdirectory(tests) endif()
