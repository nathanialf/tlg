/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: a buffer member: its block at +0x0, a count at +0x8, flags
 * at +0xc (bit 0: the block is not its own; bit 4 survives a reset) and an
 * int at +0x10. Its destructor releases an owned block and resets the rest. */
struct Buffer00d650e0 { /* derived name */

    ~Buffer00d650e0()
    {
        if (!(flags & 1))
            releaseBlock(block);
        block = 0;
        count = 0;
        flags &= 0x10;
        unknown10 = 0;
    }

    void *block;    /* +0x0 */
    int count;      /* +0x8 */
    unsigned flags; /* +0xc */
    int unknown10;  /* +0x10 */
};

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16baa48 (config/vtables.derived.base.txt; made by FUN_00d64f10): it
 * stores the vtable, passes the object to FUN_00d65170, destroys the buffer
 * at +0x50 and runs its base's destructor FUN_00d30550 as a tail call.
 * FUN_00d655d0, slot 1, is the deleting one; slot 2 is FUN_00cb66f0. The
 * destructor is the class's key function, so this file emits the vtable. */
class Object00d30550 /* derived name */
{
  public:
    virtual ~Object00d30550();
};

class Object016baa48 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object016baa48();

  private:
    u8 unknown8[0x48];
    Buffer00d650e0 unknown50; /* +0x50 */
};

void FUN_00d65170(Object016baa48 *self); /* derived name */

// NONMATCHING: the base reads the flags into a register for the bit test and joins the skip path to `and eax, 0x10` with it, reloading only after the release (one merged block: a load PRE'd from one unavailable predecessor); the build reaches the join from the release's exits separately and keeps `and dword [rbx+0x5c], 0x10`
Object016baa48::~Object016baa48()
{
    FUN_00d65170(this);
}
