#include "TextPrint.cpp"
extern "C" void _start() {
	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("Hello\n\rFrom\nThe\nOther\n\rSide");
	return;
}
