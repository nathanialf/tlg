/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 144 of 148, size equal: in each of the two posts the base
// takes the event's address (`lea rsi, [rbp-0x70]`) right after the header's
// first store, here after its second: the pre-RA list-ilp scheduler (a78/
// llvm33dbg llc, -debug-only=pre-RA-sched) has the LEA (height 3) and the
// MOV8mi of the header's byte at +2 (height 19) available at GR64 7/12 and
// takes the LEA first bottom-up (ilp_ls_rr_sort's register pressure rule:
// the LEA ends a live range); NOTES "Round 78A".
void Modifier16a4fa0::FUN_00161cc0(CommandOwner00171180 *context,
                                   const SolverCallbackInput001623a0 *input,
                                   const Vec4 *contactImpulses, float frictionFactor) const
{
    hknpManifoldCollisionCache *cache = input->collisionCache;
    const int numPoints = FUN_000348c0(input->record);
    const u32 bodyIdA = FUN_00010650(input->record);
    const u32 bodyIdB = FUN_00034840(input->record);
    if (FUN_00034890(input->record)) {
        return;
    }
    const int pointMask = (1 << numPoints) - 1;
    const int pushing =
        _mm_movemask_ps(_mm_cmplt_ps(_mm_setzero_ps(), *contactImpulses)) & pointMask;
    if (cache) {
        const u16 flags = cache->flags22;
        const bool wasPushing = (flags & 1) != 0;
        const u16 newFlags = pushing ? (flags | 1) : (flags & ~1);
        cache->flags22 = newFlags;
        const int change = wasPushing * 2 + (pushing != 0);
        switch (change) {
        case 0:
            return;
        case 1:
            cache->flags22 = newFlags & ~6;
            break;
        case 2:
            if (!(newFlags & 4)) {
                return;
            }
            break;
        case 3:
            if (!(newFlags & 2)) {
                return;
            }
            break;
        }
        const hknpBody *bodies = context->bodyView->bodies;
        BodyPairEvent00161f10 event(bodies[bodyIdA].byte7f, bodies[bodyIdA].id,
                                    bodies[bodyIdB].byte7f, bodies[bodyIdB].id);
        event.record = input->record;
        event.status = u8(change);
        event.frictionFactor = frictionFactor;
        event.impulses = *contactImpulses;
        context->dispatcher->exec(event);
    } else if (pushing) {
        const hknpBody *bodies = context->bodyView->bodies;
        BodyPairEvent00161f10 event(bodies[bodyIdA].byte7f, bodies[bodyIdA].id,
                                    bodies[bodyIdB].byte7f, bodies[bodyIdB].id);
        event.record = input->record;
        event.status = 4;
        event.frictionFactor = frictionFactor;
        event.impulses = *contactImpulses;
        context->dispatcher->exec(event);
    }
}

void Modifier16a4fa0::FUN_00161f10(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   const hknpManifoldCollisionCache *cache) const
{
    if ((cache->flags22 & 5) == 5) {
        BodyPairEvent00161f10 event(cdBodyA->body->byte7f, cdBodyA->body->id, cdBodyB->body->byte7f,
                                    cdBodyB->body->id);
        context->dispatcher->exec(event);
    }
}
