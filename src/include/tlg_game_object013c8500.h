/* src/include/tlg_game_object013c8500.h: the class whose vtable is at
 * 0x16bc170 (config/vtables.derived.base.txt), moved from leaf_013c84c0.cpp,
 * which defines its destructor; leaf_00dd2820.cpp derives from it. derived
 * names throughout. */
#ifndef TLG_GAME_OBJECT013C8500_H
#define TLG_GAME_OBJECT013C8500_H

#include "tlg_hks.h"
#include "tlg_types.h"

void FUN_013bf660(void *a, void *b); /* derived name */

/* derived names: the values a walk visits from `first` up to `last`
 * (0xdd1cf0: `mov rbx, [r14+0x18]`, `cmp [r14], rbx` at each step) */
struct ValueRange00dd1cf0 {
    HksObject *last; /* +0x0 */
    u8 unknown8[0x10];
    HksObject *first; /* +0x18 */
};

/* derived names: a 24-byte element and the range of them a walk visits
 * (0xdd1e90: `mov rbx, [r14]`, `cmp [r14+0x10], rbx; jb` at each step) */
struct Entry00dd1e90 {
    u8 unknown0[0x18];
};

struct EntryRange00dd1e90 {
    Entry00dd1e90 *first; /* +0x0 */
    u8 unknown8[0x8];
    Entry00dd1e90 *last; /* +0x10 */
};

/* derived names: the records slots 8, 9, 13, 16, 28 and 38 walk (their
 * fields at the offsets the walks read; the rest not traced) */
struct Record00dd13d0 {
    u8 unknown0[0x18];
    void *environment; /* +0x18: to FUN_013bfaf0 */
    s16 count;         /* +0x20: of the values at +0x30 */
    u8 unknown22[0xe];
    HksObject values[1]; /* +0x30 */
};

struct Function00dd1460 {
    u8 unknown0[0x10];
    u16 count; /* +0x10: of the pointers at +0x38 of its record */
};

/* derived name: the element at +0x21 of slot 9's record, unaligned */
struct Inline00dd1460 {
    u8 unknown0[0x17];
};

/* derived name: what a pointer at +0x38 of slot 9's record points to: the
 * value at +0x20 (FUN_00dd2e60 reads its kind and pointer) */
struct Upvalue00dd2e60 {
    u8 unknown0[0x20];
    const HksObject *value; /* +0x20 */
};

struct Record00dd1460 {
    u8 unknown0[0x10];
    Function00dd1460 *function; /* +0x10: to FUN_013bfd90 */
    void *environment;          /* +0x18: to FUN_013bfaf0 */
    u8 unknown20;
    Inline00dd1460 inline21;      /* +0x21 */
    Upvalue00dd2e60 *pointers[1]; /* +0x38: function->count of them, to FUN_013bf700 */
};

struct ValueArray00dd18c0 {
    HksObject *values; /* +0x0 */
    u64 count;         /* +0x8 */
};

struct Record00dd1af0 {
    void *unknown0;  /* +0x0: to FUN_013bf510 */
    HksObject value; /* +0x8 */
    void *unknown18; /* +0x18: to FUN_013bfee0 */
    void *unknown20; /* +0x20: to FUN_013bfee0 */
};

struct Element00dd1f20 {
    u8 unknown0[0x20];
};

struct Array00dd1f20 {
    Element00dd1f20 *elements; /* +0x0 */
    int count;                 /* +0x8 */
};

struct Element00dd2500 {
    u8 unknown0[0x10];
};

struct Array00dd2500 {
    u32 count;                 /* +0x0 */
    Element00dd2500 *elements; /* +0x8 */
};

/* derived names: the allocator of the state at +0x10 of the walker (a
 * block, its old size and its new one; 0 and 0 to allocate) */
struct HksAllocator00dd1740 {
    void *(*allocate)(void *user, void *block, size_t oldSize, size_t newSize); /* +0x0 */
    void *user;                                                                 /* +0x8 */
};

struct HksState00dd1740 {
    u8 unknown0[0x10];
    HksAllocator00dd1740 *allocator; /* +0x10 */
};

/* derived names: a node of the walker's tree of the objects it has walked,
 * ordered by address */
struct VisitedNode00dd1740 {
    const void *object;         /* +0x0 */
    VisitedNode00dd1740 *left;  /* +0x8 */
    VisitedNode00dd1740 *right; /* +0x10 */
};

/* externalAllocate (the name from its assertion message, MemoryManager.h of
 * the VM): a block from the state's allocator, which must be 8-byte
 * aligned */
inline void *externalAllocate(HksState00dd1740 *state, size_t size)
{
    HksAllocator00dd1740 *allocator = state->allocator;
    void *allocation = allocator->allocate(allocator->user, 0, 0, size);
    if (!(((size_t)allocation & 0x7) == 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xab100901, "((hksSize)allocation & 0x7) == 0", "externalAllocate",
               "Havok Script requires allocations to be at least 8-byte aligned",
               "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../"
               "source/Debugger/../Platform/String/../../virtualMachine/String/../Memory/"
               "MemoryManager.h",
               59);
        __builtin_trap();
    }
    return allocation;
}

/* derived names: slot 12's array: 16-byte elements and their signed count */
struct Element00dd1740 {
    u8 unknown0[0x10];
};

struct Array00dd1740 {
    Element00dd1740 *elements; /* +0x0 */
    int count;                 /* +0x8 */
};

/* derived names: slot 18's record: a pointer to FUN_013bf510, arrays of
 * the kinds of slots 28, 13 and 12, two values */
struct Record00dd1b80 {
    u8 unknown0[0x48];
    void *unknown48; /* +0x48: to FUN_013bf510 */
    u8 unknown50[0x18];
    Array00dd1f20 array68;      /* +0x68 */
    ValueArray00dd18c0 array78; /* +0x78 */
    u8 unknown88[0x20];
    Array00dd1740 arrayA8; /* +0xa8 */
    u8 unknownB8[0x8];
    HksObject valueC0; /* +0xc0 */
    u8 unknownD0[0x18];
    HksObject valueE8; /* +0xe8 */
};

/* derived names: slot 15's record: its first 0x58 bytes of slot 17's kind
 * (the body there empty), a record of slot 18's kind, a table of slot 21's
 * kind (0xdd1dc0), a value, a block of slot 41's kind (an array of
 * pointers) walked only when its 16-bit field at +0xa is set, and pointers
 * to the object's own marks */
struct Header00dd1950 {
    u8 unknown0[0x58];
};

struct Table00dd1950 {
    u8 unknown0[0x10];
};

struct Collected00dd22f0;

struct Block00dd1950 {
    Collected00dd22f0 **items; /* +0x0 */
    u16 count;                 /* +0x8: of the items (slot 41) */
    u16 unknownA;              /* +0xa: slot 15 walks the block when it is set */
    u8 unknownC[0x4];
};

struct Record00dd1950 {
    Header00dd1950 header;   /* +0x0 */
    Record00dd1b80 record58; /* +0x58 */
    u8 unknown150[0x58];
    Table00dd1950 table1a8; /* +0x1a8 */
    u8 unknown1b8[0x10];
    HksObject value1c8;     /* +0x1c8 */
    Block00dd1950 block1d8; /* +0x1d8 */
    void *unknown1e8;       /* +0x1e8: to FUN_013bfaf0 */
    u8 unknown1f0[0x8];
    void *unknown1f8; /* +0x1f8: to FUN_013bfc40 */
    void *unknown200; /* +0x200: to FUN_013bf510 */
    u8 unknown208[0x380];
    void *unknown588; /* +0x588: to FUN_013bfee0 */
};

/* derived names: slot 35's record: a 16-byte block (slot 36's kind, the
 * body there empty), an array of pointers (slot 37's kind: the unsigned
 * count, the pointers), a pointer to FUN_013bf850 and an array of slot 38's
 * kind */
struct Block00dd2190 {
    u8 unknown0[0x10];
};

struct PointerArray00dd2190 {
    u32 count;    /* +0x0 */
    void **items; /* +0x8 */
};

struct Record00dd2190 {
    u8 unknown0[0x8];
    Block00dd2190 block8;          /* +0x8 */
    PointerArray00dd2190 pointers; /* +0x18 */
    void *unknown28;               /* +0x28: to FUN_013bf850 */
    u8 unknown30[0x8];
    Array00dd2500 array38; /* +0x38 */
};

/* derived names: what slot 86 of the vtable at 0x16bba90 prints as
 * "UserData": its size from the header word's bits 10 and up, less the
 * 0x20-byte block, and its environment at +0x10 */
struct UserData00dd2cf0 {
    u64 header; /* +0x0 */
    u8 unknown8[0x8];
    const void *environment; /* +0x10 */
};

/* derived names: what slot 89 of the vtable at 0x16bba90 prints as
 * "Method": the names of its debug record (strings whose characters start
 * at +0x14) and the pointers it holds */
struct String00dd2f70 {
    u8 unknown0[0x14];
    char chars[1]; /* +0x14 */
};

struct Debug00dd2f70 {
    u8 unknown0[0x28];
    const String00dd2f70 *source; /* +0x28 */
    const String00dd2f70 *name;   /* +0x30 */
};

struct Method00dd2f70 {
    u8 unknown0[0x38];
    u32 count;                  /* +0x38 */
    void **items;               /* +0x40 */
    const Debug00dd2f70 *debug; /* +0x48 */
};

class Object013c8500 /* derived name */
{
  public:
    virtual void release() /* derived name */
    {
        if (visited) {
            FUN_013bf660(visited, state);
            visited = 0;
        }
    }

    virtual ~Object013c8500();

    /* slots 3 to 158 (the vtable has 159; most hold the shared `ret` at
     * 0x1af750): a slot the bytes call carries its argument, the others
     * are not traced. The walks of slots 19 and 26 call four slots on each
     * element: three hooks 39 slots apart around the element's own mark */
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void visit00dd13d0(const Record00dd13d0 *record); /* 0xdd13d0 */
    virtual void visit00dd1460(const Record00dd1460 *record); /* 0xdd1460 */
    virtual void slot10();
    virtual void markElement00dd1740(const Element00dd1740 *element);
    virtual void visit00dd1740(const Array00dd1740 *array);      /* 0xdd1740 */
    virtual void visit00dd18c0(const ValueArray00dd18c0 *array); /* 0xdd18c0 */
    virtual void slot14();
    virtual void visit00dd1950(const Record00dd1950 *record); /* 0xdd1950 */
    virtual void visit00dd1af0(const Record00dd1af0 *record); /* 0xdd1af0 */
    virtual void markHeader(const Header00dd1950 *header);
    virtual void visit00dd1b80(const Record00dd1b80 *record);  /* 0xdd1b80 */
    virtual void visitValues(const ValueRange00dd1cf0 *range); /* 0xdd1cf0 */
    virtual void markValue(const HksObject *value);            /* 0xdd1d60 in 0x16bba90 */
    virtual void markTable(const Table00dd1950 *table);
    virtual void markInline(const Inline00dd1460 *value);
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void visitEntries(const EntryRange00dd1e90 *range); /* 0xdd1e90 */
    virtual void markEntry(const Entry00dd1e90 *entry);
    virtual void visit00dd1f20(const Array00dd1f20 *array); /* 0xdd1f20 */
    virtual void markElement32(const Element00dd1f20 *element);
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void visit00dd2190(const Record00dd2190 *record); /* 0xdd2190 */
    virtual void markBlock(const Block00dd2190 *block);
    virtual void markPointers(const PointerArray00dd2190 *array);
    virtual void visit00dd2500(const Array00dd2500 *array); /* 0xdd2500 */
    virtual void markElement16(const Element00dd2500 *element);
    virtual void markReference(Collected00dd22f0 *const *reference);
    virtual void visit00dd22f0(const Block00dd1950 *block); /* 0xdd22f0 */
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void beforeElement00dd1740(const Element00dd1740 *element);
    virtual void beforeArray00dd1740(const Array00dd1740 *array);
    virtual void beforeValueArray(const ValueArray00dd18c0 *array);
    virtual void slot54();
    virtual void slot55();
    virtual void beforeHeader(const Header00dd1950 *header);
    virtual void beforeRecord00dd1b80(const Record00dd1b80 *record);
    virtual void slot58();
    virtual void beforeValue(const HksObject *value);
    virtual void beforeTable(const Table00dd1950 *table);
    virtual void beforeInline(const Inline00dd1460 *value);
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void beforeEntry(const Entry00dd1e90 *entry);
    virtual void beforeArray32(const Array00dd1f20 *array);
    virtual void beforeElement32(const Element00dd1f20 *element);
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void beforeBlock(const Block00dd2190 *block);
    virtual void beforePointers(const PointerArray00dd2190 *array);
    virtual void beforeArray16(const Array00dd2500 *array);
    virtual void beforeElement16(const Element00dd2500 *element);
    virtual void beforeReference(Collected00dd22f0 *const *reference);
    virtual void beforeBlock1d8(const Block00dd1950 *block);
    virtual void enterThread(const lua_State *state);
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void enterUserData(const UserData00dd2cf0 *userData);
    virtual void enterCFunction(const Record00dd13d0 *function);
    virtual void enterClosure(const Record00dd1460 *closure);
    virtual void enterMethod(const Method00dd2f70 *method);
    virtual void enterElement00dd1740(const Element00dd1740 *element);
    virtual void enterArray00dd1740(const Array00dd1740 *array);
    virtual void enterValueArray(const ValueArray00dd18c0 *array);
    virtual void slot93();
    virtual void slot94();
    virtual void enterHeader(const Header00dd1950 *header);
    virtual void enterRecord00dd1b80(const Record00dd1b80 *record);
    virtual void slot97();
    virtual void enterValue(const HksObject *value);
    virtual void enterTable(const Table00dd1950 *table);
    virtual void enterInline(const Inline00dd1460 *value);
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void enterEntry(const Entry00dd1e90 *entry);
    virtual void enterArray32(const Array00dd1f20 *array);
    virtual void enterElement32(const Element00dd1f20 *element);
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void enterBlock(const Block00dd2190 *block);
    virtual void enterPointers(const PointerArray00dd2190 *array);
    virtual void enterArray16(const Array00dd2500 *array);
    virtual void enterElement16(const Element00dd2500 *element);
    virtual void enterReference(Collected00dd22f0 *const *reference);
    virtual void enterBlock1d8(const Block00dd1950 *block);
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void afterElement00dd1740(const Element00dd1740 *element);
    virtual void afterArray00dd1740(const Array00dd1740 *array);
    virtual void afterValueArray(const ValueArray00dd18c0 *array);
    virtual void slot132();
    virtual void slot133();
    virtual void afterHeader(const Header00dd1950 *header);
    virtual void afterRecord00dd1b80(const Record00dd1b80 *record);
    virtual void slot136();
    virtual void afterValue(const HksObject *value);
    virtual void afterTable(const Table00dd1950 *table);
    virtual void afterInline(const Inline00dd1460 *value);
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void afterEntry(const Entry00dd1e90 *entry);
    virtual void afterArray32(const Array00dd1f20 *array);
    virtual void afterElement32(const Element00dd1f20 *element);
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void afterBlock(const Block00dd2190 *block);
    virtual void afterPointers(const PointerArray00dd2190 *array);
    virtual void afterArray16(const Array00dd2500 *array);
    virtual void afterElement16(const Element00dd2500 *element);
    virtual void afterReference(Collected00dd22f0 *const *reference);
    virtual void afterBlock1d8(const Block00dd1950 *block);

  protected:
    /* derived names: one element through its kind's four slots, in the
     * order the walks call them (before, enter, mark, after) */
    void visit(const HksObject *value)
    {
        beforeValue(value);
        enterValue(value);
        markValue(value);
        afterValue(value);
    }

    void visit(const Inline00dd1460 *value)
    {
        beforeInline(value);
        enterInline(value);
        markInline(value);
        afterInline(value);
    }

    void visit(const Element00dd1f20 *element)
    {
        beforeElement32(element);
        enterElement32(element);
        markElement32(element);
        afterElement32(element);
    }

    void visit(const Element00dd2500 *element)
    {
        beforeElement16(element);
        enterElement16(element);
        markElement16(element);
        afterElement16(element);
    }

    void visit(const Block00dd2190 *block)
    {
        beforeBlock(block);
        enterBlock(block);
        markBlock(block);
        afterBlock(block);
    }

    void visit(const PointerArray00dd2190 *array)
    {
        beforePointers(array);
        enterPointers(array);
        markPointers(array);
        afterPointers(array);
    }

    /* derived name: the node of the tree for the object, or the one under
     * which a node for it goes (null when the tree is empty) */
    VisitedNode00dd1740 *closestVisited(const void *object) const
    {
        VisitedNode00dd1740 *node = visited;
        while (node) {
            if (object < node->object) {
                if (!node->left)
                    break;
                node = node->left;
            } else if (node->object < object) {
                if (!node->right)
                    break;
                node = node->right;
            } else
                break;
        }
        return node;
    }

    /* derived name: whether the object is walked for the first time; a
     * node for it is added to the tree when it is (one copy for each kind of
     * object) */
    template <class T> bool firstVisit(const T *pointer)
    {
        const void *object = pointer;
        VisitedNode00dd1740 *node = visited;
        while (node) {
            if (node->object > object && node->left)
                node = node->left;
            else if (node->object < object && node->right)
                node = node->right;
            else
                break;
        }
        if (node && node->object == object)
            return false;
        VisitedNode00dd1740 *added = static_cast<VisitedNode00dd1740 *>(
            externalAllocate(state, sizeof(VisitedNode00dd1740)));
        added->object = object;
        added->left = 0;
        added->right = 0;
        VisitedNode00dd1740 *parent = closestVisited(object);
        if (!parent)
            visited = added;
        else if (object < parent->object)
            parent->left = added;
        else if (parent->object < object)
            parent->right = added;
        return true;
    }

    void visit(Collected00dd22f0 *object)
    {
        beforeReference(&object);
        if (object && firstVisit(object)) {
            enterReference(&object);
            markReference(&object);
            afterReference(&object);
        }
    }

    void visit(const Element00dd1740 *element)
    {
        beforeElement00dd1740(element);
        if (element && firstVisit(element)) {
            enterElement00dd1740(element);
            markElement00dd1740(element);
            afterElement00dd1740(element);
        }
    }

    void visit(const Array00dd1740 *array)
    {
        beforeArray00dd1740(array);
        enterArray00dd1740(array);
        visit00dd1740(array);
        afterArray00dd1740(array);
    }

    void visit(const ValueArray00dd18c0 *array)
    {
        beforeValueArray(array);
        enterValueArray(array);
        visit00dd18c0(array);
        afterValueArray(array);
    }

    void visit(const Array00dd1f20 *array)
    {
        beforeArray32(array);
        enterArray32(array);
        visit00dd1f20(array);
        afterArray32(array);
    }

    void visit(const Header00dd1950 *header)
    {
        beforeHeader(header);
        enterHeader(header);
        markHeader(header);
        afterHeader(header);
    }

    void visit(const Record00dd1b80 *record)
    {
        beforeRecord00dd1b80(record);
        enterRecord00dd1b80(record);
        visit00dd1b80(record);
        afterRecord00dd1b80(record);
    }

    void visit(const Table00dd1950 *table)
    {
        beforeTable(table);
        enterTable(table);
        markTable(table);
        afterTable(table);
    }

    void visit(const Block00dd1950 *block)
    {
        beforeBlock1d8(block);
        enterBlock1d8(block);
        visit00dd22f0(block);
        afterBlock1d8(block);
    }

    void visit(const Array00dd2500 *array)
    {
        beforeArray16(array);
        enterArray16(array);
        visit00dd2500(array);
        afterArray16(array);
    }

  private:
    VisitedNode00dd1740 *visited; /* +0x8: the objects already walked */
    HksState00dd1740 *state;      /* +0x10 */
};

#endif
