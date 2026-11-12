/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16af038 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_0085e360): it stores the vtable, runs 0x134f620 (the record's
 * destructor) on its member at +0x78, releases its Name at +0x74, then
 * tail-calls its base's destructor Object01370f10's (0x1370f10).
 * FUN_01371060, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. The other members are not
 * traced. */

class Object01370f10 /* derived name */
{
  public:
    virtual ~Object01370f10();
};

class Object016af038 : public Object01370f10 /* derived name */
{
  public:
    virtual ~Object016af038();

  private:
    u8 unknown8[0x6c];
    Name name74;              /* +0x74 */
    Object0134f620 unknown78; /* +0x78 */
};

Object016af038::~Object016af038() {}
