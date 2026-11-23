/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b8d40.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_shared.h"

/* derived names: the block lists of leaf_013ace60.cpp (not traced here)
 * and the object D_59455b8 points to, as far as the destructor below reads
 * it: two of them, at +0x100 and +0x108 */
struct Blocks013ace60;

void FUN_013ace60(Blocks013ace60 *list, int i); /* derived name */

struct Object059455b8 {
    /* derived names: a block given back to each list (the index read
     * before the list: `mov esi, [r14+0xf8]` before `mov rdi, [rbx+0x100]`) */
    void freeBlock100(int i)
    {
        FUN_013ace60(blocks100, i);
    }

    void freeBlock108(int i)
    {
        FUN_013ace60(blocks108, i);
    }

    u8 unknown0[0x100];
    Blocks013ace60 *blocks100; /* +0x100 */
    Blocks013ace60 *blocks108; /* +0x108 */
};

extern Object059455b8 *D_59455b8;

/* derived names: the object the class below owns at +0x100, deleted by its
 * destructor: four shared objects held at +0x60, +0x78, +0x90 and +0xa8;
 * the other fields are not traced */
struct Owned00cadd70 {
    u8 unknown0[0x60];
    SharedRef00901550<Shared00901550> shared60; /* +0x60 */
    u8 unknown68[0x10];
    SharedRef00901550<Shared00901550> shared78; /* +0x78 */
    u8 unknown80[0x10];
    SharedRef00901550<Shared00901550> shared90; /* +0x90 */
    u8 unknown98[0x10];
    SharedRef00901550<Shared00901550> sharedA8; /* +0xa8 */
};

/* derived names: elements of the array at +0x110 with nothing to release
 * (not traced) */
struct Element00cadd70 {
    u8 unknown0[0x4];
};

/* derived names: the class whose vtable is at 0x16b8ea0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00cabe60
 * and its destructor FUN_00cadd70), derived from Object016b8d40 (the class
 * whose destructor is 0xca38f0): the base's slots and fields are not
 * traced, so the bytes below the first member here are the base's or this
 * class's. Its own fields are traced where the destructor reads them or
 * tears them down: counted references from +0x80, the blocks it holds in
 * the two lists of D_59455b8 at +0xf8 and +0xfc (none when negative), the
 * owned object at +0x100, a reference at +0x108 and two arrays at +0x110
 * and +0x128. */
class Object016b8ea0 : public Object016b8d40 /* derived name */
{
  public:
    virtual ~Object016b8ea0();

  private:
    u8 unknown54[0x2c];
    Ref00503fb0<Object016b9108> held80; /* +0x80 */
    Ref00503fb0<Object016b9108> held88; /* +0x88 */
    Ref00503fb0<Object016b9108> held90; /* +0x90 */
    Ref00503fb0<Object016b9108> held98; /* +0x98 */
    Ref00503fb0<Object016b9108> heldA0; /* +0xa0 */
    u8 unknownA8[0x50];
    int blockF8;                             /* +0xf8: in D_59455b8's list at +0x100 */
    int blockFC;                             /* +0xfc: in D_59455b8's list at +0x108 */
    Owned00cadd70 *owned;                    /* +0x100 */
    Ref00503fb0<Object016b9108> held108;     /* +0x108 */
    Array05943280<Element00cadd70> array110; /* +0x110 */
    Object0134f620 array128;                 /* +0x128 */
};

/* derived name: the complete destructor FUN_00cadd70: the owned object
 * deleted and its pointer cleared when there is one (the null arm skips
 * the store: `je` past it), the two blocks freed in D_59455b8's lists when there is one,
 * then both set to none; the members are released, last first, and the
 * base's destructor 0xca38f0 runs as a tail call. FUN_00cae220, slot 1, is
 * the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. */
Object016b8ea0::~Object016b8ea0()
{
    if (owned) {
        delete owned;
        owned = 0;
    }
    if (Object059455b8 *blocks = D_59455b8) {
        blocks->freeBlock100(blockF8);
        blocks->freeBlock108(blockFC);
    }
    blockF8 = -1;
    blockFC = -1;
}
