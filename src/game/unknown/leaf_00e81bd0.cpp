/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_scriptcode.h"
#include "tlg_hks_string.h"

/* derived name: the hashed string the value at a script index holds: the
 * VM's string of the value (a number formatted "%0.8g" and made one in its
 * slot first, as FUN_00db6b20 does), its text, hash and length; the empty
 * text, hash 0 and length 0 for an index outside the frame or a value that
 * is neither, the mark then set */
// NONMATCHING: 956 bytes against 979: the conversion from memory (round 578E's class); the state,
// the result and the value in r14, r12 and r13 where the base has r12, r13 and r14; the base sends
// an index outside the frame straight to the four stores with their constants (si 1, the empty
// text) and spills the strings' table before the hash (frame 0x118 against 0x108)
void FUN_00e81bd0(HashedString *string, lua_State *state, int argument)
{
    HksString *found = 0;
    HksObject *value;
    if (!indexToHksObjectUnchecked(state, argument, &value)) {
        switch (value->type & 0xf) {
        case 3: {
            char text[256];
            const size_t size = FUN_00d95b60(text, sizeof(text), "%0.8g", value->value.number);
            found = static_cast<HksString *>(
                FUN_00dd06f0(state->global->strings, state, 0, text, size, hashString(text, size)));
            value->value.pointer = found;
            value->type = 4;
            break;
        }
        case 4:
            found = static_cast<HksString *>(value->value.pointer);
            break;
        }
    }
    string->string = found ? found->data : "";
    string->hash = found ? found->hash : 0;
    string->length = found ? found->lengthAndFlags : 0;
    string->unknownE = found == 0;
}
