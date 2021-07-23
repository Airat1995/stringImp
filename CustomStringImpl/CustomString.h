#pragma once
#include "CustomStringAllocator.h"

class CustomString
{
public:

	CustomString(const char string[]);
	~CustomString();

	void AssignLinkedStringToThis(CustomString* appendString) noexcept;
	CustomString* AssignLinkedStringToCopy(CustomString* appendString);

	void AppendToThis(const char* stringAdd);
	CustomString* AppendToCopy(const char* stringAdd);

	friend std::ostream& operator<<(std::ostream& stream, CustomString& string);
	void PrintString(std::ostream& stream, CustomString& string);
	
private:

	//Copy constructor to be able append another string, without allocating new array of chars
	CustomString(CustomString* currentString);

	size_t _size = 0;
	char* _startPointer;
	CustomString* _appendString;

	static CustomStringAllocator StringAllocator;
};