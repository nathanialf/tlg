/* src/include/tlg_game_object00bc1a50.h: FUN_00b8e610's object (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00BC1A50_H
#define TLG_GAME_OBJECT00BC1A50_H

#include "tlg_game_shared.h"

/* derived names: FUN_00b8e610's object (FUN_00bc1a50 called at 0xb8eedb
 * with the object itself, and by FUN_00b91750 at 0xb91ad6; FUN_00bc15b0 at
 * 0xb8ec08, and by FUN_00b997d0 at 0xb99dcf): ten references to shared
 * objects at +0x3b70 to +0x3bb8, three sets of four at +0x4118, +0x4138 and
 * +0x4158 and nine more at +0x4178 to +0x41b8, the objects' class not
 * traced. The other fields are not traced. */
class Object00bc1a50 /* derived name */
{
  public:
    void releaseShared();     /* derived name */
    void releaseSharedSets(); /* derived name */

  private:
    u8 unknown0[0x3b70];
    SharedRef00901550<Shared00901550> shared3b70; /* +0x3b70 */
    SharedRef00901550<Shared00901550> shared3b78; /* +0x3b78 */
    SharedRef00901550<Shared00901550> shared3b80; /* +0x3b80 */
    SharedRef00901550<Shared00901550> shared3b88; /* +0x3b88 */
    SharedRef00901550<Shared00901550> shared3b90; /* +0x3b90 */
    SharedRef00901550<Shared00901550> shared3b98; /* +0x3b98 */
    SharedRef00901550<Shared00901550> shared3ba0; /* +0x3ba0 */
    SharedRef00901550<Shared00901550> shared3ba8; /* +0x3ba8 */
    SharedRef00901550<Shared00901550> shared3bb0; /* +0x3bb0 */
    SharedRef00901550<Shared00901550> shared3bb8; /* +0x3bb8 */
    u8 unknown3bc0[0x558];
    SharedRef00901550<Shared00901550> sharedA[4]; /* +0x4118 */
    SharedRef00901550<Shared00901550> sharedB[4]; /* +0x4138 */
    SharedRef00901550<Shared00901550> sharedC[4]; /* +0x4158 */
    SharedRef00901550<Shared00901550> shared4178; /* +0x4178 */
    SharedRef00901550<Shared00901550> shared4180; /* +0x4180 */
    SharedRef00901550<Shared00901550> shared4188; /* +0x4188 */
    SharedRef00901550<Shared00901550> shared4190; /* +0x4190 */
    SharedRef00901550<Shared00901550> shared4198; /* +0x4198 */
    SharedRef00901550<Shared00901550> shared41a0; /* +0x41a0 */
    SharedRef00901550<Shared00901550> shared41a8; /* +0x41a8 */
    SharedRef00901550<Shared00901550> shared41b0; /* +0x41b0 */
    SharedRef00901550<Shared00901550> shared41b8; /* +0x41b8 */
};

#endif
