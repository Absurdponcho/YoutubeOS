#include "TextPrint.h"

uint_16 CursorPosition;

void ClearScreen(uint_64 ClearColor)
{
  uint_64 value =0;
  value += ClearColor << 8;
  value += ClearColor << 24;
  value += ClearColor << 40;
  value += ClearColor << 56;
  for (uint_64* i = (uint_64*)VGA_MEMORY; i < (uint_64*)(VGA_MEMORY + 4000); i++){
      *i = value;
  }
}

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

void PrintString(const char* str, uint_8 color){
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
      *(VGA_MEMORY + index * 2 + 1) = color;
      index++;
    }

    charPtr++;
  }
  SetCursorPosition(index);
}

void PrintChar(char chr, uint_8 color)
{
  *(VGA_MEMORY + CursorPosition * 2) = chr;
  *(VGA_MEMORY + CursorPosition * 2 + 1) = color;

  SetCursorPosition(CursorPosition + 1);
}

char hexToStringOutput[128];
template<typename T>
const char* HexToString(T value){
  T* valPtr = &value;
  uint_8* ptr;
  uint_8 temp;
  uint_8 size = (sizeof(T)) * 2 - 1;
  uint_8 i;
  for (i = 0; i < size; i++){
    ptr = ((uint_8*)valPtr + i);
    temp = ((*ptr & 0xF0) >> 4);
    hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
    temp = ((*ptr & 0x0F));
    hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
  }
  hexToStringOutput[size + 1] = 0;
  return hexToStringOutput;
}

const char* HexToString(uint_8 value) { return HexToString<uint_8>(value); }
const char* HexToString(uint_16 value) { return HexToString<uint_16>(value); }
const char* HexToString(uint_32 value) { return HexToString<uint_32>(value); }
const char* HexToString(uint_64 value) { return HexToString<uint_64>(value); }
const char* HexToString(char value) { return HexToString<char>(value); }
const char* HexToString(short value) { return HexToString<short>(value); }
const char* HexToString(int value) { return HexToString<int>(value); }
const char* HexToString(long long value) { return HexToString<long long>(value); }

char integerToStringOutput[128];
template<typename T>
const char* IntegerToString(T value) {

	uint_8 isNegative = 0;

	if (value < 0) {
		isNegative = 1;
		value *= -1;
		integerToStringOutput[0] = '-';
	}

	uint_8 size = 0;
	uint_64 sizeTester = (uint_64)value;
	while (sizeTester / 10 > 0) {
		sizeTester /= 10;
		size++;
	}

	uint_8 index = 0;
	uint_64 newValue = (uint_64)value;
	while (newValue / 10 > 0) {
		uint_8 remainder = newValue % 10;
		newValue /= 10;
		integerToStringOutput[isNegative + size - index] = remainder + 48; 
		index++;
	}
	uint_8 remainder = newValue % 10;
	integerToStringOutput[isNegative + size - index] = remainder + 48;
	integerToStringOutput[isNegative + size + 1] = 0;
	return integerToStringOutput;
}

const char* IntegerToString(uint_8 value) { return IntegerToString<uint_8>(value); }
const char* IntegerToString(uint_16 value) { return IntegerToString<uint_16>(value); }
const char* IntegerToString(uint_32 value) { return IntegerToString<uint_32>(value); }
const char* IntegerToString(uint_64 value) { return IntegerToString<uint_64>(value); }
const char* IntegerToString(char value) { return IntegerToString<char>(value); }
const char* IntegerToString(short value) { return IntegerToString<short>(value); }
const char* IntegerToString(int value) { return IntegerToString<int>(value); }
const char* IntegerToString(long long value) { return IntegerToString<long long>(value); }

char floatToStringOutput[128];
const char* FloatToString(float value, uint_8 decimalPlaces) {
	char* intPtr = (char*)IntegerToString((int)value);
	char* floatPtr = floatToStringOutput;

	if (value < 0) {
		value *= -1;
	}

	while (*intPtr != 0) {
		*floatPtr = *intPtr;
		intPtr++;
		floatPtr++;
	}
	*floatPtr = '.';
	floatPtr++;

	float newValue = value - (int)value;

	for (uint_8 i = 0; i < decimalPlaces; i++) {
		newValue *= 10;
		*floatPtr = (int)newValue + 48;
		newValue -= (int)newValue;
		floatPtr++;
	}

	*floatPtr = 0;

	return floatToStringOutput;
}


