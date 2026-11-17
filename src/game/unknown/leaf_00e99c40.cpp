/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be4f0 (+0x60 from the vtable stored at
 * 0x16be490): has the motion properties library (+0x1038 of the record at
 * +0x370 of the object 0x5a8dbc0 holds) give back the entries the world at
 * +0x38 of the object's record at +0x268 no longer uses, then reads that
 * world's construction info into a local one and copies its broad phase box
 * to the box the record's +0x40 points at, corner by corner. The classes are not traced. */
struct Record00e99c40 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
    hkAabb *unknown40;
};

struct Object00e99c40 { /* derived name */
    u8 unknown0[0x268];
    Record00e99c40 *unknown268;
};

struct Physics05a8dbc0_370 { /* derived name */
    u8 unknown0[0x1038];
    hknpMotionPropertiesLibrary *unknown1038;
};

struct Physics05a8dbc0 { /* derived name */
    u8 unknown0[0x370];
    Physics05a8dbc0_370 *unknown370;
};

extern Physics05a8dbc0 *D_5a8dbc0;

void FUN_00e99c40(Object00e99c40 *self) /* derived name */
{
    Record00e99c40 *record = self->unknown268;
    D_5a8dbc0->unknown370->unknown1038->FUN_000372a0(record->unknown38, 1);
    hknpWorldCinfo info;
    record->unknown38->FUN_0004ab80(info);
    hkAabb *box = record->unknown40;
    box->min = info.broadPhaseAabb.min;
    box->max = info.broadPhaseAabb.max;
}
