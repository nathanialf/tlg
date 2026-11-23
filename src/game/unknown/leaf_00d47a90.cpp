/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_counted00d47fc0.h"

/* FUN_00d47a90: bit 7 of the source's flag byte at +0x24 set; an object of
 * the type at 0x5948af8 made under the empty name (FUN_00cbc5a0, mode 0) and
 * a reference to it appended to the holder's array at +0x268 (FUN_00d47fc0,
 * an empty reference for null); the object then takes the source's second
 * name (+0x10) when the source's own name holds a '#', else the source's
 * name, and is handed to FUN_00d461b0 with the holder. Its callers are not
 * traced. */
void FUN_00d47a90(Holder00d47a90 *holder, Source00d47a90 *source) /* derived name */
{
    source->flags24 |= 0x80;
    Counted00d47fc0 *object =
        static_cast<Counted00d47fc0 *>(FUN_00cbc5a0(D_5945a38, D_5948af8, Name(), 0));
    holder->objects268.push(Ref00503fb0<Counted00d47fc0>(object));
    const Name &name =
        strchr(D_17ac870[source->name.index].string0, '#') ? source->name10 : source->name;
    object->name28 = name;
    FUN_00d461b0(object, holder);
}
