/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_lib_unknown.h"

/* The router built, flush-to-zero turned on, the router handed to the memory
 * system under the class's name and made the thread's, then the thread's
 * number kept. */
hkWorkerThreadContext::hkWorkerThreadContext(int threadNumber)
{
    _mm_setcsr(_mm_getcsr() | _MM_FLUSH_ZERO_ON);
    FUN_00006c50()->threadInit(memoryRouter, "hkWorkerThreadContext", 3);
    FUN_00009a60(&memoryRouter);
    D_16dc068 = threadNumber;
}
