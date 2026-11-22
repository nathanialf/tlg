/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_hks.h"
#include "tlg_hks_string.h"

/* derived names: FUN_008a82f0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 33 names
 * from strings, each registered with Name's destructor (0x1331800), and 3
 * lists, each destroyed by the array destructor the compiler writes for it
 * (0x8aec00, 0x8aed30, 0x8aee30). What reads them is not traced. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry008a82f0 { /* derived name */

    template <size_t N> Entry008a82f0(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_159a2a3[7];
extern const char D_159bb29[8];
extern const char D_159bb31[7];
extern const char D_159bb38[10];
extern const char D_159bb42[11];
extern const char D_159bb4d[10];
extern const char D_159bb57[9];
extern const char D_159bb60[12];
extern const char D_159bb6c[14];
extern const char D_159bb7a[8];
extern const char D_159bb82[8];
extern const char D_159bb8a[10];
extern const char D_159bb94[12];
extern const char D_159bba0[10];
extern const char D_159bbaa[10];
extern const char D_159bbb4[5];
extern const char D_159bbb9[5];
extern const char D_159bbbe[9];
extern const char D_159bbc7[53];
extern const char D_159bbfc[53];
extern const char D_159bc31[38];
extern const char D_159bc57[15];
extern const char D_159bc66[13];
extern const char D_159bc73[12];
extern const char D_159bc7f[13];
extern const char D_159bc8c[13];
extern const char D_159bc99[9];
extern const char D_159bca2[8];
extern const char D_15a40b5[17];
extern const char D_15a40c6[17];
extern const char D_15a40d7[17];
extern const char D_15a40e8[17];
extern const char D_15a40f9[17];
extern const char D_15a411b[19];
extern const char D_15a41d2[16];
extern const char D_15a41e2[5];
extern const char D_15a41e7[5];
extern const char D_15a41ec[5];
extern const char D_15b4f92[8];
extern const char D_15b8061[7];
extern const char D_15be63e[7];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15c7a8a[5];
extern const char D_15c94db[5];
extern const char D_15ca420[7];

Name D_581efe0(D_15c627c);
Name D_581efe4(D_15c62a5);
Name D_581efe8(D_15ca420, false);

static Entry008a82f0 D_581e760[] = {D_159bb29, D_159bb31, D_159bb38, D_159bb42, D_159bb4d};

static Name D_581e790[] = {Name(D_15c7a8a), Name(D_159bb57), Name(D_159bb60), Name(D_159bb6c)};

Name D_581e81c(D_159bb7a, false);
Name D_581e80c(D_159bb82, false);
Name D_581e820(D_159bb8a, false);
Name D_581e824(D_159bb94, false);
Name D_581e814(D_159bba0, false);
Name D_581ee20(D_159bbaa, false);
Name D_581e830(D_159bbb4, false);
Name D_581e810(D_159bbb9, false);
Name D_581e828(D_15be63e, false);
Name D_581e82c(D_159bbbe, false);
Name D_581e818(D_159a2a3, false);
Name D_581ee24(D_15b8061, false);
Name D_581e7a4(D_15a40b5, false);
Name D_581e7b0(D_15a40c6, false);
Name D_581e7b4(D_15a40d7, false);
Name D_581e7b8(D_15a40e8, false);
Name D_581e7bc(D_15a40f9, false);
Name D_581e7c0(D_15a411b, false);
Name D_581e7a8(D_159bbc7, false);
Name D_581e7ac(D_159bbfc, false);
Name D_581e7a0(D_159bc31, false);
Name D_581efec(D_159bc57);
Name D_581eff0(D_15b4f92);
Name D_581eff4(D_15a41d2);
Name D_581eff8(D_159bc66);
Name D_581effc(D_159bc73);
Name D_581f000(D_159bc7f);
Name D_581f004(D_159bc8c);
Name D_581f008(D_159bc99);
Name D_581f00c(D_159bca2);

static Entry008a82f0 D_581f010[] = {D_15a41e2, D_15c94db, D_15a41e7, D_15a41ec};

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
