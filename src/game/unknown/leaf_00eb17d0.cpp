/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_referenced.h"

/* derived names: the object the destructor below holds at +0x28: a
 * referenced object (tlg_game_referenced.h) whose pointer at +0x10 is
 * cleared before the release. */
class Held00eb17d0 : public Referenced00eaaec0 /* derived name */
{
  public:
    void *holder10; /* +0x10 */
};

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16be848 (config/vtables.derived.base.txt, stored by FUN_00eb17d0 and
 * FUN_00eb1840 only: the row names the destructor): it stores the vtable, clears the held object's pointer at +0x10
 * and releases the object at +0x28, then runs its base's destructor
 * (leaf_00cef2a0.cpp, defined empty there and inlined in the module: the base's
 * vtable stored). FUN_00eb1840, slot 1, is the deleting one. The destructor is
 * the class's key function, so this file emits the vtable. The other members
 * are not traced. */
class Object00cef2a0 /* derived name */
{
  public:
    virtual ~Object00cef2a0();
};

class Object016be848 : public Object00cef2a0 /* derived name */
{
  public:
    virtual ~Object016be848();

  private:
    u8 unknown8[0x20];
    Held00eb17d0 *unknown28; /* +0x28 */
};

// NONMATCHING: two residuals. The base's destructor (leaf_00cef2a0.cpp)
// keeps its vptr store in the base and compiles to a bare
// return here (a destructor that keeps only its vptr store, the class held
// open), so the base's store after the release and the frame around the
// release's call are missing; and the count's merge in the release loop is
// `or esi, edx` where the base has `lea esi, [rsi + rdx]` (leaf_00eaaec0.cpp's
// residual, `lea` against `or`).
Object016be848::~Object016be848()
{
    unknown28->holder10 = 0;
    unknown28->removeReference();
}
