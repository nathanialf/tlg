/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_record006df470.h"

extern Type00503fb0 *D_5814e08; /* derived name: the character's type */

/* derived names: the character component's three records (at +0x5a98,
 * +0x5af0 and +0x5b68) */
struct Character006dbc80 : Component00503fb0 /* derived name */
{
    u8 unknown8c[0x5a0c];
    Record006df470 unknown5a98; /* +0x5a98 */
    u8 unknown5ab0[0x40];
    Record006df5e0 unknown5af0; /* +0x5af0 */
    u8 unknown5b40[0x28];
    Binding006df730 unknown5b68; /* +0x5b68 */
};

struct Object006dbc80 { /* derived name */
    u8 unknown0[0x28];
    Object016b85e0 *node; /* +0x28 */
    u8 unknown30[0x22d0];
    Record006df470 unknown2300; /* +0x2300 */
    u8 unknown2318[0x8];
    Record006df5e0 unknown2320;  /* +0x2320 */
    Binding006df730 unknown2370; /* +0x2370 */
};

/* derived names: the three records copied from the node's character
 * component (the type at 0x5814e08, its kind tested again on the found
 * component) */
void FUN_006dbc80(Object006dbc80 *self) /* derived name */
{
    Component00503fb0 *found = self->node->component(D_5814e08);
    if (found && found->isKindOf(D_5814e08)) {
        Character006dbc80 *character = static_cast<Character006dbc80 *>(found);
        self->unknown2300 = character->unknown5a98;
        self->unknown2320 = character->unknown5af0;
        self->unknown2370 = character->unknown5b68;
    }
}
