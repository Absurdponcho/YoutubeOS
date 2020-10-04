#include "TextPrint.h"
#include "IDT.h"
#include "Keyboard.h"
#include "MemoryMap.h"
#include "Heap.h"


extern "C" void _start() {
	SetCursorPosition(PositionFromCoords(0, 0));
	InitializeIDT();
	MainKeyboardHandler = KeyboardHandler;
	
	MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();


	InitializeHeap(0x100000, 0x100000);
	
	uint_64* TestAddress = (uint_64*)malloc(0x08);
	*TestAddress = 12345678;
	PrintString(IntegerToString(*TestAddress));
	PrintString("\n\r");

	uint_64* TestAddress2 = (uint_64*)realloc(TestAddress, 0x08);
	PrintString(IntegerToString(*TestAddress2));
	PrintString("\n\r");

	uint_64* TestAddress3 = (uint_64*)calloc(0x08);
	PrintString(IntegerToString(*TestAddress));
	PrintString("\n\r");

	return;
}
