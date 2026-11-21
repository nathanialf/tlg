/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16b7f48
 * (config/vtables.derived.base.txt; stored by FUN_00c18f10), derived from
 * Object00c1b7f0: Names at +0x38 and +0x3c, a counted reference at +0x40
 * that its destructor's body empties by compare-and-swap and a counted
 * reference at +0x48, the members then destroyed last to first before the
 * base's destructor (0xc1b7f0, a tail call). FUN_00c19a80, slot 1, is the
 * deleting destructor. */
class Object016b7f48 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016b7f48();

  private:
    Name unknown38;                           /* +0x38 */
    Name unknown3c;                           /* +0x3c */
    AtomicRef0045c470<Object016b9108> held40; /* +0x40 */
    Ref00503fb0<Object016b9108> unknown48;    /* +0x48 */
};

Object016b7f48::~Object016b7f48()
{
    held40.clear();
}
