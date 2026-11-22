/* src/include/tlg_game_links00c63970.h: the links an object holds by name
 * and their removal through the links at +0xd0 of the object at 0x5938c40
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_LINKS00C63970_H
#define TLG_GAME_LINKS00C63970_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b9108.h"

/* derived names: one link of a linked object: two names, whose addresses
 * FUN_00c63970 takes, and how many times the pair is linked (the u32 at
 * +0x8 read once for the inner loop: `mov r14d, [rax+rcx*4+8]`). 12 bytes
 * (`lea rcx, [rcx+rcx*2]` over four-byte words). */
struct Link00c63970 { /* derived name */
    Name first;       /* +0x0 */
    Name second;      /* +0x4 */
    unsigned count;   /* +0x8 */
};

/* derived names: an object that holds links, as the destructors that take
 * them out read it: the links an array at +0x28 (the block at +0x28, the
 * count at +0x30); the rest is not traced */
class Linked00c63970 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x28 - 0x24];
    Array01343a80<Link00c63970> links; /* +0x28 */
};

/* derived name: takes one link of the pair out of the object the reference
 * holds (1,186 bytes, not written: it reads the reference's object and its
 * count at +0x30 first) */
void FUN_00c63970(Links05938c40 *links, const Name *first, const Name *second,
                  AtomicRef0045c470<Object016b9108> *reference);

/* derived name: the list of links the pointer at 0x59396d0 holds
 * (Object016acbe8's slot 15 takes its object's links out of it) */
extern Links05938c40 *D_59396d0;

/* derived name: every link of the object a reference holds taken out, last
 * first, each as many times as it is counted: the links at +0xd0 of the
 * object at 0x5938c40 read once, after the tests (`mov rsi, [0x5938c40]`
 * after `dec ecx; js`: passed in as an argument, the two loads are sunk
 * there and take each other's registers with the object's), the held object
 * read again for each link (`mov rax, [r12]` at the top of the outer loop,
 * 0x2962e0 and 0xad5e20), the counter signed (`dec ecx; js`) */
inline void unlinkAll(AtomicRef0045c470<Object016b9108> &reference) /* derived name */
{
    const Linked00c63970 *linked = static_cast<const Linked00c63970 *>(reference.get());
    if (linked && linked->links.size() != 0) {
        Links05938c40 *links = D_5938c40->links;
        for (int i = linked->links.size() - 1; i >= 0; --i) {
            const Link00c63970 &link =
                static_cast<const Linked00c63970 *>(reference.get())->links.at(i);
            for (unsigned n = link.count; n != 0; --n)
                FUN_00c63970(links, &link.first, &link.second, &reference);
        }
    }
}

#endif
