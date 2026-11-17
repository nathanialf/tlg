/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: whether the object the name at 0x15aba40 names (of the
 * type the pointer at 0x5814678 holds, usable by this thread) is missing or
 * has its float at +0x1b4 at 0.9 or above. It reads no argument. The
 * object's class is not traced. */
struct Named006424c0 : Object016b9108 /* derived name */
{
    u8 unknown24[0x190];
    float unknown1b4; /* +0x1b4 */
};

extern const char D_15aba40[18];
extern const Type00503fb0 *D_5814678;

// NONMATCHING: 74 of 76. The float at +0x1b4 is converted from memory after a `vxorps` (round
// 260A's class: the memory-form vcvtss2sd); the build loads it with vmovss and converts the register.
bool FUN_006424c0() /* derived name */
{
    Named006424c0 *object = findNamed<Named006424c0>(Name(D_15aba40), D_5814678);
    return !object || object->unknown1b4 >= 0.9;
}
