/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: whether the int at +0xff8 of the object the name at
 * 0x15aba40 names (of the type the pointer at 0x5814678 holds, usable by
 * this thread) is one of the five ints at 0x14f01b0; the object is looked
 * up again for each of the five. It reads no argument. FUN_00644430 and
 * FUN_00644570 are the same over the tables at 0x14f0190 and 0x14f0170. The
 * object's class is not traced. */
struct Named006442f0 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16;              /* +0x16 */
    const Type00503fb0 *type; /* +0x18 */
    u8 unknown20[0xfd8];
    int unknownff8; /* +0xff8 */
};

extern const char D_15aba40[18];
extern const Type00503fb0 *D_5814678;
extern const int D_14f01b0[5];

// NONMATCHING: the thread flag's read. The base tests the object's flag 4 first and the thread's
// flag second, through an `or` of the two (`movzx r13d, word [r12 + 0x16]` above the flag's
// address, `test r13b, 4; jne`, then `mov al, [rax]; xor al, 1; test al, 1; jne`); the build has
// the same `or` with the thread's flag first (`mov al, [rax]; and al, 1; jne`, then the mask).
// The order is Reassociate's: the flag is a one-bit load in this module when the pass runs and
// ranks below the mask test, so the operands are exchanged; with the flag still a byte compared
// with zero (a unit compiled before the flag is made one bit) the ranks are equal and the order
// stays: a witness for the two-stage build, not a source form. Otherwise the base's (24 of 85, 308 bytes for 305)
bool FUN_006442f0() /* derived name */
{
    for (unsigned i = 0; i < 5; i++) {
        Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
        if (object && object->unknownff8 == D_14f01b0[i])
            return true;
    }
    return false;
}
