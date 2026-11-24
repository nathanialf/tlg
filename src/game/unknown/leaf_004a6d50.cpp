/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_string01331840.h"

/* FUN_004a6d50: formats into the text (vsnprintf with 0x7f), the length the
 * one vsnprintf returns, 127 when it fails; unlike its siblings
 * (FUN_01331920) the last byte is not cleared first. A file static: its one
 * caller FUN_00489c30 passes the format "AttackHitCondor_%s" (0x156d7d8),
 * which the link propagates into it (the format's register is not saved,
 * `lea rdx` of the constant before vsnprintf; the caller leaves rsi unset) */
static void FUN_004a6d50(Text004a6d50 *text, const char *format, ...) /* derived name */
{
    va_list args;
    va_start(args, format);
    int written = vsnprintf(text->text, sizeof text->text - 1, format, args);
    va_end(args);
    text->length = written < 0 ? sizeof text->text - 1 : written;
}

struct Owner002a45c0; /* derived name */

struct Record002a45c0 /* derived name */
{
    u8 unknown0[0x58];
    Name name; /* +0x58 */
};

extern const Name D_57d6d38; /* derived name: the key looked up (leaf_00accd20.cpp) */
extern const Name D_57d6b88; /* derived name (leaf_004af420.cpp) */

Record002a45c0 *FUN_002a45c0(Owner002a45c0 *owner, const Name *key,
                             int unknown2);                                  /* derived name */
void FUN_004a6bf0(const Name &first, const Name &second, const Name &third); /* derived name */

/* derived names: when the owner holds a record of the key at 0x57d6d38,
 * posts "AttackHitCondor_<part>", the name at 0x57d6b88 and the record's
 * name at +0x58 through FUN_004a6bf0 */
// NONMATCHING: 68/73 in the whole module, 293 bytes against 290: the base keeps the name's index in r14 across
// FUN_004a6bf0 and across the release's own `lock xadd` (`mov edi, r14d` for FUN_00d66e30); this build forwards it
// across the call (the callee's argument is nocapture readonly at the link) but reloads [rbp-0xb8] after the
// seq_cst xadd (AliasAnalysis.cpp:339-340 in 3.7.1: ModRef for any ordering above monotonic), and the index and the
// part swap r14 and r15. The Name atomics' fact (b) of docs/NOTES.md round 167A, left there for the supervisor;
// the same shape (a frame Name passed by reference, released from a register) is at 2,667 call sites of unwritten
// functions and in no matched one (the one rowed hit, 0x1b5740, frees another name; scratch e549/relscan3.py).
void FUN_00489c30(const char *part, Owner002a45c0 *owner) /* derived name */
{
    if (!owner)
        return;
    Record002a45c0 *record = FUN_002a45c0(owner, &D_57d6d38, 1);
    if (!record)
        return;
    Text004a6d50 text;
    FUN_004a6d50(&text, "AttackHitCondor_%s", part);
    FUN_004a6bf0(Name(text), D_57d6b88, record->name);
}
