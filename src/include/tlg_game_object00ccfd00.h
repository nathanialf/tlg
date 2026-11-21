/* src/include/tlg_game_object00ccfd00.h: the class whose destructor is
 * 0xccfd00, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT00CCFD00_H
#define TLG_GAME_OBJECT00CCFD00_H

#include "tlg_types.h"

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

class Object00ccfd00;

/* derived names: the object the pointer at +0x40 names; its pointer at
 * +0x20 names the holder back. Only that field is traced (the holder's
 * destructor clears both ends). */
struct Peer00ccfd00 /* derived name */
{
    inline void detach(); /* derived name */

    u8 unknown0[0x20];
    Object00ccfd00 *holder20; /* +0x20 */
};

/* derived names: the class whose complete destructor is 0xccfd00 (its row
 * named for it, D15) and whose vtable is 0x16b92f8, over Object016b9108
 * (slots 2 to 4 are the base's). The classes derived from it tail-call that
 * destructor from their own (the files that include this header). The
 * destructor is the key function (leaf_00ccfd00.cpp). Its own fields from
 * +0x24 are traced only where the destructor reads them (the linked object
 * at +0x40). */
class Object00ccfd00 : public Object016b9108 /* derived name */
{
  public:
    Object00ccfd00(
        const Name &name,
        int kind); /* 0xccfbe0, its row named after it (D15): the derived classes' creators call it (FUN_00e90cb0 passes 4) */
    virtual ~Object00ccfd00();

  private:
    friend struct Peer00ccfd00;

    u8 unknown24[0x1c];
    Peer00ccfd00 *peer40; /* +0x40: detached by the destructor */
    /* 0x58 bytes: the class at 0x16d3248 has its counted reference at +0x58
     * (FUN_00e93310 allocates 0x68 and clears +0x58 and +0x60 after this
     * constructor; its destructor 0x13cbe00 releases +0x58 before this
     * one's); the fields are not traced */
    u8 unknown48[0x10];
};

/* derived name: cuts the link from both ends where a holder is attached
 * (`mov rcx, [rax+0x20]; test rcx, rcx; je; mov qword [rcx+0x40], 0;
 * mov qword [rax+0x20], 0`). */
inline void Peer00ccfd00::detach()
{
    if (holder20 != 0) {
        holder20->peer40 = 0;
        holder20 = 0;
    }
}

#endif
