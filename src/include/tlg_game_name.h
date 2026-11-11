/* src/include/tlg_game_name.h: the game's interned name and the tables of
 * named values built from it (game region; docs/TARGETS.md). Every name here
 * is derived (the executable is stripped and no string names them). */
#ifndef TLG_GAME_NAME_H
#define TLG_GAME_NAME_H

#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: one entry of the name table at 0x17ac870, 32 bytes,
 * indexed by a Name's index (`shl 5`): the string at +0x0 (read by
 * FUN_0138d9d0) and the reference count at +0x10, which the Name's
 * destructor decrements (`lock xadd`, FUN_00a660b0). */
struct NameTableEntry017ac870 /* derived name */
{
    const char *string0; /* +0x0 */
    u8 unknown8[8];
    int references10; /* +0x10 */
    u8 unknown14[0xc];
};

extern NameTableEntry017ac870 D_17ac870[];

/* derived names: FUN_013bad90 hashes a string (it takes its length itself,
 * strlen at 0x13bad9a), FUN_013baad0 interns it under that hash and its
 * length (the last argument 1) and returns its index, FUN_00d66e30 frees the
 * entry of an index whose last reference is gone. */
unsigned FUN_013bad90(const char *string); /* derived name */
unsigned FUN_013baad0(const char *string, unsigned hash, size_t length,
                      bool add);   /* derived name */
void FUN_00d66e30(unsigned index); /* derived name */

/* derived names: an interned name, the 4-byte index of its entry. Built from
 * a string array its length is the array's (the callers pass a constant,
 * `mov edx, 5` for "FALSE" in FUN_00a653b0); the destructor drops the
 * entry's reference, inlined in the array destructors FUN_00a660b0 and on. */
class Name /* derived name */
{
  public:
    template <size_t N>
    Name(const char (&string)[N]) : index(FUN_013baad0(string, FUN_013bad90(string), N - 1, true))
    {
    }

    ~Name()
    {
        if (index != 0) {
            if (__sync_fetch_and_sub(&D_17ac870[index].references10, 1) == 1)
                FUN_00d66e30(index);
            index = 0;
        }
    }

    unsigned index; /* +0x0 */
};

/* derived names: one value of a NamedValueTable: its name, a display colour
 * (three bytes) and the value. 12 bytes. */
struct NamedValue /* derived name */
{
    Name name;    /* +0x0 */
    u8 colour[3]; /* +0x4 */
    int value;    /* +0x8 */
};

/* derived names: the data of a table of named values over a static array
 * of them, shared by the nine classes whose vtables are 0x16ce490 to
 * 0x16ce6d0 (0x48 apart; each the guarded local static of its accessor,
 * FUN_00a64740 and FUN_00a65190 to FUN_00a65bd0). The int at +0xc is 4 in
 * all nine. Each class declares its own virtual functions: their bodies are
 * the same but for slot 3, and the linker folded them (slots 0 and 1 on the
 * shared empty and deleting bodies 0x1af750 and 0x21a00, slot 2 on 0x1af750,
 * slot 4 on 0xdde740, which returns its int argument, slot 5 on FUN_0138d9d0,
 * the name's string of an index or else the second argument, slot 6 on
 * FUN_0138da00, a lookup by string). Slot 3 is each class's own
 * (FUN_0138d450 and on: the entry of an index, else the class's static
 * "<ERROR>" entry). The classes have no common polymorphic base: an empty
 * destructor inherited from one is called through a cast in the complete
 * destructor and its __cxa_atexit is then kept, which the accessors do not
 * register (GlobalOpt drops the registration of an empty destructor). */
struct NamedValueTable /* derived name */
{
    template <int N>
    explicit NamedValueTable(const NamedValue (&values)[N])
        : unknown8(0), unknownC(4), count(N), values(values)
    {
    }

    int unknown8;             /* +0x8 */
    int unknownC;             /* +0xc */
    int count;                /* +0x10 */
    const NamedValue *values; /* +0x18 */
};

/* derived names: the nine tables (the class names are the vtable rows of
 * config/vtables.derived.base.txt); slot 3 is each one's own. */
class Object016ce490 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce490(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce490() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce490 &FUN_00a64740(); /* derived name */

class Object016ce4d8 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce4d8(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce4d8() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce4d8 &FUN_00a65190(); /* derived name */

class Object016ce520 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce520(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce520() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce520 &FUN_00a653b0(); /* derived name */

class Object016ce568 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce568(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce568() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce568 &FUN_00a65500(); /* derived name */

class Object016ce5b0 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce5b0(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce5b0() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce5b0 &FUN_00a65650(); /* derived name */

class Object016ce5f8 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce5f8(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce5f8() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce5f8 &FUN_00a657a0(); /* derived name */

class Object016ce640 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce640(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce640() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce640 &FUN_00a658f0(); /* derived name */

class Object016ce688 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce688(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce688() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce688 &FUN_00a65a40(); /* derived name */

class Object016ce6d0 : public NamedValueTable /* derived name */
{
  public:
    template <int N>
    explicit Object016ce6d0(const NamedValue (&values)[N]) : NamedValueTable(values)
    {
    }

    virtual ~Object016ce6d0() {}

    virtual void unknown2() {}

    virtual const NamedValue *entry(int index) const;
    virtual int value(int index) const;
    virtual const char *name(int index, const char *fallback) const;
    virtual int find(const char *string) const;
};

Object016ce6d0 &FUN_00a65bd0(); /* derived name */

#endif
