/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c7c78.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b1d00
 * (config/vtables.derived.base.txt, stored by FUN_00a29f30 FUN_00a2b360 FUN_00a2b430), derived from Object016c7c78 (tlg_game_object016c7c78.h; itself derived from
 * Object016b9108): slot 5 is its own (declared; their bodies are not written here), the others the base's. Its own fields
 * from +0x28 are traced only where its destructor FUN_00a2b360 tears them down
 * (the record at +0x50); the rest are not traced. */
class Object016b1d00 : public Object016c7c78 /* derived name */
{
  public:
    virtual ~Object016b1d00();
    virtual void slot5(); /* derived name; FUN_00a2b500, not traced */

  private:
    u8 unknown28[0x28];
    /* +0x50: torn down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Object0134f620 record50;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * (FUN_00a2a290, tlg_game_object016c7c78.h) is inlined, and Object016b9108's in it.
 * FUN_00a2b430, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b1d00::~Object016b1d00() {}
