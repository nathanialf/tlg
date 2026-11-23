/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* the type names, from the strings (each the whole name) */
extern const char D_15cb729[]; /* "Buffer" */
extern const char D_15c0541[]; /* "Color" */
extern const char D_15b5fb0[]; /* "Float" */
extern const char D_15b6081[]; /* "Mat4x4" */
extern const char D_15b6088[]; /* "Module" */
extern const char D_15c054e[]; /* "Object" */
extern const char D_15b608f[]; /* "Pod" */
extern const char D_15b6065[]; /* "Sint32" */
extern const char D_15b606c[]; /* "Sint64" */
extern const char D_15c0547[]; /* "String" */
extern const char D_15b6073[]; /* "Uint32" */
extern const char D_15b607a[]; /* "Uint64" */
extern const char D_15c052b[]; /* "Vec2" */
extern const char D_15c0530[]; /* "Vec3" */
extern const char D_15c0535[]; /* "Vec4" */

/* derived names: the type a name gives (FUN_00c6aff0 and FUN_00c6e800 call
 * it): the names compared without case after a switch on the first letter,
 * "Pod" as a prefix of three letters; -1 for a name that is none of them */
enum ValueType00d0d850 { /* derived name */
                         VALUE_SINT32 = 0,
                         VALUE_UINT32 = 1,
                         VALUE_SINT64 = 2,
                         VALUE_UINT64 = 3,
                         VALUE_FLOAT = 4,
                         VALUE_VEC2 = 5,
                         VALUE_VEC3 = 6,
                         VALUE_VEC4 = 7,
                         VALUE_MAT4X4 = 8,
                         VALUE_COLOR = 9,
                         VALUE_STRING = 10,
                         VALUE_BUFFER = 11,
                         VALUE_OBJECT = 12,
                         VALUE_MODULE = 13,
                         VALUE_POD = 14,
                         VALUE_NONE = -1
};

int FUN_00d0d850(const char *name) /* derived name */
{
    switch (name[0]) {
    case 'B':
        if (!strcasecmp(D_15cb729, name))
            return VALUE_BUFFER;
        break;
    case 'C':
        if (!strcasecmp(D_15c0541, name))
            return VALUE_COLOR;
        break;
    case 'F':
        if (!strcasecmp(D_15b5fb0, name))
            return VALUE_FLOAT;
        break;
    case 'M':
        if (!strcasecmp(D_15b6081, name))
            return VALUE_MAT4X4;
        if (!strcasecmp(D_15b6088, name))
            return VALUE_MODULE;
        break;
    case 'O':
        if (!strcasecmp(D_15c054e, name))
            return VALUE_OBJECT;
        break;
    case 'P':
        if (!strncmp(name, D_15b608f, 3))
            return VALUE_POD;
        break;
    case 'S':
        if (!strcasecmp(D_15b6065, name))
            return VALUE_SINT32;
        if (!strcasecmp(D_15b606c, name))
            return VALUE_SINT64;
        if (!strcasecmp(D_15c0547, name))
            return VALUE_STRING;
        break;
    case 'U':
        if (!strcasecmp(D_15b6073, name))
            return VALUE_UINT32;
        if (!strcasecmp(D_15b607a, name))
            return VALUE_UINT64;
        break;
    case 'V':
        if (!strcasecmp(D_15c052b, name))
            return VALUE_VEC2;
        if (!strcasecmp(D_15c0530, name))
            return VALUE_VEC3;
        if (!strcasecmp(D_15c0535, name))
            return VALUE_VEC4;
        break;
    }
    return VALUE_NONE;
}
