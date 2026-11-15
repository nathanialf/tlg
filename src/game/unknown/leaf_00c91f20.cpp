/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d1668.h"

/* derived names: the object the pointer at 0x5938c40 holds and the member
 * at +0x38 of it, whose node at +0x30 the constructor takes a reference to
 * (`mov rax, [0x5938c40]; mov rax, [rax+0x38]; mov rcx, [rax+0x30]` at
 * 0xc91f43). The classes are not traced. */
class Value00c91f20 : public Node00503fb0 /* derived name */
{
};

struct Member05938c40_38 { /* derived name */
    u8 unknown0[0x30];
    /* +0x30: an object of a class over the reference's (the constructor
     * compares it first, `cmp rcx, rbx` at 0xc91f84, where a pointer of the
     * reference's own class compares second) */
    Value00c91f20 *unknown30;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x38];
    Member05938c40_38 *unknown38; /* +0x38 */
};

extern Object05938c40 *D_5938c40;

/* derived name: the constructor of Object016d1668 (the third storer of the
 * vtable 0x16d1668): the base built from the name, the eight bytes at +0x24 and the
 * reference cleared, then the reference set to the node of the member at
 * +0x38 of the object at 0x5938c40. This unit defines the constructor, so it
 * emits the class's vtable and its two destructors (FUN_013abbe0 and
 * FUN_013abd00, defined in the header). */
Object016d1668::Object016d1668(const Name &name) : Object016b9108(name)
{
    Member05938c40_38 *member = D_5938c40->unknown38;
    unknown24 = 0;
    unknown28 = 0;
    held30.set(member->unknown30);
}
