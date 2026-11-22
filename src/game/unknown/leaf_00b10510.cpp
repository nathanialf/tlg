/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object058325c8.h"

/* derived names: the flags at 0x583260c, 0x583260d and 0x583260e (direct
 * RIP-relative accesses; the last two the file's own, internal linkage,
 * docs/DECISIONS.md D17), which FUN_00b127e0 also clears (0xb12956 to
 * 0xb12964). The program stores only 0 and 1 to them, so GlobalOpt shrinks
 * each to a bool (`movzx eax, byte; and eax, 1; cmp eax, 1`). FUN_00b10ec0
 * takes these functions' addresses and FUN_00b105c0's for its records (the
 * latter's lea at 0xb11d22). FUN_00b10510 sets the flags from the objects the pointers at
 * 0x58325c8 and 0x58325d8 hold: the int at +0x20a0 set, then with the int at
 * +0x67c at 15 bits 6 or 7 of the int at +0x20a4 set the first flag, bit 0 of
 * its low three the second and the others the third; at 21 the second. FUN_00b105c0 and the
 * two below answer whether their flag still holds and clear it when it
 * does not. No argument is read and none is traced; the fields' meaning is
 * not traced. */
/* read by FUN_00b105c0 in its own file (leaf_00b105c0.cpp): local to the
 * optimiser all the same (config/local_data.base.txt, D74) */
bool D_583260c;
static bool D_583260d;
static bool D_583260e;

// NONMATCHING: the int at +0x20a4 is read once (`mov eax, [rax+0x20a4]`
// before the 0xc0 test) where the base tests its byte for 0xc0 and reads the
// word again after the three stores (`mov eax, [rax+0x20a4]` at 0xb10595).
// Measured: a 1-byte variable stored between cannot alias a 4-byte read
// (BasicAA's object-size test) and GVN forwards it; declared extern with its
// size unknown, stage 1 keeps the reload and the link's GVN forwards it.
bool FUN_00b10510() /* derived name */
{
    const Object058325c8 *object = D_58325c8;
    if (object->unknown20a0 != 0) {
        int state = D_58325d8->unknown67c;
        if (state == 15 && (object->unknown20a4 & 0xc0) != 0) {
            D_583260c = true;
            D_583260d = false;
            D_583260e = false;
            return false;
        }
        D_583260c = false;
        D_583260d = false;
        D_583260e = false;
        if (state == 21) {
            D_583260d = true;
        } else if (state == 15 && (object->unknown20a4 & 7) != 0) {
            if ((object->unknown20a4 & 1) != 0)
                D_583260d = true;
            else
                D_583260e = true;
        }
        return false;
    }
    D_583260c = false;
    D_583260d = false;
    D_583260e = false;
    return false;
}

bool FUN_00b10610() /* derived name */
{
    if (D_583260d) {
        const Object058325c8 *object = D_58325c8;
        if (object->unknown20a0 != 0) {
            int state = D_58325d8->unknown67c;
            if (state == 21 || (state == 15 && (object->unknown20a4 & 7) != 0))
                return true;
        }
        D_583260d = false;
    }
    return false;
}

bool FUN_00b10660() /* derived name */
{
    if (D_583260e) {
        const Object058325c8 *object = D_58325c8;
        if (object->unknown20a0 != 0) {
            int state = D_58325d8->unknown67c;
            if (((state == 15 && (object->unknown20a4 & 7) != 0) || state == 21) &&
                (object->unknown20a4 & 1) == 0)
                return true;
        }
        D_583260e = false;
    }
    return false;
}
