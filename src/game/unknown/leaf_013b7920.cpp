/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00760920.h"

/* FUN_013b7920: an object whose int at +0x30 is not zero is gathered into
 * the record. Bit 31 of its flags at +0x188 is set first when bit 0 or bit
 * 8 of its flags at +0x38 is, or its +0x28 is null or has a zero int at
 * +0x21c. With bit 11 of the flags at +0x38 a reference to it is appended
 * to the array at +0x1c8 (FUN_00906610, called with a temporary
 * reference); else, with a number at +0x48 of 12 or less: when its int at
 * +0x18c is not zero, to the array of that number and, with its pointer at
 * +0x98 set, to the array at +0x180 (FUN_00760920), and in either case to
 * the array at +0x1b0 (FUN_00906610). Returns 1. Its callers are not
 * traced. */
// NONMATCHING: one block. Where the int at +0x18c is zero the base forms
// the count's address and jumps to the third append's first instruction
// (`lea r12, [r13+8]; jmp` at 0x13b7ad4, the store of the temporary after
// it); the build stores the temporary in that block too and jumps past the
// store. 806 bytes in both, every other instruction the base's.
int FUN_013b7920(Counted00760920 *object, Record013b7610 *record) /* derived name */
{
    if (object->unknown30 != 0) {
        const u32 flags = object->flags38;
        if ((flags & 0x101) || !object->unknown28 || object->unknown28->unknown21c == 0)
            object->flags188 |= 0x80000000;
        if (flags & 0x800) {
            record->objects1c8.push(Ref00503fb0<Counted00906610>(object));
        } else if (object->kind48 < 13) {
            if (object->unknown18c != 0) {
                record->byKind[object->kind48].push(Ref00503fb0<Counted00760920>(object));
                if (object->unknown98)
                    record->objects180.push(Ref00503fb0<Counted00760920>(object));
            }
            record->objects1b0.push(Ref00503fb0<Counted00906610>(object));
        }
    }
    return 1;
}
