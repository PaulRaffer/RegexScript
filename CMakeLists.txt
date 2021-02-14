cmake_minimum_required(VERSION 3.9)
project(RegexScript)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR "C:/Program Files/boost/boost_1_73_0")
set(RAFFER_ROOT ".")
set(Raffer_INCLUDE_DIR "${RAFFER_ROOT}/include")

include_directories(
	${Boost_INCLUDE_DIR}
	${Raffer_INCLUDE_DIR}
)

add_executable(regs "src/main.cpp"
	"include/raffer/regex/call/call.cpp"
	"include/raffer/string/string.cpp"
	"include/raffer/system/system.cpp")
