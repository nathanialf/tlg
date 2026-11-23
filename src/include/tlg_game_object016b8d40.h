/* src/include/tlg_game_object016b8d40.h: the class whose vtable is at
 * 0x16b8d40 (config/vtables.derived.base.txt: stored by its constructor
 * 0xca34c0 and its destructors 0xca38f0 and 0xca39b0), a base of other game
 * classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8D40_H
#define TLG_GAME_OBJECT016B8D40_H

#include "tlg_game_name.h"
#include "tlg_game_object01343880.h"

/* derived names: the class of the vtable at 0x16b8d40, whose complete
 * destructor is 0xca38f0 (its row named for it, D15), over Object01343880:
 * its slots 5 to 8 are that class's (0x58a0, 0x1343880, 0x1af750 twice) and
 * its constructor clears that class's +0x28 and +0x30 with its own fields.
 * The constructor (0xca34c0, not written) finds the object registered
 * under the name of the type (the table at +0xf8 of the object at
 * 0x5938c40), links this object at the head of that object's list at
 * +0x38 and calls its slot 7; the destructor (leaf_00ca38f0.cpp) finds it
 * again and calls its slot 8 with this object. The classes derived from it
 * tail-call that destructor from their own. */
class Object016b8d40 : public Object01343880 /* derived name */
{
  public:
    Object016b8d40(
        const Name &
            name); /* 0xca34c0, its row named after it (D15): the derived classes' creators call it (FUN_00b1f270) */
    virtual ~Object016b8d40();

    /* slot 9, FUN_013742c0 (leaf_013742c0.cpp, written on a record of its
     * own): sets the int at +0x50 and returns 1 */
    virtual int slot9(); /* derived name */
    /* slot 10: 0x58a0, which returns 1 */
    virtual int slot10(); /* derived name */
    /* slot 11, FUN_013742d0 (leaf_013742d0.cpp): clears the int at +0x50 */
    virtual void slot11(); /* derived name */
    /* slot 12: the empty body 0x1af750 */
    virtual void slot12(); /* derived name */

  private:
    /* +0x38: the next object of the list the found object holds at its
     * +0x38 (the constructor links this object at the head) */
    Object016b8d40 *next38;
    /* +0x40: the pointer that points to this object in that list */
    Object016b8d40 **link40;
    u64 unknown48; /* +0x48: 1 from the constructor; not traced */

  public:
    /* +0x50: zero from the constructor, set by slot 9 and cleared by slot
     * 11; Object016b8fd0's slot 10 does nothing while it is clear */
    int unknown50;
};

#endif
