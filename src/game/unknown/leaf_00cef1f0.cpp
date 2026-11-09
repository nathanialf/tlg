/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose vtable is at 0x16b97a0 (stored by FUN_00cef1f0
 * FUN_00eb2710): slot 0, FUN_00cef1f0, the complete destructor, slot 1,
 * FUN_00cef200, the deleting one (operator delete of the object). The complete
 * destructor stores the vptr and returns, the shape of a body holding a
 * statement that emits nothing (D16); that statement is not recovered, so the
 * body here is empty and FUN_00cef1f0 stays unclaimed (its vtable is not named
 * either). The deleting destructor is the same either way: dead store
 * elimination drops the vptr store before operator delete. */
class Object00cef1f0 /* derived name */
{
  public:
    virtual ~Object00cef1f0();
};

Object00cef1f0::~Object00cef1f0() {}
