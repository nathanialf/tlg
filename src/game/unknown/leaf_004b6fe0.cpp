/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: a holder whose array of counted references is its first
 * member, as FUN_004b6d00 and FUN_004b7270 pass it (`mov rdi, r13` with
 * the object, after `cmp [rcx+0x28], rax`); nothing else is traced */
struct Holder004b6fe0 /* derived name */
{
    /* 0x4b6fe0: the object's reference taken while the array is searched,
     * dropped, then its element removed and the ones after it moved down */
    void remove(Object016b9108 *object); /* derived name */

    Array05943280<Ref00503fb0<Object016b9108>> objects; /* +0x0 */
};

void Holder004b6fe0::remove(Object016b9108 *object)
{
    int index = objects.indexOf(Ref00503fb0<Object016b9108>(object));
    if (index >= 0)
        objects.removeAt(index);
}
