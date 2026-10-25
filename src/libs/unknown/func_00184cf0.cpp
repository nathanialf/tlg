/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: reads the processor's time-stamp counter with rdtscp, the
 * high half in edx and the low in eax joined into 64 bits; the processor id
 * rdtscp leaves in ecx is not kept. The instruction is written as inline
 * assembly because that is the only way this compiler emits it: LLVM 3.3 has
 * no rdtscp intrinsic (X86InstrSystem.td:22 defines the instruction with no
 * selection pattern, IntrinsicsX86.td has no int_x86_rdtscp, clang 3.3 has no
 * __rdtscp header); the asm is the function's own instruction, ruled in
 * tools/dev_native_allow.txt. */
u64 FUN_00184cf0() /* derived name */
{
    unsigned int low;
    unsigned int high;
    __asm__ __volatile__("rdtscp" : "=a"(low), "=d"(high) : : "rcx");
    return (static_cast<u64>(high) << 32) | low;
}
