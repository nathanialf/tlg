/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_vector.h"
#include "tlg_hks.h"
#include "tlg_math.h"

/* derived names: FUN_00ab26d0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15a8ded[11];
extern const char D_15a8e19[11];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_582aa10(D_15cb5dd, false);
Name D_582aa14(D_15cb5e6, false);
Name D_582aa18(D_15ca420, false);
Name D_582a7dc(D_15a8e19, false);
Name D_582a7e0(D_15a8ded, false);

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

/* derived names: an object of D_582a300's type (leaf_00aac4b0.cpp) and the
 * object at its +0x28 */
struct Target00ab1a60; /* derived name */

class Interest00ab1a60 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x4];
    Target00ab1a60 *unknown28; /* +0x28 */
};

/* derived name: an object of D_5829dd0's type: a locator */
class Locator00ab1a60 : public Object016b9108 /* derived name */
{
};

extern Type00503fb0 *D_5829020; /* derived name: the AI's type (leaf_00aaef50.cpp) */
extern Type00503fb0 *D_582a300; /* derived name: the interest's type */
extern Type00503fb0 *D_5829dd0; /* derived name: the locator's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00a9a240(Locator00ab1a60 *locator, Target00ab1a60 *target, Float4A *position,
                  Float4 *rotation);                                  /* derived name */
void FUN_00a9a090(Locator00ab1a60 *locator, Locator00ab1a60 *parent); /* derived name */
void FUN_00c57c10(Locator00ab1a60 *locator, const Float4A *position); /* derived name */
void FUN_00c57f00(Locator00ab1a60 *locator, const Float4 *rotation);  /* derived name */

/* derived names: the script C function "Ai2UpdateInterestLocator": its
 * arguments are an AI (D_5829020's type), an interest (D_582a300's) and two
 * locators (D_5829dd0's); each is read through FUN_00c8c290 and tested in
 * turn, 0 returned at the first that is missing or of another type. The
 * first locator's position and rotation are computed by FUN_00a9a240 from
 * the interest's target at +0x28 (from zero and this file's VECTOR_W); the
 * second is attached to it (FUN_00a9a090) and given them (FUN_00c57c10,
 * FUN_00c57f00). Pushes the number 1 and returns 1. */
int FUN_00ab1a60(lua_State *state) /* derived name */
{
    Object016b9108 *ai = 0;
    ArgumentReader00c8c290 first(state);
    FUN_00c8c290(&first, &ai);
    if (!ai || !ai->isKindOf(D_5829020))
        return 0;
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 second(state, 1);
    FUN_00c8c290(&second, &object);
    if (!object || !object->isKindOf(D_582a300))
        return 0;
    Interest00ab1a60 *interest = static_cast<Interest00ab1a60 *>(object);
    Object016b9108 *locator = 0;
    ArgumentReader00c8c290 third(state, 2);
    FUN_00c8c290(&third, &locator);
    if (!locator || !locator->isKindOf(D_5829dd0))
        return 0;
    Locator00ab1a60 *parent = static_cast<Locator00ab1a60 *>(locator);
    Object016b9108 *child = 0;
    ArgumentReader00c8c290 fourth(state, 3);
    FUN_00c8c290(&fourth, &child);
    if (!child || !child->isKindOf(D_5829dd0))
        return 0;
    Locator00ab1a60 *attached = static_cast<Locator00ab1a60 *>(child);
    Float4A position(0.0f, 0.0f, 0.0f, 0.0f);
    const Float4Data unit = reinterpret_cast<const Float4Data &>(VECTOR_W);
    Float4 rotation = unit;
    FUN_00a9a240(parent, interest->unknown28, &position, &rotation);
    FUN_00a9a090(attached, parent);
    FUN_00c57c10(attached, &position);
    FUN_00c57f00(attached, &rotation);
    pushNumber(state, 1.0f);
    return 1;
}
