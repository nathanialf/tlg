/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_hks.h"
#include "tlg_hks_string.h"

/* derived names: FUN_008a82f0 is this file's static initializer. Among its
 * objects are 3 lists of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x8aec00, 0x8aed30, 0x8aee30, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry008a82f0 { /* derived name */

    Entry008a82f0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_159bb29[8];
extern const char D_159bb31[7];
extern const char D_159bb38[10];
extern const char D_159bb42[11];
extern const char D_159bb4d[10];
extern const char D_159bb57[9];
extern const char D_159bb60[12];
extern const char D_159bb6c[14];
extern const char D_15a41e2[5];
extern const char D_15a41e7[5];
extern const char D_15a41ec[5];
extern const char D_15c7a8a[5];
extern const char D_15c94db[5];

// NONMATCHING: the file's initializer (FUN_008a82f0): only the lists are
// written; its other objects are not.
static Entry008a82f0 D_581e760[] = {Name(D_159bb29), Name(D_159bb31), Name(D_159bb38),
                                    Name(D_159bb42), Name(D_159bb4d)};
static Name D_581e790[] = {Name(D_15c7a8a), Name(D_159bb57), Name(D_159bb60), Name(D_159bb6c)};
static Entry008a82f0 D_581f010[] = {Name(D_15a41e2), Name(D_15c94db), Name(D_15a41e7),
                                    Name(D_15a41ec)};

/* derived names: the script C function "GameMenu_GetResult" (FUN_008817d0
 * registers it through FUN_00c87e30, lea at 0x88188f): slot 14 of the menu
 * at +0xd0 of the object the pointer at 0x57c9390 holds answers the menu's
 * result, an index into D_581e790 (None, LoadGame, ReturnTitle,
 * NextSceneSkip); that name's string is pushed with the length its entry
 * keeps, and one result returned. leaf_00881690.cpp's "GameMenu_IsEnd"
 * reads slot 13 of the same menu. The C function's own name is unknown. */
class Menu057c9390_d0 /* derived name */
{
  public:
    virtual void slot0();      /* derived name; not traced */
    virtual void slot1();      /* derived name; not traced */
    virtual void slot2();      /* derived name; not traced */
    virtual void slot3();      /* derived name; not traced */
    virtual void slot4();      /* derived name; not traced */
    virtual void slot5();      /* derived name; not traced */
    virtual void slot6();      /* derived name; not traced */
    virtual void slot7();      /* derived name; not traced */
    virtual void slot8();      /* derived name; not traced */
    virtual void slot9();      /* derived name; not traced */
    virtual void slot10();     /* derived name; not traced */
    virtual void slot11();     /* derived name; not traced */
    virtual void slot12();     /* derived name; not traced */
    virtual bool slot13();     /* derived name; whether the menu has ended */
    virtual unsigned slot14(); /* derived name; the menu's result */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0xd0];
    Menu057c9390_d0 *unknownD0; /* +0xd0 */
};

extern Object057c9390 *D_57c9390;

int FUN_008816e0(lua_State *state) /* derived name */
{
    const NameTableEntry017ac870 &entry =
        D_17ac870[D_581e790[D_57c9390->unknownD0->slot14()].index];
    FUN_013aacc0(state, entry.string0, entry.length14);
    return 1;
}
