/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: names kept in the order they are used, a cursor past the
 * ones used so far (FUN_00c727d0 and FUN_00c747e0 call add). Not traced
 * further. */
struct Names013aa640 { /* derived name */
    int add(const Name &name);

    Array05943280<Name> names; /* +0x0 */
    int cursor;                /* +0x18 */
};

/* FUN_013aa640: the name's slot: below the cursor a name found in the list
 * keeps its slot (the cursor moved up to it), else the name takes the
 * cursor's slot and the cursor moves on; past the end the name is found or
 * appended, and the cursor follows the last one */
// NONMATCHING: 6/139, 428 bytes against 470: the base searches in each branch (two loops, the
// first one's data pointer loaded before its count test and kept for the cursor's slot, the
// cursor sign-extended once at the top); with indexOf() in both branches the calls are hoisted
// into one search above the test. Left: the second branch's found path is not tested in the
// base (`mov ecx, ebx; mov ebx, eax; jmp`), here it is compared with -1
int Names013aa640::add(const Name &name) /* derived name */
{
    if (unsigned(cursor) < names.size()) {
        int index = names.indexOf(name);
        if (index >= 0) {
            if (index == cursor)
                return cursor++;
            if (cursor < index)
                cursor = index;
            return index;
        }
        names.at(cursor) = name;
        return cursor++;
    }
    int index = -1;
    for (unsigned i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            index = i;
            break;
        }
    }
    if (index == -1)
        index = names.add(name);
    if (unsigned(index + 1) == names.size())
        cursor = names.size();
    return index;
}
