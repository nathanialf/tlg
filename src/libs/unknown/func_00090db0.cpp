/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: slot 4 of the vtable at 0x16a3470, an allocator behind a
 * spinning mutex at +0x440 (hkPthreadUtil.h's lockMutexWithSpinCount,
 * inlined in FUN_00090b70). Slot 2 (0x90b20) rounds a block request up to
 * 128 bytes and allocates it exactly; this one allocates a buffer of at least
 * the requested size, the size passed by reference for the allocator to
 * update, not exactly (FUN_00090b70's flag tested as a bool). */
class Allocator00090db0 /* derived name */
{
  public:
    virtual ~Allocator00090db0();

    void *FUN_00090db0(int &reqNumBytes); /* vtable slot 4; derived name */
};

void *FUN_00090b70(Allocator00090db0 *self, int &reqNumBytes, bool exact); /* derived name */

void *Allocator00090db0::FUN_00090db0(int &reqNumBytes) /* derived name */
{
    return FUN_00090b70(this, reqNumBytes, false);
}
