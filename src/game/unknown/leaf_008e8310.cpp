/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_object0581f740.h"

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

/* derived names: the script C function named "MSC_CreateTime" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): the first timer of the object the
 * pointer at 0x581f740 holds whose Name is the one its first argument's
 * string makes gets the second argument's number as its time and the third
 * argument's truth as its repeat flag, and a timer with the three is added
 * to the object's timers whether one was found or not; pushes true and
 * returns 1 (one result). The C function's own name is unknown. */
// NONMATCHING: 87/183 single-file: (1) the third argument's truth is widened to an int where it is
// made (`setne cl` ... `movzx r13d, cl`), the build widens it at each store (`movzx ecx, r13b`);
// (2) the growth's reallocation keeps the owner lookup's null arm (`movzx edx, byte [rsi-0x10];
// xor edi, edi; cmp edx, 0xa; jne`), the build drops it (the parked reallocation class; round 352B)
int FUN_008e8310(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 3) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_CreateTime", 3);
    }
    Name name;
    name = argumentName(state, 1);
    float time = toNumber(state, 2);
    const HksObject *third = state->base + 2;
    const HksObject *value = third < state->top ? third : 0;
    int type = third < state->top ? value->type & 0xf : 0;
    bool loop = false;
    if (type != 0) {
        loop = true;
        if (type == 1)
            loop = value->value.boolean != 0;
    }
    Object0581f740 *object = D_581f740;
    for (unsigned i = 0; i < object->timers.size(); ++i) {
        if (object->timers.at(i).name == name) {
            object->timers.at(i).time = time;
            object->timers.at(i).loop = loop;
            break;
        }
    }
    new (object->timers.append()) Timer0581f740(name, time, loop);
    pushBoolean(state, true);
    return 1;
}
