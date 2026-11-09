/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback that stores its third argument, a pointer (rdx),
 * in the file's own pointer at 0x57ca428 (a direct RIP-relative store:
 * internal linkage, docs/DECISIONS.md D17); FUN_01345f70 reads it (0x1346000).
 * FUN_00218e80 writes {3, its address, 0} as a 24-byte entry (lea at 0x21bc3f)
 * into the array it fills, as FUN_001bd010 does for the callbacks of round
 * 110A. Its first two arguments are unused and their types not traced. Owner
 * and meaning unknown. */
struct Record01345f50; /* derived name */

static Record01345f50 *D_57ca428;

void FUN_01345f50(void *, void *, Record01345f50 *record) /* derived name */
{
    D_57ca428 = record;
}
