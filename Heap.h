#pragma once
#include "Typedefs.h"
#include "Memory.h"

struct MemorySegmentHeader {
	uint_64 MemoryLength;
	MemorySegmentHeader* NextSegment;
	MemorySegmentHeader* PreviousSegment;
	MemorySegmentHeader* NextFreeSegment;
	MemorySegmentHeader* PreviousFreeSegment;
	bool Free;
};

struct AlignedMemorySegmentHeader {
	uint_64 MemorySegmentHeaderAddress : 63;
	bool IsAligned : 1;
};

extern MemorySegmentHeader* FirstFreeMemorySegment;

void InitializeHeap(uint_64 heapAddress, uint_64 heapLength);

void* calloc(uint_64 size);

void* realloc(void* address, uint_64 newSize);

void* malloc(uint_64 size);

void* aligned_alloc(uint_64 alignment, uint_64 size);

void free(void* address);