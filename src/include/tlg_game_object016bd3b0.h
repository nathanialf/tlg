/* src/include/tlg_game_object016bd3b0.h: the class whose vtable is at
 * 0x16bd3b0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BD3B0_H
#define TLG_GAME_OBJECT016BD3B0_H

#include "tlg_game_counted00bd7e30.h"
#include "tlg_game_shared.h"

/* derived names: a set of references at +0xd0 of the class below, five of
 * 0x88 bytes: one to a counted object and sixteen to shared objects, plain
 * pointers dropped by FUN_00df1030 (the loop at 0xdf11a0) */
struct Set016bd3b0 /* derived name */
{
    Counted00bd7e30 *counted; /* +0x0 */
    Shared00901550 *shared8;  /* +0x8 */
    Shared00901550 *shared10; /* +0x10 */
    Shared00901550 *shared18; /* +0x18 */
    Shared00901550 *shared20; /* +0x20 */
    Shared00901550 *shared28; /* +0x28 */
    Shared00901550 *shared30; /* +0x30 */
    Shared00901550 *shared38; /* +0x38 */
    Shared00901550 *shared40; /* +0x40 */
    Shared00901550 *shared48; /* +0x48 */
    Shared00901550 *shared50; /* +0x50 */
    Shared00901550 *shared58; /* +0x58 */
    Shared00901550 *shared60; /* +0x60 */
    Shared00901550 *shared68; /* +0x68 */
    Shared00901550 *shared70; /* +0x70 */
    Shared00901550 *shared78; /* +0x78 */
    Shared00901550 *shared80; /* +0x80 */
};

/* derived names: an entry at +0x380 of the class below, sixteen of 0x28
 * bytes with references to shared objects at +0x8 to +0x18, plain pointers
 * dropped by FUN_00df1030 (the loop at 0xdf10e0); the other fields are not
 * traced */
struct Entry016bd3b0 /* derived name */
{
    u8 unknown0[0x8];
    Shared00901550 *shared8;  /* +0x8 */
    Shared00901550 *shared10; /* +0x10 */
    Shared00901550 *shared18; /* +0x18 */
    u8 unknown20[0x8];
};

/* derived names: the class whose vtable is at 0x16bd3b0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b981a0
 * and its complete destructor FUN_00df0f40; home ComputeInterface.cpp, as
 * leaf_00df2f80.cpp reads it): four shared objects held at +0x30, +0x60,
 * +0xc0 and +0x630, dropped by the destructor last first after it hands
 * the object to releaseResources (FUN_00df1030, also called by
 * FUN_00b8e610 at 0xb8e949), which drops those and the references the
 * object holds by plain pointers: the sets at +0xd0, the entries at +0x380,
 * four at +0x600 to +0x618, two of six at +0x660 and +0x690 and two at
 * +0x650 and +0x658. FUN_00df1930, slot 1, is the deleting destructor. The
 * other members are not traced. */
class Object016bd3b0 /* derived name */
{
  public:
    virtual ~Object016bd3b0();

    void releaseResources(); /* derived name */

  private:
    u8 unknown8[0x28];
    SharedRef00901550<Shared00901550> shared30; /* +0x30 */
    u8 unknown38[0x28];
    SharedRef00901550<Shared00901550> shared60; /* +0x60 */
    u8 unknown68[0x58];
    SharedRef00901550<Shared00901550> sharedc0; /* +0xc0 */
    u8 unknownc8[0x8];
    Set016bd3b0 sets[5]; /* +0xd0 */
    u8 unknown378[0x8];
    Entry016bd3b0 entries[16]; /* +0x380 */
    Shared00901550 *shared600; /* +0x600 */
    Shared00901550 *shared608; /* +0x608 */
    Shared00901550 *shared610; /* +0x610 */
    Shared00901550 *shared618; /* +0x618 */
    u8 unknown620[0x10];
    SharedRef00901550<Shared00901550> shared630; /* +0x630 */
    u8 unknown638[0x18];
    Shared00901550 *shared650;  /* +0x650 */
    Shared00901550 *shared658;  /* +0x658 */
    Shared00901550 *sharedA[6]; /* +0x660 */
    Shared00901550 *sharedB[6]; /* +0x690 */
};

#endif
