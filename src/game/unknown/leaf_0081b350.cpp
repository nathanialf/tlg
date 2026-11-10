/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: destroys the object through slot 0 of its vtable (the
 * complete destructor) and passes its storage to FUN_00d1fd20, as a tail
 * call: a release callback, its address stored by FUN_0081bb10 beside
 * FUN_0081b200 in the record passed to FUN_00cbb0e0. FUN_00d1fd20's
 * other parameters are not traced. Class unknown. */
class Object0081b350 /* derived name */
{
  public:
    virtual ~Object0081b350();
};

void FUN_00d1fd20(void *storage); /* derived name */

void FUN_0081b350(Object0081b350 *object) /* derived name */
{
    object->~Object0081b350();
    FUN_00d1fd20(object);
}
