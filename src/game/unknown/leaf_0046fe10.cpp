/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Soldier_SomeOne_HasMirrorShield"
 * (registered through FUN_00c89b70 at 0x22357a): pushes the boolean whether
 * the pointer at +0x148 of the record at +0x900 of the record at +0x38 of the
 * object at 0x57c9390 is set, and returns 1. The records' types are not
 * traced. */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x148];
    void *unknown148; /* +0x148 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: 9/13: the registers are the base's with the header's pushBoolean; left, the stack
// top's load, which the base has after the compare (`cmp qword [rax+0x148], 0; mov rcx,
// [rdi+0x48]`) and the build second. Measured (round 284A): the function is the base's when the
// pointer at +0x148 is declared `void *volatile`: the scheduler after register allocation takes
// the top's load at once unless it follows a barrier, and a compare whose memory reference is
// ordered is one (ScheduleDAGInstrs' BarrierChain, MachineInstr::hasOrderedMemoryRef); a
// volatile read still folds into the `cmp`, an atomic one does not. Not written: this is the
// field's only read in the executable, so nothing but this order says the program treats it as
// volatile (a ruling)
int FUN_0046fe10(lua_State *state) /* derived name */
{
    pushBoolean(state, D_57c9390->unknown38->unknown900->unknown148 != 0);
    return 1;
}
