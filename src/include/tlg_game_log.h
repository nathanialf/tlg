/* src/include/tlg_game_log.h: the game's debug text output. derived names
 * throughout. FUN_00c831d0 formats a message into a 4 KiB buffer and hands
 * it to the output object at 0x17ac798; 380 call sites across the region
 * call it, 378 of them without setting its first argument, which it never
 * reads (DeadArgumentElimination replaces an unused argument by undef at the
 * call sites of a function defined in the module, D50 addendum). */
#ifndef TLG_GAME_LOG_H
#define TLG_GAME_LOG_H

#include "tlg_types.h"

/* The output's interface as the vtable at 0x16b8980 lays it out (the object
 * at 0x17ac798 holds its address point 0x16b8990): slots 0 and 1 the
 * destructors (an empty one at 0x1af750, PlainPolymorphic's deleting one at
 * 0x21a00), slot 2 returns the address of a float table (FUN_013aab40),
 * slots 3 to 5 empty (0x1af750), slot 6 writes text with its length
 * (FUN_00c831c0). The class of the object itself is not traced. */
class DebugOutput /* derived name */
{
  public:
    virtual ~DebugOutput();
    virtual const float *unknown2() const;
    virtual void unknown3();
    virtual void unknown4();
    virtual void unknown5();
    virtual void write(int channel, const char *text, int length);
};

extern DebugOutput D_17ac798;

/* The game's output, reached as its interface. */
inline DebugOutput &debugOutput() /* derived name */
{
    return D_17ac798;
}

/* The caller's object comes first and is not read; its type is not traced. */
void FUN_00c831d0(const void *source, const char *format, ...); /* derived name */

#endif
