/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bda38.h"

/* derived names: a vtable slot (its address at 0x16bea18 in the file) that
 * has FUN_00d44120 find, for the entry at +0x34 of its argument, an object
 * in the record at +0x38 of the object the pointer at 0x5938c40 holds (mode
 * 0), and sets the argument's counted reference at +0x38 to it. The object
 * itself is not read; the classes are not traced. */
struct Argument00d641e0 { /* derived name */
    u8 unknown0[0x34];
    u8 unknown34[4];
    AtomicRef0045c470<Node00503fb0> unknown38; /* +0x38 */
};

/* the object found: a class of its own over the counted one (the pointer
 * is converted where the reference compares it, first: `cmp rcx, rbx` at
 * 0xd64234) */
class Value00d44120 : public Node00503fb0 /* derived name */
{
};

/* the second argument is where the object found is written (0xd641ef:
 * `lea rsi, [rbp-0x28]`, read back after the call) */
void FUN_00d44120(Member05938c40_38 *record, Value00d44120 **found, void *entry,
                  int mode); /* derived name */

struct Object00d641e0; /* derived name */

void FUN_00d641e0(Object00d641e0 *, Argument00d641e0 *argument) /* derived name */
{
    Value00d44120 *found;
    FUN_00d44120(D_5938c40->unknown38, &found, argument->unknown34, 0);
    argument->unknown38.set(found);
}
