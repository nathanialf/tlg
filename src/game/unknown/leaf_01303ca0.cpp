/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jscomputecontext.h"

/* derived names: -2 without a target, else what slot 5 of the target returns
 * for the context and the three further arguments, passed on, as a tail call
 * (their types are not traced). */
class Target01303ca0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual int slot5(JsComputeContext *context, void *first, void *second,
                      void *third); /* derived name */
};

int JsComputeContext::GetData(Target01303ca0 *target, void *first, void *second, void *third)
{
    if (target) {
        return target->slot5(this, first, second, third);
    }
    return -2;
}
