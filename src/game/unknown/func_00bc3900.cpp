/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: FUN_00bc3900 is this file's static initializer. Its one
 * object is a lock word the file's functions take and give with
 * `lock cmpxchg` (0xbc365d, 0xbc3702, 0xbc374e, 0xbc37b9, 0xbc3861,
 * 0xbc38a9): the constructor clears it, a store the optimizer keeps because
 * the word is volatile (other threads change it). */
struct LockWord00bc3900 /* derived name */
{
    LockWord00bc3900() : word(0) {}

    volatile int word; /* +0x0: changed by other threads (lock cmpxchg) */
};

LockWord00bc3900 D_58b6238;
