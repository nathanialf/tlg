/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: hands the six RBRElocater_ script functions' names, one
 * call each, to FUN_00c89a10 with the object at +0x40 of the one the
 * pointer at 0x5938c40 holds, nothing done when it is null; called once,
 * from 0x1f9230. FUN_00cf1cf0 (leaf_00cf1cf0.cpp) does the same for the
 * RBSnooper_ ones. The object's class and what FUN_00c89a10 does with a
 * name are not traced. */
struct Registry05938c40_40; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x40];
    Registry05938c40_40 *unknown40;
};

extern Object05938c40 *D_5938c40;

void FUN_00c89a10(Registry05938c40_40 *registry, const char *name); /* derived name */

void FUN_00a07bd0() /* derived name */
{
    Registry05938c40_40 *registry = D_5938c40->unknown40;
    if (registry) {
        FUN_00c89a10(registry, "RBRElocater_Regist");
        FUN_00c89a10(registry, "RBRElocater_Unregist");
        FUN_00c89a10(registry, "RBRElocater_Prepare");
        FUN_00c89a10(registry, "RBRElocater_Do");
        FUN_00c89a10(registry, "RBRElocater_AllPrepare");
        FUN_00c89a10(registry, "RBRElocater_AllDo");
    }
}
