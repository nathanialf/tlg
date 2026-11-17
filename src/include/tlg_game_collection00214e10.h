/* src/include/tlg_game_collection00214e10.h: a member that resets an
 * Object00214e10 when it is destroyed (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_COLLECTION00214E10_H
#define TLG_GAME_COLLECTION00214E10_H

#include "tlg_types.h"

/* derived names: the class whose complete destructor is 0x2150c0 (its row
 * named for it, D15) as leaf_013f9340.cpp declares it; FUN_00214e10 is its
 * reset (leaf_00793ce0.cpp); FUN_00216780 runs it while its int at +0x8 is
 * set (Object016acb20's slot 14, leaf_00766e50.cpp). Not traced further. */
class Object00214e10 /* derived name */
{
  public:
    virtual ~Object00214e10();
    int FUN_00216780(); /* derived name: not traced */

    int unknown8; /* +0x8 */

  private:
    u8 unknownc[0x2b4];
};

void FUN_00214e10(Object00214e10 *self);

/* derived names: the 0x330-byte member of the classes whose destructors are
 * 0x12ec7e0 (four from +0x5d8) and 0x10351b0 (two from +0x1188): its destructor clears the count at +0x8 and resets the
 * object at +0x18 before that object's destructor runs (0x12ecb21: `mov
 * dword [r14+0xf70], 0`, then FUN_00214e10 and FUN_002150c0 on +0xf80), as
 * Collection013f9340's (leaf_013f9340.cpp). The rest is not traced. */
struct Collection012ec7e0 { /* derived name */

    ~Collection012ec7e0()
    {
        count8 = 0;
        FUN_00214e10(&unknown18);
    }

    u8 unknown0[0x8];
    int count8; /* +0x8 */
    u8 unknownc[0xc];
    Object00214e10 unknown18; /* +0x18 */
    u8 unknown2d8[0x58];
};

#endif
