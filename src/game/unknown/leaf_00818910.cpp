/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16ae740
 * (config/vtables.derived.base.txt, stored by FUN_00818730 FUN_00818910 FUN_008189e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00818910 tears them down
 * (the Name at +0x34, the records at +0x58, +0x40); the rest are not traced. */
class Object016ae740 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ae740();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x10];
    Name name34; /* +0x34: released by the destructor (`mov eax, [rbx+0x34]; shl 5`) */
    u8 unknown38[0x8];
    /* +0x40: torn down by the destructor (`lea rdi, [rbx+0x40]; call FUN_0134f620`) */
    Object0134f620 record40;
    u8 unknown50[0x8];
    /* +0x58: torn down by the destructor (`lea rdi, [rbx+0x58]; call FUN_0134f620`) */
    Object0134f620 record58;
};

/* derived name: the complete destructor: the records, last first, then the other members in reverse, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_008189e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ae740::~Object016ae740()
{
    FUN_0134f620(&record58);
    FUN_0134f620(&record40);
}
