/* src/include/tlg_game_object016acb20.h: the class whose vtable is at 0x16acb20
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACB20_H
#define TLG_GAME_OBJECT016ACB20_H

#include "tlg_game_object00774560.h"
#include "tlg_game_name.h"

/* derived names: the member at +0x100 of the class below, handed to
 * FUN_00216780 while its int at +0x8 is set; the rest is not traced */
struct Member00216780 { /* derived name */
    int FUN_00216780(); /* derived name: not traced */

    u8 unknown0[0x8];
    int unknown8; /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16acb20
 * (config/vtables.derived.base.txt, stored by its constructor FUN_007658a0
 * and its destructor FUN_007659d0, not written), derived from
 * Object00774560; nothing else of it is traced */
class Object016acb20 : public Object00774560 /* derived name */
{
  public:
    Object016acb20(const Name &name); /* 0x7658a0, its row named after it (D15) */
    virtual ~Object016acb20();
    virtual void slot14(Pose0077bac0 *pose); /* FUN_00766e50 */

  private:
    u8 unknownfc[0x4];
    Member00216780 unknown100; /* +0x100 */
    u8 unknown10c
        [0x344]; /* to the 0x450 bytes the creator FUN_00765740 allocates (`mov edi, 0x450`) */
};

#endif
