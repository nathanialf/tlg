/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* A slot of a member-function signal (vtable 0x1698ee0, ruled hkSlot, D14):
 * 0x18 bytes, its deleting destructor 0x47cc0 frees 0x18. The constructor,
 * inlined at 0x49442 and 0x156010, links the slot at the head of its
 * signal's list: next takes the signal's head without its two flag bits,
 * the head becomes this slot with the flags kept, object is the instance the
 * slot calls. The derived vtables 0x1698eb0 and 0x1698f10 keep this
 * destructor in slot 0 (their implicit destructors are aliases of it), test
 * a 16-byte member-function pointer against the one they hold at +0x18
 * (slot 2, 0x47d60) and call it on object (slot 3, 0x47c80 and 0x47d90). */
class hkSlot /* derived name */
{
  public:
    virtual ~hkSlot();

    hkSlot *next; /* derived name */
    void *object; /* derived name */
};

// NONMATCHING: the base stores the vtable, which an empty body skips
// (CGClass.cpp:1224, CanSkipVTablePointerInitialization; Decl.cpp:1997,
// hasTrivialBody): the original body is a non-empty statement that emits no
// code (docs/NOTES.md, Round 18).
hkSlot::~hkSlot() {}
