#pragma once
#include <unordered_map>

#include "Allocator.h"

class CustomStringAllocator : public Allocator
{
public:

	explicit CustomStringAllocator(int totalSize);
		
	void* Allocate(size_t size) override;
	void Free(void* ptr, size_t size) override;
	void Init() override;
	char* AddNewMemory(char* oldStr, size_t size, const char* stringAdd, size_t strAddSize);

protected:
	std::unordered_map<void*, size_t> _memoryHoles;

	void* _startPtr = nullptr;

private:
	void* FindBestFit(size_t size);
	void* FindFirstFit(size_t size);
};
