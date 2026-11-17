/* src/include/tlg_game_object016ad548.h: the class whose vtable is at
 * 0x16ad548 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD548_H
#define TLG_GAME_OBJECT016AD548_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"
#include "tlg_game_value004af700.h"

/* derived name: the value FUN_0078de30's link is reset to (`mov rax,
 * [0x5818330]; mov rcx, [0x5818338]`, copied member by member) */
extern Value004af700 D_5818330;

/* derived names: a 0x38-byte member of Object016ad548: a pointer and a
 * counted reference, null from its constructor (one memset with the Name
 * before it), an int, a value of four ints, an int and a float that only
 * reset() sets; reset() empties the reference by an exchange, then clears
 * the pointer and the ints, copies the value at 0x5818330 and sets the
 * float to 0.5 (the last two stores merged: `movabs rax,
 * 0x3f00000000000000; mov [r15+0x130], rax`). Not traced further. */
struct Link0078de30 /* derived name */
{
    Link0078de30() : unknown0(0) {}

    void reset() /* derived name */
    {
        held8.clear();
        unknown0 = 0;
        unknown10 = 0;
        unknown20.set(D_5818330);
        unknown30 = 0;
        unknown34 = 0.5f;
    }

    void *unknown0;                          /* +0x0 */
    AtomicRef0045c470<Object016b9108> held8; /* +0x8: released by the holder's destructor */
    int unknown10;                           /* +0x10 */
    u8 unknown14[0xc];
    Value004af700 unknown20; /* +0x20 */
    int unknown30;           /* +0x30 */
    float unknown34;         /* +0x34 */
};

/* derived names: the class whose vtable is at 0x16ad548
 * (config/vtables.derived.base.txt, stored by FUN_0078de30 FUN_0078e010), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0078e010 tears them
 * down (the counted reference at +0x108, the Names at +0x138, +0xfc); the rest are not traced. */
class Object016ad548 : public Object00774560 /* derived name */
{
  public:
    Object016ad548(const Name &name); /* FUN_0078de30 */
    virtual ~Object016ad548();
    virtual void slot14(Pose0077bac0 *pose); /* FUN_00790150 */

  private:
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    /* +0x100: a link, reset by the constructor's body */
    Link0078de30 link100;
    Name name138; /* +0x138: released by the destructor (`mov eax, [rbx+0x138]; shl 5`) */
};

#endif
