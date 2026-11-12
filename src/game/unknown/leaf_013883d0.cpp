/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_namelist.h"

/* derived names: slot 2 of the vtables at 0x16b9a90 and 0x16c7208 (and of
 * the one holding it at 0x16c7300): appends a name and an int to the list of
 * pairs at +0x14, its count at +0x10 (the name assigned with Name's
 * operator=, the count read again after it). The destructors of the classes
 * with such a list (FUN_01350be0 and on) release the names from the last
 * entry down. No row names the class. The entry is tlg_game_namelist.h's. */

class NameList013883d0 /* derived name */
{
  public:
    virtual ~NameList013883d0();
    virtual void add(const Name &name, unsigned value); /* derived name */

    u8 unknown8[8];
    unsigned count;                /* +0x10 */
    NamedValue013883d0 entries[1]; /* +0x14: the class's own length */
};

// NONMATCHING: the base increments the count in memory after the value's store (`inc dword
// [rbx + 0x10]`: the store not proven apart from the count), the build keeps the count it read
// (BasicAA: a zero-extended index past +0x18) and stores count + 1; rbx and r12 exchanged
void NameList013883d0::add(const Name &name, unsigned value)
{
    entries[count].name = name;
    entries[count].value = value;
    ++count;
}
