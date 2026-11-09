/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 8 of the vtables at 0x16d4580 (its pointer at 0x16d45d0)
 * and 0x16d45d8 (its pointer at 0x16d4628), both stored by FUN_00fbb0f0 (the
 * first counted from the nearest stored vtable), whose slot 7 is FUN_00fb7520:
 * it calls that method directly, not through the vtable, as a tail call, with
 * 0 inserted as its third argument and its own int passed as the fourth.
 * FUN_00fb7520 indexes the record at +0x8 of its second argument (0x140-byte
 * entries) with the third and returns nothing (no register written before its
 * returns); its twin of the same size is FUN_01248760. Class and method
 * unknown; the direct call is written as a call to the method's FUN_ row. */
struct Object00fb7520; /* derived name */
struct Target00fb7520; /* derived name */

void FUN_00fb7520(Object00fb7520 *self, Target00fb7520 *target, int first,
                  int second); /* derived name */

void FUN_013e3920(Object00fb7520 *self, Target00fb7520 *target, int second) /* derived name */
{
    FUN_00fb7520(self, target, 0, second);
}
