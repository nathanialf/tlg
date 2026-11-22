/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */

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
