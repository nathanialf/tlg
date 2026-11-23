/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
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

/* derived names: the 0x1c-byte records of the array at +0x7c8 below, a
 * name first */
struct Named00415d50 /* derived name */
{
    Name name; /* +0x0 */
    u8 unknown4[0x18];
};

/* derived names: the object FUN_004143d0, FUN_00415d50 and FUN_00420420
 * empty through FUN_00415bb0: its entries at +0x6c8 */
struct Object00415bb0 /* derived name */
{
    /* 0x415bb0: each entry's records deleted, then the entries destroyed and
     * the count cleared (the block kept) */
    void clearEntries(); /* derived name */

    /* 0x415d50 (called by FUN_003fcc60, FUN_00412a80 and FUN_0041c7c0) */
    void clear(); /* derived name */

    u8 unknown0[0x678];
    Array05943280<Name> names678;         /* +0x678 */
    Array05943280<Name> names690;         /* +0x690 */
    Array05943280<Name> names6a8;         /* +0x6a8 */
    int unknown6c0;                       /* +0x6c0 */
    int unknown6c4;                       /* +0x6c4 */
    Array05943280<Entry00415bb0> entries; /* +0x6c8 */
    u8 unknown6e0[0xb0];
    Array05943280<Name> names790;               /* +0x790 */
    Array05943280<Array05943280<u32>> lists7a8; /* +0x7a8 */
    void *unknown7c0;                           /* +0x7c0 */
    Array05943280<Named00415d50> records7c8;    /* +0x7c8 */
    int unknown7e0;                             /* +0x7e0 */
    int unknown7e4;                             /* +0x7e4 */
    int unknown7e8;                             /* +0x7e8 */
};

void Object00415bb0::clearEntries()
{
    for (unsigned i = 0; i < entries.size(); i++)
        delete[] entries.at(i).records;
    entries.removeAll();
}

/* FUN_00415d50: the names, the entries and the lists emptied, the blocks
 * kept */
void Object00415bb0::clear()
{
    names678.removeAll();
    names690.removeAll();
    names6a8.removeAll();
    unknown6c0 = 0;
    unknown6c4 = 0;
    clearEntries();
    unknown7c0 = 0;
    names790.removeAll();
    records7c8.removeAll();
    unknown7e8 = 0;
    lists7a8.removeAll();
}
