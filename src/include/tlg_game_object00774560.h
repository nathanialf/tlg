/* src/include/tlg_game_object00774560.h: the class whose vtable is at
 * 0x16acd78 and whose destructor is 0x774560, a base of several game classes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00774560_H
#define TLG_GAME_OBJECT00774560_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_array.h"
#include "tlg_game_object016b9108.h"

/* derived names: a three-float vector, added lane by lane into a new value
 * (0x77bb12 to 0x77bb52: the three loads of one operand and the three adds
 * before the three stores, each lane a scalar add: with its own copy
 * constructor a vector returned by value travels through the hidden pointer,
 * not as two lanes in one register and a third in another; four-byte
 * aligned: FUN_01343bb0's result sits below the 16-byte product in
 * FUN_00777b10's frame) */
struct Vector0077bac0 { /* derived name */
    float x;
    float y;
    float z;

    Vector0077bac0(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    Vector0077bac0(const Vector0077bac0 &o) : x(o.x), y(o.y), z(o.z) {}

    /* a point's x, y and z */
    explicit Vector0077bac0(const Float4A &p) : x(p.x), y(p.y), z(p.z) {}
};

inline Vector0077bac0 operator+(const Vector0077bac0 &a, const Vector0077bac0 &b)
{
    return Vector0077bac0(a.x + b.x, a.y + b.y, a.z + b.z);
}

/* derived name: a vector scaled, the factor read first (0x762b6e) */
inline Vector0077bac0 operator*(float s, const Vector0077bac0 &v)
{
    return Vector0077bac0(s * v.x, s * v.y, s * v.z);
}

/* derived names: a point moved by a vector, its w kept (0x777bdf to
 * 0x777c71: the w read as an int and stored back as one) */
inline Float4A operator+(const Float4A &point, const Vector0077bac0 &v)
{
    return Float4A(point.x + v.x, point.y + v.y, point.z + v.z, point.w);
}

/* derived name: the product of two rotations, returned through the hidden
 * pointer (the product's slot in rdi, the two operands in rsi and rdx) */
Float4A FUN_013439c0(const Float4A &first, const Float4A &second);

/* derived name: a point turned by a rotation, the vector returned through
 * the hidden pointer (0x777c36) */
Vector0077bac0 FUN_01343bb0(const Float4A &point, const Float4A &rotation);

/* derived names: what the pointer at +0x68 of the class below holds: a
 * rotation at +0xb90, a point at +0xba0 and where they are put back to
 * (the slot-14 overrides FUN_0077bac0 and on); the rest is not traced */
struct Body0077bac0 { /* derived name */

    /* the rotation turned by another (the other's address formed before
     * the body's: `lea rdx, [r14+0x160]` before `lea rsi, [r12+0xb90]` at
     * 0x79d4fa) */
    void turn(const Float4A &by) /* derived name */
    {
        rotation = FUN_013439c0(rotation, by);
    }

    /* the point moved by a vector, its w left as it is */
    void move(const Vector0077bac0 &by) /* derived name */
    {
        position = position + by;
    }

    u8 unknown0[0xb90];
    Float4A rotation; /* +0xb90 */
    /* +0xba0: a point; slot 14 moves its x, y and z (follow(), the w left
     * as it is), FUN_0079d4a0 sets it whole from +0x13c0, one aligned copy */
    Float4A position;
    u8 unknownbb0[0x780];
    int unknown1330; /* +0x1330: while it is not zero slot 14 leaves the body where it put it back (FUN_0079d4a0) */
    u8 unknown1334[0x8c];
    Float4A unknown13c0; /* +0x13c0: the point the body is put back to */
    u8 unknown13d0[0x10];
    Float4A unknown13e0; /* +0x13e0: the rotation the body is put back to */
    u8 unknown13f0[0x71c];
    int unknown1b0c; /* +0x1b0c: copied to +0x3c of the object by FUN_007950a0 */
};

/* derived names: a member of a pose's group: a Name at +0x34; the rest is
 * not traced */
struct Member00790150 { /* derived name */
    u8 unknown0[0x34];
    Name name; /* +0x34 */
};

/* derived names: a pose's group: its members, an array at +0x4dc0 (the
 * block, the count at +0x4dc8 read once before the search); the rest is not
 * traced */
struct Group00790150 { /* derived name */
    u8 unknown0[0x4dc0];
    Array05943280<Member00790150 *> members; /* +0x4dc0 */
};

/* derived names: the argument of slot 14: its group at +0x38, rotations at
 * +0xd0 and +0x160, a point at +0xe0 and a position at +0x170; the rest is
 * not traced */
struct Pose0077bac0 { /* derived name */
    u8 unknown0[0x38];
    Group00790150 *group; /* +0x38 */
    u8 unknown40[0x90];
    Float4A rotationd0; /* +0xd0 */
    Float4A pointe0;    /* +0xe0 */
    u8 unknownf0[0x70];
    Float4A rotation;        /* +0x160 */
    Vector0077bac0 position; /* +0x170 */
};

/* derived names: the class whose vtable is at 0x16acd78
 * (config/vtables.derived.base.txt, stored by FUN_00774370 and its two
 * destructors), derived from Object016b9108: its slots 2 to 4 are the
 * base's, slots 5 to 22 its own (declared; their bodies are not written).
 * The classes of leaf_00761150.cpp, leaf_00765600.cpp and the others that
 * include this header derive from it: their destructors tail-call its
 * complete destructor (FUN_00774560, leaf_00774560.cpp), the key function.
 * Its own fields from +0x24 are traced only where that destructor releases
 * them (the Names at +0xe4, +0xe0). */
class Object00774560 : public Object016b9108 /* derived name */
{
  public:
    Object00774560(
        const Name &
            name); /* 0x774370, its row named after it (D15): the derived classes' creators call it (FUN_00763020) */
    virtual ~Object00774560();
    virtual void slot5();  /* derived name; FUN_001af750, not traced */
    virtual void slot6();  /* derived name; FUN_00774760, not traced */
    virtual void slot7();  /* derived name; FUN_00774820, not traced */
    virtual void slot8();  /* derived name; FUN_00774890, not traced */
    virtual void slot9();  /* derived name; FUN_007748a0, not traced */
    virtual void slot10(); /* derived name; FUN_007748b0, not traced */
    virtual void slot11(); /* derived name; FUN_007748c0, not traced */
    virtual void slot12(); /* derived name; FUN_007748d0, not traced */
    virtual void slot13(); /* derived name; FUN_007748e0, not traced */
    /* FUN_007748f0, empty; the derived classes' FUN_0077bac0 and
     * FUN_0077c5a0 turn the body at +0x68 by the pose and move it */
    virtual void slot14(Pose0077bac0 *pose); /* derived name */
    virtual void slot15();                   /* derived name; FUN_00774900, not traced */
    virtual void slot16();                   /* derived name; FUN_00774910, not traced */
    virtual void slot17();                   /* derived name; FUN_00774920, not traced */
    virtual void slot18();                   /* derived name; FUN_00774930, not traced */
    virtual void slot19();                   /* derived name; FUN_00774940, not traced */
    virtual void slot20();                   /* derived name; FUN_00774950, not traced */
    virtual void slot21();                   /* derived name; FUN_00774b50, not traced */
    /* FUN_000058a0 returns 1; tested `test eax, eax` before slot 14's work
     * (FUN_00777b10) */
    virtual int slot22(); /* derived name */

  protected:
    /* the body at +0x68 turned by the pose's rotation (the body read once
     * for the product and its store) and moved by the pose's position (the
     * body read again): the whole of Object016ad2f0's slot 14
     * (FUN_0077bac0) and the start of Object016ace40's (FUN_00777b10, whose
     * second product reuses this one's slot: the temporary of an inlined
     * call ends with it) */
    void follow(const Pose0077bac0 *pose) /* derived name */
    {
        unknown68->turn(pose->rotation);
        unknown68->move(pose->position);
    }

    /* the body at +0x68 put back to its point and rotation at +0x13c0 and
     * +0x13e0, then, unless its int at +0x1330 is set, turned and moved by
     * the pose (FUN_0079d4a0, FUN_007950a0, FUN_007a0710; the body read
     * again for each statement: `mov rax, [rbx+0x68]` before each copy) */
    void followFromHome(const Pose0077bac0 *pose) /* derived name */
    {
        goHome();
        if (!unknown68->unknown1330)
            follow(pose);
    }

    /* the body at +0x68 put back to its point and rotation at +0x13c0 and
     * +0x13e0 (also the start of FUN_00762b30) */
    void goHome() /* derived name */
    {
        unknown68->position = unknown68->unknown13c0;
        unknown68->rotation = unknown68->unknown13e0;
    }

    u8 unknown24[0x18];
    /* +0x3c, +0x40: both set by Object016ad548's slot 14 (FUN_00790150) to
     * whether the pose's group holds a member of this object's name; +0x3c
     * by Object016ad6d8's (FUN_007950a0) to the body's int at +0x1b0c */
    int unknown3c;
    int unknown40;
    u8 unknown44[0x24];
    Body0077bac0 *unknown68; /* +0x68 */
    u8 unknown70[0xc];
    /* +0x7c: zero from this constructor, and again in the body of FUN_00763020's
     * (`mov dword [r15+0x7c], 0` last); 0.2 in FUN_00794290's (`mov dword
     * [rbx+0x7c], 0x3e4ccccd`): a float; not traced */
    float unknown7c;

  private:
    u8 unknown80[0x60];

  protected:
    Name namee0; /* +0xe0: released by the destructor (`mov eax, [rbx+0xe0]; shl 5`) */

  private:
    Name namee4; /* +0xe4: released by the destructor (`mov eax, [rbx+0xe4]; shl 5`) */
};

#endif
