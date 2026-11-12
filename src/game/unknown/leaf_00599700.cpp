/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x526284): finds the node its argument refers to in the owner's list (from
 * the current index to the end, then from the start), makes it the current
 * one, and when the argument's Name contains "ratio" stores the owner's int
 * value in that node's value; returns 0. Handler unknown. The search is
 * written in the body as round 213C's equal draft writes it. */
// NONMATCHING: the base widens the search index to 64 bits from a zero-extended start (`mov rcx, rdi`, `cmp ecx, ebx`), this build keeps it 32 bits (`mov edi, ecx` each pass); round 213C's draft of the same loop with its own walker types (c213/drafts/) is equal and gives the same optimised IR but for the order of the loop header's predecessors (round 217C, c217/ir_mine.ll, ir_their.ll): not resolved
int FUN_00599700(Owner583950 *self, void *arg) /* derived name */
{
    NamedNode583950 *node = static_cast<NamedNode583950 *>(arg);
    void *target = node->target;
    NodeList583950 *list = self->list;
    unsigned found = self->current;
    bool seen = false;
    for (unsigned i = self->current; i < list->count; ++i) {
        if (list->items[i] == target) {
            found = i;
            seen = true;
            break;
        }
    }
    if (!seen) {
        for (unsigned i = 0; i < self->current; ++i) {
            if (list->items[i] == target) {
                found = i;
                seen = true;
                break;
            }
        }
    }
    if (!seen)
        return 0;
    self->current = found;
    int *value = reinterpret_cast<int *>(list->value(found));
    if (value && strstr(D_17ac870[node->name].string0, "ratio"))
        *value = self->intValue;
    return 0;
}
