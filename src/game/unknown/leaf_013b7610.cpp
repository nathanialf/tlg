/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00760920.h"

/* FUN_013b7610: an object whose int at +0x30 is not zero and whose number
 * at +0x48 is 12 or less has a reference to it appended to the record's
 * array of that number (FUN_00760920, called with a temporary reference)
 * and, when its pointer at +0x98 is set, to the array at +0x180; returns 1.
 * Its callers are not traced. */
int FUN_013b7610(Counted00760920 *object, Record013b7610 *record) /* derived name */
{
    if (object->unknown30 != 0 && object->kind48 < 13) {
        record->byKind[object->kind48].push(Ref00503fb0<Counted00760920>(object));
        if (object->unknown98)
            record->objects180.push(Ref00503fb0<Counted00760920>(object));
    }
    return 1;
}
