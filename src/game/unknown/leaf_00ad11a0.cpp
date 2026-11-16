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
static Component057d4a68 *markerComponent(MarkerEvent00ad3090 *event) /* derived name */
{
    Node00503fb0 *node = findNamed<Node00503fb0>(event->unknown10, D_5939080);
    if (!node)
        return 0;
    return static_cast<Component057d4a68 *>(node->findComponent(D_57d4a68));
}

// NONMATCHING: cookbook 1704/2127 shape B of the thread flag (base `movzx r14d, word [r15+0x16]` above the flag's address, `mov al, [rax]; xor al, 1; test al, 1`; build `test byte [r15+0x16], 4` and `test byte [rax], 1; je`), the same in all eight
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
