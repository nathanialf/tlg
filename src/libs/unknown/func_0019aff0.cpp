/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Each class brought up to the version, then its member offsets (and its
 * members' classes') computed under the host's layout, one map keeping the
 * classes done. */
void FUN_0019aff0(const hkClass *const *classes, int classVersion)
{
    FUN_0019f270(classes, classVersion);
    Layout00180ef0 layout;
    FUN_00180ee0(&layout);
    OwnedPointerMap classesDone; /* derived name */
    for (const hkClass *const *klass = classes; *klass; klass++) {
        layout.FUN_00180f00(const_cast<hkClass &>(**klass), classesDone, 1);
    }
}
