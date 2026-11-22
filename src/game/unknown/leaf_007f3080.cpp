/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names throughout: FUN_007f3080 of the record at +0x70 of the
 * game's record (0x57c9390), called once at 0x528662 with a character whose
 * flag 4 at +0x4d is set. None of the fields is traced beyond what this
 * function reads. */
struct Character007f3080;

struct Item007f3080 { /* derived name */
    u8 unknown0[0xc];
    int id; /* +0xc */
    u8 unknown10[0x110];
    Character007f3080 *owner120; /* +0x120 */
    u8 unknown128[0x8];
    int unknown130; /* +0x130 */
};

struct Holder007f3080 { /* derived name */
    u8 unknown0[0xd8];
    Array05943280<Item007f3080 *> items; /* +0xd8 */
};

struct Actor007f3080 { /* derived name */
    u8 unknown0[0x24];
    u8 flags24; /* +0x24: 1 while it is active */
    u8 unknown25[0x23b];
    Holder007f3080 *holder260; /* +0x260 */
    u8 unknown268[0x30];
    Array05943280<Item007f3080 *> items; /* +0x298 */
};

struct Part007f3080 { /* derived name */
    u8 unknown0[0x24];
    int id; /* +0x24 */
    u8 unknown28[0x4];
    int group; /* +0x2c */
    u8 unknown30[0xc];
    u32 flags3c; /* +0x3c */
};

struct Character007f3080 { /* derived name */
    u8 unknown0[0x28];
    int group; /* +0x28 */
    u8 unknown2c[0x49f4];
    Character007f3080 *target4a20; /* +0x4a20 */
};

struct Entry007f3080 { /* derived name */
    const Character007f3080 *character;
    Actor007f3080 *actor;
    Part007f3080 *part;
};

struct Record007f3080 { /* derived name */
    u8 unknown0[0x550];
    Array05943280<Entry007f3080> entries; /* +0x550 */
};

/* derived names: the character's entry with an active actor found, the
 * actor's item with the part's id looked up in its holder and then in its
 * own list; 1 when the item's int at +0x130 is set, or when the
 * character's target is of the part's group (the part's flag 0x10 set) and
 * the item's owner is not */
int FUN_007f3080(Record007f3080 *record, const Character007f3080 *character) /* derived name */
{
    for (unsigned i = 0; i < record->entries.size(); ++i) {
        const Entry007f3080 &entry = record->entries.at(i);
        if (entry.character != character || !(entry.actor->flags24 & 1))
            continue;
        Part007f3080 *part = entry.part;
        Actor007f3080 *actor = entry.actor;
        Item007f3080 *item = 0;
        bool found = false;
        Holder007f3080 *holder = actor->holder260;
        for (unsigned j = 0; j < holder->items.size(); ++j) {
            if (holder->items.at(j)->id == part->id) {
                item = holder->items.at(j);
                found = true;
                break;
            }
        }
        if (!found) {
            for (unsigned j = 0; j < actor->items.size(); ++j) {
                if (actor->items.at(j)->id == part->id) {
                    item = actor->items.at(j);
                    break;
                }
            }
        }
        int result = 0;
        const Character007f3080 *target = character->target4a20;
        if (target && (part->flags3c & 0x10) && part->group == target->group) {
            const Character007f3080 *owner = item->owner120;
            if (!owner || part->group != owner->group)
                result = 1;
        }
        if (item->unknown130)
            return 1;
        return result;
    }
    return 0;
}
