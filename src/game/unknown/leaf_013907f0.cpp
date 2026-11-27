/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code and
 * its value at +0x8 (leaf_00b10e30.cpp's) */
struct ScriptArgument00a2efa0 {
    void set(int type_, int value_) /* derived name */
    {
        type = type_;
        value = value_;
    }

    int type;
    u8 unknown4[4];
    int value;
    u8 unknownc[4];
};

/* derived names: calls the script function its name gives with count
 * arguments, its int result through the last pointer; nonzero on success. */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: an entry shown or hidden. While the guide holds its
 * changes (+0xf0) the change is kept in the array at +0xf8. A shown entry
 * with a count goes into its list (+0x68 for an entry with the int at +0xc4
 * set, else +0x50) when it is not there, is marked shown (its handler at
 * +0x38 run, and "GuideSystem.CallEnter" called with its id when +0x82 is
 * set) and the list sorted (FUN_01390fd0); a hidden entry of state 2 and up
 * is faded out (FUN_00b1aad0), else it is taken out of its list and marked
 * hidden (the handler at +0x48, "GuideSystem.CallExit" when +0x83 is set). */
// NONMATCHING: 64/415, 1578 against 1686 bytes; to the first search the base's. Two classes left.
// (1) The searches' answer: the base carries "not found" (`mov bl, 1` in the latch, `xor ebx, ebx`
// on a match, 0x139091d and 0x1390a12) where the build carries "found"; `!contains`, `contains`
// and `indexOf() == -1` compiled (the last keeps the index). (2) The temporary reference: the base
// raises the entry's count with no null test (0x13908e7) and tests the entry for null at each
// release (`test r14, r14; sete al` kept to 0x1390a8d), where Ref00503fb0(T *) tests it at both and
// the build threads the second test away: the base's temporary comes from a construction that does
// not test (a reference made from an entry known to exist)
// Round 586C, the module: the raise is already the base's (`cmp [r14+8], 0xdeadc0de` with no null
// test, the entry dereferenced first), so (2) is the release's kept test alone. (1) in the module:
// the build sets bl 1 on the match edge and clears it after the loop, the base sets bl 1 in the
// latch and clears it on the match (0x139091d, 0x1390a12): the phi carries "not found"
void FUN_013907f0(Object016b4ce0 *self, Entry016b4ce0 *entry, bool shown) /* derived name */
{
    if (self->holdingF0) {
        const Change016b4ce0 change = {entry, shown};
        self->changesF8.push(change);
        return;
    }
    Array05943280<Ref00503fb0<Object016b9108>> &list =
        entry->listC4 ? self->array68 : self->array50;
    if (shown) {
        if (entry->countC8 <= 0)
            return;
        if (!list.contains(Ref00503fb0<Object016b9108>(entry->object()))) {
            FUN_00b16e40(&list, Ref00503fb0<Object016b9108>(entry->object()));
            entry->changedD1 = 0;
            if (entry->shown14 != 1) {
                entry->shown14 = 1;
                entry->unknown88 = 0;
                if (entry->onEnter38)
                    (entry->handler18.*entry->onEnter38)();
                if (entry->callEnter82) {
                    ScriptArgument00a2efa0 argument;
                    argument.set(3, entry->id8C);
                    FUN_00a2efa0("GuideSystem.CallEnter", 1, &argument, 0);
                }
            }
            FUN_01390fd0(list.begin(), list.end());
        }
        return;
    }
    if (entry->state10 >= 2) {
        FUN_00b1aad0(entry, true, 0.6f);
        return;
    }
    if (!list.contains(Ref00503fb0<Object016b9108>(entry->object())))
        return;
    list.removeAt(list.indexOf(Ref00503fb0<Object016b9108>(entry->object())));
    entry->changedD1 = 0;
    if (entry->shown14 != 0) {
        entry->shown14 = 0;
        entry->unknown88 = 0;
        if (entry->onExit48)
            (entry->handler18.*entry->onExit48)();
        if (entry->callExit83) {
            ScriptArgument00a2efa0 argument;
            argument.set(3, entry->id8C);
            FUN_00a2efa0("GuideSystem.CallExit", 1, &argument, 0);
        }
    }
}
