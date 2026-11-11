/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: the destructor of the class of FUN_00cff180's
 * function-local static at 0x5946d88 (its guard at 0x5946d80; registered
 * with __cxa_atexit there): gives back the two direct-memory blocks it
 * holds, the first (its start at +0x0, its length at +0x20) when its start
 * is set, the second (start +0x8, length +0x28) when its length is, and
 * clears each. The other members are not traced. */
class Object00cffd30 /* derived name */
{
  public:
    ~Object00cffd30();

  private:
    long start0; /* +0x0 */
    long start8; /* +0x8 */
    u8 unknown10[0x10];
    unsigned long length20; /* +0x20 */
    unsigned long length28; /* +0x28 */
};

Object00cffd30::~Object00cffd30()
{
    if (start0) {
        sceKernelReleaseDirectMemory(start0, length20);
        start0 = 0;
        length20 = 0;
    }
    if (length28) {
        sceKernelReleaseDirectMemory(start8, length28);
        start8 = 0;
        length28 = 0;
    }
}
