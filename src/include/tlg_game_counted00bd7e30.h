/* src/include/tlg_game_counted00bd7e30.h: an object shared by reference
 * count with a 32-bit count taken down without a lock (game region;
 * docs/TARGETS.md). Every name here is derived. Its holders drop it with
 * releaseAndClear (tlg_game_shared.h). */
#ifndef TLG_GAME_COUNTED00BD7E30_H
#define TLG_GAME_COUNTED00BD7E30_H

#include "tlg_types.h"

/* derived names: the count at +0x8, an int taken down in place (`mov eax,
 * [rdi+8]; lea ecx, [rax-1]; cmp eax, 1; mov [rdi+8], ecx; jg`), the holder
 * of the last reference deleting the object through slot 1, its deleting
 * destructor (0xbd7e57, 0xbc3b95). The class is not traced further. */
class Counted00bd7e30 /* derived name */
{
  public:
    virtual ~Counted00bd7e30();

    void release() /* derived name */
    {
        if (--references <= 0)
            delete this;
    }

  private:
    int references; /* +0x8 */
};

#endif
