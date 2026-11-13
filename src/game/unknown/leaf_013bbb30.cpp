/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16bad40
 * (config/vtables.derived.base.txt, stored by FUN_00d85060 FUN_013bbb30 FUN_013bbc00), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_013bbb30 tears them down
 * (the block at +0x50, the record at +0x38); the rest are not traced. */
class Object016bad40 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bad40();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_00d85230, not traced */
    virtual void slot8(); /* derived name; FUN_00d85500, not traced */

  private:
    u8 unknown24[0x14];
    /* +0x38: torn down by the destructor (`lea rdi, [rbx+0x38]; call 0x134f620`) */
    Object0134f620 record38;
    /* +0x50: an owned block, released by the destructor (`mov rax, [rbx+0x50]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block50;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_013bbc00, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016bad40::~Object016bad40() {}
