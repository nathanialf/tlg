/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01398700.h"

/* derived name: the type the object at +0x48 is tested against */
extern const Type00503fb0 *D_5821208;

/* derived names: the settings the object copies from its simulation when
 * the simulation has a second item: with a first item, the two ids by the
 * level of the object at +0x48 (taken as the type at 0x5821208's, its
 * result not tested), the blocks of the objects at +0x58 and +0x60 where
 * they are set with a bit of +0x94 for each, the mode and the value of the
 * object at +0x40, and the first item's settings; then the second item's.
 * Called by FUN_00b40f10 (the constructor) and slot 56 (FUN_01398700). */
// NONMATCHING: the cast walk's polarity (the base selects null on a `not found` byte, `mov al, 1; ... test al, al;
// cmovne r8, rcx`; the build selects the object on `found`) and the level's test as `cmp eax, 1; jle` where the
// base has `cmp eax, 2; jl`; the rest (the blocks, the mask, the word-by-word copies) is the base's
void FUN_00b41780(Object01398700 *self, Target01398700 *simulation) /* derived name */
{
    if (!simulation || simulation->itemCount < 2 || !simulation->itemAt(1))
        return;
    if (simulation->itemAt(0)) {
        Object016b9108 *object = simulation->unknown48;
        Kind01398700 *kind = static_cast<Kind01398700 *>(object->isKindOf(D_5821208) ? object : 0);
        if (kind->level < 2) {
            self->unknown64 = 0x12;
            self->unknown68 = 0x19;
        } else {
            self->unknown64 = 0x12;
            if (kind->level == 3)
                self->unknown68 = 0x7a;
            else if (kind->level == 4)
                self->unknown68 = 0x95;
            else
                self->unknown68 = 0x19;
        }
        Part01398700_58 *part58 = simulation->unknown58;
        Part01398700_60 *part60 = simulation->unknown60;
        Part01398700_40 *part40 = simulation->unknown40;
        self->present = 0;
        if (part58) {
            self->unknown6c = part58->unknown40;
            self->present |= 1;
        }
        if (part60) {
            self->unknown84 = part60->unknown40;
            self->present |= 2;
        }
        if (part40) {
            self->unknown98 = part40->mode == 1;
            self->unknown90 = part40->unknown50;
        }
        const ItemSettings01398700 *first = simulation->itemAt(0);
        self->settings[0].copy(*first);
    }
    const ItemSettings01398700 *second = simulation->itemAt(1);
    self->settings[1].copy(*second);
}
