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
	void* TestMemoryAddress = malloc(0x10);
	void* TestMemoryAddress2 = malloc(0x10);
	void* TestMemoryAddress3 = malloc(0x10);

	PrintString(HexToString((uint_64)TestMemoryAddress));
	PrintString("\n\r");
	PrintString(HexToString((uint_64)TestMemoryAddress2));
	PrintString("\n\r");
	PrintString(HexToString((uint_64)TestMemoryAddress3));

	free(TestMemoryAddress);
	free(TestMemoryAddress2);
	free(TestMemoryAddress3);

	void* Test4 = malloc(0x60);

	PrintString("\n\r");
	PrintString(HexToString((uint_64)Test4));

	return;
}
