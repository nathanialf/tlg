/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16a9dc8 (config/vtables.derived.base.txt; stored by the constructor
 * FUN_0047a6e0 and by the destructors FUN_0047dd70 and FUN_0047de60): it
 * stores the vtable and deletes the object the pointer at +0x8 holds through
 * its virtual deleting destructor (slot 1 of its vtable, a tail call, skipped
 * for null). FUN_0047de60, slot 1, is the deleting one. The owned object's
 * class is not traced beyond its virtual destructor. The destructor is the
 * class's key function, so this file emits the vtable. */
class Member0047dd70_8 /* derived name */
{
  public:
    virtual ~Member0047dd70_8();
};

class Object0047dd70 /* derived name */
{
  public:
    virtual ~Object0047dd70();

  private:
    Member0047dd70_8 *unknown8; /* +0x8: owned */
};

Object0047dd70::~Object0047dd70()
{
    delete unknown8;
}
