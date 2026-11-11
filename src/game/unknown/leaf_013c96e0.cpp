/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d2d40 (config/vtables.derived.base.txt; stored also by FUN_00dfca70):
 * it stores the vtable, passes the object to FUN_00bc4600 and runs its base's
 * destructor FUN_00bc3780 as a tail call. FUN_013c9710, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
class Object00bc3780 /* derived name */
{
  public:
    virtual ~Object00bc3780();
};

class Object013c96e0 : public Object00bc3780 /* derived name */
{
  public:
    virtual ~Object013c96e0();
};

void FUN_00bc4600(Object013c96e0 *self); /* derived name */

Object013c96e0::~Object013c96e0()
{
    FUN_00bc4600(this);
}
