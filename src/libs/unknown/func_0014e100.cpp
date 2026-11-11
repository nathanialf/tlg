/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The larger object's destructor body (0x14e100): the tasks released from
 * the last, then the arrays, the members' own destructors. The base's
 * complete destructor 0x14e0a0 is a lone jump to it and the deleting one
 * 0x14e0b0 sits between them, the layout of an inline destructor emitted
 * with the vtable in the key function's file (cookbook 441): it moves into
 * the file of slot 2 (0x150330) when that is written. */
hknpWorldObject1d0Large::~hknpWorldObject1d0Large() {}
