/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: the complete destructor (slot 0 of the vtable at
 * 0x16a6480) of a class whose constructor FUN_00181b10 runs the base
 * constructor FUN_0019be50. It adds nothing to destroy and runs the base's
 * destructor body FUN_0019c150, which stores the base's vtable (0x16a6970);
 * the deleting destructor FUN_00181ba0 frees 0x140 bytes by default.
 * Written as a call: the classes (hkBinaryPackfileWriter over
 * hkPackfileWriter, derived names) are named, their destructors not yet
 * written as such. */
struct hkPackfileWriter; /* derived name */

void FUN_0019c150(hkPackfileWriter *self); /* derived name */

void FUN_00181bf0(hkPackfileWriter *self) /* derived name */
{
    FUN_0019c150(self);
}
