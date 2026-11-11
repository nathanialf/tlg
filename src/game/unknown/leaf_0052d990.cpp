/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16ab308 (config/vtables.derived.base.txt; stored by FUN_0052c710
 * FUN_0052d470 FUN_0052d890): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
#include <new>

namespace std
{
[[noreturn]] void _Xbad_alloc();
}

class Object0052d470 /* derived name */
{
  public:
    virtual Object0052d470 *FUN_0052d470(void *where); /* derived name */
    virtual Object0052d470 *FUN_0052d890(void *where); /* derived name */
    virtual void FUN_0052d8d0(void *argument);         /* derived name */
    virtual const void *FUN_0052d950();                /* derived name */
    virtual void FUN_0052d960(bool deallocate);        /* derived name */
    virtual ~Object0052d470();
    virtual void *FUN_0052d9b0(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object0052d470::FUN_0052d960(bool deallocate)
{
    this->~Object0052d470();
    if (deallocate)
        operator delete(this);
}

Object0052d470::~Object0052d470() {}

void *Object0052d470::FUN_0052d9b0()
{
    return &stored;
}

/* slots 0 and 1: copy the object into where, or into a new block when given
 * none (the C++ library's allocate: bad_alloc, _Xbad_alloc with its NID
 * verified, when operator new returns null) */
// NONMATCHING: the null test of operator new's result is folded away: 4.0.0's InferFunctionAttrs marks _Znwm nonnull (BuildLibCalls.cpp:686) and InstCombine's icmp simplification (InstructionSimplify.cpp:2085) drops the test and the _Xbad_alloc call; the base keeps `test rax, rax; je` to the call (135 game functions do, none matched)
Object0052d470 *Object0052d470::FUN_0052d470(void *where)
{
    if (where == 0) {
        where = operator new(sizeof(Object0052d470));
        if (where == 0)
            std::_Xbad_alloc();
    }
    return new (where) Object0052d470(*this);
}

Object0052d470 *Object0052d470::FUN_0052d890(void *where)
{
    if (where == 0) {
        where = operator new(sizeof(Object0052d470));
        if (where == 0)
            std::_Xbad_alloc();
    }
    return new (where) Object0052d470(*this);
}
