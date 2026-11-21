/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: an object with an array of ints at +0xe8, called by
 * FUN_001b3180. FUN_00a1c8e0 makes the array `count` zeros when its count
 * differs (the array made that size, then each element cleared, the count
 * and the block read again at each one). Nothing else of the object is
 * traced. */
class Object00a1c8e0 /* derived name */
{
  public:
    void FUN_00a1c8e0(unsigned count);

  private:
    u8 unknown0[0xe8];
    Array05943280<u32> valuese8; /* +0xe8 */
};

void Object00a1c8e0::FUN_00a1c8e0(unsigned count)
{
    if (valuese8.size() != count) {
        valuese8.resize(count);
        for (unsigned i = 0; i < valuese8.size(); ++i)
            valuese8[i] = 0;
    }
}
