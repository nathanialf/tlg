/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the result of the script function "GuideSystem.checkDisp" for
 * the int at +0x74 (type 3) and the int at +0x19c of the record at 0x5938c40
 * (type 4): true when the call succeeds and its result is nonzero. Its
 * address is taken at 0xb14ecd, as FUN_00b10180's (leaf_00b10160.cpp) is
 * by its file's initializer; owner unknown. */
struct Object00b10da0 { /* derived name */
    u8 unknown0[0x74];
    int unknown74;
};

/* derived names: a script call's argument, 16 bytes: a 32-bit type code and
 * its value at +0x8 (the stores at rbp-0x30 and rbp-0x28). */
struct ScriptArgument00a2efa0 {
    int type;
    u8 unknown4[4];
    int value;
    u8 unknownc[4];
};

/* derived names: the record the pointer at 0x5938c40 holds. */
struct Object05938c40 {
    u8 unknown0[0x19c];
    int unknown19c;
};

extern Object05938c40 *D_5938c40;

/* derived names: calls the script function its name gives with count
 * arguments, its int result through the last pointer; nonzero on success. */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

// NONMATCHING: instruction order: the base sets the count (`mov esi, 2`) before the canary's
// copy and reads +0x74 into eax before the name goes straight into rdi; the build sets esi
// last and passes the name through rax; 6 of 33 before it
bool FUN_00b10da0(const Object00b10da0 *self) /* derived name */
{
    int result = 0;
    ScriptArgument00a2efa0 arguments[2];
    arguments[0].type = 3;
    arguments[0].value = self->unknown74;
    arguments[1].type = 4;
    arguments[1].value = D_5938c40->unknown19c;
    int ok = FUN_00a2efa0("GuideSystem.checkDisp", 2, arguments, &result);
    return ok != 0 && result != 0;
}
