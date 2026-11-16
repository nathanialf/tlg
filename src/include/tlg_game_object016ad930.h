/* src/include/tlg_game_object016ad930.h: the class whose vtable is at
 * 0x16ad930 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD930_H
#define TLG_GAME_OBJECT016AD930_H

#include "tlg_game_link0079ab40.h"
#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad930
 * (config/vtables.derived.base.txt, stored by FUN_0079ab40 FUN_0079adb0), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0079adb0 tears them
 * down (the counted references at +0x138, +0x108, the Name at +0xfc); the rest are not traced. */
class Object016ad930 : public Object00774560 /* derived name */
{
  public:
    Object016ad930(const Name &name); /* FUN_0079ab40 */
    virtual ~Object016ad930();
    virtual void slot14(Pose0077bac0 *pose);       /* FUN_0079c560 */
    virtual void slot17(Context0079c700 *context); /* FUN_0079c700 */

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    /* +0x100, +0x130: two links, each reset by the constructor's body */
    Link0079ab40 link100;
    Link0079ab40 link130;
    int unknown160;     /* +0x160: handed to the body's tracker by slot 17 */
    u8 unknown164[0xc]; /* the rest of the 0x170 bytes the creator allocates; not traced */
};

#endif
