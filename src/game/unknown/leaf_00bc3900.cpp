/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: releases the lock word at 0x58b6238 with a plain store of 0.
 * FUN_00bc3620 and FUN_00bc3780 take it with lock cmpxchg from 0 to 1,
 * sleeping between attempts; the word is reached by a direct RIP-relative
 * operand, so it is the file's own (D17). It is volatile because the program
 * treats it so, a lock word other threads take and release. Without its
 * readers in the file a plain int's store is deleted (GlobalOpt: never
 * loaded); with them either spelling keeps it. */
static volatile int D_58b6238;

void FUN_00bc3900() /* derived name */
{
    D_58b6238 = 0;
}
