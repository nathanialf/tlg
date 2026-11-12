/* src/include/tlg_game_object016d0698.h: the class whose vtable is at
 * 0x16d0698 (config/vtables.derived.base.txt, stored by FUN_00c23dd0
 * FUN_013a2910 FUN_013a2a00), moved from leaf_013a2910.cpp, which defines
 * its destructor (the key function, so that file emits the vtable);
 * leaf_00c23dd0.cpp defines its constructor. derived names throughout. */
#ifndef TLG_GAME_OBJECT016D0698_H
#define TLG_GAME_OBJECT016D0698_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: derived from Object016b9108: its slots 2 to 4 are the
 * base's. Its own fields from +0x24 are the two Names the constructor
 * clears together (`mov qword [rbx+0x24], 0`) and the destructor releases,
 * last first; the rest of the class is not traced. */
class Object016d0698 : public Object016b9108 /* derived name */
{
  public:
    Object016d0698(const Name &name); /* FUN_00c23dd0 */
    virtual ~Object016d0698();        /* FUN_013a2910 */

  private:
    Name name24;    /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name texture28; /* +0x28: derived name, after the constructor's string "_black_texture" */
};

#endif
