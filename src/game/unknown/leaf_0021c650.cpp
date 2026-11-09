/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a callback that stores its third argument, a pointer (rdx),
 * in the file's own pointer at 0x57ca6d8 (a direct RIP-relative store:
 * internal linkage, docs/DECISIONS.md D17); no instruction reads it (GlobalOpt
 * keeps the store: a never-loaded pointer is a leak-checker root, whose
 * cleanup deletes only stores of dead allocations,
 * tools/cc/src/llvm-4.0.0.src/lib/Transforms/IPO/GlobalOpt.cpp:1846 and :71).
 * FUN_001bd010 appends {5, its address, 0} as a 24-byte entry (lea at
 * 0x1d3447) to the array at +0x10 of the list at +0xb8 of the record at +0x38
 * of the object the pointer at 0x5938c40 holds. Its first two arguments are
 * unused and their types not traced. Owner and meaning unknown. */
struct Record0021c650; /* derived name */

static Record0021c650 *D_57ca6d8;

void FUN_0021c650(void *, void *, Record0021c650 *record) /* derived name */
{
    D_57ca6d8 = record;
}
