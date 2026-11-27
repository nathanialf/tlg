/* src/include/tlg_game_property00e78f90.h: a property as the script tables
 * describing it read it (FUN_00e78f90, FUN_00c8af90), and the strings they
 * push (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_PROPERTY00E78F90_H
#define TLG_GAME_PROPERTY00E78F90_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_type.h"
#include "tlg_hks_string.h"

struct Enumeration00e78f90 { /* derived name */
    u8 unknown0[0x8];
    int kind; /* +0x8 */
};

/* 0x28 bytes: the value of an entry of a type's table of properties
 * (FUN_00cb7e20 copies it out: the first 0x14 bytes, the two names, the
 * enumeration). A local one has only its names made (`mov qword
 * [rbp-0x9c], 0` at 0xe66ecf) */
struct Property00e78f90 { /* derived name */
    int kind;             /* +0x0 */
    /* +0x4: one word of flags: bit 16 the array flag ("isArray", read as
     * the word at +0x6: `movzx eax, word [r14+6]` at 0xe7908a), bit 9 and
     * bit 16 tested in one `test dword [rdi+0xc], 0x10200` (0xe7760e) */
    unsigned unknown4 : 9;
    unsigned unknown9 : 1; /* bit 9 */
    unsigned unknown10 : 6;
    unsigned isArray : 1; /* bit 16 */
    unsigned unknown17 : 15;
    u64 unknown8; /* +0x8 */
    /* +0x10: the field's offset in the object (FUN_013ca090: `mov r10d,
     * [r14+0x10]; add r10, r8`) */
    unsigned offset;
    Name name14;                      /* +0x14 */
    Name className;                   /* +0x18 */
    Enumeration00e78f90 *enumeration; /* +0x20 */
};

/* derived names: an entry of a type's table of properties: the name's
 * index, the property and the next entry of its chain. 0x38 bytes. */
struct PropertyNode00cb7e20 {   /* derived name */
    unsigned key;               /* +0x0 */
    Property00e78f90 property;  /* +0x8 */
    PropertyNode00cb7e20 *next; /* +0x30 */
};

/* derived name: the property of a name of a type or of one of its
 * parents, null for none (inlined at FUN_00e774f0: the chains walked from
 * the object's type with no test of it before) */
inline const Property00e78f90 *findProperty(const Type00503fb0 *type, const Name &name)
{
    for (; type; type = type->parent) {
        if (type->propertyChains == 0)
            continue;
        for (const PropertyNode00cb7e20 *node = type->properties[name.index % type->propertyChains];
             node; node = node->next) {
            if (node->key == name.index)
                return &node->property;
        }
    }
    return 0;
}

/* derived names: a type's property of a name, looked up in the type's
 * table and then in each parent's; copied to `property` when found (it may
 * be null) and 1 answered, else 0 (FUN_00cb7e20, leaf_00cb7e20.cpp) */
int FUN_00cb7e20(const Type00503fb0 *type, const Name *name, Property00e78f90 *property);

/* derived names: a reader of one argument of the frame for the script's
 * property calls: its index the argument's offset from the first less the
 * count of arguments; for a value to store, the property it goes to, a
 * mode (1 an element, 2 and 3 a whole value: FUN_00e678b0, FUN_00e66e40,
 * FUN_00e67070) and the element's index, -1 for none */
struct ArgumentReader00c91760 { /* derived name */

    explicit ArgumentReader00c91760(lua_State *state_)
        : state(state_), property(0), mode(0), element(0)
    {
        index = -argumentCount(state_);
    }

    /* a reader of an argument counted from 1 (an index from the top, 0 or
     * less, kept as it is); defined in leaf_00c91760.cpp, not
     * inline: the link inlines it, and FUN_00e66e40's store of the count
     * from 1 before the index from the top (`mov [rbp-0x60], r12d`, then
     * `mov [rbp-0x60], eax`) is what the link's passes leave of the inlined
     * test (its DSE before the IndVarSimplify that proves the argument
     * positive) */
    ArgumentReader00c91760(lua_State *state_, const Property00e78f90 *property_, int argument,
                           int mode_, int element_);

    lua_State *state;                 /* +0x0 */
    const Property00e78f90 *property; /* +0x8 */
    int index;                        /* +0x10 */
    int mode;                         /* +0x14 (derived name) */
    int element;                      /* +0x18 (derived name) */
};

/* derived names: an object and the name of one of its properties, as a
 * script argument hands them over (FUN_00c91760 reads one: from a string,
 * the object its name names; from a user value or a light one, the pair it
 * holds). The pair is let go when it ends: the object cleared, then the
 * name made the empty one (0xe66fc8: `mov qword [rbp-0x88], 0`, then the
 * empty name's count raised before the old one's is dropped) */
struct PropertyHandle00c91760 { /* derived name */

    PropertyHandle00c91760() : object(0) {}

    ~PropertyHandle00c91760()
    {
        object = 0;
        name = Name();
    }

    Object016b9108 *object; /* +0x0 */
    Name name;              /* +0x8 */
    /* +0xc: not read or written by the functions here; the pair's data runs
     * to 16 bytes (the stack protector places the readers, whose 0x1c bytes
     * leave tail padding, above it: 0xe66e40's reader at rbp-0x50, the
     * handle at rbp-0x88) */
    int unknownc;
    void *unknown10; /* +0x10 */
};

void FUN_00c91760(ArgumentReader00c91760 *reader,
                  PropertyHandle00c91760 *handle); /* derived name */

/* derived names: stores the value a reader's argument holds in the
 * property of an object (FUN_013ca090, its body not written; the last
 * argument tested with bit 5 of the flags at 0x13ca451) */
int FUN_013ca090(const Property00e78f90 *property, Object016b9108 *object,
                 ArgumentReader00c91760 *reader, int unknown);

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
