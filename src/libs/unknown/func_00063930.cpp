/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 25 of 38 instructions, 120 bytes against 118; the record
// reaches the array as one 8-byte store (`shl r14, 32; or r14, r15; mov
// [rcx+rax*8], r14`) where the base stores its two fields apart: the base
// copies the record member by member (a throwaway with a user-written copy
// constructor on the record gives the base's bytes exactly), which no
// recovered type explains yet (docs/NOTES.md Round 46).
void hknpWorldObject4f8::FUN_00063930(int bodyId) /* derived name */
{
    const hknpBody &body = world->bodyManager.bodies[bodyId];
    if (body.flags & 8) {
        BodyRecord record;
        record.bodyId = body.id;
        record.byte7f = body.byte7f;
        bodyRecords.pushBack(record);
    }
}
