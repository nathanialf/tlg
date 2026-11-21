/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: one column's description, 40 bytes, its kind first */
struct Column00beba70 { /* derived name */
    int kind;           /* +0x0 */
    u8 unknown4[0x24];
};

/* derived names: parallel arrays, one entry per column: its name (+0x18),
 * its value (+0x20), its description (+0x28), its end offset (+0x30) and a
 * byte (+0x38) */
struct Columns00beba70 { /* derived name */
    u8 unknown0[0x18];
    Name *names;           /* +0x18 */
    u64 *values;           /* +0x20 */
    Column00beba70 *kinds; /* +0x28 */
    u32 *ends;             /* +0x30 */
    s8 *flags;             /* +0x38 */
};

/* derived names: the class whose vtable is at 0x16b7c08
 * (config/vtables.derived.base.txt; built by FUN_005269a0 and others), which
 * fills the columns at +0x10, the current one at +0x8. Slot 1 (0xbeba70)
 * starts the current column with a name: the name assigned, the value
 * cleared, the kind 4, the end four bytes after the previous column's (four
 * for the first) and the byte -1. The arrays are read again after each
 * store. Slot 0 (0xbeb3b0) is not traced. */
class Object016b7c08 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; 0xbeb3b0, not traced */
    virtual void FUN_00beba70(const Name &name);

  private:
    u32 current;              /* +0x8 */
    Columns00beba70 *columns; /* +0x10 */
};

void Object016b7c08::FUN_00beba70(const Name &name)
{
    const unsigned i = current;
    columns->names[i] = name;
    columns->values[i] = 0;
    columns->kinds[i].kind = 4;
    columns->ends[i] = i != 0 ? columns->ends[i - 1] + 4 : 4;
    columns->flags[i] = -1;
}
