/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: the objects the two arrays hold (counted, derived from
 * the root class, two kinds); not traced. Each array's destructor over its
 * kind is this unit's alone and has one caller, so the link inlines both
 * in the destructor below, as the base shows (no call to 0x134f620 for
 * them) */
class Element250016baba8 : public Object016b9108
{
};

class Element268016baba8 : public Object016b9108
{
};

/* derived names: the class whose vtable is at 0x16baba8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d7dd00
 * and its destructor FUN_00d7e240), derived from Object016b85e0 (its
 * destructor 0xc55550): the base's slots and fields are not traced, so the
 * bytes below the first member here are the base's or this class's. Its
 * own fields are traced where the destructor tears them down (a counted
 * reference at +0x248, two arrays of them at +0x250 and +0x268, another
 * reference at +0x280). */
class Object016baba8 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016baba8();

  private:
    u8 unknown238[0x10];
    Ref00503fb0<Object016b9108> held248;                     /* +0x248 */
    Array05943280<Ref00503fb0<Element250016baba8>> array250; /* +0x250 */
    Array05943280<Ref00503fb0<Element268016baba8>> array268; /* +0x268 */
    Ref00503fb0<Object016b9108> held280;                     /* +0x280 */
};

/* derived name: the complete destructor: the body is empty; the members
 * are released, last first, then the base's destructor FUN_00c55550 runs
 * as a tail call. FUN_00d7e570, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the
 * vtable. */
Object016baba8::~Object016baba8() {}
