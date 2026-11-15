/* src/include/tlg_game_object016ab9d8.h: the class whose vtable is at
 * 0x16ab9d8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB9D8_H
#define TLG_GAME_OBJECT016AB9D8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab9d8
 * (config/vtables.derived.base.txt, stored by FUN_005aa770 FUN_005aaf20), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced where its creator FUN_005aa770 sets them and its
 * destructor FUN_005aaf20 tears them down (the Names at +0x40, +0x2c,
 * +0x28). 0x60 bytes (`mov edi, 0x60` before operator new). */
class Object016ab9d8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_005aa770: the base built from the name, the
     * vptr, the three names empty; then the body: the ints from +0x24 and
     * -1.0 at +0x3c (the zeros one 16-byte store and one 8-byte store with
     * the names' between them: a run of zero stores made one memset, the
     * name at +0x40 stored before it), +0x24 cleared again (its own store
     * after the memset's), the four ints from +0x44 (one 16-byte store) and
     * the three floats from +0x54 */
    Object016ab9d8(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0;
        unknown30 = 0;
        unknown34 = 0;
        unknown38 = 0;
        unknown3c = -1.0f;
        unknown24 = 0;
        unknown44 = 0;
        unknown48 = 0;
        unknown4c = 0;
        unknown50 = 0;
        unknown54 = -90.0f;
        unknown58 = 90.0f;
        unknown5c = 90.0f;
    }

    virtual ~Object016ab9d8();

  private:
    int unknown24;   /* +0x24: zero from the constructor, twice; not traced */
    Name name28;     /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    Name name2c;     /* +0x2c: released by the destructor (`mov eax, [rbx+0x2c]; shl 5`) */
    int unknown30;   /* +0x30: zero from the constructor; not traced */
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    int unknown38;   /* +0x38: zero from the constructor; not traced */
    float unknown3c; /* +0x3c: -1.0 from the constructor; not traced */
    Name name40;     /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    int unknown44;   /* +0x44: zero from the constructor; not traced */
    int unknown48;   /* +0x48: zero from the constructor; not traced */
    int unknown4c;   /* +0x4c: zero from the constructor; not traced */
    int unknown50;   /* +0x50: zero from the constructor; not traced */
    float unknown54; /* +0x54: -90.0 from the constructor; not traced */
    float unknown58; /* +0x58: 90.0 from the constructor; not traced */
    float unknown5c; /* +0x5c: 90.0 from the constructor; not traced */
};

#endif
