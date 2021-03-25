#include <cstddef>

class Allocator
{
    char *ptr = nullptr;
    size_t maxSize = 0;
    size_t offset = 0;
public:
    void makeAllocator(size_t _maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator();
    
    size_t get_maxSize() {
        return maxSize;
    }
    
    size_t get_offset() {
        return offset;
    }
    
    char* get_ptr() {
        return ptr;
    }
};