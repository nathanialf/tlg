/* src/include/tlg_game_object011f7800.h: what the classes whose destructors
 * are 0x11f7800 and 0xf2bd20 hold (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT011F7800_H
#define TLG_GAME_OBJECT011F7800_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: a node those classes hold four counted references to
 * (from +0x268); while the holder is active its destructor clears the
 * node's pointer at +0xa0 before it empties the reference (0x11f79f1: `mov
 * qword [rax+0xa0], 0`). A counted object of the root class; the rest is
 * not traced. */
class Node011f7800 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x7c];
    void *unknowna0; /* +0xa0 */
};

/* derived names: an object deleted through slot 1 of its vtable; not
 * traced */
class Owned011f7800 /* derived name */
{
  public:
    virtual ~Owned011f7800();
};

/* derived names: the 24-byte entry of the array at +0x290 of those
 * classes: the object at +0x8 is deleted for each entry while the holder is
 * active (0x11f7927: `movsxd rcx, ebx; lea rcx, [rcx+rcx*2]; mov rdi,
 * [rdx+rcx*8+8]`). The rest is not traced. */
struct Entry011f7800 { /* derived name */
    u8 unknown0[0x8];
    Owned011f7800 *object8; /* +0x8 */
    u8 unknown10[0x8];
};

#endif
