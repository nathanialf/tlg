/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_creation.h"
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "CharacterUpdateProxyEventSubscribe"
 * ("update the character proxy event subscribe"; FUN_001c4670's
 * registration, lea at 0x1c4707): reads its first argument as an object
 * through FUN_00c8c290 with a reader of the frame (as leaf_0046bc50.cpp's)
 * and, when it is of the type D_5814e08 points to (or one derived from it),
 * hands it to FUN_00712b60; returns 0 (no results). The C function's own
 * name is unknown. */
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

/* derived names: the part of a character FUN_01366b90 empties (+0x5a90:
 * an int, two exchanged references and a name; leaf_01366b90.cpp's) */
struct Object01366b90 { /* derived name */
    u8 unknown0[0x20];
    int unknown20;                               /* +0x20 */
    AtomicRef0045c470<Object016b9108> unknown28; /* +0x28 */
    AtomicRef0045c470<Object016b9108> unknown30; /* +0x30 */
    Name unknown38;                              /* +0x38 */
};

/* derived names: the part of a character FUN_01367790 empties (+0x5ad0:
 * an int and two exchanged references; leaf_01367790.cpp's) */
struct Object01367790 { /* derived name */
    u8 unknown0[0x70];
    int unknown70; /* +0x70 */
    u8 unknown74[0x4];
    AtomicRef0045c470<Object016b9108> unknown78; /* +0x78 */
    AtomicRef0045c470<Object016b9108> unknown80; /* +0x80 */
};

/* derived names: the character: a lock at +0xad0 (the creation lock's
 * kind, tlg_game_creation.h) taken around the two parts' emptying; the
 * rest is not traced */
class Character007d8be0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0xaac];
    Lock059458a4 lock; /* +0xad0 */
    u8 unknownad4[0x4fbc];
    Object01366b90 unknown5a90; /* +0x5a90 */
    Object01367790 unknown5ad0; /* +0x5ad0 */
};

extern Type00503fb0 *D_5814e08; /* derived name: the character's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00712b60(Character007d8be0 *character);                            /* derived name */
void FUN_01366b90(Object01366b90 *part);                                    /* derived name */
void FUN_01367790(Object01367790 *part);                                    /* derived name */
void FUN_00b06100(Character007d8be0 *character);                            /* derived name */

// NONMATCHING: the second type walk (the cast's): the base enters it past the type itself, the
// type's own compare threaded away, and keeps "not found" in dl (`mov dl, 1` in the loop, `cmovne
// rdi, 0`); this build compares the type again at 0x7f and keeps "found" in cl (`cmovne rdi, rax`);
// 19/59 equal. Byte-identical copies: 0xa08af0, 0xcf2930, 0xcf29f0 (RBSnooper_Suspend, _Resume).
int FUN_007d8be0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5814e08))
        FUN_00712b60(object->isKindOf(D_5814e08) ? static_cast<Character007d8be0 *>(object) : 0);
    return 0;
}

/* derived names: the script C functions "CharacterResetProxyCaptureTarget"
 * ("reset the character proxy capture target", FUN_007d6930) and
 * "CharacterResetProxyAttachOwner" ("reset the character proxy attach
 * owner", FUN_007d6f50), FUN_001c4670's registrations (lea at 0x1c45c9 and
 * 0x1c4603), of the same reader: when the first argument is a character
 * (the type D_5814e08 points to, or one derived from it), its part at
 * +0x5ad0 (+0x5a90) is emptied under the character's lock, its int cleared
 * first by the caller as by FUN_01367790 (FUN_01366b90) itself, then the
 * character handed to FUN_00b06100; returns 1, else 0. The C functions' own
 * names are unknown. */
// NONMATCHING: FUN_007d8be0's class, the cast walk's flag polarity: the base
// keeps "not found" in dl and enters the second walk past the type itself
// (`cmovne r14, rax` with rax 0); this build keeps "found" in al, compares the
// type again (`cmove r14, rcx`); 28/123, the same 497 bytes. The same in
// FUN_007d6f50.
int FUN_007d6930(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5814e08)) {
        Character007d8be0 *character =
            object->isKindOf(D_5814e08) ? static_cast<Character007d8be0 *>(object) : 0;
        character->lock.lock();
        character->unknown5ad0.unknown70 = 0;
        FUN_01367790(&character->unknown5ad0);
        FUN_00b06100(character);
        character->lock.unlock();
        return 1;
    }
    return 0;
}

int FUN_007d6f50(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5814e08)) {
        Character007d8be0 *character =
            object->isKindOf(D_5814e08) ? static_cast<Character007d8be0 *>(object) : 0;
        character->lock.lock();
        character->unknown5a90.unknown20 = 0;
        FUN_01366b90(&character->unknown5a90);
        FUN_00b06100(character);
        character->lock.unlock();
        return 1;
    }
    return 0;
}
