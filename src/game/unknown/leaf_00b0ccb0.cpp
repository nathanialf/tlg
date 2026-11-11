/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b4b00 (config/vtables.derived.base.txt): it stores the vtable, runs
 * FUN_0134f620 (the record's destructor) on its member at +0x278, then its
 * base Object00c29c00's destructor (leaf_00c29c00.cpp), inlined in the
 * module. FUN_00b0cd00, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
struct Object0134f620 /* derived name */
{
    void **unknown0; /* +0x0 */
    int unknown8;    /* +0x8 */
};

void FUN_00c2a490(Object0134f620 *self); /* derived name */
void FUN_0134f620(Object0134f620 *self); /* derived name */

class Object00c55550 /* derived name */
{
  public:
    virtual ~Object00c55550();
};

class Object00c29c00 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object00c29c00();

  private:
    u8 unknown8[0x230];
    Object0134f620 unknown238; /* +0x238 */
};

class Object00b0ccb0 : public Object00c29c00 /* derived name */
{
  public:
    virtual ~Object00b0ccb0();

  private:
    u8 unknown248[0x30];
    Object0134f620 unknown278; /* +0x278 */
};

Object00b0ccb0::~Object00b0ccb0()
{
    FUN_0134f620(&unknown278);
}
