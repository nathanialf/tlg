/* src/include/tlg_game_property00e78f90.h: a property as the script tables
 * describing it read it (FUN_00e78f90, FUN_00c8af90), and the strings they
 * push (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_PROPERTY00E78F90_H
#define TLG_GAME_PROPERTY00E78F90_H

#include "tlg_game_name.h"
#include "tlg_hks_string.h"

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

#endif
