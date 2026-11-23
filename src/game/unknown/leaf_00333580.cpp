/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_links00c63970.h"

extern const Name D_57ce048; /* derived name */

/* derived names: the record FUN_003073c0 hands over: the object whose name
 * is posted at +0x28; the rest is not traced */
struct Record00333580 { /* derived name */
    u8 unknown0[0x28];
    const Object016b9108 *object; /* +0x28 */
};

/* FUN_00333580: the name at 0x57ce048, the name of the record's object and
 * the given name posted to the dispatcher at +0xd0 of the object at
 * 0x5938c40. The dispatcher and the record's object are both read before
 * the first name is copied (`mov rax, [rax+0xd0]` and `mov rax, [rdi+0x28]`
 * above the first `lock inc`), the dispatcher first. */
void FUN_00333580(const Record00333580 *record, const Name &third) /* derived name */
{
    Dispatcher00c644d0 *links = D_5938c40->links;
    const Object016b9108 *object = record->object;
    links->post(D_57ce048, object->name, third);
}
