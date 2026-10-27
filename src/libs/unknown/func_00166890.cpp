/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of hknpMountedBallGun's vtable (address point 0x16a5290): the
 * class adds nothing to destroy, so its destructor is its base's (the
 * compiler emits the complete destructor as a jump to hknpBallGun's). The
 * deleting destructor (slot 1, 0x1668a0) runs hknpBallGun's and frees the
 * object at its recorded size, 0x90 by default. */
hknpMountedBallGun::~hknpMountedBallGun() {}
