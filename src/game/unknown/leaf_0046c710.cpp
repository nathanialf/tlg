/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks_string.h"

/* derived names: the script C function "SoldierMission_GetSoldierSaveData"
 * (FUN_002212a0 registers it through FUN_00c89b70): reads its first
 * argument as a name (nameArgument), asks FUN_004bc7c0 for the saved state
 * of the soldier of that name (a value of the four-entry table of names at
 * 0x57d8730, func_004bc940.cpp), and pushes the state's name (the table's
 * first name for a state without one) and three booleans: whether the state
 * is one of 1 to 3, and two flags of the state (1: true, false; 2 and 3:
 * false, true; any other: true, false). Returns 4. */

/* a value and its name, 8 bytes (func_004bc940.cpp) */
struct Valued004bc940 { /* derived name */
    int value;          /* +0x0 */
    Name name;          /* +0x4 */
};

extern Valued004bc940 D_57d8730[4];
extern const Name D_57d8750; /* derived name: the name of a state outside the table */

/* derived name: the saved state of the soldier a name names, the name
 * passed by its index */
int FUN_004bc7c0(unsigned name);

/* derived name: Lua's lua_pushboolean by its argument, an int stored as it
 * is (tag 1): the values pushed here are 0 or 1 already (`mov [rax+8], r15d`
 * from the state's tables, no `setne`) */
static inline void pushBooleanInt(lua_State *state, int b)
{
    HksObject *top = state->top;
    top->value.boolean = b;
    top->type = 1;
    state->top = top + 1;
}

// NONMATCHING: the state's name: the base loads the index once and branches on it (`mov eax,
// [rdx]; test rax, rax; jne`, the table's first index loaded on the other arm), the build keeps
// a select (`test eax, eax; cmove eax, [rip]`: the load has two uses, so CodeGenPrepare keeps
// the cmov); the name chosen by reference gives a branch on `cmp dword [rcx], 0` and a second
// load. The rest is the base's
int FUN_0046c710(lua_State *state) /* derived name */
{
    const Name name = nameArgument(state, 1);
    const int saved = FUN_004bc7c0(name.index);
    int second = 0;
    int first = 1;
    int known = 0;
    switch (saved) {
    case 1:
        known = 1;
        first = 1;
        second = 0;
        break;
    case 2:
        known = 1;
        first = 0;
        second = 1;
        break;
    case 3:
        known = 1;
        first = 0;
        second = 1;
        break;
    }
    const Name &stateName = saved < 0 || saved > 3 ? D_57d8750 : D_57d8730[saved].name;
    unsigned shown = stateName.index;
    if (shown == 0)
        shown = D_57d8730[0].name.index;
    const NameTableEntry017ac870 &entry = D_17ac870[shown];
    FUN_013aacc0(state, entry.string0, entry.length14);
    pushBooleanInt(state, known);
    pushBooleanInt(state, first);
    pushBooleanInt(state, second);
    return 4;
}
