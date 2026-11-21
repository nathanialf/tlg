/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object00d30550.h"
#include "tlg_game_object016b9108.h"

/* derived name: the objects the array holds (counted, derived from the
 * root class); not traced. The array's destructor over them is this unit's
 * alone, so the link inlines it in the destructor below, as the base shows
 * (no call to 0x134f620 for it) */
class Element016b8a10 : public Object016b9108
{
};

/* derived names: the class whose vtable is at 0x16b8a10
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00c92020
 * and its destructor FUN_00c92310), derived from Object00d30550 (the class
 * whose destructor is 0xd30550): the base's slots and fields are not
 * traced, so the bytes below the first member here are the base's or this
 * class's. Its own fields are traced where the destructor tears them down
 * (three counted references from +0x40 and an array of them at +0x58, its
 * owner index at +0x68 from the constructor). */
class Object016b8a10 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object016b8a10();

  private:
    u8 unknown8[0x38];
    Ref00503fb0<Object016b9108> held40; /* +0x40 */
    Ref00503fb0<Object016b9108> held48; /* +0x48 */
    Ref00503fb0<Object016b9108> held50; /* +0x50 */
    /* +0x58: an array of references, each released, then its block */
    Array05943280<Ref00503fb0<Element016b8a10>> array58;
};

/* derived name: the complete destructor: the body is empty; the members
 * are released, last first, then the base's destructor FUN_00d30550 runs
 * as a tail call. FUN_00c925b0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the
 * vtable. */
Object016b8a10::~Object016b8a10() {}
