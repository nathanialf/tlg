/* src/include/tlg_game_object016c7d08.h: the class whose vtable is at
 * 0x16c7d08, a base of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016C7D08_H
#define TLG_GAME_OBJECT016C7D08_H

#include "tlg_game_entry00c8b0d0.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the record the pointer at +0x50 of a camera names; only
 * the int at +0x4 is traced (0x400 from PointingCamera's Init). Its block
 * comes from operator new[] (no destructor: FUN_00afd570's delete[]). */
struct Settings006910d0 /* derived name */
{
    u8 unknown0[0x4];
    int unknown4; /* +0x4 */
};

/* derived names: the object at +0x40 of the one the pointer at 0x57c9390
 * holds: from +0x1a0 a reference per camera index, set to the camera by its
 * constructor and emptied by its destructor (both by compare-and-swap); as
 * many as there are indices, not traced */
struct Cameras057c9390 { /* derived name */
    u8 unknown0[0x1a0];
    AtomicRef0045c470<Object016b9108> cameras[1]; /* +0x1a0 */
};

struct Game057c9390 { /* derived name */
    u8 unknown0[0x40];
    Cameras057c9390 *cameras40; /* +0x40 */
};

extern Game057c9390 *D_57c9390;

/* derived names: the class whose vtable is at 0x16c7d08
 * (config/vtables.derived.base.txt, stored by its constructor 0xafd2e0, by
 * 0xafd410 and by 0xafd6a0), derived from Object016b9108 (0xafd2e0
 * first calls that class's constructor 0xcb6310). The constructor of each
 * class over it calls 0xafd2e0 first; FixCamera and FollowCamera
 * (leaf_0061ae60.cpp, leaf_0061c420.cpp) tail-call its destructor
 * 0xafd410 (its row named for it, D15). The constructor, the destructor
 * (the class's key function, so that unit emits the vtable) and
 * freeEntries() are in leaf_00afd410.cpp. */
class Object016c7d08 : public Object016b9108 /* derived name */
{
  public:
    /* 0xafd2e0: the fields set, the camera put in its index's reference of
     * the record at 0x57c9390 (compared first: a class over the
     * reference's), then that record kept at +0x28 (read again after the
     * exchange) and +0x38 cleared */
    Object016c7d08(const Name &name, int index);

    /* 0xafd410: the entries freed, then the camera's reference emptied
     * where the record is still there */
    virtual ~Object016c7d08();

  protected:
    /* FUN_00afd570: the two arrays deleted and their pointers cleared */
    void freeEntries(); /* derived name */

  public:
    u8 unknown24[0x4];
    Cameras057c9390 *cameras28; /* +0x28: the record the index is in */
    int index30;                /* +0x30: the camera's index in that record */
    int unknown34;              /* +0x34: 2 from the constructor; not traced */
    void *unknown38;            /* +0x38: null from the constructor; not traced */
    u8 unknown40[0x8];
    /* +0x48: 0xb0-byte entries from operator new[], each entry's reference
     * at +0x98 dropped when the block is deleted */
    Entry00c8b0d0 *entries48;
    Settings006910d0 *unknown50; /* +0x50 */
    int unknown58;               /* +0x58: -1 from the constructor; not traced */
    int unknown5c;               /* +0x5c: 1 from the constructor; not traced */
};

#endif
