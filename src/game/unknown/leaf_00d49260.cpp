/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: an entry of the table below: a hash, a name and a value
 * with nothing to release (not traced) */
struct Entry016ba630 {
    u32 hash;  /* +0x0 */
    Name name; /* +0x4 */
    u8 unknown8[0x8];
    Entry016ba630 *next; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16ba630
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d49070
 * and its destructor FUN_00d49260), derived from Object016b85e0 (its
 * destructor 0xc55550): the base's slots and fields are not traced, so the
 * bytes below the first member here are the base's or this class's. Its
 * own fields are traced where the destructor tears them down: an array of
 * counted references at +0x238, a heap block at +0x250, a table of 64
 * buckets of named entries at +0x260 and a counted reference at +0x480. */
class Object016ba630 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016ba630();

  private:
    Array05943280<Ref00503fb0<Object016b9108>> array238; /* +0x238 */
    void *block250;                                      /* +0x250 */
    u8 unknown258[0x8];
    NameTable<Entry016ba630, 64> table260; /* +0x260 */
    Ref00503fb0<Object016b9108> held480;   /* +0x480 */
};

/* derived name: the complete destructor: the array's references are
 * released with its block kept and the heap block given back, then the
 * members are torn down, last first, and the base's destructor
 * FUN_00c55550 runs as a tail call. FUN_00d494e0, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
Object016ba630::~Object016ba630()
{
    array238.removeAll();
    releaseBlock(block250);
}
