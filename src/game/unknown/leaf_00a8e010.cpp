/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9ba8.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (leaf_00471ae0.cpp's; type 2 a string) */
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
    } value;
};

/* calls the script function its name gives with count arguments, its int
 * result through the last pointer; nonzero on success (FUN_00b10da0). */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: slot 19 of the vtable at 0x16a9ba8 (and of 0x16b2930's):
 * unless the int at +0x90 is 1, the script function "Ai2.BeforeInterestTick"
 * with the object's name's string (type 2) */
void Object016a9ba8::beforeInterestTick()
{
    if (unknown90 == 1)
        return;
    ScriptArgument00a2efa0 arguments[1];
    arguments[0].set(2, D_17ac870[name.index].string0);
    int result = 0;
    FUN_00a2efa0("Ai2.BeforeInterestTick", 1, arguments, &result);
}

/* derived names: slot 24 of the vtable at 0x16a9ba8 (and of 0x16b2930's):
 * whether the holder's first entry is of kind 36 to 38 into +0x1b0, of
 * kind 1 into +0x1b8 (both 0 without a holder), whether +0x1b0 was set
 * before and is not now into +0x1b4, then slot 28 */
// NONMATCHING: the store to +0x1b4: the build folds the test of the new
// +0x1b0 into its phi (`mov cl, 1` before the holder's test), the base keeps
// the phi of the value (`xor edx, edx` first) and tests it at the end
// (`test edx, edx; sete cl; test eax, eax; jne`); both spellings of the &&
// compile the same
void Object016a9ba8::slot24(const Source00a8fd10 *source)
{
    const int was = unknown1b0;
    unknown1b0 = 0;
    unknown1b8 = 0;
    if (const Holder00a8fd10 *holder = source->holder) {
        const Entry00a8fd10 *entry = holder->first();
        unknown1b0 = entry && entry->kind >= 36 && entry->kind <= 38;
        entry = holder->first();
        unknown1b8 = entry && entry->kind == 1;
    }
    unknown1b4 = !unknown1b0 && was;
    slot28();
}
