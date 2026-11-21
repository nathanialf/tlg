/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52619e): with bit 0 of the flags of the node of kind 31 its argument
 * holds at +0x38 set, gives the owner that node's value of its kind (type 4
 * a float, 0 an int, 7 a vector, as FUN_0058fc10 reads them) before each
 * of its children is handed on by the kind of the node it holds at +0x38
 * (Owner583950::dispatchHeld). Returns 0. Handler unknown. */
// NONMATCHING: the kind's tests: the base compares 2, then 1 (its arm next), then 0 (its arm
// last); the build compares 0, 1, 2 in ascending order (the chain made a switch either way);
// the three loops equal
int FUN_00594c10(ValueOwner583950 *self, Node583950 *arg) /* derived name */
{
    ParentNode583950Kind31 *node = reinterpret_cast<ParentNode583950Kind31 *>(arg->child38);
    if (node->flags & 1) {
        if (node->kind == 2) {
            Node583950 **end = node->children + node->count;
            for (Node583950 **it = node->children; it != end; ++it) {
                Node583950 *child = *it;
                self->valueType = 7;
                self->vector = node->vector;
                self->dispatchHeld(child);
            }
        } else if (node->kind == 1) {
            Node583950 **end = node->children + node->count;
            for (Node583950 **it = node->children; it != end; ++it) {
                Node583950 *child = *it;
                self->valueType = 0;
                self->intValue = node->intValue;
                self->dispatchHeld(child);
            }
        } else if (node->kind == 0) {
            Node583950 **end = node->children + node->count;
            for (Node583950 **it = node->children; it != end; ++it) {
                Node583950 *child = *it;
                self->valueType = 4;
                self->floatValue = node->floatValue;
                self->dispatchHeld(child);
            }
        }
    }
    return 0;
}
