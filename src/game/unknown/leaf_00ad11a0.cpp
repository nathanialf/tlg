/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the handlers of a marker's events "Marker.s_Allow_Push",
 * "Marker.s_AllowExploreSlope", "Marker.s_RequestGazeTarget" and
 * "Marker.s_RequestGazeTarget_Weak", each with its .enter and .leave
 * (FUN_00ad3090 stores each handler's address after its name's hash, lea
 * at 0xad3f04 to 0xad4070). The event names the object at +0x10; when this
 * thread may use it and it is a node of the type D_5939080 points to (or
 * one derived from it), the node's first component of the type D_57d4a68
 * points to is looked up and its flag at +0xa74 (Allow_Push) or +0xa70
 * (AllowExploreSlope) set on enter and cleared on leave; the gaze target
 * handlers look the component up and change nothing. */
struct MarkerEvent00ad3090 { /* derived name */
    u8 unknown0[0x10];
    Name unknown10; /* +0x10: the object the event is about */
};

struct Component057d4a68 : Component00503fb0 /* derived name */
{
    u8 unknown8c[0x9e4];
    int allowExploreSlope; /* derived name: +0xa70 */
    int allowPush;         /* derived name: +0xa74 */
};

extern Type00503fb0 *D_5939080; /* derived name: the node's type */
extern Type00503fb0 *D_57d4a68; /* derived name: the component's type */

/* the component of the type D_57d4a68 points to on the node the event
 * names, or null */
static inline Component057d4a68 *markerComponent(MarkerEvent00ad3090 *event) /* derived name */
{
    Node00503fb0 *node = findNamed<Node00503fb0>(event->unknown10, D_5939080);
    if (!node)
        return 0;
    return static_cast<Component057d4a68 *>(node->findComponent(D_57d4a68));
}

// NONMATCHING: 45/73 (the four that store; the four gaze handlers are equal). The component's
// search: the base reloads the array at +0x58 in each pass and keeps one release of the readers
// with the found component (or 0) tested after it; the build hoists the array and releases twice,
// the not-found path straight to the return (JumpThreading through the release block).
void FUN_00ad11a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_Allow_Push.enter" */
{
    if (event) {
        if (Component057d4a68 *component = markerComponent(event))
            component->allowPush = 1;
    }
}

void FUN_00ad12a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_Allow_Push.leave" */
{
    if (event) {
        if (Component057d4a68 *component = markerComponent(event))
            component->allowPush = 0;
    }
}

void FUN_00ad13a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_AllowExploreSlope.enter" */
{
    if (event) {
        if (Component057d4a68 *component = markerComponent(event))
            component->allowExploreSlope = 1;
    }
}

void FUN_00ad14a0(MarkerEvent00ad3090 *event) /* derived name: "Marker.s_AllowExploreSlope.leave" */
{
    if (event) {
        if (Component057d4a68 *component = markerComponent(event))
            component->allowExploreSlope = 0;
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

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
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
