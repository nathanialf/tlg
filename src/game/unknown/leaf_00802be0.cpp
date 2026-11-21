/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the counted steps of the sequence below: two names, the
 * one at +0x28 a step's own way on, the one at +0x24 the name the step
 * before it leads to. Nothing else is traced. */
struct Step00802be0 : Object016b9108 /* derived name */
{
    Name name24; /* +0x24 */
    Name name28; /* +0x28 */
};

/* derived names: the object FUN_007ff7e0 asks for the name after a step:
 * its steps at +0x2b0 and the current one at +0x320 */
struct Sequence00802be0 /* derived name */
{
    u8 unknown0[0x2b0];
    Array05943280<Ref00503fb0<Step00802be0>> steps; /* +0x2b0 */
    u8 unknown2c8[0x58];
    Step00802be0 *current320; /* +0x320 */
};

/* derived name: the name after a step (the current one for null): the
 * step's own name at +0x28 when it has one, else the name at +0x24 of the
 * step after it in the sequence, else the empty name. The step is
 * referenced while it is looked for. */
// NONMATCHING: the base stores the empty name first and copies a found name into it without a
// release (`mov dword [r15], 0`, then `lock inc` and the index stored); the copy constructor
// leaves out the first store, the assignment adds the release (sret escapes). Two forms.
Name FUN_00802be0(const Sequence00802be0 *sequence, Step00802be0 *step) /* derived name */
{
    if (step == 0)
        step = sequence->current320;
    if (step->name28.index != 0)
        return step->name28;
    int index = sequence->steps.indexOf(Ref00503fb0<Step00802be0>(step));
    if (index != -1 && index != int(sequence->steps.size()) - 1)
        return sequence->steps.at(index + 1).get()->name24;
    return Name();
}
