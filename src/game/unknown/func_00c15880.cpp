/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_array01343a80.h"

/* derived names: FUN_00c15880 is this file's static initializer (the file
 * includes no vector header). A queue of 8-byte values: a ring of 65536 at
 * 0x58b7510 indexed by two counts under a lock (FUN_00c14bc0 takes the lock
 * at 0x5937518, tests tail - head against 0xffff and stores at the tail's
 * low 16 bits), and an array under its own lock for the values the ring
 * cannot take (0x5937520, a block of 8-byte elements). The array is
 * registered with its destructor (0x1370420). */
struct Queue00c15880 /* derived name */
{
    Queue00c15880() : head(0), tail(0), locked(0) {}

    unsigned head; /* +0x0 */
    unsigned tail; /* +0x4 */
    /* +0x8: 1 while a thread holds the queue, taken and given back by
     * compare and swap with Lock059458a4's wait (FUN_00c14bc0); cleared by a
     * plain store, the third of three apart (0xc1589c): an atomic store there
     * ends the sequence of plain stores and joins the two counts */
    int locked;
};

Queue00c15880 D_5937510;
Array01343a80<void *> D_5937520;
