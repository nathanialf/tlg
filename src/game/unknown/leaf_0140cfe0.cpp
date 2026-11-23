/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

/* derived names: the control at +0x228 of the track's owner as this state
 * reads it: a flag at +0x1c and a mode at +0x20. The rest is not traced. */
struct OwnerControl0140cfe0 { /* derived name */
    u8 unknown0[0x1c];
    int unknown1c; /* +0x1c */
    int mode;      /* +0x20 */
};

/* derived names: an entry of 0x960 bytes of the owner, indexed by the
 * state's index; only its flag (at +0x1c34 of the owner for the first) is
 * read */
struct OwnerEntry0140cfe0 { /* derived name */
    int active;
    u8 unknown4[0x95c];
};

struct Owner0140cfe0 { /* derived name */
    u8 unknown0[0x228];
    OwnerControl0140cfe0 *control; /* +0x228 */
    u8 unknown230[0x1a04];
    OwnerEntry0140cfe0 entries[1]; /* +0x1c34 */
};

/* derived names: the track the state belongs to: its owner at +0x8 and its
 * fade control at +0x10 (whose step it reads) */
struct Track0140cfe0 { /* derived name */
    u8 unknown0[0x8];
    Owner0140cfe0 *owner;         /* +0x8 */
    FadeControl013e7030 *control; /* +0x10 */
};

/* derived names: the three values the state copies when it starts */
struct Source0140cfe0 { /* derived name */
    u8 unknown0[0x4];
    int unknown4; /* +0x4 */
    u8 unknown8[0x4];
    int unknownc;  /* +0xc */
    int unknown10; /* +0x10 */
};

/* derived names: the state FUN_010c79e0 steps three of (0x2d0 apart): the
 * track at +0x0, the owner's entry index at +0x8, a value at +0x2c copied
 * to +0x54 on a start with the source's three, whether it is enabled at
 * +0xe0, whether it fired at +0xe4, the state at +0x110 (0 off, 1
 * started, 2 running) and the time to the next firing at +0x170 */
struct State0140cfe0 {    /* derived name */
    Track0140cfe0 *track; /* +0x0 */
    int index;            /* +0x8 */
    u8 unknownc[0x20];
    int unknown2c; /* +0x2c */
    u8 unknown30[0x24];
    int unknown54; /* +0x54 */
    int unknown58; /* +0x58 */
    int unknown5c; /* +0x5c */
    int unknown60; /* +0x60 */
    int unknown64; /* +0x64 */
    u8 unknown68[0x78];
    int enabled; /* +0xe0 */
    int fired;   /* +0xe4 */
    u8 unknowne8[0x28];
    int state; /* +0x110 */
    u8 unknown114[0x5c];
    float time; /* +0x170 */
};

/* derived names: steps the state by an input (0 and 5 stop it, 1 starts
 * it, 3 starts it unless running, 4 starts it when off, others keep it);
 * while the owner's control is clear in mode 1 it is running when the
 * owner's entry is active, else started. Off, it has not fired; started,
 * it fires and copies the source; running, it fires once its time passes 1
 * (three a step). FUN_010c79e0 calls it three times; FUN_01491520 is its
 * bytes. */
// NONMATCHING: 13/78, 372 bytes against 332. The first part (the control's
// test, the jump table of six inputs) is the base's. The base keeps one tail
// for every state (`mov eax, [rsi]; cmp ecx, 1; cmove eax, ecx; cmp ecx, 2`,
// with rsi a phi of &fired and the off state's store through it); here the
// tail is threaded per known state. Also the base reads the source's three
// values before the three stores. Three structures tried (an early return,
// the fired value a local, the off state an if/else around the tail).
void FUN_0140cfe0(State0140cfe0 *self, int input, const Source0140cfe0 *source) /* derived name */
{
    if (!self->enabled)
        self->state = 0;
    else if (self->track->owner->control->unknown1c == 0 && self->track->owner->control->mode == 1)
        self->state = self->track->owner->entries[self->index].active ? 2 : 1;
    else {
        switch (input) {
        case 0:
        case 5:
            self->state = 0;
            break;
        case 1:
            self->state = 1;
            break;
        case 3:
            if (self->state != 2)
                self->state = 1;
            break;
        case 4:
            if (self->state == 0)
                self->state = 1;
            break;
        }
    }
    const int state = self->state;
    if (state == 0)
        self->fired = 0;
    else {
        int fired = state == 1 ? 1 : self->fired;
        if (state == 2 && !fired) {
            self->time += self->track->control->step * 3.0f;
            if (self->time > 1.0f) {
                self->time += -1.0f;
                fired = 1;
            }
        } else
            self->time = 0.0f;
        self->fired = fired;
    }
    if (state == 1) {
        self->unknown58 = source->unknown4;
        self->unknown60 = source->unknownc;
        self->unknown64 = source->unknown10;
        self->unknown54 = self->unknown2c;
        self->unknown5c = 0;
    }
}
