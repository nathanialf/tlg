/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears a 0x80-byte record but its u32 at +0x34; called by
 * FUN_01303ee0, FUN_0131e9d0, FUN_01325f10 and others. The fields are not
 * traced. */
struct Record001af730 { /* derived name */
    u32 unknown0[13];
    u32 unknown34;
    u32 unknown38[18];
};

void FUN_001af730(Record001af730 *record) /* derived name */
{
    for (int i = 0; i < 13; ++i) {
        record->unknown0[i] = 0;
    }
    for (int i = 0; i < 18; ++i) {
        record->unknown38[i] = 0;
    }
}
