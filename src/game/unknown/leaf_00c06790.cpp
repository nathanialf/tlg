/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the value a node FUN_00c06790 is given keeps in the
 * owner's list: an object whose first virtual method is called when the
 * walk below it is done, the node to walk at +0x10 and the list it walks
 * over at +0x20 */
class Value00c06790 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */

    u8 unknown8[8];
    Node583950 *node; /* +0x10 */
    u8 unknown18[8];
    NodeList583950 *list; /* +0x20 */
};

/* derived names: a handler of the table FUN_00aec5d0 builds: a node found
 * in the owner's list dispatches the node it holds at +0x38; when its value
 * names a node, an 'XAER' owner over the value's list (with the owner's
 * handlers and device) dispatches it, and the value, found again, is told
 * through its first virtual method. Returns 0. Handler unknown. */
int FUN_00c06790(DeviceOwner583950 *self, Node583950 *node) /* derived name */
{
    Value00c06790 *value =
        self->cursor.select(node) ? reinterpret_cast<Value00c06790 *>(self->cursor.value()) : 0;
    if (!value)
        return 0;
    self->dispatch(node->child38);
    if (!value->node)
        return 0;
    ErOwner00c06790 owner(*self, value->list);
    owner.dispatch(value->node);
    Value00c06790 *again =
        self->cursor.select(node) ? reinterpret_cast<Value00c06790 *>(self->cursor.value()) : 0;
    if (again)
        again->slot0();
    return 0;
}
