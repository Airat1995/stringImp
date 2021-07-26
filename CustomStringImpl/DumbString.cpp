#include "DumbString.h"

DumbString::DumbString(const char* string) : _data{0}
{
	_size = strlen(string);
	memcpy(_data, string, _size);
}

void DumbString::AppendToThis(const char* stringAdd)
{
	const size_t  addSize = strlen(stringAdd);
	const size_t finalSize = _size + addSize;
	memcpy(_data + _size, stringAdd, addSize);
	_size = finalSize;
}

std::ostream& operator<<(std::ostream& stream, DumbString& string)
{
	for (size_t index = 0; index < string._size; index++)
		stream <<  string._data[index];

	return stream;
}