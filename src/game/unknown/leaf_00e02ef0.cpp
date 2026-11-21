/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd590
 * (config/vtables.derived.base.txt, stored by its constructors FUN_00e01bb0
 * and FUN_00e02850 and by its destructors), derived from Object016b9108: its
 * slots 2 to 4 are the base's. Its own fields from +0x24 are traced only
 * where its destructor tears them down (the array of counted references at
 * +0x28); the rest are not traced. */
class Object016bd590 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bd590();

  private:
    u8 unknown24[0x4];
    Object0134f620 references28; /* +0x28 */
};

/* derived names: the class whose vtable is at 0x16bd5c8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00e02850
 * after Object016bd590's), with no fields of its own: its destructor is
 * empty and skips its own vptr store, so its complete destructor is
 * Object016bd590's body, folded onto 0xe02ef0 (slot 0 of both vtables), and
 * its deleting one FUN_00e03030 stores Object016bd590's vtable. */
class Object016bd5c8 : public Object016bd590 /* derived name */
{
  public:
    virtual ~Object016bd5c8();
};

/* derived names: the complete destructor: the array's destructor
 * FUN_0134f620 runs out of line, then the base's destructor is inlined (its
 * vptr store, then the two names). FUN_00e02f90, slot 1, is the deleting
 * one. The destructors are the classes' key functions, so this file emits
 * both vtables. */
Object016bd590::~Object016bd590() {}

Object016bd5c8::~Object016bd5c8() {}
