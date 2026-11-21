/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016a9ba8.h"

struct Sensors00471b70; /* derived name: what the record holds at +0x238, not traced */

/* derived names: the record FUN_00c57870 finds (leaf_002c4210.cpp's) */
struct Record00471b70 {
    u8 unknown0[0x238];
    Sensors00471b70 *sensors; /* +0x238 */
};

extern u64 D_57cb848; /* derived name: the key looked up (leaf_002c4210.cpp's) */

Record00471b70 *FUN_00c57870(Owner00c57870 *owner, u64 key, int *cursor); /* derived name */
void FUN_002c6900(Sensors00471b70 *sensors, Object016a9ba8 *object, Record00471b70 *record,
                  void *value); /* derived name */
void FUN_002ca480(Sensors00471b70 *sensors, Object016a9ba8 *object, Record00471b70 *record,
                  void *value); /* derived name */

/* derived names: around slot 21 with the step, the record the owner at
 * +0x28 gives for the key at 0x57cb848 hands the object, itself and the
 * object's +0x308 to FUN_002c6900 before and FUN_002ca480 after, each time
 * only when +0x308 is set and the record holds a value at +0x238. */
void Object016a9ba8::slot29(float step)
{
    Record00471b70 *record = FUN_00c57870(unknown28, D_57cb848, 0);
    if (record && unknown308 && record->sensors)
        FUN_002c6900(record->sensors, this, record, unknown308);
    slot21(step);
    record = FUN_00c57870(unknown28, D_57cb848, 0);
    if (record && unknown308 && record->sensors)
        FUN_002ca480(record->sensors, this, record, unknown308);
}
