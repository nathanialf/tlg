/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
/* derived names: the complete destructor (slot 0) of six classes with
 * nothing of their own to destroy (vtables 0x168ca00, 0x168d440, 0x168d4c0,
 * 0x168d540, 0x168da10, 0x168e220; also slot 1 of the first, fifth and
 * sixth). It runs the destructor of their common base, FUN_00008d60, which
 * is empty and out of line: slot 0 of the base's vtable 0x168d2c0, whose
 * deleting destructor FUN_000066e0 frees 16 bytes. Written as a call because
 * the base destructor has no name yet. */
class RefCountedBase00004ac0
{
  public:
    virtual ~RefCountedBase00004ac0();
};

class RefCounted00004ac0 : public RefCountedBase00004ac0
{
};

void FUN_00008d60(RefCountedBase00004ac0 *self); /* derived name */

void FUN_00004ac0(RefCounted00004ac0 *self) /* derived name */
{
    FUN_00008d60(self);
}
