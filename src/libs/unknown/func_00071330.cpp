/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Contact caching neither requested nor supported (derived name). */
static inline void disableContactCaching(hknpBodyQuality &quality)
{
    quality.requestedFlags &= ~0x400;
    quality.supportedFlags &= ~0x400;
}

void hknpBodyQualityLibrary::FUN_00071330(const hknpBodyQualityLibraryCinfo &cinfo)
{
    const u32 contactCaching = cinfo.enableContactCaching ? 0x400 : 0;
    for (int i = 0; i < 32; i++) {
        hknpBodyQuality &quality = qualities[i];
        quality.FUN_0016a380(cinfo.unitScale);
        quality.priority = i * 10;
        quality.supportedFlags = (quality.supportedFlags & ~0x400) | contactCaching;
    }

    qualities[0].supportedFlags &= ~0x800;

    qualities[1].supportedFlags &= ~0x10050;
    qualities[1].requestedFlags |= contactCaching | 0x61808;
    qualities[1].contactCachingRelativeMovementThreshold = 0.2f;

    qualities[2].supportedFlags &= ~0x10050;
    qualities[2].requestedFlags |= contactCaching | 0x61a08;
    qualities[2].contactCachingRelativeMovementThreshold = 0.2f;

    qualities[3].requestedFlags |= contactCaching | 0x20800;
    if (cinfo.enableWeldingForDefaultObjects) {
        qualities[3].requestedFlags |= 0x20880;
    } else {
        qualities[3].requestedFlags |= 0x20808;
    }

    qualities[4].requestedFlags |= contactCaching | 0x20880;

    qualities[6].requestedFlags |= contactCaching | 0x20a08;

    qualities[5].requestedFlags |= 0x20902;
    disableContactCaching(qualities[5]);

    qualities[7].requestedFlags |= contactCaching | 0x10040;
    qualities[7].contactCachingRelativeMovementThreshold = 0.01f;
    if (cinfo.enableWeldingForCriticalObjects) {
        qualities[7].requestedFlags |= 0x82;
    }

    disableContactCaching(qualities[8]);
    qualities[8].requestedFlags |= 0x100;

    disableContactCaching(qualities[9]);
    qualities[9].requestedFlags |= 0x80;

    disableContactCaching(qualities[10]);
    qualities[10].requestedFlags |= 0x10180;

    disableContactCaching(qualities[11]);
    qualities[11].requestedFlags |= 0x10102;
}
