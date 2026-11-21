/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16ae020 (config/vtables.derived.base.txt; its constructor FUN_007d9220):
 * it stores the vtable, releases its counted reference at +0x278, then its
 * base Object00c29c00's destructor (leaf_00c29c00.cpp), inlined in the
 * module. FUN_007d9520, slot 1, is the deleting one. The other members are
 * not traced. */
void FUN_00c2a490(Object0134f620 *self); /* derived name */

class Object00c29c00 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object00c29c00();

  private:
    u8 unknown8[0x230];
    Object0134f620 unknown238; /* +0x238 */
};

class Object016ae020 : public Object00c29c00 /* derived name */
{
  public:
    virtual ~Object016ae020();

  private:
    u8 unknown250[0x28];
    /* +0x278: a counted reference, released by the destructor before the
     * base's */
    Ref00503fb0<Object016b9108> held278;
};

Object016ae020::~Object016ae020() {}
