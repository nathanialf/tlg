/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the object of slot 9 of the vtable at 0x16b06b0 (its
 * pointer at 0x16b0708; stored by FUN_008ef8a0 and FUN_008efe80): the
 * pointer at +0x40 that slot 10 (FUN_008f09c0) tests. The second argument's
 * name at +0x1bc. Class and method unknown. */
struct Object008f0900 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40; /* type not traced */
};

struct Other008f0900 { /* derived name */
    u8 unknown0[0x1bc];
    Name name; /* +0x1bc */
};

/* derived name: a copy of the name "VERTEX_MODIFIER" when the pointer at
 * +0x40 is set (a static of the function at 0x581fac0, its guard at
 * 0x581fab8, interned once as a copy: FUN_013baad0's last
 * argument 0, destroyed at exit with Name's destructor), else a copy of the
 * other object's name */
Name FUN_008f0900(const Object008f0900 *self, const Other008f0900 *other) /* derived name */
{
    if (self->unknown40) {
        static Name D_581fac0("VERTEX_MODIFIER", false);
        return D_581fac0;
    }
    return other->name;
}
