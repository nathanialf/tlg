/* src/include/tlg_game_link0079ab40.h: a member of two game classes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_LINK0079AB40_H
#define TLG_GAME_LINK0079AB40_H

#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: a 0x30-byte member of Object016ad930 and Object016ad7a0 (reset at
 * +0x100 and +0x130 by their constructors FUN_0079ab40 and FUN_007970d0),
 * 16-byte aligned: a pointer and a counted reference, null from its
 * constructor (one memset with the members before it), an int and a value
 * that only reset() sets; reset() empties the reference by an exchange,
 * then clears the pointer and the int and sets the value to (0, 0, 0, 1)
 * (`vmovaps`: the value carries the alignment). Not traced further. */
struct Link0079ab40 /* derived name */
{
    Link0079ab40() : unknown0(0) {}

    void reset() /* derived name */
    {
        held8.clear();
        unknown0 = 0;
        unknown10 = 0;
        unknown20.set(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void *unknown0;                        /* +0x0 */
    AtomicRef0045c470<Node00503fb0> held8; /* +0x8: released by the holder's destructor */
    int unknown10;                         /* +0x10 */
    Float4A unknown20;                     /* +0x20 */
};

#endif
