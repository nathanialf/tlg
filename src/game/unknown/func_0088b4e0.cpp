/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"
#include <functional>

/* derived names: FUN_0088b4e0 (102307 bytes) builds a menu of named entries
 * (the strings "cansel" and "decide" are the sounds FUN_0088b2b0 plays) and
 * hands its items std::function callbacks: 34 implementations, their vtables
 * in the order of their `lea`s (0x8906b8 on). The first 22 are written
 * below in that order: 0x16af4b0, 0x16af500, 0x16af550, 0x16af5a0,
 * 0x16af910, 0x16af960, 0x16af9b0, 0x16afaf0, 0x16afb40, 0x16afb90,
 * 0x16afdc0, 0x16afe10, 0x16afe60, 0x16afeb0, 0x16af6e0, 0x16af730,
 * 0x16af780, 0x16aff00, 0x16afa00, 0x16afa50, 0x16afaa0, 0x16af690; the
 * other 12 (0x16af5f0 on, the `lea` at 0x8a0513) are still in their holder
 * files. setText, clearText and clearTitle are the creating function's
 * closures at rbp-0x9c0, rbp-0x9e8 and rbp-0x9d8, which the callbacks call
 * through (inlined there); clearList is the one the later lists' callbacks
 * call (its count read once, `test; je` then `dec; jne` on a 32-bit
 * register and the array pointer stepped by 4: a count-down loop). The object the
 * callbacks change (r12 in the base, kept at rbp-0x998) has an int state at
 * +0x110 and the list FUN_008ab9e0 searches at +0x148 (count +0x150). The
 * other members are not traced. */
void FUN_0088b2b0(const char *name); /* derived name: plays the named sound */

struct Owner0088b4e0 { /* derived name */
    u8 unknown0[0x110];
    int unknown110; /* +0x110 */
    u8 unknown114[0x10];
    int unknown124; /* +0x124 */
};

/* the record at +0x100 of D_57c9390 the sliders read and write: values
 * from 0 to 1 (or 0 to 2), shown as percentages */
struct Settings057c9390 { /* derived name */
    u8 unknown0[0x40];
    float unknown40;    /* +0x40 */
    float unknown44;    /* +0x44 */
    float unknown48;    /* +0x48 */
    unsigned unknown4c; /* +0x4c */
    float unknown50;    /* +0x50 */
    float unknown54;    /* +0x54 */
    float unknown58;    /* +0x58 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Settings057c9390 *unknown100; /* +0x100 */
};

extern Object057c9390 *D_57c9390;

/* the entry of `self`'s list whose id is `id` (+0x28 of the item at +0x8 of
 * each 0x30-byte element) is given `text` */
void FUN_008ab9e0(Owner0088b4e0 *self, unsigned id, Name text); /* derived name */

/* the list builder the first callbacks go to: the base calls it through a
 * closure of the creating function (rbp-0xa18); its arguments here are the
 * ones the call sets (0x890903), the rest not traced */
void FUN_008abb70(void *closure, Name *names, unsigned count, void *unknown, /* derived name */
                  std::function<void(Name)> onDecide, std::function<void()> onCancel, int first,
                  int second);

/* a slider entry (0x8951e7 on): its label and help, the setter given a
 * step and returning the new percentage, the sound it plays, the step's
 * bounds; the closure as FUN_008abb70's */
void FUN_008ac880(void *closure, Name label, Name help, /* derived name */
                  std::function<float(float)> change, Name sound, float step, float scale);

/* a value shown beside a slider (0x899f0f on): the getter returns the
 * percentage; the closure as FUN_008abb70's */
void FUN_008ac610(void *closure, Name label, Name help,
                  std::function<float()> value, /* derived name */
                  float step, float scale);

extern Name D_581e81c;
extern Name D_581e900[]; /* derived name: the three entries of the second list */
extern Name D_581e940[]; /* derived name: the entries of three more lists */
extern Name D_581e968[];
extern Name D_581e980[]; /* derived name: the text an entry is cleared to */
extern Name D_581ea80[]; /* derived name: the entries two later lists clear */
extern Name D_581eaa0[];
extern Name D_581ee20; /* derived name: the text those entries are cleared to */

// NONMATCHING: not written beyond the lambdas. Slots 2 not matched: 0x8af240
// and 0x8b1090 (the base's frame is 0x20 bytes larger, two more spills),
// 0x8b0700 and 0x8b0eb0 (the base keeps each arm's step and state stores,
// where this build sinks them into one block: the sinkcond question, D54).
// Slots 0 and 1 not matched where the closure is copied tail first
// (0x16af550, 0x16af910, 0x16af960, 0x16afaf0, 0x16afe10, 0x16afeb0,
// 0x16af6e0, 0x16af730; round 153A's residual). Slot 2 of 0x16af6e0
// (0x8afc90): the sinkcond question as 0x8b0700. Slots 2 that call through
// setText (0x8b1d60, 0x8b2020, 0x8b2280, 0x8b2540): the base keeps the
// text's index in a register across FUN_008ab9e0, which reads its Name
// argument only (the attribute the compiler infers when FUN_008ab9e0 is
// defined in the module); not written yet. Slot 2 of 0x16af780 (0x8affc0):
// the sign compare scheduled before the add, registers renumbered.
void FUN_0088b4e0(Owner0088b4e0 *self) /* derived name */
{
    Owner0088b4e0 *owner = self;
    bool changed = false;
    Name *names;
    unsigned count;
    Name title("");
    Name a1(""), b1(""), a2(""), b2(""), a3(""), b3(""), a4(""), b4(""), a5(""), a6(""), b6(""),
        a7("");
    void *closure = 0;
    void *unknown = 0;
    bool busy = false, done = false;
    Name yes(""), no("");
    int unknown970 = 0, unknown968 = 0, unknown980 = 0;
    Name yes2(""), no2("");
    unsigned countA = 0, countB = 0, countC = 0;
    Name label(""), help("");
    Name yes3(""), yes4(""), yes5(""), no3("");
    unsigned count3 = 0, count4 = 0;
    auto setText = [&owner](Name id, const Name &text) { FUN_008ab9e0(owner, id.index, text); };
    auto clearText = [&setText](const Name &id) { setText(id, D_581e81c); };
    auto clearTitle = [&setText, &title]() { setText(title, D_581e81c); };
    auto clearList = [&setText](const Name *ids, unsigned count) {
        while (count--)
            setText(*ids++, D_581ee20);
    };

    // NONMATCHING: the base builds these two (rbp-0x170, rbp-0x1a0) before
    // the call and destroys them after it; where they go is not traced
    std::function<void(Name)> ignore = [](Name) {};
    std::function<void()> none = []() {};
    FUN_008abb70(
        closure, names, count, unknown,
        [&a1, &b1, owner, &changed, &a2, &b2, &a3, &b3, &a4, &b4, &a5, &a6, &b6, &a7, &setText,
         &title, &clearText, &names, &count, &clearTitle](Name selected) {
            if (selected == a1 || selected == b1) {
                owner->unknown110 = 300;
                changed = true;
            }
            if (selected == a2 || selected == b2) {
                owner->unknown110 = 400;
                changed = true;
            }
            if (selected == a3 || selected == b3) {
                owner->unknown110 = 500;
                changed = true;
            }
            if (selected == a4 || selected == b4) {
                owner->unknown110 = 600;
                changed = true;
            }
            if (selected == a5) {
                owner->unknown110 = 700;
                changed = true;
            }
            if (selected == a6 || selected == b6) {
                owner->unknown110 = 800;
                changed = true;
            }
            if (selected == a7) {
                owner->unknown110 = 900;
                changed = true;
            }
            if (changed) {
                if (owner->unknown110 != 300)
                    FUN_0088b2b0("decide");
                setText(title, D_581e81c);
                for (unsigned i = 0; i < count; i++)
                    clearText(names[i]);
                clearTitle();
            }
        },
        [owner, &changed]() {
            owner->unknown110 = 300;
            changed = true;
        },
        0, 1);

    FUN_008abb70(
        closure, D_581e900, 3, unknown,
        [&busy, &yes, self, &done, &no](Name selected) {
            Owner0088b4e0 *menu = self;
            busy = true;
            if (selected == yes) {
                FUN_0088b2b0("decide");
                busy = true;
                menu->unknown110++;
                menu->unknown124 = 1100;
                done = true;
            } else if (selected == no) {
                FUN_0088b2b0("cansel");
                busy = true;
                menu->unknown110++;
                menu->unknown124 = -1;
                done = true;
            }
        },
        [self, &busy, &done]() {
            /* the object is read before the sound is played (0x8b08f1) */
            Owner0088b4e0 *menu = self;
            FUN_0088b2b0("cansel");
            busy = true;
            menu->unknown110++;
            menu->unknown124 = -1;
            done = true;
        },
        1, 1);
    FUN_008ac880(
        closure, label, help,
        [&unknown970, &unknown968](float delta) -> float {
            Settings057c9390 *settings = D_57c9390->unknown100;
            float percent = settings->unknown48 * 50.0f + delta;
            percent = percent < 0.0f ? 0.0f : percent;
            percent = percent < 100.0f ? percent : 100.0f;
            settings->unknown48 = percent * 0.02f;
            return percent;
        },
        Name("slider_sfx"), 2.0f, 0.995f);

    FUN_008abb70(
        closure, D_581e940, countA, unknown,
        [&busy, &yes2, self, &changed, &no2](Name selected) {
            Owner0088b4e0 *menu = self;
            busy = true;
            if (selected == yes2) {
                FUN_0088b2b0("decide");
                busy = true;
                menu->unknown110++;
                menu->unknown124 = 1200;
                changed = true;
            } else if (selected == no2) {
                FUN_0088b2b0("cansel");
                busy = true;
                menu->unknown110++;
                menu->unknown124 = -1;
                changed = true;
            }
        },
        [self, &busy, &clearText, &countA, &countB, &countC, &changed]() {
            Owner0088b4e0 *menu = self;
            FUN_0088b2b0("cansel");
            busy = true;
            for (unsigned i = 0; i < countA; i++)
                clearText(D_581e940[i]);
            for (unsigned i = 0; i < countB; i++)
                clearText(D_581e968[i]);
            for (unsigned i = 0; i < countC; i++)
                clearText(D_581e980[i]);
            menu->unknown110++;
            menu->unknown124 = -1;
            changed = true;
        },
        1, 1);
    FUN_008ac880(
        closure, label, help,
        [&unknown980, &unknown968](float delta) -> float {
            Settings057c9390 *settings = D_57c9390->unknown100;
            float percent = settings->unknown58 * 100.0f + delta;
            if (percent < 0.0f) {
                percent = 0.0f;
            }
            if (percent > 100.0f) {
                percent = 100.0f;
            }
            settings->unknown58 = percent * 0.01f;
            return percent;
        },
        Name("slider_sfx"), 2.0f, 0.995f);

    FUN_008abb70(
        closure, &yes3, 1, unknown,
        [&busy, &yes3, self, &clearList, &count3, &done](Name selected) {
            Owner0088b4e0 *menu = self;
            busy = true;
            if (yes3 == selected) {
                FUN_0088b2b0("decide");
                busy = true;
                clearList(D_581ea80, count3);
                menu->unknown110++;
                done = true;
            }
        },
        [self, &busy, &clearList, &count3, &done]() {
            Owner0088b4e0 *menu = self;
            FUN_0088b2b0("cansel");
            busy = true;
            clearList(D_581ea80, count3);
            menu->unknown110++;
            done = true;
        },
        1, 1);

    FUN_008abb70(
        closure, &yes4, 1, unknown,
        [&busy, &yes4, self, &clearList, &count4, &done](Name selected) {
            Owner0088b4e0 *menu = self;
            busy = true;
            if (yes4 == selected) {
                FUN_0088b2b0("decide");
                busy = true;
                clearList(D_581eaa0, count4);
                menu->unknown110++;
                done = true;
            }
        },
        [self, &busy, &clearList, &count4, &done]() {
            Owner0088b4e0 *menu = self;
            FUN_0088b2b0("cansel");
            busy = true;
            clearList(D_581eaa0, count4);
            menu->unknown110++;
            done = true;
        },
        1, 1);

    FUN_008abb70(
        closure, D_581e900, 2, unknown,
        [&busy, &no3, self, &done, &yes5](Name selected) {
            Owner0088b4e0 *menu = self;
            busy = true;
            if (no3 == selected) {
                FUN_0088b2b0("cansel");
                busy = true;
                menu->unknown110++;
                menu->unknown124 = -1;
                done = true;
            } else if (yes5 == selected) {
                FUN_0088b2b0("decide");
                busy = true;
                menu->unknown110++;
                menu->unknown124 = 1000;
                done = true;
            }
        },
        [self, &busy, &done]() {
            Owner0088b4e0 *menu = self;
            FUN_0088b2b0("cansel");
            busy = true;
            menu->unknown110++;
            menu->unknown124 = -1;
            done = true;
        },
        1, 1);

    /* the camera speeds (+0x40, +0x44): the slider sets their size and
     * keeps each one's sign */
    FUN_008ac880(
        closure, label, help,
        [&unknown970, &unknown968](float delta) -> float {
            Settings057c9390 *settings = D_57c9390->unknown100;
            float percent = (fabsf(settings->unknown40) - 0.5f) * 100.0f + delta;
            percent = percent < 0.0f ? 0.0f : percent;
            percent = percent > 100.0f ? 100.0f : percent;
            float speed = percent * 0.01f + 0.5f;
            settings->unknown40 = settings->unknown40 > 0.0f ? speed : -speed;
            settings = D_57c9390->unknown100;
            settings->unknown44 = settings->unknown44 <= 0.0f ? -speed : speed;
            return percent;
        },
        Name("slider_sfx"), 2.0f, 0.995f);

    /* the values the sliders show */
    FUN_008ac610(
        closure, label, help, []() -> float { return D_57c9390->unknown100->unknown48 * 50.0f; },
        2.0f, 0.995f);
    FUN_008ac610(
        closure, label, help, []() -> float { return D_57c9390->unknown100->unknown58 * 100.0f; },
        2.0f, 0.995f);
    FUN_008ac610(
        closure, label, help, []() -> float { return D_57c9390->unknown100->unknown50 * 100.0f; },
        2.0f, 0.995f);
    FUN_008ac610(
        closure, label, help, []() -> float { return D_57c9390->unknown100->unknown54 * 100.0f; },
        2.0f, 0.995f);
    FUN_008ac610(
        closure, label, help,
        []() -> float { return (fabsf(D_57c9390->unknown100->unknown40) - 0.5f) * 100.0f; }, 2.0f,
        0.995f);
}
