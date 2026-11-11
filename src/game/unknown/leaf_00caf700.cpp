/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 16 of the vtable at 0x16b8ea0 (its pointer at 0x16b8f30): when the
 * record has an object at +0x28, sets bit 0x20 of that object's byte at +0x24
 * and passes the record, the object's pointer at +0x258 and null to FUN_00cae240,
 * as a tail call. The object (this) is not read. Class and method unknown. */
struct Member00caf700 { /* derived name */
    u8 unknown0[0x24];
    u8 unknown24;
    u8 unknown25[0x233];
    void *unknown258;
};

struct Record00caf700 { /* derived name */
    u8 unknown0[0x28];
    Member00caf700 *unknown28;
};

void FUN_00cae240(Record00caf700 *record, void *object, void *value); /* derived name */

void FUN_00caf700(void *, Record00caf700 *record) /* derived name */
{
    Member00caf700 *member = record->unknown28;
    if (member) {
        member->unknown24 |= 0x20;
        FUN_00cae240(record, member->unknown258, 0);
    }
}
