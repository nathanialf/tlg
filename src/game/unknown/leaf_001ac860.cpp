/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_001ac870 as a tail call, the
 * only reference to that function, which follows it in the file at +0x10; no
 * reference, while FUN_001aed80, FUN_001af110 and FUN_001af4a0 call
 * FUN_001ac870 itself on stack objects. FUN_001ac870 takes the object and a
 * pointer, its type not traced. The shape of a complete-object constructor
 * delegating to the base-object one, emitted on its own as clang 3.3 does for
 * a linkonce definition (NOTES, rounds 74A and 73B on 0x195fe0); written as a
 * free function on that object until the class is modelled. */
struct Object001ac870; /* derived name */

void FUN_001ac870(Object001ac870 *self, void *source); /* derived name */

void FUN_001ac860(Object001ac870 *self, void *source) /* derived name */
{
    FUN_001ac870(self, source);
}
