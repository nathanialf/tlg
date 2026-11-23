/* src/include/tlg_game_object016d4e10.h: the class whose vtable is at
 * 0x16d4e10 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D4E10_H
#define TLG_GAME_OBJECT016D4E10_H

#include "tlg_types.h"
#include "tlg_game_joint013eb0a0.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016d7510.h"

/* derived names: the class whose vtable is at 0x16d4e10
 * (config/vtables.derived.base.txt): ten slots, no base that its destructor
 * shows; the shape of Object016d5050 (leaf_013ed250.cpp) and of
 * Object016d7510 (tlg_game_object016d7510.h). A counted reference to a
 * scene node at +0x10 (tlg_game_node.h's Ref00503fb0), which the destructor
 * (leaf_013ed630.cpp) releases. Slot 2 (FUN_013eafb0, func_01000ba0.cpp,
 * which holds the VECTOR_W copy it reads) is Object016d7510's slot 2 in
 * that file. */
class Object016d4e10 /* derived name */
{
  public:
    virtual ~Object016d4e10();
    virtual JointFrame013eb0a0 slot2(const Subject01480e70 *subject); /* derived name */
    virtual void slot3(); /* derived name; FUN_0002abc0, not traced */
    virtual void slot4(); /* derived name; FUN_000058a0, not traced */
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_013eb010, not traced */
    virtual void slot7(); /* derived name; FUN_013ea9f0, not traced */
    virtual void slot8(); /* derived name; FUN_013eb1f0, not traced */
    virtual void slot9(); /* derived name; FUN_00013e90, not traced */

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Object016b85e0> node; /* +0x10: released by the destructor */
};

#endif
