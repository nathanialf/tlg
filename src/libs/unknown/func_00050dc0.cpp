/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The solve tasks built into the arrays under the timer "BuildSolveTasks":
 * the arrays given room; with an argument (a simulation of kind 1 only) the
 * pre-solve task added after the collide stage's last entry, else its stage
 * run here; the object at +0x1d0 adding the solver's tasks; then the
 * post-solve task after them when there are any, else its stage run here.
 * derived name. */
// NONMATCHING: round 72A's class (NOTES "Round 72A", 0x50480): the two tasks' null-checked
// conversions to their interface (0x50e60, 0x50f2c) are selects here (SimplifyCFG's
// FoldTwoEntryPHINode once InstCombine makes the cast a struct GEP; CodeGenPrepare turns a
// select back into a branch only when the compare's load has one use) and cmovs in the
// output; the base keeps both branches. The entry index's store follows the select's
// schedule. Every other instruction is the base's.
void hknpWorld::FUN_00050dc0(RefArrays1698f80 &arrays, void *argument)
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBegin("TtBuildSolveTasks");
    if (object1d0->simulationType != 1) {
        argument = HK_NULL;
    }
    arrays.FUN_00092510(32, 32);
    if (argument) {
        preSolveTask->world = this;
        preSolveTask->unknown20 = object1d0;
        const RefArrays::EntryId preSolve = arrays.FUN_000922f0(preSolveTask, 1, 0);
        arrays.entry5a = preSolve.value;
        arrays.addDependency(arrays.entry58, preSolve.value);
    } else {
        FUN_000509f0();
        arrays.entry5a = 0xffff;
    }
    object1d0->unknownVirtual3(contextPool, &arrays, argument);
    if (arrays.array10.getSize() || arrays.array20.getSize()) {
        postSolveTask->world = this;
        postSolveTask->unknown20 = object1d0;
        const RefArrays::EntryId postSolve = arrays.FUN_000922f0(postSolveTask, 1, 0);
        arrays.entry5e = postSolve.value;
        arrays.addDependency(arrays.entry5c, postSolve.value);
    } else {
        FUN_00050fd0();
    }
    stream.timerEnd("EtBuildSolveTasks");
}
