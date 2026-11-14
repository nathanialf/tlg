/* src/include/tlg_game_array0081aaf0.h: the unordered removal from an array
 * of exchanged references (game region; docs/TARGETS.md). derived names
 * throughout. The block at +0x0 and the count at +0x8 are the growable
 * array's (tlg_game_array.h), and this is most likely a member of it: kept
 * apart until that header takes it. */
#ifndef TLG_GAME_ARRAY0081AAF0_H
#define TLG_GAME_ARRAY0081AAF0_H

#include "tlg_types.h"
#include "tlg_game_node.h"

template <class T> class Array0081aaf0 /* derived name */
{
  public:
    /* takes the element at `index` out without keeping the order: the last
     * element is assigned over it unless it is the last itself, then the
     * last one is released and the count lowered (FUN_0081aaf0: `mov eax,
     * [r14+8]; dec eax; cmp eax, esi; jbe`, the exchange of the two
     * references, then the block and the count read again and `dec dword
     * [r14+8]` at the end) */
    void removeUnordered(unsigned index) /* derived name */
    {
        unsigned last = count - 1;
        if (index < last) {
            T &element = data[index];
            element = data[last];
        }
        data[count - 1].release();
        --count;
    }

  private:
    T *data;        /* +0x0 */
    unsigned count; /* +0x8 */
};

#endif
