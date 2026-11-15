/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a91c8.h"

/* derived name: the constructor (tlg_game_object016a91c8.h): its base
 * Object016b9108 is built from the name passed on, the Names start empty;
 * then the body: the float at +0x2c, the value at +0x30 (`vmovaps`, after
 * the zero runs), and the nine Names from +0x50 released in order. */
// NONMATCHING: the base reloads every one of the nine Names after the zero run (`mov eax, [rbx+0x50]; test`), the build forwards the zero to the first three (released before any atomic) and reloads from +0x5c: a loop unrolled after the last GVN in the base (the late LoopUnroll) is the lead, the source form not found
Object016a91c8::Object016a91c8(const Name &name) : Object016b9108(name)
{
    unknown2c = 3.40282347e+38f;
    unknown30 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
    name50.release();
    name54.release();
    name58.release();
    name5c.release();
    name60.release();
    name64.release();
    name68.release();
    name6c.release();
    name70.release();
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_003e4bf0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a91c8::~Object016a91c8() {}
