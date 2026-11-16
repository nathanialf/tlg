/* src/include/tlg_game_object016a86d8.h: the class whose vtable is at
 * 0x16a86d8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A86D8_H
#define TLG_GAME_OBJECT016A86D8_H

#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: a 0x70-byte part of Object016a86d8, nine of them from
 * +0x40, each built by its constructor FUN_0033a440 (not written: an empty
 * box at +0x10, 1e9 and -1e9 with w 1, and an array of 64-byte entries at
 * +0x48 grown to one entry). Its block at +0x48 is released where the
 * holder's destructor tears the parts down. The rest is not traced. */
class Member0033a440 /* derived name */
{
  public:
    Member0033a440(); /* 0x33a440, its row named after it (D15) */

  private:
    u8 unknown0[0x48];
    /* +0x48: an owned block, released by the holder's destructor (`mov rax,
     * [rbx+0x88]; ... cmp ecx, 0xa` for the first part) */
    OwnedBlock05943280 block48;
    u8 unknown50[0x20];
};

/* derived names: the class whose vtable is at 0x16a86d8
 * (config/vtables.derived.base.txt, stored by FUN_0033c780 FUN_0033c850), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Nine parts from +0x40;
 * its own fields after them are traced where the constructor sets them. */
class Object016a86d8 : public Object016b9108 /* derived name */
{
  public:
    Object016a86d8(const Name &name); /* FUN_0033c780 */
    virtual ~Object016a86d8();

  private:
    u8 unknown24[0x1c];
    Member0033a440 part40;  /* +0x40 */
    Member0033a440 partb0;  /* +0xb0 */
    Member0033a440 part120; /* +0x120 */
    Member0033a440 part190; /* +0x190 */
    Member0033a440 part200; /* +0x200 */
    Member0033a440 part270; /* +0x270 */
    Member0033a440 part2e0; /* +0x2e0 */
    Member0033a440 part350; /* +0x350 */
    Member0033a440 part3c0; /* +0x3c0 */
    int unknown430;         /* +0x430: 20 from the constructor */
    float unknown434;       /* +0x434: 2 from the constructor */
    int unknown438[3];      /* +0x438: zero from the constructor */
    int unknown444;         /* +0x444: 24 from the constructor */
    float unknown448;       /* +0x448: 2 from the constructor */
    int unknown44c;         /* +0x44c: zero from the constructor */
    int unknown450;         /* +0x450: zero from the constructor */
    int unknown454;         /* +0x454: zero from the constructor */
    u8 unknown458[0x8];     /* the rest of the 0x460 bytes the creator allocates; not traced */
};

#endif
