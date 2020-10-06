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
	
	uint_64* TestAddress = (uint_64*)aligned_alloc(0x4000, 0x10);
	PrintString(HexToString((uint_64)TestAddress));
	PrintString("\r\n");
	//free(TestAddress);

	uint_64* TestAddress2 = (uint_64*)malloc(0x4000);
	PrintString(HexToString((uint_64)TestAddress2));
	PrintString("\r\n");


	return;
}
