/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_lib_unknown.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d34d0 (config/vtables.derived.base.txt), over hkReferencedObject
 * (slots 2 to 4 are its 0x270, 0x42d0 and 0x69a0), 0x28 bytes: it stores the vtable and releases
 * the block the pointer at +0x10 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable and the deleting
 * one, FUN_013cc950, which holds this body (the release inlined by the
 * link). The other members are not traced. */
class Object013cc900 : public hkReferencedObject /* derived name */
{
  public:
    virtual ~Object013cc900();

    /* the reference-counted classes' delete: FUN_013cc950, slot 1, frees
     * at the recorded size or 0x28 */
    // NONMATCHING: FUN_013cc950 (the deleting destructor, 142 bytes as the base's): leaf_013cca40.cpp's
    // list-ilp order: the base keeps only rbx across the thread-local's call and reads the size into
    // ecx after it; the build keeps r14 and rbx (the size in ebx).
    static void operator delete(void *object, unsigned long numBytes)
    {
        freeReferencedObject(object, numBytes);
    }

  private:
    void *unknown10; /* +0x10: owned block */
    u8 unknown18[0x10];
};

Object013cc900::~Object013cc900()
{
    FUN_00ebf3f0(unknown10);
}
