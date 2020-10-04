#pragma once
#include "IO.h"
#include "Typedefs.h"
#include "TextModeColorCodes.h"
#define VGA_MEMORY (uint_8*)0xb8000
#define VGA_WIDTH 80

extern uint_16 CursorPosition;
void ClearScreen(uint_64 ClearColor = BACKGROUND_BLACK | FOREGROUND_WHITE);
void SetCursorPosition(uint_16 position);
uint_16 PositionFromCoords(uint_8 x, uint_8 y);
void PrintString(const char* str, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE);
void PrintChar(char chr, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE);
const char* FloatToString(float value, uint_8 decimalPlaces);

const char* HexToString(uint_8 value);
const char* HexToString(uint_16 value);
const char* HexToString(uint_32 value);
const char* HexToString(uint_64 value);
const char* HexToString(char value);
const char* HexToString(short value);
const char* HexToString(int value);
const char* HexToString(long long value);

const char* IntegerToString(uint_8 value);
const char* IntegerToString(uint_16 value);
const char* IntegerToString(uint_32 value);
const char* IntegerToString(uint_64 value);
const char* IntegerToString(char value);
const char* IntegerToString(short value);
const char* IntegerToString(int value);
const char* IntegerToString(long long value);
