/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: slot 0 of the vtable 0x1698ee0, a 0x18-byte polymorphic
 * base (its deleting destructor 0x47cc0 frees 0x18 bytes) of the slots of a
 * member-function signal: the derived vtables 0x1698eb0 and 0x1698f10 keep
 * this destructor in slot 0, test a 16-byte member-function pointer against
 * the one they hold at +0x18 (slot 2, 0x47d60) and call it on the object at
 * +0x10 (slot 3, 0x47c80 and 0x47d90). The destructor stores the class's
 * vtable, so its body is not empty in the original. */
class SignalSlot /* derived name */
{
  public:
    virtual ~SignalSlot();

    u8 unknown8[0x10];
};

// NONMATCHING: the vtable 0x1698ee0 is named by neither config/vtables.base.txt nor
// config/vtables.derived.base.txt (a ruling); and the base stores the vtable, which
// an empty body skips (CGClass.cpp:1224, CanSkipVTablePointerInitialization).
SignalSlot::~SignalSlot() {}
