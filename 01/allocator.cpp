#include "allocator.h"

void Allocator::makeAllocator(size_t _maxSize) {
    if (maxSize != 0) {
        maxSize = 0;
        offset = 0;
        delete ptr;
    }
    maxSize = _maxSize;
    if (maxSize != 0) {
        ptr = new char(maxSize);
    }
}
    
char* Allocator::alloc(size_t size) {
    if (offset + size <= maxSize) {
        size_t curr_offset = offset;
        offset += size;
        return (ptr + curr_offset);
    } else {
        return nullptr;
    }
}
    
void Allocator::reset() {
    offset = 0;
}

Allocator::~Allocator() {
    maxSize = 0;
    offset = 0;
    delete ptr;
}