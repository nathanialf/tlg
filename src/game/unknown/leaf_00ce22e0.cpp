/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the record at +0x378 of the list holds the counted
 * references at +0x28 (block +0x28, count +0x30, capacity +0x34, owner
 * index +0x38); the rest is not traced */
struct Record00ce22e0 { /* derived name */
    u8 unknown0[0x28];
    Array05943280<AtomicRef0045c470<Object016b9108>> objects; /* +0x28 */
};

struct List00ce22e0 { /* derived name */
    u8 unknown0[0x378];
    Record00ce22e0 *record; /* +0x378 */
};

/* The references are tlg_game_node.h's AtomicRef0045c470, whose copy
 * raises the count in line: with it the append costs 125 in this unit with
 * its growth left a call, is inlined, and the growth after it (the null arm
 * of the owner's lookup kept), where over Ref00503fb0, whose copy raises the
 * count out of line, the append costs 290 and stays a call. */
/* derived name: adds a counted reference to the record's array unless it
 * holds the object already; the reference is passed by value, and copied
 * again for the append (the count raised at 0xce2308 before the record is
 * read, and dropped at the end) */
void FUN_00ce22e0(List00ce22e0 *list, AtomicRef0045c470<Object016b9108> object)
{
    list->record->objects.pushUnique(object);
}
