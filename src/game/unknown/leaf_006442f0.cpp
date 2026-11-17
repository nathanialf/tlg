/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: whether the int at +0xff8 of the object the name at
 * 0x15aba40 names (of the type the pointer at 0x5814678 holds, usable by
 * this thread) is one of the five ints at 0x14f01b0; the object is looked
 * up again for each of the five. It reads no argument. FUN_00644430 and
 * FUN_00644570 are the same over the tables at 0x14f0190 and 0x14f0170. The
 * object's class is not traced. */
struct Named006442f0 : Object016b9108 /* derived name */
{
    u8 unknown24[0xfd4];
    int unknownff8; /* +0xff8 */
};

extern const char D_15aba40[18];
extern const Type00503fb0 *D_5814678;
extern const int D_14f01b0[5];

// NONMATCHING: 80 of 83. The compare: the base loads the table's entry and compares the field
// from memory (`cmp dword [r13+0xff8], eax`), then `mov al, 1`; the build sets al first and folds
// the field into `cmp ecx, [r13+0xff8]`.
bool FUN_006442f0() /* derived name */
{
    for (unsigned i = 0; i < 5; i++) {
        Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
        if (object && D_14f01b0[i] == object->unknownff8)
            return true;
    }
    return false;
}
