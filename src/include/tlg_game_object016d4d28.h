/* src/include/tlg_game_object016d4d28.h: three track classes of the shape
 * of Object016d52c8 (tlg_game_object016d7a28.h), each built by a
 * constructor in its own file's stretch of inline functions (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D4D28_H
#define TLG_GAME_OBJECT016D4D28_H

#include "tlg_types.h"
#include "tlg_game_frames013fb310.h"

/* derived names: the class whose vtable is at 0x16d4d28 (three slots; the
 * row of config/vtables.derived.base.txt names it), stored by its
 * constructor FUN_013e5230 and by FUN_00fcd3c0. The slots are not traced.
 * The constructor is FUN_013ef390's body with func_00fda5c0.cpp's VECTOR_W,
 * not written: defined there (equal alone in the whole module), that
 * file's copy of FUN_013e71b0, the first the link meets, inlines
 * FrameSet00fda5c0's constructor (cost 210, the unit's threshold 225),
 * which the base calls. The base's copy and both constructors lie in the
 * file's stretch of inline functions, so they were inline there; the
 * reading, not compiled: the inliner's check for an outer inline it would
 * spoil (Inliner.cpp:351-394 of 3.7.1, a linkonce_odr caller) kept the
 * call, with the constructor inline and its caller FUN_00fcc550 written. */
class Object016d4d28 /* derived name */
{
  public:
    /* FUN_013e5230 (not written, above): each array made one element for
     * each key, then every key cleared (the file's own VECTOR_W) */
    explicit Object016d4d28(unsigned count);

    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    FadeModel013d4610 *model;               /* +0x8: null from the constructor */
    Array01343a80<u32> values10;            /* +0x10: one for each key, cleared */
    Array01343a80<FrameSet00fda5c0> sets28; /* +0x28: one for each key (FUN_013e71b0) */
    Array01343a80<Frame016c1128> frames40;  /* +0x40: one for each key */
    u8 unknown58[0x8];
    Frame016c1128 frame60;       /* +0x60 */
    Array01343a80<u32> values80; /* +0x80: one for each key, cleared */
    unsigned count;              /* +0x98: the number of keys */
};

/* derived names: the class whose vtable is at 0x16d56e8 (three slots), the
 * part of Object016d5760 and Object016d5710 that FUN_013fb5f0 and FUN_013fb820 destroy after
 * storing this vtable, with the fields of Object016d52c8 (as the parts of
 * tlg_game_object0143e060.h: its destructor, implicit, is inlined into
 * both).
 * No destructor of its own in the executable. The slots are not traced. */
class Object016d56e8 /* derived name */
{
  public:
    /* FUN_01400e60: each array made one element for each key, then every key
     * cleared (the file's own VECTOR_W) */
    explicit Object016d56e8(unsigned count);

    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    FadeModel013d4610 *model;               /* +0x8: null from the constructor */
    Array01343a80<u32> values10;            /* +0x10: one for each key, cleared */
    Array01343a80<FrameSet00fda5c0> sets28; /* +0x28: one for each key (FUN_013e71b0) */
    Array01343a80<Frame016c1128> frames40;  /* +0x40: one for each key */
    u8 unknown58[0x8];
    Frame016c1128 frame60;       /* +0x60 */
    Array01343a80<u32> values80; /* +0x80: one for each key, cleared */
    unsigned count;              /* +0x98: the number of keys */
};

/* derived names: the class whose vtable is at 0x16d6178 (three slots; the
 * row of config/vtables.derived.base.txt names it), stored by its
 * constructor FUN_01446a80 (func_01174d00.cpp) and by FUN_01166b80 and
 * FUN_01167470. The slots are not traced. */
class Object016d6178 /* derived name */
{
  public:
    /* FUN_01446a80: each array made one element for each key, then every key
     * cleared (the file's own VECTOR_W) */
    explicit Object016d6178(unsigned count);

    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    FadeModel013d4610 *model;               /* +0x8: null from the constructor */
    Array01343a80<u32> values10;            /* +0x10: one for each key, cleared */
    Array01343a80<FrameSet00fda5c0> sets28; /* +0x28: one for each key (FUN_013e71b0) */
    Array01343a80<Frame016c1128> frames40;  /* +0x40: one for each key */
    u8 unknown58[0x8];
    Frame016c1128 frame60;       /* +0x60 */
    Array01343a80<u32> values80; /* +0x80: one for each key, cleared */
    unsigned count;              /* +0x98: the number of keys */
};

#endif
