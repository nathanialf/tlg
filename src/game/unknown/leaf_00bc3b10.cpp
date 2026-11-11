/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b76b0 (config/vtables.derived.base.txt; stored also by FUN_00df9930 and FUN_00dfca70):
 * it stores the vtable, passes the object to FUN_00bc3b40 and runs its base's
 * destructor FUN_00bc3780 as a tail call. FUN_00bc3d70, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
class Object00bc3780 /* derived name */
{
  public:
    virtual ~Object00bc3780();
};

class Object00bc3b10 : public Object00bc3780 /* derived name */
{
  public:
    virtual ~Object00bc3b10();
};

void FUN_00bc3b40(Object00bc3b10 *self); /* derived name */

Object00bc3b10::~Object00bc3b10()
{
    FUN_00bc3b40(this);
}
