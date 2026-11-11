/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a vtable slot (its pointer at 0x16acd70, no row), written as
 * a free function: answers, as an int, whether the entry the index at +0x10c
 * selects in the table at +0x68 (the pointers at +0x5c18, their count at
 * +0x5c20) has the word at +0x8 set; 0 when the index or the int at +0x130
 * is -1, or the index is out of range. The fields' meaning is not traced. */
struct Entry00773e40 /* derived name */
{
    u8 unknown0[8];
    int unknown8; /* +0x8 */
};

struct Table00773e40 /* derived name */
{
    u8 unknown0[0x5c18];
    Entry00773e40 **entries5c18; /* +0x5c18 */
    unsigned count5c20;          /* +0x5c20 */
};

struct Object00773e40 /* derived name */
{
    u8 unknown0[0x68];
    Table00773e40 *unknown68; /* +0x68 */
    u8 unknown70[0x9c];
    int index10c; /* +0x10c */
    u8 unknown110[0x20];
    int unknown130; /* +0x130 */

    bool isSet() const /* derived name */
    {
        if (index10c == -1 || unknown130 == -1)
            return false;
        if ((unsigned)index10c >= unknown68->count5c20)
            return false;
        return unknown68->entries5c18[index10c]->unknown8 != 0;
    }
};

int FUN_00773e40(const Object00773e40 *self) /* derived name */
{
    return self->isSet();
}
