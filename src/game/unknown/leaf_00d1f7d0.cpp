/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: an entry of the table below: a hash, a name and a value
 * with nothing to release (not traced) */
struct Entry00d1f7d0 {
    u32 hash;  /* +0x0 */
    Name name; /* +0x4 */
    u8 unknown8[0x8];
    Entry00d1f7d0 *next; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16ba158
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d1f600
 * and its destructor FUN_00d1f7d0), derived from Object016b9108: its slots
 * 2 to 4 are the base's. Its fields are traced where the destructor tears
 * them down: counted references at +0x28, +0x30, +0x38 and +0x50 and a
 * table of 8 buckets of named entries at +0x68. */
class Object016ba158 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ba158();

  private:
    u8 unknown24[0x4];
    Ref00503fb0<Object016b9108> held28; /* +0x28 */
    Ref00503fb0<Object016b9108> held30; /* +0x30 */
    Ref00503fb0<Object016b9108> held38; /* +0x38 */
    u8 unknown40[0x10];
    Ref00503fb0<Object016b9108> held50; /* +0x50 */
    u8 unknown58[0x10];
    NameTable<Entry00d1f7d0, 8> table68; /* +0x68 */
};

/* derived name: the complete destructor: the body is empty; the members
 * are torn down, last first, then the base. FUN_00d1fb30, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ba158::~Object016ba158() {}
