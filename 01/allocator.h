#include <cstddef>

class Allocator
{
public:
    char *ptr = nullptr;
    size_t maxSize = 0;
    size_t offset = 0;
    
    void makeAllocator(size_t _maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator();
};