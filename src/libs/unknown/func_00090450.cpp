/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 0 of the vtable 0x16a3370, a 0x38-byte reference-counted
 * object (constructor 0x904c0, called at 0x167f1b on a 0x38-byte block; its
 * deleting destructor 0x90460 frees the size kept in the high half of +8).
 * Slot 7 (0x904f0) appends a record whose padded byte size is the u16 at its
 * start to the block writer at +0x10 (0x939c0 opens a new 0xfe0-byte block);
 * 0x938a0 binds that writer at 0x167f35. The destructor stores the class's
 * vtable, so its body (or a member's destructor) is not trivial in the
 * original. */
class CommandBlockWriter /* derived name */ : public hkReferencedObject
{
  public:
    virtual ~CommandBlockWriter();

    u8 unknown10[0x28];
};

// NONMATCHING: the vtable 0x16a3370 is named by neither config/vtables.base.txt nor
// config/vtables.derived.base.txt (a ruling); and the base stores the vtable, which
// an empty body skips (CGClass.cpp:1224, CanSkipVTablePointerInitialization); and
// the base calls no base destructor, while hkBaseObject's is declared out of line
// here (compiled: a tail jmp to it).
CommandBlockWriter::~CommandBlockWriter() {}
