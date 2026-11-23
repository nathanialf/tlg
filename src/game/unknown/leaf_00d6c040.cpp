/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the object this thread's pointer at 0x16dc0b8 holds: its
 * flags at +0x84 and its slot 5 */
class Thread00d6c040 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */

    u8 unknown8[0x7c];
    unsigned flags84; /* +0x84: bits 0, 3 and 4 tested here */
};

/* derived names: the object the pointer at 0x5989c08 holds: its flags at
 * +0x100 (bits 1 and 2 tested here) */
struct Settings00d6c040 { /* derived name */
    u8 unknown0[0x100];
    u8 flags100; /* +0x100 */
};

extern __thread Thread00d6c040 *D_16dc0b8; /* derived name */
extern Settings00d6c040 *D_5989c08;

/* derived name: the function of the job FUN_00d6c0a0 hands FUN_00d680b0
 * (stored at 0xd6c457; its task is not read): this thread's object runs its
 * slot 5 unless bit 0 of its flags is set, or bit 3 is and the setting's
 * bit 1, or bit 4 is clear and the setting's bit 2 is set */
void FUN_00d6c040(void *task)
{
    Thread00d6c040 *thread = D_16dc0b8;
    const unsigned flags = thread->flags84;
    if (flags & 1)
        return;
    if ((flags & 8) && (D_5989c08->flags100 & 2))
        return;
    if (!(flags & 0x10) && (D_5989c08->flags100 & 4))
        return;
    thread->slot5();
}
