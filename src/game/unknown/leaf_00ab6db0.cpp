/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2MovePath" (FUN_002212a0 registers
 * it through FUN_00c89b70): reads its first argument as an object and its
 * second as another through FUN_00c8c290 (as leaf_0031d9a0.cpp's); when the
 * first is of the type D_5829020 points to (or one derived from it) and the
 * second of the type D_57dad78 points to (a path), reads the third as a
 * number with the second's reader (FUN_00c8d380; nothing set when absent),
 * points the path's pair at +0x258 at the first object's +0x320 and the
 * pointer at its +0x430, hands the path to FUN_0051afa0 with 0, 0 and the
 * number, clears the pair and returns 1; 0 otherwise. */
struct ArgumentReader00c8c290 { /* derived name */

    /* a reader at an argument of the frame (0 the first), its index taken
     * from the top: the argument less the count of arguments */
    explicit ArgumentReader00c8c290(lua_State *state_, int argument = 0)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = argument - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                                 sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

/* derived name: an object of D_5829020's type (leaf_002c40a0.cpp) */
class Object00ab6db0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x2fc];
    u8 unknown320[0x110]; /* +0x320: its address is handed to the path */
    void *unknown430;     /* +0x430 */
};

/* derived name: an object of D_57dad78's type, a path (leaf_0031d9a0.cpp) */
class Path00ab6db0 : public Object016b9108 /* derived name */
{
  public:
    /* the pair at +0x258, cleared again after the call */
    void setTarget(void *first, void *second) /* derived name */
    {
        unknown258 = first;
        unknown260 = second;
    }

    u8 unknown24[0x234];
    void *unknown258; /* +0x258 */
    void *unknown260; /* +0x260 */
};

extern Type00503fb0 *D_5829020; /* derived name: the object's type */
extern Type00503fb0 *D_57dad78; /* derived name: the path's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object);     /* derived name */
void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value);                /* derived name */
void FUN_0051afa0(Path00ab6db0 *path, int unknown1, int unknown2, float value); /* derived name */

int FUN_00ab6db0(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    Object016b9108 *other = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    ArgumentReader00c8c290 second(state, 1);
    FUN_00c8c290(&second, &other);
    if (object && object->isKindOf(D_5829020) && other && other->isKindOf(D_57dad78)) {
        Object00ab6db0 *mover = static_cast<Object00ab6db0 *>(object);
        Path00ab6db0 *path = static_cast<Path00ab6db0 *>(other);
        float value;
        FUN_00c8d380(&second, &value);
        path->setTarget(mover->unknown320, mover->unknown430);
        FUN_0051afa0(path, 0, 0, value);
        path->setTarget(0, 0);
        return 1;
    }
    return 0;
}
