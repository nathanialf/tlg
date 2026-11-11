/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 21 of the vtable at 0x16b08a8 (its pointer at 0x16b0960): when the
 * record has an object at +0x28, sets bit 0x20 of that object's byte at +0x24
 * and passes the record, the object's pointer at +0x258 and its first argument to FUN_008f4020,
 * as a tail call. The object (this) is not read. Class and method unknown. */
struct Member008f5590 { /* derived name */
    u8 unknown0[0x24];
    u8 unknown24;
    u8 unknown25[0x233];
    void *unknown258;
};

struct Record008f5590 { /* derived name */
    u8 unknown0[0x28];
    Member008f5590 *unknown28;
};

void FUN_008f4020(Record008f5590 *record, void *object, void *value); /* derived name */

void FUN_008f5590(void *, void *value, Record008f5590 *record) /* derived name */
{
    Member008f5590 *member = record->unknown28;
    if (member) {
        member->unknown24 |= 0x20;
        FUN_008f4020(record, member->unknown258, value);
    }
}
