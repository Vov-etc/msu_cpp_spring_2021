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

void BunchOfMakeTest() {
    Allocator allctr;
    allctr.makeAllocator(4);
    size_t size_1 = allctr.get_maxSize();
    char* ptr_1 = allctr.get_ptr();
    allctr.makeAllocator(2);
    size_t size_2 = allctr.get_maxSize();
    char* ptr_2 = allctr.get_ptr();
    assert(size_1 != size_2);
    //assert(ptr_1 != ptr_2);      will not work, new allocation will be on the same position
}

int main() {
    DefaulTest();
    NullTest();
    LargeAllocTest();
    BunchOfAllocTest();
    ResetTest();
    BigDataTest();
    BunchOfMakeTest();
    std::cout << "Success!" << std::endl;
    return 0;
}
