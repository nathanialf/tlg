/* Havok Script: pushing a C string, as the game's script C functions inline
 * it (0xe70540 "GetDataPath", 0xa45c20 "Sound_GetCSV", 0x1b58b0). */
#ifndef TLG_HKS_STRING_H
#define TLG_HKS_STRING_H

#include "tlg_hks.h"

/* derived name: the string of the VM's table for a text of known length and
 * hash, made when there is none (FUN_00db9de0) */
void *FUN_00db9de0(lua_State *state, const char *text, size_t length, u32 hash);

/* Bob Jenkins' lookup3 mixing steps (its mix() and final()) */
#define HKS_ROT(x, k) (((x) << (k)) | ((x) >> (32 - (k))))
#define HKS_MIX(a, b, c)                                                                           \
    {                                                                                              \
        a -= c;                                                                                    \
        a ^= HKS_ROT(c, 4);                                                                        \
        c += b;                                                                                    \
        b -= a;                                                                                    \
        b ^= HKS_ROT(a, 6);                                                                        \
        a += c;                                                                                    \
        c -= b;                                                                                    \
        c ^= HKS_ROT(b, 8);                                                                        \
        b += a;                                                                                    \
        a -= c;                                                                                    \
        a ^= HKS_ROT(c, 16);                                                                       \
        c += b;                                                                                    \
        b -= a;                                                                                    \
        b ^= HKS_ROT(a, 19);                                                                       \
        a += c;                                                                                    \
        c -= b;                                                                                    \
        c ^= HKS_ROT(b, 4);                                                                        \
        b += a;                                                                                    \
    }
#define HKS_FINAL(a, b, c)                                                                         \
    {                                                                                              \
        c ^= b;                                                                                    \
        c -= HKS_ROT(b, 14);                                                                       \
        a ^= c;                                                                                    \
        a -= HKS_ROT(c, 11);                                                                       \
        b ^= a;                                                                                    \
        b -= HKS_ROT(a, 25);                                                                       \
        c ^= b;                                                                                    \
        c -= HKS_ROT(b, 16);                                                                       \
        a ^= c;                                                                                    \
        a -= HKS_ROT(c, 4);                                                                        \
        b ^= a;                                                                                    \
        b -= HKS_ROT(a, 14);                                                                       \
        c ^= b;                                                                                    \
        c -= HKS_ROT(b, 24);                                                                       \
    }

/* derived name: the hash of a string's text, the key of the VM's string
 * table: lookup3 over the first 31 characters at most, seeded with the
 * whole length, whole words read as they lie and a last partial word's
 * characters from the high byte down (lookup3's hashbig); the empty string's
 * is the seed (0xdd41f0 passes 0x6b6f7265, 0xde9960 "file (closed)"'s
 * 0x377b9582). Inlined by the VM's string pushes (0x13aacc0, 0x13aa820,
 * 0xd94bc0, 0xdb6b20 and others). */
inline u32 hashString(const char *text, size_t length)
{
    u32 a, b, c;
    a = b = c = 0x6b6f7265 + u32(length);
    const u32 *k = reinterpret_cast<const u32 *>(text);
    size_t remaining = length < 31 ? length : 31;
    /* at most two whole blocks of twelve in 31 characters */
    if (remaining > 12) {
        a += k[0];
        b += k[1];
        c += k[2];
        HKS_MIX(a, b, c);
        remaining -= 12;
        k += 3;
        if (remaining > 12) {
            a += k[0];
            b += k[1];
            c += k[2];
            HKS_MIX(a, b, c);
            remaining -= 12;
            k += 3;
        }
    }
    const u8 *k8 = reinterpret_cast<const u8 *>(k);
    switch (remaining) {
    case 12:
        c += k[2];
        b += k[1];
        a += k[0];
        break;
    case 11:
        c += u32(k8[10]) << 8;
    case 10:
        c += u32(k8[9]) << 16;
    case 9:
        c += u32(k8[8]) << 24;
    case 8:
        b += k[1];
        a += k[0];
        break;
    case 7:
        b += u32(k8[6]) << 8;
    case 6:
        b += u32(k8[5]) << 16;
    case 5:
        b += u32(k8[4]) << 24;
    case 4:
        a += k[0];
        break;
    case 3:
        a += u32(k8[2]) << 8;
    case 2:
        a += u32(k8[1]) << 16;
    case 1:
        a += u32(k8[0]) << 24;
        break;
    case 0:
        return c;
    }
    HKS_FINAL(a, b, c);
    return c;
}

/* derived name: pushes a string of a given length (FUN_013aacc0; Lua's
 * lua_pushlstring by its arguments) */
void FUN_013aacc0(lua_State *state, const char *string, size_t length);

/* derived name: lua_pushstring as Lua writes it: nil (tag 0) on the stack's
 * top for a null string, else the string with its length from strlen */
inline void pushString(lua_State *state, const char *string)
{
    if (string == 0) {
        HksObject *top = state->top;
        top->type = 0;
        state->top = top + 1;
    } else {
        FUN_013aacc0(state, string, strlen(string));
    }
}

#endif
