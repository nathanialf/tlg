/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: passes its arguments on to FUN_001aaaf0 as a tail call, the
 * only reference to that function, which follows it in the file at +0x10; no
 * reference (the base-object form is not called either). FUN_001aaaf0 fills
 * the object's ints at +0x0 to +0x24 and pointers at +0x28 and +0x30 from the
 * record its second argument points to; the pointer type is not traced. The
 * shape of a complete-object constructor delegating to the base-object one,
 * emitted on its own as clang 3.3 does for a linkonce definition (NOTES,
 * rounds 74A and 73B on 0x195fe0); written as a free function on that object
 * until the class is modelled. */
struct Object001aaaf0; /* derived name */

void FUN_001aaaf0(Object001aaaf0 *self, void *source); /* derived name */

void FUN_001aaae0(Object001aaaf0 *self, void *source) /* derived name */
{
    FUN_001aaaf0(self, source);
}
