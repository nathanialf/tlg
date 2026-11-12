/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16ba6d8
 * (config/vtables.derived.base.txt, stored by FUN_00d4cdb0 FUN_00d4cf60 FUN_00d4d030), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00d4cf60 tears them down
 * (the block at +0x48); the rest are not traced. */
class Object016ba6d8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ba6d8();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x24];
    /* +0x48: an owned block, released by the destructor (`mov rax, [rbx+0x48]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block48;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00d4d030, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ba6d8::~Object016ba6d8() {}
