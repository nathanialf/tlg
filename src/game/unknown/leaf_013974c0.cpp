/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cc6c0.h"

/* derived names: the class whose vtable is at 0x16c7ae8
 * (config/vtables.derived.base.txt; stored by FUN_01398280), over
 * Object016cc6c0 with RefHolder013974c0 at +0x28: slot 2 Object016cc6c0's
 * (0x69a0), slots 3 and 4 pure, slots 5 and 6 (0x9531c0, 0x953730) its
 * overriders of RefHolder013974c0's two functions (the second vtable at
 * 0x16c7b58 holds the thunks 0x953720 and 0x953820 to them). No members of
 * its own to destroy: its destructor stores no vptr of its own. */
class Object016c7ae8 /* derived name */
    : public Object016cc6c0,
      public RefHolder013974c0
{
  public:
    virtual ~Object016c7ae8();
    virtual void slot3() = 0; /* derived name; not traced */
    virtual void slot4() = 0; /* derived name; not traced */
    virtual void slot0();     /* derived name; 0x9531c0, not traced */
    virtual void slot1();     /* derived name; 0x953730, not traced */
};

/* FUN_013974c0 (slot 0): RefHolder013974c0's part (its vptr stored at +0x28,
 * the reference at +0x30 released), then Object016cc6c0's destructor
 * 0x137be20 as a tail call; FUN_01397570, slot 1, the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016c7ae8::~Object016c7ae8() {}
