/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_namelist.h"

/* derived names: the class whose vtable is at 0x16c72e0
 * (config/vtables.derived.base.txt, stored by FUN_001bd010 and 42 other
 * functions): a list of 2 named values from +0x14, its count at +0x10, held
 * in a NamedValueList013883d0; its slot 2 is FUN_013883d0's append, slots 3
 * to 6 FUN_013884a0, FUN_013884b0, FUN_01388460 and FUN_013884c0 (declared;
 * their parameters are not traced). The other fields are not traced. */
class Object016c72e0 /* derived name */
{
  public:
    virtual ~Object016c72e0();
    virtual void slot2(); /* derived name; FUN_013883d0 */
    virtual void slot3(); /* derived name; FUN_013884a0 */
    virtual void slot4(); /* derived name; FUN_013884b0 */
    virtual void slot5(); /* derived name; FUN_01388460 */
    virtual void slot6(); /* derived name; FUN_013884c0 */

  private:
    u8 unknown8[8];
    NamedValueList013883d0<2> list; /* +0x10 */
};

/* derived name: the complete destructor: the body is empty and the two
 * names are released, the last entry first. FUN_0134a6f0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016c72e0::~Object016c72e0() {}
