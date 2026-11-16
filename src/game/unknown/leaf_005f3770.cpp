/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "AnimationSetupDelegates"
 * (FUN_001bd010 registers it, lea at 0x1c457b): reads its first argument
 * as an object through FUN_00c8c290 with a reader of the frame (as
 * leaf_0046bc50.cpp's); when it is of the type D_57db090 points to (or one
 * derived from it) calls its slot 12; returns 0 (no results). The C
 * function's own name is unknown. */
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

/* derived names: an object of that type: slots 5 to 12 after the root
 * class's; slot 12 takes no argument, the others are not traced */
class Object005f3770 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
};

extern Type00503fb0 *D_57db090; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

int FUN_005f3770(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57db090))
        static_cast<Object005f3770 *>(object)->slot12();
    return 0;
}
