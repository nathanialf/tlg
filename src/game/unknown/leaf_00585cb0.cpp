/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an entry of the array at +0x390 of the object the owner
 * holds at +0x1b0: eight bytes not traced and a counted reference. 16
 * bytes. */
struct Entry585cb0 { /* derived name */
    u8 unknown0[8];
    Ref00503fb0<Object016b9108> reference; /* +0x8 */
};

struct Holder585cb0 { /* derived name */
    u8 unknown0[0x390];
    Array05943280<Entry585cb0> entries; /* +0x390 */
};

extern Type00503fb0 *D_58b6280; /* derived name: the node's type */

void FUN_00c0bd50(FrameOwner583950 *self, Object016b9108 *node); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes: for a node of
 * the type D_58b6280 points to (or one derived from it), its value (a float)
 * and its state byte taken from the owner's first list; a state of 2 becomes
 * 1, then FUN_00c0bd50 runs with the node; when that has added two entries or
 * more to the holder's array, the first of them is removed, or the second
 * when the value is under a half. Returns 0. Handler unknown. */
int FUN_00585cb0(FrameOwner583950 *self, Object016b9108 *node) /* derived name */
{
    if (!node->isKindOf(D_58b6280))
        return 0;
    Holder585cb0 *holder = static_cast<Holder585cb0 *>(self->unknown1b0);
    const float *value =
        self->cursor.select(node) ? reinterpret_cast<const float *>(self->cursor.value()) : 0;
    u8 *state = self->selectState(node);
    const unsigned first = holder->entries.size();
    if (*state == 2)
        *state = 1;
    FUN_00c0bd50(self, node);
    if (value && holder->entries.size() - first >= 2)
        holder->entries.removeAt(first + (*value < 0.5f));
    return 0;
}
