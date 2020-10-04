#include "Memory.h"
#include "Typedefs.h"

void memset(void* start, uint_64 value, uint_64 num) {

	if (num <= 8) {
		uint_8* valPtr = (uint_8*)&value;
		for (uint_8* ptr = (uint_8*)start; ptr < (uint_8*)((uint_64)start + num); ptr++) {
			*ptr = *valPtr;
			valPtr++;
		}

		return;
	}

	uint_64 proceedingBytes = num % 8;
	uint_64 newnum = num - proceedingBytes;

	for (uint_64* ptr = (uint_64*)start; ptr < (uint_64*)((uint_64)start + newnum); ptr++) {
		*ptr = value;
	}

	uint_8* valPtr = (uint_8*)&value;
	for (uint_8* ptr = (uint_8*)((uint_64)start + newnum); ptr < (uint_8*)((uint_64)start + num); ptr++)
	{
		*ptr = *valPtr;
		valPtr++;
	}
}

void memcpy(void* destination, void* source, uint_64 num) {
	if (num <= 8) {
		uint_8* valPtr = (uint_8*)source;
		for (uint_8* ptr = (uint_8*)destination; ptr < (uint_8*)((uint_64)destination + num); ptr++) {
			*ptr = *valPtr;
			valPtr++;
		}

		return;
	}

	uint_64 proceedingBytes = num % 8;
	uint_64 newnum = num - proceedingBytes;
	uint_64* srcptr = (uint_64*)source;

	for (uint_64* destptr = (uint_64*)destination; destptr < (uint_64*)((uint_64)destination + newnum); destptr++) {
		*destptr = *srcptr;
		srcptr++;
	}

	uint_8* srcptr8 = (uint_8*)((uint_64)source + newnum);
	for (uint_8* destptr8 = (uint_8*)((uint_64)destination + newnum); destptr8 < (uint_8*)((uint_64)destination + num); destptr8++)
	{
		*destptr8 = *srcptr8;
		srcptr8++;
	}

}