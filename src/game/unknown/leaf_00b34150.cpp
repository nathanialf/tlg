/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b5608.h"

Object016b5608::~Object016b5608()
{
    FUN_00b342b0();
}

/* derived name: the function pointer at 0x17ac730 through which this code
 * frees its blocks (leaf_009066d0.cpp) */
extern void (*D_17ac730)(void *block);

void FUN_009066d0(Object009066d0 *object); /* derived name */

// NONMATCHING: instruction order only: the base zeroes the entries' offset (`xor ebx,
// ebx`) above the loop's guard on the count, the build after it; the rest is equal.
void Object016b5608::FUN_00b342b0()
{
    for (int i = 0; i < 9; ++i) {
        if (objects[i]) {
            FUN_009066d0(objects[i]);
            objects[i] = 0;
        }
    }
    if (Table016b5608 *released = table) {
        for (int i = 0; i < released->count; ++i) {
            if (released->entries[i].flags & 1) {
                if (released->entries[i].block)
                    D_17ac730(released->entries[i].block);
                released->entries[i].block = 0;
                released->entries[i].unknown58 = 0;
            }
        }
        if (released->unknown40)
            D_17ac730(released->unknown40);
        if (released->entries)
            D_17ac730(released->entries);
        D_17ac730(released);
        table = 0;
    }
}
