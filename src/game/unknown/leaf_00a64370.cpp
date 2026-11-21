/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b6bc8.h"
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16b22e0
 * (config/vtables.derived.base.txt; its constructor 0xa64050 registers the
 * Subtitle_ script C functions through FUN_00c87e30), over Object016c81c0,
 * with the subtitles' object at +0x98 (the one the pointer at 0x5828450 holds
 * for the C functions: leaf_00a645a0.cpp, leaf_00a64680.cpp; its functions
 * 0xb728c0 to 0xb738b0, its destructor 0xb724e0, the class at 0x16b6bc8,
 * tlg_game_object016b6bc8.h).
 * The destructor (0xa64370;
 * its deleting one 0xa64410) stops the member (0xb728c0), takes the four C
 * functions' names back from the script registry at +0x40 of the object the
 * pointer at 0x5938c40 holds (FUN_00c89a10, as leaf_00a07bd0.cpp, the
 * registry read once and not tested), and clears the pointer to the member. */
struct Registry05938c40_40; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x40];
    Registry05938c40_40 *unknown40; /* +0x40 */
};

extern Object05938c40 *D_5938c40;

void FUN_00c89a10(Registry05938c40_40 *registry, const char *name); /* derived name */

extern Object016b6bc8 *D_5828450;

class Object016b22e0 : public Object016c81c0 /* derived name */
{
  public:
    virtual ~Object016b22e0();

  private:
    Object016b6bc8 subtitles; /* +0x98 */
};

Object016b22e0::~Object016b22e0()
{
    subtitles.FUN_00b728c0();
    Registry05938c40_40 *registry = D_5938c40->unknown40;
    FUN_00c89a10(registry, "Subtitle_Start");
    FUN_00c89a10(registry, "Subtitle_End");
    FUN_00c89a10(registry, "Subtitle_PreLoad");
    FUN_00c89a10(registry, "Subtitle_SetParam");
    D_5828450 = 0;
}
