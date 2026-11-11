/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <stddef.h>

/* derived names: the owner of the allocation calls below: a reallocation
 * function at +0x120 called as (user data, block, old size, new size), its
 * user data at +0x128 and the bytes held at +0x130; a block is freed by
 * subtracting its size and calling the function with a new size of 0, as
 * FUN_00c36a80 frees a 0xc30-byte object (0xc375a3). */
struct Allocator00d96d30 /* derived name */
{
    u8 unknown0[0x120];
    void *(*reallocate)(void *userData, void *block, size_t oldSize, size_t newSize); /* +0x120 */
    void *userData;                                                                   /* +0x128 */
    size_t bytesHeld;                                                                 /* +0x130 */

    void free(void *block, size_t size)
    {
        bytesHeld -= size;
        reallocate(userData, block, size, 0);
    }
};

/* derived names: the class whose vtable is at 0x16baf50
 * (config/vtables.derived.base.txt), a buffer of 0xc00 bytes held in the
 * object (+0x10) until it grows into a block of the allocator at +0x8 (the
 * pointer at +0xc10, its size at +0xc18). The complete destructor 0xd96d30
 * frees the block when the pointer is not the object's own storage; the
 * deleting one 0xd96d70 is the compiler's. FUN_00c36a80 inlines it
 * (0xc37554). The destructor is the class's key function. */
class Object00d96d30 /* derived name */
{
  public:
    virtual ~Object00d96d30();

  private:
    Allocator00d96d30 *allocator; /* +0x8 */
    u8 storage[0xc00];            /* +0x10 */
    u8 *data;                     /* +0xc10 */
    size_t capacity;              /* +0xc18 */
};

// NONMATCHING: list-ilp order, the allocator (+0x8) and the size (+0xc18) loaded the other way
// round (base: the allocator first, as FUN_00c36a80's inlined copy); the rest equal, D1 and D0
Object00d96d30::~Object00d96d30()
{
    if (data != storage)
        allocator->free(data, capacity);
}
