/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the handlers of a marker's events
 * "Marker.phy_SetIsUpdateBones_On.enter" and "..._Off.enter" (FUN_00a104a0
 * stores their addresses at 0xa10806 and 0xa1083d, each after the next
 * event's name, as FUN_00ad3090 does for leaf_00ad11a0.cpp's). The event
 * (never null here: no test, unlike leaf_00ad11a0.cpp's) names the object at +0x10; when this thread may use it and it is a node
 * of the type D_5939080 points to, its first component of the type
 * D_57db090 points to has the int at +0x4e14 set to 1 or 0. */
struct MarkerEvent00a104a0 { /* derived name */
    u8 unknown0[0x10];
    Name unknown10; /* +0x10: the object the event is about */
};

struct Component057db090 : Component00503fb0 /* derived name */
{
    u8 unknown8c[0x4d88];
    int updateBones; /* derived name: +0x4e14 */
};

extern Type00503fb0 *D_5939080; /* derived name: the node's type */
extern Type00503fb0 *D_57db090; /* derived name: the component's type */

/* the component on the node the event names, or null */
static inline Component00503fb0 *bonesComponent(MarkerEvent00a104a0 *event) /* derived name */
{
    Object016b85e0 *node = findNamed<Object016b85e0>(event->unknown10, D_5939080);
    if (!node)
        return 0;
    return node->findComponent(D_57db090);
}

void FUN_00a12360(
    MarkerEvent00a104a0 *event) /* derived name: "Marker.phy_SetIsUpdateBones_On.enter" */
{
    if (Component00503fb0 *component = bonesComponent(event))
        static_cast<Component057db090 *>(component)->updateBones = 1;
}

void FUN_00a12460(
    MarkerEvent00a104a0 *event) /* derived name: "Marker.phy_SetIsUpdateBones_Off.enter" */
{
    if (Component00503fb0 *component = bonesComponent(event))
        static_cast<Component057db090 *>(component)->updateBones = 0;
}
