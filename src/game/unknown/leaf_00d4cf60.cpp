/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16ba6d8
 * (config/vtables.derived.base.txt, stored by FUN_00d4cdb0 FUN_00d4cf60 FUN_00d4d030), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own fields
 * from +0x34 are traced only where its destructor FUN_00d4cf60 tears them down
 * (the block at +0x48); the rest are not traced. */
class Object016ba6d8 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016ba6d8();

  private:
    u8 unknown34[0x14];
    /* +0x48: an owned block, released by the destructor (`mov rax, [rbx+0x48]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block48;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00d4d030, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ba6d8::~Object016ba6d8() {}
