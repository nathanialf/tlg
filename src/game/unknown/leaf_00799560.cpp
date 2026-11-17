/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad7a0.h"

/* derived names: FUN_00755d60 and FUN_007563b0, not traced: the body's part
 * at +0x4f80 and its tracker at +0x4fe0 given the record found, the turn
 * and the point (FUN_00755d60 also the first link's value at +0x120, as its
 * fifth and its last argument) */
void FUN_00755d60(Part00799560 *part, TrackerC00799560 *tracker, int index, Record00799560 *record,
                  const Float4A &offset, const Float4A &turn, const Float4A &point,
                  const Float4A &offset2); /* derived name */
void FUN_007563b0(Part00799560 *part, TrackerC00799560 *tracker, const Float4A &turn,
                  const Float4A &point); /* derived name */

/* derived name: a record matches a link that holds its object and its
 * value (the object compared first: `cmp [rbx+rsi+0x78], rdx; jne`, then
 * `cmp [rbx+rsi+0x80], rcx`) */
inline bool operator==(const Record00799560 &record, const Link0079ab40 &link)
{
    return record.object == link.held8.get() && record.value == link.unknown0;
}

/* derived names: slot 17 of the vtable at 0x16ad7a0: the record of the
 * body's part at +0x4f80 that holds the first link's object and value is
 * handed, with the context's rotation turned by the body's and the
 * context's point moved by the body's (the body read again), to
 * FUN_00755d60 and then FUN_007563b0; the int at +0x170 goes to the body's
 * tracker at +0x4fe0, which is cleared when the link's object has a zero
 * at +0x58 */
// NONMATCHING: (1) the address of the link's object (`lea r12, [r15+0x108]`)
// is kept in a register from the search to the clear at the end, where the
// base reads `[r13+0x108]` again and keeps the addresses of the body's part
// and tracker (r8, r9) instead; with Array05943280::find the frame is 0x58
// against 0x48, with the search written out 0x48 but the value at +0x100 read
// in the loop. (2) The tracker's four zero floats at +0x50 are one aligned
// store (`vmovaps`) where the base's is `vmovups`. 559 bytes against 552.
void Object016ad7a0::slot17(Context0079c700 *context)
{
    Body0077bac0 *body = unknown68;
    const Link0079ab40 &link = link100;
    int index = -1;
    for (unsigned i = 0; i < body->part4f80.records.size(); ++i) {
        const Record00799560 &record = body->part4f80.records.at(i);
        if (record.object == link.held8.get() && record.value == link.unknown0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Record00799560 &record = body->part4f80.records.at(index);
        const Float4A turn = FUN_013439c0(context->rotationd0, body->rotation);
        const Float4A point = context->pointe0 + Vector0077bac0(unknown68->position);
        FUN_00755d60(&body->part4f80, &body->trackerC, index, &record, link100.unknown20, turn,
                     point, link100.unknown20);
        FUN_007563b0(&body->part4f80, &body->trackerC, turn, point);
    }
    body->trackerC.unknown68 = unknown170;
    if (link100.held8.get() && link100.held8.get()->unknown58 == 0)
        body->trackerC.reset();
}
