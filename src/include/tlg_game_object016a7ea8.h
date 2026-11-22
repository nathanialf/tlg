/* src/include/tlg_game_object016a7ea8.h: the class whose vtable is at
 * 0x16a7ea8 and the class over it at 0x16a7f18 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7EA8_H
#define TLG_GAME_OBJECT016A7EA8_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16a7ea8
 * (config/vtables.derived.base.txt, stored by FUN_002ae3c0 FUN_002aec50),
 * derived from Object016b85e0 (its constructor 0x2ae3c0 first calls that
 * class's constructor 0xc55320). 0x420 bytes (`mov edi, 0x420` before
 * operator new in its creator FUN_002aa650);
 * its destructor FUN_002aec50 (the row named for it, D15) is not written,
 * and its fields are not traced. */
class Object016a7ea8 : public Object016b85e0 /* derived name */
{
  public:
    Object016a7ea8(const Name &name); /* 0x2ae3c0, its row named after it (D15) */
    virtual ~Object016a7ea8();

  private:
    u8 unknown238[0x1e8];
};

/* derived name: the counted object the array of references of the class
 * below refers to; nothing of it is traced but its base. */
class Node002b5080 : public Object016b9108 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16a7f18
 * (config/vtables.derived.base.txt, stored by FUN_002b4bf0 FUN_002b5080),
 * derived from Object016a7ea8. Its members are traced only where the
 * destructor releases them: two arrays of Names at +0x420 and +0x438,
 * counted references at +0x450 and +0x498 with an array of them at +0x480
 * between (references to a class of its own: its destructor is inlined), an
 * array of counted references at +0x4a0 (FUN_0134f620) and blocks at +0x538
 * and +0x550. */
class Object016a7f18 : public Object016a7ea8 /* derived name */
{
  public:
    Object016a7f18(const Name &name); /* 0x2b4bf0, its row named after it (D15) */
    virtual ~Object016a7f18();

  private:
    Array05943280<Name> names420;              /* +0x420 */
    Array05943280<Name> names438;              /* +0x438 */
    AtomicRef0045c470<Object016b9108> held450; /* +0x450 */
    u8 unknown458[0x28];
    Array05943280<AtomicRef0045c470<Node002b5080>> refs480; /* +0x480 */
    AtomicRef0045c470<Object016b9108> held498;              /* +0x498 */
    Object0134f620 refs4a0;                                 /* +0x4a0 */
    u8 unknown4b8[0x80];
    OwnedBlock05943280 block538; /* +0x538 */
    u8 unknown540[0x10];
    OwnedBlock05943280 block550; /* +0x550 */
    u8 unknown558[0x18];         /* to the 0x570 bytes its creator FUN_002b1070 allocates */
};

#endif
