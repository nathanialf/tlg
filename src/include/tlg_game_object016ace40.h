/* src/include/tlg_game_object016ace40.h: the class whose vtable is at
 * 0x16ace40 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACE40_H
#define TLG_GAME_OBJECT016ACE40_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"
#include "tlg_game_link0079ab40.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16ace40
 * (config/vtables.derived.base.txt, stored by FUN_00775ec0 FUN_00776130), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_00776130 tears them
 * down (the counted references at +0x138, +0x108, the Name at +0xfc), the others where its constructor FUN_00775ec0 sets
 * them. 0x170 bytes (`mov edi, 0x170` before operator new in its creator
 * FUN_00775d60). */
class Object016ace40 : public Object00774560 /* derived name */
{
  public:
    Object016ace40(const Name &name); /* FUN_00775ec0 */
    virtual ~Object016ace40();
    virtual void slot14(Pose0077bac0 *pose);       /* FUN_00777b10 */
    virtual void slot17(Context0079c700 *context); /* FUN_00777cb0 */

  private:
    u8 unknowne8[0x14];
    Name namefc;      /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    void *unknown100; /* +0x100: null from the constructor; not traced */
    /* +0x108: a counted reference another thread may replace, emptied by
     * compare-and-swap by the constructor, released by the destructor (the
     * pointer cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    AtomicRef0045c470<Target00777cb0> held108;
    int unknown110; /* +0x110: zero from the constructor; not traced */
    u8 unknown114[0xc];
    /* +0x120: (0, 0, 0, 1.0) from the constructor, one aligned store
     * (`vmovaps [r15+0x120]`); not traced */
    Float4A unknown120;
    void *unknown130; /* +0x130: null from the constructor; not traced */
    /* +0x138: a counted reference another thread may replace, emptied by
     * compare-and-swap by the constructor, released by the destructor (the
     * pointer cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    AtomicRef0045c470<Object016b9108> held138;
    int unknown140; /* +0x140: zero from the constructor; not traced */
    u8 unknown144[0xc];
    /* +0x150: (0, 0, 0, 1.0) from the constructor, one aligned store
     * (`vmovaps [r15+0x150]`); not traced */
    Float4A unknown150;
    int unknown160;     /* +0x160: handed to the body's tracker by slot 17 */
    u8 unknown164[0xc]; /* the rest of the 0x170 bytes the creator allocates; not traced */
};

#endif
