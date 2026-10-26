/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The size of what each type of record carries between its entries and its
 * tail (derived name): types 3 and 4 carry 144 bytes (FUN_0002b040 scales
 * floats in them for types from 3), the others nothing. */
static const int D_14b8690[5] = {0, 0, 0, 144, 144};

/* derived name: the address of what follows the record's entries and its
 * type's extra bytes (the byte offset is an int). */
Pair08Tail *FUN_0002af30(const Pair08Owner *self) /* derived name */
{
    int offset = sizeof(Pair08Owner) + self->count * sizeof(Pair08Entry) + D_14b8690[self->type];
    return reinterpret_cast<Pair08Tail *>(const_cast<char *>(reinterpret_cast<const char *>(self)) +
                                          offset);
}
