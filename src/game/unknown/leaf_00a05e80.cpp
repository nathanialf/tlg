/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object05945a38.h"

/* derived names: makes one of four objects by kind (0 to 3, the jump table
 * 0x1558c10): FUN_00cbc5a0 with the object the pointer at 0x5945a38 holds,
 * the kind's type (the pointers at 0x5946d70, 0x5946cb0, 0x5946cc8, 0x5946d10),
 * the empty name and 0, the result passed to FUN_00cf8120 and returned; any
 * other kind gives null. */
extern Type00503fb0 *D_5946d70;
extern Type00503fb0 *D_5946cb0;
extern Type00503fb0 *D_5946cc8;
extern Type00503fb0 *D_5946d10;

void FUN_00cf8120(Object016b9108 *object); /* derived name */

/* each call keeps its own empty name and none is released: the module knows
 * FUN_00cbc5a0 only reads its name (it copies it at 0xcbc5d4) */
Object016b9108 *FUN_00a05e80(int kind) /* derived name */
{
    Object016b9108 *object;
    switch (kind) {
    case 0:
        object = FUN_00cbc5a0(D_5945a38, D_5946d70, Name(), 0);
        break;
    case 1:
        object = FUN_00cbc5a0(D_5945a38, D_5946cb0, Name(), 0);
        break;
    case 2:
        object = FUN_00cbc5a0(D_5945a38, D_5946cc8, Name(), 0);
        break;
    case 3:
        object = FUN_00cbc5a0(D_5945a38, D_5946d10, Name(), 0);
        break;
    default:
        return nullptr;
    }
    FUN_00cf8120(object);
    return object;
}
