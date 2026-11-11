/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_referenced.h"

/* derived names: the object the destructor below holds at +0x28: a
 * referenced object (tlg_game_referenced.h) whose pointer at +0x18 is
 * cleared before the release. */
class Held00eab2a0 : public Referenced00eaaec0 /* derived name */
{
  public:
    u8 unknown10[8];
    void *holder18; /* +0x18 */
};

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16be6e0 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00ea6700): it stores the vtable, clears the held object's pointer at +0x18
 * and releases the object at +0x28, then runs its base's destructor
 * (leaf_00cef210.cpp, defined empty there and inlined in the module: the base's
 * vtable stored). FUN_00eab310, slot 1, is the deleting one. The destructor is
 * the class's key function, so this file emits the vtable. The other members
 * are not traced. */
class Object00cef210 /* derived name */
{
  public:
    virtual ~Object00cef210();
};

class Object016be6e0 : public Object00cef210 /* derived name */
{
  public:
    virtual ~Object016be6e0();

  private:
    u8 unknown8[0x20];
    Held00eab2a0 *unknown28; /* +0x28 */
};

// NONMATCHING: two residuals. The base's destructor (leaf_00cef210.cpp)
// keeps its vptr store in the base and compiles to a bare
// return here (a destructor that keeps only its vptr store, the class held
// open), so the base's store after the release and the frame around the
// release's call are missing; and the count's merge in the release loop is
// `or esi, edx` where the base has `lea esi, [rsi + rdx]` (leaf_00eaaec0.cpp's
// residual, `lea` against `or`).
Object016be6e0::~Object016be6e0()
{
    unknown28->holder18 = 0;
    unknown28->removeReference();
}
