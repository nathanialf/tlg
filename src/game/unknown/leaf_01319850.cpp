/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* derived names: the target's slot 3 called with the context, null skipped,
 * as a tail call. The target's class and the return type are not traced. */
class Target01319850 /* derived name */
{
  public:
    virtual void slot0();                         /* derived name; not traced */
    virtual void slot1();                         /* derived name; not traced */
    virtual void slot2();                         /* derived name; not traced */
    virtual void slot3(JsDeviceContext *context); /* derived name; not traced */
};

void JsDeviceContext::Begin(Target01319850 *target)
{
    if (target) {
        target->slot3(this);
    }
}
