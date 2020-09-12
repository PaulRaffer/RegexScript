cmake_minimum_required(VERSION 3.9)
project(RegexScript)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR "C:/Program Files/boost/boost_1_73_0")
set(RAFFER_ROOT "C:/Program Files/raffer_cpplib")
set(Raffer_INCLUDE_DIR "${RAFFER_ROOT}/cpp${CMAKE_CXX_STANDARD}/include")
set(Raffer_INCLUDE_DIR_CPP11 "${RAFFER_ROOT}/cpp11/include")
set(Raffer_LIBRARY_DIR "${RAFFER_ROOT}/cpp${CMAKE_CXX_STANDARD}/build")
set(Raffer_LIBRARY_DIR_CPP11 "${RAFFER_ROOT}/cpp11/build")
include_directories(
	${Boost_INCLUDE_DIR}
	${Raffer_INCLUDE_DIR}
	${Raffer_INCLUDE_DIR_CPP11}
)
link_directories(
	${Raffer_LIBRARY_DIR}
	${Raffer_LIBRARY_DIR_CPP11}
)

add_executable(regs src/main.cpp)

target_link_libraries(regs libraffer_regex_call-static.a)
target_link_libraries(regs libraffer_type-static.a)
target_link_libraries(regs libraffer_system-static.a)
