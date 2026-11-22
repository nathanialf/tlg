/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_command003e4440.h"

/* derived names: a script C function (its name not traced): when the game
 * object at 0x5938c40 lets commands be made and the first argument is an
 * object of the type D_5829020 points to (or one derived from it), makes a
 * command of the class at 0x16a8f58, reads its two vectors from the second
 * and third arguments and its value from the fourth, and appends a counted
 * reference to it to the object's commands (FUN_003e4440). Returns 0. */
// NONMATCHING: one instruction: after the append the base reads the count at the object (`cmp
// dword [r14 + 8], 0xdeadc0de`), the build through the count's address (`cmp dword [r13]`); the
// unit stage leaves the release its own address after the call, the link stage merges it with the
// constructor's. 140 of 141 equal. The append's own row (FUN_003e4440) takes its call sites from
// these files: they stay.
int FUN_003e12d0(lua_State *state) /* derived name */
{
    if ((D_5938c40->unknowne8->flags6c & 8) && D_5938c40->unknown1f4 != 0) {
        Object016b9108 *object = 0;
        ArgumentReader003e4440 reader(state);
        FUN_00c8c290(&reader, &object);
        if (object && object->isKindOf(D_5829020)) {
            Holder003e4440 *holder = static_cast<Holder003e4440 *>(object);
            Object016a8f58 *command = new Object016a8f58;
            ArgumentReader003e4440 second(state, 1);
            FUN_00c8edb0(&second, &command->unknown20);
            ArgumentReader003e4440 third(state, 2);
            FUN_00c8edb0(&third, &command->unknown30);
            long value = 0;
            ArgumentReader003e4440 fourth(state, 3);
            FUN_00c8d080(&fourth, &value);
            command->unknown10 = (int)value;
            holder->commands.push(Ref00503fb0<Command003e4440>(command));
        }
    }
    return 0;
}
