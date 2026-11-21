/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0139b6b0.h"

/* derived names: the object a record's reference holds, as FUN_0135f640
 * reads it: an int at +0x30 that must be set and a mask at +0x64 */
struct Target0135f640 : Object016b9108 /* derived name */
{
    u8 unknown24[0xc];
    int unknown30; /* +0x30 */
    u8 unknown34[0x30];
    int mask64; /* +0x64 */
};

/* derived names: the records' holder (+0x27b0 and +0x29b0 of the object
 * FUN_00721xxx passes): the 64-byte records at +0x30 */
struct List0135f640 /* derived name */
{
    u8 unknown0[0x30];
    Array05943280<Entry0135f4e0> entries; /* +0x30 */
};

/* derived names: a choice made once (its callers call FUN_0135f640 while
 * the state at +0x0 is zero): the state, set to 1, and the index of the
 * record chosen, -1 for none */
struct Pick0135f640 /* derived name */
{
    /* 0x135f640: the record with the smallest value in [0, 1] whose object
     * is set, is not `except`, has its int at +0x30 set and none of `mask`'s
     * bits; each record's object referenced while it is looked at */
    void choose(const List0135f640 *list, const Object016b9108 *except,
                int mask); /* derived name */

    int state; /* +0x0 */
    int index; /* +0x4 */
};

// NONMATCHING: register assignment: the base keeps the released mark 0xdeadc0de in r12d across
// the loop (hoisted) and the holder in r13, the build materialises the mark at each release;
// the control flow and the reads are the base's.
void Pick0135f640::choose(const List0135f640 *list, const Object016b9108 *except, int mask)
{
    state = 1;
    index = -1;
    float best = 3.40282347e+38f;
    for (unsigned i = 0; i < list->entries.size(); i++) {
        const Entry0135f4e0 &entry = list->entries.at(i);
        const float value = entry.unknown20;
        Ref00503fb0<Target0135f640> target(static_cast<Target0135f640 *>(entry.unknown38.get()));
        if (value >= 0.0f && value <= 1.0f && target.get() && target.get() != except &&
            target.get()->unknown30 != 0 && value < best && (target.get()->mask64 & mask) == 0) {
            best = value;
            index = i;
        }
    }
}
