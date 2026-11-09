/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 8 of the vtables at 0x16d72e0 (its pointer at 0x16d7330)
 * and 0x16d7338 (its pointer at 0x16d7388), both stored by FUN_0122be10 (the
 * first counted from the nearest stored vtable), whose slot 7 is FUN_01243810:
 * it calls that method directly, not through the vtable, as a tail call, with
 * 0 inserted as its third argument and its own int passed as the fourth.
 * FUN_01243810 indexes the record at +0x8 of its second argument (0x140-byte
 * entries) with the third and returns nothing (no register written before its
 * returns); its twin of the same size is FUN_00fb0cf0. Class and method
 * unknown; the direct call is written as a call to the method's FUN_ row. */
struct Object01243810; /* derived name */
struct Target01243810; /* derived name */

void FUN_01243810(Object01243810 *self, Target01243810 *target, int first,
                  int second); /* derived name */

void FUN_0147e150(Object01243810 *self, Target01243810 *target, int second) /* derived name */
{
    FUN_01243810(self, target, 0, second);
}
