/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d5050
 * (config/vtables.derived.base.txt, stored by FUN_00ffe8c0 FUN_013ed250 FUN_013ed2e0): ten slots, no base
 * that its destructor shows. Its fields are traced only where the destructor
 * tears them down: a counted reference at +0x10 (tlg_game_node.h's
 * Ref00503fb0: the count at +0x8 of the object, its slot 2 called when the
 * last reference goes on a thread that destroys at once). The object's own
 * class is not traced. */
class Object016d5050 /* derived name */
{
  public:
    virtual ~Object016d5050();
    virtual void slot2(); /* derived name; FUN_013eb670, not traced */
    virtual void slot3(); /* derived name; FUN_0002abc0, not traced */
    virtual void slot4(); /* derived name; FUN_000058a0, not traced */
    virtual void slot5(); /* derived name; FUN_013eb6e0, not traced */
    virtual void slot6(); /* derived name; FUN_013eb010, not traced */
    virtual void slot7(); /* derived name; FUN_013eb6f0, not traced */
    virtual void slot8(); /* derived name; FUN_013eb1f0, not traced */
    virtual void slot9(); /* derived name; FUN_00013e90, not traced */

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Node00503fb0> held10; /* +0x10: released by the destructor */
};

/* derived name: the complete destructor: the body is empty; the reference is
 * released. FUN_013ed2e0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
// NONMATCHING: three instructions, the thread-local's access sequence: the
// flag D_16dc088 is local to the module's optimiser (config/local_data.base.txt)
// and the installed compiler gives a local thread-local the local-dynamic
// sequence (`lea rdi, [rip]; call; movzx eax, byte [rax + off]`) where the
// base has the general-dynamic one of every thread-local access. Both
// destructors compile equal once the compiler keeps it general-dynamic
// (round 228C's test build, restored).
Object016d5050::~Object016d5050() {}
