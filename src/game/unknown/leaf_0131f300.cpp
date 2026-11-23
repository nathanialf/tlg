/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_game_object01499f30.h"

/* derived names: the counts the block of the kinds 1 and 5 holds: eight
 * pairs of 64-bit counts, one taken at the start and one at the end */
struct Counts01499f30 { /* derived name */
    u64 begin;
    u64 end;
};

/* derived names: what the kind 3 writes: the counter's frequency and
 * whether it was disjoint (never) */
struct Disjoint01499f30 { /* derived name */
    u64 frequency;
    bool disjoint;
};

/* slot 5 of the vtables at 0x16c3b40 and 0x16c3b90: the result of the
 * query read from its block into `data`: for the kind 1 the counts summed
 * over the eight pairs, for 2 the 64-bit value, for 3 the frequency (800
 * MHz, 911 MHz in the Neo mode, the mode asked once: FUN_012fcfd0, inlined
 * by the link) and no disjoint, for 5 whether any pair differs; 0, or -2
 * for a kind it does not know. The context and the size are not read. */
// NONMATCHING: 48/96, 328 bytes against 334. First: the base's jump table spans the kinds 0 to 15
// (`cmp rcx, 15; ja`, the -2 block at the entries 0 and 6 to 15), so its switch held those cases with a
// successor other than the default's; a case written with the default's `return -2` is dropped from
// the switch (ConstantFoldTerminator, Local.cpp, removes a case whose successor is the default) and
// the table is 1 to 5. Then: the sum's subtractions come before each pair's add (Reassociate's ranks:
// the begin loaded first), the Neo select's polarity, and the kind 5's two stores kept apart.
int Object01499f30::FUN_0131f300(Context01499f30 *context, void *data, u32 size, u32 flags)
{
    switch (desc.Query) {
    case 1: {
        const Counts01499f30 *counts = static_cast<const Counts01499f30 *>(block);
        u64 total = 0;
        for (int i = 0; i < 8; i++)
            total += counts[i].end - counts[i].begin;
        *static_cast<u64 *>(data) = total;
        break;
    }
    case 2:
        *static_cast<u64 *>(data) = *static_cast<const u64 *>(block);
        break;
    case 3: {
        Disjoint01499f30 *result = static_cast<Disjoint01499f30 *>(data);
        u64 frequency = 0;
        switch (FUN_012fcfd0()) {
        case 0:
            frequency = 800000000;
            break;
        case 1:
            frequency = 911000000;
            break;
        }
        result->frequency = frequency;
        result->disjoint = false;
        break;
    }
    case 4:
        break;
    case 5: {
        const Counts01499f30 *counts = static_cast<const Counts01499f30 *>(block);
        bool any = false;
        for (int i = 0; i < 8; i++) {
            if (counts[i].begin != counts[i].end) {
                any = true;
                break;
            }
        }
        *static_cast<bool *>(data) = any;
        break;
    }
    default:
        return -2;
    }
    return 0;
}
