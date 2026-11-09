/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16cac28 (stored by FUN_002370b0 FUN_004080d0 FUN_0069d690 FUN_008c25c0
 * FUN_00909420 FUN_00a2b8c0 FUN_00cf67f0 FUN_00dff610 FUN_00e10cd0
 * FUN_00e82e80 FUN_013506c0), slot 0, as a tail call to FUN_013506c0, which
 * stores that vtable itself and whose only other caller is the deleting
 * destructor in slot 1 (0x1350870): FUN_013506c0 is the same class's base-
 * object destructor (D2), not a base class's. A separate D1 jumping to its D2
 * is not what the public 4.0.0 emits for a strong or an inline definition
 * under -mconstructor-aliases (an alias, or the D1 replaced by the D2): an
 * open question for the supervisor. Written as a free function on the record
 * until the destructor's row is named (a class form needs its D2 symbol). */
struct Object013506c0; /* derived name */

void FUN_013506c0(Object013506c0 *self); /* derived name */

void FUN_01350310(Object013506c0 *self) /* derived name */
{
    FUN_013506c0(self);
}
