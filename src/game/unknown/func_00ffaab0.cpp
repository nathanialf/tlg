/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <functional>

/* derived names: FUN_00ffaab0 asks FUN_00fec060 six times for a count (its
 * result an int), each time with a std::function<int(int)> predicate built in
 * place for the call (the fifth argument, r8): their implementations' vtables
 * are 0x16c09b0, 0x16c0a00, 0x16c0960, 0x16c0a50, 0x16c0aa0 and 0x16c0af0
 * (the `lea`s at 0xffbc82, 0xffbd07, 0xffbfa0, 0xffc066, 0xffc4aa and
 * 0xffc50f), the lambdas below in that order. Each captures by reference an
 * int pair of the frame (rbp-0x1050, then rbp-0x11f0, which the first two
 * calls' results fill) and, for the third and fourth, an index into it
 * (rbp-0x1040, rbp-0x1300). The other arguments are not traced. */
struct Context00ffaab0; /* derived name */

struct Owner00ffaab0 { /* derived name */
    u8 unknown0[8];
    void *unknown8; /* +0x8, passed as the second argument */
};

int FUN_00fec060(Context00ffaab0 *context, void *table, int which, Owner00ffaab0 *owner,
                 std::function<int(int)> predicate); /* derived name */

// NONMATCHING: not written beyond the lambdas
void FUN_00ffaab0(Context00ffaab0 *context, Owner00ffaab0 *owner, int index,
                  int other) /* derived name */
{
    int values[2];
    int results[2];
    results[0] = FUN_00fec060(context, owner->unknown8, 0, owner,
                              [&values](int value) -> int { return values[1] != value; });
    results[1] = FUN_00fec060(context, owner->unknown8, 1, owner,
                              [&values](int value) -> int { return values[0] != value; });
    values[0] =
        FUN_00fec060(context, owner->unknown8, index, owner,
                     [&values, &index](int value) -> int { return values[index] == value; });
    values[1] =
        FUN_00fec060(context, owner->unknown8, other, owner,
                     [&values, &other](int value) -> int { return values[other] == value; });
    FUN_00fec060(context, owner->unknown8, 0, owner,
                 [&results](int value) -> int { return results[1] == value; });
    FUN_00fec060(context, owner->unknown8, 1, owner,
                 [&results](int value) -> int { return results[0] == value; });
}
