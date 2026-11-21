/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the part at +0x10 that FUN_0134af20 resets; not traced */
struct Part0134b090 /* derived name */
{
    u8 unknown0[0x50];
};

void FUN_0134af20(Part0134b090 *part); /* derived name */

/* derived names: a state the five callers (0x41b241, 0x5028a3 and on)
 * reset: an int at +0x0, a pointer at +0x8, the part at +0x10, a float at
 * +0x60, a counted reference at +0x78, exchanged, and a pointer at +0x80.
 * Not traced further. */
struct State0134b090 /* derived name */
{
    int unknown0;        /* +0x0 */
    void *unknown8;      /* +0x8 */
    Part0134b090 part10; /* +0x10 */
    float unknown60;     /* +0x60 */
    u8 unknown64[0x14];
    AtomicRef0045c470<Object016b9108> held78; /* +0x78 */
    void *unknown80;                          /* +0x80 */
};

/* derived name: the part reset first, then the fields: the float to -1, the
 * reference emptied by compare-and-swap */
void FUN_0134b090(State0134b090 *state)
{
    FUN_0134af20(&state->part10);
    state->unknown0 = 0;
    state->unknown8 = 0;
    state->unknown60 = -1.0f;
    state->held78.clear();
    state->unknown80 = 0;
}
