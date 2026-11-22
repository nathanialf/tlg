/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted004a2d20.h"

/* derived names: what the holder's +0x88 points to: a count at +0xc0 */
struct Object00481a70_88 { /* derived name */
    u8 unknown0[0xc0];
    int countc0; /* +0xc0 */
};

/* derived names: the holder FUN_00481a70 adds an object to: its array of
 * references at +0x18, a count at +0x30 and the next base number at
 * +0x34; the rest is not traced */
struct Holder00481a70 { /* derived name */
    u8 unknown0[0x18];
    Array004a2d20 objects; /* +0x18 */
    int count30;           /* +0x30 */
    int next34;            /* +0x34 */
    u8 unknown38[0x50];
    Object00481a70_88 *unknown88; /* +0x88 */
};

extern const Name D_57d6b70; /* derived name */

void FUN_00481c10(Holder00481a70 *holder, Counted004a2d20 *object,
                  const Name &name);          /* derived name */
void FUN_004ae460(Object00481a70_88 *object); /* derived name */

/* FUN_00481a70: an object added to the holder: the low five bits of the
 * numbers of the objects held make a mask, the first clear bit of it is the
 * new object's slot (-1 with all 32 taken); a reference to the object is
 * appended to the array at +0x18 (FUN_004a2d20, called with a temporary
 * reference), the count at +0x30 raised, the object's number set to the
 * slot plus the base at +0x34, which goes up by 32; then FUN_00481c10 with
 * the name at 0x57d6b70, the count at +0xc0 of the holder's +0x88 raised
 * and FUN_004ae460 on it. */
// NONMATCHING: the search for the first clear bit. The base carries the
// mask's bit across a block as a byte (`setne dl` beside the select, `test
// dl, dl; jne` after `cmp ecx, 0x1f; jg`); the build tests the masked value
// again (`test rdx, rdx; jne`): 399 bytes for 415. The first loop, the
// append and the tail are the base's.
void FUN_00481a70(Holder00481a70 *holder, Counted004a2d20 *object) /* derived name */
{
    u64 taken = 0;
    for (int i = 0; i < (int)holder->objects.size(); ++i) {
        Counted004a2d20 *held = holder->objects[i].get();
        if (held)
            taken |= 1ull << (held->number3a0 & 31);
    }
    int slot = -1;
    int i = 0;
    bool used;
    do {
        used = (taken & (1ull << i)) != 0;
        if (!used)
            slot = i;
        ++i;
    } while (i < 32 && used);
    holder->objects.push(Ref00503fb0<Counted004a2d20>(object));
    ++holder->count30;
    const int number = slot + holder->next34;
    holder->next34 += 32;
    object->number3a0 = number;
    FUN_00481c10(holder, object, D_57d6b70);
    Object00481a70_88 *unknown88 = holder->unknown88;
    ++unknown88->countc0;
    FUN_004ae460(unknown88);
}
