#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>				// pre pracu s pamatou
#include <cstring>				

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),	   // kazdy ma svoju pamat a nedojde k ziadnemu prekryvu					 
		size_(size)								 
	{
	}

	// kopirovaci konstruktor 
	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		memory_ = memcpy(memory_, other.memory_, size_);
		
	}


	// domaca uloha 
	// move sematics
	// v dosledku vacsich objektov aby sa nekopirovali stale dokola
	// other -> parameter value, temporary valu or r-value
	// nebude to volat klasicky konstruktor kvoli r-value  
	// (Vector&&)(other.size_) => std::move(x)

	Vector::Vector(Vector&& other):
		Vector(std::move(other.size_))
	{
		// ako prve ideme presunut ukazovatele z other na old, ukradneme si daný ukazovael a ten other ppotom treba zrusit ako svedka pri kradezi :D  
		memory_ = std::move(other.memory_);

		// ked sme ukradli vsetko treba zrusit 
		// cistiace prace -> 
		other.memory_ = nullptr;
		other.size_ = 0;

	}

	// String string = "ahoj"
	// chceme to dat do Strin dst = string
	// potrebuejeme temporary premmenu z toho std::move()
	Vector& Vector::operator=(Vector&& other)
	{
		// pozor nebudeme davat dest = dest 
		if (this != &other)
		{
			// potrebuejeme prepisat nas aktualny objekt , pozor na memory leak
			delete memory_;

			size_ = other.size_;
			memory_ = other.memory_;

			other.size_ = 0;
			other.memory_ = nullptr;

		}


		return *this;
	}
	
	
	
	

	// destruktor 
	Vector::~Vector()
	{
		// upratovacie prace 
		free(memory_);			// uvolnenie pamate
		memory_ = nullptr;
		size_ = 0;
	}
	
	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);				// pretypujeme na vector 
		}
		return *this;
	}

	// operator priradenia druhý ked mam pretypovanie spravene 

	Vector& Vector::operator=(const Vector& other)
	{
		// nikdy nepriradujem samu do seba 
		if (this != &other)
		{
			// zmenime si velkost podla vectora other 
			size_ = other.size_;

			memory_ = realloc(memory_, size_);				// nehrozi mi nic zle, aby sme dostali rovnako velku pamat ako other
			// skopirujeme obsah pamate vektora other 
			memory_ = memcpy(memory_, other.memory_, size_);

		}

		return *this;
	}

	// porovnanie dvoch vektorov 
	bool Vector::operator==(const Vector& other) const
	{
		// memcpm vrati 0 ak su zhodne pamate 
		return size_ == other.size_ && memcmp(memory_, other.memory_, size_) == 0;
	}

	
	byte& Vector::operator[](const int index)
	{
		// posunut ukazovatel a pozriet sa co ukazuje  *() dereferencia na co ta sipka ukazuje 
		// ale mam smernik na void neviem posuvat -> treba povedat ze sa na to pozeram ako na byte nie na void 
		// treba osetrit index [0, size_) -> je na to trieda DSROUTINES
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector");
		return *(reinterpret_cast<byte*>(memory_) + index);


	}

	byte Vector::operator[](const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector");
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	


	// zapisovanie blok vectora do lokalnej premmenej int i = 1 - 0 0 0 1 
	// citam byte od indexu a zapisem do premmenej i 
	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		// kontrola platnosti pamate 
		// preto + 1 lebo sa pozera na hranicne velkosti ci je mensi 
		// OPYTAT SA NA TO -> kontroluje interval [ ) horna hranica vectora vzdy size_ + 1 aby som ten posledny este vzal  
		// ci su tie byte vnutri vectora 
		DSRoutines::rangeCheckExcept(index + count, size_ + 1, "Invalid end index");
		// kazdy ma svoje pam,atove miesto a ziadny prekryv nemame
		// 1.kontrola je getBytePointer
		memcpy(&dest, getBytePointer(index), count);
		return dest; 

	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		// pozor na prekryv a ci ma kopirovanie zmysel 
		if (length != 0)
		{
			// platny index
			DSRoutines::rangeCheckExcept(srcStartIndex, src.size_, "Invalid index in Vector src!");
			DSRoutines::rangeCheckExcept(destStartIndex, dest.size_, "Invalid index in Vector dest!");
			// ci kopirujem to co mi patri 
			DSRoutines::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid end index in Vector src!");
			DSRoutines::rangeCheckExcept(destStartIndex + length, dest.size_ + 1, "Invalid end index in Vector dest!");
			
		}

		// bud mozem pouzit istotu pri kopirovani ked kopirujem sa prekrývajú pamate
		// ked kopirujem v ramci sameho seba potom pozeram ci sa mi prekrýva pamat 
		if ((&src == &dest) && (((srcStartIndex >= destStartIndex) && (srcStartIndex < destStartIndex + length)) || ((destStartIndex >= srcStartIndex) && (destStartIndex < srcStartIndex + length))))
		{
			memmove(src.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else {
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length );
		}



		
	}


	// potrebujeme vratit iba smernik, ukazovatel na pamat(modra sipka)
	byte* Vector::getBytePointer(const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector");
		return reinterpret_cast<byte*>(memory_) + index;
	}

}