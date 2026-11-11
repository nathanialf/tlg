/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16ca660 (config/vtables.derived.base.txt; stored by FUN_00f9ab50 FUN_013e4ac0 FUN_013e4b00): it stores
 * the vtable, deletes the object the pointer at +0x460 holds through its
 * virtual deleting destructor (slot 1 of its vtable, skipped for null), then
 * runs its base's destructor FUN_013e4200 (its row named for it, D15) as a
 * tail call. FUN_013e4b00, slot 1, is the deleting one. The owned object's class
 * is not traced beyond its virtual destructor. The destructor is the class's
 * key function, so this file emits the vtable. */
class Object013e4200 /* derived name */
{
  public:
    virtual ~Object013e4200();
};

class Member013e4ac0_460 /* derived name */
{
  public:
    virtual ~Member013e4ac0_460();
};

class Object013e4ac0 : public Object013e4200 /* derived name */
{
  public:
    virtual ~Object013e4ac0();

  private:
    u8 unknown8[0x458];
    Member013e4ac0_460 *unknown460; /* +0x460: owned */
};

Object013e4ac0::~Object013e4ac0()
{
    delete unknown460;
}
