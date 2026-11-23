/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"

/* derived names: the member at +0x10, 0x410 bytes, not traced */
struct Member0134fb80 { /* derived name */
    u8 unknown0[0x410];
};

void FUN_0134fb80(Member0134fb80 *member); /* derived name */

/* derived names: a block of the chain at +0x420, the next one at +0x1008 */
struct Chunk01350030 { /* derived name */
    u8 unknown0[0x1008];
    Chunk01350030 *next; /* +0x1008 */
};

/* derived names: the class whose vtable is at 0x16cabc8
 * (config/vtables.derived.base.txt; made by FUN_002212a0): a member at
 * +0x10 that FUN_0134fb80 empties and a chain of blocks at +0x420. Its
 * complete destructor FUN_01350030 empties the member, then releases the
 * blocks first to last, the head stored after each; FUN_013500e0, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. */
class Object016cabc8 : public Counted00c14bc0 /* derived name */
{
  public:
    virtual ~Object016cabc8();

  private:
    u8 unknownc[0x4];
    Member0134fb80 member10; /* +0x10: emptied by FUN_0134fb80 */
    Chunk01350030 *chunks;   /* +0x420 */
};

Object016cabc8::~Object016cabc8()
{
    FUN_0134fb80(&member10);
    while (chunks) {
        Chunk01350030 *next = chunks->next;
        FUN_00ebf3f0(chunks);
        chunks = next;
    }
}
