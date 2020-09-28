#pragma once
#include "Typedefs.h"

struct MemorySegmentHeader {
	uint_64 MemoryLength;
	MemorySegmentHeader* NextSegment;
	MemorySegmentHeader* PreviousSegment;
	MemorySegmentHeader* NextFreeSegment;
	MemorySegmentHeader* PreviousFreeSegment;
	bool Free;
};

void InitializeHeap(uint_64 heapAddress, uint_64 heapLength);

void* malloc(uint_64 size);

void free(void* address);