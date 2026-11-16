/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d22b8.h"

/* derived names: the object a name names, of a class over the reference's
 * (AtomicRef0045c470::set compares it first, `cmp r12, rbx` at 0xd48584) */
struct Value00d48470 : Node00503fb0 {};

/* derived names: the record the pointer at 0x5938c40 holds, and the record
 * at its +0x38: the owner the lookup asks, its object at +0x30 the default */
struct Member05938c40_38 {
    u8 unknown0[0x30];
    Value00d48470 *unknown30;
};

struct Object05938c40 {
    u8 unknown0[0x38];
    Member05938c40_38 *unknown38;
};

extern Object05938c40 *D_5938c40;

/* derived name: asks the owner for the object a name names: nonzero with the
 * object stored through the second argument when it has one (the result
 * and the stored pointer are both tested at 0xd4854c) */
int FUN_00d44120(Member05938c40_38 *owner, Value00d48470 **object, const Name *name, int mode);

/* derived name: the object the name names: the name's own record when
 * this thread may use it, else the owner's answer, else the owner's
 * default (the thread may use the record: the plain test of 0x618b00, the
 * thread's flag read after the record's bit, `movzx; and 1; cmp 1`); the
 * answer's slot is the caller's (written on the first two
 * paths, `mov [rbp-0x38], r12` at 0xd4852c, `mov qword [rbp-0x38], 0` at
 * 0xd4853f) */
static inline Value00d48470 *findNamed(Member05938c40_38 *owner, Value00d48470 *&found,
                                       const Name &name)
{
    Value00d48470 *object = static_cast<Value00d48470 *>(D_17ac870[name.index].record18);
    if (object && ((object->flags16 & 4) || D_16dc098)) {
        found = object;
        return found;
    }
    found = 0;
    if (FUN_00d44120(owner, &found, &name, 0) && found)
        return found;
    return owner->unknown30;
}

/* derived name: the constructor: the base built from the name and the
 * reference empty, then the float and the pair (one 8-byte store after the
 * float's), and the reference set to the object the name
 * "game/textures/clut/treecolor" names. The creator FUN_00d48310 calls
 * it. */
Object016d22b8::Object016d22b8(const Name &name) : Object016b9108(name)
{
    unknown24 = 0.5f;
    unknown28 = Pair0057e850(0.5f, 1.0f);
    Value00d48470 *found;
    held30.set(findNamed(D_5938c40->unknown38, found, Name("game/textures/clut/treecolor")));
}
