/* src/include/tlg_game_node.h: a node of the game's scene and its components
 * (game region; docs/TARGETS.md). Every name here is derived. A node's
 * components (+0x58, count +0x60) are scanned under the reader count at +0x30
 * (FUN_01331c10 takes it, an atomic decrement drops it); its children are
 * counted references (+0x40, count +0x48). Written with FUN_00503fb0
 * (func_00503fb0.cpp) and the components' type tests (leaf_009f54b0.cpp). */
#ifndef TLG_GAME_NODE_H
#define TLG_GAME_NODE_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_type.h"
#include "tlg_game_object016b9108.h"

/* a component is an object of the root class: its type at +0x18, its
 * count at +0x8 (a counted reference holds one: FUN_0083c7f0) */
struct Component00503fb0 : public Object016b9108 { /* derived name */
    u8 unknown24[0x16];
    /* +0x3a: flags; FUN_00cf56b0 clears flag 2 of the component of the
     * type the pointer at 0x5948180 holds */
    u8 flags3a;
    u8 unknown3b[5];
    int unknown40; /* +0x40: set to 1 where it is 0 by FUN_00cf56b0 */
    u8 unknown44[0x10];
    Name name; /* +0x54 */
    /* +0x58: a second name, which the scripts
     * Soldier_SoldierHelmet_TractionInvalidArea_Enter and _Leave assign
     * (FUN_0046f770, FUN_0046f980) */
    Name name58;
    u8 unknown5c[0x2c];
    int kind; /* +0x88 */
};

void FUN_01331c10(int *readers); /* derived name */

/* the released mark of a counted object: set when its last reference is
 * dropped on a thread that destroys it at once */
static const int RELEASED = 0xdeadc0de; /* derived name */

extern __thread bool D_16dc088; /* derived name: the thread destroys released objects itself */

/* set for the calling thread while a type's function makes an object
 * (FUN_00cbc5a0: read, set to 1 and put back around `call r13` at 0xcbc759);
 * its readers are not traced */
extern __thread bool D_16dc089; /* derived name */

void FUN_00c14bc0(Object016b9108 *object); /* derived name: releases it later */

/* the value at `value` replaced by `replacement` when it is `expected`;
 * returns the value found (`lock cmpxchg; cmove eax, ecx` at every site: the
 * expected value is returned when the exchange was made).
 *
 * OPEN: 6,415 of the game's 20,959 `lock cmpxchg` are followed by `pushfq;
 * pop rax; push rax; popfq` before the branch (0x2188f3, 0x81a967), every one
 * a 32-bit exchange with a constant zero expected, in the wait loop of a spin
 * lock: the exchange's flags are copied across something that clobbers them.
 * No source form found gives it (the two __sync builtins, the __atomic strong
 * and weak forms, wrappers returning the old value or a bool, 20 lock loops:
 * 35 forms branch on the exchange's flags at once). An empty assembly
 * statement after the exchange reproduced it and stood here until 2026-11-21;
 * it is not code a developer wrote and was removed (docs/DECISIONS.md D88). */
inline int compareAndSwap(int *value, int expected, int replacement) /* derived name */
{
    __atomic_compare_exchange_n(value, &expected, replacement, false, __ATOMIC_SEQ_CST,
                                __ATOMIC_SEQ_CST);
    return expected;
}

/* the same for a pointer (`lock cmpxchg qword; cmove rax, rbx` at 0x45c487),
 * without the barrier: a pointer exchanged against a known null branches on
 * the exchange's flags at once (`xor eax, eax; lock cmpxchg qword [r14+0x30],
 * rcx; je` at 0xc91f5c); relaxed, as the counts are: an ordered exchange is a
 * clobber of every location, and with it 0x5c0fe0 (the reference at +0x50
 * set) takes other registers and 451 bytes for the base's 453; relaxed, all
 * of it but the name's release is the base's. No other function of the
 * module changes */
template <class T>
inline T *compareAndSwap(T **value, T *expected, T *replacement) /* derived name */
{
    __atomic_compare_exchange_n(value, &expected, replacement, false, __ATOMIC_RELAXED,
                                __ATOMIC_RELAXED);
    return expected;
}

/* the same without ordering, for the count of a counted object (the
 * exchange that marks it released: see dropReference) */
inline int compareAndSwapRelaxed(int *value, int expected, int replacement) /* derived name */
{
    __atomic_compare_exchange_n(value, &expected, replacement, false, __ATOMIC_RELAXED,
                                __ATOMIC_RELAXED);
    return expected;
}

/* one more reference to a counted object; the count is left alone once it
 * holds the released mark. The raise is a relaxed add: a caller already
 * holds a reference, so nothing is ordered by it (the base keeps a pointer
 * it stored before the `lock inc` in a register after a call, 0xa07550,
 * where an ordered add would make it read the pointer again) */
template <class T> inline void addReference(T *object) /* derived name */
{
    if (object->references != RELEASED)
        __atomic_fetch_add(&object->references, 1, __ATOMIC_RELAXED);
}

/* one reference less: the last one destroys the object at once on a thread
 * whose flag is set (the count swapped for the released mark first), else
 * hands it to FUN_00c14bc0. The fall and the exchange are relaxed like the
 * raise: the base keeps a local array's block in a register across a loop
 * that drops references (FUN_00f707b0 and its 42 copies: `mov r14, [rbp-0x50]`
 * once at 0xf7082e, freed from r14 at 0xf70a08), which an ordered fall or
 * exchange makes it read again at each pass; no other function of the
 * module changes */
template <class T> inline void dropReference(T *object) /* derived name */
{
    if (object->references != RELEASED &&
        __atomic_fetch_sub(&object->references, 1, __ATOMIC_RELAXED) == 1) {
        if (D_16dc088) {
            int count;
            do
                count = object->references;
            while (compareAndSwapRelaxed(&object->references, count, RELEASED) != count);
            object->destroy();
        } else {
            FUN_00c14bc0(object);
        }
    }
}

/* a counted reference to a node: the count at +0x8 of the node is left
 * alone once it holds the released mark */
template <class T> class Ref00503fb0 /* derived name */
{
  public:
    Ref00503fb0() : object(0) {}

    /* a reference to an object held by pointer (0xbe7e3f: the count raised
     * behind the null test) */
    explicit Ref00503fb0(T *object) : object(object)
    {
        if (object)
            addReference(object);
    }

    Ref00503fb0(const Ref00503fb0 &other) : object(other.object)
    {
        if (object)
            addReference(object);
    }

    ~Ref00503fb0()
    {
        release();
    }

    /* drops the reference and leaves this empty: the pointer is cleared
     * first (`mov qword [rdi], 0` before the count is read); the last
     * reference destroys the object at once on a thread whose flag is set,
     * else hands it to FUN_00c14bc0 */
    void release() /* derived name */
    {
        T *released = object;
        if (released) {
            object = 0;
            dropReference(released);
        }
    }

    T *get() const
    {
        return object;
    }

    bool operator==(const Ref00503fb0 &other) const
    {
        return object == other.object;
    }

  private:
    T *object;
};

/* this thread's flag: set, the thread may use an object a name names
 * whatever the object's own flags say (1,158 sites read it) */
extern __thread bool D_16dc098; /* derived name */

/* the flag read out of line (func_00cbb000.cpp); the link inlines it at
 * every call, and the executable keeps no copy of it */
bool threadMayUse(); /* derived name */

/* whether this thread may use an object a name names: any thread when the
 * object's flag 4 at +0x16 is set, else a thread whose own flag is. T has
 * the field `flags16`. */
template <class T> inline bool isUsable(const T *object) /* derived name */
{
    return (object->flags16 & 4) || D_16dc098;
}

/* the object a name names (the record of its entry in the name table) when
 * this thread may use it and its type at +0x18 is `type` or derives from it,
 * else null; nothing is looked up for a null type. T derives from
 * Object016b9108. The two flags are tested in place, the object's word read
 * before the thread's flag's address (`movzx r, word [obj+0x16]`, then `mov
 * al, [rax]; xor al, 1; test al, 1`: 903 sites); the walk is kindOf's, which
 * hands back the object, so the found object is tested for null again after
 * the walk's loop (0x858390: `test r14, r14` at 0x8583ff). */
template <class T>
inline T *findNamed(const Name &name, const Type00503fb0 *type) /* derived name */
{
    if (type) {
        T *object = static_cast<T *>(D_17ac870[name.index].record18);
        if (object && ((object->flags16 & 4) || D_16dc098))
            return static_cast<T *>(kindOf(object, type));
    }
    return 0;
}

/* the same for an object whose type is `type` itself, its parents not
 * walked (`cmp [rbx+0x18], r15; je` at 0xa5ec82) */
template <class T>
inline T *findNamedOf(const Name &name, const Type00503fb0 *type) /* derived name */
{
    if (type) {
        T *object = static_cast<T *>(D_17ac870[name.index].record18);
        if (object && ((object->flags16 & 4) || D_16dc098))
            return object->type == type ? object : 0;
    }
    return 0;
}

/* a counted reference another thread may replace: the pointer is exchanged
 * by compare-and-swap, then the new object gains a reference and the old one
 * loses its own (FUN_0045c470 sets one from a pointer, FUN_013cfaa0 from
 * another reference, FUN_0079d400 empties one) */
template <class T> class AtomicRef0045c470 /* derived name */
{
  public:
    /* empty (`mov qword [r14+0x30], 0` at 0xc91f3b, before the constructor's
     * body sets it) */
    AtomicRef0045c470() : object(0) {}

    /* a copy holds its own reference (0x1391cd0: the first of two
     * exchanged references copied, `mov r14, [rdi]; test r14, r14; je; cmp
     * dword [r14+8], 0xdeadc0de; je; lea rax, [r14+8]; lock inc dword [rax]`) */
    AtomicRef0045c470(const AtomicRef0045c470 &other) : object(other.object)
    {
        if (object)
            addReference(object);
    }

    /* an object of a class over T goes in: the pointer is converted where
     * it is exchanged and compared (`cmp rsi, rbx` at 0x45c494, the
     * argument first, where an argument of T's own type compares second) */
    template <class U> void set(U *replacement) /* derived name */
    {
        T *old;
        do
            old = object;
        while (compareAndSwap(&object, old, static_cast<T *>(replacement)) != old);
        exchanged(old, replacement);
    }

    /* the other reference is read again at each attempt (`mov rcx, [rsi]`
     * inside the loop at 0x13cfab3) */
    AtomicRef0045c470 &operator=(const AtomicRef0045c470 &other)
    {
        T *old, *replacement;
        do {
            old = object;
            replacement = other.object;
        } while (compareAndSwap(&object, old, replacement) != old);
        exchanged(old, replacement);
        return *this;
    }

    /* the reference is dropped the plain way, the pointer cleared first
     * without an exchange (`mov r12, [r15]; test; mov qword [r15], 0` at
     * 0xf1aa96, after the destructor's body emptied the same member by
     * compare-and-swap; the same at 0x4aca44) */
    ~AtomicRef0045c470()
    {
        T *released = object;
        if (released) {
            object = 0;
            dropReference(released);
        }
    }

    void clear() /* derived name */
    {
        T *old;
        do
            old = object;
        while (compareAndSwap(&object, old, static_cast<T *>(0)) != old);
        if (old)
            dropReference(old);
    }

    /* drops the reference without an exchange, as the reference's last
     * use does: the pointer cleared first, then the count lowered (the last
     * element of an array at 0x81abc4: `mov r15, [rcx+rax*8]; test r15,
     * r15; je; mov qword [rcx+rax*8], 0`) */
    void release() /* derived name */
    {
        T *released = object;
        if (released) {
            object = 0;
            dropReference(released);
        }
    }

    /* the object as it is now (`cmp qword [rbx+0x38], 0` at 0x4ab651) */
    T *get() const
    {
        return object;
    }

  private:
    /* the counts after an exchange: nothing when the same object went in */
    static void exchanged(T *old, T *replacement) /* derived name */
    {
        if (replacement != old) {
            if (replacement)
                addReference(replacement);
            if (old)
                dropReference(old);
        }
    }

    T *object;
};

/* the scene node: the root class's object with its components (+0x58,
 * count +0x60) and its children (+0x40, count +0x48), its own members from
 * the root class's end on */
class Node00503fb0 : public Object016b9108 /* derived name */
{
  public:
    /* the component at a signed index (`movsxd` at each use under an unsigned
     * counter: 0x9f54b0, 0x5065f0) */
    Component00503fb0 *componentAt(int index) const /* derived name */
    {
        return components[index];
    }

    /* the child at a signed index (`movsxd` under an unsigned counter at
     * 0x83c9c4), read without a reference of its own */
    Node00503fb0 *childAt(int index) const /* derived name */
    {
        return children[index].get();
    }

    /* the first component from `next` on whose type is `type` or derives
     * from it; `next` is left after it */
    Component00503fb0 *findComponent(const Type00503fb0 *type, unsigned &next) /* derived name */
    {
        FUN_01331c10(&readers);
        Component00503fb0 *found = 0;
        for (unsigned i = next; i < componentCount; ++i) {
            if (::isKindOf(componentAt(i)->type, type)) {
                found = componentAt(i);
                next = i + 1;
                break;
            }
        }
        __sync_fetch_and_sub(&readers, 1);
        return found;
    }

    /* the first component whose type is `type` or derives from it */
    Component00503fb0 *findComponent(const Type00503fb0 *type) /* derived name */
    {
        unsigned next = 0;
        return findComponent(type, next);
    }

    int unknown24; /* +0x24: the index of the object's handler in a visitor's table (FUN_00589590) */
    /* +0x28: FUN_00c5a160 reads it first, and a caller hands it the node
     * only while it is set (0x7a9ba2) */
    void *unknown28;
    int readers;                         /* +0x30 */
    Node00503fb0 *parent;                /* +0x38 */
    Ref00503fb0<Node00503fb0> *children; /* +0x40 */
    unsigned childCount;                 /* +0x48 */
    u8 unknown4c[0xc];
    Component00503fb0 **components; /* +0x58 */
    unsigned componentCount;        /* +0x60 */
};

/* derived name: not traced; reads the node's +0x28 and calls its slot 6
 * with the node */
void FUN_00c5a160(Node00503fb0 *node);

/* two values exchanged through a copy of the first (0x1391cd0 over two
 * references another thread may replace; inlined at 0xa055f0 over two
 * members, both addresses formed first: `lea rdx, [rdi+0x10]; lea r15,
 * [rdi+0x20]`) */
template <class T> inline void exchange(T &first, T &second) /* derived name */
{
    T held(first);
    first = second;
    second = held;
}

#endif
