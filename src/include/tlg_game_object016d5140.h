/* src/include/tlg_game_object016d5140.h: the class whose vtable is at
 * 0x16d5140, the fading state of one unit of the game region
 * (tlg_game_fade013d2490.h; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D5140_H
#define TLG_GAME_OBJECT016D5140_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"

/* derived name: this unit's fade entry: one element type per unit, as the
 * base holds one resize of an array of them per unit */
struct FadeEntry01000ba0 : FadeEntry013d2490 { /* derived name */
};

/* derived names: the class of the vtable at 0x16d5140
 * (config/vtables.derived.base.txt; made by FUN_00ff6830), the fading state of
 * tlg_game_fade013d2490.h in this unit's copy: slot 2 (FUN_013ea8a0) begins a
 * fade in, slot 5 (FUN_013ecff0) is one update, slot 6 (FUN_013ed0d0) poses the
 * target's entries while it runs; slot 3 is the shared empty body
 * FUN_001af750 and slot 4 is pure (__cxa_pure_virtual). The constructor,
 * inlined into its maker, stores the model, the owner, the entries' array
 * with its lock word, a Name, 16 bytes at +0x40, the model's address plus
 * 0x1c4 at +0x50, the state 2 and 16 bytes from +0x5c (the level, the int
 * and the two lengths), then sizes the entries to the target's count. Its
 * complete destructor 0xff6950 releases the Name, then the entries' block; the
 * deleting one 0xff69f0 is the compiler's. */
class Object016d5140 /* derived name */
{
  public:
    virtual ~Object016d5140();
    virtual void slot2();     /* derived name: FUN_013ea8a0 (func_01000ba0.cpp) */
    virtual void slot3();     /* derived name: FUN_001af750, not traced */
    virtual void slot4() = 0; /* derived name: pure here */
    virtual void slot5();     /* derived name: FUN_013ecff0 (leaf_013ecff0.cpp) */
    virtual void slot6();     /* derived name: FUN_013ed0d0 (func_01000ba0.cpp) */

    /* this unit's copy of the fade's large update (FUN_013d0470's; nonzero
     * when it has run), not written */
    int FUN_013ebd10(); /* derived name */

    FadeModel013d4610 *model;                 /* +0x8 */
    FadeOwner013d2490 *owner;                 /* +0x10 */
    Array01343a80<FadeEntry01000ba0> entries; /* +0x18 */
    Name unknown30;                           /* +0x30 */
    u8 unknown34[0x1c];
    void *unknown50; /* +0x50: the model's address plus 0x1c4 (the constructor) */
    int state;       /* +0x58: 1 fading in, 2 full, 3 fading out, 0 off */
    float level;     /* +0x5c */
    u32 unknown60;
    float fadeIn;  /* +0x64: the fade-in's length */
    float fadeOut; /* +0x68: the fade-out's length */
    int unknown6c; /* +0x6c: cleared by the update */
};

/* derived names: the class whose vtable is at 0x16c0710
 * (config/vtables.derived.base.txt), derived from Object016d5140: slot 2 is
 * its own (FUN_00ff8a20: the base's slot 2, then +0x80 set to 1), slot 3
 * FUN_00ff8a40 and slot 4 FUN_00ffaab0 (not traced), the rest the base's. Its
 * destructor FUN_00ff8880 (slot 0) is the class's key function, defined in
 * leaf_00ff6950.cpp with the base's, which it holds in line, so that file
 * emits the vtable; the deleting one FUN_00ff8a00 is the compiler's.
 * The names at +0x78 are an array the object owns, deleted by the
 * destructor. */
class Object016c0710 : public Object016d5140 /* derived name */
{
  public:
    virtual ~Object016c0710();
    virtual void slot2(); /* derived name */

  private:
    u8 unknown70[0x8];
    Array01343a80<Name> *names78; /* +0x78: owned (derived name) */
    int unknown80;                /* +0x80 */
};

#endif
