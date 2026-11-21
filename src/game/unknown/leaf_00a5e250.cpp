/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16b2298
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a5d530
 * and its complete destructor FUN_00a5e250), over Object016c81c0, with the
 * spells' object at +0x98 (the class at 0x16b6b30, whose destructor is
 * 0xb60680). The destructor stops the member (FUN_00b611a0), takes the five
 * Spell_ script C functions' names back from the script registry at +0x40
 * of the object the pointer at 0x5938c40 holds (FUN_00c89a10,
 * as leaf_00a64370.cpp, the registry read once and not tested), clears the
 * pointer at 0x5827ee0 and empties the reference at 0x5827ee8
 * (leaf_00a5ebe0.cpp sets it); then the member and the base are torn down.
 * FUN_00a5e380, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
struct Registry05938c40_40; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x40];
    Registry05938c40_40 *unknown40; /* +0x40 */
};

extern Object05938c40 *D_5938c40;

void FUN_00c89a10(Registry05938c40_40 *registry, const char *name); /* derived name */

/* derived names: the spells' class, whose vtable is at 0x16b6b30
 * (config/vtables.derived.base.txt: the constructor 0xa5d530 builds the
 * member in place and its destructor 0xb60680 stores it) */
class Object016b6b30 /* derived name */
{
  public:
    virtual ~Object016b6b30(); /* 0xb60680, its row named after it (D15) */

    void FUN_00b611a0(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
};

extern Object016b6b30 *D_5827ee0;                   /* derived name */
extern AtomicRef0045c470<Object016b9108> D_5827ee8; /* derived name */

class Object016b2298 : public Object016c81c0 /* derived name */
{
  public:
    virtual ~Object016b2298();

  private:
    Object016b6b30 spells; /* +0x98 */
};

Object016b2298::~Object016b2298()
{
    spells.FUN_00b611a0();
    Registry05938c40_40 *registry = D_5938c40->unknown40;
    FUN_00c89a10(registry, "Spell_Start");
    FUN_00c89a10(registry, "Spell_End");
    FUN_00c89a10(registry, "Spell_SetupParameterTable");
    FUN_00c89a10(registry, "Spell_GetParam");
    FUN_00c89a10(registry, "Spell_IsFinish");
    D_5827ee0 = 0;
    D_5827ee8.clear();
}
