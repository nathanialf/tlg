/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* derived names: the script C function "SoundGetParams" (FUN_00e7d5a0's
 * registration through FUN_00dd6ba0, lea at 0xe7db61): with two arguments or
 * more, their strings (FUN_00db6b20, null for an absent one) are passed to
 * slot 25 of the object at +0x100 of the object the pointer at 0x5938c40
 * holds; the string it answers is pushed (FUN_013aacc0 with its length) and
 * 1 returned, else 0 (no results). "SoundToolGetSoundFxName" (lea at
 * 0xe7dc7f, the same registration), FUN_00e7d450, does the same with the
 * first argument's string and the second's number as an int through slot 28.
 * The classes are not traced. */
class Sound00e7d320 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */
    virtual void slot20(); /* derived name; not traced */
    virtual void slot21(); /* derived name; not traced */
    virtual void slot22(); /* derived name; not traced */
    virtual void slot23(); /* derived name; not traced */
    virtual void slot24(); /* derived name; not traced */
    virtual const char *slot25(const char *first, const char *second); /* derived name */
    virtual void slot26();                                     /* derived name; not traced */
    virtual void slot27();                                     /* derived name; not traced */
    virtual const char *slot28(const char *first, int second); /* derived name */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Sound00e7d320 *unknown100; /* +0x100 */
};

extern Object05938c40 *D_5938c40;

const char *FUN_00db6b20(lua_State *state, const HksObject *value,
                         size_t *length); /* derived name */

/* derived name: an argument's string, null past the frame's top */
static inline const char *toString(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    return value < state->top ? FUN_00db6b20(state, value, 0) : 0;
}

int FUN_00e7d320(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count < 2) {
        return 0;
    }
    const char *first = toString(state, 1);
    const char *second = toString(state, 2);
    const char *result = D_5938c40->unknown100->slot25(first, second);
    if (result == 0) {
        return 0;
    }
    FUN_013aacc0(state, result, strlen(result));
    return 1;
}

int FUN_00e7d450(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count < 2) {
        return 0;
    }
    const char *first = toString(state, 1);
    int second = toNumber(state, 2);
    const char *result = D_5938c40->unknown100->slot28(first, second);
    if (result == 0) {
        return 0;
    }
    FUN_013aacc0(state, result, strlen(result));
    return 1;
}
