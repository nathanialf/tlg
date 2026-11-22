/* src/include/tlg_game_animationcamera.h: AnimationCamera, the class whose
 * vtable is at 0x16b46c8 (game region; docs/TARGETS.md). The class's name
 * is its messages'; every other name here is derived. */
#ifndef TLG_GAME_ANIMATIONCAMERA_H
#define TLG_GAME_ANIMATIONCAMERA_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016c7d08.h"

/* AnimationCamera (the class's name from its messages
 * "AnimationCamera(%s)::Init" and "AnimationCamera(%s)::Term"), its vtable
 * at 0x16b46c8 (config/vtables.derived.base.txt; stored by FUN_00afa2f0 and
 * its complete destructor FUN_00afa590, leaf_00afa590.cpp). Its base's
 * destructor FUN_00afd410 is Object016c7d08's (tlg_game_object016c7d08.h);
 * the name at +0xc is the root class's. Slot 5 is FUN_00afa950
 * (leaf_00afa950.cpp). Its fields are traced where Init sets them and the
 * destructor tears them down: names at +0x14c, +0x150 and +0x158, counted
 * references at +0x168, +0x1a0 and +0x1a8, and the reference at +0x1b8
 * another thread may replace. */
class AnimationCamera : public Object016c7d08
{
  public:
    virtual ~AnimationCamera();

    u8 unknown60[0xec];
    Name name14c; /* +0x14c */
    Name name150; /* +0x150 */
    u8 unknown154[0x4];
    Name name158; /* +0x158 */
    u8 unknown15c[0xc];
    Ref00503fb0<Object016b9108> held168; /* +0x168 */
    u8 unknown170[0x30];
    Ref00503fb0<Object016b9108> held1a0; /* +0x1a0 */
    Ref00503fb0<Object016b9108> held1a8; /* +0x1a8 */
    u8 unknown1b0[0x8];
    AtomicRef0045c470<Object016b9108> held1b8; /* +0x1b8 */
};

#endif
