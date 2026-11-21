/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: the 0xb0-byte records an entry below makes with new[]:
 * only the counted reference at +0x98 has a destructor; they are aligned to
 * 16 (the array's count 16 bytes before it: `lea rax, [r14-0x10]` for
 * operator delete[]), so the first fields are points */
struct Record00415bb0 /* derived name */
{
    Float4A unknown0[9]; /* +0x0 */
    u8 unknown90[0x8];
    Ref00503fb0<Object016b9108> held98; /* +0x98 */
    u8 unknownA0[0x10];
};

/* derived names: the 48-byte entries of the array at +0x6c8 below, each
 * destroyed through its vtable's slot 0, with the records at +0x10 */
class Entry00415bb0 /* derived name */
{
  public:
    virtual ~Entry00415bb0();

    u8 unknown8[0x8];
    Record00415bb0 *records; /* +0x10 */
    u8 unknown18[0x18];
};

/* derived names: the object FUN_004143d0, FUN_00415d50 and FUN_00420420
 * empty through FUN_00415bb0: its entries at +0x6c8 */
struct Object00415bb0 /* derived name */
{
    /* 0x415bb0: each entry's records deleted, then the entries destroyed and
     * the count cleared (the block kept) */
    void clearEntries(); /* derived name */

    u8 unknown0[0x6c8];
    Array05943280<Entry00415bb0> entries; /* +0x6c8 */
};

void Object00415bb0::clearEntries()
{
    for (unsigned i = 0; i < entries.size(); i++)
        delete[] entries.at(i).records;
    entries.removeAll();
}
