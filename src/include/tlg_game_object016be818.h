/* src/include/tlg_game_object016be818.h: the class whose vtable is at
 * 0x16be818 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BE818_H
#define TLG_GAME_OBJECT016BE818_H

#include "tlg_types.h"
#include "tlg_game_object00cef280.h"
#include "tlg_game_referenced.h"

class Object016be818;

/* derived names: what the object is made for: its kind at +0x40 (0 to 3, the
 * constructor's switch) and its object at +0x48 */
struct Target00ea8480 { /* derived name */
    u8 unknown0[0x40];
    int kind; /* +0x40 */
    u8 unknown44[0x4];
    Object016be818 *unknown48; /* +0x48 */
};

/* derived names: the counted object the constructor makes for kind 0 (0x40
 * bytes, built by FUN_0017d0c0), which points back at its maker from +0x28 */
class Shape00eb1170 : public Referenced00eaaec0 /* derived name */
{
  public:
    u8 unknownc[0x1c];
    Object016be818 *owner; /* +0x28 */
};

/* derived names: the class of the vtable at 0x16be818
 * (config/vtables.derived.base.txt), over Object00cef280: its constructor
 * FUN_00eb1170 links it to a target (the target at +0x20, the object at the
 * target's +0x48), takes the target's kind at +0x18 and makes a counted
 * object of that kind at +0x28. The complete destructor, FUN_00eb13f0, clears
 * the kind 0 object's link back and drops the reference; FUN_00eb1470, slot
 * 1, is the deleting one. Slots 2 and 3 are not traced. */
class Object016be818 : public Object00cef280 /* derived name */
{
  public:
    explicit Object016be818(Target00ea8480 *target); /* FUN_00eb1170 */
    virtual ~Object016be818();
    virtual void slot2();
    virtual int slot3();

    int kind;                  /* +0x18: the target's kind */
    Target00ea8480 *target;    /* +0x20 */
    Referenced00eaaec0 *shape; /* +0x28: null from the constructor, then the object made */
};

#endif
