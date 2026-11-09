/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose vtable is at 0x16b97f8 (stored by FUN_00cef230
 * FUN_00eadb60 FUN_00eb1a20): slot 0, FUN_00cef230, the complete destructor,
 * slot 1, FUN_00cef240, the deleting one (operator delete of the object). The
 * complete destructor stores the vptr and returns, the shape of a body holding
 * a statement that emits nothing (D16); that statement is not recovered, so
 * the body here is empty and FUN_00cef230 stays unclaimed (its vtable is not
 * named either). The deleting destructor is the same either way: dead store
 * elimination drops the vptr store before operator delete. */
class Object00cef230 /* derived name */
{
  public:
    virtual ~Object00cef230();
};

Object00cef230::~Object00cef230() {}
