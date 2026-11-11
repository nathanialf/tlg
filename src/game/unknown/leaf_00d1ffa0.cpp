/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: destroys the object through slot 0 of its vtable (the
 * complete destructor) and passes its storage to FUN_00d1fd20, as a tail
 * call: a release callback, its address taken by FUN_00d1ffc0 (lea at
 * 0xd232c6), as FUN_0081b350 (cookbook 1141). Class unknown. */
class Object00d1ffa0 /* derived name */
{
  public:
    virtual ~Object00d1ffa0();
};

void FUN_00d1fd20(void *storage); /* derived name */

void FUN_00d1ffa0(Object00d1ffa0 *object) /* derived name */
{
    object->~Object00d1ffa0();
    FUN_00d1fd20(object);
}
