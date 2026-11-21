/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d1520.h"

struct List059396d0; /* derived name; leaf_00c63060.cpp */
extern List059396d0 *D_59396d0;

/* derived name: puts the object first in the list (leaf_00c63060.cpp); the
 * reference is passed by value */
void FUN_00c63060(List059396d0 *list, Ref00503fb0<Object016d1520> object);

/* derived name: the constructor: the base built from the name, the members
 * cleared (the array's first block from this thread's heap), the ints at
 * +0x6c and +0x70 set to 8 and 1, then the object puts itself in the list
 * at 0x59396d0 and sets bit 0 of the root class's flags at +0x20 (`or byte
 * [rbx+0x20], 1`). Its creator FUN_00c5f340 calls it. */
Object016d1520::Object016d1520(const Name &name)
    : Object01343880(name), unknown68(0), unknown6c(8), unknown70(1)
{
    FUN_00c63060(D_59396d0, Ref00503fb0<Object016d1520>(this));
    flags |= 1;
}
