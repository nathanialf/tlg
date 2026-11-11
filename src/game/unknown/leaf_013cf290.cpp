/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtables at 0x16d3800, 0x16d3d48 and 0x16d6a10:
 * whether the u32 at +0x8 is at least what slot 0 of the object at +0x10
 * returns. Class and method unknown. */
class Target013cf290 /* derived name */
{
  public:
    virtual u32 slot0(); /* derived name */
};

struct Object013cf290 { /* derived name */
    u8 unknown0[0x8];
    u32 unknown8;
    u8 unknownc[0x4];
    Target013cf290 *unknown10;
};

int FUN_013cf290(const Object013cf290 *self) /* derived name */
{
    return self->unknown8 >= self->unknown10->slot0();
}
