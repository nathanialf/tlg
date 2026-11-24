/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_record01352f40.h"

/* derived names: eight owned records (FUN_0047f7e0 calls FUN_004bbeb0 on
 * them); the rest of the holder is not traced */
struct Records004bbeb0 {        /* derived name */
    Record01352f40 *records[8]; /* +0x0 */
};

/* FUN_004bbeb0: each record deleted (FUN_01352f40, then operator delete)
 * and its pointer cleared */
void FUN_004bbeb0(Records004bbeb0 *self) /* derived name */
{
    for (int i = 0; i < 8; ++i) {
        delete self->records[i];
        self->records[i] = 0;
    }
}
