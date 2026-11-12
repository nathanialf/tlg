/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: a script C function (its address is not stored where a
 * table was found): with the object at +0x8c0 of the global's member at
 * +0x38 (1 returned without either), reads its first argument as a Name
 * through FUN_00c91140 with a reader of the frame, calls FUN_003ebc90 on the
 * object, drops the Name and returns 0. The reader is 0x20 bytes: the state,
 * a null pointer, the frame's first argument as an index from the top (minus
 * the count of arguments) and two ints cleared. */
struct ArgumentReader00c8c290 { /* derived name */

    explicit ArgumentReader00c8c290(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index =
            -(int)((unsigned long)((char *)state_->top - (char *)state_->base) / sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

struct Object003ebc90; /* derived name */

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x8c0];
    Object003ebc90 *unknown8c0; /* +0x8c0 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

void FUN_00c91140(ArgumentReader00c8c290 *reader, Name *name); /* derived name */
void FUN_003ebc90(Object003ebc90 *object);                     /* derived name */

// NONMATCHING: the Name's release: the base passes the index it loaded for the test to
// FUN_00d66e30 (`mov edi, [rbp-0x40]; test rdi, rdi; mov rax, rdi`), the header's release reads
// it again after the atomic; and the Name's zero store between the reader's stores (list-ilp)
int FUN_003e7260(lua_State *state) /* derived name */
{
    Member057c9390_38 *member = D_57c9390->unknown38;
    if (!member)
        return 1;
    Object003ebc90 *object = member->unknown8c0;
    if (!object)
        return 1;
    ArgumentReader00c8c290 reader(state);
    Name name;
    FUN_00c91140(&reader, &name);
    FUN_003ebc90(object);
    return 0;
}
