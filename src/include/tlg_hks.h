/* Havok Script, the game's Lua-derived script VM. Its own strings name
 * lua_State and hks; the other names here are derived. */
#ifndef TLG_HKS_H
#define TLG_HKS_H

#include "tlg_types.h"

/* A value on the VM's stack: a type tag, then the value (16 bytes). The tags
 * the bytes show: 1 a boolean, 3 a number (a float). derived name. */
struct HksObject {
    int type; /* derived name */
    u32 pad4; /* derived name; never written */

    union {
        int boolean;   /* derived name */
        float number;  /* derived name */
        void *pointer; /* derived name */
    } value;           /* derived name */
};

/* The VM's state as far as the bytes read it: the stack top at +0x48, the
 * slot the next pushed value takes, and at +0x50 the base of the running C
 * function's frame, its first argument (the count of arguments is top - base:
 * FUN_008f38f0, FUN_00e7d500; FUN_00845520 reads the first). */
struct lua_State {
    u8 unknown0[0x48];
    HksObject *top;  /* derived name */
    HksObject *base; /* derived name */
};

/* One entry of a library's table of C functions, a name and its function,
 * the table ending in a null entry (the tables at 0x16bc8b0 to 0x16bd100 that
 * FUN_00ddc6b0 registers under a library's name). derived name. */
struct HksLibraryEntry {
    const char *name;                  /* derived name */
    int (*function)(lua_State *state); /* derived name */
};

#endif
