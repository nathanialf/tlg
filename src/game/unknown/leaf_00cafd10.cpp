/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016cc398.h"
#include "tlg_game_shared.h"

/* derived names: the object the class below owns at +0xb0, deleted by its
 * destructor: four shared objects held at +0x60, +0x78, +0x90 and +0xa8;
 * the other fields are not traced */
struct OwnedB0016b8f60 {
    u8 unknown0[0x60];
    SharedRef00901550<Shared00901550> shared60; /* +0x60 */
    u8 unknown68[0x10];
    SharedRef00901550<Shared00901550> shared78; /* +0x78 */
    u8 unknown80[0x10];
    SharedRef00901550<Shared00901550> shared90; /* +0x90 */
    u8 unknown98[0x10];
    SharedRef00901550<Shared00901550> sharedA8; /* +0xa8 */
};

/* derived names: a list of blocks the class below owns at +0x100 and
 * +0x108 (the lists FUN_013ace60 works on, leaf_013ace60.cpp: its entries
 * at +0x0), deleted by its destructor; its entries' storage is an array of
 * its own */
struct BlockList016b8f60 {
    ~BlockList016b8f60()
    {
        delete[] blocks;
    }

    u8 *blocks; /* +0x0 */
    int count;  /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16b8f60
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00caf730
 * and its destructor FUN_00cafd10), derived from Object016cc398: the
 * object D_59455b8 points to (leaf_00cadd70.cpp reads its lists at +0x100
 * and +0x108). Its own fields are traced where the destructor tears them
 * down: counted references from +0x78 to +0xa0, the object it owns at
 * +0xb0, the two lists and a heap block at +0x110. */
class Object016b8f60 : public Object016cc398 /* derived name */
{
  public:
    virtual ~Object016b8f60();

  private:
    u8 unknown58[0x20];
    Ref00503fb0<Object016b9108> held78; /* +0x78 */
    Ref00503fb0<Object016b9108> held80; /* +0x80 */
    Ref00503fb0<Object016b9108> held88; /* +0x88 */
    Ref00503fb0<Object016b9108> held90; /* +0x90 */
    Ref00503fb0<Object016b9108> held98; /* +0x98 */
    Ref00503fb0<Object016b9108> heldA0; /* +0xa0 */
    u8 unknownA8[0x8];
    OwnedB0016b8f60 *ownedB0; /* +0xb0 */
    u8 unknownB8[0x48];
    BlockList016b8f60 *blocks100; /* +0x100 */
    BlockList016b8f60 *blocks108; /* +0x108 */
    OwnedBlock05943280 block110;  /* +0x110 */
};

/* derived name: the one object of the class (leaf_00cadd70.cpp) */
extern Object016b8f60 *D_59455b8;

/* derived name: the complete destructor: the owned object is deleted, the
 * pointer to this object cleared, the two lists deleted, then the members
 * are torn down, last first, then the base's destructor inline.
 * FUN_00cb0270, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016b8f60::~Object016b8f60()
{
    delete ownedB0;
    D_59455b8 = 0;
    delete blocks100;
    delete blocks108;
}
