/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: a mission's procedure, an object of the type D_581f8c0
 * points to, found by its name; it runs its script's functions by the names
 * it holds (+0x48 to +0x54) through FUN_008ee400 while its script at +0x28
 * is ready (bit 0 at +0x24). The four names are those of the script C
 * functions FUN_001db8b0 registers (lea at 0x1dde57 to 0x1ddec6) under the
 * script names "MissionProc_Restart", "MissionProc_Enter", "MissionProc_Action"
 * and "MissionProc_Leave" (their descriptions "MissionProc_Restart(state)"
 * and so on), which run the one each names. The classes are not traced. */
struct Script008e0cb0 { /* derived name */
    u8 unknown0[0x24];
    u8 flags24; /* +0x24: bit 0, ready */
};

struct MissionProc008e0cb0 : Object016b9108 /* derived name */
{
    u8 unknown24[4];
    Script008e0cb0 *script; /* +0x28 */
    u8 unknown30[4];
    int state34; /* +0x34 */
    u8 unknown38[8];
    int unknown40; /* +0x40: the action runs only while it is 0 */
    u8 unknown44[4];
    Name restart; /* +0x48 */
    Name enter;   /* +0x4c */
    Name action;  /* +0x50 */
    Name leave;   /* +0x54 */
    u8 unknown58[4];
    int acted5c; /* +0x5c: set to 1 once its action ran */
};

extern const Type00503fb0 *D_581f8c0; /* derived name: the procedure's type */

/* derived name: runs the script function of a name on the object (the three
 * ints not traced) */
void FUN_008ee400(MissionProc008e0cb0 *proc, const char *function, int unknown1, int unknown2,
                  int unknown3);

/* derived name: the procedure's script is ready */
static inline bool isReady(const MissionProc008e0cb0 *proc)
{
    return proc->script && (proc->script->flags24 & 1);
}

/* derived name: the procedure the name names runs its restart function */
void FUN_008e0cb0(const Name &name) /* derived name */
{
    MissionProc008e0cb0 *proc = findNamed<MissionProc008e0cb0>(name, D_581f8c0);
    if (proc && isReady(proc) && proc->restart.index != 0)
        FUN_008ee400(proc, D_17ac870[proc->restart.index].string0, 1, 0, 0);
}

/* derived name: the procedure the name names, in the state 1, runs its enter
 * function; returns whether it ran */
// NONMATCHING: the result: the base keeps it in r14 from the entry (`xor r14d, r14d`), sets it to 1
// before the call and to the name's test (`setne cl`) on the path without one; the build folds
// every path's value to a constant (`xor eax, eax` in each exit, `mov al, 1` after the call)
bool FUN_008e0d70(const Name &name) /* derived name */
{
    MissionProc008e0cb0 *proc = findNamed<MissionProc008e0cb0>(name, D_581f8c0);
    bool ran = proc && proc->state34 == 1 && isReady(proc) && proc->enter.index != 0;
    if (ran)
        FUN_008ee400(proc, D_17ac870[proc->enter.index].string0, 1, 0, 0);
    return ran;
}

/* derived name: the procedure the name names runs its action function and
 * marks it run */
void FUN_008e0e60(const Name &name) /* derived name */
{
    MissionProc008e0cb0 *proc = findNamed<MissionProc008e0cb0>(name, D_581f8c0);
    if (proc && proc->unknown40 == 0 && isReady(proc) && proc->action.index != 0) {
        FUN_008ee400(proc, D_17ac870[proc->action.index].string0, 1, 1, 0);
        proc->acted5c = 1;
    }
}

/* derived name: the same with the third int 1, not marked */
void FUN_008e0f40(const Name &name) /* derived name */
{
    MissionProc008e0cb0 *proc = findNamed<MissionProc008e0cb0>(name, D_581f8c0);
    if (proc && proc->unknown40 == 0 && isReady(proc) && proc->action.index != 0)
        FUN_008ee400(proc, D_17ac870[proc->action.index].string0, 1, 1, 1);
}

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

int FUN_008d5820(lua_State *state) /* derived name: "MissionProc_Restart" */
{
    FUN_008e0cb0(argumentName(state, 1));
    return 0;
}

int FUN_008d5970(lua_State *state) /* derived name: "MissionProc_Enter" */
{
    FUN_008e0d70(argumentName(state, 1));
    return 0;
}

int FUN_008d5ad0(lua_State *state) /* derived name: "MissionProc_Action" */
{
    FUN_008e0e60(argumentName(state, 1));
    return 0;
}

int FUN_008d5c40(lua_State *state) /* derived name: "MissionProc_Leave" */
{
    Name name = argumentName(state, 1);
    MissionProc008e0cb0 *proc = findNamed<MissionProc008e0cb0>(name, D_581f8c0);
    if (proc && proc->leave.index != 0)
        FUN_008ee400(proc, D_17ac870[proc->leave.index].string0, 1, 0, 0);
    return 0;
}
