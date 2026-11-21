/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the objects the array holds (counted, derived from the
 * root class); not traced. The array's destructor over them is this unit's
 * alone, so the link inlines it in the destructor below, as the base shows
 * (no call to 0x134f620 for it) */
class Element016b2ae8 : public Object016b9108
{
};

/* derived names: the class whose vtable is at 0x16b2ae8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a95370
 * and its destructor FUN_00a95920), derived from Object016b9108: its slots
 * 2 to 4 are the base's. Its fields are traced where the constructor
 * clears them (from +0x28, the array's owner index at +0x48) and the
 * destructor tears them down. */
class Object016b2ae8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b2ae8();

  private:
    u8 unknown24[0x4];
    Ref00503fb0<Object016b9108> held28; /* +0x28 */
    Ref00503fb0<Object016b9108> held30; /* +0x30 */
    /* +0x38: an array of references, each released, then its block */
    Array05943280<Ref00503fb0<Element016b2ae8>> array38;
    int unknown4c; /* +0x4c: zero from the constructor */
};

/* derived name: the complete destructor: the body is empty; the members
 * are released, last first, then the base's destructor is inlined.
 * FUN_00a95bb0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016b2ae8::~Object016b2ae8() {}
