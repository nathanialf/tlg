/* src/include/tlg_game_object016a7db8.h: the class whose vtable is at
 * 0x16a7db8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7DB8_H
#define TLG_GAME_OBJECT016A7DB8_H

#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7db8
 * (config/vtables.derived.base.txt, stored by FUN_002a94b0 FUN_002a9720 FUN_002a9970), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_002a9720 tears them down
 * (the blocks at +0x138, +0x120, +0xc8, +0xb0, +0x98, +0x80, +0x68); the rest are not traced. */
class Object016a7db8 : public Object016b9108 /* derived name */
{
  public:
    Object016a7db8(const Name &name); /* FUN_002a94b0 */
    virtual ~Object016a7db8();

  private:
    u8 unknown24[0x44];
    /* +0x68: an owned block, released by the destructor (`mov rax, [rbx+0x68]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block68;
    u8 unknown70[0x10];
    /* +0x80: an owned block, released by the destructor (`mov rax, [rbx+0x80]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block80;
    u8 unknown88[0x10];
    /* +0x98: an owned block, released by the destructor (`mov rax, [rbx+0x98]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block98;
    u8 unknowna0[0x10];
    /* +0xb0: an owned block, released by the destructor (`mov rax, [rbx+0xb0]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 blockb0;
    u8 unknownb8[0x10];
    /* +0xc8: an owned block, released by the destructor (`mov rax, [rbx+0xc8]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 blockc8;
    u8 unknownd0[0x50];
    /* +0x120: an owned block, released by the destructor (`mov rax, [rbx+0x120]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block120;
    u8 unknown128[0x10];
    /* +0x138: an owned block, released by the destructor (`mov rax, [rbx+0x138]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block138;
    u8 unknown140[0x10]; /* the rest of the 0x150 bytes the creator allocates; not traced */
};

#endif
