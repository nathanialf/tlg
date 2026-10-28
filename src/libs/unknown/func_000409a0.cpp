/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the output kept with the data, or computed from the
 * pair's jacobian record and the two bodies' motions into the buffer. */
const Output0002b3b0 *hknpCharacterProxySignalData::FUN_000409a0(const hknpWorld *world,
                                                                 Output0002b3b0 *buffer) const
{
    if (output.numEntries != -1) {
        return &output;
    }
    const hknpMotion *motionA = &world->motions[world->bodyManager.bodies[bodyIdA].motionId];
    const hknpMotion *motionB = &world->motions[world->bodyManager.bodies[bodyIdB].motionId];
    FUN_00034920(jacobian->record(), &world->solverInfo, motionA, motionB, buffer);
    return buffer;
}
