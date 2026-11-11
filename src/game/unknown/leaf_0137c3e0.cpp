/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: allocates a 16-byte object of the class whose vtable is at
 * 0x16ccba8 (config/vtables.derived.base.txt), value-initialized (zeroed,
 * then the vtable stored), and passes it with the object to FUN_0137c420,
 * which queues it (the seven other functions of this shape, 0x137c3e0 to
 * 0x137c910, each with its own class). The vtables share every slot but slot
 * 3 (slot 0 an empty destructor, slot 1 the deleting one, as the linker
 * folded them), so the classes are written as derived from one base holding
 * the pointer at +0x8, its destructor empty and inline, so this file emits
 * the vtable. */
struct Object0137c420; /* derived name */

class Job0137c420 /* derived name */
{
  public:
    virtual ~Job0137c420() {}

  private:
    void *unknown8; /* +0x8 */
};

class Object0137c3e0 : public Job0137c420 /* derived name */
{
};

void FUN_0137c420(Object0137c420 *self, Job0137c420 *job); /* derived name */

void FUN_0137c3e0(Object0137c420 *self) /* derived name */
{
    FUN_0137c420(self, new Object0137c3e0());
}
