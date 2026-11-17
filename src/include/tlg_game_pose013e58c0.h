/* src/include/tlg_game_pose013e58c0.h: the six-bone poser whose slot 5 takes
 * each bone's pose from the model and keeps the frame before it
 * (FUN_013e58c0, FUN_013f4370, FUN_01485810: one per unit, each over its
 * unit's own VECTOR_ZERO; vtables 0x16d4ba0, 0x16d5418, 0x16d79a8), and the
 * same over four bones as slot 6 of 0x16d4c20 and 0x16d4ca8 (FUN_013e59f0,
 * FUN_013e5b20). Every name here is derived. */
#ifndef TLG_GAME_POSE013E58C0_H
#define TLG_GAME_POSE013E58C0_H

#include "tlg_types.h"
#include "tlg_game_fade013d2490.h"

/* derived names: a bone's frame and the one before it */
struct FramePair013e58c0 {  /* derived name */
    Frame016c1128 current;  /* +0x0 */
    Frame016c1128 previous; /* +0x20 */

    /* the frame kept as the one before (two vector copies) */
    void keep() /* derived name */
    {
        previous.unknown0 = current.unknown0;
        previous.unknown10 = current.unknown10;
    }
};

/* derived names: one bone of the poser (24 bytes): its frames */
struct PoserBone013e58c0 {     /* derived name */
    FramePair013e58c0 *frames; /* +0x0 */
    u8 unknown8[0x10];
};

/* derived names: the poser: the model, the model's pose index of each bone
 * and the bones (six for the slot-5 classes, four for the slot-6 classes
 * 0x16d4c20 and 0x16d4ca8); its classes are not traced */
struct Poser013e58c0 { /* derived name */
    void *vptr;
    FadeModel013d4610 *model; /* +0x8 */
    const int *indices;       /* +0x10 */
    u8 unknown18[0x10];
    PoserBone013e58c0 *bones; /* +0x28 */
};

#endif
