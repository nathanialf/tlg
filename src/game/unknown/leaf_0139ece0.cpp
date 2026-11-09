/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method returning the int at +0x8 of its argument,
 * slot 2 of the vtables at 0x16caee0 (stored by FUN_005114e0 FUN_01354780
 * FUN_01354f30), 0x16d0298 (stored by FUN_00bf9780 FUN_013a05f0) and 0x16d1c38
 * (stored by FUN_00cd5ca0 FUN_013af5c0), callable holders whose slots 0 and 1
 * copy them. The vtable fixes the signature; the object is unused. The 32-bit
 * load gives the width; int is not traced further. */
struct Object0139ece0;

struct Item0139ece0 {
    u8 unknown0[0x8];
    int unknown8;
};

int FUN_0139ece0(const Object0139ece0 *, const Item0139ece0 *item) /* derived name */
{
    return item->unknown8;
}
