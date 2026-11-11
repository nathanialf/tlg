/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a reference-counted object: its count at +0x8, taken down
 * atomically; the holder of the last reference calls slot 2 to destroy it.
 * release() returns the count read again after the decrement. */
class Shared00e5aea0 /* derived name */
{
  public:
    virtual void slot0();   /* derived name; not traced */
    virtual void slot1();   /* derived name; not traced */
    virtual void destroy(); /* derived name; slot 2 */

    long release() /* derived name */
    {
        if (__sync_fetch_and_sub(&references, 1) == 1)
            destroy();
        return references;
    }

  private:
    /* volatile: the count other threads take and drop while this one
     * releases (the base reads it again after the decrement) */
    volatile long references; /* +0x8 */
};

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bdaa8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00e5acb0): it stores the vtable, releases the shared object it holds at
 * +0x270 and clears the pointer, then tail-calls its base's destructor
 * Object00c55550's (0xc55550). FUN_00e5af00, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. The
 * other members are not traced. */
class Object00c55550 /* derived name */
{
  public:
    virtual ~Object00c55550();
};

class Object016bdaa8 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016bdaa8();

  private:
    u8 unknown8[0x268];
    Shared00e5aea0 *shared270; /* +0x270 */
};

Object016bdaa8::~Object016bdaa8()
{
    if (shared270 != 0) {
        shared270->release();
        shared270 = 0;
    }
}
