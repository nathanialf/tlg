/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: what FUN_00c8c290 is asked (passed through); not traced */
struct Source00c91670; /* derived name */

/* derived name: the class of the object found, over the reference's (the
 * value compared first, `cmp rcx, rbx`); not traced */
class Value00c91670 : public Object016b9108 /* derived name */
{
};

void FUN_00c8c290(Source00c91670 *source, Value00c91670 **found); /* derived name */

/* derived name: the object FUN_00c8c290 finds put into the reference */
void FUN_00c91670(Source00c91670 *source, AtomicRef0045c470<Object016b9108> *reference)
{
    Value00c91670 *found;
    FUN_00c8c290(source, &found);
    reference->set(found);
}
