/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016a9ba8.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (leaf_002dc440.cpp's: a pointer, the object
 * itself and a float) */
struct ScriptArgument00a2efa0 {
    void set(int type_, void *pointer) /* derived name */
    {
        type = type_;
        value.pointer = pointer;
    }

    void set(int type_, float number) /* derived name */
    {
        type = type_;
        value.number = number;
    }

    int type;
    u8 unknown4[4];

    union {
        void *pointer;
        float number;
    } value;
};

/* calls the script function its name gives with count arguments, its int
 * result through the last pointer; nonzero on success (FUN_00b10da0). */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: slot 29 with the step, then the script function
 * "Ai2.CallPhysicsBgTick" with the pointer at +0x28 and the object (both
 * type 1) and the step (type 4), as FUN_00403530 of the class at 0x16a96d0
 * without its heap. */
void Object016a9ba8::callPhysicsBgTick(float step)
{
    slot29(step);
    ScriptArgument00a2efa0 arguments[3];
    arguments[0].set(1, unknown28);
    arguments[1].set(1, this);
    arguments[2].set(4, step);
    int result = 0;
    FUN_00a2efa0("Ai2.CallPhysicsBgTick", 3, arguments, &result);
}
