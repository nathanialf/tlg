/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 3 of the vtable at 0x16b35f0 (its pointer at 0x16b3618),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582b460: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_Chase" (its hash from FUN_013bad90), stored by the file's
 * initializer at 0xac22ea, which registers FUN_01331800 as the object's
 * destructor with __cxa_atexit. Written as a reference to an object declared
 * extern: the initializer's direct store makes it the file's own (D17), but
 * defining it here would need its constructor, not traced; the relaxed GOT
 * load is the same lea (D10). Class and method unknown. */
struct Object01331800; /* derived name: the record FUN_01331800 destroys */

extern Object01331800 D_582b460;

struct Object00ac2180;

const Object01331800 *FUN_00ac2180(const Object00ac2180 *self) /* derived name */
{
    return &D_582b460;
}
