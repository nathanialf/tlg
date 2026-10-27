/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The library's stack tracer (D14's first row): built by this file's static
 * initializer (0x6bf0) and destroyed at exit. */
// NONMATCHING: equal but for the exit registration's `__dso_handle`
// (0x16dc0d8), a symbol the gate does not resolve (docs/NOTES.md, Round 30).
static StackTracer D_57b7b80;
