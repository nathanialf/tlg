/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a reference-counted table of eleven counted state objects
 * at +0x10 (vtable 0x1692ec0; its destructor FUN_00035b10 releases them,
 * FUN_00035ba0 replaces one, taking a reference to the new one and
 * releasing the old). The owner at 0x3e9c0 keeps the table at +0x10 and the
 * current state's index at +0x18; on a change it calls slot 9 of the old
 * state's object and slot 8 of the new one, fetching each through this
 * getter. The index travels zero-extended, as an enumeration with no
 * negative value. */
enum StateType /* derived name */
{
    STATE_COUNT = 11 /* derived name: the destructor's loop bound */
};

class StateObject; /* derived name */

class StateTable /* derived name */
{
  public:
    virtual ~StateTable();
    StateObject *FUN_00035c40(StateType type) const; /* derived name */

    u8 unknown8[8];
    StateObject *states[STATE_COUNT]; /* derived name */
};

StateObject *StateTable::FUN_00035c40(StateType type) const /* derived name */
{
    return states[type];
}
