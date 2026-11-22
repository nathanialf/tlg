/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16c76a0
 * (config/vtables.derived.base.txt), derived from Object016b85e0: a Name at +0x238 and an array
 * of Names at +0x240.
 * Its complete destructor FUN_0134dc10 releases them in reverse order, then
 * tail-calls the base's destructor 0xc55550; FUN_0134dd20, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016c76a0 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016c76a0();

  private:
    Name name238; /* +0x238 */
    u8 unknown23c[0x4];
    Array05943280<Name> names240; /* +0x240 */
};

// NONMATCHING: the deleting destructor FUN_0134dd20: the base inlines this complete destructor into it (268 bytes);
// the build calls it (an inline-cost margin)
Object016c76a0::~Object016c76a0() {}
