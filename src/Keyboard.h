#pragma once
#include "Typedefs.h"
#include "TextPrint.h"

extern bool LeftShiftPressed;
extern bool RightShiftPressed;
extern uint_8 LastScancode;

void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr);
void KeyboardHandler0xE0(uint_8 scanCode);
void KeyboardHandler(uint_8 scanCode, uint_8 chr);