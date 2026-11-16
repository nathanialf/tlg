/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: FUN_00b100a0 sets and FUN_00b100b0 clears the file's own flag at
 * 0x58325e9 (direct RIP-relative stores: internal linkage, docs/DECISIONS.md D17);
 * FUN_00b100c0 beside them reads it. FUN_00b10ec0, the file's initializer, stores
 * the three addresses (lea at 0xb1171f, 0xb1173c and 0xb117eb), each followed by a zero
 * 8-byte word (pointers to member functions, the adjustment 0), in the
 * descriptor whose int at 0x5831eb0 holds a FUN_013baad0 id. The three take the
 * object in rdi; the setters do not use it. Owner and meaning unknown. */
struct Object00b100c0 { /* derived name */
    u8 unknown0[0x74];
    int unknown74;
};

/* derived names: a script call's argument, a 32-bit type code and its value. */
struct ScriptArgument00a2efa0 {
    /* the value read before the type is stored (`mov eax,
     * [rdi+0x74]` before `mov dword [rbp-0x30], 3` at 0xb10dcb; `mov rax,
     * [rbx+0x28]` before the first type at 0x2dc470): both are the setter's
     * arguments, evaluated before its stores */
    void set(int type_, int value_) /* derived name */
    {
        type = type_;
        value = value_;
    }

    int type;
    u8 unknown4[4];
    int value;
    u8 unknownc[4];
};

/* derived names: the record the pointer at 0x5938c40 holds. */
struct Object05938c40 {
    u8 unknown0[0x19c];
    int unknown19c;
};

extern Object05938c40 *D_5938c40;

/* derived names: calls the script function its name gives with count
 * arguments, its int result through the last pointer; nonzero on success. */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

static bool D_58325e9;

void FUN_00b100a0(Object00b100c0 *) /* derived name */
{
    D_58325e9 = true;
}

void FUN_00b100b0(Object00b100c0 *) /* derived name */
{
    D_58325e9 = false;
}

/* derived names: when the flag is set, the result of the script function
 * "GuideSystem.checkDisp" for the int at +0x74 (type 3) and the int at +0x19c
 * of the record at 0x5938c40 (type 4); false otherwise. Not a row of this
 * round: written so the flag's loads keep the setters' stores (GlobalOpt
 * deletes the stores of a never-loaded bool). */
bool FUN_00b100c0(const Object00b100c0 *self) /* derived name */
{
    if (!D_58325e9) {
        return false;
    }
    int result = 0;
    ScriptArgument00a2efa0 arguments[2];
    arguments[0].set(3, self->unknown74);
    arguments[1].set(4, D_5938c40->unknown19c);
    int ok = FUN_00a2efa0("GuideSystem.checkDisp", 2, arguments, &result);
    return result != 0 && ok != 0;
}
