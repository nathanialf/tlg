/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the task's name for the dumps, its timer's (by the int at
 * +0x18), in the first state's fill colour. The interface's thunk of it
 * (0x155150, slot 6 of the second vtable) is emitted beside it with the body
 * inlined. */
void hknpBuildConstraintsTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    FUN_000116c0(name, unknown18 ? "Build Activated Constraints" : "Constraints/Build Active");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(0));
    }
}

/* NONMATCHING: 82 of 167, size equal, every instruction but the registers:
 * greedy keeps the context in r15 across the sub-task loop (copied to r10 at
 * its end) and spills the groups at -0x40 at their load, `this` in rbx; here
 * the groups stay in rbx and the context is spilled, `this` in r15. The
 * select of the element (`jne; xor`) took the base's form once the element
 * is passed as itself (0x77250's form). */
/* Slot 5: the constraints' groups taken one at a time, each group's
 * jacobians built into the context's element under its own timer, its
 * constraint count recorded as a monitor value. The interface's thunk
 * (0x155420, a jump) is emitted with it. */
void hknpBuildConstraintsTask::process()
{
    const ConstraintGroups000c6630 *groups = static_cast<ConstraintGroups000c6630 *>(unknown30);
    if (groups->groups.getSize() == 0 || unknown38 >= groups->groups.getSize()) {
        return;
    }
    ConstraintSetup00150330 *setup = static_cast<ConstraintSetup00150330 *>(unknown20);
    Elements000760c0 *elements = setup->elements;
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBegin("TtBuildConstraintJacobians");
    hknpWorldContextPool *pool = static_cast<hknpWorldContextPool *>(unknown28);
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    Elements000760c0::Element &element = elements->elements[context->index];
    hknpWorld *world = context->world;
    hknpConstraint *constraints = world->constraintManager.constraints;
    for (int i = __sync_fetch_and_add(&unknown38, 1); i < groups->groups.getSize();
         i = __sync_fetch_and_add(&unknown38, 1)) {
        stream.timerBegin("TtSubTask");
        const ConstraintGroups000c6630::Group &group = groups->groups[i];
        FUN_000c5340(context, world, constraints, &setup->gather, group.first, group.last,
                     &elements->array30, &element.slots[3], &element.slots[4],
                     context->world->enabled4f0 ? &element : HK_NULL);
        stream.timerEnd("Et");
        /* The count read once the command is named (0x154f50's form). */
        if (stream.end < stream.capacityMinus16) {
            ThreadBuffer::AddValueCommand *command =
                reinterpret_cast<ThreadBuffer::AddValueCommand *>(stream.end);
            command->commandAndMonitor = "MiNumConstraints";
            command->value = float(group.last + 1 - group.first);
            stream.end = reinterpret_cast<char *>(command + 1);
        }
    }
    stream.timerEnd("Et");
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
