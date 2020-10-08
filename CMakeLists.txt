cmake_minimum_required(VERSION 3.0)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project("OS")

include_directories("${PROJECT_SOURCE_DIR}/src")

set(CMAKE_CXX_FLAGS "-Ttext 0x8000 -ffreestanding -mno-red-zone -m64")
set(CMAKE_EXE_LINKER_FLAGS "-T \"link.ld\" ")

FILE (GLOB_RECURSE kernel_C_SOURCES "*.c")
FILE (GLOB_RECURSE kernel_CPP_SOURCES "*.cpp")

ADD_LIBRARY (kernel STATIC
		${kernel_C_SOURCES}
		${kernel_CPP_SOURCES})

ADD_CUSTOM_COMMAND (TARGET kernel
	POST_BUILD
	COMMAND custom-ld -T \"link.ld\")