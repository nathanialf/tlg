/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16d0180 (config/vtables.derived.base.txt), slot 0 of it: it stores the
 * vtable, frees the block at +0x30 with the C library's free and clears the
 * pointer and the 8 bytes after it (one 16-byte store), then runs its base's
 * destructor FUN_0130acb0 (its row named for it, D15) as a tail call.
 * FUN_0139e090, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
class Object0130acb0 /* derived name */
{
  public:
    virtual ~Object0130acb0();
};

class Object0139e050 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object0139e050();

  private:
    u8 unknown8[0x28];
    void *unknown30; /* +0x30: freed with free */
    u64 unknown38;   /* +0x38: cleared with it */
};

Object0139e050::~Object0139e050()
{
    free(unknown30);
    unknown30 = 0;
    unknown38 = 0;
}
