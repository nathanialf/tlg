/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 6 of 161 vtables from 0x16a76f8 (stored by FUN_00204080
 * FUN_00204320 FUN_007609e0) to 0x16d2f28, one body folded across their
 * classes (slot 2 FUN_00cb66f0 and the empty slots 3 and 4 in each, as
 * Object016b9108): stores its argument, a 64-bit value, at +0x28. No reader
 * of +0x28 found in 0x16a76f8's own methods; the field's type is not traced. */
struct Object01343880 /* derived name */
{
    unsigned char unknown0[0x28];
    void *value28; /* +0x28 */
};

void FUN_01343880(Object01343880 *self, void *value) /* derived name */
{
    self->value28 = value;
}
