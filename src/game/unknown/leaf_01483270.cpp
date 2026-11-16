/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d75d0
 * (config/vtables.derived.base.txt): ten slots, no base that its destructor
 * shows; the shape of Object016d5050 (leaf_013ed250.cpp). Its fields are
 * traced only where the destructor tears them down: a counted reference at
 * +0x10 (tlg_game_node.h's Ref00503fb0). The object's own class is not
 * traced. */
class Object016d75d0 /* derived name */
{
  public:
    virtual ~Object016d75d0();
    virtual void slot2(); /* derived name; FUN_01481020, not traced */
    virtual void slot3(); /* derived name; FUN_0002abc0, not traced */
    virtual void slot4(); /* derived name; FUN_000042d0, not traced */
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_01481080, not traced */
    virtual void slot7(); /* derived name; FUN_01481320, not traced */
    virtual void slot8(); /* derived name; FUN_013eb1f0, not traced */
    virtual void slot9(); /* derived name; FUN_00013e90, not traced */

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Object016b9108> held10; /* +0x10: released by the destructor */
};

/* derived name: the complete destructor: the body is empty; the reference is
 * released. FUN_01483300, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016d75d0::~Object016d75d0() {}
