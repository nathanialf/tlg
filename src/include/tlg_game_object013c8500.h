/* src/include/tlg_game_object013c8500.h: the class whose vtable is at
 * 0x16bc170 (config/vtables.derived.base.txt), moved from leaf_013c84c0.cpp,
 * which defines its destructor; leaf_00dd2820.cpp derives from it. derived
 * names throughout. */
#ifndef TLG_GAME_OBJECT013C8500_H
#define TLG_GAME_OBJECT013C8500_H

#include "tlg_types.h"

void FUN_013bf660(void *a, void *b); /* derived name */

struct HksObject;

/* derived names: the values a walk visits from `first` up to `last`
 * (0xdd1cf0: `mov rbx, [r14+0x18]`, `cmp [r14], rbx` at each step) */
struct ValueRange00dd1cf0 {
    HksObject *last; /* +0x0 */
    u8 unknown8[0x10];
    HksObject *first; /* +0x18 */
};

/* derived names: a 24-byte element and the range of them a walk visits
 * (0xdd1e90: `mov rbx, [r14]`, `cmp [r14+0x10], rbx; jb` at each step) */
struct Entry00dd1e90 {
    u8 unknown0[0x18];
};

struct EntryRange00dd1e90 {
    Entry00dd1e90 *first; /* +0x0 */
    u8 unknown8[0x8];
    Entry00dd1e90 *last; /* +0x10 */
};

class Object013c8500 /* derived name */
{
  public:
    virtual void release() /* derived name */
    {
        if (unknown8) {
            FUN_013bf660(unknown8, unknown10);
            unknown8 = 0;
        }
    }

    virtual ~Object013c8500();

    /* slots 3 to 144 (the vtable has 158; most hold the shared `ret` at
     * 0x1af750): a slot the bytes call carries its argument, the others
     * are not traced. The walks of slots 19 and 26 call four slots on each
     * element: three hooks 39 slots apart around the element's own mark */
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void visitValues(const ValueRange00dd1cf0 *range); /* 0xdd1cf0 */
    virtual void markValue(const HksObject *value);            /* 0xdd1d60 in 0x16bba90 */
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void visitEntries(const EntryRange00dd1e90 *range); /* 0xdd1e90 */
    virtual void markEntry(const Entry00dd1e90 *entry);
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void beforeValue(const HksObject *value);
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void beforeEntry(const Entry00dd1e90 *entry);
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void enterValue(const HksObject *value);
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void enterEntry(const Entry00dd1e90 *entry);
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void afterValue(const HksObject *value);
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void afterEntry(const Entry00dd1e90 *entry);

  private:
    void *unknown8;  /* +0x8 */
    void *unknown10; /* +0x10 */
};

#endif
