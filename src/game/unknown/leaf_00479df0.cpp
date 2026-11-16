/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Soldier_DebugGetReferenceCount"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2235e8): reads
 * its first argument as an object through FUN_00c8c290 with a reader of the
 * frame (as leaf_0046bc50.cpp's) and pushes two numbers: the object's
 * reference count (0 for a released object, whose count is 0xdeadc0de) and
 * what FUN_00c8b2d0 counts of it in the state; 0 and 0 without an object.
 * Returns 2. The C function's own name is unknown. */
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

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
int FUN_00c8b2d0(lua_State *state, Object016b9108 *object);                 /* derived name */

int FUN_00479df0(lua_State *state) /* derived name */
{
    ArgumentReader00c8c290 reader(state);
    Object016b9108 *object = 0;
    FUN_00c8c290(&reader, &object);
    float scriptReferences = 0.0f;
    float references = 0.0f;
    if (object) {
        const int count = object->references;
        const int inScript = FUN_00c8b2d0(state, object);
        references = count != int(0xdeadc0de) ? float(count) : 0.0f;
        scriptReferences = float(inScript);
    }
    pushNumber(state, references);
    pushNumber(state, scriptReferences);
    return 2;
}
