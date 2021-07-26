#pragma once
#include <vector>

#include "Allocator.h"

class DumbStringAllocator : public Allocator
{
public:
	DumbStringAllocator(int totalSize);
	
	void* Allocate(size_t size) override;
	void Free(void* ptr, size_t size) override;
protected:
	void Init() override;

	std::vector<void*> _emptyPointers;

	void* _startPtr = nullptr;

private:
	std::vector<void*>::iterator FindBestFit();

};
