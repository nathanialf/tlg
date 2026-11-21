/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 (as leaf_008d6160.cpp's) */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

/* derived names: the script C function FUN_001db8b0 registers (lea at
 * 0x1ddfee) under the script name "MSDebugPrintDeletedObjectList" (its
 * description "MSDebugPrintDeletedObjectList()"): with an argument, the
 * Name of its string is made (and dropped: the list's print is not in the
 * retail executable); returns 0. The C function's own name is unknown. */
int FUN_008d6720(lua_State *state) /* derived name */
{
    if (argumentCount(state) != 0) {
        Name name = argumentName(state, 1);
    }
    return 0;
}

/* derived names: one of the three chain hanger gates of the object the
 * pointer at 0x5938c40 holds, 0x1c bytes from +0x1f8: its name and the two
 * ratios the script functions below set */
struct ChainHangerGate008d69a0 { /* derived name */
    Name name;
    u8 unknown4[0xc];
    float ratioFactor; /* +0x10: "MC_SetChainHangerGate_Ratio_Factor" */
    float ratioTarget; /* +0x14: "MC_SetChainHangerGate_Ratio_Target" */
    u8 unknown18[0x4];
};

/* derived names: the object the pointer at 0x581f4b8 holds
 * (leaf_008d7c30.cpp, leaf_008d5e20.cpp): its gates at +0x1f8 */
struct Object0581f4b8 { /* derived name */

    /* the gate a name names, -1 for none */
    int findGate(const Name &name) const /* derived name */
    {
        for (int i = 0; i < 3; ++i)
            if (gates[i].name == name)
                return i;
        return -1;
    }

    /* the name taken by value (its copy made before the gates are compared:
     * `lock inc` at 0x8d6a29) */
    void setRatioFactor(Name name, float value) /* derived name */
    {
        const int i = findGate(name);
        if (i >= 0)
            gates[i].ratioFactor = value;
    }

    void setRatioTarget(Name name, float value) /* derived name */
    {
        const int i = findGate(name);
        if (i >= 0)
            gates[i].ratioTarget = value;
    }

    u8 unknown0[0x1f8];
    ChainHangerGate008d69a0 gates[3]; /* +0x1f8 */
};

extern Object0581f4b8 *D_581f4b8;

/* derived names: the script C function FUN_001db8b0 registers (lea at
 * 0x1de038) under the script name "MC_SetChainHangerGate_Ratio_Factor" (its
 * description "MC_SetChainHangerGate_Ratio_Factor(name, value)"): the gate
 * the first argument's name names takes the second argument's number as its
 * factor; returns 0. The C function's own name is unknown. */
int FUN_008d69a0(lua_State *state) /* derived name */
{
    Name name = argumentName(state, 1);
    const float value = toNumber(state, 2);
    D_581f4b8->setRatioFactor(name, value);
    return 0;
}

/* derived names: "MC_SetChainHangerGate_Ratio_Target" (lea at 0x1de05d, its
 * description "MC_SetChainHangerGate_Ratio_Target(name, value)"): the same
 * for the gate's target */
int FUN_008d6ac0(lua_State *state) /* derived name */
{
    Name name = argumentName(state, 1);
    const float value = toNumber(state, 2);
    D_581f4b8->setRatioTarget(name, value);
    return 0;
}
