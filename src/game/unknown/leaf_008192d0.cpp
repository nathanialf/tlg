/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object01388080.h"
#include "tlg_hks.h"

/* derived names: the game objects by type, behind the script C functions
 * "FindGameObject" and "GetNumGameObject" that its creator FUN_008191e0
 * registers (0x8196e0 and 0x819b40). One entry, 0x18 bytes (the creator's
 * entry size at +0x83c): the type name's hash at +0x0, the name at +0x4,
 * the array of the type's objects the entry owns at +0x8 (deleted with it:
 * `call 0x134f620` then operator delete), the next entry of the bucket or
 * of the free list at +0x10. */
struct ObjectsByType008192d0Entry { /* derived name */

    ~ObjectsByType008192d0Entry()
    {
        delete objects;
    }

    u32 hash;                                            /* +0x0 */
    Name name;                                           /* +0x4 */
    Array05943280<Ref00503fb0<Object016b9108>> *objects; /* +0x8 */
    ObjectsByType008192d0Entry *next;                    /* +0x10 */
};

struct ObjectsByType008192d0Block { /* derived name */
    u8 unknown0[0x8];
    ObjectsByType008192d0Block *next; /* +0x8 */
};

/* derived names: the table of 256 buckets (the creator's count at +0x810 of
 * it) over blocks of entries it allocated; Table00ad4df0's layout
 * (leaf_00ad4df0.cpp) with 256 buckets */
class ObjectsByType008192d0 /* derived name */
{
  public:
    ObjectsByType008192d0()
        : buckets(), blocks(0), freeList(0), bucketCount(256),
          entrySize(sizeof(ObjectsByType008192d0Entry)), count(0)
    {
    }

    inline ~ObjectsByType008192d0()
    {
        if (count) {
            for (size_t i = 0; i < 256; ++i) {
                ObjectsByType008192d0Entry *entry = buckets[i];
                while (entry) {
                    ObjectsByType008192d0Entry *next = entry->next;
                    entry->~ObjectsByType008192d0Entry();
                    entry->next = freeList;
                    freeList = entry;
                    entry = next;
                }
                buckets[i] = 0;
            }
            count = 0;
        }
        while (blocks) {
            ObjectsByType008192d0Block *block = blocks;
            blocks = block->next;
            free(block);
        }
    }

  private:
    ObjectsByType008192d0Entry *buckets[256]; /* +0x0 */
    ObjectsByType008192d0Block *blocks;       /* +0x800 */
    ObjectsByType008192d0Entry *freeList;     /* +0x808 */
    u32 bucketCount;                          /* +0x810: 256 from the creator */
    u32 entrySize;                            /* +0x814: 0x18 from the creator */
    u32 count;                                /* +0x818 */
    u8 unknown81c[0x4];
    Lock059458a4 lock; /* +0x820: made free by the creator, the last store */
    u8 unknown824[0x4];
};

/* derived names: the primary base: slots 0 to 2 of 0x16ae890 (the
 * destructors, 0x69a0, as Base016cc6c0_0's in tlg_game_object016cc6c0.h),
 * its int at +0x8 zeroed before the derived class's vptr is stored (the
 * creator: `mov dword [rbx+8], 0` first); an empty destructor (0x8192d0
 * stores no vptr of its own after its members') */
class Base016ae890 /* derived name */
{
  public:
    Base016ae890() : unknown8(0) {}

    virtual ~Base016ae890() {}

    virtual void slot2(); /* derived name; 0x69a0, not traced */

  private:
    int unknown8; /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16ae890
 * (config/vtables.derived.base.txt, stored by its creator FUN_008191e0 and
 * its complete destructor 0x8192d0), 0x850 bytes (the creator's `mov edi,
 * 0x850` before operator new). */
class Object016ae890 : public Base016ae890 /* derived name */
{
  public:
    virtual ~Object016ae890();

  private:
    void FUN_008193f0(); /* derived name: the destructor calls it first */

    Array01343a80<Ref00503fb0<Object016b9108>> held10; /* +0x10 */
    ObjectsByType008192d0 types;                       /* +0x28 */
};

/* derived name: the complete destructor: FUN_008193f0 first, then the
 * members' destructors, the table's inlined. FUN_008196c0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ae890::~Object016ae890()
{
    FUN_008193f0();
}

/* derived names: the script functions' registry at +0x40 of the object the
 * pointer at 0x5938c40 holds: a C function registered under its name with
 * its description (the first two of the creator's arguments read from
 * .rodata strings, `lea rsi` and `lea rcx`) */
void FUN_00c87e30(ScriptFunctions05938c40 *functions, const char *name,
                  int (*function)(lua_State *), const char *description); /* derived name */

int FUN_008196e0(lua_State *state); /* derived name: "FindGameObject" */
int FUN_00819b40(lua_State *state); /* derived name: "GetNumGameObject" */

/* derived name: the creator: the object built (operator new without a
 * test), then its two script functions registered.
 * NONMATCHING: 43/47 at 227 bytes as the base: the order of the last
 * call's first two address arguments (`lea rsi` then `lea rdx` in the base,
 * the other order here). The four stores of +0x838 to +0x848 stay apart as
 * the base's since the lock word is volatile (round 559D,
 * tlg_game_creation.h); before, the bucket count and entry size were one
 * merged `movabs` store. */
Object016ae890 *FUN_008191e0() /* derived name */
{
    Object016ae890 *objects = new Object016ae890;
    FUN_00c87e30(D_5938c40->functions, "FindGameObject", FUN_008196e0,
                 "<object array> = FindGameObject( typeName[, subTypeName] )");
    FUN_00c87e30(D_5938c40->functions, "GetNumGameObject", FUN_00819b40,
                 "integer = GetNumGameObject( typeName[, subTypeName] )");
    return objects;
}
