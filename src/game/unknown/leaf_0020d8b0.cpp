/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback that stores its third argument, a pointer (rdx),
 * in the file's own pointer at 0x57ca0d0 (a direct RIP-relative store:
 * internal linkage, docs/DECISIONS.md D17); FUN_0020d8c0 reads it at 0x20d8e2,
 * 0x20d960 and 0x20dc90. FUN_001bd010 appends {6, its address, 0} as a 24-byte
 * entry (lea at 0x1c40b4) to the array at +0x10 of the list at +0xb8 of the
 * record at +0x38 of the object the pointer at 0x5938c40 holds. Its first two
 * arguments are unused and their types not traced. Owner and meaning unknown. */
struct Record0020d8b0; /* derived name */

static Record0020d8b0 *D_57ca0d0;

void FUN_0020d8b0(void *, void *, Record0020d8b0 *record) /* derived name */
{
    D_57ca0d0 = record;
}
