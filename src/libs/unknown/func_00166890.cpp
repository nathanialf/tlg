/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of hknpMountedBallGun's vtable (address point 0x16a5290): the
 * class adds nothing to destroy, so its destructor is its base's (the
 * compiler emits the complete destructor as a jump to hknpBallGun's). */
hknpMountedBallGun::~hknpMountedBallGun() {}
