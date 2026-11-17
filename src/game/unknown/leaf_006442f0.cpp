/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_libc.h"

/* derived names: whether the int at +0xff8 of the object the name at
 * 0x15aba40 names (of the type the pointer at 0x5814678 holds, usable by
 * this thread) is one of the five ints at 0x14f01b0; the object is looked
 * up again for each of the five. It reads no argument. FUN_00644430 and
 * FUN_00644570 are the same over the tables at 0x14f0190 and 0x14f0170. The
 * object's class is not traced. */
struct Named006442f0 : Object016b9108 /* derived name */
{
    u8 unknown24[0xe25];
    u8 flagse49; /* +0xe49: bits 2 and 3 read by FUN_00645a60, FUN_00645b60 */
    u8 unknowne4a[0x1ae];
    int unknownff8; /* +0xff8 */
};

extern const char D_15aba40[18];
extern const Type00503fb0 *D_5814678;
extern const int D_14f01b0[5];

// NONMATCHING: 80 of 83. The compare: the base loads the table's entry and compares the field
// from memory (`cmp dword [r13+0xff8], eax`), then `mov al, 1`; the build sets al first and folds
// the field into `cmp ecx, [r13+0xff8]`.
bool FUN_006442f0() /* derived name */
{
    for (unsigned i = 0; i < 5; i++) {
        Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
        if (object && D_14f01b0[i] == object->unknownff8)
            return true;
    }
    return false;
}

/* derived names: whether the int at +0xff8 of the same object is one value
 * (1 to 25, not 7, 10 or 13: the compared constant of each); the object is
 * looked up as FUN_006442f0 looks it up */
bool FUN_00642770() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 1;
}

bool FUN_00642870() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 2;
}

bool FUN_00642970() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 3;
}

bool FUN_00642a70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 4;
}

bool FUN_00642b70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 5;
}

bool FUN_00642c70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 6;
}

bool FUN_00642d70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 8;
}

bool FUN_00642e70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 9;
}

bool FUN_00642f70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 11;
}

bool FUN_00643070() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 12;
}

bool FUN_00643170() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 14;
}

bool FUN_00643270() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 15;
}

bool FUN_00643370() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 16;
}

bool FUN_00643470() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 17;
}

bool FUN_00643570() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 18;
}

bool FUN_00643670() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 19;
}

bool FUN_00643770() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 20;
}

bool FUN_00643870() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 21;
}

bool FUN_00643970() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 22;
}

bool FUN_00643a70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 23;
}

bool FUN_00643b70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 24;
}

bool FUN_00643c70() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == 25;
}

/* derived name: whether the int at +0xff8 of the same object is `state`,
 * the object looked up for the test */
static inline bool hasState(int state)
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == state;
}

/* derived names: whether the int at +0xff8 of the same object is one of two
 * values (a table of two), the object looked up again for the second */
bool FUN_00644a70() /* derived name */
{
    static const int states[] = {1, 2};
    for (unsigned i = 0; i < 2; i++) {
        if (hasState(states[i]))
            return true;
    }
    return false;
}

bool FUN_00644890() /* derived name */
{
    static const int states[] = {3, 4};
    for (unsigned i = 0; i < 2; i++) {
        if (hasState(states[i]))
            return true;
    }
    return false;
}

bool FUN_00643d70() /* derived name */
{
    static const int states[] = {11, 12};
    for (unsigned i = 0; i < 2; i++) {
        if (hasState(states[i]))
            return true;
    }
    return false;
}

bool FUN_006446b0() /* derived name */
{
    static const int states[] = {14, 15};
    for (unsigned i = 0; i < 2; i++) {
        if (hasState(states[i]))
            return true;
    }
    return false;
}

/* derived name: whether the same object is there with a flag of its byte
 * at +0xe49 set, the object looked up for the test */
static inline bool hasFlag(u8 flag)
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && (object->flagse49 & flag);
}

/* derived names: flag 4 */
bool FUN_00645a60() /* derived name */
{
    return hasFlag(4);
}

/* derived names: flag 8; FUN_00645c60 is the same code */
bool FUN_00645b60() /* derived name */
{
    return hasFlag(8);
}

bool FUN_00645c60() /* derived name */
{
    return hasFlag(8);
}

/* derived names: the records of the object the pointer at 0x57c9390 holds:
 * at +0x38 a list (+0x858, count +0x860) whose first object is tested for
 * the type D_57d35a8 points to, at +0x40 one whose record at +0x1a0 has a
 * flag 0x8000 at +0x2420 (`test byte [rax+0x2421], 0x80`) */
struct Settings006425c0 { /* derived name */
    u8 unknown0[0x2420];
    unsigned flags2420; /* +0x2420 */
};

struct Member006425c0 { /* derived name */
    u8 unknown0[0x1a0];
    Settings006425c0 *unknown1a0; /* +0x1a0 */
    u8 unknown1a8[0x1068];

    /* the name at a signed index (`movsxd` under an unsigned counter at
     * 0x6453d0) */
    const Name &nameAt(int index) const /* derived name */
    {
        return names1210[index];
    }

    Name *names1210;    /* +0x1210 */
    unsigned count1218; /* +0x1218 */
};

struct List006425c0 { /* derived name */
    u8 unknown0[0x858];
    Object016b9108 **entries858; /* +0x858 */
    int count860;                /* +0x860 */
};

struct Game006425c0 { /* derived name */
    u8 unknown0[0x38];
    List006425c0 *unknown38;   /* +0x38 */
    Member006425c0 *unknown40; /* +0x40 */
};

extern Game006425c0 *D_57c9390;
extern const Type00503fb0 *D_57d35a8; /* derived name */

/* derived names: the test of flag 4, made only when the list at +0x858 of
 * the record at +0x38 is not empty, its first object is of the type
 * D_57d35a8 points to (or derives from it) and the flag 0x8000 at +0x2420
 * is set */
bool FUN_006425c0() /* derived name */
{
    List006425c0 *member = D_57c9390->unknown38;
    if (member->count860 == 0)
        return false;
    if (!kindOf(member->entries858[0], D_57d35a8))
        return false;
    if (!(D_57c9390->unknown40->unknown1a0->flags2420 & 0x8000))
        return false;
    return hasFlag(4);
}

extern const char D_158ad22[24];

/* derived names: whether the name at 0x158ad22 is one of the names at
 * +0x1210 of the record at +0x40 (count +0x1218) and flag 8 is not set
 * (or the object is not there) */
bool FUN_00645370() /* derived name */
{
    Name name(D_158ad22);
    bool result = false;
    Member006425c0 *member = D_57c9390->unknown40;
    for (unsigned i = 0; i < member->count1218; i++) {
        if (member->nameAt(i) == name) {
            result = !hasFlag(8);
            break;
        }
    }
    return result;
}

/* derived names: the object FUN_00645a60 looks up holds names at +0x2898
 * (count +0x28a0) */
struct Named00644d30 : Object016b9108 /* derived name */
{
    u8 unknown24[0x2874];

    /* the name at a signed index (`movsxd` under an unsigned counter at
     * 0x644e30) */
    const Name &nameAt(int index) const /* derived name */
    {
        return names2898[index];
    }

    Name *names2898;    /* +0x2898 */
    unsigned count28a0; /* +0x28a0 */
};

extern const char D_158ad3a[9];
extern const char D_158ad43[8];

/* derived names: whether one of that object's names holds the string at
 * 0x158ad3a or the one at 0x158ad43 */
bool FUN_00644d30() /* derived name */
{
    Named00644d30 *object = findNamed<Named00644d30>(Name(D_15aba40), D_5814678);
    if (object) {
        for (unsigned i = 0; i < object->count28a0; i++) {
            const char *string = D_17ac870[object->nameAt(i).index].string0;
            if (strstr(string, D_158ad3a) || strstr(string, D_158ad43))
                return true;
        }
    }
    return false;
}
