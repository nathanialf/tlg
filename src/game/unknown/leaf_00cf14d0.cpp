/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00cf14d0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_00cf1630: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_00cf1790: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_00cf18e0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array01343a80.h"

/* derived names: an object whose word at +0x48 is set holds a locked array
 * of elements at +0x50 (its spin lock at +0x64); four functions set a word
 * of every element under the lock and mark the element's flags at +0x20:
 * the word at +0x58 to 1 or 0 with bit 0 (FUN_00cf1790, FUN_00cf18e0, each
 * element written), the word at +0xb0 to 1 or 0 with bit 6 where it changes
 * (FUN_00cf1630, FUN_00cf14d0, reached by tail calls at 0x72be3a and
 * 0x72beb6). The classes are not traced. */
struct Element00cf14d0 { /* derived name */
    u8 unknown0[0x20];
    u8 flags20; /* +0x20 */
    u8 unknown21[0x37];
    int unknown58; /* +0x58 */
    u8 unknown5c[0x54];
    int unknownb0; /* +0xb0 */
};

struct Object00cf14d0 { /* derived name */
    u8 unknown0[0x48];
    int unknown48; /* +0x48 */
    u8 unknown4c[0x4];
    Array01343a80<Element00cf14d0 *> elements; /* +0x50 */
};

void FUN_00cf1790(Object00cf14d0 *self) /* derived name */
{
    if (self->unknown48) {
        self->elements.lock.lock();
        for (Element00cf14d0 *element : self->elements) {
            element->unknown58 = 1;
            element->flags20 |= 1;
        }
        self->elements.lock.unlock();
    }
}

void FUN_00cf18e0(Object00cf14d0 *self) /* derived name */
{
    if (self->unknown48) {
        self->elements.lock.lock();
        for (Element00cf14d0 *element : self->elements) {
            element->unknown58 = 0;
            element->flags20 |= 1;
        }
        self->elements.lock.unlock();
    }
}

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 280 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00cf1630(Object00cf14d0 *self) /* derived name */
{
    if (self->unknown48) {
        self->elements.lock.lock();
        for (Element00cf14d0 *element : self->elements) {
            if (element->unknownb0 != 1) {
                element->unknownb0 = 1;
                element->flags20 |= 0x40;
            }
        }
        self->elements.lock.unlock();
    }
}

void FUN_00cf14d0(Object00cf14d0 *self) /* derived name */
{
    if (self->unknown48) {
        self->elements.lock.lock();
        for (Element00cf14d0 *element : self->elements) {
            if (element->unknownb0 != 0) {
                element->unknownb0 = 0;
                element->flags20 |= 0x40;
            }
        }
        self->elements.lock.unlock();
    }
}
