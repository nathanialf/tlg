/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: whether the object the name at 0x15aba40 names (of the
 * type the pointer at 0x5814678 holds, usable by this thread) is there and
 * has its float at +0x1b4 below 0.9. It reads no argument. The
 * object's class is not traced. */
struct Named006423c0 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16;              /* +0x16 */
    const Type00503fb0 *type; /* +0x18 */
    u8 unknown20[0x194];
    float unknown1b4; /* +0x1b4 */
};

extern const char D_15aba40[18];
extern const Type00503fb0 *D_5814678;

// NONMATCHING: the thread flag's read. The base tests the object's flag 4 first and the thread's
// flag second, through an `or` of the two (`movzx r13d, word [r12 + 0x16]` above the flag's
// address, `test r13b, 4; jne`, then `mov al, [rax]; xor al, 1; test al, 1; jne`); the build has
// the same `or` with the thread's flag first (`mov al, [rax]; and al, 1; jne`, then the mask).
// The order is Reassociate's: the flag is a one-bit load in this module when the pass runs and
// ranks below the mask test, so the operands are exchanged; with the flag still a byte compared
// with zero (a unit compiled before the flag is made one bit) the ranks are equal and the order
// stays: a witness for the two-stage build, not a source form. Otherwise the base's (19 of 77, 252 bytes for 255)
bool FUN_006423c0() /* derived name */
{
    Named006423c0 *object = findNamed<Named006423c0>(Name(D_15aba40), D_5814678);
    return object && object->unknown1b4 < 0.9;
}
