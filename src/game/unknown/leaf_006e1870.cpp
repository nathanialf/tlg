/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_types.h"

/* derived names: an entry held by two lists of the owner below, each entry
 * keeping its place in each (-1 when it is in none): at +0x3c and +0x40 for
 * FUN_006e1870, at +0x38 and +0x3c for FUN_007b2350. The entries are the
 * classes whose vtables are at 0x16c7810 and 0x16c78d0
 * (config/vtables.derived.base.txt, stored by their constructors
 * FUN_0069b4c0 and FUN_004233f0 and by their destructors below), derived
 * from Object016b9108, each with a Name at +0x34 */
class Object016c7810 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c7810();

  private:
    u8 unknown24[0x10];
    Name name34; /* +0x34 */
    u8 unknown38[0x4];

  public:
    int index3c; /* +0x3c */
    int index40; /* +0x40 */
};

class Object016c78d0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c78d0();

  private:
    u8 unknown24[0x10];
    Name name34; /* +0x34 */

  public:
    int index38; /* +0x38 */
    int index3c; /* +0x3c */
};

/* derived names: the two lists, at +0x10 and +0x28 */
template <class T> struct Owner006e1870 { /* derived name */
    u8 unknown0[0x10];
    Array05943280<T *> first;  /* +0x10 */
    Array05943280<T *> second; /* +0x28 */
};

/* derived names: the entry taken out of each list it is in: the last entry
 * of the list told its new place (unless the list holds one entry, or the
 * entry's place equals the count), the entry replaced by the last and its
 * place cleared. The first list goes through Array05943280::removeSwap (the
 * place passed, so read before the count); the second is written out with
 * the last index taken first (`mov ecx, [rdi+0x30]; mov eax, [rsi+0x40]`
 * after the store: GVN's load PRE puts each reload at the end of the block
 * that stored, in the order the join reads them, GVN.cpp:1672 and :2398),
 * the test `last > place` (`cmp edx, eax; jbe`) and the last dropped by
 * removeLast(1) */
void FUN_006e1870(Owner006e1870<Object016c7810> *owner, Object016c7810 *entry) /* derived name */
{
    if (entry->index3c >= 0) {
        const int count = owner->first.size();
        if (count > 1 && count != entry->index3c)
            owner->first.at(count - 1)->index3c = entry->index3c;
        owner->first.removeSwap(entry->index3c);
        entry->index3c = -1;
    }
    if (entry->index40 >= 0) {
        const int count = owner->second.size();
        if (count > 1 && count != entry->index40)
            owner->second.at(count - 1)->index40 = entry->index40;
        const unsigned last = owner->second.size() - 1;
        if (last > unsigned(entry->index40))
            owner->second[entry->index40] = owner->second[last];
        owner->second.removeLast(1);
        entry->index40 = -1;
    }
}

/* derived names: the same over the places at +0x38 and +0x3c */
void FUN_007b2350(Owner006e1870<Object016c78d0> *owner, Object016c78d0 *entry) /* derived name */
{
    if (entry->index38 >= 0) {
        const int count = owner->first.size();
        if (count > 1 && count != entry->index38)
            owner->first.at(count - 1)->index38 = entry->index38;
        owner->first.removeSwap(entry->index38);
        entry->index38 = -1;
    }
    if (entry->index3c >= 0) {
        const int count = owner->second.size();
        if (count > 1 && count != entry->index3c)
            owner->second.at(count - 1)->index3c = entry->index3c;
        const unsigned last = owner->second.size() - 1;
        if (last > unsigned(entry->index3c))
            owner->second[entry->index3c] = owner->second[last];
        owner->second.removeLast(1);
        entry->index3c = -1;
    }
}

/* derived names: the object the pointer at 0x57c9390 holds, as the
 * destructors below read it: the owners of the two classes' lists at +0x20
 * and +0x28 */
struct Object057c9390 { /* derived name */
    u8 unknown0[0x20];
    Owner006e1870<Object016c78d0> *unknown20; /* +0x20 */
    Owner006e1870<Object016c7810> *unknown28; /* +0x28 */
};

extern Object057c9390 *D_57c9390;

/* derived names: the complete destructors: the entry taken out of its
 * owner's lists when there is an owner (the pointer at 0x57c9390 read once),
 * then the Name at +0x34 and the base's (Object016b9108's destructor,
 * inlined); FUN_006e1350 and FUN_007b1e30, slot 1, are the deleting ones.
 * Each destructor is its class's key function, so this file emits the
 * vtables. */
Object016c7810::~Object016c7810()
{
    if (Object057c9390 *object = D_57c9390) {
        if (object->unknown28)
            FUN_006e1870(object->unknown28, this);
    }
}

Object016c78d0::~Object016c78d0()
{
    if (Object057c9390 *object = D_57c9390) {
        if (object->unknown20)
            FUN_007b2350(object->unknown20, this);
    }
}
