/* src/include/tlg_game_counted00760920.h: the classes of the objects the
 * appends FUN_00760920 and FUN_00906610 take references to, and the record
 * two visitors gather them into (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_COUNTED00760920_H
#define TLG_GAME_COUNTED00760920_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: what the +0x28 of an object points to: an int at +0x21c */
struct Object013b7920_28 { /* derived name */
    u8 unknown0[0x21c];
    int unknown21c; /* +0x21c */
};

/* derived names: one of the root class's (the count at +0x8), with the
 * members FUN_013b7610 and FUN_013b7920 read before they append a reference
 * to the object: a pointer at +0x28, an int at +0x30, flags at +0x38, a
 * number from 0 to 12 at +0x48 that picks the array, a pointer at +0x98,
 * flags at +0x188 and an int at +0x18c; not traced further. FUN_013b7920
 * appends references to one object through two appends, FUN_00906610
 * (leaf_00906610.cpp, 3 sites in 2 functions) and FUN_00760920
 * (leaf_00760920.cpp, 11 sites in 6 functions), so their arrays hold
 * references of two classes: written here as a class and one derived from
 * it that adds nothing; which of the two the members belong to is not
 * traced. */
struct Counted00906610 : Object016b9108 { /* derived name */
    u8 unknown24[4];
    Object013b7920_28 *unknown28; /* +0x28 */
    int unknown30;                /* +0x30 */
    u8 unknown34[4];
    u32 flags38; /* +0x38 */
    u8 unknown3c[0xc];
    int kind48; /* +0x48 */
    u8 unknown4c[0x4c];
    void *unknown98; /* +0x98 */
    u8 unknowna0[0xe8];
    u32 flags188;   /* +0x188 */
    int unknown18c; /* +0x18c */
};

struct Counted00760920 : Counted00906610 {}; /* derived name */

typedef Array05943280<Ref00503fb0<Counted00760920>> Array00760920; /* derived name */
typedef Array05943280<Ref00503fb0<Counted00906610>> Array00906610; /* derived name */

/* derived names: what FUN_013b7610 and FUN_013b7920 gather into: thirteen
 * arrays of references from +0x18, one for each number an object's +0x48
 * takes, and arrays at +0x180, +0x1b0 and +0x1c8; the rest is not traced */
struct Record013b7610 { /* derived name */
    u8 unknown0[0x18];
    Array00760920 byKind[13]; /* +0x18 */
    u8 unknown150[0x30];
    Array00760920 objects180; /* +0x180 */
    u8 unknown198[0x18];
    Array00906610 objects1b0; /* +0x1b0 */
    Array00906610 objects1c8; /* +0x1c8 */
};

#endif
