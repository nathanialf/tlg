/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a job callback (its address taken by FUN_00cdde30, lea at
 * 0xce084d): runs FUN_00ce4970 on its record with the two ints at +0x20 and +0x24,
 * then raises the shared count its pointer at +0x28 names with one locked
 * increment. Record and job unknown. */
struct Record00ce4c60 { /* derived name */
    u8 unknown0[0x20];
    int unknown20;
    int unknown24;
    int *unknown28;
};

void FUN_00ce4970(Record00ce4c60 *record, int first, int second); /* derived name */

void FUN_00ce4c60(Record00ce4c60 *record) /* derived name */
{
    FUN_00ce4970(record, record->unknown20, record->unknown24);
    __sync_fetch_and_add(record->unknown28, 1);
}
