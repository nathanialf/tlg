/* src/include/tlg_game_parameters01358c30.h: the tables of named parameters
 * the classes over Object016cb108 keep at +0x38 of their objects (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_PARAMETERS01358C30_H
#define TLG_GAME_PARAMETERS01358C30_H

#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: a name given as a string in a static table and made once
 * at run time, on the heap: the slot holds the made name and the string
 * (the constructors' 0x70-byte entries hold one at +0x10, `mov [r15-0x8],
 * r14` at 0xad8e2a; FUN_01358c30's 0x58-byte entries three) */
struct NameSlot01358c30 { /* derived name */

    /* the name made new from the string, after its block (`mov edi, 4;
     * call _Znwm` before the string is read, 0x1358c60) */
    void bind() /* derived name */
    {
        name = new Name(Name::intern(string));
    }

    Name *name;         /* +0x0 */
    const char *string; /* +0x8 */
};

/* derived names: one entry of the table at +0x30, 0x58 bytes (`add r12,
 * 0x58` at 0x1358d4e), its three names at +0x8, +0x20 and +0x30 */
struct Parameter01358c30 { /* derived name */
    u8 unknown0[0x8];
    NameSlot01358c30 first; /* +0x8 */
    u8 unknown18[0x8];
    NameSlot01358c30 second; /* +0x20 */
    NameSlot01358c30 third;  /* +0x30 */
    u8 unknown40[0x18];
};

/* derived names: the tables an object over Object016cb108 points at, at +0x38
 * of it: FUN_00ad8d30 stores the table at 0x582d4c0 at +0x30 with the count
 * 1 at +0x38 (`mov [rbx+0x68], rdx; mov dword [rbx+0x70], 1`), FUN_0057c270
 * the table at 0x57fb6f0 */
struct Parameters01358c30 { /* derived name */
    void bindNames();       /* FUN_01358c30 */

    u8 unknown0[0x30];
    Parameter01358c30 *entries30; /* +0x30 */
    int count38;                  /* +0x38 */
};

#endif
