/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the pointer at +0x10 of its record is set, hands it to
 * the caller through the third argument, clears it and returns the record's
 * first word; returns 0 otherwise. Its address is stored by FUN_00de3540
 * beside its context in the record passed to FUN_00dd38c0's caller; the first
 * argument is unused. The pointee types are not traced. */
struct Context013c8870; /* derived name */
struct Item013c8870;    /* derived name */

struct Record013c8870 { /* derived name */
    void *unknown0;
    u8 unknown8[8];
    Item013c8870 *unknown10;
};

void *FUN_013c8870(Context013c8870 *, Record013c8870 *record,
                   Item013c8870 **item) /* derived name */
{
    Item013c8870 *taken = record->unknown10;
    if (!taken) {
        return 0;
    }
    *item = taken;
    record->unknown10 = 0;
    return record->unknown0;
}
