/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: whether packfile data can be loaded on this platform: its
 * magic, its layout rules against the host's, its alignment and its
 * contents version against the current one; on failure the reason is
 * stored when asked for. Its one caller is the in-place loader (0x17e388). */
hkResult FUN_0017dec0(const void *packfileData, const char **errorOut) /* derived name */
{
    if (packfileData == HK_NULL) {
        if (errorOut) {
            *errorOut = "Pointer is null";
        }
        return HK_FAILURE;
    }
    const hkPackfileHeader *header = static_cast<const hkPackfileHeader *>(packfileData);
    const hkPackfileHeader magic;
    if (header->magic[0] != magic.magic[0] || header->magic[1] != magic.magic[1]) {
        if (errorOut) {
            *errorOut = "Missing packfile magic header. Is this from a binary file?";
        }
        return HK_FAILURE;
    }
    if (header->layoutRules[0] != D_14cb8f6.bytesInPointer) {
        if (errorOut) {
            *errorOut = "Trying to process a binary file with a different pointer size than this "
                        "platform.";
        }
        return HK_FAILURE;
    }
    if (header->layoutRules[1] != D_14cb8f6.littleEndian) {
        if (errorOut) {
            *errorOut = "Trying to process a binary file with a different endian than this "
                        "platform.";
        }
        return HK_FAILURE;
    }
    if (header->layoutRules[2] != D_14cb8f6.reusePadding) {
        if (errorOut) {
            *errorOut = "Trying to process a binary file with a different padding optimization "
                        "than this platform.";
        }
        return HK_FAILURE;
    }
    if (header->layoutRules[3] != D_14cb8f6.emptyBaseOptimization) {
        if (errorOut) {
            *errorOut = "Trying to process a binary file with a different empty base class "
                        "optimization than this platform.";
        }
        return HK_FAILURE;
    }
    if ((hkUlong(packfileData) & 3) != 0) {
        if (errorOut) {
            *errorOut = "Packfile data source needs to be 4 byte aligned";
        }
        return HK_FAILURE;
    }
    if (header->contentsVersion[0] == -1) {
        if (errorOut) {
            *errorOut = "Packfile file format is too old";
        }
        return HK_FAILURE;
    }
    if (FUN_00017f40(header->contentsVersion, FUN_0019afc0()) != 0) {
        if (errorOut) {
            *errorOut = "Packfile contents are not up to date";
        }
        return HK_FAILURE;
    }
    return HK_SUCCESS;
}
