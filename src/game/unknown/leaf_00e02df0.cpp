/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd558
 * (config/vtables.base.txt, stored by its constructor FUN_00e016b0),
 * derived from Object016b9108: its vtable holds the base's slots 2 to 4 and
 * no others. Its destructors tear down nothing of their own: the complete
 * one (0xe02df0) is the base's destructor inlined (its vptr store, then the
 * names at +0x10 and +0xc released), the deleting one (0xe02e70) the same
 * before operator delete. The destructor is the class's key function, so
 * this file emits the vtable. Its fields from +0x24 are not traced. */
class Object016bd558 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bd558();
};

Object016bd558::~Object016bd558() {}
