/* src/include/tlg_game_object016b7e70.h: the class whose vtable is at
 * 0x16b7e70 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7E70_H
#define TLG_GAME_OBJECT016B7E70_H

#include "tlg_game_block.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b7e70 (two slots: the
 * complete destructor 0xc13c70 and the deleting one 0xc13dc0), 0x58 bytes:
 * its objects live on their users' stacks (FUN_0059e8d0 at -0xe0 and -0x88)
 * and in other objects (FUN_0059d8f0). Its fields are traced only where the
 * destructor reads them: flag 2 at +0x8 says the block at +0x38 is its own;
 * a counted reference at +0x10 and a block at +0x18 its members. */
class Object016b7e70 /* derived name */
{
  public:
    virtual ~Object016b7e70();

  private:
    /* the fields emptied (0xc13c84 to 0xc13cee): the own block given back
     * first, then the sizes, the flags and the three words from +0x40 */
    void reset() /* derived name */
    {
        if ((flags8 & 2) && block38) {
            FUN_00ebf3f0(block38);
            block38 = 0;
        }
        size20 = 0;
        unknown30 = 0;
        flags8 = 0;
        unknown40 = 0;
        unknown48 = 0;
        unknown50 = 0;
    }

    unsigned flags8;                    /* +0x8 */
    Ref00503fb0<Object016b9108> held10; /* +0x10 */
    OwnedBlock05943280 block18;         /* +0x18 */
    unsigned size20;                    /* +0x20 */
    u8 unknown24[0xc];
    int unknown30;   /* +0x30 */
    void *block38;   /* +0x38: released by reset() when flag 2 is set */
    void *unknown40; /* +0x40 */
    void *unknown48; /* +0x48 */
    void *unknown50; /* +0x50 */
};

#endif
