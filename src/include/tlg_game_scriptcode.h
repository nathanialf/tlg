/* src/include/tlg_game_scriptcode.h: the script compiler's code generation
 * as the slots of the vtable at 0x16bb0c0 see it (game region;
 * docs/TARGETS.md): the function being compiled, its stacks in chunks
 * (tlg_game_chunkstack.h) and the expressions on top of them. The compiler
 * is Havok Script's (the message strings), a Lua 5.1 parser and code
 * generator; the fields are named for what the slots do with them, after
 * the Lua 5.1 fields they behave as. Every name here is derived. */
#ifndef TLG_GAME_SCRIPTCODE_H
#define TLG_GAME_SCRIPTCODE_H

#include "tlg_game_chunkstack.h"
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: the compiler's reporter at +0x18: slot 3 reports an error
 * message, slot 6 returns the line the code is generated for (the other
 * slots are not traced) */
class Lexer016bb0c0 /* derived name */
{
  public:
    virtual void slot0();                    /* derived name; not traced */
    virtual void slot1();                    /* derived name; not traced */
    virtual void slot2();                    /* derived name; not traced */
    virtual void error(const char *message); /* derived name */
    virtual int slot4();                     /* derived name; not traced */
    virtual void slot5();                    /* derived name; not traced */
    virtual int line();                      /* derived name */
};

/* derived names: the text an expression carries, up to 16 characters kept
 * inline: the characters, a pointer to them and one to the last of them
 * (the byte before them when empty); a copy keeps its own pointers (the
 * last one at the same distance from the start) and takes the characters */
struct ExpressionText016bb0c0 { /* derived name */
    char buffer[0x10];          /* +0x0 */
    char *start;                /* +0x10 */
    char *last;                 /* +0x18 */

    ExpressionText016bb0c0() : start(buffer), last(buffer - 1) {}

    ExpressionText016bb0c0 &operator=(const ExpressionText016bb0c0 &other)
    {
        if (this != &other) {
            last = other.last < other.start ? start - 1 : start + (other.last - other.start);
            memcpy(buffer, other.buffer, sizeof(buffer));
        }
        return *this;
    }

    /* derived name */
    void clear()
    {
        start = buffer;
        last = buffer - 1;
    }
};

/* derived names: an expression of 0x70 bytes: its kind (13 a value in a
 * register, as Lua's VNONRELOC), its info (the register, constant or
 * instruction), the jump lists to patch when true and when false, its text
 * and a type word at +0x60 */
struct Expression016bb0c0 { /* derived name */
    int kind;               /* +0x0 */
    u8 unknown4[4];
    int info; /* +0x8 */
    u8 unknownc[0x2c];
    int trueJumps;               /* +0x38 */
    int falseJumps;              /* +0x3c */
    ExpressionText016bb0c0 text; /* +0x40 */
    int type;                    /* +0x60 */
    u8 unknown64[4];
    void *unknown68; /* +0x68 */
};

/* derived name: the expression set to a kind, its info and its type with
 * no jumps pending, as Lua's init_exp (the stores in this order, as the
 * slots of 0x16bb0c0 from FUN_00da92f0 make them) */
static inline void initExpression(Expression016bb0c0 *e, int kind, int info, int type)
{
    e->kind = kind;
    e->trueJumps = -1;
    e->falseJumps = -1;
    e->text.clear();
    e->unknown68 = 0;
    e->type = type;
    e->info = info;
}

/* derived names: a constant handed to FUN_00da9130 to be found or added in
 * the function's constants: its type (3 a number, 4 a string) and value */
struct Constant016bb0c0 { /* derived name */
    int type;             /* +0x0 */
    u8 unknown4[4];

    union {
        float number; /* +0x8 */
        void *object; /* +0x8 */
        u64 integer;  /* +0x8 */
    };
};

/* derived names: the record of a block being compiled (Lua's BlockCnt):
 * its list of breaks, its upvalue flag, whether it can be broken out of
 * and the count of active locals when it began */
struct BlockScope016bb0c0 { /* derived name */
    int breaks;             /* +0x0 */
    int upvalues;           /* +0x4 */
    int breakable;          /* +0x8 */
    u16 activeLocals;       /* +0xc */
    u8 unknowne[2];

    BlockScope016bb0c0(int breakable, u16 activeLocals)
        : breaks(-1), upvalues(0), breakable(breakable), activeLocals(activeLocals)
    {
    }
};

/* derived names: a local variable's record: the pc it is live from at +0x8 */
struct LocalVariable016bb0c0 { /* derived name */
    u8 unknown0[8];
    int startPc; /* +0x8 */
    u8 unknownc[4];
};

/* derived names: the 24-byte records of the stack at +0x1708 (the blocks of
 * tlg_game_compiler00da5b20.h's pushBlock): a kind, a line or a jump list by
 * the loop at +0x4, the loop's start, the base register at +0xc, the count
 * of its hidden variables at +0xe, whether it is a numeric loop at +0x10 */
struct Loop016bb0c0 { /* derived name */
    int kind;         /* +0x0 */
    int unknown4;     /* +0x4 */
    int start;        /* +0x8 */
    u16 unknownc;     /* +0xc */
    u16 hidden;       /* +0xe */
    int unknown10;    /* +0x10 */
    int unknown14;    /* +0x14 */
};

/* derived names: the 0x158-byte records of the stack at +0x17c0: two stacks
 * of 24-byte items over the script state's heap and an int between them;
 * handed to FUN_013be1a0 when popped (the items are not traced) */
struct PendingItem016bb0c0 { /* derived name */
    u8 unknown0[0x18];
};

struct Pending016bb0c0 {                       /* derived name */
    ChunkStack<PendingItem016bb0c0, 4> first;  /* +0x0 */
    int unknowna8;                             /* +0xa8 */
    ChunkStack<PendingItem016bb0c0, 4> second; /* +0xb0 */

    explicit Pending016bb0c0(HksState00dd1740 *heap) : first(heap), unknowna8(0), second(heap) {}
};

/* derived names: the 24-byte records of the stack at +0x1d68 */
struct Slot016bb0c0 { /* derived name */
    int unknown0;     /* +0x0 */
    u8 unknown4[4];
    void *unknown8; /* +0x8 */
    int unknown10;  /* +0x10 */
    u8 unknown14[4];
};

/* derived names: the function being compiled (0x1e10 bytes, as Lua's
 * FuncState): the stacks of block records, of code (256 instructions to a
 * chunk, the pc their count), of local variables and of the active locals'
 * indexes, the pending jumps to the next instruction, the free register
 * and the high mark of registers, the vararg flags, the last target of a
 * jump, the stacks of expressions, of loops and two more */
struct ScriptFunction016bb0c0 { /* derived name */
    u8 unknown0[0x260];
    ChunkStack<BlockScope016bb0c0, 16> scopes; /* +0x260 */
    ChunkStack<u32, 256> code;                 /* +0x3a8: its count the pc */
    u8 unknown7f0[0x430];
    int *unknownc20; /* +0xc20 */
    u8 unknownc28[0x18];
    int pendingJumps; /* +0xc40 */
    u32 freeRegister; /* +0xc44 */
    u32 maxStack;     /* +0xc48 */
    u8 unknownc4c[0x8c];
    ChunkStack<LocalVariable016bb0c0, 16> locals; /* +0xcd8 */
    ChunkStack<u16, 16> activeIndexes;            /* +0xe20 */
    u32 activeCount;                              /* +0xe88 */
    u8 unknowne8c[0xcc];
    u8 vararg; /* +0xf58: bit 0 an "arg" parameter, bit 2 the implicit "arg" needed */
    u8 unknownf59[3];
    int lineDefined;    /* +0xf5c: 0 for the main function */
    u32 parameterCount; /* +0xf60 */
    u8 unknownf64[8];
    int lastTarget; /* +0xf6c */
    u8 unknownf70[0x3d0];
    ChunkStack<Expression016bb0c0, 8> expressions; /* +0x1340 */
    ChunkStack<Loop016bb0c0, 4> loops;             /* +0x1708 */
    int unknown17b0;                               /* +0x17b0 */
    u8 unknown17b4[0xc];
    ChunkStack<Pending016bb0c0, 4> pending; /* +0x17c0 */
    ChunkStack<Slot016bb0c0, 4> slots;      /* +0x1d68 */
};

/* derived names: the table of names of the state's global part (+0x1a8 of
 * it, tlg_game_object013c8500.h), and a name made in it */
struct NameTable016bb0c0; /* derived name */
struct Name016bb0c0;      /* derived name */

/* derived names: the structure a table constructor builds an instance of:
 * its count of slots, whether its instances take other keys (number
 * indexes, slots it does not declare) at +0xc, its name at +0x18 and its
 * slots from +0x20, 24 bytes each with the slot's name first */
struct ScriptString016bb0c0 { /* derived name */
    u8 unknown0[0x14];
    char chars[4]; /* +0x14 */
};

struct StructureSlot016bb0c0 {  /* derived name */
    ScriptString016bb0c0 *name; /* +0x0 */
    u8 unknown8[0x10];
};

struct Structure016bb0c0 { /* derived name */
    u64 slotCount;         /* +0x0 */
    u8 unknown8[4];
    int open; /* +0xc */
    u8 unknown10[8];
    ScriptString016bb0c0 *name;     /* +0x18 */
    StructureSlot016bb0c0 slots[1]; /* +0x20: slotCount of them */
};

/* derived name: resolves a type declaration's name (leaf_00db3300.cpp) */
struct CodeGen016bb0c0;
void FUN_00db3300(CodeGen016bb0c0 *self, ScriptString016bb0c0 *name, int *type,
                  Structure016bb0c0 **structure);

/* derived name: whether a structure declares a slot of the name */
static inline bool hasSlot(const Structure016bb0c0 *structure, const ScriptString016bb0c0 *name)
{
    for (u64 i = 0; i < structure->slotCount; ++i)
        if (structure->slots[i].name == name)
            return true;
    return false;
}

/* derived names: a value of the script VM's tables (its type in the low
 * four bits of the word at +0x0: 4 a string, 7 a structure's object) and a
 * node of a table's hash part: its key and value; the nodes' next links are
 * kept before the nodes, the last node's first (the link of node i at
 * index ~i) */
struct HksValue016bb0c0 { /* derived name */
    int type;             /* +0x0 */
    u8 unknown4[4];
    void *value; /* +0x8 */
};

struct HksNode016bb0c0 {    /* derived name */
    HksValue016bb0c0 key;   /* +0x0 */
    HksValue016bb0c0 value; /* +0x10 */
};

struct HksTable016bb0c0 { /* derived name */
    u8 unknown0[0x1c];
    u32 mask;               /* +0x1c */
    HksNode016bb0c0 *nodes; /* +0x20 */
};

/* derived name: the nil value a lookup gives when the key is not there */
extern const HksValue016bb0c0 D_1557370;

/* derived name: the value of a string key, nil when not there, copied into
 * the value given (the copies in two arms whose loads the compiler sinks
 * into one: the base's two pointers, to the type and to the value) */
static inline void findString(const HksTable016bb0c0 *table, const ScriptString016bb0c0 *key,
                              HksValue016bb0c0 &value)
{
    if (HksNode016bb0c0 *nodes = table->nodes) {
        u64 k = reinterpret_cast<u64>(key);
        HksNode016bb0c0 *node = &nodes[table->mask & (k ^ (k >> 5) ^ (k >> 8))];
        do {
            if (node->key.value == key && (node->key.type & 0xf) == 4) {
                value = node->value;
                return;
            }
            node = reinterpret_cast<HksNode016bb0c0 **>(nodes)[~(node - nodes)];
        } while (node);
    }
    value = D_1557370;
}

/* derived names: the object a structure's value points to: the structure
 * after a header of 0x20 bytes */
struct StructureObject016bb0c0 { /* derived name */
    u8 unknown0[0x20];
    Structure016bb0c0 structure; /* +0x20 */
};

/* derived names: the table constructor being compiled (Lua's ConsControl):
 * the last list item, the table's expression, the counts of hash and list
 * items, the list items waiting to be stored and the structure at +0x108
 * (0x110 bytes, the elements of the stack at +0x48) */
struct Constructor016bb0c0 {   /* derived name */
    Expression016bb0c0 item;   /* +0x0 */
    Expression016bb0c0 *table; /* +0x70 */
    int hashItems;             /* +0x78 */
    int listItems;             /* +0x7c */
    int toStore;               /* +0x80 */
    u8 unknown84[0x84];
    Structure016bb0c0 *structure; /* +0x108 */
};

/* derived names: the 16-byte entries of the compiler's stack at +0x4d0 */
struct Entry016bb0c0 { /* derived name */
    void *value;       /* +0x0 */
    int unknown8;      /* +0x8 */
};

/* derived names: the compiler, the class whose vtable is at 0x16bb0c0 as its
 * code generation slots read it: the script state at +0x8, the reporter at +0x18,
 * whether structures are enabled at +0x20, the options at +0x3c (bit 0 int
 * literals, bit 1 60-bit ones), the stacks of table constructors and of
 * entries and the function on top of its stack of functions at +0x558 */
struct CodeGen016bb0c0 { /* derived name */
    u8 unknown0[8];
    HksState00dd1740 *state; /* +0x8 */
    u8 unknown10[8];
    Lexer016bb0c0 *lexer; /* +0x18 */
    int structures;       /* +0x20 */
    u8 unknown24[0x18];
    u8 options; /* +0x3c */
    u8 unknown3d[0xb];
    ChunkStack<Constructor016bb0c0, 4> constructors; /* +0x48 */
    ChunkStack<Entry016bb0c0, 4> entries;            /* +0x4d0 */
    u8 unknown558[0x7870];
    ScriptFunction016bb0c0 *function; /* +0x7dc8 */
    u8 unknown7dd0[0x1540];
    Structure016bb0c0 *structure; /* +0x9310: the structure referenced last */
};

/* derived names: the callees, not written */
void FUN_013bdca0(ChunkStack<Expression016bb0c0, 8> *stack);               /* derived name: pops */
void FUN_013bdfe0(ChunkStack<Pending016bb0c0, 4> *stack);                  /* derived name: pops */
void FUN_013be1a0(Pending016bb0c0 *record);                                /* derived name */
int FUN_00db1aa0(CodeGen016bb0c0 *self, u32 instruction, int line);        /* derived name: codes */
void FUN_00da7fc0(CodeGen016bb0c0 *self, Expression016bb0c0 *e);           /* derived name */
void FUN_00db01b0(CodeGen016bb0c0 *self, Expression016bb0c0 *e, int reg);  /* derived name */
int FUN_00da9130(CodeGen016bb0c0 *self, const Constant016bb0c0 *constant); /* derived name */
void FUN_00da61c0(CodeGen016bb0c0 *self, Expression016bb0c0 *top,
                  Expression016bb0c0 *popped); /* derived name */
void FUN_00da88a0(CodeGen016bb0c0 *self, Expression016bb0c0 *top,
                  Expression016bb0c0 *popped);                              /* derived name */
void FUN_00da7410(CodeGen016bb0c0 *self, int unknown, int count);           /* derived name */
void FUN_00da9f90(CodeGen016bb0c0 *self, int base, int items, int toStore); /* derived name */
Name016bb0c0 *FUN_00dd0a60(NameTable016bb0c0 **names, HksState00dd1740 *state, const char *name,
                           size_t length); /* derived name */
void FUN_00daba60(CodeGen016bb0c0 *self, Name016bb0c0 *name, int index, int type,
                  void *structure);           /* derived name: declares a local */
int FUN_00db26b0(ScriptString016bb0c0 *name); /* derived name: the built-in type of a name */
void FUN_00da8700(CodeGen016bb0c0 *self, Expression016bb0c0 *e); /* derived name */
/* derived name: formats into a buffer (vsprintf: the size is not used) */
int FUN_00d95b60(char *buffer, size_t size, const char *format, ...);

/* derived names: an instruction of three arguments or of one wide one: the
 * opcode in the top 7 bits, B from bit 17, C from bit 8 (its low byte the
 * call's results), A in the low byte, Bx from bit 8 */
#define SCRIPT_ABC(op, a, b, c)                                                                    \
    (((u32)(op) << 25) | (((u32)(b) << 17) & 0x3fe0000) | (((u32)(c) << 8) & 0x1ff00) |            \
     ((u32)(a) & 0xff))
#define SCRIPT_ABX(op, a, bx) (((u32)(op) << 25) | ((u32)(bx) << 8) | ((u32)(a) & 0xff))
#define SCRIPT_SET_C(i, c) ((i) = ((i) & 0xffff00ff) | ((u32)(c) << 8))

/* derived name: the instruction an expression's info points at */
#define SCRIPT_CODE(fs, e) ((fs)->code.at((e)->info))

/* derived name: checks there is room for n more registers, the high mark
 * raised (an error reported at 200); returns the registers then in use */
static inline u32 checkStack(CodeGen016bb0c0 *self, u32 n)
{
    u32 needed = self->function->freeRegister + n;
    if (needed > self->function->maxStack) {
        if (needed >= 200)
            self->lexer->error("Function or expression requires too many registers (too complex).");
        self->function->maxStack = needed;
    }
    return needed;
}

/* derived name: takes n more registers; returns the first of them */
static inline u32 reserveRegisters(CodeGen016bb0c0 *self, u32 n)
{
    u32 needed = checkStack(self, n);
    self->function->freeRegister = needed;
    return needed - n;
}

/* derived name: gives back the register a temporary value is in */
static inline void freeExpression(CodeGen016bb0c0 *self, Expression016bb0c0 *e)
{
    if (e->kind == 13 && !(e->info & 0x100) && self->function->activeCount <= (u32)e->info)
        --self->function->freeRegister;
}

/* derived name: puts an expression in the next free register (Lua's
 * luaK_exp2nextreg) */
static inline void toNextRegister(CodeGen016bb0c0 *self, Expression016bb0c0 *e)
{
    FUN_00da7fc0(self, e);
    freeExpression(self, e);
    u32 reg = reserveRegisters(self, 1);
    FUN_00db01b0(self, e, reg);
}

/* derived name: codes an instruction at the reporter's line */
static inline int code(CodeGen016bb0c0 *self, u32 instruction)
{
    return FUN_00db1aa0(self, instruction, self->lexer->line());
}

/* derived name: codes an instruction of A and a wide argument */
static inline int codeABx(CodeGen016bb0c0 *self, int op, int a, int bx)
{
    return code(self, SCRIPT_ABX(op, a, bx));
}

/* derived names: the index of a number constant and of a string constant
 * (Lua's luaK_numberK and luaK_stringK, defined once in leaf_00daf320.cpp:
 * the link inlines them, after each caller's unit has marked its own calls
 * tail calls, as 0xda87e0's `jmp` to FUN_00da88a0 shows) */
int numberConstant(CodeGen016bb0c0 *self, float number);
int stringConstant(CodeGen016bb0c0 *self, void *string);

/* derived name: the local variable of an active index */
static inline LocalVariable016bb0c0 &localVariable(ScriptFunction016bb0c0 *fs, u32 i)
{
    return fs->locals.at(fs->activeIndexes.at(i));
}

/* derived name: makes n declared locals active from the current pc (Lua's
 * adjustlocalvars) */
static inline void activateLocals(CodeGen016bb0c0 *self, u32 n)
{
    ScriptFunction016bb0c0 *fs = self->function;
    int pc = fs->code.count;
    for (u32 i = 0; i < n; ++i)
        localVariable(fs, fs->activeCount + i).startPc = pc;
    fs->activeCount += n;
}

/* derived name: begins a block (Lua's enterblock) */
static inline void enterBlock(CodeGen016bb0c0 *self, int breakable)
{
    *self->function->scopes.push() = BlockScope016bb0c0(breakable, self->function->activeCount);
}

/* derived name: declares a local of a name given with its length */
static inline void declareLocal(CodeGen016bb0c0 *self, const char *name, size_t length, int index,
                                int type)
{
    FUN_00daba60(self, FUN_00dd0a60(&self->state->allocator->names, self->state, name, length),
                 index, type, 0);
}

/* derived name: reports a count over its limit (Lua's luaY_checklimit and
 * errorlimit) */
static inline void checkLimit(CodeGen016bb0c0 *self, u32 value, u32 limit, const char *what)
{
    if (value > limit) {
        char message[0x100];
        ScriptFunction016bb0c0 *fs = self->function;
        if (fs->lineDefined)
            FUN_00d95b60(message, sizeof(message), "Function at line %i has more than %i %s",
                         fs->lineDefined, limit, what);
        else
            FUN_00d95b60(message, sizeof(message), "Main function has more than %i %s", limit,
                         what);
        self->lexer->error(message);
    }
}

#endif
