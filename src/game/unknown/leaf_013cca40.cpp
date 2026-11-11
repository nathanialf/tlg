/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 1 of the vtable at 0x16d3428 (also at 0x16d3488 and
 * 0x16d3590), the deleting destructor of a 16-byte class derived from
 * hkReferencedObject (slots 2 to 4 hkReferencedObject's 0x270, 0x42d0 and
 * 0x69a0) whose destructor is empty (slot 0 the shared empty body 0x1af750):
 * the class allocator's delete of the reference-counted classes, the game's
 * own copy of the library's 16-byte body 0x4060 (freeReferencedObject). The
 * class is not traced further. */
class Object013cca40 : public hkReferencedObject /* derived name */
{
  public:
    virtual ~Object013cca40();

    static void operator delete(void *object, unsigned long numBytes)
    {
        freeReferencedObject(object, numBytes);
    }
};

// NONMATCHING: list-ilp order: the base makes the thread-local's general-dynamic call
// (relaxed to `mov rax, fs:[0]; add rax, [GOT]`) before it reads the size at +0x8, keeping
// only rbx; the build reads the size first and keeps r14 and rbx across the call (as
// FUN_00e9a310); the same with the call written as one expression.
Object013cca40::~Object013cca40() {}
