/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16caaf0 (config/vtables.derived.base.txt; stored by FUN_0122be10 FUN_0147f080 FUN_0147f0c0): it stores
 * the vtable, deletes the object the pointer at +0x460 holds through its
 * virtual deleting destructor (slot 1 of its vtable, skipped for null), then
 * runs its base's destructor FUN_0147ec30 (its row named for it, D15) as a
 * tail call. FUN_0147f0c0, slot 1, is the deleting one. The owned object's class
 * is not traced beyond its virtual destructor. The destructor is the class's
 * key function, so this file emits the vtable. */
class Object0147ec30 /* derived name */
{
  public:
    virtual ~Object0147ec30();
};

class Member0147f080_460 /* derived name */
{
  public:
    virtual ~Member0147f080_460();
};

class Object0147f080 : public Object0147ec30 /* derived name */
{
  public:
    virtual ~Object0147f080();

  private:
    u8 unknown8[0x458];
    Member0147f080_460 *unknown460; /* +0x460: owned */
};

Object0147f080::~Object0147f080()
{
    delete unknown460;
}
