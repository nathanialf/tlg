/* src/include/tlg_game_object016d6a90.h: the class of the vtable at
 * 0x16d6a90 and the class of 0x16ca810 derived from it, read from the bytes
 * of their destructors (the same shapes as tlg_game_object016d3ad0.h's two
 * classes). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D6A90_H
#define TLG_GAME_OBJECT016D6A90_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_simd.h"
#include "tlg_types.h"

/* derived name: this unit's fade entry: one element type per unit, as the
 * base holds one resize of an array of them per unit */
struct FadeEntry01225a30 : FadeEntry013d2490 { /* derived name */
};

/* derived names: the class of the vtable at 0x16d6a90
 * (config/vtables.derived.base.txt; made by FUN_0121a680), the fading state of
 * tlg_game_fade013d2490.h in this unit's copy: slot 2 (FUN_01478b40) begins a
 * fade in, slot 5 (FUN_0147a0a0) is one update, slot 6 (FUN_0147a180) poses the
 * target's entries while it runs; slot 3 is the shared empty body
 * FUN_001af750 and slot 4 is pure (__cxa_pure_virtual). The constructor,
 * inlined into its maker, stores the model, the owner, the entries' array
 * with its lock word, a Name, 16 bytes at +0x40, the model's address plus
 * 0x1c4 at +0x50, the state 2 and 16 bytes from +0x5c (the level, the int
 * and the two lengths), then sizes the entries to the target's count. Its
 * complete destructor 0x147a4d0 releases the Name, then the entries' block; the
 * deleting one 0x147a570 is the compiler's. Its destructor is inline here (in the linkonce stretch, emitted with
 * the vtable in slot 2's unit, the key function's) and inlined into the
 * derived destructors of other units. */
class Object016d6a90 /* derived name */
{
  public:
    virtual ~Object016d6a90() {}

    virtual void slot2();     /* derived name: FUN_01478b40 (func_01225a30.cpp) */
    virtual void slot3();     /* derived name: FUN_001af750, not traced */
    virtual void slot4() = 0; /* derived name: pure here */
    virtual void slot5();     /* derived name: FUN_0147a0a0 (leaf_0147a0a0.cpp) */
    virtual void slot6();     /* derived name: FUN_0147a180 (func_01225a30.cpp) */

    /* this unit's copy of the fade's large update (FUN_013d0470's; nonzero
     * when it has run), not written */
    int FUN_01478dc0(); /* derived name */

    FadeModel013d4610 *model;                 /* +0x8 */
    FadeOwner013d2490 *owner;                 /* +0x10 */
    Array01343a80<FadeEntry01225a30> entries; /* +0x18 */
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

/* derived names: the class of the vtable at 0x16ca810
 * (config/vtables.derived.base.txt; made by FUN_0121a680): a vector at
 * +0x110, an int at +0x124 and an owned block at +0x128 after its base's
 * members. Slot 2, FUN_01223180, is its key function: the vtable and the
 * implicit destructor are emitted with it, the complete one 0x1222fb0
 * releasing the block, then running its base's (inlined), the deleting one
 * 0x12230a0 the complete one inlined. Slot 4 is pure (__cxa_pure_virtual).
 * The other members are not traced. */
class Object016ca810 : public Object016d6a90 /* derived name */
{
  public:
    virtual void slot2(); /* derived name: FUN_01223180 */
    /* derived name: pure here; each class derived from this one gives its
     * own */
    virtual void slot4() = 0;

  private:
    u8 unknown70[0xa0];
    Vec4 unknown110; /* +0x110: cleared by slot 2 */
    u8 unknown120[4];
    int unknown124;                /* +0x124: cleared by slot 2 */
    OwnedBlock05943280 unknown128; /* +0x128 */
};

#endif
