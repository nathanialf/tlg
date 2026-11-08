/* src/libs/havok/Common/Base/System/Hardware/hkHardwareInfo.cpp: the file its
 * report names (config/homes.base.txt, _ZN14hkHardwareInfoC1Ev). */
#include "tlg_lib_unknown.h"
#include <cpuid.h>

/* Not claimed: equal instruction for instruction under tools/quick_diff.sh,
 * but its vtable 0x16a32a0 (slots 0x8c0a0, 0x1ba30, 0x270, 0x42d0, 0x69a0;
 * no type info) has no row in either vtables file, a D14 ruling for the
 * supervisor. */
/* Six threads, and the processor's features read through CPUID when its
 * vendor is Intel or AMD (leaf 7 only on Intel); another vendor is
 * reported. */
hkHardwareInfo::hkHardwareInfo() : numThreads(6), cpuFeatures(CPU_DEFAULT)
{
    unsigned int maxLevel, vendorB, vendorC, vendorD;
    __get_cpuid(0, &maxLevel, &vendorB, &vendorC, &vendorD);
    /* The vendor's twelve characters are ebx, edx and ecx in turn. */
    char vendor[32];
    u32 *vendorWords = reinterpret_cast<u32 *>(vendor);
    vendorWords[0] = vendorB;
    vendorWords[1] = vendorD;
    vendorWords[2] = vendorC;
    vendorWords[3] = 0;
    const bool isIntel = FUN_00017f40(vendor, "GenuineIntel") == 0;
    const bool isAmd = FUN_00017f40(vendor, "AuthenticAMD") == 0;
    if (isIntel || isAmd) {
        unsigned int eax, ebx, ecx, edx;
        __get_cpuid(1, &eax, &ebx, &ecx, &edx);
        cpuFeatures |= (edx & (1 << 8)) ? CPU_CX8 : 0;
        cpuFeatures |= (edx & (1 << 15)) ? CPU_CMOV : 0;
        cpuFeatures |= (edx & (1 << 19)) ? CPU_CLFLUSH : 0;
        cpuFeatures |= (edx & (1 << 25)) ? CPU_SSE : 0;
        cpuFeatures |= (edx & (1 << 26)) ? CPU_SSE2 : 0;
        cpuFeatures |= (edx & (1 << 23)) ? CPU_MMX : 0;
        cpuFeatures |= (ecx & (1 << 0)) ? CPU_SSE3 : 0;
        cpuFeatures |= (ecx & (1 << 1)) ? CPU_PCLMULQDQ : 0;
        cpuFeatures |= (ecx & (1 << 9)) ? CPU_SSSE3 : 0;
        cpuFeatures |= (ecx & (1 << 13)) ? CPU_CX16 : 0;
        cpuFeatures |= (ecx & (1 << 19)) ? CPU_SSE41 : 0;
        cpuFeatures |= (ecx & (1 << 20)) ? CPU_SSE42 : 0;
        cpuFeatures |= (ecx & (1 << 22)) ? CPU_MOVBE : 0;
        cpuFeatures |= (ecx & (1 << 23)) ? CPU_POPCNT : 0;
        cpuFeatures |= (ecx & (1 << 25)) ? CPU_AES : 0;
        cpuFeatures |= (ecx & (1 << 12)) ? CPU_FMA : 0;
        cpuFeatures |= (ecx & (1 << 28)) ? CPU_AVX : 0;
        cpuFeatures |= (ecx & (1 << 29)) ? CPU_F16C : 0;
        __get_cpuid(0x80000001, &eax, &ebx, &ecx, &edx);
        cpuFeatures |= (ecx & (1 << 5)) ? CPU_LZCNT : 0;
    }
    if (isIntel) {
        if (maxLevel >= 7) {
            unsigned int eax, ebx, ecx, edx;
            __get_cpuid(7, &eax, &ebx, &ecx, &edx);
            cpuFeatures |= (ebx & (1 << 5)) ? CPU_AVX2 : 0;
            cpuFeatures |= (ebx & (1 << 3)) ? CPU_BMI1 : 0;
            cpuFeatures |= (ebx & (1 << 8)) ? CPU_BMI2 : 0;
        }
    } else if (!isAmd) {
        char assertBuf[512];
        BufferOstream ostr(assertBuf, sizeof(assertBuf));
        ostr.FUN_00008440("CPU vendor information's ('")
            .FUN_00008440(vendor)
            .FUN_00008440("') not recognized.");
        hkError::FUN_00014c70(0x4fa4b98c, assertBuf, HK_HARDWARE_INFO_CPP, 154);
    }
}
