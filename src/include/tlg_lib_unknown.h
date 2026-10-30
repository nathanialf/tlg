/* Library-region objects of unknown class, each reached by two matched
 * accessors of one field, the pair shown by a caller that uses both on the
 * same object. derived names throughout. */
#ifndef TLG_LIB_UNKNOWN_H
#define TLG_LIB_UNKNOWN_H

#include "tlg_hk_reflect.h"
#include "tlg_hk_thread.h"
#include "tlg_sce_fios.h"
#include "tlg_simd.h"
#include "tlg_types.h"

/* FUN_00180f50 reads +0x10 through FUN_00004580 and, when it differs from
 * the value it computed, writes it through FUN_00004590. */
struct Value10Owner {
    u8 unknown0[0x10];
    s32 value;
};

/* FUN_0000b660 and FUN_0000b670 sit in adjacent vtable slots (0x168d600,
 * 0x168d608): a setter and a getter of the int at +0x40. FUN_00061f40
 * compares the value against 1. */
struct Mode40Owner {
    u8 unknown0[0x40];
    s32 mode;
};

/* FUN_0003d7d0 reads +8 through FUN_00010650 and +0xc through FUN_00034840
 * on the same object (its own +0x18) and sign-extends the first.
 * FUN_00161cc0 reads the byte at +2 (FUN_000348c0), +8, +0xc and the byte
 * at +5 (FUN_00034890) of one object. The functions at 0x2b010 to 0x2b120
 * walk `count` 32-byte entries from +0x40 (floats at +0xc and +0x1c of
 * each); FUN_0002b0b0 sets the byte at +5 to 3, FUN_00072dc0 then clears
 * the pointer at +0x38 through FUN_00034950, and FUN_0002b180 adds into the
 * object it points to. The forwarders at 0x34810 to 0x34970 call the
 * 0x2b0xx functions from another file. */
struct Pair08Target; /* a u16 at +0x20 and a 16-byte sum at +0x40 */

struct Pair08Owner {
    /* Bit 3 cleared and bit 5 set by FUN_0002b0c0. derived name. */
    u8 flags0;
    u8 flags; /* bit 2 set and cleared by FUN_0002b390; derived name */
    u8 count;
    u8 type; /* indexes the tail sizes at 0x14b8690 (FUN_0002af30); derived name */
    u8 unknown4;
    u8 state;
    u8 unknown6[2];
    s32 first;
    s32 second;
    /* FUN_0002b0c0 sets the mode at +0x1d, 0xff at +0x1c and a float at
     * +0x18, and bit 5 of flags0 for modes 2 and 3 when both ints at +0x10
     * and +0x14 are nonzero. derived names. */
    s32 value10;
    s32 value14;
    float value18;
    u8 value1c;
    u8 mode;
    u8 unknown1e[2];
    /* The direction the entries' rows act along (FUN_00031740 projects the
     * motions' linear velocities on it). derived name. */
    Vec4 direction;
    u8 unknown30[8];
    Pair08Target *target;
};

/* One of the 32-byte entries after the owner's 0x40 bytes: two vectors,
 * each with a value in its w (valueA and valueB below). FUN_0002b0f0 scales
 * valueA of each, FUN_0002b120 valueB where it is positive; FUN_0002b010
 * and FUN_0002b030 return their addresses by index. FUN_0002b620 takes
 * valueB from the whole second vector (its loop's address is the vector's,
 * +0x50, with the lane at +0xc). */
struct Pair08Entry {
    Vec4 vectorA; /* derived name; valueA in its w */
    Vec4 vectorB; /* derived name; valueB in its w */
};

/* What a record of type 3 or 4 carries after its entries, 144 bytes
 * (FUN_0002af30 skips them): three rows of three vectors 48 bytes apart,
 * the first two of each with a value in their w that FUN_0002b040 scales,
 * the first factor taking the second vector's of rows 0 and 1 and the
 * first's of row 2. derived names. */
struct Pair08Extra /* derived name */
{
    struct Row {
        Vec4 vectorA; /* derived name */
        Vec4 vectorB; /* derived name */
        Vec4 vectorC; /* derived name */
    };

    Row rows[3]; /* derived name */
};

float *FUN_0002b010(Pair08Owner *self, int index);                /* derived name */
float *FUN_0002b030(Pair08Owner *self, int index);                /* derived name */
void FUN_0002b040(Pair08Owner *self, float scaleA, float scaleB); /* derived name */
void FUN_0002b0b0(Pair08Owner *self);                             /* derived name */
void FUN_0002b0c0(Pair08Owner *self, int mode, float value);      /* derived name */
void FUN_0002b0f0(Pair08Owner *self, float scale);                /* derived name */
void FUN_0002b120(Pair08Owner *self, float scale);                /* derived name */
/* Out-of-line forwarders to the two scales (0x34900, 0x34910). derived
 * names. */
void FUN_00034900(Pair08Owner *self, float scale); /* derived name */
void FUN_00034910(Pair08Owner *self, float scale); /* derived name */
/* Out-of-line forwarders to the state's set (0x34930) and the target's
 * store (0x34950). derived names. */
void FUN_00034930(Pair08Owner *self);                       /* derived name */
void FUN_00034950(Pair08Owner *self, Pair08Target *target); /* derived name */

/* A modifier as the cache callbacks reach it (derived names): slot 5
 * takes the thread's context, the shared data, the two bodies, the cache
 * and an int. */
class CacheModifier0017a000 /* derived name */
{
  public:
    virtual void unknownVirtual0();
    virtual void unknownVirtual1();
    /* Slot 2: a bit for each callback the modifier takes part in, the
     * index of its set in the manager (0x66650). derived name. */
    virtual u32 unknownVirtual2();
    virtual void unknownVirtual3();
    virtual void unknownVirtual4();
    virtual void unknownVirtual5(const void *threadContext, const void *sharedData,
                                 const void *bodyA, const void *bodyB,
                                 hknpManifoldCollisionCache *cache, int value) const;
};

/* Slot 5 of every modifier whose mask meets the cache's, when any does: a
 * set whose masks meet the cache's has at least one modifier. Inline in
 * the collision detectors' slot 3 (0x72d30) and out of line as 0x17a000.
 * derived name. */
inline void fireCacheModifiers(hknpManifoldCollisionCache *cache, /* derived name */
                               const hknpWorldContextPool::Context *threadContext,
                               const void *sharedData, const void *bodyA, const void *bodyB,
                               int value)
{
    const u32 enabled = cache->enabledModifiers;
    const hknpModifierManager::ModifierSet *modifiers =
        &threadContext->modifierManager->modifierSets[0];
    if (modifiers->enabledModifiers & enabled) {
        int i = 0;
        do {
            if (modifiers->entries[i].mask & enabled) {
                modifiers->entries[i].modifier->unknownVirtual5(threadContext, sharedData, bodyA,
                                                                bodyB, cache, value);
            }
        } while (++i < modifiers->numModifiers);
    }
}

void FUN_0017a000(hknpManifoldCollisionCache *cache,
                  const hknpWorldContextPool::Context *threadContext, const void *sharedData,
                  const void *bodyA, const void *bodyB, int value); /* derived name */

/* The collision detector of vtable 0x169b220 (address point 0x169b230,
 * 16 bytes, no type info; built in place at +0x98 of the default modifier
 * set, 0x49e6c, its int at +0xa0 zero; derived names): slots 0 and 2 are
 * the shared empty 0x3b640, slot 1 the 16-byte delete 0x13e50. Slot 3
 * (0x72d30) passes a cache of three quads or more to the callback, slot 5,
 * of every modifier of the shared data's list (+0x38) whose mask meets the
 * cache's; slot 4 (0x72dc0) first lets the cache's solver record go
 * (0x34930), unbinds its target and clears the cache's reference. The
 * fourth and fifth arguments are not read. */
class CollisionDetector169b230 /* derived name */
{
  public:
    virtual ~CollisionDetector169b230();
    virtual void unknownVirtual2();
    virtual void FUN_00072d30(const hknpWorldContextPool::Context *threadContext,
                              const void *sharedData, hknpManifoldCollisionCache *cache,
                              const void *argument4, const void *argument5, const void *bodyA,
                              const void *bodyB, int value); /* derived names */
    virtual void FUN_00072dc0(const hknpWorldContextPool::Context *threadContext,
                              const void *sharedData, hknpManifoldCollisionCache *cache,
                              const void *argument4, const void *argument5, const void *bodyA,
                              const void *bodyB, int value); /* derived names */

    int unknown8;
};

/* A new manifold's points (derived names): their count at +0 and their
 * positions from +0x40 (hknpSurfaceVelocityModifier's slot 7, 0x16d22a,
 * averages them). */
struct hknpManifold /* derived name */
{
    int numPoints; /* derived name */
    u8 unknown4[0x2c];
    /* Each point's distance, a lane each (0x156e90). derived name. */
    float distances[4];
    Vec4 positions[4]; /* derived name */
    u8 unknown80[0x28];
    hknpManifoldCollisionCache *collisionCache; /* derived name */
    u8 unknownB0[0x30];
    /* The bodies' mass scales, each broadcast (the mass changer's slot 4,
     * 0x69450, writes them). derived names. */
    Vec4 massScaleA;
    Vec4 massScaleB;
};

/* The modifier of vtable 0x169a5a0 (address point 0x169a5b0, no type info,
 * 8 bytes: slot 1 is the shared 0xd900; derived name after the materials'
 * mass changer members it reads). Slot 4 (0x69450), as a manifold is
 * processed: when one body's material is debris, the other's heavy object
 * factor f splits the masses, (1 + x) for the debris and (1 - x) for the
 * other, x = (f - 1) / (f + 1). */
class hknpMassChangerModifier /* derived name */
{
  public:
    void FUN_00069450(const void *threadContext, const void *sharedData, const hknpCdBody &bodyA,
                      const hknpCdBody &bodyB,
                      hknpManifold *manifold); /* vtable slot 4; derived name */
};

/* The modifier of vtable 0x16a5010 (address point 0x16a5020; derived name),
 * one of the twenty FUN_00048b20 builds for the world: slots 2 to 5
 * 0x161fc0, 0x161fd0, 0x1620c0 and 0x1622a0, slot 7 (0x162350) sets valueA
 * of each of the manifold's points in the jacobian to 1, slot 10 0x1623a0.
 * Slot 7's arguments follow hknpSurfaceVelocityModifier's (0x16d200): the
 * manifold seventh, the jacobian eighth, both on the stack. */
class Modifier16a5020 /* derived name */
{
  public:
    /* Slot 3 (0x161fd0), when a manifold is created: the cache marked;
     * when either body raises trigger events, a contact solver trigger
     * (its material's type) leaves the manifold without impulse, else the
     * modifier's bit 9 is enabled and an event of the manifold created
     * posted with the shape keys, the cache's flags at +0x22 given bit 3;
     * with neither body a trigger, only the bit enabled. derived name. */
    void FUN_00161fd0(CommandOwner00171180 *context, const void *sharedData,
                      const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                      ManifoldCreatedInput *input) const;
    /* Slot 5 (0x1622a0), as a cache's modifiers are fired: when the
     * cache's flags at +0x22 have bit 3, an event of the bodies' manifold
     * going posted with their shape keys; bits 3 and 4 cleared either
     * way. derived name. */
    void FUN_001622a0(CommandOwner00171180 *context, const void *sharedData,
                      const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                      hknpManifoldCollisionCache *cache) const;
    void FUN_00162350(const void *threadContext, const void *sharedData, const void *bodyA,
                      const void *bodyB, hknpManifoldCollisionCache *cache,
                      const hknpManifold *manifold, Pair08Owner *jacobian,
                      int jacobianIndex); /* vtable slot 7; derived name */
};

/* An event of a manifold's status (derived names; primary type 4,
 * secondary type 1, 0xb0 bytes padded): each body as its byte at +0x7f
 * and its id, as the manifold events give them, the status at +0x18, the
 * bodies' shape keys, the cache, and from +0x30 the manifold, whose point
 * count reads -1 when there is none (the modifier slots 0x154bc0 and
 * 0x154ca0; 0x154a60 copies a manifold there). */
struct ManifoldStatusEvent00154bc0 : public hkCommand /* derived name */
{
    /* The header filled in order, then the bodies' words, the status, the
     * cache and the keys, no manifold. */
    ManifoldStatusEvent00154bc0(u32 bodyByte7fA, u32 idA, u32 bodyByte7fB, u32 idB,
                                u8 manifoldStatus, hknpManifoldCollisionCache *cache_,
                                u32 shapeKeyA, u32 shapeKeyB)
    {
        sizePaddedTo16 = 0xb0;
        unknown2 = 0;
        primaryType = 4;
        secondaryType = 1;
        byte7fA = bodyByte7fA;
        bodyIdA = idA;
        byte7fB = bodyByte7fB;
        bodyIdB = idB;
        status = manifoldStatus;
        cache = cache_;
        keyA = shapeKeyA;
        keyB = shapeKeyB;
        manifoldNumPoints = -1;
    }

    u32 byte7fA;
    u32 bodyIdA;
    u32 byte7fB;
    u32 bodyIdB;
    u8 status; /* derived name */
    u32 keyA;
    u32 keyB;
    hknpManifoldCollisionCache *cache; /* derived name */
    /* The manifold's first 0x80 bytes: its point count, then from +0x40
     * its seven vectors (0x154a60 copies them one by one). */
    int manifoldNumPoints; /* derived name */
    u8 unknown34[0xc];
    Vec4 manifoldVectors[7]; /* derived name */
};

/* The modifier of vtable 0x16a4570 (address point 0x16a4580; derived name),
 * slot 1 the shared 0xd900, slot 2 0x7c980, slot 4 0x154a60, slot 6 the
 * shared 0x69440: slots 5 (0x154ca0) and 8 (0x154bc0), as a cache's
 * modifiers are fired, post a manifold status event to the context's
 * dispatcher when the cache's flags at +0x22 have bit 7, and bit 6,
 * respectively. */
class Modifier16a4580 /* derived name */
{
  public:
    /* Slot 5 (0x154ca0): status 8, the bodies' ids from the cache, no
     * cache in the event. derived name. */
    void FUN_00154ca0(CommandOwner00171180 *context, const void *sharedData,
                      const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                      const hknpManifoldCollisionCache *cache) const;
    /* Slot 8 (0x154bc0): status 4, the bodies' ids from the bodies, the
     * cache in the event. derived name. */
    void FUN_00154bc0(CommandOwner00171180 *context, const void *sharedData,
                      const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                      hknpManifoldCollisionCache *cache) const;
};

/* The modifier of vtable 0x16a4f90 (address point 0x16a4fa0; derived
 * name), slot 1 the shared 0xd900, slot 10 0x161cc0: slot 5 (0x161f10), as
 * a cache's modifiers are fired (fireCacheModifiers' arguments), posts a
 * body pair event to the context's dispatcher when the cache's flags at
 * +0x22 have bits 0 and 2 both set. */
class Modifier16a4fa0 /* derived name */
{
  public:
    void
    FUN_00161f10(CommandOwner00171180 *context, const void *sharedData, const hknpCdBody *cdBodyA,
                 const hknpCdBody *cdBodyB,
                 const hknpManifoldCollisionCache *cache) const; /* vtable slot 5; derived name */
};

/* The second argument of the modifier slot 0x156e90: a vector at +0x20 of
 * the object at +0x18 (derived names). */
struct ModifierVector00156e90 /* derived name */
{
    u8 unknown0[0x20];
    Vec4 vector; /* derived name */
};

struct ModifierSharedData00156e90 /* derived name */
{
    u8 unknown0[0x18];
    const ModifierVector00156e90 *object; /* derived name */
};

/* What the modifier of vtable 0x16a4850 keeps in a manifold's cache under
 * property key 2, set from the softer material when the manifold is
 * created (0x156dc0): its soft contact separation velocity, its force
 * factor over its damping factor at most one, and the damping factor
 * (derived names). */
struct ManifoldScaleProperty /* derived name */
{
    float separationVelocity; /* derived name */
    float scaleB;             /* derived name */
    float scaleA;             /* derived name */
};

/* The modifier of vtable 0x16a4850 (address point 0x16a4860, 8 bytes: slot
 * 1 is the shared 0xd900; derived name): slot 7 (0x1570a0) scales the
 * jacobian's valueA and valueB of every point by the two factors its cache
 * keeps under property key 2. Its arguments are those of
 * Modifier16a5020's slot 7. */
class Modifier16a4860 /* derived name */
{
  public:
    /* Slot 3 (0x156dc0), when a manifold is created: the property above
     * reserved and set from the material of the smaller nonzero soft
     * contact force factor (a zero one compares as the largest). derived
     * name. */
    void FUN_00156dc0(const void *threadContext, const void *sharedData, const hknpCdBody *bodyA,
                      const hknpCdBody *bodyB,
                      ManifoldCreatedInput *input); /* vtable slot 3; derived name */
    void FUN_00156e90(const void *threadContext, const ModifierSharedData00156e90 *sharedData,
                      const void *bodyA, const void *bodyB,
                      hknpManifold *manifold); /* vtable slot 6; derived name */
    void FUN_001570a0(const void *threadContext, const void *sharedData, const void *bodyA,
                      const void *bodyB, hknpManifoldCollisionCache *cache,
                      const hknpManifold *manifold, Pair08Owner *jacobian,
                      int jacobianIndex); /* vtable slot 7; derived name */
};

float *FUN_00034810(Pair08Owner *self, int index); /* derived name */

/* What follows the record's entries (derived names): FUN_0002af30 returns
 * its address (past the 32-byte entries from +0x40 and a size the table at
 * 0x14b8690 gives for the byte at +3), FUN_0002af50 the address of an int
 * in it, 16 bytes further for each of the conditions its byte at +4 tells
 * (nonzero, bit 1, bit 0). */
struct Pair08Tail /* derived name */
{
    /* The tests are inline accessors: each and is done on the byte (the
     * base's `andb $2` at 0x2af62), as InstCombine narrows it inside the
     * accessor before the reads merge (cookbook 71). */
    bool hasFlags() const
    {
        return flags != 0;
    } /* derived name */

    bool hasFlag1() const
    {
        return (flags & 2) != 0;
    } /* derived name */

    bool hasFlag0() const
    {
        return (flags & 1) != 0;
    } /* derived name */

    u8 unknown0[4];
    u8 flags; /* derived name */
};

Pair08Tail *FUN_0002af30(const Pair08Owner *self); /* derived name */
const s32 *FUN_0002af50(const Pair08Tail *tail);   /* derived name */
s32 FUN_00034850(const Pair08Owner *self);         /* derived name */
s32 FUN_00034870(const Pair08Owner *self);         /* derived name */

/* One vector per entry of the record (derived names): FUN_00031740 writes
 * one vector per entry (its count) from the two motions' vectors at +0x40
 * and +0x50 and the record's vector at +0x20; FUN_000348a0, called at
 * 0x15d8e5, forwards to it with the record's count, its fourth argument
 * unused. */
void FUN_00031740(const Pair08Owner *self, int count, const hknpMotion *motionA,
                  const hknpMotion *motionB, Vec4 *out); /* derived name */
void FUN_000348a0(const Pair08Owner *self, const hknpMotion *motionA, const hknpMotion *motionB,
                  const void *argument4, Vec4 *out); /* derived name */
/* The record's whole size (derived names): FUN_00031a30 takes the record's
 * count, type and the byte at +4 (the flags whose blocks FUN_0002af50
 * skips) besides four arguments not recovered; FUN_000319f0, called at
 * 0x77011, hands them on from the record. */
void FUN_00031a30(const Pair08Owner *self, void *argument2, u8 count, u8 type, u8 flags,
                  void *argument6, void *argument7, void *argument8); /* derived name */
void FUN_000319f0(const Pair08Owner *self, void *argument2, void *argument3, void *argument4,
                  void *argument5); /* derived name */

void FUN_0002b390(Pair08Owner *self,
                  bool enable); /* derived name: sets or clears bit 2 of the byte at +1 */

/* The object handed to FUN_0002b180 and FUN_0002b3b0 before the record is
 * the world's solver settings at +0x390 (FUN_0003d7d0 passes the one
 * embedded at +0x390 of its second argument). */
typedef hknpSolverInfo Info0002b180;

/* The values B of the record's first four entries, scaled by the product of
 * the info's +0x130 and the first lane of its +0x40 and negated, into a
 * caller's array (FUN_0002b620), and an array of four, scaled by the info's
 * +0x110 and negated, back into them (FUN_0002b670); the modifier slot
 * 0x156f40 calls one before its vector loop and the other after it. */
void FUN_0002b620(const Pair08Owner *self, const Info0002b180 *info, float *out); /* derived name */
void FUN_0002b670(const Info0002b180 *info, const float *values,
                  Pair08Owner *self); /* derived name */

/* FUN_0002b3b0's output: an int at +0, a float at +4, a vector at +0x10,
 * floats from +0x30 and vectors from +0x40, one per entry (the character
 * proxy's contact handler 0x176d5e walks the floats from the count at +0;
 * a count of -1 marks one not computed yet, 0x409aa). derived names. */
struct Output0002b3b0 /* derived name */
{
    int numEntries;
    float value4;
    u8 unknown8[8];
    Vec4 vector10;
    u8 unknown20[0x10];
    float values[4];
    Vec4 vectors[4];
};

void FUN_0002b180(const Info0002b180 *info, Pair08Owner *self, const Vec4 &a,
                  const Vec4 &b); /* derived name */
void FUN_0002b3b0(const Info0002b180 *info, Pair08Owner *self, const hknpMotion *motionA,
                  const hknpMotion *motionB, Output0002b3b0 *out); /* derived name */
void FUN_00034920(Pair08Owner *self, const Info0002b180 *info, const hknpMotion *motionA,
                  const hknpMotion *motionB, Output0002b3b0 *out); /* derived name */

/* What the character proxy's signal hands over second (derived names;
 * hknpCharacterProxy's slot 5, 0x176cc0, reads it): the two bodies' ids at
 * +0xc and +0x14, a pointer at +0x28 to where the pair's jacobian record
 * sits (a block and an offset in it, flags at +0x26), and the record's
 * output at +0x30 once computed. FUN_000409a0 returns that output,
 * computing it into the buffer first when it is not there yet (the count
 * -1). */
struct JacobianLocation000409a0 /* derived name */
{
    u8 unknown0[0x26];
    u8 flags; /* derived name: the handler skips the pair under 0x20 */
    u8 unknown27;
    char *block;     /* derived name */
    u16 blockOffset; /* derived name */

    Pair08Owner *record() const
    {
        return reinterpret_cast<Pair08Owner *>(block + blockOffset);
    }
};

struct hknpCharacterProxySignalData /* derived name */
{
    const Output0002b3b0 *FUN_000409a0(const hknpWorld *world, Output0002b3b0 *buffer) const;

    u8 unknown0[0xc];
    u32 bodyIdA; /* derived name */
    u8 unknown10[4];
    u32 bodyIdB; /* derived name */
    u8 unknown18[0x10];
    const JacobianLocation000409a0 *jacobian; /* derived name */
    Output0002b3b0 output;                    /* derived name */
};

/* The record's first and second ints (0x10650, 0x34840). derived names. */
int FUN_00010650(const Pair08Owner *self); /* derived name */
int FUN_00034840(const Pair08Owner *self); /* derived name */

/* What slot 11 of the modifier at 0x16a4e60 receives (derived name): the
 * pair whose bodies the event names first. */
struct ImpulseClippedInput0015db70 /* derived name */
{
    Pair08Owner *pair; /* derived name */
};

/* An event of two bodies and a pair (derived names; primary type 4,
 * secondary type 3, 0x30 bytes padded): each body as its byte at +0x7f
 * and its id, as the manifold events give them, then the pair and an
 * impulse (the modifier slot 0x15db70 posts one). */
struct ImpulseEvent0015db70 : public hkCommand /* derived name */
{
    /* The header filled in order, then the bodies' words; the pair and
     * the impulse are the poster's to set. */
    ImpulseEvent0015db70(u32 bodyByte7fA, u32 idA, u32 bodyByte7fB, u32 idB)
    {
        sizePaddedTo16 = 0x30;
        unknown2 = 0;
        primaryType = 4;
        secondaryType = 3;
        byte7fA = bodyByte7fA;
        bodyIdA = idA;
        byte7fB = bodyByte7fB;
        bodyIdB = idB;
    }

    u32 byte7fA;
    u32 bodyIdA;
    u32 byte7fB;
    u32 bodyIdB;
    Pair08Owner *pair; /* derived name */
    float impulse;     /* derived name */
};

/* A body as a 64-bit key (derived names): its byte at +0x7f in the low
 * word and its id in the high one, the same two words as the world
 * object's BodyRecord; 0x16e040 reads the id alone and compares the key
 * whole. */
union BodyKey0016e040 /* derived name */
{
    struct {
        u32 byte7f;
        int bodyId;
    };

    u64 key;
};

/* What the solver's step at 0xc4cd0 and 0xc5e30 holds the world in at
 * +0x148 (derived name): 0x16e040 asks whether both keys of a pair still
 * name live bodies, the same ones. */
struct WorldReference0016e040 /* derived name */
{
    bool FUN_0016e040(const BodyKey0016e040 *pair) const; /* derived name */

    const hknpWorld *world;
};

/* hknpMotionWeldTOICommand (the name its print, 0x170f20, writes: a fact):
 * the bodies' ids at +0xc and +0x14, which the print writes, and the pair's
 * jacobian record at +0x18. Field names derived. */
struct hknpMotionWeldTOICommand {
    /* The record's output computed from the motions of its two bodies
     * (0x3d7d0; the print 0x170f20 writes its normal and positions).
     * derived name. */
    void FUN_0003d7d0(const hknpWorld *world, Output0002b3b0 *out) const;
    /* The command written to a stream (0x170f20; the command dispatch
     * 0x171040 jumps to it): the bodies' ids, then the record's normal and
     * four positions. derived name. */
    void FUN_00170f20(const hknpWorld *world, hkOstream &out) const;

    u8 unknown0[0xc];
    u32 bodyIdA; /* derived name */
    u8 unknown10[4];
    u32 bodyIdB;         /* derived name */
    Pair08Owner *record; /* derived name */
};

/* The cell index of the motion of the record's first and second body (the
 * ints at +8 and +0xc index the world's bodies). */
u8 FUN_0002afa0(const hknpWorld *world, const Pair08Owner *self); /* derived name */
u8 FUN_0002afd0(const hknpWorld *world, const Pair08Owner *self); /* derived name */

/* FUN_000ae6a0 and FUN_000ae810 sit in slots 5 and 9 of one vtable
 * (0x16a3b00): getters of the ints at +0x38 and +0x48. FUN_000ae6a0 also
 * fills a slot of the vtables at 0x16a6330 and 0x16b1500, so +0x38 belongs
 * to a class those share. */
struct Values38Owner {
    u8 unknown0[0x38];
    s32 value38;
    u8 unknown3c[0xc];
    s32 value48;
};

/* The two polymorphic bases of the allocators below: the primary, whose slot
 * 12 (the shared FUN_00001620) returns the object as its second base, and a
 * second interface of eleven slots at +8. The interface's slots 2 to 10 are
 * overridden by every allocator met so far, so its vtable in each holds the
 * this-adjusting thunks of the overriders (or their folded bodies). Slot 8
 * returns a byte count (TwoBaseAllocator: FUN_000022d0, thunk FUN_00002300;
 * hkLargeBlockAllocator: FUN_00012e20, thunk FUN_00012e30). */
class AllocatorInterface;
struct MemoryStatistics;

class AllocatorBase /* derived name */
{
  public:
    /* Empty and out of line (0x8d60): every allocator's destructor ends in
     * a call or jump to it (0x4ac0, 0x14a79, 0x8f17b and a dozen more). The
     * same one-instruction body stands in the slots of other vtables
     * (hkDummySingleton's slots 0 and 5), which cite it by address. */
    virtual ~AllocatorBase();

    /* The class's own placement form (the memory setup FUN_00001140 builds
     * its allocators in static storage with it). A member, not the reserved
     * global form clang folds to its argument while it builds the IR, so
     * the pointers the setup records are calls' results when GlobalOpt runs,
     * before the inliner: the quit function FUN_00001200 then reaches each
     * vtable through the loaded pointer, not through the storage. */
    static void *operator new(unsigned long, void *where)
    {
        return where;
    }

    /* Its delete frees nothing: an allocator lives in storage its owner
     * gives it, so a deleting destructor is the complete destructor's body
     * (BlockListAllocator's slots 0 and 1 are one body, 0x8f120;
     * BufferAllocator's are two equal ones, 0x909a0 and 0x90930). */
    static void operator delete(void *, unsigned long) {}

    /* Slots 2 and 3 allocate and free a block of a given size; slots 4 and
     * 5 (FUN_00008d70, FUN_00008d80) are defaults the allocators keep that
     * forward to them (the layout of Havok's hkMemoryAllocator). */
    virtual void *blockAlloc(int numBytes) = 0;              /* slot 2; derived name */
    virtual void blockFree(void *pointer, int numBytes) = 0; /* slot 3; derived name */
    virtual void *FUN_00008d70(int &numBytes);               /* slot 4; derived name */
    virtual void FUN_00008d80(void *pointer, int numBytes);  /* slot 5; derived name */

    /* Slot 5 for a number of elements of a type (the arrays' frees): the
     * pointer and the count are the caller's arguments, read before the
     * call loads the slot (0x9ce1 after 0x9cde). derived name. */
    template <typename T> void freeElements(void *pointer, int numElements)
    {
        FUN_00008d80(pointer, numElements * sizeof(T));
    }

    /* Slot 5 for a size in bytes the caller has computed, the pointer read
     * before the call loads the slot as above (hkArray's storage). derived
     * name. */
    void freeBytes(void *pointer, int numBytes)
    {
        FUN_00008d80(pointer, numBytes);
    }

    /* Slot 6 (the default 0x8d90): a buffer resized, from its old size to
     * the size asked for, which the allocator may round up in place (the
     * slab allocator's 0xefd0). derived name. Slot 11's signature is not
     * recovered (the peak reset). */
    virtual void *FUN_00008d90(void *pointer, int oldNumBytes, int &numBytesInOut);
    /* Slot 7 (the default 0x8e00): numBlocks blocks of blockSize bytes,
     * each from slot 2, into blocksOut. derived name. */
    virtual void blockAllocBatch(void **blocksOut, int numBlocks, int blockSize);
    /* Slot 8 (the default 0x8e50): the non-null of numBlocks blocks of
     * blockSize bytes, each to slot 3. derived name. */
    virtual void blockFreeBatch(void **blocks, int numBlocks, int blockSize);
    /* Slot 9: the allocator's statistics into the caller's record
     * (MemoryStatistics, below). derived name. */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;
    /* Slot 10: the size a block of the given request occupies (the large
     * block allocator's 0x13500; the router adaptors forward it). derived
     * name. */
    virtual int getAllocatedSize(const void *pointer, int numBytes) const;
    /* Slot 11: the peak use reset to the current use (TwoBaseAllocator's
     * 0x2670, the buffer allocator's 0x910d0). derived name. */
    virtual void resetPeak();
    /* Slot 12: the allocator's second interface, null by default (the
     * shared 0x42d0); named after TwoBaseAllocator's overrider, which
     * returns its second base. */
    virtual AllocatorInterface *FUN_00001620();
};

template <typename T> inline void hkArray<T>::clearAndDeallocate()
{
    /* The elements destroyed first, from the last (nothing for an element
     * with no destructor; the string map's cleanup 0x360 runs each
     * string's). */
    clear();
    if ((capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0) {
        /* The storage's size in bytes first, then the pointer: an array
         * destroyed in a loop keeps the data pointer's store behind a phi
         * (0x40dd0, 0x12a8c0: `mov rax, rbx` after the free, the address
         * rebuilt from the index on the other path), which a pointer read
         * first would let SimplifyCFG hoist away (cookbook 190). */
        const int numBytes = getCapacity() * sizeof(T);
        hkContainerHeapAllocator::get().freeBytes(data, numBytes);
    }
    data = 0;
    capacityAndFlags = DONT_DEALLOCATE_FLAG;
}

template <typename T> inline void hkArray<T>::clearAndDeallocate(AllocatorBase &allocator)
{
    clear();
    if ((capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0) {
        const int numBytes = getCapacity() * sizeof(T);
        allocator.freeBytes(data, numBytes);
    }
    data = 0;
    capacityAndFlags = DONT_DEALLOCATE_FLAG;
}

/* The memory copies at 0x910e0 to 0x91210 (derived names), each with a
 * signed int count: FUN_000910e0 forwards to memcpy, FUN_00091100 copies
 * backwards in the widest unit the count and both pointers' alignment allow,
 * and FUN_00091210 moves overlapping memory, backwards when the destination
 * is above the source. */
void FUN_000910e0(void *dst, const void *src, int n); /* derived name */
void FUN_00091100(void *dst, const void *src, int n); /* derived name */
void FUN_00091210(void *dst, const void *src, int n); /* derived name */

/* The array's storage set to a capacity, through an allocator, for elements
 * of a size (0xa70: reallocated in place by the allocator's slot 6 when the
 * array owns its storage, else allocated and copied); the result is
 * nonzero when the allocation failed. derived name. */
hkResult FUN_00000a70(AllocatorBase &allocator, void *array, int numElements,
                      int elementSize); /* derived name */

/* Room for n elements at least: the capacity doubled, or n when that is
 * more (hkArrayStreamWriter's terminator, 0x8ffa0). */
template <typename T> inline hkResult hkArray<T>::reserve(AllocatorBase &allocator, int n)
{
    const int capacity = getCapacity();
    if (capacity < n) {
        const int doubled = 2 * capacity;
        return FUN_00000a70(allocator, this, n < doubled ? doubled : n, sizeof(T));
    }
    return HK_SUCCESS;
}

template <typename T> inline T *hkArray<T>::expandBy(int n)
{
    const int oldSize = size;
    reserve(hkContainerHeapAllocator::get(), oldSize + n);
    size += n;
    return data + oldSize;
}

template <typename T> inline void hkArray<T>::setSize(int n)
{
    reserve(hkContainerHeapAllocator::get(), n);
    hkArrayUtil::construct(data + size, n - size);
    size = n;
}

template <typename T> inline void hkArray<T>::setSize(AllocatorBase &allocator, int n)
{
    reserve(allocator, n);
    hkArrayUtil::construct(data + size, n - size);
    size = n;
}

template <typename T>
inline void hkArray<T>::setSize(AllocatorBase &allocator, int n, const T &fill)
{
    reserve(allocator, n);
    const int numNew = n - size;
    T *const added = data + size;
    for (int i = 0; i < numNew; i++) {
        added[i] = fill;
    }
    size = n;
}

template <typename T>
inline void hkArray<T>::insertAt(int index, const T *elements, int numElements)
{
    const int numToMove = size - index;
    const int newSize = size + numElements;
    const int capacity = getCapacity();
    if (newSize > capacity) {
        const int doubled = 2 * capacity;
        FUN_00000a70(hkContainerHeapAllocator::get(), this, doubled > newSize ? doubled : newSize,
                     sizeof(T));
    }
    FUN_00091210(data + index + numElements, data + index, numToMove * int(sizeof(T)));
    T *const dst = data + index;
    for (int i = 0; i < numElements; i++) {
        dst[i] = elements[i];
    }
    size = newSize;
}

template <typename T> inline void hkArray<T>::append(const T *elements, int numElements)
{
    const int newSize = size + numElements;
    const int capacity = getCapacity();
    if (newSize > capacity) {
        const int doubled = 2 * capacity;
        FUN_00000a70(hkContainerHeapAllocator::get(), this, doubled > newSize ? doubled : newSize,
                     sizeof(T));
    }
    T *dst = data + size;
    for (int i = 0; i < numElements; i++) {
        dst[i] = elements[i];
    }
    size = newSize;
}

template <typename T> inline hkArray<T> &hkArray<T>::operator=(const hkArray &other)
{
    _copyFromArray(hkContainerHeapAllocator::get(), other);
    return *this;
}

template <typename T>
inline void hkArray<T>::_copyFromArray(AllocatorBase &allocator, const hkArray &other)
{
    const int oldSize = size;
    const int newSize = other.size;
    const int numAssigned = newSize > oldSize ? oldSize : newSize;
    reserve(allocator, newSize);
    destructElements(data + newSize, oldSize - newSize);
    hkArrayUtil::copy(data, other.data, numAssigned);
    hkArrayUtil::constructWithArray(data + numAssigned, newSize - numAssigned,
                                    other.data + numAssigned);
    size = newSize;
}

/* The array's grow by one more element at least, through an allocator, for
 * elements of a size (0xb40, 470 call sites; the capacity doubled, or one
 * when empty, by the allocator's slot 6). derived name. */
void FUN_00000b40(AllocatorBase &allocator, void *array, int elementSize); /* derived name */

template <typename T> inline void hkArray<T>::pushBack(const T &element)
{
    if (size == getCapacity()) {
        FUN_00000b40(hkContainerHeapAllocator::get(), this, sizeof(T));
    }
    /* Copy-constructed in place, or assigned when the type is plain old
     * data (a skinned mesh part goes over whole, 0xae9a0, where its
     * assignment copies the handles one by one; a body's record goes member
     * by member, 0x63930). */
    hkArrayUtil::constructWithCopy(data + size, element);
    size++;
}

template <typename T> inline T &hkArray<T>::expandOne()
{
    if (size == getCapacity()) {
        FUN_00000b40(hkContainerHeapAllocator::get(), this, sizeof(T));
    }
    hkArrayUtil::construct(data + size);
    return data[size++];
}

template <typename T> inline void hkArray<T>::pushBack(AllocatorBase &allocator, const T &element)
{
    if (size == getCapacity()) {
        FUN_00000b40(allocator, this, sizeof(T));
    }
    hkArrayUtil::constructWithCopy(data + size, element);
    size++;
}

template <typename T> inline T &hkArray<T>::expandOne(AllocatorBase &allocator)
{
    if (size == getCapacity()) {
        FUN_00000b40(allocator, this, sizeof(T));
    }
    return data[size++];
}

/* An array of 32-byte elements and the indices of the free ones (derived
 * names): FUN_00198a70 grows the elements, FUN_00198a20 hands an index
 * back; FUN_0013e090 builds one and walks it. The elements are the nodes
 * of the broad phase's trees (BroadPhaseTree00142a40, below). */
struct ElementPool00198a20 /* derived name */
{
    /* A node (derived names): its box; its two children, a leaf's first
     * the index of its bucket and its second NO_CHILD; the number of leaves
     * under it, which the refit 0x197610 counts. */
    struct Element {
        enum { NO_CHILD = 0x7fffffff };

        hkAabb16 aabb;
        int children[2];
        int numLeaves;
        u8 unknown1c[4];
    };

    void FUN_00198a20(int index); /* derived name */

    /* Room for numElements (0x196570): the elements grown to that size and
     * each new index handed to the free list, the highest first. The count
     * is unsigned: the first index, numElements - 1, is computed without
     * the signed no-wrap flag, so the loop's guard compares it with the old
     * size as the base does (InstCombineCompares.cpp:2495 folds the signed
     * form into the growth test). derived name. */
    void FUN_00196570(u32 numElements);

    /* The growth itself, inline in both 0x196570 and the allocation
     * 0x196630: declared `inline`, the hint its cost (250 to 275) needs in
     * the allocation (defined in func_00196570.cpp). derived name. */
    inline void growTo(u32 numElements);

    /* A free element taken (0x196630; the tree's builders at 0x13cae1,
     * 0x13cfd8, 0x196342 and 0x196f95): 128 more made first when none is
     * free, the last free index handed out and its element returned.
     * derived name. */
    Element *FUN_00196630(int *indexOut);

    /* Room for numFree free elements (0x198a70; the tree builder at
     * 0x13c2a4 calls it): the elements grown by what the free list lacks.
     * derived name. */
    void FUN_00198a70(u32 numFree);

    /* The boxes and the leaf counts of a subtree refitted from its leaves
     * (0x197610, recursive); its number of leaves back. derived name. */
    int FUN_00197610(Element *node);

    hkArray<Element> elements; /* derived name */
    hkArray<int> freeIndices;  /* derived name */
};

/* The interface's slots 2 to 10 in their vtable order, each named after
 * TwoBaseAllocator's overrider (primary slots 13 to 21) and typed from its
 * body. The executable holds no vtable of the interface itself (no run of
 * nine __cxa_pure_virtual slots after two destructors), and every allocator
 * met so far overrides all nine, so they are pure. */
/* A memory walk's callback (derived names): a block's start and size,
 * whether it is allocated, its pool, and the walker's parameter. */
typedef void (*MemoryWalkCallback)(void *start, unsigned long size, bool allocated, int pool,
                                   void *param);

class AllocatorInterface /* derived name */
{
  public:
    /* Empty and inline: hkLargeBlockAllocator's destructor (0x12370) calls
     * nothing for its second base. */
    virtual ~AllocatorInterface() {}

    virtual void FUN_00003140() = 0;             /* slot 2; derived name */
    virtual void FUN_000032e0(int value) = 0;    /* slot 3; derived name */
    virtual int FUN_000034a0(u64 limit) = 0;     /* slot 4; derived name */
    virtual u64 FUN_00003580() const = 0;        /* slot 5; derived name */
    virtual bool FUN_00002230(int numBytes) = 0; /* slot 6; derived name */
    virtual int FUN_00002f10(MemoryWalkCallback callback, void *param) = 0; /* slot 7 */
    virtual u64 allocatedBytes() const = 0;   /* slot 8; derived name */
    virtual void FUN_00002330(int value) = 0; /* slot 9; derived name */
    /* Slot 10: the allocator recorded in a memory snapshot under a parent
     * provider, its own provider's index returned (Havok's name). derived
     * name. */
    virtual int addToSnapshot(void *snapshot, int parentId) = 0;
};

/* An allocator (vtable address points 0x168c640 and, for the second base,
 * 0x168c708), both stored by its constructor FUN_00001960. Its complete
 * destructor is FUN_00001fb0, its deleting destructor (slot 1) FUN_00001f90;
 * slot 12 (FUN_00001620) returns the object as its second base. Slot 15
 * (0x34a0, also reached through the second base by the thunk 0x3570) stores
 * a byte limit at +0xb50 under the spinning mutex at +0x10; slot 16
 * (FUN_00003580) reads it. Primary slots 13 to 21 override the interface's
 * slots 2 to 10 in order; the second base's vtable holds their
 * this-adjusting thunks (0x32d0, 0x3490, 0x3570, 0x3590, 0x2280, 0x3130,
 * 0x2300, 0x2400, 0x3700). */
struct FreeList;

struct TwoBaseAllocatorCinfo; /* derived name: what FUN_00001ae0 takes */

class TwoBaseAllocator : public AllocatorBase, public AllocatorInterface
{
  public:
    /* Out of line (0x1960): the allocator below and its interface at +0x30
     * and +0x38; the third argument goes on to FUN_00001ae0. */
    TwoBaseAllocator(AllocatorBase *large, AllocatorInterface *largeInterface,
                     const TwoBaseAllocatorCinfo *cinfo);
    virtual ~TwoBaseAllocator();
    /* Slot 2 (0x29b0): a block through slot 4, the size passed by
     * reference. */
    virtual void *blockAlloc(int numBytes);
    virtual AllocatorInterface *FUN_00001620();

    /* The rest of the overriders, declared so the class is complete (slot
     * 3 0x2c40; primary slots 13 to 15, 17, 18, 20 and 21). */
    virtual void blockFree(void *pointer, int numBytes);
    virtual void FUN_00003140();
    virtual void FUN_000032e0(int value);
    virtual int FUN_000034a0(u64 limit);
    virtual bool FUN_00002230(int numBytes);
    virtual int FUN_00002f10(MemoryWalkCallback callback, void *param);
    virtual void FUN_00002330(int value);
    virtual int addToSnapshot(void *snapshot, int parentId); /* 0x35a0 */

    virtual u64 FUN_00003580() const; /* vtable slot 16; derived name */
    /* Slot 20 (0x22d0, also the second base's slot 8 through the thunk
     * 0x2300, which has it inlined): the bytes the allocator below has
     * handed out since the count at +0x20, none without one. */
    virtual u64 allocatedBytes() const;
    /* Slot 10 (0x27e0): a small block's size is its free list's element
     * size, none for no bytes; a larger one, or one of a size no free list
     * holds, the allocator below knows. */
    virtual int getAllocatedSize(const void *pointer, int numBytes) const;
    /* Slot 11 (0x2670): the peak back to what is in use now. */
    virtual void resetPeak();
    /* Slot 22 (0x26f0, at 0x168c6f0, after the interface's overriders):
     * under the lock, every free list checked in turn (FUN_000188c0), the
     * first failing one the answer. derived name. */
    virtual bool FUN_000026f0();

    /* The lock the slots of the interface run under (0x34a0). derived
     * name. */
    hkCriticalSection criticalSection;
    u64 baseBytes;                   /* derived name */
    u64 peakBytes;                   /* derived name; the largest count slot 18 (0x2230) has seen */
    AllocatorBase *largeAllocator;   /* derived name; the constructor's first argument */
    AllocatorInterface *allocator38; /* derived name; the constructor's second argument */
    u8 unknown40[0x78];
    /* The free list of each block size up to 640 bytes by 32-byte steps,
     * indexed by (size + 31) / 32 (0x27ee). derived name. */
    FreeList *sizeToFreeList[21];
    /* The distinct free lists and their count (slot 22, 0x26f0, walks
     * them). derived names. */
    FreeList *freeLists[21];
    int numFreeLists;
    u8 unknown20c[0x944];
    /* The byte limit slot 15 stores and slot 16 reads; slot 18 (0x2230)
     * tests a request against it. derived name. */
    u64 limitB50;
};

/* An allocator of blocks with a 0x20-byte header (vtable address points
 * 0x168e2a0 and, for the second base, 0x168e360), both stored by its
 * constructor FUN_00012160. The allocation paths add a block's size to the
 * total at +0x1a0 and its size less the header to the total at +0x1a8, the
 * free (slot 3, 0x133e0) subtracts both. Primary slots 13 to 18 override the
 * interface's slots 2 to 7, slot 19 its slot 10, slot 20 (FUN_00012e20) its
 * slot 8 and slot 21 its slot 9. */
/* Each block of hkLargeBlockAllocator sits after a 0x20-byte chunk header
 * whose second word holds the chunk's size, with flags in its low two bits
 * (derived names). */
struct LargeBlockChunk /* derived name */
{
    u64 prevFoot;          /* derived name */
    u64 head;              /* derived name */
    LargeBlockChunk *next; /* derived name */
    LargeBlockChunk *prev; /* derived name */
};

/* The allocator over one block at +0x138 of hkLargeBlockAllocator (derived
 * name; vtable 0x168e210, address point 0x168e220, stored in place by the
 * constructor FUN_00012160 at 0x12194, which clears +8 to +0x20; slots 0
 * and 1 the shared 0x4ac0): the block's start at +8 and the end of what is
 * handed out at +0x20. Slot 4 (0x120d0) hands out the whole block when
 * nothing is out, slot 5 (FUN_00012100) takes it back, slot 9 (0x12120)
 * reports its use. */
class SingleBlockAllocator : public AllocatorBase /* derived name */
{
  public:
    /* Inline: no block yet (0x12194 to 0x121bc). */
    SingleBlockAllocator() : start(HK_NULL), limit(HK_NULL), end(HK_NULL), top(HK_NULL) {}

    void *FUN_000120d0(int &numBytes);              /* vtable slot 4; derived name */
    void FUN_00012100(void *pointer, int numBytes); /* vtable slot 5; derived name */
    /* Slot 9 (0x12120): what is handed out is allocated, in use and the
     * peak; the rest of the block is available and the block the largest. */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;

    /* Slots 2 and 3, not read yet. */
    virtual void *blockAlloc(int numBytes);
    virtual void blockFree(void *pointer, int numBytes);

    char *start; /* derived name */
    char *limit; /* the block's end; derived name */
    char *end;   /* derived name */
    char *top;   /* derived name */
};

class hkLargeBlockAllocator : public AllocatorBase, public AllocatorInterface /* derived name */
{
  public:
    /* Out of line (0x12160): the allocator its chunks come from at
     * +0x160. */
    hkLargeBlockAllocator(AllocatorBase *server);
    virtual ~hkLargeBlockAllocator();

    /* The overriders not read yet, declared so the class is complete (slots
     * 2 and 3, 0x12910 and 0x133e0; primary slots 13 to 16, 18, 19 and 21). */
    virtual void *blockAlloc(int numBytes);
    virtual void blockFree(void *pointer, int numBytes);
    virtual void FUN_00003140();
    virtual void FUN_000032e0(int value);
    virtual int FUN_000034a0(u64 limit);
    virtual u64 FUN_00003580() const;
    /* Every chunk of every page handed to the callback with its payload,
     * its size and whether it is in use, the top chunk marked first
     * (0x12ee0, primary slot 18; the thunk 0x12fb0 holds a copy); a page
     * without chunks, or a chain that runs out before the page's footer,
     * ends the walk. derived name. */
    virtual int FUN_00002f10(MemoryWalkCallback callback, void *param);
    virtual void FUN_00002330(int value);
    /* Primary slot 19 (0x13060; the interface's slot 10, its thunk
     * 0x13190): the allocator recorded in a memory snapshot under a parent,
     * then each page's header, every chunk's header and payload (used or
     * not) and the footer; the allocator's provider index returned. The
     * snapshot is MemorySnapshot00011280. */
    virtual int addToSnapshot(void *snapshot, int parentId);

    /* Slot 10 (Havok's getAllocatedSize): the usable size of a block, its
     * chunk's size less the header. */
    int FUN_00013500(const void *pointer, int numBytes) const; /* derived name */

    virtual u64 allocatedBytes() const; /* vtable slot 20, FUN_00012e20; derived name */

    /* Slot 11 (0x13530): the pages' sizes as allocated, the payloads in
     * use, the difference available; the largest block the larger of the
     * top and the biggest free chunk of the highest tree bin from the top's
     * bin up, found down each bin's right children (dlmalloc's tree). */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;
    /* Slot 17 (0x12e60; the interface's slot 6): whether a block of the
     * size can be had, tried by allocating one and freeing it again. */
    virtual bool FUN_00002230(int numBytes);

    /* A chunk of a page (derived names, dlmalloc's): its head holds the
     * size with the in-use bits low (1 the previous chunk's, 2 its own);
     * the payload follows the 32-byte header. */
    struct Chunk {
        u64 prevFoot;
        u64 head;
        Chunk *next;
        Chunk *prev;
    };

    /* A page the allocator took from its server, kept on a ring through
     * +8 with its size at +0x14 (the destructor 0x12370 walks the ring
     * from the sentinel at +0x178). derived names. */
    struct Page {
        Page *prev; /* derived name */
        Page *next;
        u8 unknown10[4];
        /* Unsigned: the page's end is its address plus the size zero
         * extended (0x130d5). */
        u32 size;
        /* The page's first chunk and its end; the chunk before the end is
         * the footer the walk stops at. derived names. */
        Chunk *firstChunk;
        char *end;
    };

    /* A free chunk of a tree bin (dlmalloc's tree chunk, derived names):
     * its children, its parent, the bin it is in. */
    struct TreeChunk : public Chunk {
        TreeChunk *child[2];
        TreeChunk *parent;
        u32 index;
    };

    /* A free chunk taken off its tree bin (0x12550, dlmalloc's
     * unlink_large_chunk without the address checks; the allocation and
     * free paths 0x12620, 0x131a0 and 0x133e0 call it): from its ring when
     * it has siblings, else replaced by its rightmost leaf, the bin's bit
     * cleared when the bin empties. derived name. */
    void FUN_00012550(TreeChunk *chunk);

    /* A free chunk put into its tree bin by its size (0x12410, dlmalloc's
     * insert_large_chunk; the free 0x133e0 ends with it). derived name. */
    void FUN_00012410(TreeChunk *chunk, u64 size);

    /* dlmalloc's tree bins: sizes from 256 bytes, two bins a power of
     * two. */
    enum { TREEBIN_SHIFT = 8, NTREEBINS = 32 };

    /* The tree bin of a size (dlmalloc's compute_tree_index; the free's
     * insertion 0x12410 and the statistics 0x13530). derived name. */
    static int treeIndex(u64 size)
    {
        const u64 x = size >> TREEBIN_SHIFT;
        if (x == 0) {
            return 0;
        }
        if (x > 0xffff) {
            return NTREEBINS - 1;
        }
        u32 y = u32(x);
        u32 n = ((y - 0x100) >> 16) & 8;
        u32 k = (((y <<= n) - 0x1000) >> 16) & 4;
        n += k;
        n += k = (((y <<= k) - 0x4000) >> 16) & 2;
        k = 14 - n + ((y <<= k) >> 15);
        return int((k << 1) + ((size >> (k + (TREEBIN_SHIFT - 1))) & 1));
    }

    /* How far a size is shifted to put the bits that pick the children of
     * its bin's tree at the top (dlmalloc's leftshift_for_tree_index, over
     * a signed index: `sar`, 0x124c6). derived name. */
    static int leftShiftForTreeIndex(int index)
    {
        return index == NTREEBINS - 1 ? 0 : 63 - ((index >> 1) + TREEBIN_SHIFT - 2);
    }

    /* The head's in-use bits (dlmalloc's PINUSE_BIT and CINUSE_BIT). */
    enum { PREVIOUS_IN_USE = 1, IN_USE = 2, IN_USE_BITS = 3 };

    /* A chunk's header alone (derived name): the allocator's empty top
     * is one (0x12211: no size, both in-use bits set). */
    struct ChunkHeader {
        u64 prevFoot;
        u64 head;
    };

    /* An object the allocation asks, through its slot 2, before taking a
     * page from the server (0x129c1); none from the constructor. derived
     * name. */
    void *listener;
    u32 treemap; /* derived name: a bit for each tree bin in use */
    u8 unknown1c[4];
    void *pointer20;                     /* derived name; none from the constructor */
    Chunk *top;                          /* derived name */
    u64 topSize;                         /* derived name */
    TreeChunk *treebins[32];             /* derived name */
    SingleBlockAllocator blockAllocator; /* derived name; the constructor builds it in place */
    AllocatorBase *server;               /* derived name */
    ChunkHeader emptyTop;                /* derived name */
    Page pages;                          /* derived name: the ring's sentinel */
    u64 totalBlockBytes;                 /* derived name */
    u64 totalPayloadBytes;               /* derived name */
};

void FUN_00001fb0(TwoBaseAllocator *self); /* derived name */

/* Primary slots 13, 14, 15, 18 and 21 (interface slots 2, 3, 4, 7 and 10),
 * each run under the spinning mutex at +0x10; reached through the second
 * base by the thunks 0x32d0, 0x3490, 0x3570, 0x3130 and 0x3700. Slot 15
 * stores its limit at +0xb50 and returns 0. */
void FUN_00003140(TwoBaseAllocator *self);                  /* derived name */
void FUN_000032e0(TwoBaseAllocator *self, int value);       /* derived name */
int FUN_000034a0(TwoBaseAllocator *self, u64 limit);        /* derived name */
int FUN_00002f10(TwoBaseAllocator *self, void *a, void *b); /* derived name */

/* The filter TwoBaseAllocator's slot 7 (0x2f10) walks its base allocator
 * through (0x301d): the large blocks the allocator itself holds, sorted
 * (FUN_00001630 fills them), are left out, every other block is handed on
 * to the caller's callback with pool 0. derived names. */
struct MemoryWalkFilter000015c0 /* derived name */
{
    void *unknown0;
    hkArray<void *> ownBlocks;
    MemoryWalkCallback callback;
    void *callbackParam;
};

void FUN_000015c0(void *start, unsigned long size, bool allocated, int pool,
                  void *param);                                     /* derived name */
int FUN_000035a0(TwoBaseAllocator *self, void *pointer, int value); /* derived name */

/* hkLargeBlockAllocator's primary slot 13 (interface slot 2), reached
 * through the second base by the thunk 0x133d0. */
void FUN_000131a0(hkLargeBlockAllocator *self); /* derived name */

/* A reference-counted allocator of 4096-byte pages (vtable address point
 * 0x168e8f0; constructor FUN_000195c0: a lock at +0x10, an array of every
 * page at +0x20, an array of free pages at +0x30, the peak of the bytes in
 * use at +0x40; FUN_00019640 allocates the pages, 128-byte aligned, and adds
 * each to both arrays). Slot 5 (0x198a0) hands out pages, growing by at
 * least slot 9's amount, and updates the peak from slot 7; slot 6 (0x199f0)
 * takes them back; slot 8 (0xb670) returns the peak. */
class PageAllocator : public hkReferencedObject /* derived name */
{
  public:
    enum { PAGE_SIZE = 4096 }; /* derived name */

    virtual void FUN_000198a0(void **pagesOut, int numPages);    /* vtable slot 5; derived name */
    virtual void FUN_000199f0(void *const *pages, int numPages); /* vtable slot 6; derived name */
    virtual int FUN_00019b30() const;                            /* vtable slot 7; derived name */
    virtual int FUN_0000b670() const;                            /* vtable slot 8; derived name */
    virtual int FUN_00019b50() const;                            /* vtable slot 9; derived name */
    virtual void FUN_00019b60();                                 /* vtable slot 10; derived name */
    /* Slot 11 (0x19c80): the statistics from slots 9, 7 and 8, every
     * page free counted as available, the largest block a page. derived
     * name. */
    virtual void FUN_00019c80(MemoryStatistics &statistics) const; /* derived name */

    /* 0x195c0 (the game builds one at 0xe996d5 and 0xea4fdf): the lock
     * with no spin count, no pages, a zero peak, then the initial pages
     * when a size is given. */
    PageAllocator(int initialBytes);

    /* Out of line (0x19780, slot 0; the deleting one 0x19730, slot 1,
     * before it): every page given back to the thread's heap, then the
     * members. */
    virtual ~PageAllocator();

    /* The reference-counted class delete (freeReferencedObject). */
    static void operator delete(void *object, unsigned long numBytes);

    /* A page's header (derived names): the allocator it came from at +0x10
     * (0x196a9). */
    struct Page {
        u8 unknown0[0x10];
        PageAllocator *allocator;
    };

    /* Pages for numBytes more (0x19640): each a 128-byte aligned block of
     * the thread's heap, its header pointing back here, added to every
     * page and to the free ones. derived name. */
    void FUN_00019640(int numBytes);

    hkCriticalSection lock;    /* derived name */
    hkArray<void *> pages;     /* derived name */
    hkArray<void *> freePages; /* derived name */
    int peakBytesInUse; /* derived name; slot 8 returns it; the deleting destructor frees 0x48 */
};

/* The memory system (derived name): a polymorphic object whose instance
 * the global at 0x57b7ba0 holds. The startup at 0x11c3 installs it through
 * FUN_00006c40 and the shutdown at 0x17ae6 clears it; FUN_00006c50 returns
 * it to the callers of its slots (13 at 0x7350, 17 at 0xecb6, 4 at 0x8f5c5,
 * and the game code at 0xe993e5). */
/* hkHardwareInfo (the name its singleton record's string at 0x14c3f06
 * gives, the record built at 0x8fdc0): 0x18 bytes from the thread's heap,
 * created by 0x8faf0 and filled by 0x8fb30; the slot at 0x57c8728 holds the
 * instance. The count at +0xc is what a job queue's construction info takes
 * as its thread count. */
class hkHardwareInfo : public hkReferencedObject
{
  public:
    hkHardwareInfo(); /* out of line, 0x8fb30 */

    /* The class allocator inline, the thread heap's slot 2 called in
     * place (0x8faf6), where hkReferencedObject's goes through
     * FUN_0000bcc0. */
    static void *operator new(unsigned long numBytes);

    int numThreads; /* derived name */
    u8 unknown10[8];
};

extern hkHardwareInfo *D_57c8728; /* hkHardwareInfo's singleton instance */

/* Its create function, the singleton record's (0x8faf0). derived name. */
hkReferencedObject *FUN_0008faf0(); /* derived name */

/* hknpGlobals (the name its singleton record's string at 0x14caf6c gives,
 * the record built at 0x1760c0, instance pointer 0x57c8818): 0x100 bytes
 * from the thread's heap, created by 0x175f30 and built by 0x175f70, which
 * stores the vtable 0x16a5aa0 (no type info). */
class hknpGlobals : public hkReferencedObject
{
  public:
    hknpGlobals(); /* out of line, 0x175f70 */

    /* Slot 0 (0x175e30): the directions given back; the triangle at +0x10
     * is storage the constructor builds a shape in (0x78270), not a
     * member, and nothing destroys it. */
    virtual ~hknpGlobals();

    /* The class allocator inline, as hkHardwareInfo's (0x175f36). */
    static void *operator new(unsigned long numBytes);

    /* The reference-counted delete (the deleting destructor 0x175e90,
     * slot 1). */
    static void operator delete(void *object, unsigned long numBytes);

    /* The triangle shape the constructor builds in place (0x78270), the
     * prototype each in-place triangle copies (0x78160). derived name. */
    Vec4 triangleShapeStorage[14];
    /* 49 unit directions, the 7 by 7 grid the constructor maps through
     * 0xc05b0 (16-byte elements, grown by 0xb40). derived name. */
    hkArray<hkVector4> directions;
};

extern hknpGlobals *D_57c8818; /* hknpGlobals's singleton instance */

/* A triangle shape built in a buffer of its own (derived names): the
 * globals' prototype copied in, its convex radius set (0x78160, out of
 * line; the callers from 0x6ec63 build one on their stacks). */
struct InplaceTriangleShape00078160 /* derived name */
{
    InplaceTriangleShape00078160(float convexRadius);

    hknpTriangleShape *getTriangleShape()
    {
        return reinterpret_cast<hknpTriangleShape *>(buffer);
    }

    Vec4 buffer[14];
};

/* Its create function, the singleton record's (0x175f30). derived name. */
hkReferencedObject *FUN_00175f30(); /* derived name */

/* The other singletons' create functions (each record's second field) and
 * the instance pointers not declared with their classes: */
/* hkProcessFactory, the singleton registered by that name (the string at
 * 0x14cbab3; record 0x57c88f0 filled by 0x183f90, instance pointer
 * 0x57c88e8): 0x28 bytes from the thread's heap (0x183f29), vtable 0x16a6530
 * (no type info; slots 0 and 1 its destructors 0x183db0 and 0x183d60). */
class hkProcessFactory : public hkReferencedObject
{
  public:
    /* 24-byte entries, each releasing its string at +0 (0x183e53). derived
     * name. */
    struct Entry {
        hkStringPtr name; /* derived name */
        u8 unknown8[0x10];
    };

    /* A zero int, an empty array and a lock of 2000 spins (0x183f00). */
    hkProcessFactory() : unknownC(0), lock(new hkCriticalSection(2000)) {}

    /* The lock deleted, then the entries (0x183db0); the deleting
     * destructor is 0x183d60. */
    virtual ~hkProcessFactory();

    /* The class allocator: a block of the thread's heap (defined beside the
     * router). */
    static void *operator new(unsigned long numBytes);
    static void operator delete(void *object, unsigned long numBytes);

    int unknownC;            /* in the base's tail padding */
    hkArray<Entry> entries;  /* derived name */
    hkCriticalSection *lock; /* derived name; freed at 0x10 bytes (0x183e2b) */
};

extern hkProcessFactory *D_57c88e8; /* hkProcessFactory's instance */
hkReferencedObject *FUN_00183f00(); /* hkProcessFactory's; derived name */
hkReferencedObject *FUN_001845b0(); /* hkVtableClassRegistry's; derived name */
hkReferencedObject *FUN_00184e80(); /* hkTypeInfoRegistry's; derived name */
hkReferencedObject *FUN_00184f40(); /* hkDefaultClassNameRegistry's; derived name */
class hkVersionPatchManager;
extern hkVersionPatchManager *D_57c89b8; /* hkVersionPatchManager's instance */
hkReferencedObject *FUN_00199f80();      /* hkVersionPatchManager's; derived name */
extern hkSerializeDeprecated *D_57c89e0; /* hkSerializeDeprecated's instance */
hkReferencedObject *FUN_0019a5f0();      /* hkSerializeDeprecated's; derived name */

/* A job queue's construction info (derived names: no string names the
 * struct), built by its constructor (0x5640) on the game's stack at 0xe997c8
 * and handed to the queue's constructor 0x56c0 after the game sets the
 * count at +0x20 (15). The thread ids at +0x10 are an empty array. */
struct JobQueueCinfo /* derived name */
{
    JobQueueCinfo();

    int unknown0;
    hkBool unknown4;
    int unknown8;
    int numCpuThreads;      /* derived name */
    hkArray<int> threadIds; /* derived name */
    int maxNumJobTypes;     /* derived name */
};

/* A worker thread pool's construction info (derived names: no string names
 * the struct). Its constructor (0x6d20) gives one thread, no hardware
 * thread ids, a 128 KiB stack and the name "HavokWorkerThread" (0x14b2cb5);
 * the game builds one on its stack at 0xe996eb and sets four threads and
 * the field at +0x1c (0 again) before it creates the pool. */
struct WorkerThreadPoolCinfo /* derived name */
{
    WorkerThreadPoolCinfo();

    int numThreads;                 /* derived name */
    hkArray<int> hardwareThreadIds; /* derived name */
    int stackSize;                  /* derived name */
    int unknown1c;
    const char *threadName; /* derived name */
};

struct hkMemoryRouter;

/* Slots 4 and 5 (the memory system's 0xc590 and 0xc810, vtable address
 * point 0x168d690): a thread's router set up under a name and the flags,
 * and taken down; the worker thread context (0x8f5c5, 0x8f621) passes 3.
 * Slots 6 to 12 are the memory system's (0xd230 to 0xd2b0), not read
 * here. derived names. */
/* A pair of ints (derived names): the memory system's constructor
 * builds one at its +0x10 from (0, 32768) with its constructor 0x6c30;
 * the game (0xe9963f) builds one on its stack from (1048576, 32768) and
 * hands it to the memory setup FUN_00001140, which passes it to the memory
 * system's slot 2. */
struct SizePair00006c30 {
    /* Out of line (0x6c30). */
    SizePair00006c30(int first, int second);

    s32 first;
    s32 second;
};

/* The memory system's interface and the free-list memory system over it
 * (0xc270's class); both defined after hkMemoryRouter, which the second
 * holds. */
class hkMemorySystem;
class hkFreeListMemorySystem;

extern hkMemorySystem *D_57b7ba0;

/* The memory system the setup FUN_00001140 built, and the function that
 * takes its allocators down (derived names); the quit FUN_00017ab0 runs
 * both. */
extern hkFreeListMemorySystem *D_57b99e0;
extern void (*D_57b99e8)();
hkResult FUN_00017ab0();                   /* derived name */
void FUN_00006c40(hkMemorySystem *system); /* derived name */
hkMemorySystem *FUN_00006c50();            /* derived name */

/* A global state word (derived name) and its setter FUN_00006640: the
 * allocation paths at 0x2958 and 0x2bde (TwoBaseAllocator's: the byte count
 * of the object at +0x38, less the base at +0x20, against the value at
 * +0xb50) set it to 1 when the limit is reached. */
extern int D_57b7b18;
void FUN_00006640(int state); /* derived name */

/* The base system's initialised flag (derived name): the initialiser at
 * 0x98d0 returns at once when it is set and sets it at the end, the
 * shutdown at 0x9ad0 does nothing unless it is set and clears it, and
 * FUN_00009c10 returns it (tested by 0x9353a before a teardown walk). */
extern bool D_57b80c0;
bool FUN_00009c10(); /* derived name */

/* Primary slot 20 (interface slot 9): stores its int argument into the
 * global at 0x16dc128 under the spinning mutex at +0x10. */
void FUN_00002330(TwoBaseAllocator *self, int value); /* derived name */

/* Blocks with a 16-byte header before the payload (owner, size):
 * FUN_0000bc30 allocates through the allocator's slot 2 (blockAlloc),
 * FUN_0000bc60 reads the size back, FUN_0000bc70 finds the header. */
struct ArenaBlockHeader {
    AllocatorBase *owner;
    s32 size;
    /* For an aligned block (FUN_0000bba0): how far the payload lies past the
     * start of the block the allocator returned. derived name. */
    s32 alignmentOffset;
};

/* A block of size bytes with that header, owned by the allocator
 * (0xbc30; the string duplicate 0x180c0 and the error report call it).
 * derived name. */
void *FUN_0000bc30(AllocatorBase &allocator, int size); /* derived name */

/* The size the header of such a block records (0xbc60; the allocator
 * argument is not read). derived name. */
u64 FUN_0000bc60(const AllocatorBase *allocator, const void *payload); /* derived name */

/* A copy of a string in such a block of the thread's heap (0x180c0).
 * derived name. */
char *FUN_000180c0(const char *string); /* derived name */

/* The string library's free of such a duplicate, to the allocator given
 * (0x18090). derived name. */
void FUN_00018090(char *string, AllocatorBase &allocator); /* derived name */

/* Frees a block with that header through an allocator's slot 3, the header
 * included: its owner cleared first (0xbc80; called by hkStringPtr's
 * destructor 0xe5d0 with the router's heap). derived name. */
void FUN_0000bc80(AllocatorBase &allocator, void *payload); /* derived name */

/* An aligned block from an allocator's slot 2, the header before the
 * payload (0xbba0; six callers, 0x8f2a to 0x16d5fe). derived name. */
void *FUN_0000bba0(AllocatorBase &allocator, int numBytes, int alignment); /* derived name */

/* Frees an aligned block (FUN_0000bba0's: the header records the block's
 * size less its own 16 bytes and the payload's offset into the block)
 * through the allocator's slot 3: 0xbc00. derived name. */
void FUN_0000bc00(AllocatorBase &allocator, void *payload); /* derived name */

/* An allocator over one fixed buffer (derived name; vtable address point
 * 0x16a3470, slots 0 and 1 0x909a0 and 0x90930, slots 2 to 5 0x90b20 to
 * 0x90dc0): the buffer's start at +8 and end at +0x10, the end of what is in
 * use at +0x18 and the peak use at +0x28. Slot 9 (0x910a0) reports the
 * buffer size, the free and used bytes and the peak; slot 11 (0x910d0)
 * resets the peak to the current use. FUN_00091090, not a slot, tells
 * whether the whole buffer could hold a block of a size; the memory system's
 * wrapper at 0xd270 asks it of the allocator at its +0x100. */
class BufferAllocator : public AllocatorBase /* derived name */
{
  public:
    /* 0x908d0: no buffer yet, the free list empty over its own storage, the
     * lock with no spinning (the memory system builds one at its +0x100,
     * 0xc2dd). */
    BufferAllocator();

    /* Out of line (0x909a0, slot 0; 0x90930, slot 1): the lock destroyed,
     * the free list left as it is. */
    virtual ~BufferAllocator();

    void *blockAlloc(int numBytes); /* slot 2 (0x90b20); derived name */
    /* The allocation under the lock at +0x440 (0x90b70): slot 2 asks for
     * the rounded size exactly, slot 4 (0x90db0) lets the size it gets back
     * differ. derived names. */
    void *FUN_00090b70(int &numBytesInOut, bool exactSize);
    void blockFree(void *pointer, int numBytes); /* slot 3 (0x90d90); derived name */
    bool FUN_00091090(int numBytes) const;       /* derived name */
    /* The buffer handed over under the lock (0x90a10; the memory system's
     * slots 2 and 3 set it and clear it). derived name. */
    void FUN_00090a10(void *buffer, int numBytes);
    void getMemoryStatistics(MemoryStatistics &statistics) const; /* slot 9 (0x910a0) */
    void FUN_000910d0();                                          /* vtable slot 11; derived name */

    /* A freed block the allocation takes back (0x90b70 scans them from
     * the last for the smallest that fits). derived names. */
    struct FreeBlock {
        char *start;
        int numBytes;
    };

    /* The freed blocks, an array over 64 entries of its own storage that
     * the destructor does not give back. derived name. */
    struct FreeBlockList {
        FreeBlockList()
            : data(storage), size(0),
              capacityAndFlags(64 | hkArray<FreeBlock>::DONT_DEALLOCATE_FLAG)
        {
        }

        FreeBlock *data;
        int size;
        int capacityAndFlags;
        FreeBlock storage[64];
    };

    char *bufferStart;        /* derived name */
    char *bufferEnd;          /* derived name */
    char *currentEnd;         /* derived name */
    int numAllocations;       /* derived name: counted by each allocation (0x90ccf, 0x90d21) */
    hkUlong peakUse;          /* derived name */
    FreeBlockList freeBlocks; /* derived name */
    hkCriticalSection lock;   /* derived name */
};

struct hkMemoryRouter;

/* Slot 13 of the memory system's vtable: with a thread allocator per
 * thread (flags bit 2), runs slot 13 of the router's one. derived name. */
void FUN_0000d080(hkFreeListMemorySystem *self, hkMemoryRouter &router); /* derived name */

void FUN_0000d0a0(hkFreeListMemorySystem *self); /* derived name */
/* Slots 6 and 7 of the memory system's vtable: hand an int to slot 4 of
 * the allocator interface at +0x20, and read slot 5 back as an int; 0
 * without one. derived names. */
int FUN_0000d230(hkFreeListMemorySystem *self, int value);     /* derived name */
int FUN_0000d250(hkFreeListMemorySystem *self);                /* derived name */
bool FUN_0000d290(hkFreeListMemorySystem *self, int numBytes); /* derived name */

/* Slot 8 of the memory system's vtable: whether its buffer allocator could
 * hold a block of a size. derived name. */
bool FUN_0000d270(hkFreeListMemorySystem *self, int numBytes); /* derived name */

/* Slot 20: hands an int to slot 9 of the allocator interface at +0x20, when
 * there is one. derived name. */
void FUN_0000d2c0(hkFreeListMemorySystem *self, int value); /* derived name */

/* A polymorphic class with an empty virtual destructor and the global
 * operator delete: its deleting destructor FUN_00021a00 (beside hkcdSimdTree's
 * code) is one shared body in slot 1 of 175 vtables, whose slot 0 is an
 * empty complete destructor (FUN_0003b640, FUN_000add50, FUN_001af750, ...). */
class PlainPolymorphic
{
  public:
    virtual ~PlainPolymorphic();
};

/* A reference-counted object, 0x50 bytes (vtable 0x16969d0, constructor
 * FUN_0003e840: takes a counted reference to the object at +0x10, stores the
 * int argument at +0x18 and +0x1c, clears the int at +0xc and the vector at
 * +0x30). The game code at 0xeaa625 sets +0xc to 1 through FUN_0003ea60;
 * FUN_0003ea80 returns the address of the vector. */
/* A 12-byte record (derived name) kept in an array at +0xd0 (count at
 * +0xd8) of the objects FUN_0004d650 and FUN_0005b680 grow, each new one
 * built by the out-of-line constructor FUN_001618f0: the ids at +0 and +8
 * start invalid (0x7fffffff), the u16 at +4 at zero; the caller then stores
 * the first id. */
struct Object001618f0 /* derived name */
{
    Object001618f0();

    u32 first;  /* derived name */
    u16 second; /* derived name */
    u32 third;  /* derived name */
};

/* The world's work on the body of an index with a pointer and an int
 * (0x5d6b0; its bodies are the 0x90-byte entries at +0x20). derived
 * name. */
void FUN_0005d6b0(hknpWorld *self, int index, const void *argument3,
                  int argument4); /* derived name */

/* The body of an index given new velocities, the linear one and the
 * angular one (0x5dc50; 0x178545 passes the motion's linear velocity
 * again). derived name. */
void FUN_0005dc50(hknpWorld *self, int bodyId, const Vec4 &linearVelocity,
                  const Vec4 &angularVelocity); /* derived name */

/* The object whose FUN_00178580 the game calls (0xeb055f, 0xeb0e90): a
 * body's index at +0xc into the bodies of the world at +0x18 (derived
 * names). */
struct Object00178580 /* derived name */
{
    u8 unknown0[0xc];
    s32 index; /* derived name */
    u8 unknown10[8];
    hknpWorld *world; /* derived name */
};

void FUN_00178580(Object00178580 *self, const void *argument); /* derived name */

/* derived name: the body's angular velocity set to the one given, its
 * linear velocity kept, unless the motion's angular velocity in the world
 * already equals it within the constant table's tolerance (0x178460; the
 * game calls it at 0xeb059d, 0xeb0c79 and 0xeb0ef5). */
void FUN_00178460(Object00178580 *self, const Vec4 &angularVelocity);

struct Object0003ea60 {
    u8 unknown0[0xc];
    s32 value;
    u8 unknown10[0x20];
    Vec4 vector; /* +0x30 */
};

/* A reference-counted object, 0x70 bytes (vtable 0x169ab20, constructor
 * FUN_0006bc50) holding arrays at +0x38 (16-byte elements, each releasing
 * the object at +8 of the element), +0x48 and +0x60. Its out-of-line
 * destructor (0x5a230) restores the vtable and frees the arrays; the
 * destructors of two derived classes (vtable 0x1699260 at 0x5a150, and
 * 0x5a14b's) end by running it. */
class RefArrays0005a230 : public hkReferencedObject /* derived name */
{
  public:
    /* 0x6bc50: over the world (stored at +0x10), the arrays sized from it
     * (the world builds it at 0x49594 and, under the derived class, at
     * 0x5a349). */
    RefArrays0005a230(hknpWorld *world);

    /* The destructor (0x5a230, its base variant, which stores the vtable
     * and frees the arrays; slot 0, 0x6b7c0, jumps to it and slot 1,
     * 0x6b7d0, calls it). */
    virtual ~RefArrays0005a230();

    /* The reference-counted class delete (freeReferencedObject; the
     * derived class's deleting destructor 0x5a150). */
    static void operator delete(void *object, unsigned long numBytes);

    /* A 16-byte entry (derived names): the next entry of its run, 0xffff
     * at the end, and a signal at +8. */
    struct Entry {
        u16 next;
        Signal00093530 signal;
    };

    /* A run of entries given back (0x6bd90; the dirty walks at 0x5a96b,
     * 0x5adbb and 0x5b1db): each entry's signal emptied, the run put at
     * the head of the free list. derived name. */
    void FUN_0006bd90(u16 first);

    hknpWorld *world; /* derived name */
    /* Three pointers the constructor clears (0x6bcc3 to 0x6bcd3). derived
     * names. */
    void *pointer18;
    void *pointer20;
    void *pointer28;
    u16 freeHead;           /* derived name: the first free entry, 0xffff for none */
    hkArray<Entry> entries; /* derived name */
    /* Two arrays of 16-bit words, given back by the destructor (0x5a24b,
     * 0x5a284); the first sized by the constructor to the capacity of the
     * world's bodies, every word 0xffff. derived names. */
    hkArray<u16> array48;
    hkBool flag58; /* derived name: cleared by the constructor */
    u8 unknown59[7];
    hkArray<u16> array60;
};

/* The class built over it by hknpWorld's constructor (0x494ff) when the
 * world's construction info asks for it (+0x71): 0x90 bytes, two more
 * arrays (vtable 0x1699260, D14; destructors 0x5a0b0 and 0x5a150 end in
 * the base's 0x5a230). derived name after its constructor. */
class RefArrays0005a340 : public RefArrays0005a230 /* derived name */
{
  public:
    /* 0x5a340 */
    RefArrays0005a340(hknpWorld *world);

    /* Out of line (0x5a0b0, slot 0; 0x5a150, slot 1). */
    virtual ~RefArrays0005a340();

    /* The arrays' elements, not typed yet (derived names). */
    struct Element28 {
        u8 unknown0[0x28];
    };

    struct Element18 {
        u8 unknown0[0x18];
    };

    hkArray<Element28> unknown70; /* 0x28-byte elements */
    hkArray<Element18> unknown80; /* 0x18-byte elements */
};

/* A reference-counted object of 0x58 bytes (vtable 0x168d5b0, D14: slots 5
 * to 13 its own) that hkBaseSystem's start (0x98d0) builds from its second
 * and third arguments, a report function and the object it is called with
 * by shape: a pointer map at +0x10 and an array of 4-byte elements at
 * +0x20, both given back by the destructors, and a critical section at
 * +0x48. */
class Object0000b330 : public hkReferencedObject /* derived name */
{
  public:
    /* 0xb330 */
    Object0000b330(void *reportFunction, void *reportObject);

    /* The members' own destructors: the critical section, the array, the
     * map (0xb1a0, slot 0; the deleting destructor 0xb250, slot 1, holds
     * the same body). Inline, emitted with the vtable in the constructor's
     * file: the executable holds the complete destructor before the
     * deleting one (cookbook 187). */
    inline virtual ~Object0000b330() {}

    /* Slot 6 (0xb390): an id enabled or disabled, under the critical
     * section: its entry taken out of the map, or a 1 put in. derived
     * name. */
    void FUN_0000b390(int id, bool enabled);

    /* Slot 7 (0xb4a0): whether an id is enabled, under the critical
     * section: the map holds a nonzero value for an id that is not.
     * derived name. */
    hkBool FUN_0000b4a0(int id);

    /* Slots 11 and 12 (0xb970, 0xba70): an id pushed on the array and the
     * last one dropped, each under the critical section. derived names. */
    void FUN_0000b970(int id);
    void FUN_0000ba70();

    /* The reference-counted class delete (freeReferencedObject). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 10 (0xb580): under the lock, the int at +0x40 cleared and the
     * map emptied, its storage kept. derived name. */
    void FUN_0000b580();

    OwnedPointerMap map;  /* derived name */
    hkArray<u32> array;   /* derived name */
    void *reportFunction; /* derived name */
    void *reportObject;   /* derived name */
    int unknown40;
    hkCriticalSection criticalSection; /* derived name */
};

/* Slot 7 of hknpHeightFieldShape's vtable (and of 0x16a5990's): its box
 * under a transform, no radius added. derived name. */
void FUN_0012aa80(const hknpHeightFieldShape *self, const Mat4 &transform,
                  hkAabb &aabbOut); /* derived name */

/* The 0x40-byte object hkVersionPatchManager's creator 0x199f80 builds
 * zeroed at its +0x10 (derived name): a string map, an array of 8-byte
 * elements and a string map whose values are strings it owns. Its
 * destructor is out of line (0x19a0b0). */
struct ClassVersionIndex0019a0b0 /* derived name */
{
    /* The owned strings freed to the thread's heap, then the members. */
    ~ClassVersionIndex0019a0b0();

    /* The class allocator: from the thread's heap (0x19a00b), and back to
     * it at the class's size (0x19a27e). */
    static void *operator new(unsigned long numBytes);
    static void operator delete(void *object, unsigned long numBytes);

    StringMap map0;          /* derived name */
    hkArray<void *> array18; /* derived name */
    StringMap ownedNames;    /* derived name */
};

/* A reference-counted object of 0x48 bytes (vtable 0x16a6820, D14, stored
 * by FUN_00199f80 and the out-of-line destructor 0x19a230), built by
 * hkVersionPatchManager's creator: the 0x40-byte index it owns at +0x10, an
 * array of 8-byte elements at +0x18, a pointer map over the containers'
 * heap at +0x28 and a critical section at +0x38. */
class Object0019a230 : public hkReferencedObject /* derived name */
{
  public:
    /* Out of line (0x19a230, slot 0; the deleting destructor 0x19a1e0, slot
     * 1, before it in the executable, cookbook 187): the index destroyed and
     * given back, then the members. */
    virtual ~Object0019a230();

    /* Inline in the creator FUN_00199f80: the members built, then the
     * index allocated and built (zeroed first, its members' constructors
     * after) and kept. */
    Object0019a230() : lock(0)
    {
        index = new ClassVersionIndex0019a0b0();
    }

    /* From the thread's heap (0x199fa7); the reference-counted class
     * delete (freeReferencedObject). */
    static void *operator new(unsigned long numBytes);
    static void operator delete(void *object, unsigned long numBytes);

    ClassVersionIndex0019a0b0 *index; /* derived name */
    hkArray<void *> array18;          /* derived name */
    OwnedPointerMap map28;            /* derived name */
    hkCriticalSection lock;           /* derived name */
};

/* A reference-counted object of 0x40 bytes (vtable 0x16a68d0, D14), the
 * cache hkPlatformObjectWriter's constructor builds in place (0x19aa7b):
 * two pointer maps and an array of loaded buffers. */
class Object0019a7c0 : public hkReferencedObject /* derived name */
{
  public:
    /* Out of line (0x19a7c0, slot 0; the deleting destructor 0x19a770,
     * slot 1): every buffer given back through FUN_0019bb80, then the
     * members' own destructors. */
    virtual ~Object0019a7c0();

    /* The reference-counted class delete (freeReferencedObject). */
    static void operator delete(void *object, unsigned long numBytes);

    OwnedPointerMap map10;   /* derived name */
    OwnedPointerMap map20;   /* derived name */
    hkArray<void *> buffers; /* derived name */
};

/* An object of 0x160 bytes with its own class allocator (vtable 0x169b460,
 * constructor FUN_000763a0) holding an array of 0x500-byte elements at
 * +0x140 (count at +0x148). Its out-of-line destructor FUN_000760c0
 * restores the vtable and destroys the elements. A derived class
 * (vtable 0x169b410, constructor FUN_000768c0: a pointer at +0x150) adds
 * nothing to destroy, so both vtables share the complete destructor
 * FUN_00076060 and the deleting destructor FUN_00076070. */
class Elements000760c0 : public hkBaseObject /* derived name */
{
  public:
    /* FUN_000763a0: the arrays' storage reserved, the 0x500-byte elements
     * built (their streams reset over the two allocators the thread
     * context holds at +0x260 and +0x250) and the counts set. The context
     * comes first and the body does not read it. derived names. */
    Elements000760c0(void *context, void *allocator260, void *allocator250, int numElements,
                     int capacity20, int capacity10);
    virtual ~Elements000760c0();

    /* An element (derived names): five block streams. */
    struct Element {
        hkBlockStream slots[5];
    };

    /* Slot 3 of both vtables (0x76910): every element's streams emptied,
     * the second and third with the first cache, the others with the
     * second, then the stream at +0x40 with the second. derived names. */
    void FUN_00076910(BlockCache *cacheA, BlockCache *cacheB);

    u8 unknown8[0x38];
    hkBlockStream stream40;    /* derived name */
    hkArray<Element> elements; /* derived name */
};

/* The derived class (vtable 0x169b400, the same seven slots): built once,
 * by FUN_0006c850 at 0x6cc19, over the simulation context it is given
 * (kept at +0x150), one element and room for one entry in each array; the
 * thread context it is also given is not read. derived names. */
class Elements000768c0 : public Elements000760c0 /* derived name */
{
  public:
    Elements000768c0(void *simulationContext, void *threadContext, void *allocator260,
                     void *allocator250);
    virtual ~Elements000768c0();

    void *simulationContext; /* derived name */
};

void FUN_000760c0(Elements000760c0 *self); /* derived name */

/* An object of 0xa0 bytes (vtable 0x16a3f50, no type info; constructor
 * FUN_00140a60, out-of-line destructor FUN_00140e70, which restores the
 * vtable and releases the pointers from +0x10 up to the count at +0x60);
 * its deleting destructor 0x140e20 runs the destructor and frees the 0xa0
 * bytes unless null (written as calls while the class is opaque, cookbook
 * 15). derived names. */
/* What the object keeps at +0x98, made on first use by its slot 7 (derived
 * name): 0xf8 bytes from the thread's heap, built by the out-of-line
 * constructor 0x18d640, which gives it the broad phase's tasks (the
 * per-layer update tasks, the collide tasks); 0x18d960 sets it up for a
 * step from its four arguments (the second's +0x1e0 and +0x10 read). */
class BroadPhaseTasks0018d640 /* derived name */
{
  public:
    BroadPhaseTasks0018d640();

    static void *operator new(unsigned long numBytes);

    /* Out of line (0x18d880, called by the owner's destructor at 0x140ef1
     * before it frees the 0xf8 bytes): every task deleted, the three
     * single ones first. */
    ~BroadPhaseTasks0018d640();

    void FUN_0018d960(void *argument1, void *argument2, void *argument3,
                      void *argument4); /* derived names */

    u8 unknown0[0x20];
    /* The constructor's tasks (derived names): the dirty bodies' update, the
     * update of each of eight layers (with the layer, 0 to 7), the export
     * of new pairs, the finish, and sixteen collide tasks (with their
     * index). */
    hknpBroadPhaseUpdateDirtyBodiesTask *updateDirtyBodiesTask;
    hknpBroadPhaseUpdateLayerTask *updateLayerTasks[8];
    hknpBroadPhaseExportNewPairsTask *exportNewPairsTask;
    hknpBroadPhaseUpdateFinishedTask *updateFinishedTask;
    BroadPhaseCollideTask *collideTasks[16];
};

/* The object is the broad phase's trees by layer (BroadPhaseLayers00142a40,
 * below: its slot 4 marks bodies, slot 5 is the update 0x142bb0). */
struct BroadPhaseLayers00142a40;

void FUN_00140e70(BroadPhaseLayers00142a40 *self); /* derived name */
void FUN_00140e20(BroadPhaseLayers00142a40 *self); /* derived name */

/* Its deleting destructor (0x76070, beside 0x760c0; both vtables' slot
 * 1): the destructor, then the 0x160 bytes back to the thread's heap
 * unless null. Written as calls while the class is opaque (cookbook 15).
 * derived name. */
void FUN_00076070(Elements000760c0 *self); /* derived name */
/* Reads the processor's time-stamp counter (rdtscp, edx:eax joined into 64
 * bits); its only caller is FUN_00092200, whose caller (0xdb64) mixes the
 * low half into a random seed with the time and a process value. */
u64 FUN_00184cf0(); /* derived name */

/* The tick counter (0x92200, a jump to FUN_00184cf0). derived name. */
u64 FUN_00092200(); /* derived name */

/* A four-byte structure layout description (FUN_00180ee0, FUN_00180ef0):
 * the rules {8, 1, 1, 1} and {8, 1, 0, 1} sit in rodata at 0x14cb8f6 and
 * 0x14cb8fa, just before the assert string of hkStructureLayout.cpp; the
 * class is likely hkStructureLayout (the file of FUN_001814f0), not
 * established. */
struct LayoutRules00180ef0 {
    u8 bytesInPointer;
    u8 littleEndian;
    u8 reusePadding;
    u8 emptyBaseOptimization;
};

struct Layout00180ef0 {
    /* A class's member offsets computed under the rules unless the map
     * already holds the class (0x180f00, called at 0x19a91e and 0x19b05b
     * with recurse 1). derived name. */
    void FUN_00180f00(hkClass &klass, PointerMap &classesDone, int recurse) const;

    LayoutRules00180ef0 rules;
};

/* The layout built with the host's rules (0x180ee0). derived name. */
void FUN_00180ee0(Layout00180ef0 *self); /* derived name */

/* An object graph deep-copied under its class (0x19b2b0, Havok's deep
 * copier: the copies already made by original, the vtable and type-info
 * registries and the copy flags, all null or zero from 0x19a8cf). derived
 * names. */
void *FUN_0019b2b0(const void *data, const hkClass &klass, PointerMap *previousCopies,
                   const void *vtableRegistry, const void *typeInfoRegistry,
                   int flags); /* derived name */

/* What 0x19aca0 keeps at +0x18 of its object (derived names): the classes
 * it has copied, by original, the classes whose layout is done, and every
 * copy made. */
struct ClassCopies0019a880 /* derived name */
{
    /* A class's copy, made the first time (0x19a880, three calls from
     * 0x19aca0): deep-copied as an hkClass, kept, and its member offsets
     * computed under the layout given. derived name. */
    hkClass *FUN_0019a880(const hkClass *klass, const Layout00180ef0 &layout);

    u8 unknown0[0x10];
    PointerMapOf<const hkClass *, hkClass *> copies;
    PointerMap classesDone;
    hkArray<hkClass *> allCopies;
};

/* The member offsets of a class and, when recurse is set, of its members'
 * classes, computed in place under the rules; each class done is added to
 * the map (0x180f50). derived name. */
void FUN_00180f50(hkClass &klass, const LayoutRules00180ef0 &rules, PointerMap &classesDone,
                  int recurse); /* derived name */

/* The object copier (derived name, from hkObjectCopier.cpp, the home of
 * its neighbours 0x1a0890 and 0x1a0b40): a reference-counted object
 * (vtable address point 0x16a75e0) whose constructor 0x1a0840 copies the
 * source layout to +0xc and the target layout to +0x10, stores the flags
 * at +0x14 and sets +0x18 when the two byte orders differ. Slot 6
 * (0x1a0b20) tells whether a member of one layout can be copied to one of
 * the other. */
class hkObjectCopier : public hkReferencedObject /* derived name */
{
  public:
    /* 0x1a0840 (the platform object writer builds one at 0x19a9dc, the
     * packfile writer at 0x19b49e). */
    hkObjectCopier(const Layout00180ef0 &layoutIn, const Layout00180ef0 &layoutOut, int flags);

    int FUN_001a0b20(const hkClassMember &src,
                     const hkClassMember &dst); /* vtable slot 6; derived name */

    Layout00180ef0 layoutIn;  /* derived name */
    Layout00180ef0 layoutOut; /* derived name */
    int flags;                /* derived name */
    hkBool byteSwap;          /* derived name */
};

/* The platform object writer (derived name): a reference-counted object
 * (vtable address point 0x16a6920, constructor 0x19a950) that builds an
 * object copier from the host layout {8, 1, 1, 1} to the target one and
 * keeps it at +0x10. FUN_0019ab00 returns the copier's target layout; the
 * packfile writer at 0x183261 compares its byte order with the host's. */
class hkPlatformObjectWriter : public hkReferencedObject /* derived name */
{
  public:
    /* Out of line (0x19abf0, slot 0; the deleting destructor 0x19ab10,
     * slot 1): the copier's reference released, then the cache's when
     * there is one. */
    virtual ~hkPlatformObjectWriter();

    /* The reference-counted class delete (freeReferencedObject). */
    static void operator delete(void *object, unsigned long numBytes);

    const Layout00180ef0 &FUN_0019ab00() const; /* derived name */
    /* Slot 6 (0x19ae90): raw bytes to a stream, failing unless all of them
     * were written. derived name. */
    hkResult FUN_0019ae90(hkStreamWriter *writer, const void *data,
                          int size); /* vtable slot 6; derived name */

    hkObjectCopier *copier; /* derived name */
    /* Null when the layouts are the host's, else the constructor's argument
     * with a reference taken, or a new 0x40-byte object of the vtable
     * 0x16a68d0 (0x19aa7b). derived name. */
    hkReferencedObject *cache;
};

/* What the binary writer's save (0x183350) builds on its stack and hands
 * its section writers (derived names): arrays of 64-byte and 8-byte
 * entries at +8 and +0x18, the stream at +0x28, an object writer at +0x30,
 * the offset of each class's name in the class names' section at +0x50
 * (0x181dc0's records), the save's records at +0x68, the byte-swap flag at
 * +0x78. Its destructor (0x1819c0, out of line, called at 0x183746)
 * destroys the members. */
struct PackfileSaveContext00181dc0 /* derived name */
{
    struct Entry40 {
        u8 unknown0[0x40];
    };

    ~PackfileSaveContext00181dc0();

    u8 unknown0[8];
    hkArray<Entry40> entries8;        /* derived name */
    hkArray<const void *> pointers18; /* derived name */
    hkStreamWriter *writer;
    hkPlatformObjectWriter objectWriter; /* derived name */
    StringMap classNameOffsets;
    hkArray<hkRelocationInfo>
        records; /* derived name (the relocations, 0x19b0b0 their destructor) */
    hkBool byteSwap;
};

/* A polymorphic pool (vtables 0x168cbb0 and 0x16d3390, the second a
 * game-region class sharing every slot from 2): slot 9 (FUN_00007880)
 * returns the count at +0x328, the number of 64-byte records that slot 6
 * (FUN_000076d0) walks after storing the callback FUN_00007730 and its
 * argument at +0x310. Slot 13 (FUN_000075d0) sets the flag at +0x330, which
 * the worker loop at 0x7337 tests after each callback; the code at 0x70a1
 * clears it with the byte after it. That byte (+0x331) is set by slots 5
 * and 6 (0x7600, 0x7660, 0x76d0) when they hand the workers a callback,
 * tested by the waits at 0x7402 and 0x774d, and read by slot 7
 * (FUN_000077a0) as a test against zero (hkBool). */
/* It is reference-counted: its constructor 0x6d70 stores 0xffff0001 at +8
 * and slots 2 to 4 are hkReferencedObject's (0x270, 0x42d0, 0x69a0). From
 * +0x10, up to eleven 64-byte worker records (0x7890 starts at most 11
 * threads): the pool at +0, the thread at +8 (constructed by 0x104b0 and
 * started by 0x10580 on FUN_00007180 with the record as its argument), the
 * worker's index plus one at +0x18. Slot 14 (0x71a0) is a worker's loop,
 * taking its index (it reads the record's +0x18 at index * 64). */
/* A monitor stream's extent, as a thread pool hands out its workers'
 * streams (0x77b0: 16-byte elements, the start then the end). derived
 * names. */
struct MonitorStreamRange /* derived name */
{
    const char *begin; /* derived name */
    const char *end;   /* derived name */
};

class hkWorkerThreadContext;

class Pool00007880 : public hkReferencedObject /* derived name */
{
  public:
    struct WorkerRecord /* derived name */
    {
        Pool00007880 *pool; /* derived name */
        hkThread thread;    /* derived name */
        int threadId;       /* derived name */
        int threadId1c;     /* derived name: the same index plus one (0x78fc) */
        /* Set to stop the worker before its start is signalled (0x7951).
         * derived name. */
        bool killThread;
        /* Set by slot 12 when it clears the worker's timers. derived name. */
        bool timersCleared;
        u8 unknown22[6];
        /* What the pool signals to start the worker on a callback (slots 5
         * and 6, through FUN_00007600). derived name. */
        hkSemaphore workerStart;
        /* The worker's monitor stream: the loop (0x721c, 0x7228) copies the
         * thread's start and current pointers here; slot 12 rewinds the
         * second to the first. derived names. */
        char *monitorStreamBegin;
        char *monitorStreamEnd;
    };

    /* What a worker runs on the argument stored beside it. derived name. */
    typedef void (*WorkCallback)(void *argument);

    virtual ~Pool00007880();

    /* Slots 5 (0x7660) and 6 (0x76d0): FUN_00007600 with the callbacks
     * FUN_000076c0 and FUN_00007730. derived names. */
    virtual void FUN_00007660(void *argument);
    virtual void FUN_000076d0(void *argument);
    virtual bool FUN_000077a0() const; /* vtable slot 7; derived name */
    /* Slot 8 (0x7740): while workers run, one count of the semaphore taken
     * for each of them, then the flag and the running byte cleared.
     * derived name. */
    virtual void FUN_00007740();
    virtual int FUN_00007880() const; /* vtable slot 9; derived name */
    /* Slot 10 (0x7890): the workers brought to a number, at most eleven:
     * new ones started on their records, the last ones stopped, signalled
     * and joined. derived name. */
    virtual void FUN_00007890(int numThreads);
    /* Slot 11 (0x77b0): each worker's monitor stream appended, its start
     * and end, the array grown from the allocator given. derived name. */
    virtual void FUN_000077b0(hkArray<MonitorStreamRange> &streamsOut, AllocatorBase &allocator);
    /* Slot 12: every worker's monitor stream rewound to its start. */
    virtual void FUN_00007850(); /* vtable slot 12; derived name */
    virtual void FUN_000075d0(); /* vtable slot 13; derived name */
    /* Slot 14 (0x71a0): a worker's loop: its thread context built for the
     * worker's thread, the thread's monitor stream resized to the pool's
     * buffer size when there is one and its extent recorded, then the
     * callbacks run (0x7280) until the pool stops. derived name. */
    virtual void FUN_000071a0(int workerIndex);

    /* The worker's callbacks run (0x7280, not a slot): each time its start
     * is signalled, until it is killed, the callback run on its argument
     * (the thread's monitor stream reset first when the timers were
     * cleared), the stream's end recorded, the thread's memory collected
     * when the pool asks for it, and the pool told the worker is done.
     * derived name. */
    void FUN_00007280(int workerIndex, hkWorkerThreadContext &context);

    /* Hands the workers a callback (0x7600, not a slot; inline in slots 5
     * and 6): running set, the callback and its argument stored, each
     * worker's start signalled from the last. derived name. */
    void FUN_00007600(WorkCallback newCallback, void *argument);

    u8 unknownC[4];
    WorkerRecord workers[11]; /* derived name */
    u8 unknown2d0[0x40];
    WorkCallback callback;  /* derived name */
    void *callbackArgument; /* derived name */
    /* What a worker signals when it is done with a callback (the waits at
     * 0x7410 and 0x7761 take one count per worker). derived name. */
    hkSemaphore workerDone;
    int count; /* derived name */
    /* The size each worker's monitor stream is given (0x71de). derived
     * name. */
    int timerBufferSize;
    bool flag330;   /* derived name */
    hkBool running; /* derived name */
    u8 unknown332[6];
    /* The workers' threads' name and stack size (0x7901, 0x7909). derived
     * names. */
    const char *threadName;
    int stackSize;
    /* To the 0x348 bytes the deleting destructor (0x7390) frees by
     * default. */
    u8 unknown344[4];
};

/* The pool's destructor (0x73e0, which stores the vtable 0x168cba0) and
 * its deleting destructor (slot 1, 0x7390), written as calls while the
 * destructor is not (cookbook 15, 97). derived names. */
void FUN_000073e0(Pool00007880 *self); /* derived name */
void FUN_00007390(Pool00007880 *self); /* derived name */

/* derived name: the start function of a pool's worker thread (0x7890
 * passes it to 0x10580 with the worker's record): runs the pool's worker
 * loop for the record's index. */
void *FUN_00007180(void *argument); /* derived name */

/* A singly linked node (derived name): the next node at +0. FUN_000188a0
 * counts a list's nodes; 0x1630 sums the counts of the two lists at +0x18
 * and +0x20 of each of its objects before it allocates eight bytes per
 * node. */
struct ListNode000188a0 /* derived name */
{
    ListNode000188a0 *next; /* derived name */
};

int FUN_000188a0(const ListNode000188a0 *node); /* derived name */

/* A Mersenne twister (MT19937): 624 words of state in a block of 2496 bytes
 * the seeding (FUN_000106e0, multiplier 1812433253) allocates on first use
 * and FUN_00010690 frees, the index at +0. The constructor (FUN_00010680)
 * only clears the state pointer; 0xdaf0 builds one at +0x10 of a new
 * reference-counted object and seeds it from the time. */
struct MersenneTwister /* derived name */
{
    /* Out of line (0x10680): no state until the first seeding. */
    MersenneTwister();

    /* Out of line (0x10690): the state given back to the thread's heap and
     * forgotten; hkUuidPseudoRandomGenerator's destructors (0xd9e0, 0xda50)
     * run it on their +0x10 after the lock's. */
    ~MersenneTwister();

    /* The state seeded (0x106e0; hkUuidPseudoRandomGenerator's creation
     * seeds it from the time): allocated from the thread's heap the first
     * time, then each word from the one before it. derived name. */
    void FUN_000106e0(u32 seed);

    enum { NUM_STATE_WORDS = 624 }; /* derived name */

    u16 index;  /* derived name */
    u32 *state; /* derived name */
};

/* hkUuidPseudoRandomGenerator, the singleton registered by that name
 * (create function 0xdaf0, vtable 0x168d8a0): a twister at +0x10 and a
 * critical section at +0x20, 0x30 bytes. */
class hkUuidPseudoRandomGenerator : public hkReferencedObject
{
  public:
    /* Inline in the create function (0xdaf0): the twister, a lock of 5000
     * spins, then the twister seeded from the time, the clock and the tick
     * counter. */
    hkUuidPseudoRandomGenerator() : lock(5000)
    {
        twister.FUN_000106e0(u32(time(0)) ^ u32(clock()) ^ u32(FUN_00092200()));
    }

    /* Slot 0 (0xd9e0); slot 1 (0xda50) frees at the recorded size. */
    virtual ~hkUuidPseudoRandomGenerator();

    /* The class allocator: a block of the thread's heap (defined beside the
     * router). */
    static void *operator new(unsigned long numBytes);
    static void operator delete(void *object, unsigned long numBytes);

    MersenneTwister twister; /* derived name */
    hkCriticalSection lock;  /* derived name */
};

/* A free list of fixed-size elements: the head of the free elements at +0
 * (each holds the next), the element size at +8, the bump pointer and the
 * end of the current block at +0x40 and +0x48, the free count at +0x68.
 * FUN_00019230 adds a block, FUN_00018770 frees them all, FUN_00019440
 * fills a statistics record. */
/* A free list's block header (derived names): the next block, the block's
 * memory, its element count at +0x18; 0x20 bytes. */
struct FreeListBlock /* derived name */
{
    FreeListBlock *next;
    void *memory;
    /* The first element (the list's check, 0x18980, finds a free element
     * between it and numElements elements on). derived name. */
    char *elements;
    u64 numElements;
};

struct FreeList /* derived name */
{
    /* Out of line (0x18640; TwoBaseAllocator's constructor builds four at
     * 0x19b8 to 0x19e6): the list empty, the fields at +0x10 and +0x38
     * left as they are. */
    FreeList();

    /* Built set up (0x18580; TwoBaseAllocator's constructor builds its
     * size classes' lists in place at 0x1c48): the element size rounded up
     * to the alignment, the block size, the two allocators (a null block
     * allocator taking the thread's router's temporary allocator) and the
     * number of elements a block holds. */
    FreeList(u64 newElementSize, u64 newAlignment, u64 newBlockSize,
             AllocatorBase *newBlockAllocator, AllocatorBase *newElementAllocator);

    /* Sets the free list up (0x186a0): frees what it held, then keeps the
     * element size rounded up to the alignment, the block size and the two
     * allocators, a null block allocator taking the thread's router's
     * temporary allocator. */
    void FUN_000186a0(u64 elementSize, u64 alignment, u64 blockSize, AllocatorBase *blockAllocator,
                      AllocatorBase *elementAllocator); /* derived name */

    /* Every block given back to its allocator and the list emptied
     * (0x18770): the setup (0x186c1) calls it before it starts over and the
     * owner at 0x1c81 calls it on a list it keeps using, so it is a member
     * of its own, which the destructor runs. */
    void FUN_00018770(); /* derived name */

    /* A chain of blocks given back, their elements uncounted: the block
     * with its elements to the block allocator, or, when the element
     * allocator keeps the headers apart, the memory to the one and the
     * header to the other (twice inline in 0x18770). derived name. */
    void giveBackBlocks(FreeListBlock *block)
    {
        while (block) {
            totalNumElements -= block->numElements;
            numFreeElements -= block->numElements;
            FreeListBlock *next = block->next;
            if (!elementAllocator) {
                blockAllocator->FUN_00008d80(block, int(blockSize));
            } else {
                blockAllocator->FUN_00008d80(block->memory, int(blockSize));
                elementAllocator->blockFree(block, sizeof(FreeListBlock));
            }
            block = next;
        }
    }

    ~FreeList()
    {
        FUN_00018770();
    }

    /* A new block's first element when the current block is used up
     * (0x19230): a block of the list's own or a new one. derived name. */
    void *FUN_00019230();

    /* The list's counts checked against its blocks (0x188c0, the
     * allocator's slot 22 asks it of each list): true when they agree.
     * derived name. */
    bool FUN_000188c0() const;

    /* An element: a freed one first, else the next of the current block,
     * else the slow path (inline in the allocator's 0x14aa0). derived
     * name. */
    void *alloc()
    {
        if (void **element = static_cast<void **>(freeHead)) {
            numFreeElements--;
            freeHead = *element;
            return element;
        }
        if (top < blockEnd) {
            numFreeElements--;
            char *element = top;
            top = element + elementSize;
            return element;
        }
        return FUN_00019230();
    }

    /* An element put back at the head of the freed ones (inline in
     * TwoBaseAllocator's free, 0x2ce2). derived name. */
    void free(void *element)
    {
        numFreeElements++;
        *static_cast<void **>(element) = freeHead;
        freeHead = element;
    }

    /* The blocks whose elements are all free given back to the block
     * allocator, their headers to the element allocator when it keeps them
     * apart, and counted (0x19190; slots 13 and 14 of TwoBaseAllocator,
     * 0x31e3 and 0x33e2, call it). derived name. */
    int FUN_00019190();

    /* Whether a block's elements are all free (0x189d0). derived name. */
    hkBool32 FUN_000189d0(FreeListBlock *block);

    /* Up to numBlocks blocks examined from where the last call stopped,
     * each whose elements are all free moved from the blocks in use to
     * the free blocks; the number examined out, and whether the walk came
     * to the end (0x18ba0; TwoBaseAllocator's slot 14 runs it, 0x33c4).
     * derived name. */
    bool FUN_00018ba0(int numBlocks, int &numBlocksOut);

    void *freeHead;  /* derived name */
    u64 elementSize; /* derived name */
    /* The last block in use the walk above examined and kept, none when it
     * starts from the first. derived name. */
    FreeListBlock *cursor;
    FreeListBlock *activeBlocks;     /* derived name */
    FreeListBlock *freeBlocks;       /* derived name */
    u64 blockSize;                   /* derived name */
    u64 unknown30;                   /* the alignment (0x18580); derived name */
    u64 elementsPerBlock;            /* derived name */
    char *top;                       /* derived name */
    char *blockEnd;                  /* derived name */
    AllocatorBase *blockAllocator;   /* derived name */
    AllocatorBase *elementAllocator; /* derived name */
    u64 totalNumElements;            /* derived name */
    s64 numFreeElements;             /* derived name */
};

/* An allocator's statistics, six signed byte counts (the copy in slot 9 of
 * the allocator at 0x16a3230, FUN_0008f470; its allocation path keeps the
 * third as the maximum of the second). Field names derived. */
struct MemoryStatistics /* derived name */
{
    /* Every figure unknown (-1) until an allocator reports it (0x268c on,
     * TwoBaseAllocator's slot 11). */
    MemoryStatistics()
        : allocated(-1), inUse(-1), peakInUse(-1), available(-1), totalAvailable(-1),
          largestBlock(-1)
    {
    }

    s64 allocated;      /* derived name */
    s64 inUse;          /* derived name */
    s64 peakInUse;      /* derived name */
    s64 available;      /* derived name */
    s64 totalAvailable; /* derived name */
    s64 largestBlock;   /* derived name */
};

void FUN_00019440(const FreeList *self, MemoryStatistics &statistics); /* derived name */

/* An allocator of fixed-size blocks over the free list at +8 (vtable address
 * point 0x168e5c0, slots 0 and 1 the one destructor 0x14a50): blockAlloc and
 * bufAlloc are one body (0x14aa0), blockFree and bufFree another (0x14af0);
 * slot 9 (FUN_00014c40) reports the free list's statistics. */
class FixedSizeAllocator : public AllocatorBase /* derived name */
{
  public:
    /* Slots 0 and 1 (0x14a50): the free list's blocks given back, then
     * AllocatorBase's destructor (the empty 0x8d60, out of line). */
    virtual ~FixedSizeAllocator();

    /* Sets the free list up with an alignment of at least 32 and no element
     * allocator (the caller at 0x1b92 passes 32, 8 and the block size). */
    void FUN_00014a80(u64 elementSize, u64 alignment, u64 blockSize,
                      AllocatorBase *blockAllocator);      /* derived name */
    void FUN_00014c40(MemoryStatistics &statistics) const; /* vtable slot 9; derived name */

    /* Slots 2 and 4 (0x14aa0): an element of the free list. */
    void *FUN_00014aa0(); /* derived name */

    /* Slot 7 (0x14b10): the blocks taken from the free list. */
    virtual void blockAllocBatch(void **blocksOut, int numBlocks, int blockSize);

    /* Slot 8 (0x14be0): the non-null blocks pushed on the free list. */
    virtual void blockFreeBatch(void **blocks, int numBlocks, int blockSize);

    FreeList freeList; /* derived name */
};

/* An allocator that draws its blocks from another allocator and keeps them
 * on a list (vtable 0x16a3220, address point 0x16a3230; constructor
 * FUN_0008f180, destructor FUN_0008f120 in slots 0 and 1): a critical
 * section at +8 (spin count 1000), the parent allocator at +0x18, its
 * statistics at +0x20 and the list head at +0x50, each block with a 16-byte
 * header (next, rounded size, requested size). Slots 2 and 3 (0x8f220,
 * 0x8f330) allocate and free under the lock, slot 9 (0x8f470) copies the
 * statistics, slot 11 resets the peak. */
class BlockListAllocator : public AllocatorBase /* derived name */
{
  public:
    /* 0x8f180: the lock with a spin count of 1000, the parent kept, the
     * counts of what was drawn zeroed and no block yet. */
    BlockListAllocator(AllocatorBase *parent);

    /* Slots 0 and 1 (0x8f120, one body): the lock destroyed, then
     * AllocatorBase's destructor. Inline: the memory system's destructor
     * 0xc360 holds it for its member at +0x28. */
    virtual ~BlockListAllocator() {}

    /* Slots 2 and 3 (0x8f220, 0x8f330): under the lock. */
    virtual void *blockAlloc(int numBytes);
    virtual void blockFree(void *pointer, int numBytes);
    /* Slot 9 (0x8f470): the statistics copied under the lock. */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;

    void FUN_0008f560(); /* vtable slot 11; derived name */

    /* The header before each block (0x8f2b1 to 0x8f2c2): the next block
     * on the list, the size drawn from the parent and the size asked for.
     * derived names. */
    struct Block {
        Block *next;
        int size;
        int numBytes;
    };

    /* mutable: the const statistics read takes it too. */
    mutable hkCriticalSection lock; /* derived name */
    AllocatorBase *parent;          /* derived name */
    MemoryStatistics statistics;    /* derived name */
    Block *blocks;                  /* derived name */
};

/* A thread's allocator (derived name; vtable 0x168e460, address point
 * 0x168e470, constructor FUN_000143a0): the memory system keeps one per
 * thread, 0x1a8 bytes apart from its +0x550, and when its flags have bit 2
 * hands the thread's one to the router as its temporary allocator (+0x58,
 * FUN_0000c590). It adds slot 13 (0x14690) to the allocator's slots. */
class ThreadMemory : public AllocatorBase /* derived name */
{
  public:
    /* Out of line (0x143a0): the free lists and the tables cleared. */
    ThreadMemory();

    /* Slots 0 and 1 (0x13ea0, one body): the cached blocks given back
     * (slot 13) before AllocatorBase's destructor; the memory system's
     * destructor 0xc360 holds it for each thread's record, slot 13 called
     * through the vtable. Declared `inline`: the complete and deleting
     * destructors hold the base one with slot 13 in it, past 225 (cookbook
     * 300: without the hint the complete one is a jump to the base one). */
    inline virtual ~ThreadMemory()
    {
        FUN_00014690();
    }

    virtual void *blockAlloc(int numBytes); /* slot 2 (0x140e0) */

    /* Slot 13 (0x14690), declared `inline`: the destructor (0x13ea0) holds
     * it, past -O2's threshold of 225, which needs the hint's 325 (defined
     * in func_00014690.cpp, the class's file). derived name. */
    inline virtual void FUN_00014690();

    /* Gives the thread's allocator the allocator it draws from and how many
     * blocks each free list may keep (FUN_0000c590 passes 8); a null
     * allocator only clears it. */
    void FUN_00014610(AllocatorBase *memory, int maxNumElemsOnFreeList); /* derived name */

    /* Slot 10 (0x14920): a request of a row's size occupies the row's
     * block size in the allocator it draws from; a larger one is that
     * allocator's to size. */
    virtual int getAllocatedSize(const void *pointer, int numBytes) const;

    /* The largest request a row serves, and the largest the small table
     * indexes in 32-byte steps (larger ones in 1024-byte steps). derived
     * names. */
    enum { MAX_ROW_SIZE = 8192, MAX_SMALL_ROW_SIZE = 640 };

    /* The row a request of a row's size is served from. derived name. */
    int getRow(int numBytes) const
    {
        if (numBytes <= MAX_SMALL_ROW_SIZE) {
            return smallSizeToRow[(numBytes + 31) >> 5];
        }
        return largeSizeToRow[(numBytes - 1) >> 10];
    }

    /* Slot 3 (0x14220): a block of a row's size onto its row's free list,
     * or, when the list is full, through FUN_000147c0, which first gives
     * part of the list back; a larger one back to the allocator it came
     * from. */
    virtual void blockFree(void *pointer, int numBytes);

    /* The free itself, inline in slot 3 and in slot 6's resize (0x1404a to
     * 0x140c6): declared `inline`, the hint its cost (225 to 250) needs in
     * the resize (defined in func_00014220.cpp). derived name. */
    inline void freeBlock(void *pointer, int numBytes);

    /* Slot 6 (0x14000): a buffer resized as a new block of the size asked
     * for, the old contents copied up to the smaller size and the old block
     * freed, through this allocator's own allocation by name. derived
     * name. */
    virtual void *FUN_00008d90(void *pointer, int oldNumBytes, int &numBytesInOut);

    /* A block onto a full row's list (0x147c0), the list emptied down to
     * half its limit into the allocator first. derived name. */
    void FUN_000147c0(int row, void *pointer);

    /* Slots 7 and 8 (0x142a0, 0x14320): a batch of a row's size block by
     * block through slots 2 and 3, a larger one passed to the allocator it
     * draws from. */
    virtual void blockAllocBatch(void **blocksOut, int numBlocks, int blockSize);
    virtual void blockFreeBatch(void **blocks, int numBlocks, int blockSize);

    /* Slot 9 (0x14640): only what the free lists hold is known, the blocks
     * kept on them times their rows' sizes; every other figure is -1. */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;

    /* A row's free list: the blocks kept for reuse, linked through their
     * first word, and how many (slot 13 gives them back four at a time).
     * derived names. */
    struct FreeList {
        /* The first block taken off, or null when there is none (inline in
         * slot 13, 0x14730). derived name. */
        void *pop()
        {
            if (head) {
                void *block = head;
                numElem--;
                head = *static_cast<void **>(block);
                return block;
            }
            return HK_NULL;
        }

        /* A block put at the head (inline in slot 2's refill, 0x141c0).
         * derived name. */
        void push(void *block)
        {
            numElem++;
            *static_cast<void **>(block) = head;
            head = block;
        }

        void *head;
        int numElem;
    };

    AllocatorBase *memory;     /* derived name; slot 13 returns blocks to it */
    int maxNumElemsOnFreeList; /* derived name */
    u8 unknown14[4];
    FreeList freeLists[16]; /* derived name; one per row */
    int rowToSize[16];      /* derived name; a row's block size */
    s8 smallSizeToRow[21];  /* derived name; by (size + 31) >> 5 */
    int largeSizeToRow[8];  /* derived name; by (size - 1) >> 10 */
};

/* A union-find over node indices (derived name; the stage timer of its
 * caller at 0x6dcf3 is "StUnionFind"), 0x18 bytes, built by FUN_0008f640:
 * the parents (an object whose +0 points to the int array; -1 marks a root)
 * at +0, the node count at +8, an int at +0xc set to 1 there and cleared
 * by FUN_00065f10, -1 at +0x10 and 0 at +0x14. FUN_0008f710 joins two
 * nodes. */
struct UnionFindParents /* derived name */
{
    /* Back to the thread's heap at its size, 0x10 bytes (the owner's
     * destructor, 0x65e2f). */
    static void operator delete(void *object, unsigned long numBytes);

    int *data; /* derived name */
    u8 unknown8[8];
};

struct UnionFind /* derived name */
{
    /* 0x8f640: every node its own root. */
    UnionFind(UnionFindParents *parents, int numNodes);

    /* Back to the thread's heap at its size, 0x18 bytes (the owner's
     * destructor, 0x65e01). */
    static void operator delete(void *object, unsigned long numBytes);

    /* 0x8f6a0 (called at 0x62ce4): a node's root, every node on the way
     * made a child of the root. A negative parent marks a root. derived
     * name. */
    int findRootOfNode(int node);

    /* 0x8f7d0 (called at 0x14e94e): every node pointed straight at its
     * root and the roots counted, once; the count kept with the state set
     * (a join clears it). Out of line over collapseTree, which the group
     * assignment 0x8f850 holds inline. derived name. */
    int FUN_0008f7d0();

    /* Each node that is not a root pointed at its root, the roots counted;
     * the parents' storage is read again after each store (the library is
     * built without strict aliasing). derived name. */
    int collapseTree()
    {
        if (state) {
            return numRoots;
        }
        int roots = numNodes;
        int *const end = parents->data + numNodes;
        for (int *node = parents->data; node != end; node++) {
            if (*node >= 0) {
                roots--;
                while (parents->data[*node] >= 0) {
                    *node = parents->data[*node];
                }
            }
        }
        state = 1;
        numRoots = roots;
        return roots;
    }

    /* 0x8f850 (called at 0x62d86): the tree collapsed, then each root
     * given its group's index in order and its group's size appended,
     * every other node its root's group; a failure when the sizes cannot
     * be made room for. derived name. */
    hkResult FUN_0008f850(hkArray<int> &groupSizes);

    /* 0x8f710: two nodes joined, under the root of the first. derived
     * name. */
    void FUN_0008f710(int nodeA, int nodeB);

    UnionFindParents *parents; /* derived name */
    int numNodes;              /* derived name */
    int state;                 /* derived name */
    int numRoots;              /* derived name: -1 until counted */
    int unknown14;             /* derived name */
};

/* A 32-byte record of the union-find's owner: a bit field (the callers at
 * 0x6d79e and 0x16e475 resize it with FUN_00047b30) and eight bytes the
 * constructor leaves alone. */
struct Record00065f00 /* derived name */
{
    hkBitField bits; /* derived name */
    u8 unknown18[8];
};

/* The union-find's owner (constructor FUN_00065b70, destructor
 * FUN_00065de0): the union-find at +0 (freed with 0x18 bytes) and its
 * parents at +8 (0x10 bytes), twelve 32-byte records from +0x10 (each
 * starting with an empty hkBitField; FUN_00065f00 returns one by index), the
 * node count at +0x190 and a second count at +0x194; the constructor sets
 * the flag at +0x198, FUN_00065f20 clears it (called at 0x6dd1f and
 * 0x14e946, after the records are filled). */
struct Object00065f20 /* derived name */
{
    /* Out of line (0x65de0): the union-find and its parents deleted, the
     * parents' storage given back at the node count's size, then the
     * records' bit fields. */
    ~Object00065f20();

    UnionFind *unionFind;       /* derived name */
    UnionFindParents *parents;  /* derived name */
    Record00065f00 records[12]; /* derived name */
    int numNodes;               /* derived name */
    int numRecords;             /* derived name: the records in use, 0x66080's count */
    bool open;                  /* derived name */
};

void FUN_00065f10(Object00065f20 *self); /* derived name */

/* Every record's bits into one field: the field sized to the first record's
 * bits and cleared, then each record's bits set in it (0x66080; the caller
 * at 0x14eb93). derived name. */
void FUN_00066080(const Object00065f20 *self, hkBitField &bitsOut);

/* An edge of the union-find's stream (derived names): two node indices and
 * the index of the range each is relative to (0x65fd0 adds the ranges'
 * starts; the join 0x65f30 reads neither), 12 bytes. */
struct UnionFindEdge /* derived name */
{
    int nodeA;
    int nodeB;
    u8 rangeA;
    u8 rangeB;
    u8 unknownA[2];
};

/* A range of nodes (derived names): its first node, 8 bytes. */
struct UnionFindRange /* derived name */
{
    int firstNode;
    u8 unknown4[4];
};

/* Every edge of a stream joined (0x65f30, called at 0x6dd17 under the
 * "StUnionFind" timer). derived name. */
void FUN_00065f30(Object00065f20 *self, const hkBlockStream *edges);
/* The same over edges whose nodes are relative to ranges (0x65fd0, called
 * at 0x14e928 for each of a list's streams): each node offset by its range's
 * first. derived name. */
void FUN_00065fd0(Object00065f20 *self, const hkBlockStream *edges,
                  const hkArray<UnionFindRange> &ranges);
void FUN_00065f20(Object00065f20 *self);                       /* derived name */
Record00065f00 *FUN_00065f00(Object00065f20 *self, int index); /* derived name */

/* The allocator over the system heap (derived name, from the shape: the
 * vtable 0x168c9f0, address point 0x168ca00, D14): one static instance at
 * 0x57b7b00, built in place with an alignment of 32 by its initializer
 * FUN_00004b30 and destroyed at exit. Slots 0 and 1 are the one empty
 * destructor 0x4ac0 (the class's delete is a no-op, so the deleting
 * destructor folded with it); slot 2 (blockAlloc, 0x4ad0) adds the size atomically to
 * the bytes in use at +0xc, raises the peak at +0x10 to it and allocates
 * with the alignment at +8; slot 3 (blockFree, 0x4af0) subtracts and frees;
 * slots 4 to 8 are AllocatorBase's defaults; slot 9 (0x4b00) reports both
 * counts widened to 64 bits; slot 10 is the shared 0x4b20 that returns the
 * request; slot 11 (FUN_00004b10) resets the peak to the current use (also
 * called directly from six places in the game region). */
class hkMallocAllocator : public AllocatorBase /* derived name */
{
  public:
    hkMallocAllocator(int alignment) : alignment(alignment), bytesInUse(0), peakInUse(0) {}

    virtual ~hkMallocAllocator();

    virtual void *blockAlloc(int numBytes);                /* slot 2, 0x4ad0 */
    virtual void blockFree(void *pointer, int numBytes);   /* slot 3, 0x4af0 */
    void FUN_00004b00(MemoryStatistics &statistics) const; /* vtable slot 9; derived name */
    void FUN_00004b10();                                   /* vtable slot 11; derived name */

    int alignment;  /* derived name */
    u32 bytesInUse; /* derived name: updated atomically by every thread */
    u32 peakInUse;  /* derived name */
};

/* A stack tracer (derived name), built on the stack by the error report at
 * 0xb680 and as the static instance at 0x57b7b80 (constructor 0xd8f0 stores
 * the vtable address point 0x168d850, destructor the empty 0xd940). On this
 * platform it has no
 * trace: collecting one (the shared FUN_000042d0) finds no frames and
 * printing one (FUN_0000d890) reports the fact through the caller's print
 * function. */
class StackTracer /* derived name */
{
  public:
    typedef void (*PrintFunction)(const char *text, void *context); /* derived name */

    StackTracer();
    virtual ~StackTracer();

    /* The class allocator's delete, inline: the object goes back to the
     * calling thread's heap at its size (the deleting destructor 0xd900,
     * slot 1, which fifteen other classes' vtables of an empty destructor
     * cite by address). */
    static void operator delete(void *object, unsigned long numBytes);

    void FUN_0000d890(const hkUlong *trace, int numTrace, PrintFunction print,
                      void *context) const; /* derived name */
};

/* An image loaded from a file (derived name): FUN_00188560 opens the file a
 * name gives, checks its extension against "tga" and returns what the
 * loader at 0x1887a0 builds, or null. */
struct LoadedImage; /* derived name */

/* The pixels the loader reads into (derived names): built on its stack
 * (0x18882d) by FUN_001a0470, the width and height at +0 and +4 (from the
 * TGA header's 16-bit fields at 0x188832) and the bytes from +8; the
 * reference-counted image 0x1a04d0 builds copies the three. */
struct RawImagePart /* derived name */
{
    /* The loader's one part: 3, a value of its own, a 16-bit value, type 0
     * and 3 (0x1889df to 0x1889f0); 0x1a0780 reads the two ints and the
     * type. derived names. */
    int value0;
    int value4;
    u16 value8;
    u8 type; /* derived name: 0 to 3, a part of 1, 2, 4 or 4 bytes (0x1a0780) */
    u8 valueB;
};

struct RawImage /* derived name */
{
    RawImage();

    int width;  /* derived name */
    int height; /* derived name */
    /* 12-byte records (the loader fills one at 0x1889df: an int 3, an
     * int, two 16-bit values), which the image copies as such (0x1a0570).
     * derived name. */
    hkArray<RawImagePart> pixels;
};

/* The image (derived name): 0x38 bytes from the thread's heap, built by
 * FUN_001a0720 over the loader's raw image; its constructor 0x1a04d0 (out
 * of line) stores the vtable 0x16a7580 and copies the raw image's width,
 * height and array into the raw image it holds at +0x20 (slot 5 hands that
 * image out whole: its implicit assignment copies the two ints as one
 * 8-byte run, clang's field memcpy, 0x1a0635). */
struct LoadedImage : public hkReferencedObject /* derived name */
{
    LoadedImage(const RawImage &raw);

    /* Out of line (0x1a0310, slot 0): the arrays freed, the parts first;
     * the deleting destructor (0x1a03a0, slot 1) runs it and frees through
     * the class's delete. */
    virtual ~LoadedImage();

    /* Slot 5 (0x1a0620): the image copied out to a raw image. derived
     * name. */
    virtual void FUN_001a0620(RawImage &rawOut) const;
    /* Slot 6, the folded 0x7f80: the storage of the array at +0x10.
     * derived name. */
    virtual const u8 *FUN_00007f80() const;

    /* The class allocator: a block of the thread's heap (0x1a073d;
     * defined beside the router). */
    static void *operator new(unsigned long numBytes);

    /* The reference-counted class delete (freeReferencedObject). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<u8> unknown10; /* empty from the constructor; elements not read */
    RawImage image;        /* derived name */
};

/* The loader's image made (0x1a0720, called at 0x1889fe). derived name. */
LoadedImage *FUN_001a0720(const RawImage &raw); /* derived name */

/* A TGA image read from a stream (0x1887a0, the file loader's at
 * 0x1885d7). derived name. */
class Object00185000;
LoadedImage *FUN_001887a0(Object00185000 &stream); /* derived name */

LoadedImage *FUN_00188560(const char *fileName); /* derived name */

/* A reference-counted source of an image (derived name; vtable address
 * point 0x16a6620, constructor FUN_00188e90, slots 5 and 6 pure), and the
 * one that names a file (derived name; vtable address point 0x16a3ab0,
 * 0x18 bytes as the copier at 0xad7c0 allocates it, destructors 0xad590 and
 * 0xad5b0): its file name (hkStringPtr) at +0x10; slot 5 is the empty
 * 0xa9140, slot 6 (FUN_000ad7b0) loads the file. */
class ImageSource : public hkReferencedObject /* derived name */
{
  public:
    ImageSource();
};

class FileImageSource : public ImageSource /* derived name */
{
  public:
    /* Over a copy of a file name (the texture's image source, 0xad7c0):
     * the string copied out of line by hkStringPtr's copy constructor
     * (0xe550). */
    FileImageSource(const hkStringPtr &name) : fileName(name) {}

    virtual ~FileImageSource();

    /* The class allocator inline, the thread heap's slot 2 called in
     * place (0xad7e9). */
    static void *operator new(unsigned long numBytes);

    /* The reference-counted class delete: its deleting destructor 0xad5b0
     * frees at the recorded size, 0x18 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    LoadedImage *FUN_000ad7b0(); /* vtable slot 6; derived name */

    hkStringPtr fileName; /* derived name */
};

/* A stream reader (derived name), the object a buffered reader reads from:
 * slot 5 tells whether it can be read (the buffered reader's 0x94580: data
 * still buffered, or its stream's answer); its slot 9 returns the stream
 * itself when it can seek and tell, else null, slot 10 seeks and slot 11
 * tells. */
class StreamReader : public hkReferencedObject /* derived name */
{
  public:
    virtual hkBool isOk() const; /* vtable slot 5; derived name */
    /* Slot 6: up to numBytes bytes read into the buffer, the count read.
     * derived name. */
    virtual int read(void *buffer, int numBytes);
    /* Slot 7 (0x8f080, the readers' shared one): numBytes skipped by
     * reading them, the count skipped. derived name. */
    virtual int skip(int numBytes);
    /* Slot 8: up to numBytes bytes copied into the buffer without being
     * consumed, the count copied (the XML reader looks ahead 32 bytes at a
     * time, 0x19db48). derived name. */
    virtual int peek(void *buffer, int numBytes);
    virtual StreamReader *unknownVirtual9();
    virtual hkResult seek(int offset, int whence); /* vtable slot 10; derived name */
    virtual int tell() const;                      /* vtable slot 11; derived name */
};

/* An input stream over a reader (derived name after its constructor, the
 * vtable's row; vtable 0x16a65d0, address point 0x16a65e0, with only the
 * reference-counted object's slots; the constructor 0x185060 opens the
 * reader of a file name through the file system at 0x57b9b70): the reader
 * at +0x10, whose reference it keeps. The image loader builds one on the
 * stack (0x18858c) and tests it with FUN_00185230 before reading; the XML
 * reader builds one over a reader (0x19dac2, 0x19e734). */
class Object00185000 : public hkReferencedObject /* derived name */
{
  public:
    /* The constructor (0x185000): a new stream over the reader, whose
     * reference it takes. */
    Object00185000(StreamReader *reader);

    /* The constructor of a file name (0x185060): the stream over the
     * reader the file system opens, buffered. */
    Object00185000(const char *name);

    /* Out of line (0x1851c0, slot 0): the reader's reference released;
     * the deleting destructor (0x185120, slot 1) frees at the recorded
     * size, 0x18 by default. */
    virtual ~Object00185000();

    /* The reference-counted class delete (below). */
    static void operator delete(void *object, unsigned long numBytes);

    hkBool FUN_00185230() const; /* derived name */

    StreamReader *reader; /* derived name */
};

/* The native file reader (derived name; vtable 0x16a3550, address point
 * 0x16a3560, no type info names it), built by FUN_00093180 over the Fios
 * handle it opens: the handle at +0xc, whether the last operation worked at
 * +0x10. Slot 10 (0x933a0) seeks the handle; slot 11 is the stream
 * writer's tell, 0x92030, the same body. */
class FiosStreamReader : public StreamReader /* derived name */
{
  public:
    /* Slot 0 (0x932c0): an open handle closed and the reader marked
     * failed. */
    virtual ~FiosStreamReader();

    /* A new reader over an opened handle, ok while the handle is valid
     * (0x931ee, inline in FUN_00093180). */
    FiosStreamReader(SceFiosFH fileHandle) : handle(fileHandle), ok(fileHandle >= 0) {}

    /* The class allocator: a block of the thread's heap (0x931eb; defined
     * beside the router). */
    static void *operator new(unsigned long numBytes);

    /* The reference-counted class delete: its deleting destructor 0x93250
     * frees at the recorded size, 0x18 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 6 (0x93300): up to the count of bytes read into the buffer from
     * an open handle; a read that brings nothing marks the reader failed.
     * derived name. */
    int FUN_00093300(void *buffer, int numBytes);
    /* Slot 8 (0x93340): the bytes read as slot 6 reads them and the handle
     * moved back over them, a peek; a read that brings nothing or a seek
     * that fails marks the reader failed. derived name. */
    int FUN_00093340(void *buffer, int numBytes);
    hkResult FUN_000933a0(int offset, int whence); /* vtable slot 10; derived name */

    SceFiosFH handle; /* derived name */
    hkBool ok;        /* derived name */
};

/* A reader of a file opened through Fios for reading, or null when the
 * open fails (0x93180; the file system's slot at 0x1bb60 hands it on).
 * derived name. */
StreamReader *FUN_00093180(const char *path);

/* The file system the library installs (derived name; vtable 0x168ea90,
 * address point 0x168eaa0, built as a bare reference-counted object by
 * FUN_000098d0 and stored in the slot at 0x57b9b70, the singleton the
 * string "hkFileSystem" names): slot 7 removes a file and slot 8 creates a
 * directory through Fios. */
class hkFileSystem : public hkReferencedObject
{
  public:
    /* Slot 5: a reader of the named file, through the flags (bit 0
     * buffered; the Fios file system's 0x1bb50). derived name. */
    virtual StreamReader *FUN_0001bb50(const char *name, int flags) = 0;
};

extern hkFileSystem *D_57b9b70; /* hkFileSystem's instance */

/* The native file reader of a file name (0x93180): the file opened, a
 * reference-counted reader over it (vtable 0x16a3550, the descriptor at
 * +0xc, whether it opened at +0x10), or null when the open fails. derived
 * name. */
StreamReader *FUN_00093180(const char *name);
/* The native file writer of a file name (0x91d50): opened through Fios
 * with the open flags in the third argument (the second is not read), a
 * reference-counted writer over the handle, or null. derived name. */
hkStreamWriter *FUN_00091d50(const char *name, int flags, u16 openFlags);

/* A directory listing's entry (derived names): the file system at +0, the
 * path (hkStringPtr) at +8, two 64-bit values from the entry's status at
 * +0x10 and +0x18, the kind at +0x20 (the listing at 0x1bc42 passes 1 or
 * 2 from bit 0 of the status). FUN_0001a700 sets them all. */
struct FileSystemEntry /* derived name */
{
    void FUN_0001a700(hkReferencedObject *fileSystem, const char *path, int flags, s64 value10,
                      s64 value18); /* derived name */

    hkReferencedObject *fileSystem;
    hkStringPtr path;
    s64 value10;
    s64 value18;
    int flags;
};

class FiosFileSystem : public hkReferencedObject /* derived name */
{
  public:
    /* Slot 5: a reader of the named file, through the flags. derived name. */
    StreamReader *FUN_0001bb50(const char *name, int flags);
    /* The reader handed back as the flags ask (0x1a7b0): with bit 0 the
     * reader is wrapped in a 0x38-byte buffered reader of 0x4000 bytes
     * (0x94170) and given up; a null reader stays null. derived name. */
    StreamReader *FUN_0001a7b0(StreamReader *reader, int flags);
    /* Slot 6 (0x1bb80): a writer of the named file, truncated when bit 1 of
     * the flags asks, handed back as the flags ask (0x1a850). derived
     * names. */
    hkStreamWriter *FUN_0001bb80(const char *name, int flags);
    hkStreamWriter *FUN_0001a850(hkStreamWriter *writer, int flags);
    hkResult FUN_0001bbc0(const char *path); /* vtable slot 7; derived name */
    hkResult FUN_0001bbe0(const char *path); /* vtable slot 8; derived name */
    /* Slot 9 (0x1bc00): the entry of a path from its status, its kind 1 or
     * 2 from bit 0 of the status flags; a failure when there is no status.
     * derived name. */
    hkResult FUN_0001bc00(const char *path, FileSystemEntry &entry);
    /* Slot 10 (0x1bc80): a listing of the directory (the current one for an
     * empty path) whose names pass the pattern, or null when it does not
     * open; the iterator's class is local to the file. derived name. */
    hkReferencedObject *FUN_0001bc80(const char *path, const char *pattern);
};

/* A reader interface whose slot 9 seeks and slot 10 tells (derived names):
 * the object of the vtable at 0x16a6400 (address point 0x16a6410; no type
 * info names it), built on the stack by FUN_00183350, implements it over
 * another at +0x10, offset by the int at +0x18: slots 5 to 8 forward to the
 * same slots of the inner reader (the folded forwarders 0xabf0, 0x89f0,
 * 0x89e0 and 0xaa530), slot 9 (FUN_00181ad0) seeks it, moving an absolute
 * position by the offset, slot 10 (FUN_00181af0) tells its position less
 * the offset, slot 11 is the shared false 0x1bad0. Slots 5 to 8 are not
 * recovered. */
class SeekableReader : public hkReferencedObject /* derived name */
{
  public:
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual int seek(int offset, int whence) = 0; /* vtable slot 9; derived name */
    virtual int tell() const = 0;                 /* vtable slot 10; derived name */
};

class OffsetSeekableReader : public SeekableReader /* derived name */
{
  public:
    int FUN_00181ad0(int offset, int whence); /* vtable slot 9; derived name */
    int FUN_00181af0() const;                 /* vtable slot 10; derived name */

    SeekableReader *reader; /* derived name */
    int start;              /* derived name */
};

/* A buffered stream reader (derived names; vtable address point 0x16a35d0,
 * constructor 0x94170, the reference-counted object's slots 2 to 4): the
 * stream at +0x10 (its reference count raised), what the stream's slot 9
 * returned at +0x18, the buffer at +0x20, the read position and the bytes in
 * the buffer at +0x28 and +0x2c, the buffer size at +0x30. Slot 9
 * (FUN_000946f0) returns the reader when the stream can seek; slot 10
 * (0x94700) empties the buffer and seeks the stream, slot 11 (0x94720) tells
 * the stream's position less what is still buffered; slot 5 (0x94580) is
 * readable while bytes are buffered, else asks the stream. */
class BufferedStreamReader : public StreamReader /* derived name */
{
  public:
    /* Out of line (0x94170): a reader over the stream, its reference
     * taken, with a buffer of bufferSize bytes from the thread's heap. */
    BufferedStreamReader(StreamReader *stream, int bufferSize);

    /* The class allocator, inline: the thread's heap (the file system's
     * 0x1a7e6). */
    static void *operator new(unsigned long numBytes);

    /* The reference-counted class delete: its deleting destructor 0x94230
     * frees at the recorded size, 0x38 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    /* Out of line (0x942e0, slot 0): the stream's reference released and
     * the buffer given back to the thread's heap. */
    virtual ~BufferedStreamReader();

    hkBool isOk() const; /* vtable slot 5; derived name */
    /* Slot 6 (0x94360): what is buffered copied out first; while more is
     * asked, the buffer emptied and filled again from the stream, the
     * count read so far returned once the stream gives nothing; then the
     * rest from the buffer. */
    int read(void *buffer, int numBytes);
    /* Slot 7 (0x94490): what is buffered skipped first; past it the
     * buffer emptied, a 512th of the rest skipped in the stream and the
     * buffer filled again, then as much as it holds of what is left; the
     * count skipped. derived name. */
    int FUN_00094490(int numBytes);
    BufferedStreamReader *FUN_000946f0();          /* vtable slot 9; derived name */
    hkResult FUN_00094700(int offset, int whence); /* vtable slot 10; derived name */
    int FUN_00094720() const;                      /* vtable slot 11; derived name */

    StreamReader *stream;         /* derived name */
    StreamReader *seekableStream; /* derived name */
    char *buffer;                 /* derived name */
    int position;                 /* derived name */
    int numBuffered;              /* derived name */
    int bufferSize;               /* derived name */
};

/* A job queue (derived names): its constructor 0x56c0 sets the pop and
 * finish functions at +0x18 and +0x20 to the dispatchers FUN_00005680 and
 * FUN_000056a0, and gives each job type in use (the count at +0x28) an
 * entry of 32 bytes from +0x130 whose pop and finish functions default to
 * 0x42d0 (returns 0) and 0x58a0 (returns 1). The queue calls the pop
 * function with a job and an output job (0x5155, the result compared with
 * 1) and the finish function with the data at +0x10, a job and an output
 * (0x62a0). A job's type is its byte at +1. */
struct hkJobQueueJob /* derived name */
{
    u8 jobSubType; /* derived name */
    u8 jobType;    /* derived name */
};

struct hkJobQueue /* derived name */
{
    typedef int (*JobPopFunc)(hkJobQueue &queue, void *data, hkJobQueueJob &jobIn,
                              hkJobQueueJob &jobOut); /* derived name */
    typedef int (*FinishJobFunc)(hkJobQueue &queue, void *data, const hkJobQueueJob &jobIn,
                                 void *newJobOut); /* derived name */

    struct CustomJobType /* derived name */
    {
        u64 unknown0;
        u32 unknown8;
        JobPopFunc popJobFunc;       /* derived name */
        FinishJobFunc finishJobFunc; /* derived name */
    };

    /* A queued job (derived name): 256 bytes, the queues' element (0x50f1
     * scales the head by 256 and copies 0xf8 bytes out). */
    struct JobQueueEntry /* derived name */
    {
        u8 unknown0[0x100];
    };

    /* The shared state (derived name), 0x220 bytes from the heap
     * (0x577a): a 16-bit count per job type from +0 (each cleared by the
     * constructor, 0x57fa), a mask of the job types in use at +0x20 (one
     * bit set per type, 0x5812), from +0x2a the number of threads waiting
     * on each semaphore, from +0x38 the job queues, each a ring of
     * entries. */
    struct DynamicData /* derived name */
    {
        s16 unknown0[16];
        u32 jobTypesMask; /* derived name */
        int unknown24;
        hkBool unknown28;
        s16 numThreadsWaiting[7];             /* derived name */
        hkQueue<JobQueueEntry> jobQueues[20]; /* derived name */
        u8 unknown218[8];
    };

    /* derived name: when a job is queued and a thread waits for one,
     * wake one waiting thread: the first of the CPU queues from +0x50 to
     * +0x54 that holds a job and has a waiting thread; else, if any queue
     * holds a job, the first waiting thread from the first CPU queue on. */
    void FUN_00006480(DynamicData *data); /* derived name */

    u8 unknown0[0x10];
    DynamicData *data;           /* derived name */
    JobPopFunc popJobFunc;       /* derived name */
    FinishJobFunc finishJobFunc; /* derived name */
    u8 unknown28[0x10];
    int numJobQueues; /* derived name */
    u8 unknown3c[0x14];
    int cpuQueuesBegin; /* derived name */
    int cpuQueuesEnd;   /* derived name */
    u8 unknown58[0x30];
    hkSemaphore *waitingThreadSemaphores[5]; /* derived name */
    int numWaitingThreadSemaphores;          /* derived name */
    u8 unknownb4[0x7c];
    CustomJobType customJobs[15]; /* derived name */
};

int FUN_00005680(hkJobQueue &queue, void *data, hkJobQueueJob &jobIn,
                 hkJobQueueJob &jobOut); /* derived name */
int FUN_000056a0(hkJobQueue &queue, void *data, const hkJobQueueJob &jobIn,
                 void *newJobOut); /* derived name */

/* An allocator (derived name; vtable 0x168da00, address point 0x168da10,
 * no type info) built by its constructor 0xed40 at +0 of the router, whose
 * constructor 0xbb60 then clears +0x50 to +0x78: slots 0 and
 * 1 the shared 0x4ac0, 2 to 6 its own (0xef00, 0xef70, 0xef40, 0xef70,
 * 0xefd0), 7 to 12 the defaults. The pointer at +8 starts null. */
class Allocator0000ed40 : public AllocatorBase /* derived name */
{
  public:
    Allocator0000ed40();

    /* Slot 2 (0xef00): a block cut from the current slab, the size rounded
     * up to 16, while the slab has room; otherwise FUN_0000f090 finds one
     * (the same fast path is inlined at 0x41390). */
    virtual void *blockAlloc(int numBytes);

    /* Slot 4 (0xef40): the requested size rounded up to 16 in place, then
     * the same fast path. */
    /* Slot 3 (0xef70; slot 5 holds the same body): a block at the top of
     * the current slab, and not its first, popped in place; any other
     * through the slow path at its rounded size. */
    virtual void blockFree(void *pointer, int numBytes);

    virtual void *FUN_00008d70(int &numBytes);

    /* Slot 6 (0xefd0): both sizes rounded up to 16; the top block of the
     * slab grown or shrunk in place when the new size still fits, any
     * other moved to a new block and the old one freed. */
    virtual void *FUN_00008d90(void *pointer, int oldNumBytes, int &numBytesInOut);

    /* The slow path (0xf090): a request larger than a slab goes to the
     * allocator at +0x40, the rest to a new slab. derived name. */
    void *FUN_0000f090(int numBytes);

    /* The free's slow path (0xf460, called directly by 130 sites; slot 3
     * inlines it): a block larger than a slab goes back to the allocator at
     * +0x40, one count fewer kept outside; a block that ends at the current
     * top becomes the top, and FUN_0000f1e0 takes the freed blocks below it
     * off too; any other is recorded by FUN_0000f2f0. derived names. */
    void FUN_0000f460(void *pointer, int numBytes);
    /* After the top moved down (0xf1e0, tail-called by 0xef70 and 0xf460):
     * the blocks freed out of order that end at the top popped, the top
     * moving down to each one's start; the slabs above the top given up
     * but the last, the latest kept at +0x30 and the one kept before it
     * freed; then the end and the first freed block's end set again.
     * derived name. */
    void FUN_0000f1e0();
    void FUN_0000f2f0(void *pointer, int numBytes);

    /* Taken down (0xee00; a thread router's taking down passes null): the
     * current and the spare slab given back, what it keeps beside them
     * emptied and freed, all through the internal allocator; the three
     * allocators handed out when asked for. derived name. */
    void FUN_0000ee00(AllocatorBase **allocatorsOut);

    /* Set up over its three allocators (0xed60; the thread's router setup
     * 0xc590 calls it): what it keeps beside its slabs from the internal
     * allocator, no slab yet. derived name. */
    void FUN_0000ed60(AllocatorBase *newSlabAllocator, AllocatorBase *newLargeAllocator,
                      AllocatorBase *newInternalAllocator, int newSlabSize);

    /* What the allocator keeps beside its slabs (derived names): the blocks
     * freed out of order at +0 (24 bytes each, 0xf1e0 walks them), a second
     * array at +0x10, the count of blocks the allocator at +0x40 holds at
     * +0x20; built empty in a block of the internal allocator (0xed88). */
    struct Impl {
        /* A block freed out of order: its start and its end (0xf1e0 pops
         * the ones that end at the top). derived names. */
        struct FreeBlock {
            char *start;
            char *end;
            u8 unknown10[8];
        };

        Impl() : numExternalAllocations(0) {}

        static void *operator new(unsigned long, void *where)
        {
            return where;
        }

        hkArray<FreeBlock> freeBlocks;
        hkArray<void *> array10;
        int numExternalAllocations;
    };

    Impl *pointer8; /* derived name */
    int slabSize;   /* derived name */
    char *cur;      /* derived name */
    char *end;      /* derived name */
    /* The current slab's start (0xf175 sets it with a new slab); the free's
     * fast path never pops the block there. derived name. */
    char *slabStart;
    char *pointer30;                  /* derived name */
    AllocatorBase *slabAllocator;     /* derived name */
    AllocatorBase *largeAllocator;    /* derived name */
    AllocatorBase *internalAllocator; /* derived name */
};

/* The thread's memory router (derived name): FUN_0000bb40 makes the router
 * the thread's (the %fs-relative slot at 0x16d80b8 the allocators read);
 * FUN_014aff00, in the game region, then gives the thread a 0x28-byte block
 * from the router's heap at +0x60, kept in the slot at 0x16d80d0. */
struct hkMemoryRouter /* derived name */
{
    /* The constructor (0xbb60; the memory system's 0xc2d0, the worker
     * context's 0x8f591 and the game at 0xe993ca build one): the stack
     * allocator built, the four allocators and the fields after them
     * cleared. */
    hkMemoryRouter();

    /* Built first by the router's constructor (0xbb69); its destructor,
     * AllocatorBase's, is the router's (the tail jump at 0x8f62d). */
    Allocator0000ed40 stack; /* derived name */
    /* The allocator the adaptor of vtable 0x168d430 forwards to (0xac60).
     * derived name. */
    AllocatorBase *allocator50;
    /* The temporary allocator (FUN_0000c590 sets it), also the heap
     * FUN_0000bcf0 frees through and the adaptor of vtable 0x168d530
     * forwards to (0xaf80). */
    AllocatorBase *temp58; /* derived name */
    /* The allocator the adaptor of vtable 0x168d4b0 forwards to (0xadf0).
     * derived name. */
    AllocatorBase *allocator60;
    void *pointer68; /* derived name */
    /* The router's place in the memory system's thread records (0xc827).
     * derived name. */
    int threadIndex;
    u8 unknown74[4];
    int int78; /* derived name */
};

/* The memory system's interface, Havok's abstract hkMemorySystem: the
 * instance the global at 0x57b7ba0 holds is reached through it. No vtable
 * of its own is stored (the derived constructor's store overwrites it), so
 * it has no row. The slots are the derived vtable's 2 to 17. */
class hkMemorySystem
{
  public:
    /* Out of line and empty (0x6c80, hkMemorySystem.cpp). */
    virtual ~hkMemorySystem();

    /* Its delete frees nothing: the system lives in storage its setup gives
     * it (FUN_00001140), so the free-list system's deleting destructor
     * 0xc350 is a jump to the complete one. */
    static void operator delete(void *, unsigned long) {}

    /* Slot 2 (0xc490): set up with the sizes, under the flags (the setup
     * passes 3); the main thread's router back. derived name. */
    virtual hkMemoryRouter *FUN_0000c490(const SizePair00006c30 &sizes, int flags) = 0;
    /* Slot 3 (0xc510): the buffer given back to the base allocator, then
     * the main router taken down and the allocator interface collected;
     * the base allocator forgotten (the quit at 0x17ab0 passes 3). */
    virtual hkResult mainQuit(int flags) = 0;
    virtual void threadInit(hkMemoryRouter &router, const char *name,
                            int flags) = 0; /* derived name */
    /* Slot 5 (0xc810): the thread's router taken down by the flags: its
     * stack allocator and temporary allocator (2), then its record and
     * the router itself (1). */
    virtual void threadQuit(hkMemoryRouter &router, int flags) = 0; /* derived name */
    virtual void unknownVirtual6() = 0;
    virtual void unknownVirtual7() = 0;
    virtual void unknownVirtual8() = 0;
    virtual void unknownVirtual9() = 0;
    virtual void unknownVirtual10() = 0;
    virtual void unknownVirtual11() = 0;
    virtual void unknownVirtual12() = 0;
    /* Slots 13 and 14 (0xd080 and 0xd0a0): the collection of a thread's
     * router and of what the threads share; slot 15 (0x6cb0), the
     * interface's own, runs the calling thread's, then the shared one.
     * derived names. */
    virtual void garbageCollectThread(hkMemoryRouter &router) = 0;
    virtual void garbageCollectShared() = 0;
    virtual void garbageCollect();
    virtual void unknownVirtual16() = 0;
    /* Slot 17: the debug interface, null here (the shared 0x42d0); the
     * monitor stream's reset asks for it (0xecb6). derived name. */
    virtual void *getDebugInterface() = 0;
};

/* The free-list memory system (D14's row for vtable 0x168d680, stored by
 * the constructor 0xc270 and the complete destructor 0xc360): its slot 4
 * (0xc590) loads the path of hkFreeListMemorySystem.cpp
 * (config/homes.base.txt). The base allocator at +8 (the constructor's
 * first argument), the sizes slot 2 was set up with at +0x10, the
 * allocator and its interface at +0x18 and +0x20, a block-list allocator
 * over the base allocator at +0x28, the main thread's router at +0x80, the
 * buffer allocator at +0x100, one record per thread from +0x550, a
 * critical section at +0x6f50 and the flags at +0x6f60. */
class hkFreeListMemorySystem : public hkMemorySystem
{
  public:
    /* Out of line (0xc270): the members built in order, the sizes (0,
     * 32768), each thread's record, the critical section with no spin. */
    hkFreeListMemorySystem(AllocatorBase *base, AllocatorBase *allocator,
                           AllocatorInterface *allocatorInterface, int flags);
    virtual ~hkFreeListMemorySystem();
    virtual hkMemoryRouter *FUN_0000c490(const SizePair00006c30 &sizes, int flags);
    virtual hkResult mainQuit(int flags);
    virtual void threadInit(hkMemoryRouter &router, const char *name, int flags); /* derived name */
    virtual void threadQuit(hkMemoryRouter &router, int flags);                   /* derived name */
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual void unknownVirtual9();
    virtual void unknownVirtual10();
    virtual void unknownVirtual11();
    virtual void unknownVirtual12();
    virtual void garbageCollectThread(hkMemoryRouter &router);
    virtual void garbageCollectShared();
    virtual void unknownVirtual16();
    virtual void *getDebugInterface();

    /* The flags' bits (derived names): the main thread's router (1), the
     * buffer allocator's buffer (2). */
    enum { FLAG_ROUTER = 1, FLAG_TEMPORARY = 2 };

    AllocatorBase *baseAllocator; /* derived name */
    SizePair00006c30 frameInfo;   /* derived name */
    /* Slot 12 (0xd2b0) returns it. derived name. */
    AllocatorBase *allocator18;
    /* Slots 6 to 9, 14 and 20 (0xd230 to 0xd2c0) forward to it, when
     * there is one. derived name. */
    AllocatorInterface *extended20;
    BlockListAllocator blockListAllocator; /* derived name */
    hkMemoryRouter mainRouter;             /* derived name */
    /* The buffer allocator at +0x100 (slot 8, FUN_0000d270, asks it). */
    BufferAllocator bufferAllocator; /* derived name */

    /* One record per thread router (derived names): the thread's allocator,
     * then two pointers and the record's in-use flag, which taking the
     * router down clears (0xc870, 0xc87c); the constructor clears the
     * second pointer and the flag (0xc308, 0xc313). */
    struct ThreadData {
        ThreadData() : pointer198(0), inUse(false) {}

        ThreadMemory memory;
        void *pointer190;
        void *pointer198;
        bool inUse;
    };

    ThreadData threads[64]; /* derived name */
    hkCriticalSection lock; /* derived name */
    /* Set by the constructor from its fifth argument; bit 2 gives each
     * thread its own allocator (FUN_0000c590). */
    s32 flags; /* derived name */
};

/* The thread's router, a thread-local pointer: the TLS segment's template
 * is at 0x16dc060 (0x70 bytes, 4 of them initialised, alignment 8), and the
 * GOT slot 0x16d80b8 holds this object's offset from the thread pointer,
 * -0x60, which places it at +0x10 of the template. Every reader adds that
 * slot to %fs:0. */
extern __thread hkMemoryRouter *D_16dc070;

/* A string the thread's heap holds freed, inline: the string handed in
 * first, the heap read inside (the patch manager's index frees its names
 * so, the value's call at 0x19a0d6 before the router's read). derived
 * name. */
inline void freeHeapString(char *string) /* derived name */
{
    FUN_0000bc80(*D_16dc070->temp58, string);
}

/* The runtime given back to the thread's heap at its recorded size when
 * there is one (a pointer of 0 or 1 holds none: `cmp 2; jb`, 0x700e1), then
 * the data's reference released (the member's destructor). */
inline hknpConstraint::~hknpConstraint()
{
    if (reinterpret_cast<hkUlong>(runtime) > 1) {
        D_16dc070->temp58->blockFree(runtime, runtimeSize);
    }
}

/* The thread's 0x28-byte block (derived name): FUN_014aff00 allocates it
 * from the router's heap at +0x60 and clears it; the GOT slot 0x16d80d0
 * holds its thread-local pointer's offset, -0x58, +0x18 of the TLS
 * template. FUN_0000ead0 gives back the buffer it records (+0 to +0x10,
 * owned when the byte at +0x20 is set), reading the pointer itself; its
 * argument is the block. */
struct ThreadBuffer /* derived name */
{
    /* A value command (derived names): the "Mf" marker and its text, and
     * the value, 16 bytes in the stream. */
    struct AddValueCommand {
        const char *commandAndMonitor;
        float value;
    };

    /* The timer commands (derived names): the marker and its name, the low
     * half of the time-stamp counter, 16 bytes in the stream; a list's
     * begin adds the name of its first split, 24 bytes. */
    struct TimerCommand {
        const char *commandAndMonitor;
        u32 time0;
    };

    struct TimerBeginListCommand : public TimerCommand {
        const char *nameOfFirstSplit;
    };

    /* A timer list begun (an "Lt" name and its first "St" split) and ended
     * (the "lt" marker) when the stream has room, the time read last (the
     * world's tasks, 0x48670 and 0x487c0, time their step this way, the
     * stream read once for both). derived names. */
    /* The time-stamp counter's low word, read through inline assembly as
     * the library's monitor does (docs/DECISIONS.md D34: the base keeps
     * each path's rdtsc where a tail merge would have joined the machine
     * instruction, 3.3 BranchFolding.cpp:340-346; the asm emits the read,
     * nothing else). derived name. */
    static u32 readTimeStampCounter()
    {
        unsigned int low;
        unsigned int high;
        __asm__ __volatile__("rdtsc" : "=a"(low), "=d"(high));
        return low;
    }

    void timerBeginList(const char *name, const char *firstSplit)
    {
        if (end < capacityMinus16) {
            TimerBeginListCommand *command = reinterpret_cast<TimerBeginListCommand *>(end);
            command->commandAndMonitor = name;
            command->nameOfFirstSplit = firstSplit;
            command->time0 = readTimeStampCounter();
            end = reinterpret_cast<char *>(command + 1);
        }
    }

    /* One timer begun ("Tt" and its name) and ended (the "Et" marker), as
     * the world's ray cast times itself (0x35d40). derived names. */
    void timerBegin(const char *name)
    {
        if (end < capacityMinus16) {
            TimerCommand *command = reinterpret_cast<TimerCommand *>(end);
            command->commandAndMonitor = name;
            command->time0 = readTimeStampCounter();
            end = reinterpret_cast<char *>(command + 1);
        }
    }

    void timerEnd(const char *name)
    {
        if (end < capacityMinus16) {
            TimerCommand *command = reinterpret_cast<TimerCommand *>(end);
            command->commandAndMonitor = name;
            command->time0 = readTimeStampCounter();
            end = reinterpret_cast<char *>(command + 1);
        }
    }

    void timerEndList(const char *name)
    {
        if (end < capacityMinus16) {
            TimerCommand *command = reinterpret_cast<TimerCommand *>(end);
            command->commandAndMonitor = name;
            command->time0 = readTimeStampCounter();
            end = reinterpret_cast<char *>(command + 1);
        }
    }

    /* The stream given a buffer of a size (0xeb90; a pool's worker sizes
     * its thread's stream with it, 0x7201). derived name. */
    void FUN_0000eb90(int size);

    /* The stream emptied; under a debug memory system the warning value
     * written into the calling thread's stream (0xeca0, called by 0x72fc).
     * derived name. */
    void FUN_0000eca0();

    char *start;                     /* derived name */
    char *end;                       /* derived name */
    char *capacity;                  /* derived name */
    char *capacityMinus16;           /* derived name: the last position a command fits */
    bool isBufferAllocatedOnTheHeap; /* derived name */
};

extern __thread ThreadBuffer *D_16dc078;

/* A timer kept by its owner between steps and written to the stream whole
 * under a new name (0x17aeb0 copies 20 bytes, the record's data size: the
 * value at +0x10 after the two counters). derived names. */
/* A marker: the name alone, 8 bytes in the stream. derived name. */
struct TimerMarker /* derived name */
{
    const char *commandAndMonitor;
};

struct TimerRecordBase /* derived name */
{
    const char *commandAndMonitor;
    u32 time0;
    u32 time1;
};

struct TimerRecord : public TimerRecordBase /* derived name */
{
    u32 value;
};

/* An owner of step timers (derived name): two records at +0xa8 and +0xc0,
 * the second written only when its value is set, two groups at +0xd8 and
 * +0x268 that write their own (FUN_0017a970, FUN_0017abe0), and the flag at
 * +0x410 that turns the writing on; FUN_0017a3c0 writes the owner's first
 * commands. Its writer is called by 0x15c5f0 (0x15d77d). */
struct StepTimers /* derived name */
{
    /* 0x17aeb0. derived name. */
    void FUN_0017aeb0(ThreadBuffer &stream);

    u8 unknown0[0xa8];
    TimerRecord timerA8; /* derived name */
    TimerRecord timerC0; /* derived name */
    u8 groupD8[0x190];   /* derived name */
    u8 group268[0x1a8];  /* derived name */
    bool enabled;        /* derived name */
};

void FUN_0017a3c0(StepTimers *self, ThreadBuffer &stream); /* derived name */
void FUN_0017a970(void *group, ThreadBuffer &stream);      /* derived name */
void FUN_0017abe0(void *group, ThreadBuffer &stream);      /* derived name */
void FUN_0000ead0(ThreadBuffer *buffer);                   /* derived name */

inline void *hkMultipleVertexBuffer::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkReferencedObjectLock::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *FileImageSource::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkHardwareInfo::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hknpGlobals::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkTypeInfoRegistry::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkVtableClassRegistry::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkBuiltinTypeRegistry::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hknpVehicleDriverInputAnalogStatus::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *BufferedStreamReader::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkBufferedStreamWriter::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *LoadedImage::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *FiosStreamReader::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkCriticalSection::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkDebugDisplay::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkProcessFactory::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hkUuidPseudoRandomGenerator::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *hknpShapeKeyMask::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *BroadPhaseTasks0018d640::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

template <typename T> inline void *hkQueue<T>::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void hknpShapeKeyMask::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
}

inline void BlockCache::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
}

inline void Object00015700::Block::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
    }
}

inline void UnionFindParents::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
}

inline void UnionFind::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
}

inline void hknpCompoundShapeInternalsKeyMask::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

inline void hkcdStaticTree::DefaultTreeStorage6::operator delete(void *object,
                                                                 unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

inline void hkcdDynamicTree::DefaultTree48Storage::operator delete(void *object,
                                                                   unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

inline void *hkSlot::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(int(numBytes));
}

inline void hkSlot::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

inline void StackTracer::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

inline void hknpCollisionQueryCollector::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

inline void hknpWorldObject1d0Small::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

inline void QueryProcessor0010b090::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

/* The class allocator's delete of the reference-counted classes (derived
 * name): the object goes back to the thread's heap at the size its
 * allocation recorded in the top 16 bits of memSizeAndRefCount, or at the
 * class's own size when none was recorded (0xffff). It has no null test:
 * the deleting destructors that inline it free unconditionally (one body per
 * class size, folded by the linker: 0x4060 for 16 bytes, 0xd990 for 32,
 * cited by every vtable of an empty destructor of that size). */
inline void freeReferencedObject(void *object, unsigned long numBytes) /* derived name */
{
    const u32 memSize = static_cast<hkReferencedObject *>(object)->memSizeAndRefCount >> 16;
    D_16dc070->temp58->blockFree(object, memSize == 0xffff ? int(numBytes) : int(memSize));
}

inline void hkCriticalSection::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

inline void hkDebugDisplay::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkProcessFactory::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkMemoryResourceHandle::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void *hkpWrappedConstraintData::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void hkpWrappedConstraintData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkUuidObject::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void Object00185000::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkReferencedObjectLock::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxBlob::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void RefArrays0005a230::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkPlatformObjectWriter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void Object0019a7c0::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void *hknpExternMeshShapeData::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void hknpExternMeshShapeData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxVertexBuffer::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void Object0000b330::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpShape::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpCompoundShape::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void LoadedImage::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkXmlParser::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkMonitorStreamColorTable::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxEnum::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxMaterialEffect::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxMaterialShaderSet::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxNodeSelectionSet::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void *Object0019a230::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void *ClassVersionIndex0019a0b0::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void Object0019a230::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkBufferedStreamWriter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void ClassVersionIndex0019a0b0::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

inline void hknpPairCollisionFilter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpVehicleData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpMaterialPalette::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

/* The map's own destructor, out of line and empty: defined in the pair
 * filter's file, where the filter's destructor holds it (0x1671f0), and
 * called by the constraint filter's (0x159c7b), where the linker folded it
 * onto the shared empty body 0x158a30 (as 0xe5c0 for the pointer maps). */
void FUN_00158a30(hknpPairCollisionFilterMapPairFilterKeyOverrideType *self); /* derived name */

inline hknpPairCollisionFilterMapPairFilterKeyOverrideType::
    ~hknpPairCollisionFilterMapPairFilterKeyOverrideType()
{
    FUN_00167170(hkContainerHeapAllocator::get());
    FUN_00158a30(this);
}

inline void hkMemoryMeshTexture::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkMemoryMeshMaterial::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxEnvironment::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkMemoryMeshVertexBuffer::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxAnimatedVector::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxTriangleSelectionChannel::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxVertexVectorDataChannel::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxVertexFloatDataChannel::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxVertexIntDataChannel::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxAnimatedQuaternion::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxEdgeSelectionChannel::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxAnimatedMatrix::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxAnimatedFloat::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxVertexSelectionChannel::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdPlanarGeometryPolygonCollection::operator delete(void *object,
                                                                 unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdStaticAabbTree::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdDynamicAabbTree::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxSpline::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpTyremarksWheel::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpDynamicCompoundShapeData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxBlobMeshShape::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpMotionPropertiesLibrary::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxMesh::UserChannelInfo::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxTextureFile::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxMaterialShader::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdPlanarGeometryVertexStorage::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkVtableClassRegistry::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkBuiltinTypeRegistry::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkpLimitedHingeConstraintData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkpPointToPathConstraintData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkpPrismaticConstraintData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkpLinearClearanceConstraintData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkTypeInfoRegistry::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void *hkDynamicClassNameRegistry::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void FiosStreamReader::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void BufferedStreamReader::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkDynamicClassNameRegistry::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkAlignSceneToNodeOptions::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void *hkXmlParser::Node::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void XmlStartElement::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void XmlEndElement::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void XmlCharacters::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void FileImageSource::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpBodyQualityLibrary::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpRefMaterial::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpGlobals::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxTextureInplace::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkRefCountedProperties::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
}

inline void BufferOstream::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkOstream::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkOArchive::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdPlanarEntity::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpDefaultExternMeshShapeGeometry::operator delete(void *object,
                                                                unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkUuidPseudoRandomGenerator::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkLocalFrameGroup::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkStringObject::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpRefWorldCinfo::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpPrepareNewPairsTask::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpSolverFactoryTask::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpVehicleSuspension::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpVehicleDefaultBrake::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpStaticCompoundShapeData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpVehicleDefaultSteering::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkBlockStreamCommandWriter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void Crc32StreamWriter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkArrayStreamWriter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpPhysicsSceneData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdPlanarGeometryPlanesCollection::operator delete(void *object,
                                                                unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdPlanarGeometryPlanesCollection::Cache::operator delete(void *object,
                                                                       unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, static_cast<int>(numBytes));
}

inline void *hkArrayStreamWriter::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline hkArrayStreamWriter::hkArrayStreamWriter(hkArray<char> *array_, ArrayOwnership ownership_)
    : array(array_), allocator(&hkContainerHeapAllocator::get()), offset(array_->getSize()),
      ownership(ownership_)
{
    array->reserve(*allocator, array->getSize() + 1);
    array->data[array->getSize()] = 0;
}

inline void hknpCharacterRigidBodyCinfo::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpGroupCollisionFilter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkpVehicleFrictionDescription::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkpConstraintData::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void *hkpConstraintMotor::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void hkpConstraintMotor::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxCamera::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpVehicleDefaultEngine::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpTyremarksInfo::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline hknpTyremarksInfo::~hknpTyremarksInfo()
{
    for (int i = 0; i < tyremarksWheel.getSize(); i++) {
        tyremarksWheel[i]->releaseReference();
    }
}

inline void hknpCharacterProxyCinfo::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void *Object000ea540::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
}

inline void Object000ea540::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

/* Three allocators that hold nothing of their own and hand every request to
 * one of the calling thread's router allocators (vtables 0x168d430,
 * 0x168d4b0 and 0x168d530, address points 0x10 further; slots 0 and 1 the
 * shared 0x4ac0 and 0xac10, 2 to 6 and 9 and 10 each class's own, 7 and 8
 * the defaults 0x8e00 and 0x8e50). Slot 2 is the allocation. derived
 * names. */
class RouterAllocator50 : public AllocatorBase /* derived name */
{
  public:
    /* Empty; the deleting destructor 0xac10, beside this class's slots, is
     * the body all three vtables cite (D15). */
    virtual ~RouterAllocator50();

    /* The class allocator's delete: back to the thread's heap at the
     * class's size, nothing for null (inline in 0xac10). */
    static void operator delete(void *object, unsigned long numBytes);

    virtual void *blockAlloc(int numBytes);                 /* 0xac60 */
    virtual void blockFree(void *pointer, int numBytes);    /* slot 3, 0xac90 */
    virtual void *FUN_00008d70(int &numBytes);              /* slot 4, 0xacd0 */
    virtual void FUN_00008d80(void *pointer, int numBytes); /* slot 5, 0xad00 */
    virtual void *FUN_00008d90(void *pointer, int oldNumBytes,
                               int &numBytesInOut);                        /* slot 6, 0xad40 */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;  /* slot 9, 0xad80 */
    virtual int getAllocatedSize(const void *pointer, int numBytes) const; /* slot 10, 0xadb0 */
};

class RouterAllocator60 : public AllocatorBase /* derived name */
{
  public:
    virtual void *blockAlloc(int numBytes);                 /* 0xadf0 */
    virtual void blockFree(void *pointer, int numBytes);    /* slot 3, 0xae20 */
    virtual void *FUN_00008d70(int &numBytes);              /* slot 4, 0xae60 */
    virtual void FUN_00008d80(void *pointer, int numBytes); /* slot 5, 0xae90 */
    virtual void *FUN_00008d90(void *pointer, int oldNumBytes,
                               int &numBytesInOut);                        /* slot 6, 0xaed0 */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;  /* slot 9, 0xaf10 */
    virtual int getAllocatedSize(const void *pointer, int numBytes) const; /* slot 10, 0xaf40 */
};

class RouterAllocator58 : public AllocatorBase /* derived name */
{
  public:
    virtual void *blockAlloc(int numBytes);                 /* 0xaf80 */
    virtual void blockFree(void *pointer, int numBytes);    /* slot 3, 0xafb0 */
    virtual void *FUN_00008d70(int &numBytes);              /* slot 4, 0xaff0 */
    virtual void FUN_00008d80(void *pointer, int numBytes); /* slot 5, 0xb020 */
    virtual void *FUN_00008d90(void *pointer, int oldNumBytes,
                               int &numBytesInOut);                        /* slot 6, 0xb060 */
    virtual void getMemoryStatistics(MemoryStatistics &statistics) const;  /* slot 9, 0xb0a0 */
    virtual int getAllocatedSize(const void *pointer, int numBytes) const; /* slot 10, 0xb0d0 */
};

/* The three, static objects built by one initializer (0xb120) and
 * destroyed at exit; the third is the allocator the containers use, an
 * object, not a pointer, reached by address from 1,621 sites. derived
 * names. */
extern RouterAllocator50 D_57b8470;
extern RouterAllocator60 D_57b8478;
extern RouterAllocator58 D_57b8480;

inline AllocatorBase &hkContainerHeapAllocator::get()
{
    return D_57b8480;
}

inline AllocatorBase &hkContainerTempAllocator::get()
{
    return D_57b8470;
}

inline hkStringBuf::~hkStringBuf()
{
    string.clearAndDeallocate(hkContainerTempAllocator::get());
}

/* An array over the temporary allocator with its first N elements in place
 * (derived name; Havok's hkInplaceArray over hkContainerTempAllocator): the
 * storage it grew to given back to that allocator when it goes. */
template <typename T, int N> struct TempInplaceArray : public hkArray<T> /* derived name */ {
    TempInplaceArray() : hkArray<T>(storage, 0, N) {}

    ~TempInplaceArray()
    {
        this->size = 0;
        if ((this->capacityAndFlags & hkArray<T>::DONT_DEALLOCATE_FLAG) == 0) {
            hkContainerTempAllocator::get().template freeElements<T>(this->data,
                                                                     this->getCapacity());
        }
        this->data = 0;
        this->capacityAndFlags = hkArray<T>::DONT_DEALLOCATE_FLAG;
    }

    T storage[N];
};

/* The same without storage in place (derived name), sized at construction
 * through the temporary allocator's slot 4, which may round the size up. */
template <typename T> struct TempArray : public hkArray<T> /* derived name */ {
    TempArray() {}

    explicit TempArray(int n)
    {
        int numBytes = n * int(sizeof(T));
        int capacity = 0;
        this->data = 0;
        if (n != 0) {
            this->data = static_cast<T *>(hkContainerTempAllocator::get().FUN_00008d70(numBytes));
            capacity = numBytes / int(sizeof(T));
        }
        this->size = n;
        this->capacityAndFlags = capacity ? capacity : hkArray<T>::DONT_DEALLOCATE_FLAG;
    }

    ~TempArray()
    {
        this->size = 0;
        if ((this->capacityAndFlags & hkArray<T>::DONT_DEALLOCATE_FLAG) == 0) {
            hkContainerTempAllocator::get().template freeElements<T>(this->data,
                                                                     this->getCapacity());
        }
        this->data = 0;
        this->capacityAndFlags = hkArray<T>::DONT_DEALLOCATE_FLAG;
    }
};

/* A block of the thread's stack allocator, rounded up to 128 bytes
 * (derived names; Havok's hkLocalBuffer and hkLocalArray): the fast paths of
 * Allocator0000ed40's slots 2 and 3 inline, a block that does not fit in
 * the slab or is not the top one through FUN_0000f090 and FUN_0000f460. */
inline void *stackBlockAlloc(int numBytes) /* derived name */
{
    Allocator0000ed40 &stack = D_16dc070->stack;
    if (numBytes <= stack.slabSize) {
        char *block = stack.cur;
        char *blockEnd = block + numBytes;
        if (blockEnd <= stack.end) {
            stack.cur = blockEnd;
            return block;
        }
    }
    return stack.FUN_0000f090(numBytes);
}

/* Room for n elements from the thread's stack allocator, the size rounded
 * up to 128 bytes once the allocator is at hand (0x13e2b0 reads the thread's
 * router before it scales the count). The block's end is computed before
 * the slab test: MachineSink sinks the top's load into the second test's
 * block, and the size's extension stays in the entry, where the free's test
 * reuses it (0x1a1d60: `movsxd r13, r15d` before `cmp r13d, [slab]`).
 * derived name. */
template <typename T> inline T *stackAllocate(int n) /* derived name */
{
    Allocator0000ed40 &stack = D_16dc070->stack;
    const int numBytes = (n * int(sizeof(T)) + 127) & ~127;
    char *block = stack.cur;
    char *blockEnd = block + numBytes;
    if (numBytes <= stack.slabSize && blockEnd <= stack.end) {
        stack.cur = blockEnd;
        return reinterpret_cast<T *>(block);
    }
    return static_cast<T *>(stack.FUN_0000f090(numBytes));
}

inline void stackBlockFree(void *pointer, int numBytes) /* derived name */
{
    Allocator0000ed40 &stack = D_16dc070->stack;
    if (stack.slabSize >= numBytes && static_cast<char *>(pointer) + numBytes == stack.cur &&
        stack.slabStart != pointer) {
        stack.cur = static_cast<char *>(pointer);
    } else {
        stack.FUN_0000f460(pointer, numBytes);
    }
}

template <typename T> struct LocalBuffer /* derived name */ {
    LocalBuffer(int n) : data(stackAllocate<T>(n)), size(n) {}

    ~LocalBuffer()
    {
        stackBlockFree(data, roundedSize(size));
    }

    static int roundedSize(int n)
    {
        return (n * int(sizeof(T)) + 127) & ~127;
    }

    T *data;
    int size;
};

template <typename T> struct LocalArray : public hkArray<T> /* derived name */ {
    explicit LocalArray(int n) : initialCapacity(n)
    {
        this->data = n ? stackAllocate<T>(n) : 0;
        this->capacityAndFlags = n | hkArray<T>::DONT_DEALLOCATE_FLAG;
        localMemory = this->data;
    }

    ~LocalArray()
    {
        if (localMemory == this->data) {
            this->size = 0;
        }
        stackBlockFree(localMemory, LocalBuffer<T>::roundedSize(initialCapacity));
    }

    T *localMemory;      /* derived name */
    int initialCapacity; /* derived name */
};

/* One of the broad phase's trees (derived names; the layer updates time
 * themselves "TtUpdateVolatileTree" and "TtUpdateNonVolatileTree"): its
 * nodes from a pool, its leaves buckets of up to 31 boxes, each box keyed
 * by the body it belongs to. */
struct BroadPhaseTree00142a40 /* derived name */
{
    typedef ElementPool00198a20::Element Node;

    /* A leaf's bucket, 0x200 bytes: the number of boxes, the updates since
     * its boxes were last sorted, the boxes from +0x10. */
    struct Bucket {
        int numEntries;
        int age;
        u8 unknown8[8];
        hkAabb16 entries[31];
    };

    /* A box on the rebuild's lists, 16 bytes: its body's key, then twice
     * its centre (the sum of the bounds) on each axis. */
    struct Entry {
        u32 key;
        u32 centre2[3];
    };

    /* A tree of no nodes over the leaf size given (0x195ee0; the broad
     * phase's setup builds each in 0x58 bytes of the thread's heap,
     * 0x140c91): 128 buckets, each free, handed out from the lowest index.
     * derived name. */
    BroadPhaseTree00142a40(int maxLeafEntries);

    /* The root node, none when the tree is empty. derived name. */
    const Node *getRoot() const
    {
        return root != Node::NO_CHILD ? &nodes.elements[root] : HK_NULL;
    }

    ElementPool00198a20 nodes;
    int root; /* NO_CHILD when the tree is empty */
    int numLeaves;
    int numEntries; /* the boxes in all the buckets */
    hkArray<Bucket> buckets;
    hkArray<int> freeBuckets;
    /* A subtree with no more boxes than this becomes one leaf (0x13f52e). */
    int maxLeafEntries;
};

/* The walk of a tree into a flat list (0x13b790, recursive): an item per
 * node, a leaf's node pointers in order of the walk. derived names. */
struct TreeWalk0013b790 /* derived name */
{
    /* A node's place in the walk: its first leaf, the leaves under each
     * child, the items of the children. */
    struct Item {
        int firstLeaf;
        int numLeft;
        int numRight;
        int leftItem;
        int rightItem;
    };

    /* The walk of a tree from its root over its leaves (0x13e0f2 in the
     * tree update): the lists sized, then the recursion from the first
     * item, its count a local of the walk's. */
    inline TreeWalk0013b790(BroadPhaseTree00142a40 *walkedTree, int numLeaves,
                            BroadPhaseTree00142a40::Node *root)
    {
        items.setSize(hkContainerTempAllocator::get(), 2 * numLeaves - 1);
        leaves.setSize(hkContainerTempAllocator::get(), numLeaves);
        tree = walkedTree;
        int numItems = 0;
        FUN_0013b790(root, numItems, 0);
    }

    /* The node and its subtree from the next item on, its leaves from
     * firstLeaf on; the leaf after its last back. derived name. */
    int FUN_0013b790(BroadPhaseTree00142a40::Node *node, int &numItems, int firstLeaf);

    TempInplaceArray<Item, 32> items;
    TempInplaceArray<BroadPhaseTree00142a40::Node *, 128> leaves;
    BroadPhaseTree00142a40 *tree;
};

/* An entry the pair processing 0x717d0 sorts in an array of its own
 * (derived names), 24 bytes: an int, two bodies' ids, a 64-bit value. The
 * sort 0x72980 orders by the two ids read as one 64-bit key, the low word
 * the first id (hkAlgorithm::quickSortRecursive, tlg_hk_algorithm.h); the
 * pivot is assigned member by member, the ids by their own assignment. */
struct BodyPairEntry000717d0 /* derived name */
{
    BodyPairEntry000717d0() {}

    BodyPairEntry000717d0(const BodyPairEntry000717d0 &other)
        : value0(other.value0), bodyA(other.bodyA), bodyB(other.bodyB), value10(other.value10)
    {
    }

    /* The two ids as one 64-bit key. derived name. */
    u64 getKey() const
    {
        return *reinterpret_cast<const u64 *>(&bodyA);
    }

    bool operator<(const BodyPairEntry000717d0 &other) const
    {
        return getKey() < other.getKey();
    }

    u32 value0;
    hknpBodyId bodyA;
    hknpBodyId bodyB;
    u64 value10;
};

/* A leaf's age and its place in the walk, sorted by age (0x13b6c0,
 * hkAlgorithm::quickSortRecursive over [first, last] with the default
 * order, tlg_hk_algorithm.h: the ages compare as unsigned words). derived
 * names. */
struct LeafAge0013b6c0 /* derived name */
{
    u32 age;
    int leaf;

    bool operator<(const LeafAge0013b6c0 &other) const
    {
        return age < other.age;
    }
};

/* The nodes of a subtree into the two lists, the inner ones and the leaves
 * (0x1985d0). derived name. */
void FUN_001985d0(int nodeIndex, BroadPhaseTree00142a40 *tree, hkArray<int> &innerNodes,
                  hkArray<int> &leafNodes); /* derived name */

/* A node rebuilt over the bodies of the keys given: 0x13c340 splits them
 * under the box of their centres, 0x13de80 puts them in one leaf. derived
 * names. */
void FUN_0013c340(BroadPhaseTree00142a40 *tree, int nodeIndex, const hkAabb16 *centres,
                  const hknpBody *bodies, const int *keys, int numKeys); /* derived name */
void FUN_0013de80(BroadPhaseTree00142a40 *tree, int nodeIndex, const hknpBody *bodies,
                  const int *keys, int numKeys); /* derived name */

/* A reference-counted object of the vtable 0x16a5b70 (no row yet: its
 * constructor 0x176420 builds it from a construction info and stores the
 * vtable at 0x176450; the game builds one at 0xea901a). The object at +0x20
 * starts null; 0x177130 sets it, a reference taken on the new one before the
 * old one's is released (the game passes its +0x60 at 0xea9048). derived
 * names. */
struct Object00176420 /* derived name */
{
    void FUN_00177130(hkReferencedObject *object); /* derived name */

    u8 unknown0[0x20];
    hkReferencedObject *object20; /* derived name */
};

/* What the broad phase's pair search gets as its first argument (derived
 * name): the world at +8. */
struct SimulationContext00142fa0 /* derived name */
{
    u8 unknown0[8];
    hknpWorld *world;
};

/* The new pairs between two layers' trees found and written (0x197c60,
 * 0x3cc bytes; the broad phase's slot 10 calls it). derived name. */
void FUN_00197c60(const SimulationContext00142fa0 *context, hknpCollisionFilter *filter,
                  BroadPhaseTree00142a40 *treeA, BroadPhaseTree00142a40 *treeB, void *argument5,
                  void *argument6);

/* The broad phase's trees by layer (derived names): a tree per layer from
 * +0x10, two flags per layer after them, the number of layers at +0x60;
 * the bodies marked for the update in a bit field at +0x78, the lowest and
 * highest marked ids at +0x90 and +0x94 (slot 4 of the vtable at address
 * point 0x16a3f60, 0x143390, marks them; slot 5 is the update 0x142bb0). */
struct BroadPhaseLayers00142a40 /* derived name */
{
    /* Slot 4 (0x143390): each of the ids, striding bytes apart, marked,
     * the field grown to a multiple of 32 bits that holds it, and the
     * lowest and highest marked ids kept. derived name. */
    void FUN_00143390(const u32 *ids, int numIds, int striding);

    /* Slot 7 (0x142e00): the tasks made on first use, then set up from the
     * arguments as they came. derived name. */
    void FUN_00142e00(void *argument1, void *argument2, void *argument3,
                      void *argument4); /* derived names */

    /* Slot 9 (0x142ea0): under the timer "FindAllPairs", each pair of
     * layers' trees walked against each other through the world's
     * collision filter, the pairs written to the output. derived name. */
    void FUN_00142ea0(const struct BroadPhaseContext00142ea0 *context, void *pairsOut);
    /* Slot 8 (0x143440): the box around every layer's tree, from each
     * root's box. derived name. */
    void FUN_00143440(hkAabb16 &aabbOut) const;

    /* Slot 10 (0x142fa0), timed as "TtFindNewPairs": each pair of layers
     * the list names whose trees both hold boxes searched for new pairs
     * (0x197c60) under the world's collision filter, the last two
     * arguments handed on the other way round; the third is not read.
     * derived name. */
    void FUN_00142fa0(const SimulationContext00142fa0 *context, void *argument2, void *argument3,
                      void *argument4);

    u8 unknown0[0x10];
    BroadPhaseTree00142a40 *trees[8];
    bool flag50[8];
    bool updatePending[8]; /* cleared by both trees' updates */
    int numLayers;
    u8 unknown64[4];
    /* The layers whose trees are searched against each other, two indices
     * a pair (0x142fa0). derived name. */
    hkArray<int> layerPairs;
    hkBitField markedBodies;
    /* While the first does not exceed the second, the broad phase's update
     * runs FUN_00141500 first (0x142bff). derived names. */
    u32 lowestMarkedId;
    u32 highestMarkedId;
    BroadPhaseTasks0018d640 *tasks; /* derived name */
};

/* What the broad phase's pair search runs in (derived names): the world at
 * +8 (slot 9 reads its modifier manager's collision filter, 0x142ef8). */
struct BroadPhaseContext00142ea0 /* derived name */
{
    u8 unknown0[8];
    hknpWorld *world; /* derived name */
};

/* Two trees' boxes walked against each other, each overlapping pair the
 * filter lets through written out (0x197c60, 0x3cc bytes). derived names. */
void FUN_00197c60(const BroadPhaseContext00142ea0 *context, hknpCollisionFilter *filter,
                  const BroadPhaseTree00142a40 *treeA, const BroadPhaseTree00142a40 *treeB,
                  void *pairsOut, int argument6); /* derived name */

/* The work the broad phase's update runs first (0x141500, 0x1533 bytes).
 * derived name. */
void FUN_00141500(BroadPhaseLayers00142a40 *layers, const hknpBody *bodies);

/* What the broad phase's update task works on (derived names): the trees
 * by layer at +8 and the body manager at +0x10 (0x18d0c9). */
struct BroadPhaseTaskData0018d050 /* derived name */
{
    u8 unknown0[8];
    BroadPhaseLayers00142a40 *layers; /* derived name */
    hknpBodyManager *bodyManager;     /* derived name */
};

/* One of the three 16-byte tasks BroadPhaseTasks0018d640's constructor
 * builds (vtable 0x16a6690, address point 0x16a66a0, no type info; slot 1
 * the shared 0x13e50): its data at +8. Slot 2 (0x18d050), timed as the
 * collide stage's broad phase, fetches the active bodies and updates the
 * layers' trees from them. derived name. */
class BroadPhaseUpdateTask0018d050 /* derived name */
{
  public:
    virtual ~BroadPhaseUpdateTask0018d050();

    void FUN_0018d050(); /* vtable slot 2; derived name */

    BroadPhaseTaskData0018d050 *data; /* derived name */
};

/* A tree's update (0x13e090): its boxes refreshed from the bodies unless
 * kept, the oldest buckets' ages reset beyond the number given, then the
 * tree rebuilt top-down over its leaves, a leaf whose boxes stray far from
 * its parent's split dissolved into its parent's lists. The first and the
 * fourth arguments are not read. derived names. */
void FUN_0013e090(BroadPhaseLayers00142a40 *layers, BroadPhaseTree00142a40 *tree,
                  const hknpBody *bodies, int layer, bool keepAabbs, int maxAgedLeaves);

/* A layer's volatile tree updated (0x142a40, from the layer task's slot 2
 * at 0x18d1c2) under its timer. derived name. */
void FUN_00142a40(BroadPhaseLayers00142a40 *layers, const hknpBody *bodies, int layer);
void FUN_00142af0(BroadPhaseLayers00142a40 *layers, const hknpBody *bodies, int layer,
                  bool refreshAabbs); /* derived name */
/* The broad phase's update (0x142bb0): every layer's tree that holds
 * boxes updated, the volatile one when flagged, else the non-volatile one
 * when pending or in mode 1, which refreshes its boxes. derived name. */
void FUN_00142bb0(BroadPhaseLayers00142a40 *layers, const hknpBody *bodies, int mode);

void FUN_0000bb40(hkMemoryRouter *router); /* derived name */

/* A record of the memory in use (derived names; Havok's memory snapshot,
 * no string names it): the allocator its arrays grow from at +0, the
 * allocations (24 bytes each) at +8, the providers (48 bytes: a name of up
 * to 31 characters, then their parents' indices) at +0x18. 0x11170 adds a
 * provider under a parent, 0x11280 an allocation of a provider. */
struct MemorySnapshot00011280 /* derived name */
{
    /* What an allocation's bytes are (derived names): bookkeeping, in use,
     * free (the large block allocator's slot 19 records its chunks so). */
    enum Status { STATUS_OVERHEAD = 0, STATUS_USED = 1, STATUS_UNUSED = 2 };

    struct Allocation {
        const void *start;
        int size;
        int sourceId;
        int traceId; /* -1: none */
        u8 status;
    };

    /* An allocation of a provider recorded with no trace; its index
     * returned (0x11280; the memory system's report at 0xd125 records its
     * blocks with it). derived name. */
    int FUN_00011280(int sourceId, u8 status, const void *address, int size);

    /* A provider (derived names): its name, cut to 31 characters, and its
     * parents' indices. */
    struct Provider {
        char name[32];
        hkArray<int> parentIndices;
    };

    /* A provider added under a parent (-1: none), its name copied; its
     * index returned (0x11170; the memory system's report at 0xd0e4 and
     * the allocators' 0x365a and 0x13084). derived name. */
    int FUN_00011170(const char *name, int parentId);

    AllocatorBase *allocator;
    hkArray<Allocation> allocations;
    hkArray<Provider> providers;
};

/* What the penetration query FUN_000a6e30 asks a support point of (derived
 * names): slot 2 of the object at +0x50 gives, for a direction, the two
 * shapes' supporting vertices (the second's w an index). */
class SupportShape000a8ef0 /* derived name */
{
  public:
    virtual void unknownVirtual0();
    virtual void unknownVirtual1();
    virtual void unknownVirtual2(const void *shapeA, const Vec4 &direction, const void *shapeB,
                                 const void *query, Vec4 *vertexBOut, Vec4 *vertexAInfoOut,
                                 Vec4 *vertexAOut) const; /* derived names */

    /* The support point of the difference for a direction: slot 2's two
     * vertices, then their difference and the first's position with its
     * index (inline in 0xa8ef0, its locals bracketed as an inlined
     * helper's, cookbook 120). derived name. */
    inline void getSupportPoint(const void *shapeA, const Vec4 &direction, const void *shapeB,
                                const void *query, struct SupportPoint000a8ef0 &pointOut) const;
};

/* A support point of the Minkowski difference (derived names): the
 * difference at +0, the second shape's vertex at +0x10 and the first's at
 * +0x20 with the index of the vertex in its w. */
struct SupportPoint000a8ef0 /* derived name */
{
    Vec4 difference; /* derived name */
    Vec4 vertexB;    /* derived name */
    Vec4 vertexA;    /* derived name */
};

inline void SupportShape000a8ef0::getSupportPoint(const void *shapeA, const Vec4 &direction,
                                                  const void *shapeB, const void *query,
                                                  SupportPoint000a8ef0 &pointOut) const
{
    Vec4 vertexAInfo;
    Vec4 vertexA;
    unknownVirtual2(shapeA, direction, shapeB, query, &pointOut.vertexB, &vertexAInfo, &vertexA);
    pointOut.difference = _mm_sub_ps(pointOut.vertexB, vertexA);
    pointOut.vertexA = _mm_blend_ps(vertexA, vertexAInfo, 8);
}

/* A face of the penetration query's polytope (derived names): its plane's
 * normal at +0, three edges of 0x20 bytes from +0x10, each starting at a
 * support point, and the plane's distance from the origin at +0x70. */
struct Face000a9cf0 /* derived name */
{
    struct Edge {
        const SupportPoint000a8ef0 *vertex; /* derived name */
        u8 unknown8[0x18];
    };

    /* The plane through the three vertices (0xa9cf0; the query at
     * 0xa7d3d): the normal of the edges' cross product, normalized, and
     * the distance along it of the first vertex. derived name. */
    void FUN_000a9cf0();

    Vec4 normal;    /* derived name */
    Edge edges[3];  /* derived name */
    float distance; /* derived name */
};

struct SupportQuery000a8ef0 /* derived name */
{
    /* The support point for a direction (0xa8ef0; the query's caller at
     * 0xa7153 and twice after). derived name. */
    void FUN_000a8ef0(const Vec4 &direction, SupportPoint000a8ef0 &pointOut) const;

    u8 unknown0[0x50];
    const SupportShape000a8ef0 *support; /* derived name */
    u8 unknown58[0x18];
    const void *shapeA; /* derived name */
    const void *shapeB; /* derived name */
};

/* Eight references (derived name): the world keeps one at +0x610, which
 * its destructor destroys and frees as 0x40 bytes (0x4b65c), and 0x170020
 * builds two on its stack. The destructor (0x906f0) releases them from the
 * last. */
struct RefPtrArray000906f0 /* derived name */
{
    ~RefPtrArray000906f0();

    hkRefPtr<hkReferencedObject> references[8]; /* derived name */
};

/* A field of a bit field map holds its own size (BitFieldMap00199770::
 * Block): FUN_00199600 takes one from the thread's temporary allocator, a
 * 0x28-byte header (its byte size at +0, an element size at +4, a bit
 * field's words at +8 in the block, the element storage pointer at +0x20)
 * before the bits and the elements; FUN_00199770 gives it back at that
 * size. */
void FUN_00199770(BitFieldMap00199770::Block *block); /* derived name */

/* The thread's teardown (derived name; 0x9a80): the thread's block and the
 * thread's router given up, always a success. */
hkResult FUN_00009a80(); /* derived name */

/* The thread's setup with its router (0x9a60). derived name. */
hkResult FUN_00009a60(hkMemoryRouter *router); /* derived name */

/* The calling thread's number (derived name), stored by the worker's
 * context (0x8f5e1). */
extern __thread int D_16dc068;

/* What a worker thread holds while it runs (FUN_000071a0 keeps one on its
 * stack, 0x80 bytes): the constructor FUN_0008f570 builds the router,
 * turns on flush-to-zero, hands the router to the memory system under the
 * name "hkWorkerThreadContext" (the string at 0x14c3ef0, which names the
 * class) and makes it the thread's (FUN_00009a60); the destructor undoes
 * it in reverse. */
class hkWorkerThreadContext
{
  public:
    /* 0x8f570: the thread's number kept in its thread-local word last. */
    hkWorkerThreadContext(int threadNumber);
    ~hkWorkerThreadContext();

    hkMemoryRouter memoryRouter; /* derived name */
};

void FUN_014aff00(); /* derived name */

/* The library's formatted print into a buffer of `size` bytes (derived name):
 * FUN_00017e80 starts the argument list and hands it to the imported
 * vsnprintf with the size widened (`movslq %esi`). */
int FUN_00017e80(char *buffer, int size, const char *format, ...); /* derived name */

/* Writes the Havok SDK version string, "hk_2014.2.0-r1", into a buffer of
 * `size` bytes (derived name); FUN_00183350 fills a 16-byte name with it
 * when the object at +0x10 has none. */
void FUN_0019d370(char *buffer, int size); /* derived name */

/* A reference-counted object (derived name; no type info names it) whose
 * vtable 0x16997f0 (address point 0x1699800) only its constructor
 * FUN_00061f00 stores; the game builds one at 0xea9d11. Slot 6 (0x61f40),
 * when the object it is given reads mode 1 (FUN_0000b670), moves a point
 * along a direction by the float at +0xc (1.5 on construction). */
class hknpCharacterContext;
struct hknpCharacterInput;
struct hknpCharacterOutput;

class Object00061f00 : public hkReferencedObject /* derived name */
{
  public:
    Object00061f00();
    virtual ~Object00061f00();

    /* Slot 6 (0x61f40): on the first update in its state the character's
     * velocity along up raised to the speed that reaches the height under
     * the gravity, sqrt(2 g h), when it is below it; on a later one the
     * context changes to state 2. derived name. */
    void FUN_00061f40(hknpCharacterContext &context, const hknpCharacterInput &input,
                      hknpCharacterOutput &output);

    float valueC; /* derived name: the height of the jump, 1.5 on construction */
};

/* The character controller's state machine (derived names throughout: no
 * string names these classes; the shapes follow Havok's character states).
 * The context holds the state manager at +0x10 and the current state at
 * +0x18; FUN_0003e9c0 changes the state: the old state's handler (from the
 * manager, FUN_00035c40) is told through its slot 9, the new state stored,
 * then the new handler told. */
struct hknpCharacterInput /* derived name */
{
    /* The stick's two axes (the climbing state's 0x3e4b0 scales them).
     * derived names. */
    float inputLR;
    float inputUD;
    hkBool wantJump; /* derived name */
    u8 unknown9[7];
    Vec4 up;         /* derived name */
    Vec4 forward;    /* derived name */
    hkBool atLadder; /* derived name */
    u8 unknown31[0xf];
    /* The surface the character stands on, from +0x40: whether it moves,
     * then how well it supports the character (2: supported). */
    hkBool isSurfaceDynamic; /* derived name */
    u8 supportedState;       /* derived name */
    u8 unknown42[0xe];
    Vec4 surfaceNormal;   /* derived name: the climbing state jumps off along it */
    Vec4 surfaceVelocity; /* derived name */
    u8 unknown70[8];
    /* The step's time (the in-air state scales its acceleration and the
     * gravity by it, 0x36693 and 0x366e6). derived name. */
    float deltaTime;
    u8 unknown7c[0x14];
    Vec4 velocity; /* derived name: the character's, at +0x90 */
    Vec4 gravity;  /* derived name: its length is the climbing state's jump speed */
};

struct hknpCharacterOutput /* derived name */
{
    Vec4 velocity; /* derived name */
};

/* A character state's id (derived names): the index of its handler in the
 * state manager, which travels zero-extended (0x35c40's `mov eax, esi`), as
 * an enumeration with no negative value does; eleven ids, the manager's
 * destructor's loop bound. */
enum hknpCharacterStateType /* derived name */
{
    HKNP_CHARACTER_STATE_COUNT = 11 /* derived name */
};

class hknpCharacterContext;

/* A character state's handler (derived names): what the manager holds by
 * id. The context's state change (0x3e9c0) tells the state it leaves
 * through slot 9 and the state it enters through slot 8, each with the
 * other state, the input and the output; slot 7 is the update (the in-air
 * state's 0x365e0). */
class hknpCharacterState : public hkReferencedObject /* derived name */
{
  public:
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void update(hknpCharacterContext &context, const hknpCharacterInput &input,
                        hknpCharacterOutput &output); /* slot 7; derived name */
    virtual void enterState(hknpCharacterContext &context, int previousState,
                            const hknpCharacterInput &input,
                            hknpCharacterOutput &output); /* slot 8; derived name */
    virtual void leaveState(hknpCharacterContext &context, int nextState,
                            const hknpCharacterInput &input,
                            hknpCharacterOutput &output); /* slot 9; derived name */
};

/* The state manager (derived name; vtable 0x1692eb0): a reference-counted
 * object of 0x68 bytes the context holds a reference to, eleven state
 * pointers by id from +0x10 (the game registers its states into them from
 * 0xea9c20, FUN_00035ba0 replacing one: a reference taken to the new
 * handler, the old one's released); FUN_00035c40 returns its handler for a
 * state. The owner at
 * 0x3e9c0 calls slot 9 of the old state's handler and slot 8 of the new
 * one, fetching each through that getter. */
class hknpCharacterStateManager : public hkReferencedObject /* derived name */
{
  public:
    /* 0x359d0: no state registered. */
    hknpCharacterStateManager();

    /* 0x35b10: each registered state's reference released; the deleting
     * destructor 0x35a40 runs it and frees through the class's delete. */
    virtual ~hknpCharacterStateManager();

    static void operator delete(void *object, unsigned long numBytes)
    {
        freeReferencedObject(object, numBytes);
    }

    /* 0x35c40: the handler registered for a state. derived name. */
    hknpCharacterState *FUN_00035c40(hknpCharacterStateType state) const;

    /* 0x35ba0: a handler registered for a state, referenced before the one
     * it replaces is released (the game registers its states at 0xea9c25
     * on). derived name. */
    void FUN_00035ba0(hknpCharacterState *handler, hknpCharacterStateType state);

    hknpCharacterState *registeredState[HKNP_CHARACTER_STATE_COUNT]; /* derived name */
};

/* The character context (vtable 0x16969d0, address point 0x16969e0, D14's
 * row hknpCharacterContext; no string names it, the shape is Havok's character
 * context): 0x50 bytes, built only by the game (0xeaa611, from the thread's
 * heap, initial state 2). Slot 0 is the complete destructor 0x3e960, slot 1
 * the deleting one 0x3e8c0, slots 2 to 4 hkReferencedObject's. */
class hknpCharacterContext : public hkReferencedObject /* derived name */
{
  public:
    /* 0x3e840: the manager referenced, the initial state current and
     * previous, filtering on, a zero surface velocity. */
    hknpCharacterContext(const hknpCharacterStateManager *stateManager, int initialState);

    /* 0x3e960: the manager's reference released. */
    virtual ~hknpCharacterContext();

    /* The class allocator's delete (the deleting destructor 0x3e8c0 frees
     * at the recorded size, 0x50 by default). */
    static void operator delete(void *object, unsigned long numBytes)
    {
        freeReferencedObject(object, numBytes);
    }

    void FUN_0003e9c0(int state, const hknpCharacterInput &input,
                      hknpCharacterOutput &output); /* derived name */

    /* The updates since the state changed (the getter folded onto the
     * int-at-+0x40 body 0xb670; 0x61f40 asks it). derived name. */
    int FUN_0000b670() const;

    int characterType;                             /* derived name: 0x3ea60 sets it */
    const hknpCharacterStateManager *stateManager; /* derived name */
    int currentState;                              /* derived name: 0x3e9b0 returns it */
    int previousState;                             /* derived name */
    hkBool filterEnable;                           /* derived name: 0x3ea50 sets it */
    float maxLinearAcceleration;                   /* derived name */
    float maxLinearSpeed;                          /* derived name */
    float gain;                                    /* derived name */
    Vec4 previousSurfaceVelocity;                  /* derived name: 0x3ea80 returns its address */
    int numUpdatesInCurrentState;                  /* derived name: 0x3ea70 returns it */
};

/* The in-air state (derived name; vtable 0x1693610, address point
 * 0x1693620, constructor 0x365a0: gain 0.05, air speed 10 and maximum
 * acceleration 50 from +0xc). Slot 7 (FUN_000365e0) leaves the state for
 * the ground (state 0) once supported, for climbing (state 3) at a
 * ladder. */
class hknpCharacterStateInAir : public hkReferencedObject /* derived name */
{
  public:
    hknpCharacterStateInAir();
    /* Empty (the shared 0x1c1e0); the deleting destructor is 0x1ba30, the
     * body every vtable of a 0x18-byte reference-counted class with an empty
     * destructor cites (D15; none of the eleven classes has other members
     * beside it, so it is named for the first vtable among them,
     * docs/NOTES.md Round 35). */
    virtual ~hknpCharacterStateInAir();

    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 6 (0x36610): the movement at the air speed toward the stick,
     * along the up axis, accelerating at most the maximum over the step;
     * the vertical part of the velocity then put back as it came in, and
     * the gravity added over the step. derived name. */
    void FUN_00036610(hknpCharacterContext &context, const hknpCharacterInput &input,
                      hknpCharacterOutput &output);

    void FUN_000365e0(hknpCharacterContext &context, const hknpCharacterInput &input,
                      hknpCharacterOutput &output); /* vtable slot 7; derived name */

    float gain;                  /* derived name */
    float airSpeed;              /* derived name */
    float maxLinearAcceleration; /* derived name */
};

inline void hknpCharacterStateInAir::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpFirstPersonGun::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

/* The climbing state (derived name; its vtable 0x16968c0 has no type info
 * and no row; slot 7 is 0x3e430). */
/* What the character's movement is computed from (derived names; 0x3bc10
 * takes it with the output velocity). */
struct CharacterMovementInput /* derived name */
{
    CharacterMovementInput() : flag68(false) {}

    Vec4 forward;
    Vec4 up;
    Vec4 surfaceNormal;
    Vec4 currentVelocity;
    Vec4 desiredVelocity;
    Vec4 surfaceVelocity;
    float gain;
    float maxVelocityDelta;
    bool flag68;
};

/* The movement toward the desired velocity along the surface, into the
 * output velocity (0x3bc10). derived name. */
void FUN_0003bc10(const CharacterMovementInput &input, Vec4 &velocityOut);

class hknpCharacterStateClimbing : public hkReferencedObject /* derived name */
{
  public:
    /* Slot 6 (0x3e4b0): on the ladder, moved along the surface by the
     * stick, ten metres a second, pressed one tenth into the surface.
     * derived name. */
    void FUN_0003e4b0(hknpCharacterContext &context, const hknpCharacterInput &input,
                      hknpCharacterOutput &output);

    /* Slot 7 (0x3e430): off the ladder, the character is in the air
     * (state 2); a jump pushes it off along the surface's normal at the
     * speed of gravity's length first. derived name. */
    void FUN_0003e430(hknpCharacterContext &context, const hknpCharacterInput &input,
                      hknpCharacterOutput &output);
};

/* The world's set of default modifiers (derived name; vtable 0x16991e0,
 * address point 0x16991f0, no type info; built inline by 0x48b20 at
 * 0x49d8b, 0xe8 bytes): twenty modifier objects from +0x10 to +0xd8, each
 * with the thirteen-slot interface (docs/NOTES.md, the round of
 * FUN_0016d1f0). */
class DefaultModifierSet : public hkReferencedObject /* derived name */
{
  public:
    /* Empty (the shared 0x3b640; the members' destructors are empty too);
     * the deleting destructor 0x48ad0 frees the set through the class
     * allocator, the body only this vtable cites. */
    virtual ~DefaultModifierSet();

    static void operator delete(void *object, unsigned long numBytes);

    u8 unknownC[0xdc];
};

inline void DefaultModifierSet::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkGeometry::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpMaterialLibrary::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpVehicleDefaultTransmission::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkpLinearParametricCurve::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkPackfileWriter::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpVehicleLinearCastWheelCollide::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxIndexBuffer::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void PageAllocator::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void StringMap::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

inline void hkSimpleLocalFrame::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkSkinBinding::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxSkinBinding::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkcdPlanarSolid::NodeStorage::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxSparselyAnimatedBool::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxSparselyAnimatedString::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hkxSparselyAnimatedInt::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void hknpConvexPolytopeShape::Connectivity::operator delete(void *object,
                                                                   unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

/* The on-ground state (derived name; vtable 0x169ae30, address point
 * 0x169ae40, no row yet; constructor 0x6fcf0: gain 0.95, walk speed 10
 * and maximum acceleration 200 from +0xc, then three flags from +0x18, the
 * first set). The game builds the 0x20-byte object at 0xea9c17 and
 * registers it as state 0 through 0x35ba0. Slots 6 and 7 are 0x6fdb0 and
 * 0x6fd40. */
class hknpCharacterStateOnGround : public hkReferencedObject /* derived name */
{
  public:
    hknpCharacterStateOnGround();
    virtual ~hknpCharacterStateOnGround();

    /* Slot 7 (0x6fd40): a jump starts jumping (state 1), a ladder climbing
     * (state 3); a character no longer supported is in the air (state 2),
     * its velocity first stripped of the part along up when the state kills
     * it on launch. derived name. */
    void FUN_0006fd40(hknpCharacterContext &context, const hknpCharacterInput &input,
                      hknpCharacterOutput &output);

    float gain;                         /* derived name */
    float walkSpeed;                    /* derived name */
    float maxLinearAcceleration;        /* derived name */
    hkBool killVelocityOnLaunch;        /* derived name */
    hkBool limitVerticalVelocity;       /* derived name */
    hkBool disableHorizontalProjection; /* derived name */
};

/* A hash map of 16-bit keys (derived name): 16-byte pairs from the pointer
 * at +0 (the key in the first two bytes, an empty slot's key 0xffff), the
 * count at +8 with the don't-deallocate flag in its top bit, the hash mask
 * at +0xc. The object FUN_0016d360 constructs holds one at +0x38, which its
 * destructor 0x16d8c0 frees through the containers' allocator. */
struct ShortKeyMap /* derived name */
{
    enum { DONT_DEALLOCATE_FLAG = int(0x80000000) }; /* derived name */

    struct Pair {
        u16 key; /* derived name */
        u8 unknown2[6];
        hkUlong value; /* derived name */
    };

    /* Every slot emptied and the count zeroed, the storage kept. derived
     * name. */
    void clear()
    {
        const int capacity = hashMod + 1;
        for (int i = 0; i < capacity; i++) {
            elems[i].key = u16(-1);
        }
        numElems &= DONT_DEALLOCATE_FLAG;
    }

    /* Emptied, the storage given back to the allocator unless the map does
     * not own it, then left with no storage (0x199580). derived name. */
    void FUN_00199580(AllocatorBase &allocator);

    /* Empty, no storage: the hash mask -1 (0x16d3bf). */
    ShortKeyMap() : elems(0), numElems(0), hashMod(-1) {}

    Pair *elems;  /* derived name */
    int numElems; /* derived name */
    int hashMod;  /* derived name */
};

/* Per-node lists of edges (derived names): the first edge of each node at
 * +0 and, per edge, the next edge at each of its two ends at +0x10. Built
 * empty at +0x50 of the object FUN_0016d360 constructs (0x16d3ca); 0x17a220
 * frees both arrays; 0x17a290 puts an edge of a 64-byte record (its second
 * node at +4, its link index at +0x18) at the head of a node's list. */
/* The 64-byte edge record those lists index (derived names): its two nodes
 * at +4 and +0xc (the caller at 0x16dd98 links the edge at each), a counted
 * reference at +0x10, its link index at +0x18, and a block of the thread's
 * heap at +0x30 with its byte size at +0x2e (0x16df30 frees it, a pointer
 * of 0 or 1 holding none). A free record has an invalid first node and the
 * next free record's index in place of its second. */
struct EdgeRecord0017a290 /* derived name */
{
    u8 unknown0[4];
    int nodeA; /* derived name */
    u8 unknown8[4];
    int nodeB;                           /* derived name */
    hkRefPtr<hkReferencedObject> object; /* derived name */
    int linkIndex;                       /* derived name */
    u8 unknown1c[0x12];
    u16 blockSize; /* derived name */
    void *block;   /* derived name */
    u8 unknown38[8];
};

struct NodeEdgeLists /* derived name */
{
    struct EdgeLinks {
        int next[2]; /* derived name */
    };

    NodeEdgeLists();

    /* Out of line (0x17a220; the owner's destructor 0x16d8c0 calls it at
     * 0x16dac4): both arrays' storage given back. */
    ~NodeEdgeLists();

    /* Puts an edge at the head of one of its nodes' lists (0x17a290). */
    void FUN_0017a290(unsigned int edgeIndex, const EdgeRecord0017a290 *edges,
                      int node); /* derived name */

    /* Takes an edge out of one of its nodes' lists (0x17a2d0; the owner's
     * edge removal 0x16df30 at each of the edge's two nodes): its
     * predecessor's link, or the node's first edge, takes its link, which
     * is cleared. derived name. */
    void FUN_0017a2d0(unsigned int edgeIndex, const EdgeRecord0017a290 *edges, int node);

    /* The link an edge keeps at a node: the first of its pair at its first
     * node, the second at the other. derived name. */
    int *linkAt(unsigned int edgeIndex, const EdgeRecord0017a290 *edges, int node)
    {
        const EdgeRecord0017a290 &edge = edges[edgeIndex];
        EdgeLinks &links = nextEdge.data[edge.linkIndex];
        const int nodeA = edge.nodeA;
        return nodeA == node ? &links.next[0] : &links.next[1];
    }

    hkArray<int> firstEdge;      /* derived name */
    hkArray<EdgeLinks> nextEdge; /* derived name */
};

/* The object the world's set-up builds at +0x148 of the world (derived
 * names; 0x48b9e): the world at +0 (null when built), the 64-byte edge
 * records at +8 with their count at +0x10, an array of 8-byte entries at
 * +0x20 (its destructor 0x16d8c0 destroys them from the last), a
 * ShortKeyMap at +0x38, a count and a last index (0x7fffffff: none) at
 * +0x48 and +0x4c, the node edge lists at +0x50. The constructor (0x16d360)
 * builds them empty and runs the set-up 0x16d3f0 with its last two
 * arguments. */
struct Entry0016d360 /* derived name */
{
    u8 unknown0[8];
};

class Owner0016d360 /* derived name */
{
  public:
    Owner0016d360(hknpWorld *world_, void *argument2, int argument3);

    /* The set-up (0x16d3f0): the world's signal at +0x5b8 fired with the
     * world and this object, then the storage sized. derived names. */
    void FUN_0016d3f0(void *argument2, int argument3);

    /* An edge taken out (0x16df30; the world's 0x4d620 after firing its
     * signal): out of both its nodes' lists while the object has a world,
     * its block given back and its reference released, then the record put
     * at the head of the free list. derived name. */
    void FUN_0016df30(unsigned int edgeIndex);

    hknpWorld *world;          /* derived name */
    EdgeRecord0017a290 *edges; /* derived name */
    int numEdges;              /* derived name */
    u8 unknown14[4];
    int int18; /* derived name: the first free record, 0x16df30 */
    u8 unknown1c[4];
    hkArray<Entry0016d360> entries; /* derived name */
    u8 unknown30[8];
    ShortKeyMap map;         /* derived name */
    int int48;               /* derived name */
    int lastIndex;           /* derived name */
    NodeEdgeLists edgeLists; /* derived name */
};

/* The world's two tables of shape functions (derived names), filled by its
 * constructor: from +0x58 (0x4a5b0 onward) and from +0x420 (0x4a850
 * onward). Some entries are adaptors in the world's file that pass the
 * table's arguments on to a function of another signature, keeping every
 * register argument and re-widening the bool on the stack (cookbook 17):
 * the +0x420 table's adaptors (0x52380 to 0x52d80) take ten arguments and
 * drop the seventh, the +0x58 table's (0x56360 to 0x57050) take nine and
 * pass all of them. The argument types are not recovered. */
void FUN_000da720(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, bool argument7, void *argument8,
                  void *argument9); /* derived name */
void FUN_000ee260(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, bool argument7, void *argument8,
                  void *argument9); /* derived name */
void FUN_000f1ca0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, bool argument7, void *argument8,
                  void *argument9); /* derived name */
void FUN_00117280(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, bool argument7, void *argument8,
                  void *argument9); /* derived name */
void FUN_0012e7f0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, bool argument7, void *argument8,
                  void *argument9); /* derived name */
void FUN_000dcae0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_000f2d80(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_0011c290(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_001219f0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00123760(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_0012eda0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00136000(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_0014cd80(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00052380(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9, void *argument10); /* derived name */
void FUN_00052600(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9, void *argument10); /* derived name */
void FUN_00052880(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9, void *argument10); /* derived name */
void FUN_00052b00(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9, void *argument10); /* derived name */
void FUN_00052d80(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9, void *argument10); /* derived name */
void FUN_00056360(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00056580(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_000567a0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_000569c0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00056be0(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00056e00(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00056e30(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */
void FUN_00057050(void *argument1, void *argument2, void *argument3, void *argument4,
                  void *argument5, void *argument6, void *argument7, bool argument8,
                  void *argument9); /* derived name */

/* A 16-byte record of the array at +0xb8 of the object FUN_000657b0 sorts
 * (derived names): a pointer to an object with an int at +4, a 16-bit key
 * at +8 and a count at +0xc. FUN_00062100 is the order the sort
 * (FUN_00062130) is given: records with a count first, then by the int
 * the pointer reaches, then by the key. */
struct SortRecord00062100 /* derived name */
{
    struct Target {
        u8 unknown0[4];
        int order; /* derived name */
    };

    const Target *target; /* derived name */
    u16 key;              /* derived name */
    u8 unknownA[2];
    int count; /* derived name */
};

bool FUN_00062100(const SortRecord00062100 &a, const SortRecord00062100 &b); /* derived name */

/* Up to 16 points over the space splitters' base (derived names; vtable
 * 0x1699510, address point 0x1699520, stored by its constructor
 * FUN_00060c70): the world builds it in 0x170 bytes (0x4991f) when its
 * cinfo's byte at +0x50 is 1, and it is kind 1, whose cell is the nearest
 * point (FUN_00061060). A flag per point from +0x28 (the constructor clears
 * them) and the points from +0x70. Slot 3 (0x61280) moves every flagged
 * point by an offset. */
class FlaggedPoints00060c70 : public hknpSpaceSplitter /* derived name */
{
  public:
    /* Out of line (0x60c70): numPoints points on a grid four wide, 10 apart
     * (the rows also rise by 5), none flagged, and their pairs. */
    FlaggedPoints00060c70(int numPoints);

    virtual void FUN_00061280(const Vec4 &offset); /* vtable slot 3; derived name */

    /* The cell of a position, its nearest point (0x61060; the world's motion
     * update at 0xcd50a). derived name. */
    void FUN_00061060(const Vec4 &position, int *cellOut) const;

    /* New bodies spread over the points (0x611a0; the island activation
     * calls it for a splitter of kind 1 at 0x63bc8): the running total
     * raised, and as many points as the bodies' share of the points, at
     * most one per eight bodies, moved in turn from the least used one to
     * even steps along the box's diagonal, each given its share of the
     * bodies. derived name. */
    void FUN_000611a0(int numBodies, const hkAabb &aabb);

    int flags[16];   /* derived name */
    Vec4 points[16]; /* derived name */
};

/* Deleting destructors written as calls while their classes' destructors
 * are not (cookbook 15, 97): the base destructor, then the object back to
 * the thread's heap at its recorded size, the class's own by default. The
 * base destructors not declared elsewhere come first. derived names. */
void FUN_00023200(hkMemoryMeshBody *self);
void FUN_0002a9b0(hkMemoryMeshShape *self);
void FUN_00037c40(hknpMaskedShape *self);
void FUN_0004b040(hknpWorld *self);
void FUN_00087130(hkxMaterial *self);
void FUN_0008bf00(hkxMesh *self);
void FUN_0008c110(hkxNode *self);
void FUN_0008d2c0(hkxScene *self);
void FUN_0009b1c0(hkcdPlanarGeometry *self);
void FUN_0009c120(hkcdPlanarCsgOperand *self);
void FUN_000aa6d0(hkSkinnedRefMeshShape *self);
void FUN_001586d0(hknpCompressedMeshShape *self);
void FUN_0015bfa0(hknpWorldSnapshot *self);
void FUN_001625d0(hknpVehicleInstance *self);
void FUN_00165af0(hknpPhysicsSystemData *self);
void FUN_00166180(hknpExternMeshShape *self);
void FUN_00176b70(hknpCharacterProxy *self);
void FUN_0017b750(hkp6DofConstraintData *self);
void FUN_0017fc20(hkMemoryResourceContainer *self);

void FUN_000231b0(hkMemoryMeshBody *self);                 /* slot 1 of 0x1691600 */
void FUN_000234a0(hkIndexedTransformSet *self);            /* slot 1 of 0x1691760 */
void FUN_00024b80(hkMultipleVertexBuffer *self);           /* slot 1 of 0x1691ff0 */
void FUN_0002a960(hkMemoryMeshShape *self);                /* slot 1 of 0x1692530 */
void FUN_00033f40(hknpStaticCompoundShapeInternals *self); /* slot 1 of 0x1692830 */
void FUN_00034b30(hknpCompressedMeshShapeData *self);      /* slot 1 of 0x1692b00 */
void FUN_00037bf0(hknpMaskedShape *self);                  /* slot 1 of 0x1693a80 */
void FUN_0003b050(hknpDecoratorShape *self);               /* slot 1 of 0x16958d0 */
/* Also slot 1 of hknpConvexShape's vtable 0x1697d90 (one body for the
 * classes of 0x30 bytes, named for the sphere's constructor beside it,
 * 0x3c540; D15). */
void FUN_0003c370(hknpSphereShape *self);           /* slot 1 of 0x1695c10 */
void FUN_0004aff0(hknpWorld *self);                 /* slot 1 of 0x1699220 */
void FUN_0006b7d0(RefArrays0005a230 *self);         /* slot 1 of 0x169ab10 */
void FUN_000870e0(hkxMaterial *self);               /* slot 1 of 0x16a0db0 */
void FUN_00089330(hkxAttributeHolder *self);        /* slot 1 of 0x16a1670 */
void FUN_0008beb0(hkxMesh *self);                   /* slot 1 of 0x16a25a0 */
void FUN_0008c0c0(hkxNode *self);                   /* slot 1 of 0x16a25e0 */
void FUN_0008c940(hkxVertexAnimation *self);        /* slot 1 of 0x16a26c0 */
void FUN_0008d270(hkxScene *self);                  /* slot 1 of 0x16a2910 */
void FUN_0008dc00(hkxMeshSection *self);            /* slot 1 of 0x16a29d0 */
void FUN_0009b170(hkcdPlanarGeometry *self);        /* slot 1 of 0x16a36f0 */
void FUN_0009c0d0(hkcdPlanarCsgOperand *self);      /* slot 1 of 0x16a3730 */
void FUN_000aa680(hkSkinnedRefMeshShape *self);     /* slot 1 of 0x16a38b0 */
void FUN_000ad920(hkStorageSkinnedMeshShape *self); /* slot 1 of 0x16a3af0 */
void FUN_00157ea0(hknpBallGun *self);               /* slot 1 of 0x16a48d0 */
void FUN_00158680(hknpCompressedMeshShape *self);   /* slot 1 of 0x16a4990 */
void FUN_00159600(hknpProjectileGun *self);         /* slot 1 of 0x16a4b30 */
void FUN_0015bf50(hknpWorldSnapshot *self);         /* slot 1 of 0x16a4d50 */
void FUN_00162580(hknpVehicleInstance *self);       /* slot 1 of 0x16a5090 */
void FUN_00165aa0(hknpPhysicsSystemData *self);     /* slot 1 of 0x16a5130 */
void FUN_00166130(hknpExternMeshShape *self);       /* slot 1 of 0x16a5170 */
void FUN_0016a640(hknpScaledConvexShapeBase *self); /* slot 1 of 0x16a5390 */
void FUN_00176b20(hknpCharacterProxy *self);        /* slot 1 of 0x16a5b70 */
void FUN_0017b700(hkp6DofConstraintData *self);     /* slot 1 of 0x16a5d20 */
void FUN_0017fbd0(hkMemoryResourceContainer *self); /* slot 1 of 0x16a6300 */

/* An object the collide step 0x15c5f0 resets before its work (derived
 * names): 0x420 bytes, cleared to zero vectors when the thread's timer
 * stream has room, else every word set to one; the choice kept at +0x410
 * (FUN_0017a360). */
struct Object0017a360 /* derived name */
{
    void FUN_0017a360(bool timersEnabled); /* derived name */

    Vec4 unknown0[65];
    bool timersEnabled; /* derived name */
};

/* A constraint atom's solver setup (derived names): the parameters at
 * 0x17d430's first argument, the scales at its second, the result at its
 * third; the 0x50-byte schema of type 10 written at the stream position
 * and the position moved past it. */
struct SetupParams0017d430 /* derived name */
{
    float unknown0;
    float unknown4;
    float unknown8;
    float unknownc;
    float unknown10;
    float unknown14;
};

struct SetupScales0017d430 /* derived name */
{
    float unknown0;
    float unknown4;
    float unknown8;
};

struct SetupOut0017d430 /* derived name */
{
    u8 unknown0[0xc];
    float unknownc;
};

struct Schema0017d430 /* derived name */
{
    u8 type;
    u8 unknown1[0x2f];
    float unknown30;
    float unknown34;
    float unknown38;
    float unknown3c;
    float unknown40;
    u8 unknown44[0xc];
};

/* derived name: 0x17d430, called by the solver's setup at 0xcc9aa. */
void FUN_0017d430(const SetupParams0017d430 *params, const SetupScales0017d430 *scales,
                  SetupOut0017d430 *out, Schema0017d430 **schemaInOut);

/* What a loaded buffer of the thread's heap keeps at its end (derived
 * names): the number of objects to clean up in its last four bytes, after
 * that many records of an object's type info and the object. */
struct LoadedObjectRecord /* derived name */
{
    const hkTypeInfo *type; /* derived name */
    void *object;           /* derived name */
};

/* A loaded buffer given back (0x19bb80; the loader's 0x19a7c0 frees each of
 * its buffers with it): each recorded object cleaned up through its type
 * info, then the block freed; always 0. derived name. */
int FUN_0019bb80(void *buffer); /* derived name */

/* A convex shape's vertices as the ray cast against them reads them
 * (derived names): the first and their count, a convex shape's
 * hkRelArray<hkVector4> (0x435a0 passes hknpConvexShape's vertices). */
struct VertexView000a6d60 /* derived name */
{
    const Vec4 *vertices;
    int numVertices;
};

/* The support provider the ray cast 0x9fed0 asks for a shape's farthest
 * vertex along a direction (vtable 0x16a37f0, ruled by D14 from the 16-byte
 * object 0xa6d60 builds on its stack: an int 0 at +8, a byte 0x41 at +0xc;
 * slot 0 the empty 0x8c0a0, slot 1 the folded 16-byte delete 0x13e50).
 * derived names. */
class Collector000a6d60 /* derived name */
{
  public:
    Collector000a6d60() : unknown8(0), unknownC(0x41) {}

    virtual ~Collector000a6d60() {}

    /* Slot 2 (0xa1960): the vertex of the view whose dot product with the
     * direction is the largest, four at a time; the two vectors at the end
     * cleared. derived name. */
    virtual void FUN_000a1960(const VertexView000a6d60 *view, const Vec4 &direction,
                              const void *argument3, const void *argument4, Vec4 *vertexOut,
                              Vec4 *argument6, Vec4 *argument7) const;

    int unknown8; /* derived name */
    u8 unknownC;  /* derived name */
};

/* The working storage of the ray cast 0x9fed0, 0xc0 bytes it writes
 * before it reads (derived names). */
struct RayCastStorage0009fed0 /* derived name */
{
    Vec4 unknown[12];
};

/* Where the ray cast leaves a hit (derived names): the normal, then the
 * fraction along the ray, which comes in as the limit. */
struct RayHit000a6d60 /* derived name */
{
    Vec4 normal;
    Vec4 fraction;
};

/* A ray cast between two support providers and their data (0x9fed0, the
 * second's data null when it is a point): true when it hits within the
 * fraction, which it lowers, with the normal. derived name. */
bool FUN_0009fed0(RayCastStorage0009fed0 *storage, const Collector000a6d60 *shapeA,
                  const VertexView000a6d60 *dataA, const void *dataB, const void *ray,
                  const Collector000a6d60 *shapeB, Vec4 *fractionInOut, Vec4 *normalOut);

/* A ray cast against a set of vertices (0xa6d60): true when it hits with a
 * fraction other than zero. derived name. */
bool FUN_000a6d60(const Vec4 *vertices, int numVertices, const void *ray, RayHit000a6d60 *hit);

#endif
