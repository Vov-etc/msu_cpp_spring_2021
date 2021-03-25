#include "allocator.h"
#include <cassert>
#include <iostream>


void DefaulTest() {
    Allocator allctr;
    allctr.makeAllocator(3);
    assert(allctr.get_maxSize() == 3 && allctr.get_offset() == 0 && allctr.get_ptr() != nullptr );
}

void NullTest() {
    Allocator allctr;
    allctr.makeAllocator(0);
    assert(allctr.get_maxSize() == 0 && allctr.get_ptr() == nullptr);
}

void LargeAllocTest() {
    Allocator allctr;
    allctr.makeAllocator(2);
    char* ptr = allctr.alloc(3);
    assert(ptr == nullptr);
}

void BunchOfAllocTest() {
    Allocator allctr;
    allctr.makeAllocator(4);
    char* ptr_1 = allctr.alloc(2);
    size_t offset = allctr.get_offset();
    char* ptr_2 = allctr.alloc(2);
    assert(ptr_2 == ptr_1 + offset && offset == 2 && ptr_2 != nullptr && ptr_1 != nullptr);
}

void ResetTest() {
    Allocator allctr;
    allctr.makeAllocator(5);
    allctr.alloc(3);
    assert(allctr.get_offset() == 3);
    allctr.reset();
    assert(allctr.get_offset() == 0 && allctr.get_ptr() != nullptr);
}    

void BigDataTest() {
    Allocator allctr;
    allctr.makeAllocator(INT_MAX);
    char* ptr = allctr.alloc(INT_MAX);
    assert(ptr != nullptr);
}

int main() {
    DefaulTest();
    NullTest();
    LargeAllocTest();
    BunchOfAllocTest();
    ResetTest();
    BigDataTest();
    std::cout << "Success!" << std::endl;
    return 0;
}
