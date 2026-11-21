/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived name: the class of the value given, over the slot's (the value
 * compared first, `cmp rdi, rbx`, as a pointer converted to the slot's
 * type); not traced */
class Value00bc2f00 : public Object016b9108 /* derived name */
{
};

/* derived name: the value put into the counted reference `slot` (exchanged,
 * the new one raised and the old one dropped where they differ); its
 * address is taken at 0xbc29c2, the value first and the slot second */
void FUN_00bc2f00(Value00bc2f00 *value, AtomicRef0045c470<Object016b9108> *slot)
{
    slot->set(value);
}
