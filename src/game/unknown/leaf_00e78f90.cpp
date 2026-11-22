/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks_string.h"

/* derived names: pushes a table describing a property: "type", the name of
 * its kind (the table of fifteen names at 0x16b9f00, "<error>" past it; a
 * Uint32 with an enumeration is a "Flag", a Sint32 with one an "Enum" or,
 * for an enumeration of kind 3, a "ShiftMaskedEnum"); "isArray", bit 0 of
 * the flags at +0x6; "className", the string of the name at +0x18 (nil for
 * none). An enumeration of another kind leaves the type unpushed, so the
 * table's store takes the key's slot for the value. The callers are not
 * traced. */
struct Enumeration00e78f90 { /* derived name */
    u8 unknown0[0x8];
    int kind; /* +0x8 */
};

struct Property00e78f90 { /* derived name */
    int kind;             /* +0x0 */
    u16 unknown4;         /* +0x4 */
    u16 flags;            /* +0x6 */
    u8 unknown8[0x10];
    Name className;                   /* +0x18 */
    Enumeration00e78f90 *enumeration; /* +0x20 */
};

extern const char D_14b2cd2[5];  /* derived name: the key of the type */
extern const char D_15c07b5[5];  /* derived name: the flag type's name */
extern const char D_15c07a5[16]; /* derived name: the shifted enumeration's name */
extern const char D_14baa92[5];  /* derived name: the enumeration's name */
extern const char D_15b6073[7];  /* derived name: the unsigned type's name */
extern const char D_15b6065[7];  /* derived name: the signed type's name */
extern const char D_15b605d[8];  /* derived name: the name of no type */
extern const char D_15c07ba[8];  /* derived name: the key of the array flag */
extern const char D_14c2f2d[10]; /* derived name: the key of the class name */

extern const char *const D_16b9f00[15]; /* derived name: the kinds' names */

/* derived name: pushes a string of a known array, its length its size less one */
#define PUSH_KNOWN_STRING(state, string) FUN_013aacc0(state, string, sizeof string - 1)

// NONMATCHING: the kind's tests: the base tests 1 first on the widened kind (`cmp rax, 1`), then
// 0 on the int (`test eax, eax`); the build forms one switch and tests 0 first (if chain and switch
// alike)
void FUN_00e78f90(lua_State *state, const Property00e78f90 *property) /* derived name */
{
    FUN_00d91880(state, 0, 0);
    PUSH_KNOWN_STRING(state, D_14b2cd2);
    switch (property->kind) {
    case 1:
        if (property->enumeration)
            PUSH_KNOWN_STRING(state, D_15c07b5);
        else
            PUSH_KNOWN_STRING(state, D_15b6073);
        break;
    case 0:
        if (property->enumeration) {
            if (property->enumeration->kind == 3)
                PUSH_KNOWN_STRING(state, D_15c07a5);
            else if (property->enumeration->kind == 0)
                PUSH_KNOWN_STRING(state, D_14baa92);
        } else {
            PUSH_KNOWN_STRING(state, D_15b6065);
        }
        break;
    default: {
        const int kind = property->kind;
        const char *name = (unsigned)kind < 15 ? D_16b9f00[kind] : D_15b605d;
        FUN_013aacc0(state, name, strlen(name));
    }
    }
    setTable(state);
    PUSH_KNOWN_STRING(state, D_15c07ba);
    pushBoolean(state, property->flags & 1);
    setTable(state);
    PUSH_KNOWN_STRING(state, D_14c2f2d);
    pushString(state, D_17ac870[property->className.index].string0);
    setTable(state);
}
