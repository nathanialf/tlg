/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_sce_kernel.h"
#include "tlg_types.h"

/* derived names: an object of the list whose bit 1 of +0x4c marks it for
 * FUN_00cf1630; the other fields are not traced */
struct Item013a5420 { /* derived name */
    u8 unknown0[0x4c];
    u32 flags; /* +0x4c */
};

/* derived names: a list under a lock, with a flag set while it is walked */
struct List013a5420 { /* derived name */
    u8 unknown0[0x10];
    pthread_mutex_t mutex; /* +0x10 */
    int walking;           /* +0x18 */
    u8 unknown1c[0x1c];
    Array05943280<Item013a5420 *> items; /* +0x38 */
};

struct Object05938c40 { /* derived name: the object, seen from here */
    u8 unknown0[0xf78];
    List013a5420 *unknownf78; /* +0xf78 */
};

extern Object05938c40 *D_5938c40;

void FUN_00cf1630(Item013a5420 *item); /* derived name; not traced */

/* derived name: under the list's lock, every object of the list at +0xf78
 * of the object at 0x5938c40 with bit 1 of +0x4c set has it cleared and is
 * passed to FUN_00cf1630 */
void FUN_013a5420() /* derived name */
{
    List013a5420 *list = D_5938c40->unknownf78;
    scePthreadMutexLock(&list->mutex);
    list->walking = 1;
    for (Item013a5420 *item : list->items) {
        if (item->flags & 2) {
            item->flags &= ~2u;
            FUN_00cf1630(item);
        }
    }
    list->walking = 0;
    scePthreadMutexUnlock(&list->mutex);
}
