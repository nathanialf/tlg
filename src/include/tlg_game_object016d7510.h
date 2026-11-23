/* src/include/tlg_game_object016d7510.h: the class whose vtable is at
 * 0x16d7510 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D7510_H
#define TLG_GAME_OBJECT016D7510_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_joint013eb0a0.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: what slot 2 is given: an object whose +0x108 points to one
 * holding a position at +0x2120 (FUN_01480e70) and, at +0x2630, a node
 * whose frame Object016d5050's slot 2 takes while the int at +0x25c0 is
 * set (FUN_013eb670); neither class is traced further */
struct Target01480e70 { /* derived name */
    u8 unknown0[0x2120];
    Float4A position; /* +0x2120 */
    u8 unknown2130[0x490];
    int unknown25c0; /* +0x25c0 */
    u8 unknown25c4[0x6c];
    const Object016b85e0 *node2630; /* +0x2630 */
};

struct Subject01480e70 { /* derived name */
    u8 unknown0[0x108];
    Target01480e70 *target; /* +0x108 */
};

/* derived names: the class whose vtable is at 0x16d7510
 * (config/vtables.derived.base.txt), ten slots, no base that its destructor
 * shows; the shape of Object016d5050 (leaf_013ed250.cpp). A counted
 * reference to a scene node at +0x10 (tlg_game_node.h's Ref00503fb0), which
 * the destructor (leaf_014833b0.cpp) releases. Slot 2 (FUN_01480e70,
 * func_0126c7f0.cpp, which holds the VECTOR_W copy it reads) returns the
 * frame of tlg_game_joint013eb0a0.h: the subject's target's position and
 * the node's rotation (+0x140), or zero and VECTOR_W without a target. */
class Object016d7510 /* derived name */
{
  public:
    virtual ~Object016d7510();
    virtual JointFrame013eb0a0 slot2(const Subject01480e70 *subject); /* derived name */
    virtual void slot3(); /* derived name; FUN_0002abc0, not traced */
    virtual void slot4(); /* derived name; FUN_000058a0, not traced */
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_013eb010, not traced */
    virtual void slot7(); /* derived name; FUN_014808b0, not traced */
    virtual void slot8(); /* derived name; FUN_013eb1f0, not traced */
    virtual void slot9(); /* derived name; FUN_00013e90, not traced */

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Object016b85e0> node; /* +0x10: released by the destructor */
};

#endif
