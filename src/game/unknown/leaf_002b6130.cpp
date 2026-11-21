/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks_string.h"
#include "tlg_lua_bindings.h"

/* derived names: the script C function "Ai2VolumeGetGridPositionByIndex"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x223706): reads its
 * first argument as an object through FUN_00c8c290 (as leaf_002c40a0.cpp's);
 * when it is of the type D_57cb398 points to (or one derived from it), reads
 * the second as a number (FUN_00c8d380), a grid index from 1; with a
 * positive index and the volume's +0x280 at 3, FUN_002b5dc0 gives the grid
 * position of the index less one and, when it answers 1, a table
 * { gridPosition = <the position> } is pushed and 1 returned; else 0. */
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

class Volume002b6130 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x25c];
    int unknown280; /* +0x280 */
};

extern Type00503fb0 *D_57cb398; /* derived name: the volume's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value);            /* derived name */
int FUN_002b5dc0(Volume002b6130 *volume, int index, Float4A *position);     /* derived name */

int FUN_002b6130(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_57cb398)) {
        Volume002b6130 *volume = static_cast<Volume002b6130 *>(object);
        float number = 0.0f;
        ArgumentReader00c8c290 second(state, 1);
        FUN_00c8d380(&second, &number);
        const int index = (int)number;
        Float4A position;
        if (index > 0 && volume->unknown280 == 3 &&
            FUN_002b5dc0(volume, index - 1, &position) == 1) {
            FUN_00d91880(state, 0, 0);
            pushString(state, "gridPosition");
            FUN_00c8aa70(state, &position);
            setTable(state);
            return 1;
        }
    }
    return 0;
}
