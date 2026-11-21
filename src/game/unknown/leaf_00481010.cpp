/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the object at +0x18 of the one at +0x50 below; only its
 * int at +0x5d8 is traced */
struct Owner00481010 /* derived name */
{
    u8 unknown0[0x5d8];
    int unknown5d8; /* +0x5d8 */
};

struct Link00481010 /* derived name */
{
    u8 unknown0[0x18];
    Owner00481010 *owner18; /* +0x18 */
};

/* derived names: the object the reference at +0x1e8 below holds: bit 7 of
 * its byte at +0x24 is set before the reference is emptied */
struct Held00481010 : Object016b9108 /* derived name */
{
    u8 flags24; /* +0x24 */
};

/* derived names: the object at +0x88 below; two of its bytes are set */
struct Peer00481010 /* derived name */
{
    u8 unknown0[0xce];
    bool unknownCe; /* +0xce */
    u8 unknownCf;
    bool unknownD0; /* +0xd0 */
};

/* derived names: the object FUN_00469f90 and FUN_0047f170 stop through
 * FUN_00481010: six flags, the pointers at +0x50 and +0x88, a counted
 * reference another thread may replace at +0x1e8 and a name at +0x1f0.
 * Their meaning is not traced. */
struct Object00481010 /* derived name */
{
    /* 0x481010: the flags cleared, the int of the object at +0x50's owner
     * cleared, the held object marked and let go, the name released, then
     * two flags of the object at +0x88 set */
    void stop(); /* derived name */

    u8 unknown0[0x41];
    bool unknown41; /* +0x41 */
    u8 unknown42[0xe];
    Link00481010 *link50; /* +0x50 */
    u8 unknown58[0x30];
    Peer00481010 *peer88; /* +0x88 */
    u8 unknown90[0xe4];
    bool unknown174; /* +0x174 */
    bool unknown175; /* +0x175 */
    bool unknown176; /* +0x176 */
    u8 unknown177[0x6e];
    bool unknown1e5; /* +0x1e5 */
    bool unknown1e6; /* +0x1e6 */
    u8 unknown1e7[0x1];
    AtomicRef0045c470<Held00481010> held1e8; /* +0x1e8 */
    Name name1f0;                            /* +0x1f0 */
};

void Object00481010::stop()
{
    unknown41 = false;
    unknown1e5 = false;
    unknown175 = false;
    unknown174 = false;
    unknown176 = false;
    unknown1e6 = false;
    if (Owner00481010 *owner = link50->owner18)
        owner->unknown5d8 = 0;
    if (Held00481010 *held = held1e8.get()) {
        held->flags24 |= 0x80;
        held1e8.clear();
    }
    name1f0.release();
    if (Peer00481010 *peer = peer88) {
        peer->unknownD0 = true;
        peer->unknownCe = true;
    }
}
