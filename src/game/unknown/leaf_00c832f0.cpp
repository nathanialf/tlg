/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_mutex.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the objects the array at +0x1088 holds (counted, derived
 * from the root class); not traced. The array's destructor over them is
 * this unit's alone and has one caller, so the link inlines it in the
 * destructor below, as the base shows (no call to 0x134f620) */
class Element1088016b89c8 : public Object016b9108
{
};

/* derived name: a record of the fixed table at +0x10b0, 0xb0 bytes: a
 * counted reference at +0x98 the only part with a destructor; the rest is
 * not traced */
struct Record016b89c8 {
    u8 unknown0[0x98];
    Ref00503fb0<Object016b9108> held98; /* +0x98 */
    u8 unknownA0[0x10];
};

/* derived name: the object an entry of the table at +0x68b8 owns, deleted
 * through its virtual destructor (slot 1); not traced */
class Value016b89c8
{
  public:
    virtual ~Value016b89c8();
};

/* derived names: an entry of the table at +0x68b8: a hash, a name, the
 * object it owns and the next entry */
struct Entry016b89c8 {
    ~Entry016b89c8()
    {
        delete value;
    }

    u32 hash;             /* +0x0 */
    Name name;            /* +0x4 */
    Value016b89c8 *value; /* +0x8 */
    Entry016b89c8 *next;  /* +0x10 */
};

/* derived name: an element of the array at +0x70d8, 16 bytes: a name at
 * +0x4; the rest is not traced */
struct Element70d8016b89c8 {
    u32 unknown0;
    Name name; /* +0x4 */
    u8 unknown8[0x8];
};

/* derived names: the class whose vtable is at 0x16b89c8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00c32940
 * and its destructor FUN_00c832f0), with no base whose destructor does
 * anything. Its fields are traced where the destructor tears them down: a
 * mutex at +0x8, counted references at +0x30 and +0x10a0, an array of
 * references at +0x1088, a fixed table of 128 records at +0x10b0, a table
 * of 256 buckets of named entries at +0x68b8, an array of named elements
 * at +0x70d8, a heap block at +0x70f0 and an array of names at +0x7110. */
class Object016b89c8 /* derived name */
{
  public:
    virtual ~Object016b89c8();

  private:
    Mutex013847e0 mutex8; /* +0x8 */
    u8 unknown20[0x10];
    Ref00503fb0<Object016b9108> held30; /* +0x30 */
    u8 unknown38[0x1050];
    Array05943280<Ref00503fb0<Element1088016b89c8>> array1088; /* +0x1088 */
    Ref00503fb0<Object016b9108> held10a0;                      /* +0x10a0 */
    u8 unknown10a8[0x8];
    Record016b89c8 records10b0[0x80]; /* +0x10b0 */
    u8 unknown68b0[0x8];
    NameTable<Entry016b89c8, 256> table68b8;      /* +0x68b8 */
    Array05943280<Element70d8016b89c8> array70d8; /* +0x70d8 */
    OwnedBlock05943280 block70f0;                 /* +0x70f0 */
    u8 unknown70f8[0x18];
    Array05943280<Name> names7110; /* +0x7110 */
};

/* derived name: the complete destructor: the body is empty; the members
 * are torn down, last first. FUN_00c83850, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016b89c8::~Object016b89c8() {}
