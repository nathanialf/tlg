/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback that stores its third argument, a pointer (rdx),
 * in the file's own pointer at 0x57ca6e0 (a direct RIP-relative store:
 * internal linkage, docs/DECISIONS.md D17); no instruction reads it (as for
 * 0x57ca6d8). FUN_001bd010 appends {6, its address, 0} as a 24-byte entry (lea
 * at 0x1d3503) to the array at +0x10 of the list at +0xb8 of the record at
 * +0x38 of the object the pointer at 0x5938c40 holds. Its first two arguments
 * are unused and their types not traced. Owner and meaning unknown. */
struct Record0021c660; /* derived name */

static Record0021c660 *D_57ca6e0;

void FUN_0021c660(void *, void *, Record0021c660 *record) /* derived name */
{
    D_57ca6e0 = record;
}
