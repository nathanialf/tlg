/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_0088b4e0 calls it after each Name it adds to the array
 * at +0x50 of the record at +0x30 of the record at +0x108 of the object the
 * pointer at 0x57c9390 holds (0x8a1901, 0x8a1bf0, 0x8a1d7b): the state at
 * 0x581d1d0 becomes 2 when the array holds the Name at 0x581d1d4, else 1 when
 * it holds the one at 0x581d1d8, else 0, and the object the Name at 0x581d1dc
 * names (of the type D_581d718 points to, usable by this thread) takes it at
 * +0x148. The classes are not traced. */
struct Record00850590 { /* derived name */
    u8 unknown0[0x50];
    Array05943280<Name> names; /* +0x50 */
};

struct Member00850590 { /* derived name */
    u8 unknown0[0x30];
    Record00850590 *unknown30; /* +0x30 */
};

struct Game00850590 { /* derived name */
    u8 unknown0[0x108];
    Member00850590 *unknown108; /* +0x108 */
};

struct Named00850590 : Object016b9108 /* derived name */
{
    u8 unknown24[0x124];
    int state148; /* +0x148 */
};

extern Game00850590 *D_57c9390;
extern int D_581d1d0;                 /* derived name */
extern Name D_581d1d4;                /* derived name */
extern Name D_581d1d8;                /* derived name */
extern Name D_581d1dc;                /* derived name */
extern const Type00503fb0 *D_581d718; /* derived name: the named object's type */

// NONMATCHING: the two searches: the base indexes the array unsigned in a widened counter (`inc
// rdx; cmp edx, eax; jb`, no `movsxd`) and keeps find()'s `test edx, edx; js`; Array05943280::find
// indexes through at(int) (`movsxd` at each element)
void FUN_00850590() /* derived name */
{
    int state = 0;
    D_581d1d0 = 0;
    Game00850590 *game = D_57c9390;
    if (game && game->unknown108 && game->unknown108->unknown30) {
        const Array05943280<Name> &names = game->unknown108->unknown30->names;
        if (names.find(D_581d1d4) >= 0) {
            D_581d1d0 = 2;
            state = 2;
        } else if (names.find(D_581d1d8) >= 0) {
            state = 1;
            D_581d1d0 = 1;
        }
    }
    Named00850590 *named = findNamed<Named00850590>(D_581d1dc, D_581d718);
    if (named)
        named->state148 = state;
}
