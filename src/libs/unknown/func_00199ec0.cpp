/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

namespace
{
/* A 0x18-byte reference-counted object of this file only (vtable 0x16a67e0,
 * stored by the initializer as the address point 0x16a67f0 itself, the
 * vtable local to the file; slots the shared empty destructor 0x17de10 and
 * the 0x18-byte deleting destructor 0x1ba30, then hkReferencedObject's):
 * a pointer at +0x10, null when built, and the object's own size recorded.
 * Nothing in the executable reads the instance. derived names. */
class Object00199ec0 : public hkReferencedObject
{
  public:
    Object00199ec0() : pointer10(0)
    {
        setMemSize(sizeof(Object00199ec0));
    }

    void *pointer10;
};
} // namespace

/* The static instance (0x57c89a0), built by this file's initializer
 * (0x199ec0); its empty destructor is not registered for exit. */
static Object00199ec0 D_57c89a0;
