/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a Havok object the game holds by reference, seen through
 * its count: the word at +0x8 keeps the allocation size in its top 16 bits
 * and the reference count in its low 16, as hkReferencedObject's
 * (tlg_hk_reflect.h); a release counts only on an object with a known size,
 * by compare-and-swap, and the last one deletes the object through slot 4.
 * The shapes the constructor FUN_00eaaa30 builds through the library are
 * these. */
class Referenced00eaaec0 /* derived name */
{
  public:
    virtual void slot0();      /* derived name; not traced */
    virtual void slot1();      /* derived name; not traced */
    virtual void slot2();      /* derived name; not traced */
    virtual void slot3();      /* derived name; not traced */
    virtual void deleteThis(); /* derived name: slot 4 */

    void removeReference() /* derived name */
    {
        if ((memSizeAndRefCount & 0xffff0000) != 0) {
            /* volatile: other threads change the count between the reads,
             * so each attempt reads it again (0xeaaee0 reloads it). */
            volatile u32 *count = &memSizeAndRefCount;
            u32 oldValue, newValue;
            do {
                oldValue = *count;
                newValue = (oldValue & 0xffff0000) | u16(oldValue - 1);
            } while (__sync_val_compare_and_swap(count, oldValue, newValue) != oldValue);
            if (u16(newValue) == 0) {
                deleteThis();
            }
        }
    }

  private:
    u32 memSizeAndRefCount; /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16be6b8
 * (config/vtables.derived.base.txt; stored by its constructor FUN_00eaaa30):
 * its complete destructor 0xeaaec0 stores the vtable and releases the object
 * at +0x10; FUN_00eaaf10, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object00eaaec0 /* derived name */
{
  public:
    virtual ~Object00eaaec0();

  private:
    u8 unknown8[0x8];
    Referenced00eaaec0 *unknown10; /* +0x10 */
};

// NONMATCHING: the count's merge in the release loop: the base has `lea esi,
// [rsi + rdx]` where this build has `or esi, edx` (InstCombine's or of the
// masked halves either way; the base converts the or-as-add pseudo to three
// addresses with the low half live after the loop: 63 such `lea` in the game
// region's releases, the increments keep `or`); one byte short.
Object00eaaec0::~Object00eaaec0()
{
    unknown10->removeReference();
}
