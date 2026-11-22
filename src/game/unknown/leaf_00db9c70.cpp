/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the head every collected object starts with, its low bit
 * the collector's mark, and the marking of a value's object (FUN_00dc6090,
 * its body not written) */
struct HksGcObject {
    u64 flags;
};

void FUN_00dc6090(void *gray, const HksObject *value);

/* derived name: the collector's barrier: while it marks, a value stored in
 * a marked object has its own object marked (a string only marked, a fixed
 * string, its length's top bit set, left alone); the call timed */
void FUN_00db9c70(lua_State *s, HksGcObject *parent, const HksObject *value)
{
    HksApiTimer timer(s);
    HksGlobal *global = s->global;
    const int type = value->type & 0xf;
    if (global->gcState == 1) {
        switch (type) {
        case 4: /* a string, table, function, userdata, thread or structure */
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
            break;
        default:
            return;
        }
        if (parent->flags & 1) {
            if (type == 4 &&
                static_cast<s64>(static_cast<HksString *>(value->value.pointer)->lengthAndFlags) <
                    0)
                return;
            HksGcObject *object = static_cast<HksGcObject *>(value->value.pointer);
            if (!(object->flags & 1)) {
                object->flags |= 1;
                if (type != 4)
                    FUN_00dc6090(global->gray, value);
            }
        }
    }
}
