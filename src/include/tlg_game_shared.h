/* src/include/tlg_game_shared.h: an object shared by reference count with
 * a 64-bit count, and the pointer that holds one (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_SHARED_H
#define TLG_GAME_SHARED_H

#include "tlg_types.h"

/* derived names: a reference-counted object: its count at +0x8, taken
 * down atomically (`lock xadd qword [rdi+8], rax` with -1); the holder of
 * the last reference calls slot 2 to destroy it. release() returns the
 * count read again after the decrement (as leaf_00e5aea0.cpp's
 * Shared00e5aea0 and JsDevice do). */
class Shared00901550 /* derived name */
{
  public:
    virtual void slot0();   /* derived name; not traced */
    virtual void slot1();   /* derived name; not traced */
    virtual void destroy(); /* derived name; slot 2 */

    long release() /* derived name */
    {
        if (__sync_fetch_and_sub(&references, 1) == 1)
            destroy();
        return references;
    }

  private:
    /* volatile: the count other threads take and drop while this one
     * releases (the base reads it again after the decrement: `mov rax,
     * [r14]` after the call at 0x901597) */
    volatile long references; /* +0x8 */
};

/* derived names: the pointer that holds one reference to a shared object:
 * dropped and cleared by reset() and by the destructor (0x901550: `test
 * rdi, rdi; je` around the release, then `mov qword [rbx+0x90], 0`) */
template <class T> class SharedRef00901550 /* derived name */
{
  public:
    SharedRef00901550() : object(0) {}

    ~SharedRef00901550()
    {
        reset();
    }

    /* where a maker puts the object it makes (0x901721: `add rax, 0x90`
     * passed as the device's last argument) */
    T **operator&()
    {
        return &object;
    }

    void reset() /* derived name */
    {
        if (object) {
            object->release();
            object = 0;
        }
    }

  private:
    T *object;
};

#endif
