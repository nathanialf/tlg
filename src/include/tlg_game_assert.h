/* src/include/tlg_game_assert.h: the engine's assertion. A failed check
 * formats "<file>(<line>): <function>() ASSERT(<expression>)" into a 512-byte
 * buffer, hands it to the report handler with the kind "ASSERT" when one is
 * set, else prints it, then traps (`__builtin_debugtrap()`, `int 0x41` on the
 * game's target): the sites of 0x139ddf0, 0x139ded0 and FUN_00b8a480. The
 * file and line are the original source's, as its strings name them (the
 * tree's paths and lines are not the original's), so they are the macro's
 * arguments; the function is __FUNCTION__, the name the report gives.
 *
 * The handler D_5ace510 is stored once in the executable, with FUN_00b8a440,
 * by FUN_00b8a480 (CreateDevice, func_00b8a480.cpp), and every other access
 * tests it for null: a pointer local to the optimiser and stored once
 * (config/local_data.base.txt, tools/module_boundary.py), whose calls the
 * link's GlobalOpt makes direct and its inliner inlines.
 *
 * The report is a function of its own unit (anzu_assert.cpp) that the link
 * inlines at every site: a call after a check is a tail call in the base
 * (0x13003d0 and 0x13005d0 `jmp` to memcpy, 0x12ff060 to the base
 * destructor), which the unit's own pipeline marks only where no local's
 * address has escaped on a path to it (llvm-3.7.1
 * TailRecursionElimination.cpp:251-370; the link's pipeline has no such
 * pass, PassManagerBuilder.cpp:430-527). The report's buffer, written in the
 * macro, escapes to the handler on every check's path; in the report's own
 * function, the site's unit holds no buffer. */
#ifndef TLG_GAME_ASSERT_H
#define TLG_GAME_ASSERT_H

#include "tlg_types.h"

#include "tlg_libc.h"

typedef void (*AssertHandler)(const char *message, const char *kind); /* derived name */

extern AssertHandler D_5ace510; /* derived name: the report's handler */

/* derived name: the handler CreateDevice stores, reporting through the
 * thread's report object (leaf_00b8a440.cpp) */
void FUN_00b8a440(const char *message, const char *kind);

/* derived name: the report of a failed check: the 512-byte message, the
 * handler or puts (anzu_assert.cpp) */
void AnzuAssertFailed(const char *file, long line, const char *function, const char *condition);

#define ANZU_ASSERT(file, line, condition) /* derived name */                                      \
    do {                                                                                           \
        if (!(condition)) {                                                                        \
            AnzuAssertFailed(file, line, __FUNCTION__, #condition);                                \
            __builtin_debugtrap();                                                                 \
        }                                                                                          \
    } while (0)

#endif
