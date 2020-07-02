#pragma once
#include "IO.cpp"
#include "Typedefs.cpp"
#define VGA_MEMORY (uint_8*)0xb8000
#define VGA_WIDTH 80

uint_16 CursorPosition;

void SetCursorPosition(uint_16 position){
  outb(0x3D4, 0x0F);
  outb(0x3D5, (uint_8)(position & 0xFF));
  outb(0x3D4, 0x0E);
  outb(0x3D5, (uint_8)((position >> 8) & 0xFF));

  CursorPosition = position;
}

uint_16 PositionFromCoords(uint_8 x, uint_8 y){
  return y * VGA_WIDTH + x;
}

void PrintString(const char* str){
  uint_8* charPtr = (uint_8*)str;
  uint_16 index = CursorPosition;
  while(*charPtr != 0)
  {
    switch (*charPtr) {
      case 10:
        index+= VGA_WIDTH;
        break;
      case 13:
        index -= index % VGA_WIDTH;
        break;
      default:
      *(VGA_MEMORY + index * 2) = *charPtr;
      index++;
    }

    charPtr++;
  }
  SetCursorPosition(index);
}
