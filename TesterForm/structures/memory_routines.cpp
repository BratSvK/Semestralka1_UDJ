#include "memory_routines.h"

namespace structures {
	byte & MemoryRoutines::byteSet(byte & B)
	{
		// 1 byte = 255 
		B = MAX_BYTE;
		return B;
	}
	byte & MemoryRoutines::byteReset(byte & B)
	{
		B = 0;
		return B;
	}
	byte & MemoryRoutines::byteXOR(byte & B)
	{
			// spytat sa ucitela 
		return B;
	}
	byte & MemoryRoutines::byteSHL(byte & B)
	{
		B << 1;
		return B;
	}
	byte & MemoryRoutines::byteSHR(byte & B)
	{
		B >> 1;
		return B;
	}
	bool MemoryRoutines::byteNthBitGet(byte & B, int n)
	{
		return (B >> n) & 1;
	}

	byte & MemoryRoutines::byteNthBitTo0(byte & B, int n)
	{
		
		return byteNthBitGet(B, n) ? B = B ^ n : B;
	}

	byte & MemoryRoutines::byteNthBitTo1(byte & B, int n)
	{
		return  byteNthBitGet(B, n) ? B : B = ~B;
		
	}

	byte & MemoryRoutines::byteNthBitToggle(byte & B, int n)
	{
		//TODO 01: MemoryRoutines
		return B = ~B;
	}

	MemoryRoutines::MemoryRoutines()
	{
	}

}
