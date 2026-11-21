/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b8450.h"

/* derived names: the class whose vtable is at 0x16adfe8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_007d8f60
 * and its destructor), derived from Object016b8450 (the destructor tail-calls
 * 0xc298a0): a counted reference held in a block of its own at +0xa8; the
 * rest is not traced. */
class Object016adfe8 : public Object016b8450 /* derived name */
{
  public:
    virtual ~Object016adfe8();

  private:
    u8 unknown98[0x10];
    Ref00503fb0<Object016b9108> *heldA8; /* +0xa8: freed by the destructor */
};

/* derived names: the complete destructor: the block at +0xa8, where there is
 * one, is deleted (the reference in it released, then operator delete) and
 * the pointer cleared; then the base's destructor runs as a tail call.
 * FUN_007d9200, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016adfe8::~Object016adfe8()
{
    if (heldA8 != 0) {
        delete heldA8;
        heldA8 = 0;
    }
}
