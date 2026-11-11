/* src/include/tlg_game_object0134a660.h: the object whose fields the
 * accessors FUN_0134a390 to FUN_0134a6e0 read and write (each a slot of the
 * vtables at 0x16a7a50, 0x16a8260, 0x16ac218, 0x16ac3a8 and 13 more; the
 * accessors are written as free functions on it, one per file). The union of
 * the fields the 27 files named, each with the functions that show it.
 * derived names throughout. Where two files disagreed the bytes decide:
 * +0x4f4, +0x504, +0x508 and +0x50c are 32-bit words (FUN_0134a540,
 * FUN_0134a550, FUN_0134a560 and FUN_0134a570 store them with `mov dword`),
 * so +0x50c's 0x14 bytes are the word and 0x10 bytes not traced; +0x540's
 * 0xc bytes are the Names at +0x540, +0x544 and +0x548 (assigned by
 * FUN_0134a450, FUN_0134a580 and FUN_0134a5f0 through Name::operator=). */
#ifndef TLG_GAME_OBJECT0134A660_H
#define TLG_GAME_OBJECT0134A660_H

#include "tlg_types.h"
#include "tlg_game_name.h"

struct
    Value0134a530 { /* derived name: 8 bytes copied as one, alignment 4 (the field's offset); type not traced */
    u8 unknown0[8];
};

struct Object0134a660 { /* derived name */
    u8 unknown0[0x20];
    u8 unknown20; /* bit 4 set by FUN_0134a450, FUN_0134a540, FUN_0134a550, FUN_0134a560, FUN_0134a570, FUN_0134a670, FUN_0134a680 and FUN_0134a690 */
    u8 unknown21[0x22c - 0x21];
    int unknown22c; /* a count: decremented atomically by FUN_0134a3a0; its address passed to FUN_01331c10 by FUN_0134a390 */
    u8 unknown230[0x4f4 - 0x230];
    u32 unknown4f4; /* its address returned by FUN_0134a3e0, stored by FUN_0134a540; 32 bits wide, type not traced */
    u32 unknown4f8; /* bits returned by FUN_0134a660, stored by FUN_0134a670, set by FUN_0134a680 and cleared by FUN_0134a690 (each also sets bit 4 of the byte at +0x20) */
    Value0134a530 unknown4fc; /* its address returned by FUN_0134a3d0, copied in by FUN_0134a530 */
    u32 unknown504; /* its address returned by FUN_0134a3f0, stored by FUN_0134a550; 32 bits wide, type not traced */
    u32 unknown508; /* its address returned by FUN_0134a400, stored by FUN_0134a560; 32 bits wide, type not traced */
    u32 unknown50c; /* its address returned by FUN_0134a410, stored by FUN_0134a570; 32 bits wide, type and size not traced */
    u8 unknown510[0x520 - 0x510];
    u8 unknown520[0x10]; /* its address returned by FUN_0134a430; type not traced */
    u8 unknown530[0x10]; /* its address returned by FUN_0134a440; type not traced */
    Name name540;        /* its address returned by FUN_0134a3b0, assigned by FUN_0134a450 */
    Name name544;        /* assigned by FUN_0134a580 */
    Name name548;        /* assigned by FUN_0134a5f0 */
    Name name54c;        /* its address returned by FUN_0134a3c0, assigned by FUN_0134a4c0 */
    u32 unknown550; /* bits returned by FUN_0134a6a0, stored by FUN_0134a6b0, set by FUN_0134a6c0, cleared by FUN_0134a6d0 */
    u8 unknown554[0x558 - 0x554];
    u8 unknown558[4]; /* its address returned by FUN_0134a420; type and size not traced */
    u8 unknown55c[0x578 - 0x55c];
    float unknown578; /* returned by FUN_0134a6e0 */
};

#endif
