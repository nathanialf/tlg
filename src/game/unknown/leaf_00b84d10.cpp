/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_object016b9108.h"

/* derived names: an element of the arrays below with nothing to release
 * (not traced) */
struct Element00b84d10 {
    u8 unknown0[0x4];
};

/* derived names: an entry of the table below: a hash, a name and an array
 * (its block released when the entry is destroyed) */
struct Entry00b84d10 {
    u32 hash;                                /* +0x0 */
    Name name;                               /* +0x4 */
    Array05943280<Element00b84d10> elements; /* +0x8 */
    Entry00b84d10 *next;                     /* +0x20 */
};

/* derived names: the class whose vtable is at 0x16b6fe8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b83d50
 * and its destructor FUN_00b84d10), derived from Object016b9108: its slots
 * 2 to 4 are the base's. Its fields are traced where the destructor tears
 * them down: a name at +0x28, an array of names at +0x30, two arrays at
 * +0x48 and +0x60 and a table of 32 buckets of named entries at +0x78. */
class Object016b6fe8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b6fe8();

  private:
    u8 unknown24[0x4];
    Name name28;                               /* +0x28 */
    Array05943280<Name> names30;               /* +0x30 */
    Array05943280<Element00b84d10> elements48; /* +0x48 */
    Array05943280<Element00b84d10> elements60; /* +0x60 */
    NameTable<Entry00b84d10, 32> table78;      /* +0x78 */
};

/* derived name: the complete destructor FUN_00b84d10: the body is empty;
 * the members are torn down, last first, then the base. FUN_00b85010, slot
 * 1, is the deleting one. The destructor is the class's key function, so
 * this file emits the vtable. */
Object016b6fe8::~Object016b6fe8() {}
