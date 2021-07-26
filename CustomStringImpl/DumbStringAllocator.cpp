#include "DumbStringAllocator.h"

DumbStringAllocator::DumbStringAllocator(int totalSize) : Allocator(totalSize)
{
	DumbStringAllocator::Init();
}

void* DumbStringAllocator::Allocate(size_t size)
{
	if (!_emptyPointers.empty())
	{
		const std::vector<void*>::const_iterator dataAddress = FindBestFit();
		if (dataAddress != _emptyPointers.end())
		{
			const auto pointer = *dataAddress;
			_emptyPointers.erase(dataAddress);
			return pointer;
		}
	}


	const auto currentMaxAddress = reinterpret_cast<std::size_t>(_startPtr) + _used;
	if (_used + size > _totalSize)
	{
		throw std::exception("Unable to allocate more memory!");
	}

	const size_t nextAddress = currentMaxAddress + size;
	void* pointer = reinterpret_cast<void*>(nextAddress);
	_used += size;
	return pointer;
}

void DumbStringAllocator::Free(void* ptr, size_t size)
{
}

void DumbStringAllocator::Init()
{
	if (_startPtr != nullptr)
		free(_startPtr);

	_startPtr = calloc(1, _totalSize);
}

std::vector<void*>::iterator DumbStringAllocator::FindBestFit()
{
	return _emptyPointers.begin();
}
