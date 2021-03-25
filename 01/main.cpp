#include "allocator.h"
#include <iostream>

void print_Allocator(Allocator &a) {
    std::cout << "maxSize: " << a.maxSize << "    offset: " << a.offset << "    ptr: " << int(a.ptr) << std::endl;
}

int main() {
    Allocator a;
    a.makeAllocator(0);
    print_Allocator(a);
    
    a.makeAllocator(4);
    print_Allocator(a);
    
    a.makeAllocator(2);
    print_Allocator(a);
    
    std::cout << int(a.alloc(1)) << std::endl;
    print_Allocator(a);
    
    std::cout << int(a.alloc(1)) << std::endl;
    print_Allocator(a);
    
    a.reset();
    print_Allocator(a);
    
    std::cout << int(a.alloc(3)) << std::endl;
    print_Allocator(a);
    
    a.reset();
    print_Allocator(a);
    
    return 0;
}