/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cd348.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16b1738
 * (config/vtables.derived.base.txt, stored by FUN_00991430 FUN_00991560 FUN_00991670), derived from Object016cd348 (tlg_game_object016cd348.h; itself derived from
 * Object016b9108): slot 5 is its own (declared; their bodies are not written here), the others the base's. Its own fields
 * from +0x30 are traced only where its destructor FUN_00991560 tears them down
 * (the block at +0x50); the rest are not traced. */
class Object016b1738 : public Object016cd348 /* derived name */
{
  public:
    virtual ~Object016b1738();
    virtual void slot5(); /* derived name; FUN_00038120, not traced */

  private:
    u8 unknown30[0x20];
    /* +0x50: an owned block, released by the destructor (`mov rax, [rbx+0x50]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block50;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * (FUN_01382c30, tlg_game_object016cd348.h) is inlined, and Object016b9108's in it.
 * FUN_00991670, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
// NONMATCHING: an inline-cost margin: the build tail-calls the base's destructor FUN_01382c30 where the
// base inlines it
Object016b1738::~Object016b1738() {}
