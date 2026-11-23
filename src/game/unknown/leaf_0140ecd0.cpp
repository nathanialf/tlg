/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

using namespace fade013e7030;

/* derived names: the object at +0x258 of the owner of the class whose
 * vtable is at 0x16d59e0: a state at +0x4 (1 restarts the fades), a flag
 * at +0xbe0 that holds them on and a pointer at +0x7188 that the first
 * needs. The rest is not traced. */
struct Part0140ecd0 { /* derived name */
    u8 unknown0[0x4];
    int state; /* +0x4 */
    u8 unknown8[0xbd8];
    int hold; /* +0xbe0 */
    u8 unknownbe4[0x65a4];
    void *unknown7188; /* +0x7188 */
};

struct Owner0140ecd0 { /* derived name */
    u8 unknown0[0x258];
    Part0140ecd0 *part; /* +0x258 */
};

/* derived names: a request and what the fade made of it: whether it is on,
 * the fade's time and whether it started this step */
struct Request0140ecd0 { /* derived name */
    int requested;
    int on;      /* +0x4 */
    float time;  /* +0x8 */
    int started; /* +0xc */
};

/* derived names: the record at +0x70 with its two requests at +0x1a4c */
struct Record0140ecd0 { /* derived name */
    u8 unknown0[0x1a4c];
    Request0140ecd0 requests[2]; /* +0x1a4c */
};

/* derived names: one of the two fades: whether its request was on, whether
 * it started and its time */
struct Pulse0140ecd0 { /* derived name */
    int on;
    int started; /* +0x4 */
    float time;  /* +0x8 */
};

/* derived names: Object013e7030's fields with the owner above, the record
 * at +0x70 and the two fades at +0x210 */
struct Object0140ecd0 { /* derived name */
    u8 unknown0[0x8];
    Owner0140ecd0 *owner;         /* +0x8 */
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;            /* +0x60 */
    float time;             /* +0x64 */
    float duration;         /* +0x68 */
    int restarted;          /* +0x6c */
    Record0140ecd0 *record; /* +0x70 */
    u8 unknown78[0x198];
    Pulse0140ecd0 pulses[2]; /* +0x210 */

    /* derived name: a fade toward a request over 0.6 of the step's unit,
     * restarted from 0 on the request's rising edge (and on a restart);
     * its state is given back to the request */
    void stepPulse(int index, int on)
    {
        if (control->restart || owner->part->state == 1)
            pulses[index].on = 0;
        const int started = !pulses[index].on && on;
        pulses[index].started = started;
        pulses[index].on = on;
        if (started == 1)
            pulses[index].time = 0.0f;
        float time = pulses[index].time;
        if (time < 0.0f)
            time = 0.0f;
        else if (time > 1.0f)
            time = 1.0f;
        else {
            const float step = control->step / 0.6f;
            time = clamp(time + (on ? step : -step), 0.0f, 1.0f);
        }
        pulses[index].time = time;
        Request0140ecd0 &request = record->requests[index];
        request.on = on;
        request.started = started;
        request.time = time;
    }
};

/* derived names: slot 3 of the vtable at 0x16d59e0: two fades toward the
 * record's requests (the first only while the part's pointer at +0x7188
 * is set), restarted with the fade on the control's restart or the part's
 * state 1; the value and time are the greater of the two, and the fade is
 * held on while either request or the part's flag at +0xbe0 is. The class
 * is not traced. */
// NONMATCHING: 118/142, 636 bytes against 632: the two fades are the base's
// (the control read once in each, the record read again at the end); left,
// the restart flag: the base selects `state == 0 ? 1 : restart`, then
// `held ? that : restart` (`cmove esi, r8d; test r9b, r9b; cmove esi,
// eax`), as from `held && state == 0` folded to one condition with the
// state's load ahead of the held test; written that way the state's load
// stays under the test and the tail is threaded on held, written
// `state == 0 && held` the two selects come in the other order.
void FUN_0140ecd0(Object0140ecd0 *self) /* derived name */
{
    self->stepPulse(0, self->owner->part->unknown7188 && self->record->requests[0].requested);
    self->stepPulse(1, self->record->requests[1].requested != 0);
    if (self->control->restart || self->owner->part->state == 1) {
        self->control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    const bool held =
        self->record->requests[0].on || self->record->requests[1].on || self->owner->part->hold;
    self->restarted = self->control->restart;
    if (self->control->state == 0 && held)
        self->restarted = 1;
    const float value = std::max(self->record->requests[1].time, self->record->requests[0].time);
    self->time = value;
    self->value = value;
    self->control->state = held ? 1 : value > 1e-8f ? 2 : 0;
}
