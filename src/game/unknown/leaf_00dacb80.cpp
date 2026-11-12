/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: the jump-list code of the script compiler whose object the
 * vtable at 0x16bb0c0 is (stored by FUN_00da4250 and FUN_00ddbb60; home
 * BytecodeReader.cpp). Its instructions are kept in pages of 256 words; an
 * instruction's word holds a jump offset in bits 8 to 24, biased by 0xffff,
 * with 0xffff (an offset of -1) ending a list, as Lua's luaK_concat, getjump
 * and fixjump. FUN_00dacb80 is called by FUN_00da53f0, FUN_00da56c0,
 * FUN_00da7a60, FUN_00daca10, FUN_00dae680 and FUN_00db00e0; FUN_00db00e0 is
 * slot 12 of the vtable at 0x16bb0c0 (its pointer at 0x16bb130). FUN_00dafb70
 * marks the label at pc and stores pc and slot 4 of the reporter in the record
 * at +0x1798 (a slot of the same vtable). FUN_00da7a00, slot 135 (its pointer
 * at 0x16bb508), takes the expression at +0x16f0, calls FUN_013bdca0 with the
 * field at +0x1340, turns a kind of 1 into 3, passes the expression to
 * FUN_00da7a60 and stores its int at +0x3c at +0x14 of the record. The
 * reporter's class and the types at +0x1708 and +0x1798 are not traced. */
class Reporter00dacb80 /* derived name */
{
  public:
    virtual void slot0();                    /* derived name; not traced */
    virtual void slot1();                    /* derived name; not traced */
    virtual void slot2();                    /* derived name; not traced */
    virtual void slot3(const char *message); /* derived name; not traced */
    virtual int slot4();                     /* derived name; not traced */
    virtual void slot5();                    /* derived name; not traced */
    virtual int slot6();                     /* derived name; not traced */
};

struct CodePage00dacb80 { /* derived name */
    u8 unknown0[0x400];
    u32 *code;              /* derived name */
    CodePage00dacb80 *next; /* derived name */
};

struct Block00dacb80 { /* derived name */
    u8 unknown0[4];
    int unknown4;
    int unknown8;
    u8 unknownc[8];
    int unknown14;
};

struct Expression00dacb80 { /* derived name */
    int kind;               /* derived name */
    u8 unknown4[0x38];
    int unknown3c;
};

struct FuncState00dacb80 { /* derived name */
    u8 unknown0[0x7c8];
    CodePage00dacb80 *firstPage;   /* derived name */
    CodePage00dacb80 *currentPage; /* derived name */
    u8 unknown7d8[0x10];
    u32 pc; /* derived name */
    u8 unknown7ec[0x454];
    int jumpList; /* derived name; +0xc40 */
    u8 unknownc44[0x328];
    int lastTarget; /* derived name; +0xf6c */
    u8 unknownf70[0x3d0];
    u8 unknown1340; /* type not traced; its address is passed */
    u8 unknown1341[0x3af];
    Expression00dacb80 *unknown16f0;
    u8 unknown16f8[0x10];
    u8 unknown1708; /* type not traced; its address is passed */
    u8 unknown1709[0x8f];
    Block00dacb80 *unknown1798;
};

struct Compiler00dacb80 { /* derived name */
    u8 unknown0[0x18];
    Reporter00dacb80 *reporter; /* derived name */
    u8 unknown20[0x7da8];
    FuncState00dacb80 *funcState; /* derived name; +0x7dc8 */
};

void FUN_013bde50(void *field);                                            /* derived name */
void FUN_013bdca0(void *field);                                            /* derived name */
void FUN_00da7a60(Compiler00dacb80 *self, Expression00dacb80 *expression); /* derived name */
void FUN_00dae7e0(Compiler00dacb80 *self);                                 /* derived name */
int FUN_00db1aa0(Compiler00dacb80 *self, u32 code, int value);             /* derived name */

/* derived name: the word of the instruction at pc */
static inline u32 *instruction(FuncState00dacb80 *fs, u32 pc)
{
    u32 slot = pc & 0xff;
    u32 pageIndex = pc >> 8;
    if (pageIndex == fs->pc >> 8)
        return &fs->currentPage->code[slot];
    CodePage00dacb80 *page = fs->firstPage;
    for (u32 i = 0; i < pageIndex; ++i)
        page = page->next;
    return &page->code[slot];
}

/* derived name: the target of the jump at pc, -1 at the end of a list */
static int jumpTarget(FuncState00dacb80 *fs, int pc)
{
    int offset = (int)((*instruction(fs, pc) >> 8) & 0x1ffff) - 0xffff;
    if (offset == -1)
        return -1;
    return pc + 1 + offset;
}

/* derived name: points the jump at pc to dest */
static void fixJump(Compiler00dacb80 *self, FuncState00dacb80 *fs, int pc, int dest)
{
    u32 *word = instruction(fs, pc);
    int offset = dest - (pc + 1);
    if (fabsf((float)offset) > 65535.0f)
        self->reporter->slot3("Control structure contains too many instructions.");
    *word = (*word & 0xfe0000ff) | (((u32)(offset + 0xffff) << 8) & 0x1ffff00);
}

// NONMATCHING: the base materializes the instruction's address (lea; add [page+0x400]) where the build folds it into the load's addressing mode, in the walk and after it; list-ilp order of the offset and the target (the cmov tied the other way)
void FUN_00dacb80(Compiler00dacb80 *self, int *list, int jump) /* derived name */
{
    if (jump == -1)
        return;
    if (*list == -1) {
        *list = jump;
        return;
    }
    FuncState00dacb80 *fs = self->funcState;
    int pc = *list;
    int next;
    while ((next = jumpTarget(fs, pc)) != -1)
        pc = next;
    fixJump(self, fs, pc, jump);
}

void FUN_00db00e0(Compiler00dacb80 *self) /* derived name */
{
    FuncState00dacb80 *fs = self->funcState;
    int jump = fs->unknown1798->unknown4;
    fs->lastTarget = fs->pc;
    FUN_00dacb80(self, &self->funcState->jumpList, jump);
    FUN_013bde50(&self->funcState->unknown1708);
}

void FUN_00dafb70(Compiler00dacb80 *self) /* derived name */
{
    self->funcState->lastTarget = self->funcState->pc;
    Block00dacb80 *block = self->funcState->unknown1798;
    block->unknown8 = self->funcState->pc;
    self->funcState->unknown1798->unknown4 = self->reporter->slot4();
}

/* derived name: slot 13 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb138): FUN_00dacb80 joins the jump at +0x8 of the record to the list
 * at +0x4, then FUN_00db00e0, slot 12 (its pointer at 0x16bb130) */
void FUN_00db0140(Compiler00dacb80 *self) /* derived name */
{
    Block00dacb80 *block = self->funcState->unknown1798;
    FUN_00dacb80(self, &block->unknown4, block->unknown8);
    FUN_00db00e0(self);
}

/* derived name: slot 15 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb148): FUN_00db00e0's body after a call of FUN_00dae7e0, with the
 * jump read from +0x14 of the record */
void FUN_00dafdc0(Compiler00dacb80 *self) /* derived name */
{
    FUN_00dae7e0(self);
    FuncState00dacb80 *fs = self->funcState;
    int jump = fs->unknown1798->unknown14;
    fs->lastTarget = fs->pc;
    FUN_00dacb80(self, &self->funcState->jumpList, jump);
    FUN_013bde50(&self->funcState->unknown1708);
}

void FUN_00da7a00(Compiler00dacb80 *self) /* derived name */
{
    FuncState00dacb80 *fs = self->funcState;
    Expression00dacb80 *expression = fs->unknown16f0;
    FUN_013bdca0(&fs->unknown1340);
    if (expression->kind == 1)
        expression->kind = 3;
    FUN_00da7a60(self, expression);
    self->funcState->unknown1798->unknown14 = expression->unknown3c;
}

/* derived name: slots 10 and 11 of the vtable at 0x16bb0c0 (their pointers
 * at 0x16bb120 and 0x16bb128), one body: a jump emitted by FUN_00db1aa0
 * (the code 0x38fffe00 and slot 6 of the reporter) with the pending jump
 * list (+0xc40, left empty) joined to it, the jump joined to the record's
 * list at +0x4, then FUN_00db00e0's body over the jump at +0x8 */
// NONMATCHING: list-ilp order: the base adds 4 to the record (the exit list's address) right
// after the vptr load, the build after the jump list's store; the tail's pc in esi against edi
// (greedy's assignment)
void FUN_00daff40(Compiler00dacb80 *self) /* derived name */
{
    FuncState00dacb80 *fs = self->funcState;
    int *exits = &fs->unknown1798->unknown4;
    int pending = fs->jumpList;
    fs->jumpList = -1;
    int jump = FUN_00db1aa0(self, 0x38fffe00, self->reporter->slot6());
    FUN_00dacb80(self, &jump, pending);
    FUN_00dacb80(self, exits, jump);
    fs = self->funcState;
    int target = fs->unknown1798->unknown8;
    fs->lastTarget = fs->pc;
    FUN_00dacb80(self, &self->funcState->jumpList, target);
}

// NONMATCHING: as FUN_00daff40, one body
void FUN_00db0010(Compiler00dacb80 *self) /* derived name */
{
    FuncState00dacb80 *fs = self->funcState;
    int *exits = &fs->unknown1798->unknown4;
    int pending = fs->jumpList;
    fs->jumpList = -1;
    int jump = FUN_00db1aa0(self, 0x38fffe00, self->reporter->slot6());
    FUN_00dacb80(self, &jump, pending);
    FUN_00dacb80(self, exits, jump);
    fs = self->funcState;
    int target = fs->unknown1798->unknown8;
    fs->lastTarget = fs->pc;
    FUN_00dacb80(self, &self->funcState->jumpList, target);
}
