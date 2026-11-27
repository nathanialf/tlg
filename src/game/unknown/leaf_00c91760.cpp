/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_property00e78f90.h"

/* derived name: the reader of a value for a property: an argument counted
 * from 1 made an index from the top (the executable keeps no copy: the
 * link inlines it at every site) */
ArgumentReader00c91760::ArgumentReader00c91760(lua_State *state_, const Property00e78f90 *property_,
                                               int argument, int mode_, int element_)
    : state(state_), property(property_), index(argument), mode(mode_), element(element_)
{
    if (index > 0)
        index = index - 1 - argumentCount(state_);
}

/* derived name: reads the reader's argument as an object and a property
 * name: a user value (tag 7) holds the pair past its block, a light one
 * (tag 2) points to it, and both are copied; a string names the object
 * (the record of its name's entry, when this thread may use it), the name
 * left as it is. Anything else leaves the handle alone. The handle is not
 * kept: its callers' handles stay their own (0xe66fd3: the name's index
 * read once around the empty name's raise) */
// NONMATCHING: 68/219, 795 bytes against 813 (registers from instruction 8, not worked); written so the
// module has its body for its callers (FUN_00e66e40 and its siblings): both parameters nocapture
void FUN_00c91760(ArgumentReader00c91760 *reader, PropertyHandle00c91760 *handle)
{
    HksObject *value;
    if (indexToHksObjectUnchecked(reader->state, reader->index, &value))
        return;
    int type = value->type & 0xf;
    if (type == 9 || type == 10)
        type = 6;
    if (type == 7) {
        if (indexToHksObjectUnchecked(reader->state, reader->index, &value))
            return;
        const PropertyHandle00c91760 *pair;
        switch (value->type & 0xf) {
        case 2:
            pair = static_cast<const PropertyHandle00c91760 *>(value->value.pointer);
            if (!pair)
                return;
            break;
        case 7:
            pair = reinterpret_cast<const PropertyHandle00c91760 *>(
                static_cast<HksUserdata *>(value->value.pointer) + 1);
            break;
        default:
            return;
        }
        handle->object = pair->object;
        handle->name = pair->name;
    } else if (type == 4) {
        Name name = nameArgument(reader->state, reader->index);
        if (name.index) {
            Object016b9108 *object = static_cast<Object016b9108 *>(D_17ac870[name.index].record18);
            handle->object = object && isUsable(object) ? object : 0;
        }
    }
}
