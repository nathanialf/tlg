/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived name: a type's property of a name: the type's own table, then
 * each parent's; the entry's property copied out when there is somewhere to
 * put it. Answers whether one was found. */
int FUN_00cb7e20(const Type00503fb0 *type, const Name *name, Property00e78f90 *property)
{
    int found = 0;
    if (type) {
        const unsigned key = name->index;
        for (; type; type = type->parent) {
            if (type->propertyChains == 0)
                continue;
            for (PropertyNode00cb7e20 *node = type->properties[key % type->propertyChains]; node;
                 node = node->next) {
                if (node->key == key) {
                    found = 1;
                    if (property)
                        *property = node->property;
                    return found;
                }
            }
        }
    }
    return found;
}
