nasm src/bootloader.asm -f bin -i src -o bootloader.bin

nasm src/ExtendedProgram.asm -f elf64 -i src -o ExtendedProgram.o

cmake CMakeLists.txt -G "Unix Makefiles" -D CMAKE_CXX_COMPILER=x86_64-elf-gcc -D CMAKE_C_COMPILER=x86_64-elf-gcc

make -f "Makefile"

copy /b bootloader.bin+kernel.bin bootloader.flp

del kernel.bin
del libkernel.a
del Makefile
del cmake_install.cmake
del bootloader.bin
del ExtendedProgram.o

cd CMakeFiles
del /F/Q/S *.* > NUL

cd ..
rmdir /Q/S CMakeFiles

pause
