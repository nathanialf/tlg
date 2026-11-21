/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_004710c0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16a9b50
 * (config/vtables.derived.base.txt, stored by FUN_004710c0 FUN_00471350), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own fields
 * from +0x34 are traced where its destructor FUN_00471350 tears them down
 * (the Names at +0x78, +0x74, +0x38, +0x34) and where clear() FUN_00471240
 * empties them; their meaning is not traced. 0xa0 bytes (the creator's
 * `mov edi, 0xa0`). */
class Object016a9b50 : public Object01343880 /* derived name */
{
  public:
    /* the members default-built (the four Names empty), then clear() */
    Object016a9b50(const Name &name) : Object01343880(name)
    {
        clear();
    }

    virtual ~Object016a9b50();

    void clear(); /* derived name */

  private:
    Name name34; /* +0x34: released by the destructor (`mov eax, [rbx+0x34]; shl 5`) */
    Name name38; /* +0x38: released by the destructor (`mov eax, [rbx+0x38]; shl 5`) */
    int unknown3c;
    int unknown40;
    int unknown44;
    u8 unknown48[0x8];
    int unknown50[8]; /* +0x50: cleared in one 32-byte store */
    int unknown70;
    Name name74;      /* +0x74: released by the destructor (`mov eax, [rbx+0x74]; shl 5`) */
    Name name78;      /* +0x78: released by the destructor (`mov eax, [rbx+0x78]; shl 5`) */
    int unknown7c[8]; /* +0x7c: cleared in one 32-byte store */
    u8 unknown9c[0x4];
};

/* derived name: the record FUN_00cbb0e0 returns when the class is registered
 * (`mov rax, [0x57d5968]; mov [0x59458a8], rax` before the constructor) */
extern Type059458a8 *D_57d5968;

/* derived name: the creator of Object016a9b50, registered with its type
 * through FUN_00cbb0e0 by FUN_00490100 (lea at 0x49202d), whose signature it
 * keeps: the first argument is not used. The object's 0xa0 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place, its
 * constructor inlined. */
Object016b9108 *FUN_004710c0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a9b50));
    D_59458a4.lock();
    D_59458a8 = D_57d5968;
    return new (memory) Object016a9b50(name);
}

/* derived name: empties the object: each Name released in turn, the fields
 * between them cleared */
void Object016a9b50::clear()
{
    name34.release();
    name38.release();
    unknown3c = 0;
    unknown44 = 0;
    for (int i = 0; i < 8; ++i)
        unknown50[i] = 0;
    unknown70 = 0;
    name74.release();
    name78.release();
    unknown40 = 0;
    for (int i = 0; i < 8; ++i)
        unknown7c[i] = 0;
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_004714a0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a9b50::~Object016a9b50() {}
