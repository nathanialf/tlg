/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the two callbacks FUN_00535xxx hands FUN_01358440 (at
 * 0x53595b and 0x53599b) to walk a node's tree: each sets the counted
 * reference it is given to the node whose name at +0x210 is one wing
 * shoulder joint (the name looked up, not interned). The callback takes the
 * joint's own class: the reference compares the converted pointer first
 * (`cmp r14, rbx` at 0x537554), as a pointer of a class over the
 * reference's: the scene node's. */

extern const char D_15caf07[20];
extern const char D_15caf5e[20];

void FUN_005374d0(Object016b85e0 *joint,
                  AtomicRef0045c470<Object016b9108> *found) /* derived name */
{
    if (joint->name210 == Name(D_15caf07, false))
        found->set(joint);
}

void FUN_00537600(Object016b85e0 *joint,
                  AtomicRef0045c470<Object016b9108> *found) /* derived name */
{
    if (joint->name210 == Name(D_15caf5e, false))
        found->set(joint);
}
