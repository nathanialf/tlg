/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016a8430.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (leaf_002dc440.cpp's; type 2 a string) */
struct ScriptArgument00a2efa0 {
    void set(int type_, const char *string) /* derived name */
    {
        type = type_;
        value.string = string;
    }

    int type;
    u8 unknown4[4];

    union {
        const char *string;
        void *pointer;
    } value;
};

/* calls the script function its name gives with count arguments, its int
 * result through the last pointer; nonzero on success (FUN_00b10da0). */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: with the calling thread's heap (set on first use to the
 * table's first) replaced by the object's for the call, calls the script
 * function "Ai2.BeforeInterestTick" with the object's name (type 2) unless
 * its state at +0x90 is 1, then puts the thread's heap back. */
void Object016a8430::beforeInterestTick()
{
    ThreadHeapScope05943280 scope(heap);
    if (state != 1) {
        ScriptArgument00a2efa0 arguments[1];
        arguments[0].set(2, D_17ac870[name.index].string0);
        int result = 0;
        FUN_00a2efa0("Ai2.BeforeInterestTick", 1, arguments, &result);
    }
}
