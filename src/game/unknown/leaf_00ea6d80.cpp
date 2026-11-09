/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: deletes the object its second argument points to through its
 * virtual destructor (slot 1, the deleting one), null skipped; the first is
 * unused; slot 7 of the vtable at 0x16be610 (its pointer at 0x16be658), the
 * vtable stored by FUN_00e992b0 FUN_00ea4cd0. The object's class is not
 * traced. Class and method unknown. */
class Object00ea6d80Argument /* derived name */
{
  public:
    virtual ~Object00ea6d80Argument();
};

struct Object00ea6d80; /* derived name */

void FUN_00ea6d80(Object00ea6d80 *, Object00ea6d80Argument *object) /* derived name */
{
    delete object;
}
