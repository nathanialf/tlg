/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the counted objects of the array at +0x38 below: each is
 * told of the event through its slot 5 (`call [rax+0x28]` with the event's
 * int and the holder); one whose flag 0x10 at +0x28 is set and that only
 * the holder still references is let go. Nothing else is traced. */
class Listener00a2e930 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5(int event, void *holder); /* derived name; not traced */

    u8 unknown24[0x4];
    u8 flags28; /* +0x28 */
};

/* derived names: the object FUN_00a2e930 is called with (a callback whose
 * address FUN_01331f60 stores, lea at 0x1331fbf): its node at +0x28 (bit 1
 * of its byte at +0x24), its listeners at +0x38 and its flags at +0x50 */
struct Holder00a2e930 /* derived name */
{
    u8 unknown0[0x28];
    Object016b9108 *node28; /* +0x28 */
    u8 unknown30[0x8];
    Array05943280<Ref00503fb0<Listener00a2e930>> listeners; /* +0x38 */
    u8 unknown50;                                           /* +0x50 */
};

/* the node's byte at +0x24 */
struct Node00a2e930 : Object016b9108 /* derived name */
{
    u8 flags24; /* +0x24 */
};

/* derived name: when the node is set and marked and the holder is not
 * stopped, every listener is told of the event, then the ones that are done
 * are removed from the last to the first; answers 1 */
// NONMATCHING: greedy's assignment only: the count and the event's int in r12d and r14d
// swapped, the removed listener in rcx (spilled) where the build keeps it in rbx; the control
// flow and the removal are the base's (under --module).
int FUN_00a2e930(Holder00a2e930 *self, const int *event) /* derived name */
{
    const Node00a2e930 *node = static_cast<const Node00a2e930 *>(self->node28);
    if (node && (node->flags24 & 1) && !(self->unknown50 & 1)) {
        const int count = self->listeners.size();
        if (count > 0) {
            const int id = *event;
            for (int i = 0; i < count; i++)
                self->listeners.at(i).get()->slot5(id, self);
            for (int i = count - 1; i >= 0; i--) {
                const Listener00a2e930 *listener = self->listeners.at(i).get();
                if ((listener->flags28 & 0x10) && listener->references == 1)
                    self->listeners.removeAt(i);
            }
        }
    }
    return 1;
}
