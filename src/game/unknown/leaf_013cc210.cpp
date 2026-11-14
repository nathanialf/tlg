/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtable at 0x16d3470 (its pointer at
 * 0x16d34b8; slots 2 to 4 hkReferencedObject's, the deleting destructor
 * FUN_013cca40): a filter test. True when the mask at +0x4 of its second
 * argument is 0; else false unless the object has a record (the pointer at
 * +0x88) with a target (its pointer at +0x20) and the kind is 5, or 2 or 1
 * with the target's flag 8 at +0x60 set: then whether the target's mask at
 * +0x5c meets the argument's. The kinds, the masks and the objects are not
 * traced; the filter's own state is unused. */
struct Filter013cc210; /* derived name */

struct Query013cc210 { /* derived name */
    u8 unknown0[4];
    u32 mask4; /* +0x4 */
};

struct Target013cc210 { /* derived name */
    u8 unknown0[0x5c];
    u32 mask5c;  /* +0x5c */
    u32 flags60; /* +0x60 */
};

struct Record013cc210 { /* derived name */
    u8 unknown0[0x20];
    Target013cc210 *target20; /* +0x20 */
};

struct Object013cc210 { /* derived name */
    u8 unknown0[0x88];
    Record013cc210 *record88; /* +0x88 */
};

bool FUN_013cc210(const Filter013cc210 *, int kind, const Query013cc210 *query,
                  const Object013cc210 *object) /* derived name */
{
    const u32 mask = query->mask4;
    if (mask == 0)
        return true;
    const Record013cc210 *record = object->record88;
    if (!record)
        return false;
    const Target013cc210 *target = record->target20;
    if (!target)
        return false;
    if (kind == 1) {
        if (target->flags60 & 8)
            return (target->mask5c & mask) != 0;
        return false;
    }
    if (kind == 2) {
        if (target->flags60 & 8)
            return (target->mask5c & mask) != 0;
        return false;
    }
    if (kind == 5)
        return (target->mask5c & mask) != 0;
    return false;
}
