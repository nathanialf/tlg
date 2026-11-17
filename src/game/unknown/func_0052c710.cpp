/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_game_node.h"
#include <functional>

/* derived names: FUN_0052c710 finds three objects of its owner's (by class,
 * the walk at 0x52c7bc) and builds for each two 0x50-byte objects (vtables
 * 0x16cafc0, 0x16caff0 and 0x16cb020, through FUN_01357df0) that each take a
 * std::function, six in all: their implementations' vtables are 0x16ab308,
 * 0x16ab358, 0x16ab3a8, 0x16ab3f8, 0x16ab448 and 0x16ab498 (the `lea`s at
 * 0x52c82c, 0x52c8f6, 0x52cafc, 0x52cbdc, 0x52cdd0 and 0x52ceb8), the
 * lambdas below in that order. Each lambda calls a virtual function of the
 * object it is given with a float, the one at +0x19c of the object the
 * pointer at 0x5938c40 holds, or, when the object says so, the one at +0x24
 * of the record at +0x98 of the object the pointer at 0x57c9390 holds. The
 * classes are not traced beyond these fields and slots. */
struct Class0052c710 { /* derived name: a class record, its parent at +0 */
    const Class0052c710 *parent;
};

extern const Class0052c710 *D_59473c8;

struct Part0052c710 { /* derived name: the object at +0x28 of the first pair's */
    u8 unknown0[0x18];
    const Class0052c710 *type; /* +0x18 */
    u8 unknown20[4];
    u8 flags; /* +0x24, bit 0 tested */

    bool isKindOf(const Class0052c710 *of) const
    {
        const Class0052c710 *c = type;
        do {
            if (c == of)
                return true;
            c = c->parent;
        } while (c);
        return false;
    }
};

class TargetA0052c710 : public Object016b9108 /* derived name: the first pair's object */
{
  public:
    virtual void slot5();                                 /* derived name; not traced */
    virtual void slot6();                                 /* derived name; not traced */
    virtual void slot7();                                 /* derived name; not traced */
    virtual void slot8();                                 /* derived name; not traced */
    virtual void slot9(Part0052c710 *part, float value);  /* derived name; not traced */
    virtual void slot10();                                /* derived name; not traced */
    virtual void slot11(Part0052c710 *part, float value); /* derived name; not traced */

    u8 unknown24[0x4];
    Part0052c710 *part; /* +0x28 */
    u8 unknown30[4];
    int unknown34;
    int unknown38;
    int unknown3c;
};

class TargetB0052c710 : public Object016b9108 /* derived name: the second pair's object */
{
  public:
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11(float value); /* derived name; not traced */
    virtual void slot12(float value); /* derived name; not traced */

    u8 unknown24[0x1c];
    u8 unknown40; /* bit 1 tested */
};

class TargetC0052c710 : public Object016b9108 /* derived name: the third pair's object */
{
  public:
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12();            /* derived name; not traced */
    virtual void slot13();            /* derived name; not traced */
    virtual void slot14();            /* derived name; not traced */
    virtual void slot15(float value); /* derived name; not traced */
    virtual void slot16();            /* derived name; not traced */
    virtual void slot17(float value); /* derived name; not traced */

    u8 unknown24[0xb8];
    int unknowndc; /* +0xdc */
};

struct Record057c9390 { /* derived name */
    u8 unknown0[0x24];
    float unknown24; /* +0x24 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x98];
    Record057c9390 *unknown98; /* +0x98 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c; /* +0x19c */
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

struct Owner0052c710; /* derived name */

/* derived names: the 0x50-byte task FUN_0052c710 makes for each found object,
 * one class for each object's class (vtables 0x16cafb0, 0x16cafe0 and
 * 0x16cb010, config/vtables.derived.base.txt): its constructor is inlined
 * there (0x52c860: the count at +0x8, the vtable, the reference at +0x10 and
 * the function's implementation at +0x40 cleared), its destructors are
 * 0x1357f40, 0x1358100, 0x1358290 and the deleting ones 0x1358000,
 * 0x13581c0, 0x1358350 (the function destroyed, then the reference
 * dropped). */
template <class T> class Task0052c710 /* derived name */
{
  public:
    Task0052c710() : references(0) {}

    virtual ~Task0052c710() {}

    /* slot 2: the deleting destructor through the vtable for an object that
     * is there (the body at 0x69a0 the linker keeps for it) */
    virtual void destroy() /* derived name */
    {
        delete this;
    }

    /* slot 3, FUN_013580d0 (leaf_013580d0.cpp): the function called with
     * the object */
    virtual void run() /* derived name */
    {
        callback(*target.get());
    }

    /* FUN_01357df0, one body for the three classes: the object exchanged
     * in, the function assigned, the delay stored */
    void set(T *object, const std::function<void(T &)> &function, int delay) /* derived name */
    {
        target.set(object);
        callback = function;
        this->delay = delay;
    }

    int references;                    /* +0x8 */
    int delay;                         /* +0xc: the found object's +0x40 plus 100 or 300 */
    AtomicRef0045c470<T> target;       /* +0x10 */
    std::function<void(T &)> callback; /* +0x20 */
};

typedef std::function<void(TargetA0052c710 &)> CallbackA0052c710; /* derived name */
typedef std::function<void(TargetB0052c710 &)> CallbackB0052c710; /* derived name */
typedef std::function<void(TargetC0052c710 &)> CallbackC0052c710; /* derived name */

/* derived names: the owner's object of each class (the walk at 0x52c7bc)
 * and the owner's list the tasks go to (FUN_00be8900 with 1 or 2), not
 * written */
TargetA0052c710 *findTargetA(Owner0052c710 *owner); /* derived name */
TargetB0052c710 *findTargetB(Owner0052c710 *owner); /* derived name */
TargetC0052c710 *findTargetC(Owner0052c710 *owner); /* derived name */
void FUN_00be8900(Owner0052c710 *owner, void *task, int kind);

/* derived name: a task made for the object with the function, set and
 * handed to the owner's list */
template <class T>
inline void addTask(Owner0052c710 *owner, T *target, const std::function<void(T &)> &callback,
                    int delay, int kind) /* derived name */
{
    Task0052c710<T> *task = new Task0052c710<T>;
    task->set(target, callback, delay);
    FUN_00be8900(owner, task, kind);
}

/* the first pair's call: when the value is not near zero and the object's
 * part is of the class at 0x59473c8 with bit 0 of its flags set, and the
 * object's ints at +0x34 and +0x38 are nonzero */
// NONMATCHING: inlined into slot 2 of 0x16ab308 and 0x16ab358 (FUN_0052d8d0, FUN_0052da00): the
// class walk's shape, the base testing the object's own class before a rotated loop over the
// parents and the compile keeping one loop with its test at the head (round 138B (3), as
// FUN_001bbc00); every instruction before the walk is the base's
static bool FUN_0052c710_ready(TargetA0052c710 &target, float value) /* derived name */
{
    return fabsf(value) >= 0.00001f && target.part && target.part->isKindOf(D_59473c8) &&
           (target.part->flags & 1) && target.unknown34 && target.unknown38;
}

// NONMATCHING: not written beyond the lambdas and the tasks (the walk, the delays' found
// object's +0x40 added to 100 and 300)
void FUN_0052c710(Owner0052c710 *owner) /* derived name */
{
    TargetA0052c710 *a = findTargetA(owner);
    TargetB0052c710 *b = findTargetB(owner);
    TargetC0052c710 *c = findTargetC(owner);
    addTask(owner, a, CallbackA0052c710([](TargetA0052c710 &target) {
                float value = D_5938c40->unknown19c;
                if (FUN_0052c710_ready(target, value))
                    target.slot9(target.part, value);
            }),
            100, 1);
    addTask(owner, a, CallbackA0052c710([](TargetA0052c710 &target) {
                float value =
                    target.unknown3c ? D_57c9390->unknown98->unknown24 : D_5938c40->unknown19c;
                if (FUN_0052c710_ready(target, value))
                    target.slot11(target.part, value);
            }),
            300, 2);
    addTask(owner, b, CallbackB0052c710([](TargetB0052c710 &target) {
                target.slot11(D_5938c40->unknown19c);
            }),
            100, 1);
    // slot 2 of 0x16ab3f8 (FUN_0052dc20) and, below, of 0x16ab498 (FUN_0052dde0)
    addTask(owner, b, CallbackB0052c710([](TargetB0052c710 &target) {
                float value = (target.unknown40 & 2) ? D_57c9390->unknown98->unknown24
                                                     : D_5938c40->unknown19c;
                target.slot12(value);
            }),
            300, 2);
    addTask(owner, c, CallbackC0052c710([](TargetC0052c710 &target) {
                target.slot15(D_5938c40->unknown19c);
            }),
            100, 1);
    addTask(owner, c, CallbackC0052c710([](TargetC0052c710 &target) {
                float value;
                if (target.unknowndc != 0)
                    value = D_57c9390->unknown98->unknown24;
                else
                    value = D_5938c40->unknown19c;
                target.slot17(value);
            }),
            300, 2);
}
