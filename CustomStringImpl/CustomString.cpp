#include "CustomString.h"

#include <iostream>
CustomStringAllocator CustomString::StringAllocator = CustomStringAllocator(500000);

CustomString::CustomString(const char string[])
{	
	_size = strlen(string);
	_startPointer = static_cast<char*>(StringAllocator.Allocate(_size));
	_appendString = nullptr;
	for (size_t index = 0; index < _size; index++)
		_startPointer[index] = string[index];
}

CustomString::~CustomString()
{
	StringAllocator.Free(_startPointer, _size);
	_startPointer = nullptr;
	_size = 0;
}

void CustomString::AssignLinkedStringToThis(CustomString* appendString) noexcept
{
	_appendString = appendString;
}

CustomString* CustomString::AssignLinkedStringToCopy(CustomString* appendString)
{
	const auto newString = new CustomString(this);
	newString->_appendString = appendString;

	return newString;
}

void CustomString::AppendToThis(const char* stringAdd)
{
	const auto newStrLen = strlen(stringAdd);
	const auto newStrStartPointer = StringAllocator.AddNewMemory(_startPointer, _size, stringAdd, newStrLen);	
	StringAllocator.Free(_startPointer, _size);
	_startPointer = newStrStartPointer;
	_size = _size + newStrLen;
}

CustomString* CustomString::AppendToCopy(const char* stringAdd)
{
	const auto newString = new CustomString(this);
	newString->AppendToThis(stringAdd);

	return newString;
}

CustomString::CustomString(CustomString* currentString)
{
	_startPointer = currentString->_startPointer;
	_size = currentString->_size;
}

void CustomString::PrintString(std::ostream& stream, CustomString& string)
{
	for (size_t index = 0; index < string._size; index++)
		stream << string._startPointer[index];
		
	if(string._appendString != nullptr)
		PrintString(stream, *string._appendString);
}

std::ostream& operator<<(std::ostream& stream, CustomString& string)
{
	string.PrintString(stream, string);
	return stream;
}
