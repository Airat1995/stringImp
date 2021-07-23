#include "CustomStringAllocator.h"

CustomStringAllocator::CustomStringAllocator(int totalSize) : Allocator(totalSize)
{
	CustomStringAllocator::Init();
}

void* CustomStringAllocator::Allocate(size_t size)
{
	void* dataAddress =nullptr;
	if (!_memoryHoles.empty())
	{
		dataAddress = FindBestFit(size);
		if (dataAddress != nullptr)
		{
			_memoryHoles.erase(dataAddress);
			return dataAddress;
		}

		dataAddress = FindFirstFit(size);
		if (dataAddress != nullptr)
		{
			_memoryHoles.erase(dataAddress);
			return dataAddress;
		}
	}


	const auto currentMaxAddress = reinterpret_cast<std::size_t>(_startPtr) + _used;
	if (_used + size > _totalSize)
	{
		throw std::exception("Unable to allocate more memory!");
	}

	const size_t nextAddress = currentMaxAddress + size;
	dataAddress = reinterpret_cast<void*>(nextAddress);
	_used += size;
	return dataAddress;
}

void* CustomStringAllocator::FindBestFit(size_t size)
{
	for (auto& hole : _memoryHoles)
	{
		if(hole.second == size)
			continue;
		return hole.first;
	}

	return nullptr;
}

void* CustomStringAllocator::FindFirstFit(size_t size)
{
	for (auto& hole : _memoryHoles)
	{
		if(hole.second == size)
			continue;
		return hole.first;
	}

	return nullptr;
}

void CustomStringAllocator::Free(void* ptr, size_t size)
{
	//memset(ptr, 0, size);	
	_memoryHoles.insert(std::pair<void*, size_t>(ptr, size));
}

void CustomStringAllocator::Init()
{
	if(_startPtr != nullptr)
		free(_startPtr);

	_startPtr = calloc(1, _totalSize);
}

char* CustomStringAllocator::AddNewMemory(char* oldStr, size_t size, const char* stringAdd, size_t strAddSize)
{
	const auto newStrStartPointer = static_cast<char*>(Allocate(size + strlen(stringAdd)));
	memcpy(newStrStartPointer, oldStr, size);
	memcpy(newStrStartPointer + size, stringAdd, strAddSize);

	return newStrStartPointer;
}
