/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object058325c8.h"

/* derived names: three functions on the file's own flag at 0x583262c (direct
 * RIP-relative accesses: internal linkage, docs/DECISIONS.md D17), which
 * FUN_00b127e0 also clears (0xb1296b). FUN_00b10ec0 stores the addresses of
 * FUN_00b108b0 and FUN_00b108c0 (lea at 0xb11f47 and 0xb11f64) and of
 * FUN_00b108d0 (lea at 0xb12037, stored at 0x5832398) into its records; none
 * of the three reads an argument, and no call shows its parameters. Owner and
 * meaning unknown. */
static bool D_583262c;

void FUN_00b108b0() /* derived name */
{
    D_583262c = true;
}

void FUN_00b108c0() /* derived name */
{
    D_583262c = false;
}

bool FUN_00b108d0() /* derived name */
{
    return D_583262c;
}

/* derived names: two conditions FUN_00b10ec0 registers in its table, each
 * with a test-and-clear and a clear of its own beside it (the lea at
 * 0xb1218f, 0xb12196 and 0xb121b7; 0xb12278, 0xb1227f and 0xb1229c), and the
 * flags they share, which only these and FUN_00b127e0's clears (0xb12972 to
 * 0xb12987) touch: the program stores only 0 and 1 to them, so GlobalOpt
 * shrinks each to a bool (`movzx eax, byte; and eax, 1; cmp eax, 1`). Each
 * condition looks a name up in the names at +0x28f8 of the object at
 * 0x58325c8; the names are statics of the functions, interned once (as a
 * copy: the last argument of FUN_013baad0 0), each 8 bytes above its
 * guard. The states compared and the names' meaning are not traced. */
static bool D_583265c; /* derived name: FUN_00b10a30's name was seen in state 5 */
static bool D_583266c; /* derived name: FUN_00b10a30's second name was seen */
static bool D_583266d; /* derived name: FUN_00b10c20's state 3 was seen */
static bool D_583267c; /* derived name: FUN_00b10c20's name was seen */

extern const char D_15aba12[12];
extern const char D_15aba1e[19];
extern const char D_15aba31[15];

/* derived names: in state 5 (+0x67c of the object at 0x58325d8), whether the
 * name at 0x15aba12 is among the names and the int at +0x18a4 is set, which
 * marks it seen; out of it, once it was seen, whether the name at 0x15aba1e
 * is among them (the mark cleared either way) */
bool FUN_00b10a30() /* derived name */
{
    if (D_58325d8->unknown67c == 5) {
        const Object058325c8 *object = D_58325c8;
        static Name D_5832658(D_15aba12, false);
        if (object->names28f8.contains(D_5832658) && D_58325c8->unknown18a4 != 0) {
            D_583265c = true;
            return true;
        }
        return false;
    }
    if (!D_583265c)
        return false;
    const Object058325c8 *object = D_58325c8;
    D_583265c = false;
    static Name D_5832668(D_15aba1e, false);
    if (object->names28f8.contains(D_5832668)) {
        D_583266c = true;
        return true;
    }
    return false;
}

bool FUN_00b10bf0() /* derived name */
{
    if (D_583266c) {
        D_583266c = false;
        return true;
    }
    return false;
}

void FUN_00b10c10() /* derived name */
{
    D_583265c = false;
    D_583266c = false;
}

/* derived names: in state 3 (+0x1c18 of the object at 0x58325d8) true, which
 * marks it seen; out of it, once it was seen, whether the name at 0x15aba31
 * is among the names (the mark cleared either way) */
bool FUN_00b10c20() /* derived name */
{
    if (D_58325d8->unknown1c18 == 3) {
        D_583266d = true;
        return true;
    }
    if (!D_583266d)
        return false;
    const Object058325c8 *object = D_58325c8;
    D_583266d = false;
    static Name D_5832678(D_15aba31, false);
    if (object->names28f8.contains(D_5832678)) {
        D_583267c = true;
        return true;
    }
    return false;
}

bool FUN_00b10d20() /* derived name */
{
    if (D_583267c) {
        D_583267c = false;
        return true;
    }
    return false;
}

void FUN_00b10d40() /* derived name */
{
    D_583266d = false;
    D_583267c = false;
}
