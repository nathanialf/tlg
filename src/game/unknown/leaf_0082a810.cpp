/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aeb70
 * (config/vtables.derived.base.txt, stored by FUN_00829a40 FUN_0082a810),
 * derived from Object016b9108: its destructor FUN_0082a810 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: a counted reference at +0x28, two arrays of counted references
 * (destroyed by FUN_0134f620) at +0x30 and +0x78 and two arrays of Names
 * between them (the loops over `[r12+rbx*4]` with the counts at +0x68 and
 * +0x50, each block released after its loop). */
class Object016aeb70 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016aeb70();

  private:
    AtomicRef0045c470<Object016b9108> held28; /* +0x28: a counted reference */
    Object0134f620 array30;                   /* +0x30 */
    Array05943280<Name> names48;              /* +0x48 */
    Array05943280<Name> names60;              /* +0x60 */
    Object0134f620 array78;                   /* +0x78 */
};

/* derived name: the one object of the class, cleared by its destructor
 * (`mov qword [0x581bce0], 0` at 0x82a82c, before the members go) */
extern Object016aeb70 *D_581bce0;

/* derived name: the complete destructor: the pointer to the one object is
 * cleared; the members are released, last first, then the base's.
 * FUN_0082aa60, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016aeb70::~Object016aeb70()
{
    D_581bce0 = 0;
}
