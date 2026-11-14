/* src/include/tlg_game_referenced.h: an object the game holds by reference
 * and its release (moved from leaf_00eaaec0.cpp; the destructors of
 * leaf_00eab2a0.cpp and leaf_00eb17d0.cpp release the same kind). */
#ifndef TLG_GAME_REFERENCED_H
#define TLG_GAME_REFERENCED_H

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
            /* the lowered count is formed before the size is masked
             * (0xeaaee2: `lea edx, [rax + 0xffff]; movzx edx, dx` ahead of
             * `and esi, 0xffff0000`) and tested after the exchange */
            u32 oldValue, newValue;
            u32 newCount;
            do {
                oldValue = *count;
                newCount = (oldValue - 1) & 0xffff;
                newValue = (oldValue & 0xffff0000) | newCount;
            } while (__sync_val_compare_and_swap(count, oldValue, newValue) != oldValue);
            if (newCount == 0) {
                deleteThis();
            }
        }
    }

  private:
    u32 memSizeAndRefCount; /* +0x8 */
};

#endif
