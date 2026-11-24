/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the handlers of a marker's events "Marker.s_Allow_Push",
 * "Marker.s_AllowExploreSlope", "Marker.s_RequestGazeTarget" and
 * "Marker.s_RequestGazeTarget_Weak", each with its .enter and .leave
 * (FUN_00ad3090 stores each handler's address after its name's hash, lea
 * at 0xad3f04 to 0xad4070). The event names the object at +0x10; when this
 * thread may use it and it is a node of the type D_5939080 points to (or
 * one derived from it), the node's first component of the type D_57d4a68
 * points to is looked up and its flag at +0xa74 (Allow_Push) or +0xa70
 * (AllowExploreSlope) set on enter and cleared on leave; the gaze target
 * handlers look the component up and change nothing. The same table's
 * s_CaptureVolume, s_CaptureUpVolume and s_CaptureDownVolume handlers set
 * and clear bits 0 to 2 of the byte at +0x46c, the s_Pickup ones the bool
 * at +0x487 (stored at 0xad3826 to 0xad3aca, each after the next event's
 * name). */
struct MarkerEvent00ad3090 { /* derived name */
    u8 unknown0[0x10];
    Name unknown10; /* +0x10: the object the event is about */
    Name
        unknown14; /* +0x14: a second name (0xad06d0 adds it to the component's, through FUN_01344a20) */
};

/* the part at +0x348 of the component (FUN_00ace8e0, FUN_00acf290) */
struct Part057d4a68_348 { /* derived name */
    u8 unknown0[0x40];
    int unknown40; /* +0x40: 1 and 0 (FUN_00ace8e0, FUN_00ace9e0) */
    u8 unknown44[0x24];
    int unknown68;     /* +0x68 */
    Float4A unknown70; /* +0x70: zero with the int at +0x68 (FUN_00acf290) */
};

/* the object at +0x238 of the part at +0xd68: its node at +0x38 */
struct Holder057d4a68_d68_238 { /* derived name */
    u8 unknown0[0x38];
    Object016b85e0 *node; /* +0x38 */
};

struct Part057d4a68_d68 { /* derived name */
    u8 unknown0[0x238];
    Holder057d4a68_d68_238 *unknown238; /* +0x238 */
};

struct Component057d4a68 : Component00503fb0 /* derived name */
{
    u8 unknown8c[0x4c];
    Array05943280<Name> namesd8; /* +0xd8: 0xad06d0 adds the event's second name */
    u8 unknownf0[0x258];
    Part057d4a68_348 *part348; /* +0x348 */
    u8 unknown350[0x11c];
    /* +0x46c: bit 0 inside a capture volume, bit 1 an up one, bit 2 a down
     * one (the s_CaptureVolume, s_CaptureUpVolume and s_CaptureDownVolume
     * events: `or byte` and `and byte` at 0xace281 to 0xace781) */
    u8 captureVolumes; /* derived name */
    u8 unknown46d[0x13];
    int unknown480; /* +0x480: FUN_00ace7a0 acts for 1 to 5 */
    u8 unknown484[0x3];
    bool pickup;   /* derived name: +0x487, the s_Pickup events */
    u8 unknown488; /* +0x488: cleared by FUN_00acfd10 */
    u8 unknown489[0x4b];
    float unknown4d4; /* +0x4d4: a time (FUN_00ad0020, FUN_00ad0150) */
    u8 unknown4d8[0x570];
    int unknowna48;        /* +0xa48 */
    float unknowna4c;      /* +0xa4c */
    int unknowna50;        /* +0xa50 */
    int unknowna54;        /* +0xa54 */
    int unknowna58;        /* +0xa58 */
    int unknowna5c;        /* +0xa5c */
    int unknowna60;        /* +0xa60 */
    int unknowna64;        /* +0xa64 */
    int unknowna68;        /* +0xa68 */
    int unknowna6c;        /* +0xa6c */
    int allowExploreSlope; /* derived name: +0xa70 */
    int allowPush;         /* derived name: +0xa74 */
    u8 unknowna78[0x2f0];
    Part057d4a68_d68 *partd68; /* +0xd68 */

    /* the values from +0xa48 on reset (FUN_00ad1050: the four ints from
     * +0xa64 stored as one 16-byte zero) */
    void resetA48() /* derived name */
    {
        unknowna48 = 0;
        unknowna50 = -1;
        unknowna4c = -HUGE_VALF;
        unknowna54 = -1;
        unknowna58 = -1;
        unknowna60 = -1;
        unknowna64 = 0;
        unknowna68 = 0;
        unknowna6c = 0;
        allowExploreSlope = 0;
    }
};

extern Type00503fb0 *D_5939080; /* derived name: the node's type */
extern Type00503fb0 *D_57d4a68; /* derived name: the component's type */

/* the component of the type D_57d4a68 points to on the node the event
 * names, or null; a handler that stores tests it before its cast (the
 * found component's register: round 569D). The type is read here, after
 * the node's lookup (a parameter loads it before: round 569D) */
static inline Component00503fb0 *markerComponent(MarkerEvent00ad3090 *event) /* derived name */
{
    Object016b85e0 *node = findNamed<Object016b85e0>(event->unknown10, D_5939080);
    if (!node)
        return 0;
    return node->findComponent(D_57d4a68);
}

void FUN_00ad11a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_Allow_Push.enter" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->allowPush = 1;
    }
}

void FUN_00ad12a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_Allow_Push.leave" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->allowPush = 0;
    }
}

void FUN_00ad13a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_AllowExploreSlope.enter" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->allowExploreSlope = 1;
    }
}

void FUN_00ad14a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_AllowExploreSlope.leave" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->allowExploreSlope = 0;
    }
}

void FUN_00ad15a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_RequestGazeTarget.enter" */
{
    if (event)
        markerComponent(event);
}

void FUN_00ad1690(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_RequestGazeTarget.leave" */
{
    if (event)
        markerComponent(event);
}

void FUN_00ad1780(
    MarkerEvent00ad3090 *event) /* derived name: "Marker.s_RequestGazeTarget_Weak.enter" */
{
    if (event)
        markerComponent(event);
}

void FUN_00ad1870(
    MarkerEvent00ad3090 *event) /* derived name: "Marker.s_RequestGazeTarget_Weak.leave" */
{
    if (event)
        markerComponent(event);
}

void FUN_00ace1a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_CaptureVolume.enter" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->captureVolumes |= 1;
    }
}

void FUN_00ace2a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_CaptureVolume.leave" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->captureVolumes &= ~1;
    }
}

void FUN_00ace3a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_CaptureUpVolume.enter" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->captureVolumes |= 2;
    }
}

void FUN_00ace4a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_CaptureUpVolume.leave" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->captureVolumes &= ~2;
    }
}

void FUN_00ace5a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_CaptureDownVolume.enter" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->captureVolumes |= 4;
    }
}

void FUN_00ace6a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_CaptureDownVolume.leave" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->captureVolumes &= ~4;
    }
}

void FUN_00acef90(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_Pickup.enter" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->pickup = true;
    }
}

void FUN_00acf090(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_Pickup.leave" */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->pickup = false;
    }
}

/* derived names: the trophy counters of the same table (lea at 0xad43c8 and
 * 0xad43fc): the count at +0xb4 or +0xb8 of the record at +0x30 of the
 * perpetual data (+0x108 of the object at 0x57c9390) is raised; at the
 * threshold the record FUN_00a285e0 returns holds (+0x34, +0x40) the trophy
 * is unlocked (FUN_00cb5f90, as the script's "UnlockTrophy" does); the
 * progress is reported (FUN_00a1cd10) and the data saved (FUN_00a26130, as
 * "SavePerpetual" does). */
struct Counts00ad2cf0 { /* derived name */
    u8 unknown0[0xb4];
    int helmetsPulledOff; /* +0xb4, derived name */
    int pulseDefeats;     /* +0xb8, derived name */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x30];
    Counts00ad2cf0 *counts; /* +0x30, derived name */
};

/* the record at +0x900 of the record at +0x38: the time at +0x44
 * (FUN_00ad0020, FUN_00ad0150) */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x44];
    float unknown44; /* +0x44 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
    u8 unknown40[0xc8];
    Member057c9390_108 *unknown108;
};

struct Thresholds00a285e0 { /* derived name */
    u8 unknown0[0x34];
    int helmetsPulledOff; /* +0x34, derived name */
    u8 unknown38[0x8];
    int pulseDefeats; /* +0x40, derived name */
};

struct Member05938c40_f68; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf68];
    Member05938c40_f68 *unknownf68;
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

Thresholds00a285e0 *FUN_00a285e0();                              /* derived name */
void FUN_00cb5f90(Member05938c40_f68 *member, const char *name); /* derived name */
void FUN_00a1cd10(const char *name, int progress);               /* derived name */
void FUN_00a26130(Member057c9390_108 *member);                   /* derived name */

void FUN_00ad2cf0(MarkerEvent00ad3090 *) /* derived name */
{
    Counts00ad2cf0 *counts = D_57c9390->unknown108->counts;
    int count = ++counts->helmetsPulledOff;
    if (count >= FUN_00a285e0()->helmetsPulledOff)
        FUN_00cb5f90(D_5938c40->unknownf68, "TROPHY_Pull_off_Soldier_Helmet");
    FUN_00a1cd10("TROPHY_Pull_off_Soldier_Helmet", counts->helmetsPulledOff);
    FUN_00a26130(D_57c9390->unknown108);
}

void FUN_00ad2d70(MarkerEvent00ad3090 *) /* derived name */
{
    Counts00ad2cf0 *counts = D_57c9390->unknown108->counts;
    int count = ++counts->pulseDefeats;
    if (count >= FUN_00a285e0()->pulseDefeats)
        FUN_00cb5f90(D_5938c40->unknownf68, "TROPHY_Pulse_Soldier_Defeat");
    FUN_00a1cd10("TROPHY_Pulse_Soldier_Defeat", counts->pulseDefeats);
    FUN_00a26130(D_57c9390->unknown108);
}

/* derived names: the handlers of the same table found by their shape (the
 * component of the type D_57d4a68 points to on the node the event names);
 * their events' names are not traced. */
struct
    Value00ad1960 { /* derived name: the int at +0x44 of the component of the type D_57d5968 points to */
    u8 unknown0[0x44];
    int unknown44;
};

/* the component of the type D_5945fa0 points to: an int at +0x58 whose
 * change is marked in bit 0 of the flags at +0x20 */
struct Value00acfd10 { /* derived name */
    u8 unknown0[0x20];
    int flags; /* +0x20 */
    u8 unknown24[0x34];
    int unknown58; /* +0x58 */

    void set58(int value) /* derived name */
    {
        unknown58 = value;
        flags |= 1;
    }
};

extern Type00503fb0 *D_57d5968; /* derived name */
extern Type00503fb0 *D_5945fa0; /* derived name */
extern const Name D_57d6b9c;    /* derived name */
extern const Name D_57d6b8c;    /* derived name */

void FUN_004a6bf0(const Name &first, const Name &second, const Name &third); /* derived name */

void FUN_00ace8e0(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->part348->unknown40 = 1;
    }
}

void FUN_00ace9e0(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->part348->unknown40 = 0;
    }
}

void FUN_00acf290(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event)) {
            Part057d4a68_348 *part = static_cast<Component057d4a68 *>(component)->part348;
            part->unknown68 = 0;
            part->unknown70.set(0, 0, 0, 0);
        }
    }
}

void FUN_00ad1960(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event)) {
            if (Object016b85e0 *node = component->node) {
                if (Component00503fb0 *other = node->component(D_57d5968))
                    reinterpret_cast<Value00ad1960 *>(other)->unknown44 = 0;
            }
        }
    }
}

// NONMATCHING: the second search's registers: the base finds into rcx with the counter in edx
// (0xacfe3c), this build rdx and ecx; casting before the null test changes nothing (round 573D)
void FUN_00acfd10(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *found = markerComponent(event)) {
            Component057d4a68 *component = static_cast<Component057d4a68 *>(found);
            Object016b85e0 *node = component->partd68->unknown238->node;
            if (Value00acfd10 *other =
                    reinterpret_cast<Value00acfd10 *>(node->component(D_5945fa0)))
                other->set58(1);
            component->unknown488 = 0;
        }
    }
}

// NONMATCHING: FUN_00acfd10's residual (the second search's registers)
void FUN_00acfea0(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *found = markerComponent(event)) {
            Component057d4a68 *component = static_cast<Component057d4a68 *>(found);
            Object016b85e0 *node = component->partd68->unknown238->node;
            if (Value00acfd10 *other =
                    reinterpret_cast<Value00acfd10 *>(node->component(D_5945fa0)))
                other->set58(0);
        }
    }
}

void FUN_00ace7a0(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *found = markerComponent(event)) {
            Component057d4a68 *component = static_cast<Component057d4a68 *>(found);
            if (unsigned(component->unknown480 - 1) <= 4) {
                if (Object016b85e0 *node = component->node)
                    FUN_004a6bf0(D_57d6b9c, D_57d6b8c, node->name);
            }
        }
    }
}

void FUN_00ad1050(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->resetA48();
    }
}

void FUN_00ad0020(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->unknown4d4 =
                D_57c9390->unknown38->unknown900->unknown44 + 4.0f;
    }
}

void FUN_00ad0150(MarkerEvent00ad3090 *event) /* derived name */
{
    if (event) {
        if (Component00503fb0 *component = markerComponent(event))
            static_cast<Component057d4a68 *>(component)->unknown4d4 =
                D_57c9390->unknown38->unknown900->unknown44 + 4.0f;
    }
}
