/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: an entry of the table below: a hash, a name and a value
 * with nothing to release (not traced) */
struct Entry00c1bb30 {
    u32 hash;  /* +0x0 */
    Name name; /* +0x4 */
    u8 unknown8[0x8];
    Entry00c1bb30 *next; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16b8150
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00c1b970
 * and its destructor FUN_00c1bb30), derived from Object016b9108: its slots
 * 2 to 4 are the base's. Its fields are traced where the destructor tears
 * them down: an array of counted references at +0x28 and a table of 256
 * buckets of named entries at +0x40. */
class Object016b8150 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b8150();

  private:
    u8 unknown24[0x4];
    /* +0x28: emptied to no capacity by the destructor, then torn down
     * (`call 0x134f620`) */
    Object0134f620 array28;
    NameTable<Entry00c1bb30, 256> table40; /* +0x40 */
};

/* derived name: the complete destructor FUN_00c1bb30: the table and the
 * array emptied, then the members and the base torn down. FUN_00c1be30,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016b8150::~Object016b8150()
{
    table40.clear();
    array28.clear();
}
