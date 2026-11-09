/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the qsort comparator FUN_00dc31a0 passes when it sorts the
 * array of 8-byte object pointers at +0x90 of its record (its count at +0xa0)
 * before dropping duplicates: the elements are compared by the low 32 bits of
 * the pointers' difference, which orders them by address for objects closer
 * together than 2 GB. */
int FUN_00dde600(const void *a, const void *b) /* derived name */
{
    const char *left = *(const char *const *)a;
    const char *right = *(const char *const *)b;
    return (int)(left - right);
}
