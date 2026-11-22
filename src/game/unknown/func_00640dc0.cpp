/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_libc.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00640dc0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 7 names from strings, each
 * registered with Name's destructor, then the table of 58 names, each with
 * the function it stands for, at 0x5810c30, destroyed by the array destructor the
 * compiler writes for it (0x642350). FUN_00641d30 reads the table. */

typedef bool (*Handler00640dc0)(); /* derived name */

bool FUN_006423c0(); /* derived name */
bool FUN_006424c0(); /* derived name */
bool FUN_006425c0(); /* derived name */
bool FUN_00642740(); /* derived name */
bool FUN_00642770(); /* derived name */
bool FUN_00642870(); /* derived name */
bool FUN_00642970(); /* derived name */
bool FUN_00642a70(); /* derived name */
bool FUN_00642b70(); /* derived name */
bool FUN_00642c70(); /* derived name */
bool FUN_00642d70(); /* derived name */
bool FUN_00642e70(); /* derived name */
bool FUN_00642f70(); /* derived name */
bool FUN_00643070(); /* derived name */
bool FUN_00643170(); /* derived name */
bool FUN_00643270(); /* derived name */
bool FUN_00643370(); /* derived name */
bool FUN_00643470(); /* derived name */
bool FUN_00643570(); /* derived name */
bool FUN_00643670(); /* derived name */
bool FUN_00643770(); /* derived name */
bool FUN_00643870(); /* derived name */
bool FUN_00643970(); /* derived name */
bool FUN_00643a70(); /* derived name */
bool FUN_00643b70(); /* derived name */
bool FUN_00643c70(); /* derived name */
bool FUN_00643d70(); /* derived name */
bool FUN_00643f50(); /* derived name */
bool FUN_006442f0(); /* derived name */
bool FUN_00644430(); /* derived name */
bool FUN_00644570(); /* derived name */
bool FUN_006446b0(); /* derived name */
bool FUN_00644890(); /* derived name */
bool FUN_00644a70(); /* derived name */
bool FUN_00644c50(); /* derived name */
bool FUN_00644d10(); /* derived name */
bool FUN_00644d30(); /* derived name */
bool FUN_00644e90(); /* derived name */
bool FUN_00644eb0(); /* derived name */
bool FUN_00644f10(); /* derived name */
bool FUN_00644f70(); /* derived name */
bool FUN_00645010(); /* derived name */
bool FUN_00645340(); /* derived name */
bool FUN_00645370(); /* derived name */
bool FUN_00645500(); /* derived name */
bool FUN_00645740(); /* derived name */
bool FUN_006457e0(); /* derived name */
bool FUN_00645880(); /* derived name */
bool FUN_00645920(); /* derived name */
bool FUN_00645950(); /* derived name */
bool FUN_00645980(); /* derived name */
bool FUN_006459b0(); /* derived name */
bool FUN_00645a60(); /* derived name */
bool FUN_00645b60(); /* derived name */
bool FUN_00645c60(); /* derived name */
bool FUN_00645d60(); /* derived name */
bool FUN_00645d70(); /* derived name */

extern const char D_158ad4b[12];
extern const char D_158ad57[13];
extern const char D_158ad64[11];
extern const char D_158ad6f[10];
extern const char D_158ad79[16];
extern const char D_158ad89[20];
extern const char D_158ad9d[28];
extern const char D_158adb9[28];
extern const char D_158add5[32];
extern const char D_158adf5[32];
extern const char D_158ae15[27];
extern const char D_158ae30[27];
extern const char D_158ae4b[26];
extern const char D_158ae65[26];
extern const char D_158ae7f[31];
extern const char D_158ae9e[31];
extern const char D_158aebd[27];
extern const char D_158aed8[27];
extern const char D_158aef3[25];
extern const char D_158af0c[27];
extern const char D_158af27[34];
extern const char D_158af49[34];
extern const char D_158af6b[36];
extern const char D_158af8f[36];
extern const char D_158afb3[33];
extern const char D_158afd4[33];
extern const char D_158aff5[35];
extern const char D_158b018[35];
extern const char D_158b03b[31];
extern const char D_158b05a[27];
extern const char D_158b075[28];
extern const char D_158b091[30];
extern const char D_158b0af[30];
extern const char D_158b0cd[28];
extern const char D_158b0e9[33];
extern const char D_158b10a[28];
extern const char D_158b126[11];
extern const char D_158b131[15];
extern const char D_158b140[24];
extern const char D_158b158[13];
extern const char D_158b165[15];
extern const char D_158b174[14];
extern const char D_158b182[14];
extern const char D_158b190[18];
extern const char D_158b1a2[13];
extern const char D_158b1af[18];
extern const char D_158b1c1[13];
extern const char D_158b1ce[19];
extern const char D_158b1e1[17];
extern const char D_158b1f2[19];
extern const char D_158b205[14];
extern const char D_158b213[25];
extern const char D_158b22c[30];
extern const char D_158b24a[11];
extern const char D_158b255[16];
extern const char D_158b265[16];
extern const char D_158b275[19];
extern const char D_158b288[7];
extern const char D_158b28f[8];
extern const char D_158b297[8];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5810c10(D_15cb5dd, false);
Name D_5810c14(D_15cb5e6, false);
Name D_5810c18(D_15ca420, false);
Name D_5810c1c(D_15c627c);
Name D_5810c20(D_15c62a5);
Name D_5810ae0(D_158ad4b);
Name D_5810b18(D_158ad57);

/* a name and the function it stands for, 16 bytes */
struct Entry00640dc0 {       /* derived name */
    Name name;               /* +0x0 */
    Handler00640dc0 handler; /* +0x8 */
};

static Entry00640dc0 D_5810c30[] = {
    {Name(D_158ad64), FUN_006423c0}, {Name(D_158ad6f), FUN_006424c0},
    {Name(D_158ad79), FUN_006425c0}, {Name(D_158ad89), FUN_00642740},
    {Name(D_158ad9d), FUN_00642770}, {Name(D_158adb9), FUN_00642870},
    {Name(D_158add5), FUN_00642970}, {Name(D_158adf5), FUN_00642a70},
    {Name(D_158ae15), FUN_00642b70}, {Name(D_158ae30), FUN_00642c70},
    {Name(D_158ae4b), FUN_00642d70}, {Name(D_158ae65), FUN_00642e70},
    {Name(D_158ae7f), FUN_00642f70}, {Name(D_158ae9e), FUN_00643070},
    {Name(D_158aebd), FUN_00643170}, {Name(D_158aed8), FUN_00643270},
    {Name(D_158aef3), FUN_00643370}, {Name(D_158af0c), FUN_00643470},
    {Name(D_158af27), FUN_00643570}, {Name(D_158af49), FUN_00643670},
    {Name(D_158af6b), FUN_00643770}, {Name(D_158af8f), FUN_00643870},
    {Name(D_158afb3), FUN_00643970}, {Name(D_158afd4), FUN_00643a70},
    {Name(D_158aff5), FUN_00643b70}, {Name(D_158b018), FUN_00643c70},
    {Name(D_158b03b), FUN_00643d70}, {Name(D_158b05a), FUN_00643f50},
    {Name(D_158b075), FUN_006442f0}, {Name(D_158b091), FUN_00644430},
    {Name(D_158b0af), FUN_00644570}, {Name(D_158b0cd), FUN_006446b0},
    {Name(D_158b0e9), FUN_00644890}, {Name(D_158b10a), FUN_00644a70},
    {Name(D_158b126), FUN_00644c50}, {Name(D_158b131), FUN_00644d10},
    {Name(D_158b140), FUN_00644d30}, {Name(D_158b158), FUN_00644e90},
    {Name(D_158b165), FUN_00644eb0}, {Name(D_158b174), FUN_00644f10},
    {Name(D_158b182), FUN_00644f70}, {Name(D_158b190), FUN_00645010},
    {Name(D_158b1a2), FUN_00645340}, {Name(D_158b1af), FUN_00645370},
    {Name(D_158b1c1), FUN_00645500}, {Name(D_158b1ce), FUN_00645740},
    {Name(D_158b1e1), FUN_006457e0}, {Name(D_158b1f2), FUN_00645880},
    {Name(D_158b205), FUN_00645920}, {Name(D_158b213), FUN_00645950},
    {Name(D_158b22c), FUN_00645980}, {Name(D_158b24a), FUN_006459b0},
    {Name(D_158b255), FUN_00645a60}, {Name(D_158b265), FUN_00645b60},
    {Name(D_158b275), FUN_00645c60}, {Name(D_158b288), FUN_00645d60},
    {Name(D_158b28f), FUN_00645d70}, {Name(D_158b297), FUN_00645d70},
};

/* derived names: the object the name at 0x15aba40 names, of the type the
 * pointer at 0x5814678 holds (as leaf_006442f0.cpp's), its fields as these
 * handlers read them */
struct Named006442f0 : Object016b9108 /* derived name */
{
    u8 unknown24[0x190];
    float unknown1b4; /* +0x1b4 */
    u8 unknown1b8[0xc91];
    u8 flagse49; /* +0xe49 */
    u8 unknowne4a[0x146];
    float unknownf90; /* +0xf90 */
    u8 unknownf94[0x4];
    float unknownf98; /* +0xf98 */
    u8 unknownf9c[0x5c];
    int unknownff8; /* +0xff8 */
};

extern const char D_15aba40[18];
extern const Type00503fb0 *D_5814678;

/* derived name: whether the int at +0xff8 of that object is `state`, the
 * object looked up for the test (leaf_006442f0.cpp) */
static inline bool hasState(int state)
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && object->unknownff8 == state;
}

/* derived name: whether the object is there with a flag of its byte at
 * +0xe49 set, the object looked up for the test (leaf_006442f0.cpp) */
static inline bool hasFlag(u8 flag)
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    return object && (object->flagse49 & flag);
}

/* derived names: whether the int at +0xff8 of the object is one of four
 * values, the object looked up again for each */
// NONMATCHING: 243 of 249: the last test's result is a `sete` where the base
// tests it as the others (`mov al, 1; je`, then `xor eax, eax`).
bool FUN_00643f50() /* derived name */
{
    return hasState(8) || hasState(9) || hasState(11) || hasState(12);
}

extern const int D_14f0190[5];
extern const int D_14f0170[5];

/* derived names: FUN_006442f0's test (leaf_006442f0.cpp) over the five ints
 * at 0x14f0190 and at 0x14f0170 */
// NONMATCHING: 80 of 83, as FUN_006442f0 (leaf_006442f0.cpp): which load the
// compare folds.
bool FUN_00644430() /* derived name */
{
    for (unsigned i = 0; i < 5; i++) {
        Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
        if (object && D_14f0190[i] == object->unknownff8)
            return true;
    }
    return false;
}

// NONMATCHING: 80 of 83, as FUN_00644430.
bool FUN_00644570() /* derived name */
{
    for (unsigned i = 0; i < 5; i++) {
        Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
        if (object && D_14f0170[i] == object->unknownff8)
            return true;
    }
    return false;
}

/* derived names: the records of the object the pointer at 0x57c9390 holds,
 * as these handlers read them (leaf_006442f0.cpp's Game006425c0): at +0x38
 * a list whose first object (+0x858, count +0x860) is tested for the type
 * D_57d35a8 points to, at +0x40 a record with a settings record at +0x1a0
 * and an object at +0x1e8 whose components are searched */
struct Settings00640dc0 { /* derived name */
    u8 unknown0[0x5038];
    int unknown5038; /* +0x5038 */
    int unknown503c; /* +0x503c */
};

struct Member00640dc0 { /* derived name */
    u8 unknown0[0x1a0];
    Settings00640dc0 *unknown1a0; /* +0x1a0 */
    u8 unknown1a8[0x40];
    Object016b85e0 *unknown1e8; /* +0x1e8 */
};

struct List00640dc0 { /* derived name */
    u8 unknown0[0x858];
    Object016b9108 **entries858; /* +0x858 */
    int count860;                /* +0x860 */
};

struct Game00640dc0 { /* derived name */
    u8 unknown0[0x38];
    List00640dc0 *unknown38;   /* +0x38 */
    Member00640dc0 *unknown40; /* +0x40 */
};

extern Game00640dc0 *D_57c9390;

/* the component FUN_00644f70 finds: an int at +0x67c */
struct Component00644f70 : Component00503fb0 { /* derived name */
    u8 unknown8c[0x5f0];
    int unknown67c; /* +0x67c */
};

extern Type00503fb0 *D_5814e08; /* derived name: the character's type (leaf_007d8be0.cpp) */

/* derived names: whether the object at +0x1e8 of the record at +0x40 has a
 * component of the type D_5814e08 points to (or one derived from it) whose
 * int at +0x67c is 24 */
// NONMATCHING: the base keeps the found component in a register reset in
// the loop and drops the reader count once; the build duplicates the drop on
// the not-found way (register assignment differs from instruction 2).
bool FUN_00644f70() /* derived name */
{
    Object016b85e0 *owner = D_57c9390->unknown40->unknown1e8;
    if (!owner)
        return false;
    Component00644f70 *component =
        static_cast<Component00644f70 *>(owner->findComponent(D_5814e08));
    return component && component->unknown67c == 24;
}

/* the first object of the list: its owner at +0x28 */
struct Object00645500 : Object016b9108 { /* derived name */
    u8 unknown24[0x4];
    Object016b85e0 *owner; /* +0x28 */
};

extern const Type00503fb0 *D_57d35a8; /* derived name */
extern const Type00503fb0 *D_58143e0; /* derived name */
extern const char D_15a15d1[5];

/* derived names: whether the first object of the list at +0x38 is of the
 * type D_57d35a8 points to, its owner has a component of the type D_58143e0
 * points to whose name at +0x4c is the one at 0x15a15d1, and the object
 * hasState looks up is there with the float at +0xf98 off zero by more than
 * 5 or the one at +0xf90 above 5 */
// NONMATCHING: 33 of 160: the component search as FUN_00644f70's.
bool FUN_00645500() /* derived name */
{
    List00640dc0 *list = D_57c9390->unknown38;
    if (list->count860 == 0)
        return false;
    Object00645500 *first = static_cast<Object00645500 *>(kindOf(list->entries858[0], D_57d35a8));
    if (!first)
        return false;
    Component00503fb0 *component = first->owner->findComponent(D_58143e0);
    if (!component)
        return false;
    if (component->nameIndex4c != Name(D_15a15d1, false).index)
        return false;
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    if (!object)
        return false;
    return fabsf(object->unknownf98) > 5.0f || object->unknownf90 > 5.0f;
}

/* derived names: with the object hasState looks up there and the settings
 * record: while the float at +0x1b4 is above 0.95, the ints at +0x5038 and
 * +0x503c both set once flag 8 is set and +0x503c is clear; otherwise
 * +0x5038 cleared and +0x503c set to flag 8; whether +0x5038 is set */
// NONMATCHING: 61 of 215: not worked past the first difference.
bool FUN_00645010() /* derived name */
{
    Named006442f0 *object = findNamed<Named006442f0>(Name(D_15aba40), D_5814678);
    if (!object)
        return false;
    Settings00640dc0 *settings = D_57c9390->unknown40->unknown1a0;
    if (!settings)
        return false;
    if (object->unknown1b4 > 0.95) {
        if (hasFlag(8) && settings->unknown503c == 0) {
            settings->unknown5038 = 1;
            settings->unknown503c = 1;
        }
    } else {
        settings->unknown5038 = 0;
        settings->unknown503c = hasFlag(8);
    }
    return settings->unknown5038 != 0;
}
