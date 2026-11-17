/* src/include/tlg_game_object016b9108.h: the root class of the game's
 * counted objects, whose vtable is at 0x16b9108 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B9108_H
#define TLG_GAME_OBJECT016B9108_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_type.h"

/* derived names: the class whose vtable is at 0x16b9108
 * (config/vtables.derived.base.txt; no type info or string names it). Its
 * constructor at 0xcb6310 (not written; FUN_00cb6310 in the comments of the
 * files written before its row was named) takes the object's name by
 * reference and is called by the creators of the derived classes
 * (FUN_00206b60 and on) after they allocate the object and take the lock at
 * 0x59458a4: it zeroes the fields, keeps bit 6 of the flags, assigns the
 * name, takes the type the creator left at 0x59458a8 (clearing it and the
 * lock) and registers the object with the registry at 0x5945a38, holding a
 * counted reference to it meanwhile (`lock inc dword [rbx+8]` at 0xcb6537,
 * dropped through slot 2 or FUN_00c14bc0). Its destructor (FUN_00cb65f0,
 * leaf_00cb65f0.cpp) only drops the two names; the derived classes'
 * destructors inline it (0x206cf0 and on: their own vptr store dead). The
 * vtable has five slots: the two destructors, the release FUN_00cb66f0
 * (leaf_00cb66f0.cpp, a free function there: clears flag bit 1, unregisters
 * the object and hands it to its type's function at +0x10; a counted
 * reference's last drop calls it), and two empty slots folded onto 0x1af750,
 * declared here so the derived classes' own slots (5 and on) take their
 * places in the vtable. The classes derived from it put their own members
 * from +0x24 on (tlg_game_node.h's Node00503fb0, the scene node;
 * tlg_game_multibase.h's Class137ba70: slots 2 to 4, the int at +0x20). */
class Object016b9108 /* derived name */
{
  public:
    Object016b9108(const Name &name); /* 0xcb6310, its row named after it (D15) */
    virtual ~Object016b9108();
    /* slot 2, FUN_00cb66f0: the release (the counted reference's last drop
     * calls it, `call [rax+0x10]` at 0xcb65a7) */
    virtual void destroy(); /* derived name */
    /* Slots 3 and 4 of 0x16b9108: two empty bodies folded onto 0x1af750;
     * parameters not traced. */
    virtual void slot3(); /* derived name; 0x1af750 */
    virtual void slot4(); /* derived name; 0x1af750 */

    /* whether the object's own type is `wanted` or derives from it: the
     * wanted type is read before the object's (0x848cce, FUN_00848c20) */
    bool isKindOf(const Type00503fb0 *wanted) const /* derived name */
    {
        return ::isKindOf(type, wanted);
    }

    /* +0x8: the reference count, 0xdeadc0de once the object is released
     * (FUN_00cb6310: `lock inc` unless dead, the release at the last
     * reference) */
    int references;

    Name name; /* +0xc: assigned from the constructor's argument */

  private:
    Name name10;   /* +0x10: zero in the constructor */
    u16 unknown14; /* +0x14: zero in the constructor */

  public:
    /* +0x16: the constructor keeps bit 6 (`and 0x40`), the release clears
     * bit 1 (`and -3`), a derived constructor sets bit 0 (`or byte
     * [r15+0x16], 1` at 0x8c22a4); bit 2 lets any thread use the object
     * (FUN_00618b00); a word: FUN_00cbd050 ors a 16-bit value into it */
    u16 flags16;

    /* +0x18: the object's type (FUN_00858390), whose function at +0x10
     * frees this object (FUN_00cb66f0: `mov rax, [rbx+0x18]; mov rdi, rbx;
     * jmp [rax+0x10]`) */
    const Type00503fb0 *type;

    /* +0x20: zero in the constructor; bit 1 set when a child is taken out
     * of a node (FUN_00c57120); the bits the classes derived from it set and
     * test (FUN_0137ba70 sets them, FUN_0137ba50 clears 0x30, slot 6 of
     * tlg_game_multibase.h's classes returns them) */
    int flags;
};

/* the object when its type is `type` or derives from it, else null
 * (func_00503fb0.cpp; the link inlines it, and the executable keeps no
 * copy). The walk hands back the object, not a bool: where it is inlined
 * the found object is set on each edge out of the walk and tested again
 * after its loop (0x858390: `test r14, r14` at 0x8583ff; 0x6423c0: `mov
 * rbx, r12` before each compare), where isKindOf's bool is threaded away. */
Object016b9108 *kindOf(Object016b9108 *object, const Type00503fb0 *type); /* derived name */

#endif
