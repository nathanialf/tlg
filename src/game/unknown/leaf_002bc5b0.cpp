/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a7ff8.h"

void FUN_002bc7f0(Object016a7ff8 *object); /* derived name; not traced */

inline void Object016a7ff8::reset(unsigned capacity)
{
    unknown24 = 0;
    unknown28 = 0;
    unknown2c = 0;
    array30.clear(capacity);
    held48.clear();
    unknown50 = 0;
    name58 = Name();
}

/* the base built from the name, the fields empty, the array given room
 * for 10, the two vectors set (one 32-byte store from the constant at
 * 0x14e33c0) */
Object016a7ff8::Object016a7ff8(const Name &name) : Object016b9108(name)
{
    reset(10);
    unknown60 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    unknown70 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    unknown80 = 0;
}

/* the complete destructor: the object handed to FUN_002bc7f0, the fields
 * empty, the array given its block back, +0x80 cleared; then the members
 * and the base released. FUN_002bca60, slot 1, is the deleting one. */
Object016a7ff8::~Object016a7ff8()
{
    FUN_002bc7f0(this);
    reset(0);
    unknown80 = 0;
}
