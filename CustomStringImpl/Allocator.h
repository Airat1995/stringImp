#pragma once
#include <cstddef>

class Allocator
{
protected:
	size_t _totalSize;
	size_t _used;
	size_t _peak;

public:
	Allocator(size_t totalSize) : _totalSize { totalSize }, _used { 0 }, _peak { 0 } { }

    virtual ~Allocator() { _totalSize = 0; }

    virtual void* Allocate(size_t size) = 0;

    virtual void Free(void* ptr, size_t size) = 0;
protected:
    virtual void Init() = 0;

};