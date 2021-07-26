#pragma once
#include <ostream>

class DumbString
{
private:

	static const size_t MAX_STR_LEN = 256;
	
	friend std::ostream& operator<<(std::ostream& stream, DumbString& string);

	char _data[MAX_STR_LEN];
	size_t _size;
public:
	DumbString(const char* string);

	void AppendToThis(const char* stringAdd);
};
