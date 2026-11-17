/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: the script C function FUN_00a44ab0 registers (lea at 0xa44cce) under
 * the script name "SetDisabled_Shield": the object its first argument's
 * string names, of the type D_5833d00 points to (usable by this thread),
 * handed to FUN_00b4ca50 with the truth of its second argument; returns 0 (no
 * results). The C function's own name is unknown; the class is not traced. */
struct Object00a46970 : Object016b9108 /* derived name */
{};

void FUN_00b4ca50(Object00a46970 *self, bool on); /* derived name */

extern const Type00503fb0 *D_5833d00; /* derived name: the object's type */

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

// NONMATCHING: the second argument's truth, as FUN_0046b050's: the base keeps the slot a select of
// null past the top (`cmovae rax, r12; jae`) and reads the tag and the boolean through it, the
// build folds the select into the branch (`lea rcx, [rax+0x10]`)
int FUN_00a46970(lua_State *state) /* derived name */
{
    Name name = argumentName(state, 1);
    bool on = toBoolean(state, 2);
    Object00a46970 *object = findNamed<Object00a46970>(name, D_5833d00);
    if (object)
        FUN_00b4ca50(object, on);
    return 0;
}
