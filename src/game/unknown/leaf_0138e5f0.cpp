/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b36e0
 * (config/vtables.derived.base.txt, stored by FUN_00abf490 FUN_0138e5f0
 * FUN_0138e680): eight slots, no base that its destructor shows. Its fields
 * are traced only where the destructor tears them down: a counted reference
 * at +0x20 (tlg_game_node.h's Ref00503fb0: the count at +0x8 of the object,
 * its slot 2 called when the last reference goes on a thread that destroys at
 * once). The object's own class is not traced. */
class Object016b36e0 /* derived name */
{
  public:
    virtual ~Object016b36e0();
    virtual void slot2(); /* derived name; FUN_00ac3390, not traced */
    virtual void slot3(); /* derived name; FUN_00ac5f60, not traced */
    virtual void slot4(); /* derived name; FUN_001af750, not traced */
    virtual void slot5(); /* derived name; FUN_00ac33d0, not traced */
    virtual void slot6(); /* derived name; FUN_00ac34f0, not traced */
    virtual void slot7(); /* derived name; not traced */

  private:
    u8 unknown8[0x18];
    Ref00503fb0<Node00503fb0> held20; /* +0x20: released by the destructor */
};

/* derived name: the complete destructor: the body is empty; the reference is
 * released. FUN_0138e680, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016b36e0::~Object016b36e0() {}
