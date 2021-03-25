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
    allctr.makeAllocator(5);
    char* ptr_1 = allctr.alloc(2);
    size_t offset = allctr.get_offset();
    char* ptr_2 = allctr.alloc(2);
    assert(ptr_2 == ptr_1 + offset && offset == 2);
}
    

int main() {
    DefaulTest();
    NullTest();
    LargeAllocTest();
    BunchOfAllocTest();
    std::cout << "Success!" << std::endl;
    return 0;
}
