/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: a pair of ints that copies itself through its own
 * constructor (one 8-byte load and store), so that a class holding two of
 * them copies each on its own and not as one 16-byte block */
struct Pair00616a60 { /* derived name */

    Pair00616a60(const Pair00616a60 &other) : value(other.value) {}

    struct Value {
        int unknown0;
        int unknown4;
    } value;
};

/* derived names: the 0x78-byte element of the array FUN_0060ada0 appends
 * to: a Name, two locked arrays of Names (each copied by FUN_004cdb70), 28
 * plain bytes copied together, two Names, an int, a Name and two 8-byte
 * pairs each copied by one move; the fields are not traced */
struct Record00616a60 {          /* derived name */
    Name name0;                  /* +0x0 */
    Array01343a80<Name> names8;  /* +0x8 */
    Array01343a80<Name> names20; /* +0x20 */
    int unknown38[7];            /* +0x38 */
    Name name54;                 /* +0x54 */
    Name name58;                 /* +0x58 */
    int unknown5c;               /* +0x5c */
    Name name60;                 /* +0x60 */
    Pair00616a60 unknown64;      /* +0x64 */
    Pair00616a60 unknown6c;      /* +0x6c */
};

/* FUN_00616a60: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
// NONMATCHING: register assignment only: the base holds the array in r15
// and the value in r14 (the name table then taking r15); the build holds
// them the other way round. Every instruction is the base's otherwise (96,
// 360 bytes).
template void Array05943280<Record00616a60>::push(const Record00616a60 &);
