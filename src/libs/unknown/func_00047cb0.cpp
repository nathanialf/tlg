/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A slot of a member-function signal (vtable 0x1698ee0, ruled hkSlot, D14):
 * 0x18 bytes, its deleting destructor 0x47cc0 frees 0x18. The constructor,
 * inlined at 0x49442 and 0x156010, links the slot at the head of its
 * signal's list: next takes the signal's head without its two flag bits,
 * the head becomes this slot with the flags kept, object is the instance the
 * slot calls (the subscriber's this: %r12 at 0x4946e, %rbx at 0x15603b).
 * The derived vtables 0x1698eb0 and 0x1698f10 keep this destructor in slot
 * 0 (their implicit destructors are aliases of it), test a 16-byte
 * member-function pointer against the one they hold at +0x18 (slot 2,
 * 0x47d60) and call it on object (slot 3, 0x47c80 and 0x47d90). The signal
 * deletes its slots still linked (0x93530 walks next and calls slot 1 of
 * each), and nothing clears object after the constructor. */
class hkSlot /* derived name */
{
  public:
    virtual ~hkSlot();

    hkSlot *next; /* derived name */
    void *object; /* derived name */
};

hkSlot::~hkSlot()
{
    /* A slot is destroyed still bound to the subscriber it was created
     * for. */
    HK_ASSERT(0, object != 0); /* derived assert */
}
