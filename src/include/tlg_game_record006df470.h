/* src/include/tlg_game_record006df470.h: three records copied member by
 * member by their own assignments (FUN_006df470, FUN_006df5e0,
 * FUN_006df730), each defined in its own unit (game region;
 * docs/TARGETS.md). FUN_006dbc80 copies one of each from a character
 * component. Every name here is derived. */
#ifndef TLG_GAME_RECORD006DF470_H
#define TLG_GAME_RECORD006DF470_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: the copy of a record of an int, an exchanged reference
 * and two names, written member by member in the order of the offsets
 * (leaf_006df470.cpp). The record's class is not traced. */
struct Record006df470 { /* derived name */
    void operator=(const Record006df470 &other);

    int unknown0;                             /* +0x0 */
    AtomicRef0045c470<Object016b9108> object; /* +0x8 */
    Name unknown10;                           /* +0x10 */
    Name unknown14;                           /* +0x14 */
};

/* derived names: a 0x50-byte record copied member by member: an int, a
 * counted reference at +0x8 replaced by compare-and-swap, two 16-byte
 * aligned vectors, a Name at +0x30, eight bytes at +0x34 moved as one, and
 * a third vector (leaf_006df5e0.cpp). The members' types beyond their sizes
 * and alignments are not traced. */
struct Pair006df5e0 { /* derived name */
    int unknown0;
    int unknown4;
};

struct Record006df5e0 { /* derived name */
    void operator=(const Record006df5e0 &other);

    int unknown0;                               /* +0x0 */
    AtomicRef0045c470<Object016b9108> unknown8; /* +0x8 */
    Float4A unknown10;                          /* +0x10 */
    Float4A unknown20;                          /* +0x20 */
    Name unknown30;                             /* +0x30 */
    Pair006df5e0 unknown34;                     /* +0x34 */
    Float4A unknown40;                          /* +0x40 */
};

/* derived names: a record FUN_006d9xxx copies from +0x2370 to +0x4f00 of
 * its object (0x6d946d): an int, two counted references another thread may
 * replace and a name (leaf_006df730.cpp). Their meaning is not traced. */
struct Binding006df730 /* derived name */
{
    /* 0x6df730: the members assigned in turn */
    void operator=(const Binding006df730 &other);

    int unknown0;                             /* +0x0 */
    AtomicRef0045c470<Object016b9108> held8;  /* +0x8 */
    AtomicRef0045c470<Object016b9108> held10; /* +0x10 */
    Name name18;                              /* +0x18 */
};

#endif
