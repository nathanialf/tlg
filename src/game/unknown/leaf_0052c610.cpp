/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_record0052d2f0.h"

/* derived names: the object FUN_005f3590 hands over, as far as the array of
 * records at +0x4de8 */
struct Owner0052c610 { /* derived name */
    u8 unknown0[0x4de8];
    Array05943280<Record0052d2f0> records; /* +0x4de8 */
};

/* derived names: a record of the two names appended to the owner's records */
// NONMATCHING: the link inlines the append (Array05943280<Record0052d2f0>::push, FUN_0052d2f0) and
// the record is promoted (module 4/108, 400 bytes against 255), where the base keeps the record on the frame
// (zeroed in 16 bytes, the names assigned) and calls FUN_0052d2f0 at both of its threaded sites: open
// The base keeps the second name's index in ebx across the append and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
void FUN_0052c610(Owner0052c610 *owner, const Name &first, const Name &second) /* derived name */
{
    Record0052d2f0 record;
    record.name0 = first;
    record.name4 = second;
    owner->records.push(record);
}
