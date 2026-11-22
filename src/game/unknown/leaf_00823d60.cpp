/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: an object of the list at +0x270 of FUN_00823d60's owner,
 * joined to two others at +0x238 and +0x240; not traced otherwise */
struct Link00823d60 { /* derived name */
    u8 unknown0[0x238];
    void *end238; /* +0x238 */
    void *end240; /* +0x240 */
};

struct Owner00823d60 { /* derived name */
    u8 unknown0[0x270];
    Array05943280<Link00823d60 *> links; /* +0x270 */
};

/* derived names: appends to `found` every link of the owner but `except`
 * that has `end` at either of its ends, the links read again after each
 * append; called from 0x647ebd (FUN_00645d80, a locked array of its own) */
void FUN_00823d60(Owner00823d60 *owner, const void *end, Array01343a80<Link00823d60 *> &found,
                  const Link00823d60 *except) /* derived name */
{
    for (unsigned i = 0; i < owner->links.size(); ++i) {
        Link00823d60 *link = owner->links.at(i);
        if (link != except && (link->end238 == end || link->end240 == end))
            found.push(link);
    }
}
