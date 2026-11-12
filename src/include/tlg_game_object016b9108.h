/* src/include/tlg_game_object016b9108.h: the common base of the classes the
 * registry at 0x5945a38 holds, whose vtable is at 0x16b9108 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B9108_H
#define TLG_GAME_OBJECT016B9108_H

#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16b9108
 * (config/vtables.derived.base.txt). Its constructor at 0xcb6310 (not
 * written; FUN_00cb6310 in the comments of the files written before its row
 * was named) takes the object's name by reference and is called by the
 * creators of the derived classes (FUN_00206b60 and on) after they allocate
 * the object and take the lock at 0x59458a4: it zeroes the fields, keeps bit
 * 6 of the flags, assigns the name, takes the allocator the creator left at
 * 0x59458a8 (clearing it and the lock) and registers the object with the
 * registry at 0x5945a38. Its destructor (FUN_00cb65f0, leaf_00cb65f0.cpp)
 * only drops the two names; the derived classes' destructors inline it
 * (0x206cf0 and on: their own vptr store dead). The vtable has five slots:
 * the two destructors, the release FUN_00cb66f0 (leaf_00cb66f0.cpp, a free
 * function there: clears flag bit 1, unregisters the object and hands it to
 * its allocator record; the constructor calls it when it drops the last
 * reference), and two empty slots folded onto 0x1af750, declared here so the
 * derived classes' own slots (5 and on) take their places in the vtable.
 * tlg_game_multibase.h's Class137ba70 derives from it (slots 2 to 4, the
 * int at +0x20). */
class Object016b9108 /* derived name */
{
  public:
    Object016b9108(const Name &name); /* 0xcb6310, its row named after it (D15) */
    virtual ~Object016b9108();
    /* Slots 2 to 4 of 0x16b9108: the release FUN_00cb66f0 and two empty
     * bodies folded onto 0x1af750; parameters not traced. */
    virtual void FUN_00cb66f0(); /* derived name, after the release */
    virtual void slot3();        /* derived name; 0x1af750 */
    virtual void slot4();        /* derived name; 0x1af750 */

  private:
    /* +0x8: the reference count, 0xdeadc0de once the object is released
     * (FUN_00cb6310: `lock inc` unless dead, the release at the last
     * reference) */
    int references8;
    Name name0c;   /* +0xc: assigned from the constructor's argument */
    Name name10;   /* +0x10: zero in the constructor */
    u16 unknown14; /* +0x14: zero in the constructor */
    /* +0x16: the constructor keeps bit 6 (`and 0x40`), the release clears
     * bit 1 (`and -3`) */
    u8 flags16;
    /* +0x18: the record whose function at +0x10 frees this object
     * (FUN_00cb66f0: `mov rax, [rbx+0x18]; mov rdi, rbx; jmp [rax+0x10]`) */
    void *allocator18;

  protected:
    /* +0x20: zero in the constructor; the bits the classes derived from it
     * set and test (FUN_0137ba70 sets them, FUN_0137ba50 clears 0x30, slot 6
     * of tlg_game_multibase.h's classes returns them) */
    int flags;
};

#endif
