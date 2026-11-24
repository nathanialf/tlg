/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: a test FUN_00ad1c10 and FUN_00ad2030 make (calls at 0xad1c38,
 * 0xad2369, 0xad2651): true when the int at +0x4e8 of the object is the one
 * at 0x57d85a4; else false when its Name at +0x568 is empty, or when the
 * node it names (of the type D_5939080 points to, usable by this thread)
 * has a component of the type D_57d4a68 points to while the int at +0xe8
 * of the record at +0x900 of the record at +0x38 of the object the pointer
 * at 0x57c9390 holds is 0; true otherwise. The classes are not traced. */
struct Object004ba970 { /* derived name */
    u8 unknown0[0x4e8];
    int unknown4e8; /* +0x4e8 */
    u8 unknown4ec[0x7c];
    Name name568; /* +0x568 */
};

struct Record004ba970 { /* derived name */
    u8 unknown0[0xe8];
    int unknowne8; /* +0xe8 */
};

struct World004ba970 { /* derived name */
    u8 unknown0[0x900];
    Record004ba970 *unknown900; /* +0x900 */
};

struct Game004ba970 { /* derived name */
    u8 unknown0[0x38];
    World004ba970 *world; /* +0x38 */
};

extern Game004ba970 *D_57c9390;
extern const int D_57d85a4;           /* derived name */
extern const Type00503fb0 *D_5939080; /* derived name: the node's type */
extern const Type00503fb0 *D_57d4a68; /* derived name: the component's type */

// Round 576D: equal when BranchFolding's tail merge leaves alone an atomic read-modify-write with an
// unused result (the rule leaf_00857df0.cpp describes; that half alone is enough here).
// NONMATCHING: block layout: the base places the return block after the walk's loop (0x4ba9ff) and
// keeps a third release of the reader count for an empty component list; the build places the
// return last and merges the two not-found releases
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 325 at the
 * link, over its threshold of 175: one signature changes no row) */
bool FUN_004ba970(const Object004ba970 *self) /* derived name */
{
    if (self->unknown4e8 == D_57d85a4)
        return true;
    if (self->name568.index == 0)
        return false;
    Object016b85e0 *node = findNamed<Object016b85e0>(self->name568, D_5939080);
    if (node && node->findComponent(D_57d4a68) && D_57c9390->world->unknown900->unknowne8 == 0)
        return false;
    return true;
}
