/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted008e3850.h"

/* FUN_008e1200: the holder's object for the source's object at +0x98 (null
 * without one): the array at +0x1d0 searched from its last element for one
 * carrying that object's name; else an object of the type at 0x581f4d0
 * made under the empty name (FUN_00cbc5a0, mode 0), a reference to it
 * appended to the array (FUN_008e3850, an empty reference for null), one
 * more reference taken for the caller and the name given to it through a
 * copy. Its callers are not traced. */
// NONMATCHING: the caller's reference (87 of 132): the base raises it
// through the count's address the appended temporary's raise formed, one
// register for the two (`mov r13, rbx; add r13, 8` before the test at
// 0x8e12a0, `mov r13d, 8` on the null arm, `lock inc [r13]` at 0x8e1354);
// the build forms it again after the join (`mov rax, rbx; add rax, 8`).
// The raise through the counted base's type gives the same; the temporary
// as a named local lets the link inline the append.
Counted008e3850 *FUN_008e1200(Holder008e1200 *holder, Source008e1200 *source) /* derived name */
{
    if (!source->object98)
        return 0;
    for (int i = holder->objects1d0.size(); i > 0; --i) {
        Counted008e3850 *object = holder->objects1d0.at(i - 1).get();
        if (object->name24 == source->object98->name)
            return object;
    }
    Counted008e3850 *object =
        static_cast<Counted008e3850 *>(FUN_00cbc5a0(D_5945a38, D_581f4d0, Name(), 0));
    holder->objects1d0.push(Ref00503fb0<Counted008e3850>(object));
    addReference(object);
    const Name name = source->object98->name;
    object->name24 = name;
    return object;
}
