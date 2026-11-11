/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16c8170 (config/vtables.derived.base.txt), slot 0, FUN_00c9cf90, its
 * deleting one FUN_00c9cfb0 beside it: it stores the vtable and frees the
 * block the pointer at +0x10 holds through the C library's free (0x14b0238), a
 * tail call. The vtable is also stored by FUN_00c9cd10, FUN_00c9e2b0,
 * FUN_00c9e390 and the derived class's destructor FUN_00ca24c0. The block's
 * type is not traced. The deleting destructor frees the object itself through
 * free as well (`jmp 0x14b0238` after the body), the class's own operator
 * delete. */
#include "stdlib.h"

class Object00c9cf90 /* derived name */
{
  public:
    virtual ~Object00c9cf90();

    static void operator delete(void *p)
    {
        free(p);
    }

  private:
    u8 unknown8[8];
    void *unknown10; /* +0x10: the block it frees */
};

Object00c9cf90::~Object00c9cf90()
{
    free(unknown10);
}
