/* src/include/tlg_game_object016d7ab8.h: the class whose vtable is at
 * 0x16d7ab8, the fading state of one unit of the game region
 * (tlg_game_fade013d2490.h; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D7AB8_H
#define TLG_GAME_OBJECT016D7AB8_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"

/* derived name: this unit's fade entry: one element type per unit, as the
 * base holds one resize of an array of them per unit */
struct FadeEntry01295b40 : FadeEntry013d2490 { /* derived name */
};

/* derived names: the class of the vtable at 0x16d7ab8
 * (config/vtables.derived.base.txt; made by FUN_0128f530), the fading state of
 * tlg_game_fade013d2490.h in this unit's copy: slot 2 (FUN_01489630) begins a
 * fade in, slot 5 (FUN_01489780) is one update, slot 6 (FUN_01489860) poses the
 * target's entries while it runs; slot 3 is the shared empty body
 * FUN_001af750 and slot 4 is pure (__cxa_pure_virtual). The constructor,
 * inlined into its maker, stores the model, the owner, the entries' array
 * with its lock word, a Name, 16 bytes at +0x40, the model's address plus
 * 0x1c4 at +0x50, the state 2 and 16 bytes from +0x5c (the level, the int
 * and the two lengths), then sizes the entries to the target's count. Its
 * complete destructor 0x14899e0 releases the Name, then the entries' block; the
 * deleting one 0x1489a80 is the compiler's. */
class Object016d7ab8 /* derived name */
{
  public:
    virtual ~Object016d7ab8();
    virtual void slot2();     /* derived name: FUN_01489630 (func_01295b40.cpp) */
    virtual void slot3();     /* derived name: FUN_001af750, not traced */
    virtual void slot4() = 0; /* derived name: pure here */
    virtual void slot5();     /* derived name: FUN_01489780 (leaf_01489780.cpp) */
    virtual void slot6();     /* derived name: FUN_01489860 (func_01295b40.cpp) */

    /* this unit's copy of the fade's large update (FUN_013d0470's; nonzero
     * when it has run), not written */
    int FUN_01488350(); /* derived name */

    FadeModel013d4610 *model;                 /* +0x8 */
    FadeOwner013d2490 *owner;                 /* +0x10 */
    Array01343a80<FadeEntry01295b40> entries; /* +0x18 */
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

#endif
