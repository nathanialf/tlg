/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

/* derived names: the script C function FUN_001db8b0 registers (lea at
 * 0x1ddf5a) under the script name "SetSMState": the object its first
 * argument's string names, of the type D_581f030 points to (usable by this thread),
 * takes its second argument's string as the Name at +0x7c and is handed to
 * FUN_008b7080; returns 0 (no results). The C function's own name is
 * unknown; the class is not traced. */
struct Object008d6160 : Object016b9108 /* derived name */
{
    u8 unknown24[0x58];
    Name name7c; /* +0x7c */
};

extern const Type00503fb0 *D_581f030; /* derived name: the object's type */

void FUN_008b7080(Object008d6160 *object); /* derived name */

// NONMATCHING: register allocation: the build holds the second argument's string slot in a register
// and spills the first Name's index (frame 0x28, `mov [rbp-0x44], r14d`); the base keeps the
// `bextr` mask in r15 and both indexes in registers (frame 0x18)
int FUN_008d6160(lua_State *state) /* derived name */
{
    Name name = argumentName(state, 1);
    Name value = argumentName(state, 2);
    Object008d6160 *object = findNamed<Object008d6160>(name, D_581f030);
    if (object) {
        object->name7c = value;
        FUN_008b7080(object);
    }
    return 0;
}

/* derived names: the script C function FUN_001db8b0 registers (lea at
 * 0x1de0a7) under the script name "ApplyOffsetLua": the object its first
 * argument's string names, of the type D_5939080 points to (usable by this thread), is
 * handed to FUN_0082abe0 with the Name of its second argument's string;
 * returns 0 (no results). The C function's own name is unknown; the class
 * is not traced. */
struct Object008d6df0 : Object016b9108 /* derived name */
{};

extern const Type00503fb0 *D_5939080; /* derived name: the object's type */

void FUN_0082abe0(Object008d6df0 *object, const Name &name); /* derived name */

// NONMATCHING: after FUN_0082abe0 the base drops the second Name from the index it kept in r13d,
// the build reads it back from the slot it passed (`mov r13d, [rbp-0x48]`); the stack guard's
// address is loaded on each path out of the walk (the base: once, before it)
int FUN_008d6df0(lua_State *state) /* derived name */
{
    Name name = argumentName(state, 1);
    Name value = argumentName(state, 2);
    Object008d6df0 *object = findNamed<Object008d6df0>(name, D_5939080);
    if (object)
        FUN_0082abe0(object, value);
    return 0;
}
