/* src/include/tlg_game_object016cd348.h: the class whose vtable is at
 * 0x16cd348, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016CD348_H
#define TLG_GAME_OBJECT016CD348_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16cd348
 * (config/vtables.derived.base.txt, stored by FUN_00991430 FUN_00991560 FUN_00991670 and 3 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slot 5 its own (declared; its body is not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_01382c30 tears them down
 * (the block at +0x28); the rest are not traced. */
class Object016cd348 : public Object016b9108 /* derived name */
{
  public:
    Object016cd348(const Name &name); /* 0x991430, its row named for it (D15) */
    virtual ~Object016cd348();
    virtual void slot5(); /* derived name; FUN_01382dd0, not traced */

  private:
    u8 unknown24[0x4];
    /* +0x28: an owned block, released by the destructor (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block28;
    u8 unknown30
        [0x38]; /* 0x68 bytes in all (`mov edi, 0x68` before operator new in the creator FUN_009912d0); not traced */
};

#endif
