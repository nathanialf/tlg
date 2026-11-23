/* src/include/tlg_game_object00774560.h: the class whose vtable is at
 * 0x16acd78 and whose destructor is 0x774560, a base of several game classes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00774560_H
#define TLG_GAME_OBJECT00774560_H

#include <float.h>

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016b85e0.h"

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

inline Vector0077bac0 operator-(const Vector0077bac0 &a, const Vector0077bac0 &b)
{
    return Vector0077bac0(a.x - b.x, a.y - b.y, a.z - b.z);
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

/* derived name: a point turned by a rotation, returned through the hidden
 * pointer as a whole point, its w the point's (0x1343bc3: `mov eax, [rsi+0xc]`,
 * stored at +0xc of the result; 0x773e0b: the result's 16 bytes copied with
 * `vmovaps`; 0x777c36: the callers that add it read its x, y and z) */
Float4A FUN_01343bb0(const Float4A &point, const Float4A &rotation);

/* derived names: a tracker of the body's (+0x50e0): its value at +0x30
 * set by slot 17 of the holders, the whole cleared to its start when the
 * held object's int at +0x58 is zero (FUN_00777cb0) */
struct alignas(16) TrackerA00777cb0 { /* derived name */

    void reset() /* derived name */
    {
        unknown0 = 0;
        unknown10 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        unknown20 = FLT_MAX;
        unknown24 = 0.0f;
        unknown28 = 0.0f;
        unknown2c = -1;
        unknown30 = 0;
    }

    int unknown0; /* +0x0 */
    u8 unknown4[0xc];
    Float4A unknown10; /* +0x10 */
    float unknown20;   /* +0x20 */
    /* +0x24, +0x28: floats, their zero stores kept apart from the ints'
     * (four int stores in a row are one vector store) */
    float unknown24;
    float unknown28;
    int unknown2c; /* +0x2c */
    int unknown30; /* +0x30 */
};

/* derived names: the body's other trackers (+0x5180 and +0x51e0, 0x60
 * bytes each): the value at +0x5c set by slot 17 of the holders, the whole
 * cleared when the held object's int at +0x58 is zero (FUN_0079c700) */
struct alignas(16) TrackerB0079c700 { /* derived name */

    void reset() /* derived name */
    {
        unknown0 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        unknown10 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        unknown20 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        unknown30 = 0;
        unknown34 = FLT_MAX;
        unknown38 = FLT_MAX;
        unknown3c = FLT_MAX;
        unknown44 = -1;
        unknown48 = 0;
        unknown4c = 0;
        unknown50 = 0;
        unknown54 = 0;
        unknown58 = 0;
        unknown5c = 0;
    }

    Float4A unknown0;  /* +0x0 */
    Float4A unknown10; /* +0x10 */
    Float4A unknown20; /* +0x20 */
    int unknown30;     /* +0x30 */
    float unknown34;   /* +0x34 */
    float unknown38;   /* +0x38 */
    float unknown3c;   /* +0x3c */
    int unknown40;     /* +0x40: not cleared */
    int unknown44;     /* +0x44 */
    int unknown48;     /* +0x48 */
    int unknown4c;     /* +0x4c */
    int unknown50;     /* +0x50 */
    int unknown54;     /* +0x54 */
    int unknown58;     /* +0x58 */
    int unknown5c;     /* +0x5c */
};

/* derived names: slot 17's argument: at +0x58 an object whose int at
 * +0x120 picks the body's second tracker when it is 1 (FUN_0079c700) */
struct Chooser0079c700 { /* derived name */
    u8 unknown0[0x120];
    int unknown120; /* +0x120 */
};

struct Context0079c700 { /* derived name */
    u8 unknown0[0x58];
    Chooser0079c700 *unknown58; /* +0x58 */
    u8 unknown60[0x70];
    /* +0xd0, +0xe0: a rotation and a point, turned and moved by the body's
     * in Object016ad7a0's slot 17 (FUN_00799560), as a pose's */
    Float4A rotationd0;
    Float4A pointe0;
};

/* derived names: the body's tracker at +0x4fe0, the int at +0x68 set by
 * Object016ad7a0's slot 17, the whole cleared when its first link's held
 * object has a zero at +0x58 (FUN_00799560) */
struct alignas(16) TrackerC00799560 { /* derived name */

    void reset() /* derived name */
    {
        unknown0 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        unknown10 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        unknown20 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        unknown30 = 0;
        unknown34 = FLT_MAX;
        unknown38 = FLT_MAX;
        unknown3c = FLT_MAX;
        unknown40 = FLT_MAX;
        unknown44 = 0;
        unknown48 = -1;
        unknown4c = 1.0f;
        unknown50 = 0.0f;
        unknown54 = 0.0f;
        unknown58 = 0.0f;
        unknown5c = 0.0f;
        unknown60 = FLT_MAX;
        unknown64 = FLT_MAX;
        unknown68 = 0;
    }

    Float4A unknown0;  /* +0x0 */
    Float4A unknown10; /* +0x10 */
    Float4A unknown20; /* +0x20 */
    int unknown30;     /* +0x30 */
    float unknown34;   /* +0x34 */
    float unknown38;   /* +0x38 */
    float unknown3c;   /* +0x3c */
    float unknown40;   /* +0x40 */
    int unknown44;     /* +0x44 */
    int unknown48;     /* +0x48 */
    float unknown4c;   /* +0x4c */
    float unknown50;   /* +0x50 */
    float unknown54;   /* +0x54 */
    float unknown58;   /* +0x58 */
    float unknown5c;   /* +0x5c */
    float unknown60;   /* +0x60 */
    float unknown64;   /* +0x64 */
    int unknown68;     /* +0x68 */
};

/* derived names: a 0x90-byte record of the body's part at +0x4f80: an
 * object at +0x78 and a value at +0x80, which Object016ad7a0's slot 17
 * matches against its first link's (FUN_00799560); the rest is not
 * traced */
struct Record00799560 { /* derived name */
    u8 unknown0[0x78];
    Object016b9108 *object; /* +0x78 */
    void *value;            /* +0x80 */
    u8 unknown88[0x8];
};

/* derived names: the body's part at +0x4f80: its records at +0x38; the
 * rest is not traced */
struct Part00799560 { /* derived name */
    u8 unknown0[0x38];
    Array05943280<Record00799560> records; /* +0x38 */
    u8 unknown50[0x10];
};

/* derived names: the body's object at +0xc00 keeps two ints at +0x60 and
 * +0x64; a change to either sets its flag bit 2 (`or byte [rax+0x20], 4`
 * only where the value differs: the overrides of slot 6 in func_00775420.cpp,
 * Object016accb0's slot 7) */
struct State00774760 : public Object016b9108 { /* derived name */

    void setUnknown60(int value) /* derived name */
    {
        if (unknown60 != value) {
            unknown60 = value;
            flags |= 4;
        }
    }

    void setUnknown64(int value) /* derived name */
    {
        if (unknown64 != value) {
            unknown64 = value;
            flags |= 4;
        }
    }

    u8 unknown24[0x3c];
    int unknown60; /* +0x60 */
    int unknown64; /* +0x64 */
};

/* derived names: what the pointer at +0x68 of the class below holds: a
 * rotation at +0xb90, a point at +0xba0 and where they are put back to
 * (the slot-14 overrides FUN_0077bac0 and on); the rest is not traced */
/* derived names: what slot 21 is given (FUN_00774b50): two floats; not
 * traced further */
struct Source00774b50 { /* derived name */
    u8 unknown0[0x94];
    float unknown94; /* +0x94: counted only when below zero */
    u8 unknown98[0x6c];
    float unknown104; /* +0x104 */
};

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

    u8 unknown0[0xd0];
    float unknownd0; /* +0xd0: a scale, by slot 21's use (FUN_00774b50) */
    u8 unknownd4[0xa34];
    int unknownb08; /* +0xb08: masked by Object016accb0's int at +0x168 in its slot 7 */
    u8 unknownb0c[0x84];
    Float4A rotation; /* +0xb90 */
    /* +0xba0: a point; slot 14 moves its x, y and z (follow(), the w left
     * as it is), FUN_0079d4a0 sets it whole from +0x13c0, one aligned copy */
    Float4A position;
    u8 unknownbb0[0x50];
    State00774760 *unknownc00; /* +0xc00 */
    u8 unknownc08[0x728];
    int unknown1330; /* +0x1330: while it is not zero slot 14 leaves the body where it put it back (FUN_0079d4a0) */
    u8 unknown1334[0x5c];
    /* +0x1390, +0x13a0, +0x13d0, +0x13f0: copied out with +0x1330, +0x13c0
     * and +0x13e0 by Object016ad480's slot 11 (FUN_0078b710); not traced */
    Float4A unknown1390;
    Float4A unknown13a0;
    u8 unknown13b0[0x10];
    Float4A unknown13c0; /* +0x13c0: the point the body is put back to */
    Float4A unknown13d0;
    Float4A unknown13e0; /* +0x13e0: the rotation the body is put back to */
    Float4A unknown13f0;
    u8 unknown1400[0x40];
    Vector0077bac0 unknown1440; /* +0x1440: taken off the pose's position by FUN_00799350 */
    u8 unknown144c[0x6c0];
    int unknown1b0c; /* +0x1b0c: copied to +0x3c of the object by FUN_007950a0 */
    u8 unknown1b10[0x108];
    /* +0x1c18: 39, 40 or 41 choose where Object016accb0's slot 7 takes the
     * rotation from (FUN_007701b0) */
    int unknown1c18;
    u8 unknown1c1c[0x3364];
    Part00799560 part4f80;     /* +0x4f80 */
    TrackerC00799560 trackerC; /* +0x4fe0 */
    u8 unknown5050[0x10];
    Float4A unknown5060; /* +0x5060: a copy of the point FUN_00799350 sets */
    u8 unknown5070[0x70];
    TrackerA00777cb0 trackerA; /* +0x50e0 */
    u8 unknown5120[0x60];
    TrackerB0079c700 trackerB1; /* +0x5180 */
    TrackerB0079c700 trackerB2; /* +0x51e0 */
    u8 unknown5240[0x58fc - 0x5240];
    int unknown58fc; /* +0x58fc: cleared by Object016acbe8's slot 15 (FUN_0076cd70) */
    u8 unknown5900[0x62d0 - 0x5900];
    /* +0x62d0: the int at +0x3e0 of the component Object016ac990's slot 17
     * finds (FUN_00765280) */
    int unknown62d0;
    u8 unknown62d4[0xc];
    /* +0x62e0, +0x62e8: counted references another thread may replace,
     * set from Object016ac990's at +0x110 and +0x118 by its slot 17 */
    AtomicRef0045c470<Object016b85e0> unknown62e0;
    AtomicRef0045c470<Object016b85e0> unknown62e8;
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

/* derived names: the object at +0x58 of a pose: points at +0xe0 (FUN_00761f10)
 * and +0x110 (Object016accb0's slot 19), four-byte aligned (`vmovups`); the
 * rest is not traced */
struct Held00773d80 { /* derived name */
    u8 unknown0[0xe0];
    Float4 unknowne0; /* +0xe0 */
    u8 unknownf0[0x20];
    Float4 unknown110; /* +0x110 */
};

/* derived names: the argument of slots 7, 14 and 19: its group at +0x38, the
 * object at +0x58 (Object016accb0's slot 19), a
 * rotation and a point at +0x80 and +0x90 (Object016accb0's slot 7),
 * rotations at +0xd0 and +0x160, a point at +0xe0 and a position at +0x170
 * (slot 7 of the class at 0x16ac8c8, FUN_00761f10, reads +0xd0 and +0xe0 of
 * its argument as slot 14 does); the rest is not traced */
struct Pose0077bac0 { /* derived name */
    u8 unknown0[0x38];
    Group00790150 *group; /* +0x38 */
    u8 unknown40[0x18];
    Held00773d80 *unknown58; /* +0x58 */
    u8 unknown60[0x20];
    Float4A rotation80; /* +0x80 */
    Float4A point90;    /* +0x90 */
    u8 unknowna0[0x30];
    Float4A rotationd0; /* +0xd0 */
    Float4A pointe0;    /* +0xe0 */
    u8 unknownf0[0x70];
    Float4A rotation;        /* +0x160 */
    Vector0077bac0 position; /* +0x170 */
};

/* derived names: the object at +0x70 of the class below: handed to
 * FUN_0136b6f0 by slot 6 (func_00775420.cpp); a point at +0xd0 set by
 * Object016accb0's slot 19 (FUN_00773d80); the rest is not traced */
struct Object0136b6f0 { /* derived name */
    u8 unknown0[0xc8];
    int unknownc8; /* +0xc8: cleared by Object016ad480's slot 6 (FUN_00785d40) */
    u8 unknowncc[0x4];
    Float4A unknownd0; /* +0xd0 */
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
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void
    slot6(); /* derived name; FUN_00774760 (func_00775420.cpp, a free function there) */
    virtual void slot7(Pose0077bac0 *pose); /* derived name; FUN_00774820 (func_00775420.cpp) */
    virtual void slot8();                   /* derived name; FUN_00774890, not traced */
    virtual void slot9();                   /* derived name; FUN_007748a0, not traced */
    virtual void slot10();                  /* derived name; FUN_007748b0, not traced */
    virtual void slot11();                  /* derived name; FUN_007748c0, not traced */
    virtual void slot12();                  /* derived name; FUN_007748d0, not traced */
    virtual void slot13();                  /* derived name; FUN_007748e0, not traced */
    /* FUN_007748f0, empty; the derived classes' FUN_0077bac0 and
     * FUN_0077c5a0 turn the body at +0x68 by the pose and move it */
    virtual void slot14(Pose0077bac0 *pose);       /* derived name */
    virtual void slot15();                         /* derived name; FUN_00774900, not traced */
    virtual void slot16();                         /* derived name; FUN_00774910, not traced */
    virtual void slot17(Context0079c700 *context); /* derived name; FUN_00774920, not traced */
    virtual void slot18();                         /* derived name; FUN_00774930, not traced */
    virtual void slot19(Pose0077bac0 *pose);       /* derived name; FUN_00774940, empty */
    /* FUN_00774950, not written: given a rotation, the third argument of
     * slot 21, an offset and two ints (slot 21 passes 1 and its own) */
    virtual int slot20(const Float4A &rotation, void *target, const Float4A &offset, int unknown,
                       int flag); /* derived name */
    /* FUN_00774b50 (func_00775420.cpp): slot 20 with this file's VECTOR_W
     * and an offset up by the source's lift (+0x94, when below zero, and
     * +0x104) times the body's scale at +0xd0, slot 20's answer returned
     * (rax kept over the stack check) */
    virtual int slot21(const Source00774b50 *source, void *target, int flag); /* derived name */
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
    Body0077bac0 *unknown68;   /* +0x68 */
    Object0136b6f0 *unknown70; /* +0x70 */
    u8 unknown78[0x4];
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
    u8 unknowne8[0x8];

  protected:
    /* +0xf0: 0.25 from Object016accb0's constructor (FUN_0076e4a0), 0.3
     * from Object016ad9f8's (FUN_0079c900); not traced */
    float unknownf0;

  private:
    /* +0xf4, +0xf8: 1 and 0.0 from slot 6 (FUN_00774760); the derived
     * classes' own fields start after them, at +0xfc */
    int unknownf4;
    float unknownf8;
};

#endif
