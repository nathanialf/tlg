/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_chunkstack.h"
#include "tlg_libc.h"
#include "tlg_types.h"

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
    virtual int slot6();                     /* derived name; the line FUN_00da7a60 codes with */
};

struct CodePage00dacb80 { /* derived name */
    u8 unknown0[0x400];
    u32 *code;              /* derived name */
    CodePage00dacb80 *next; /* derived name */
};

/* derived names: the loop's record: the line it began at or the jump list
 * of its condition at +0x4, its start, its base register, the count of its
 * hidden variables, whether it is a numeric for at +0x10 and its exit list
 * at +0x14 */
struct Block00dacb80 { /* derived name */
    u8 unknown0[4];
    int unknown4;
    int unknown8;
    u16 base;      /* +0xc */
    u16 hidden;    /* +0xe */
    int numeric;   /* +0x10 */
    int unknown14; /* +0x14 */
};

/* derived names: a block's record (as Lua's BlockCnt): its list of breaks,
 * whether a local of it is an upvalue, whether it can be broken out of and
 * the count of active locals when it began */
struct Scope00dacb80 { /* derived name */
    int breaks;
    int upvalues;
    int breakable;
    u16 activeLocals;
    u8 unknowne[2];
};

struct Expression00dacb80 { /* derived name */
    int kind;               /* derived name */
    u8 unknown4[4];
    int unknown8;
    u8 unknownc[0x2c];
    int unknown38;
    int unknown3c;
};

struct FuncState00dacb80 { /* derived name */
    u8 unknown0[0x260];
    ChunkStack<Scope00dacb80, 16> scopes; /* +0x260 */
    u8 unknown3a8[0x420];
    CodePage00dacb80 *firstPage;   /* derived name */
    CodePage00dacb80 *currentPage; /* derived name */
    u8 unknown7d8[0x10];
    u32 pc; /* derived name */
    u8 unknown7ec[0x434];
    int *unknownc20; /* +0xc20 */
    u8 unknownc28[0x18];
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

/* derived names: the compiler; its slot 73 is the break statement
 * (FUN_00daca10), the slots before it not traced */
class Compiler00dacb80 /* derived name */
{
  public:
    virtual ~Compiler00dacb80();
    virtual void slot2();          /* derived name; not traced */
    virtual void slot3();          /* derived name; not traced */
    virtual void slot4();          /* derived name; not traced */
    virtual void slot5();          /* derived name; not traced */
    virtual void slot6();          /* derived name; not traced */
    virtual void slot7();          /* derived name; not traced */
    virtual void slot8();          /* derived name; not traced */
    virtual void slot9();          /* derived name; not traced */
    virtual void slot10();         /* derived name; not traced */
    virtual void slot11();         /* derived name; not traced */
    virtual void slot12();         /* derived name; not traced */
    virtual void slot13();         /* derived name; not traced */
    virtual void slot14();         /* derived name; not traced */
    virtual void slot15();         /* derived name; not traced */
    virtual void slot16();         /* derived name; not traced */
    virtual void slot17();         /* derived name; not traced */
    virtual void slot18();         /* derived name; not traced */
    virtual void slot19();         /* derived name; not traced */
    virtual void slot20();         /* derived name; not traced */
    virtual void slot21();         /* derived name; not traced */
    virtual void slot22();         /* derived name; not traced */
    virtual void slot23();         /* derived name; not traced */
    virtual void slot24();         /* derived name; not traced */
    virtual void slot25();         /* derived name; not traced */
    virtual void slot26();         /* derived name; not traced */
    virtual void slot27();         /* derived name; not traced */
    virtual void slot28();         /* derived name; not traced */
    virtual void slot29();         /* derived name; not traced */
    virtual void slot30();         /* derived name; not traced */
    virtual void slot31();         /* derived name; not traced */
    virtual void slot32();         /* derived name; not traced */
    virtual void slot33();         /* derived name; not traced */
    virtual void slot34();         /* derived name; not traced */
    virtual void slot35();         /* derived name; not traced */
    virtual void slot36();         /* derived name; not traced */
    virtual void slot37();         /* derived name; not traced */
    virtual void slot38();         /* derived name; not traced */
    virtual void slot39();         /* derived name; not traced */
    virtual void slot40();         /* derived name; not traced */
    virtual void slot41();         /* derived name; not traced */
    virtual void slot42();         /* derived name; not traced */
    virtual void slot43();         /* derived name; not traced */
    virtual void slot44();         /* derived name; not traced */
    virtual void slot45();         /* derived name; not traced */
    virtual void slot46();         /* derived name; not traced */
    virtual void slot47();         /* derived name; not traced */
    virtual void slot48();         /* derived name; not traced */
    virtual void slot49();         /* derived name; not traced */
    virtual void slot50();         /* derived name; not traced */
    virtual void slot51();         /* derived name; not traced */
    virtual void slot52();         /* derived name; not traced */
    virtual void slot53();         /* derived name; not traced */
    virtual void slot54();         /* derived name; not traced */
    virtual void slot55();         /* derived name; not traced */
    virtual void slot56();         /* derived name; not traced */
    virtual void slot57();         /* derived name; not traced */
    virtual void slot58();         /* derived name; not traced */
    virtual void slot59();         /* derived name; not traced */
    virtual void slot60();         /* derived name; not traced */
    virtual void slot61();         /* derived name; not traced */
    virtual void slot62();         /* derived name; not traced */
    virtual void slot63();         /* derived name; not traced */
    virtual void slot64();         /* derived name; not traced */
    virtual void slot65();         /* derived name; not traced */
    virtual void slot66();         /* derived name; not traced */
    virtual void slot67();         /* derived name; not traced */
    virtual void slot68();         /* derived name; not traced */
    virtual void slot69();         /* derived name; not traced */
    virtual void slot70();         /* derived name; not traced */
    virtual void slot71();         /* derived name; not traced */
    virtual void slot72();         /* derived name; not traced */
    virtual void breakStatement(); /* derived name */

    u8 unknown8[0x10];
    Reporter00dacb80 *reporter; /* derived name */
    u8 unknown20[0x7da8];
    FuncState00dacb80 *funcState; /* derived name; +0x7dc8 */
};

void FUN_013bde50(void *field);                                            /* derived name */
void FUN_013bdca0(void *field);                                            /* derived name */
void FUN_00da7a60(Compiler00dacb80 *self, Expression00dacb80 *expression); /* derived name */
void FUN_00dae7e0(Compiler00dacb80 *self);                                 /* derived name */
void FUN_00da7fc0(Compiler00dacb80 *self, Expression00dacb80 *expression); /* derived name */
int FUN_00db1aa0(Compiler00dacb80 *self, u32 word, int line);              /* derived name */
void FUN_00db1710(Compiler00dacb80 *self, int list, int target, int reg,
                  int defaultTarget); /* derived name */
int FUN_00db1f70(Compiler00dacb80 *self, Expression00dacb80 *expression,
                 int condition);                  /* derived name */
u8 *FUN_00db1e60(Compiler00dacb80 *self, int pc); /* derived name */

/* derived name: the word of the instruction at pc */
static inline u32 *instruction(FuncState00dacb80 *fs, u32 pc)
{
    u32 slot = pc & 0xff;
    u32 pageIndex = pc >> 8;
    if (fs->pc >> 8 == pageIndex)
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
    self->funcState->unknown1798->unknown8 = self->funcState->pc;
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

/* derived name: as Lua 5.1's luaK_goiftrue: FUN_00da7fc0 first (as
 * luaK_dischargevars), then by the expression's kind (2 to 11, the jump
 * table 0x155a018): 2, 4 and 5 jump nowhere; 3 codes a jump (the word
 * 0x38fffe00 with the reporter's slot 6, FUN_00db1aa0) joined to the pending
 * list at +0xc40, which it takes; 11 flips the byte FUN_00db1e60 returns for
 * the jump at +0x8 (as invertjump) and takes that jump; any other kind
 * FUN_00db1f70 with 0 (as jumponcond). The jump joins the list at +0x3c, and
 * the list at +0x38 goes to the pending list at the current pc (as
 * luaK_patchtohere) and is emptied. The kinds' names are not traced. */
void FUN_00da7a60(Compiler00dacb80 *self, Expression00dacb80 *expression) /* derived name */
{
    FUN_00da7fc0(self, expression);
    int jump;
    switch (expression->kind) {
    case 2:
    case 4:
    case 5:
        jump = -1;
        break;
    case 3: {
        FuncState00dacb80 *fs = self->funcState;
        int pending = fs->jumpList;
        fs->jumpList = -1;
        int coded = FUN_00db1aa0(self, 0x38fffe00, self->reporter->slot6());
        FUN_00dacb80(self, &coded, pending);
        jump = coded;
        break;
    }
    case 11: {
        u8 *control = FUN_00db1e60(self, expression->unknown8);
        *control = !*control;
        jump = expression->unknown8;
        break;
    }
    default:
        jump = FUN_00db1f70(self, expression, 0);
        break;
    }
    FUN_00dacb80(self, &expression->unknown3c, jump);
    FuncState00dacb80 *fs = self->funcState;
    int list = expression->unknown38;
    fs->lastTarget = fs->pc;
    FUN_00dacb80(self, &self->funcState->jumpList, list);
    expression->unknown38 = -1;
}

/* derived name: codes a jump with the pending jump list joined to it (Lua's
 * luaK_jump) */
static inline int codeJump(Compiler00dacb80 *self)
{
    FuncState00dacb80 *fs = self->funcState;
    int pending = fs->jumpList;
    fs->jumpList = -1;
    int jump = FUN_00db1aa0(self, 0x38fffe00, self->reporter->slot6());
    FUN_00dacb80(self, &jump, pending);
    return jump;
}

/* derived name: patches a jump list to a target: to the pending list when
 * the target is the current pc, else FUN_00db1710 with no register (Lua's
 * luaK_patchlist) */
static inline void patchList(Compiler00dacb80 *self, int list, int target)
{
    FuncState00dacb80 *fs = self->funcState;
    if (fs->pc == (u32)target) {
        fs->lastTarget = fs->pc;
        FUN_00dacb80(self, &self->funcState->jumpList, list);
    } else {
        FUN_00db1710(self, list, target, 0xff, target);
    }
}

/* derived name: slot 19 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb168): a jump patched to the start at +0x8 of the record, the exits
 * at +0x4 of the record stored where the pointer at +0xc20 points */
void FUN_00dafcd0(Compiler00dacb80 *self) /* derived name */
{
    int jump = codeJump(self);
    patchList(self, jump, self->funcState->unknown1798->unknown8);
    *self->funcState->unknownc20 = self->funcState->unknown1798->unknown4;
}

/* derived name: patches a jump list to the current pc, the pending list
 * (Lua's luaK_patchtohere) */
static inline void patchToHere(Compiler00dacb80 *self, int list)
{
    FuncState00dacb80 *fs = self->funcState;
    fs->lastTarget = fs->pc;
    FUN_00dacb80(self, &self->funcState->jumpList, list);
}

/* derived name: slot 43 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb228): a repeat loop's end (Lua's repeatstat after the condition):
 * with no upvalue in the block, the block left and the condition's exits
 * (+0x14 of the loop) patched to the loop's start (+0x4); with one, a break
 * when the condition holds (slot 73), the exits patched here, the block
 * left and a jump patched to the start; then the loop's block left and the
 * loop popped */
void FUN_00dae680(Compiler00dacb80 *self) /* derived name */
{
    if (self->funcState->scopes.top->upvalues) {
        self->breakStatement();
        patchToHere(self, self->funcState->unknown1798->unknown14);
        FUN_00dae7e0(self);
        patchList(self, codeJump(self), self->funcState->unknown1798->unknown4);
    } else {
        FUN_00dae7e0(self);
        Block00dacb80 *loop = self->funcState->unknown1798;
        patchList(self, loop->unknown14, loop->unknown4);
    }
    FUN_00dae7e0(self);
    FUN_013bde50(&self->funcState->unknown1708);
}
