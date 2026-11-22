/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* derived names: the target's slot 4 called with the context, null skipped,
 * as a tail call. The target's class and the return type are not traced. */
class Target01319870 /* derived name */
{
  public:
    virtual void slot0();                         /* derived name; not traced */
    virtual void slot1();                         /* derived name; not traced */
    virtual void slot2();                         /* derived name; not traced */
    virtual void slot3();                         /* derived name; not traced */
    virtual void slot4(JsDeviceContext *context); /* derived name; not traced */
};

void JsDeviceContext::End(Target01319870 *target)
{
    if (target) {
        target->slot4(this);
    }
}
