/* src/include/tlg_game_object0140c8d0.h: the members of the two classes
 * whose destructors are 0x10c7430 and 0x12d32a0 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT0140C8D0_H
#define TLG_GAME_OBJECT0140C8D0_H

#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object0139b6b0.h"
#include "tlg_game_object0140ccc0.h"

/* derived name: a 16-bit count other threads raise while they work on
 * these objects (FUN_010f17f0 raises it around its call); the two
 * destructors wait for it to be zero (`xor ecx, ecx; xor eax, eax; lock
 * cmpxchg word [0x5823544], cx; je` at 0x10c74ed and 0x12d335d, yielding
 * between attempts) */
extern short D_5823544;

/* derived names: the 0x960-byte member whose destructor is FUN_0140c8d0
 * (four of them from +0x1370 of the two holders, destroyed last first:
 * `lea rdi, [r14+0x2f90]; lea rbx, [r14+0x1370]; call 0x140c8d0` at
 * 0x10c781e). Not polymorphic; the destructor releases fifteen blocks, last
 * first, all in its own body: five at the same places in each of three
 * 0x2d0-byte stretches from +0x20 (+0x0, +0xb0, +0x190, +0x1a8, +0x1c0),
 * members of the object itself (a part with a destructor of its own, three
 * of them, is called three times by the compiler, not inlined). The rest is
 * not traced. */
class Object0140c8d0 /* derived name */
{
  public:
    ~Object0140c8d0();

  private:
    u8 unknown0[0x20];
    OwnedBlock05943280 block20; /* +0x20 */
    u8 unknown28[0xa8];
    OwnedBlock05943280 blockd0; /* +0xd0 */
    u8 unknownd8[0xd8];
    OwnedBlock05943280 block1b0; /* +0x1b0 */
    u8 unknown1b8[0x10];
    OwnedBlock05943280 block1c8; /* +0x1c8 */
    u8 unknown1d0[0x10];
    OwnedBlock05943280 block1e0; /* +0x1e0 */
    u8 unknown1e8[0x108];
    OwnedBlock05943280 block2f0; /* +0x2f0 */
    u8 unknown2f8[0xa8];
    OwnedBlock05943280 block3a0; /* +0x3a0 */
    u8 unknown3a8[0xd8];
    OwnedBlock05943280 block480; /* +0x480 */
    u8 unknown488[0x10];
    OwnedBlock05943280 block498; /* +0x498 */
    u8 unknown4a0[0x10];
    OwnedBlock05943280 block4b0; /* +0x4b0 */
    u8 unknown4b8[0x108];
    OwnedBlock05943280 block5c0; /* +0x5c0 */
    u8 unknown5c8[0xa8];
    OwnedBlock05943280 block670; /* +0x670 */
    u8 unknown678[0xd8];
    OwnedBlock05943280 block750; /* +0x750 */
    u8 unknown758[0x10];
    OwnedBlock05943280 block768; /* +0x768 */
    u8 unknown770[0x10];
    OwnedBlock05943280 block780; /* +0x780 */
    u8 unknown788[0x1d8];
};

/* derived names: the class whose vtable is at 0x16d5980 (four slots; the
 * row of config/vtables.derived.base.txt names it), the member at +0x230 of
 * the class whose destructor is FUN_010c7430, which holds its destructor
 * inlined: the vtable stored, then `lea rdi, [r14+0x2c0]; call 0x140ccc0`
 * for the part at +0x90. No destructor of its own in the executable.
 * 0x1140 bytes to the member after it. The slots are not traced. */
class Object016d5980 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */

  private:
    u8 unknown8[0x88];
    Object0140ccc0 part90; /* +0x90 */
};

/* derived names: the class whose vtable is at 0x16d7d60 (four slots; the
 * row of config/vtables.derived.base.txt names it), the member at +0x230 of
 * the class whose destructor is FUN_012d32a0, which holds its destructor
 * inlined: the vtable stored, then `lea rdi, [r14+0x2c0]; call 0x140ccc0`
 * for the part at +0x90. No destructor of its own in the executable.
 * 0x1140 bytes to the member after it. The slots are not traced. */
class Object016d7d60 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */

  private:
    u8 unknown8[0x88];
    Object0140ccc0 part90; /* +0x90 */
};

#endif
