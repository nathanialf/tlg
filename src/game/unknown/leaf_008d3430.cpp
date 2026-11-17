/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: the script C function FUN_001db8b0 registers (lea at
 * 0x1ddd2f) under the script name "Instance_Respawn": the object its first argument's
 * string names, of the type D_5948b00 points to (usable by this thread),
 * handed to FUN_00d47c20 (as FUN_00d8ff50 hands one); returns 0 (no
 * results). The C function's own name is unknown; the class is not traced. */
struct Object008d3430 : Object016b9108 /* derived name */
{};

void FUN_00d47c20(Object008d3430 *self); /* derived name */

extern const Type00503fb0 *D_5948b00; /* derived name: the object's type */

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

int FUN_008d3430(lua_State *state) /* derived name */
{
    Name name = argumentName(state, 1);
    Object008d3430 *object = findNamed<Object008d3430>(name, D_5948b00);
    if (object)
        FUN_00d47c20(object);
    return 0;
}
