/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: one step of the bodies three simulations move, each in
 * four copies of one template by a kind (the parameter does not change the
 * code): FUN_00b420f0, FUN_00b42220, FUN_00b42350, FUN_00b42480 (bodies of
 * one point, the four-case jump table at 0x1398057 by the kind at +0x94 of
 * the object), FUN_00b419b0 to FUN_00b41f20 (two points, the table at
 * 0x13985f3) and FUN_00b425b0 to FUN_00b42c10 (two points and a third
 * velocity, the table at 0x1397ec7). Each body named by the lists of the
 * group's cells (the list the group's current index does not name) has the
 * velocity of each point damped by that point's damping raised to `steps`,
 * then the point moves by its velocity plus its gravity scaled by the body's
 * own parameter, times `dt`. The classes are not traced beyond the fields
 * read here. */
/* a point of a body: its position and its velocity */
struct Point00b420f0 { /* derived name */
    float x;           /* +0x0 */
    float y;           /* +0x4 */
    float vx;          /* +0x8 */
    float vy;          /* +0xc */
};

struct Body00b420f0 { /* derived name */
    u8 unknown0[0xc];
    Point00b420f0 point; /* +0xc */
};

struct Body00b419b0 { /* derived name */
    u8 unknown0[0xc];
    Point00b420f0 points[2]; /* +0xc, +0x1c */
};

struct Body00b425b0 { /* derived name */
    u8 unknown0[0xc];
    Point00b420f0 points[2]; /* +0xc, +0x1c */
    u8 unknown2c[8];
    Point00b420f0 third; /* +0x34: only its velocity is damped */
};

template <class Body> struct BodyArray00b420f0 { /* derived name */
    u8 unknown0[0x10];
    Body *bodies; /* +0x10 */
};

struct BodyParameters00b420f0 { /* derived name */
    u8 unknown0[0x324];
    float gravityScale; /* +0x324 */
    u8 unknown328[0x38];
};

struct ParameterArray00b420f0 { /* derived name */
    u8 unknown0[0x10];
    BodyParameters00b420f0 *parameters; /* +0x10 */
};

struct IdList00b420f0 { /* derived name */
    u32 *ids;           /* +0x0 */
    u32 count;          /* +0x8 */
    u8 unknownc[0xc];
};

struct Cell00b420f0 {        /* derived name */
    IdList00b420f0 lists[2]; /* +0x0, +0x18 */
    u8 unknown30[0x10];
};

struct Group00b420f0 { /* derived name */
    u8 unknown0[0x10];
    u32 current; /* +0x10 */
    u8 unknown14[4];
    ParameterArray00b420f0 *parameters; /* +0x18 */
    Cell00b420f0 *cells;                /* +0x20 */
    u32 cellCount;                      /* +0x28 */

    Cell00b420f0 &cellAt(int index)
    {
        return cells[index];
    }
};

/* the velocity damped, then the point moved by it and the gravity scaled by
 * the body's parameter (read after the velocity is stored) */
static inline void movePoint(Point00b420f0 &point, float decay, float gravityX, float gravityY,
                             const BodyParameters00b420f0 &parameters, float dt) /* derived name */
{
    float vx = point.vx * decay;
    point.vx = vx;
    float vy = point.vy * decay;
    point.vy = vy;
    float scale = parameters.gravityScale;
    float dx = (vx + gravityX * scale) * dt;
    float dy = (vy + gravityY * scale) * dt;
    point.x += dx;
    point.y += dy;
}

template <int Kind> class Simulation00b420f0 /* derived name */
{
  public:
    void step(float dt, float steps);

  private:
    u8 unknown0[0x20];
    Group00b420f0 *group; /* +0x20 */
    u8 unknown28[8];
    BodyArray00b420f0<Body00b420f0> *bodies; /* +0x30 */
    u8 unknown38[0x8c];
    float gravityX; /* +0xc4 */
    float gravityY; /* +0xc8 */
    u8 unknowncc[0x10];
    float damping;         /* +0xdc */
    float gravityStrength; /* +0xe0 */
};

template <int Kind> void Simulation00b420f0<Kind>::step(float dt, float steps)
{
    Body00b420f0 *bodies = this->bodies->bodies;
    if (!bodies)
        return;
    BodyParameters00b420f0 *parameters = group->parameters->parameters;
    float decay = powf(damping, steps);
    u32 cellCount = group->cellCount;
    if (cellCount == 0)
        return;
    float gravityX = gravityStrength * this->gravityX;
    float gravityY = gravityStrength * this->gravityY;
    for (u32 i = 0; i < cellCount; ++i) {
        const IdList00b420f0 &list = group->cellAt(i).lists[group->current ^ 1];
        u32 count = list.count;
        const u32 *ids = list.ids;
        for (u32 j = 0; j < count; ++j) {
            u32 id = ids[j];
            movePoint(bodies[id].point, decay, gravityX, gravityY, parameters[id], dt);
        }
    }
}

template class Simulation00b420f0<0>;
template class Simulation00b420f0<1>;
template class Simulation00b420f0<2>;
template class Simulation00b420f0<3>;

/* the same over bodies of two points, each with its damping and gravity */
template <int Kind> class Simulation00b419b0 /* derived name */
{
  public:
    void step(float dt, float steps);

  private:
    u8 unknown0[0x20];
    Group00b420f0 *group; /* +0x20 */
    u8 unknown28[8];
    BodyArray00b420f0<Body00b419b0> *bodies; /* +0x30 */
    u8 unknown38[0x8c];
    float gravityX; /* +0xc4 */
    float gravityY; /* +0xc8 */
    u8 unknowncc[0x10];
    float damping;         /* +0xdc */
    float gravityStrength; /* +0xe0 */
    u8 unknowne4[0x14];
    float gravity2X; /* +0xf8 */
    float gravity2Y; /* +0xfc */
    u8 unknown100[0x10];
    float damping2;         /* +0x110 */
    float gravity2Strength; /* +0x114 */
};

template <int Kind> void Simulation00b419b0<Kind>::step(float dt, float steps)
{
    Body00b419b0 *bodies = this->bodies->bodies;
    if (!bodies)
        return;
    BodyParameters00b420f0 *parameters = group->parameters->parameters;
    float decay = powf(damping, steps);
    float decay2 = powf(damping2, steps);
    u32 cellCount = group->cellCount;
    if (cellCount == 0)
        return;
    float gravityX = gravityStrength * this->gravityX;
    float gravityY = gravityStrength * this->gravityY;
    float gravity2X = gravity2Strength * this->gravity2X;
    float gravity2Y = gravity2Strength * this->gravity2Y;
    for (u32 i = 0; i < cellCount; ++i) {
        const IdList00b420f0 &list = group->cellAt(i).lists[group->current ^ 1];
        u32 count = list.count;
        const u32 *ids = list.ids;
        for (u32 j = 0; j < count; ++j) {
            u32 id = ids[j];
            Body00b419b0 &body = bodies[id];
            movePoint(body.points[0], decay, gravityX, gravityY, parameters[id], dt);
            movePoint(body.points[1], decay2, gravity2X, gravity2Y, parameters[id], dt);
        }
    }
}

template class Simulation00b419b0<0>;
template class Simulation00b419b0<1>;
template class Simulation00b419b0<2>;
template class Simulation00b419b0<3>;

/* the same over bodies of two points and a third velocity, damped alone */
template <int Kind> class Simulation00b425b0 /* derived name */
{
  public:
    void step(float dt, float steps);

  private:
    u8 unknown0[0x20];
    Group00b420f0 *group; /* +0x20 */
    u8 unknown28[8];
    BodyArray00b420f0<Body00b425b0> *bodies; /* +0x30 */
    u8 unknown38[0x8c];
    float gravityX; /* +0xc4 */
    float gravityY; /* +0xc8 */
    u8 unknowncc[0x10];
    float damping;         /* +0xdc */
    float gravityStrength; /* +0xe0 */
    u8 unknowne4[0x14];
    float gravity2X; /* +0xf8 */
    float gravity2Y; /* +0xfc */
    u8 unknown100[0x10];
    float damping2;         /* +0x110 */
    float gravity2Strength; /* +0x114 */
    u8 unknown118[0x20];
    float damping3; /* +0x138 */
};

template <int Kind> void Simulation00b425b0<Kind>::step(float dt, float steps)
{
    Body00b425b0 *bodies = this->bodies->bodies;
    if (!bodies)
        return;
    BodyParameters00b420f0 *parameters = group->parameters->parameters;
    float decay = powf(damping, steps);
    float decay2 = powf(damping2, steps);
    float gravityX = gravityStrength * this->gravityX;
    float gravityY = gravityStrength * this->gravityY;
    float gravity2X = gravity2Strength * this->gravity2X;
    float gravity2Y = gravity2Strength * this->gravity2Y;
    float decay3 = powf(damping3, steps);
    u32 cellCount = group->cellCount;
    for (u32 i = 0; i < cellCount; ++i) {
        const IdList00b420f0 &list = group->cellAt(i).lists[group->current ^ 1];
        u32 count = list.count;
        const u32 *ids = list.ids;
        for (u32 j = 0; j < count; ++j) {
            u32 id = ids[j];
            Body00b425b0 &body = bodies[id];
            movePoint(body.points[0], decay, gravityX, gravityY, parameters[id], dt);
            movePoint(body.points[1], decay2, gravity2X, gravity2Y, parameters[id], dt);
            body.third.vx *= decay3;
            body.third.vy *= decay3;
        }
    }
}

template class Simulation00b425b0<0>;
template class Simulation00b425b0<1>;
template class Simulation00b425b0<2>;
template class Simulation00b425b0<3>;
