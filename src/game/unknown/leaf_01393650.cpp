/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived name: the function pointer at 0x17ac730 through which this code
 * frees its blocks (as leaf_009066d0.cpp's) */
extern void (*D_17ac730)(void *block);

/* derived names: the class whose vtable is at 0x16cee20 (config/vtables.derived.base.txt):
 * a linear allocator over one block. Slot 0 (0x1393600) starts it over, the
 * mark kept as the largest used; slot 1 (0x1393620) hands out the next
 * bytes while they fit; slot 2 (the shared empty body 0x1af750) frees
 * nothing; slots 3 and 4 its destructors (0x1393650, 0x1393670). */
class Object01393650 /* derived name */
{
  public:
    virtual void reset();
    virtual void *allocate(int numBytes);

    virtual void release(void *) {}

    virtual ~Object01393650();

  private:
    char *block8;   /* +0x8 */
    int capacity10; /* +0x10 */
    int used14;     /* +0x14 */
    int peak18;     /* +0x18 */
};

/* FUN_01393650: the block freed when there is one */
Object01393650::~Object01393650()
{
    if (block8)
        D_17ac730(block8);
}
