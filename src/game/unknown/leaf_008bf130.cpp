/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b0028
 * (config/vtables.derived.base.txt, stored by FUN_008bef40 FUN_008bf130 FUN_008bf1e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_008bf130 tears them down
 * (the records at +0x58, +0x40, +0x28); the rest are not traced. */
class Object016b0028 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b0028();

  private:
    u8 unknown24[0x4];
    /* +0x28: torn down by the destructor (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Object0134f620 record28;
    u8 unknown38[0x8];
    /* +0x40: torn down by the destructor (`lea rdi, [rbx+0x40]; call 0x134f620`) */
    Object0134f620 record40;
    u8 unknown50[0x8];
    /* +0x58: torn down by the destructor (`lea rdi, [rbx+0x58]; call 0x134f620`) */
    Object0134f620 record58;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_008bf1e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b0028::~Object016b0028() {}
