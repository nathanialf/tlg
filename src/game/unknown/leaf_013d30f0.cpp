/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d3750 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the block the pointer at +0x18 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The other members are not traced. */
class Object013d30f0 /* derived name */
{
  public:
    virtual ~Object013d30f0();
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    u32 *unknown18;     /* +0x18: owned block */
    unsigned count;     /* +0x20 */
    unsigned capacity;  /* +0x24 */
    unsigned allocator; /* +0x28: the index in D_5943280 of the owner of a new block */
};

Object013d30f0::~Object013d30f0()
{
    releaseBlock(unknown18);
}

/* derived name: slot 2 (FUN_013ce230): 28 entries, all zero. The block is
 * reallocated by its owner (the index in its header) or, when there is none,
 * allocated by the owner the object names, only when the capacity is not
 * already 28. */
// NONMATCHING: the base loads the table's address and the holder's allocator index in the entry block and redefines the index from the block's header in the other arm (one register, `lea rax; mov ecx, [rbx+0x28]` before `test rsi, rsi`); the build loads each in its own arm (an index helper by value, an owner looked up once: the same bytes)
void Object013d30f0::reset()
{
    count = 0;
    if (capacity != 28) {
        capacity = 28;
        unknown18 = static_cast<u32 *>(reallocateBlock(unknown18, 28 * sizeof(u32), 4, allocator));
    }
    count = 28;
    for (unsigned i = 0; i < count; i++)
        unknown18[i] = 0;
}
