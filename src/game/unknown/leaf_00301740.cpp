/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a8430.h"

/* derived names: the record FUN_00c57870 finds (leaf_002c4210.cpp's) and
 * the object at its +0x238 */
struct Sensors00301740; /* derived name */

struct Record00301740 { /* derived name */
    u8 unknown0[0x238];
    Sensors00301740 *sensors; /* +0x238 */
};

extern u64 D_57cb848; /* derived name: the key looked up */

void FUN_003013c0(Object016a8430 *self);                                  /* derived name */
void FUN_00516350(Part00516350 *part);                                    /* derived name */
Record00301740 *FUN_00c57870(Owner00c57870 *owner, u64 key, int *cursor); /* derived name */
void FUN_002c1f50(Sensors00301740 *sensors);                              /* derived name */
void FUN_00c57220(Record00301740 *record);                                /* derived name */

/* derived names: slot 15 of the vtable at 0x16a8430 (its pointer at
 * 0x16a84b8). Class and method unknown. */
void Object016a8430::slot15()
{
    FUN_003013c0(this);
    if (Holder00301740 *holder = unknown6d0) {
        if (holder->unknown638)
            FUN_00516350(holder->unknown638);
        if (holder->unknown640)
            FUN_00516350(holder->unknown640);
    }
    if (unknown28) {
        int cursor = 0;
        if (Record00301740 *record = FUN_00c57870(unknown28, D_57cb848, &cursor)) {
            if (record->sensors)
                FUN_002c1f50(record->sensors);
            FUN_00c57220(record);
        }
    }
}
