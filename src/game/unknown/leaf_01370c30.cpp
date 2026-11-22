/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016cc130.h"

/* derived names: the complete destructor: the names released and their
 * block, then the references' destructor FUN_0134f620 out of line, then
 * the base's destructor inlined (its vptr store, then the two names).
 * FUN_01370d70, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
// NONMATCHING: the deleting destructor FUN_01370d70: the base inlines this complete destructor into it (306 bytes);
// the build calls it (the class of 0x134dd20: an inline-cost margin on the deleting destructor)
Object016cc130::~Object016cc130() {}

/* derived names: the class whose vtable is at 0x16af178
 * (config/vtables.derived.base.txt, stored by FUN_0086e950), derived from
 * Object016cc130 with three arrays of counted references at +0x60, +0x78
 * and +0x90. Its complete destructor FUN_01371ea0 runs their destructor
 * FUN_0134f620 last first, then the base's, inlined; FUN_01372010, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. The other members are not traced. */
class Object016af178 : public Object016cc130 /* derived name */
{
  public:
    virtual ~Object016af178();

  private:
    u8 unknown58[0x8];
    Object0134f620 references60; /* +0x60 */
    Object0134f620 references78; /* +0x78 */
    Object0134f620 references90; /* +0x90 */
};

// NONMATCHING: the base inlines Object016cc130's destructor (307 bytes, this unit's) into this one and keeps the
// deleting one FUN_01372010 a call; the build calls it
Object016af178::~Object016af178() {}
