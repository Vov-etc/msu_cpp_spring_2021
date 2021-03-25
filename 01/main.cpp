#include "allocator.h"
#include <iostream>

int main() {
    Allocator a;
    a.makeAllocator(0);
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    a.makeAllocator(4);
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    a.makeAllocator(2);
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    std::cout << int(a.alloc(1)) << std::endl;
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    std::cout << int(a.alloc(1)) << std::endl;
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    a.reset();
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    std::cout << int(a.alloc(3)) << std::endl;
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    a.reset();
    std::cout << a.maxSize << " " << a.offset << " " << int(a.ptr) << std::endl;
    
    return 0;
}