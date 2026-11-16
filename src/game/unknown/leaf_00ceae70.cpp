/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d1e20.h"

/* derived names: the object at 0x5938c40 holds at +0xb0 the list the
 * constructor below adds its object to (FUN_00ce22e0, leaf_00ce22e0.cpp) */
struct List00ce22e0; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    List00ce22e0 *unknownb0; /* +0xb0 */
};

extern Object05938c40 *D_5938c40;

/* derived name: adds a counted reference to the list; the reference is
 * passed by value (a temporary at [rbp-0x28]) */
void FUN_00ce22e0(List00ce22e0 *list, Ref00503fb0<Object016b9108> object);

/* derived name: the constructor: the base built from the name, the members
 * cleared, then the object adds a reference to itself to the list the
 * object at 0x5938c40 holds at +0xb0. Its creator FUN_00ce96b0 calls it. */
Object016d1e20::Object016d1e20(const Name &name) : Object016b9108(name), held28(), unknown30()
{
    FUN_00ce22e0(D_5938c40->unknownb0, Ref00503fb0<Object016b9108>(this));
}
