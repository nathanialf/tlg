/* src/include/tlg_game_object016b9108kind.h: a class over Object016b9108
 * with an int at +0x24 that its derived classes set (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B9108KIND_H
#define TLG_GAME_OBJECT016B9108KIND_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: a class between Object016b9108 and the classes whose
 * creators clear +0x24 BEFORE their vptr and store their own value there
 * after their other fields (FUN_0057ec00: `mov dword [rbx+0x24], 0` before
 * the vptr, `mov dword [rbx+0x24], 0x6a` last; FUN_0057efb0: 0x6b). No
 * vtable or function of its own is known: its constructor is inlined and its
 * vptr store dies. */
class Object016b9108Kind : public Object016b9108 /* derived name */
{
  public:
    Object016b9108Kind(const Name &name) : Object016b9108(name), kind(0) {}

    virtual ~Object016b9108Kind();

  protected:
    int kind; /* +0x24: 0 from the constructor, a derived class's own value after its fields */
};

#endif
