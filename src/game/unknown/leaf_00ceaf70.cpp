/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bda38.h"
#include "tlg_game_object05945a38.h"

extern Type00503fb0 *D_5946570; /* derived name: the physics attributes' type (leaf_00ce96b0.cpp) */

class Value00d44120 : public Object016b9108 /* derived name (leaf_00caaf40.cpp) */
{
};

/* derived name: the entry looked up is a name here, made for the call and
 * released after it; the answer is FUN_00ceaf70's */
int FUN_00d44120(Member05938c40_38 *record, Value00d44120 **found, const Name &entry,
                 int mode); /* derived name */

/* derived names: the object named "_default_physAttrib" of the type at
 * 0x5946570 made when there is none (the object itself not kept), then the
 * answer of FUN_00d44120 for the name "game/physattrib_lib" on the global
 * record's member at +0x38, nothing asked back; called by FUN_00cd9000 */
// NONMATCHING: frame slots only (module 70/78, 287 bytes as the base): the two names' slots
// are swapped (the first at [rbp-0x28] where the base has [rbp-0x30], the second the other way round)
// The base keeps the first name's index in ebx across FUN_00cbc5a0 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
int FUN_00ceaf70() /* derived name */
{
    D_5945a38->object(Name("_default_physAttrib"), D_5946570);
    return FUN_00d44120(D_5938c40->unknown38, 0, Name("game/physattrib_lib"), 0);
}
