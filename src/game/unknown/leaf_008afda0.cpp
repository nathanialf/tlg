/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af6e0 (stored by FUN_008afbf0 FUN_008afc40): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008afda0 /* derived name */
{
  public:
    virtual Object008afda0 *FUN_008afbf0(void *where); /* derived name */
    virtual Object008afda0 *FUN_008afc40(void *where); /* derived name */
    virtual void FUN_008afc90(void *argument);         /* derived name */
    virtual const void *FUN_008afd60();                /* derived name */
    virtual void FUN_008afd70(bool deallocate);        /* derived name */
    virtual ~Object008afda0();
    virtual void *FUN_008afdc0(); /* derived name */

  private:
    unsigned char stored[32]; /* +0x8, 32 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008afda0::FUN_008afd70(bool deallocate)
{
    this->~Object008afda0();
    if (deallocate)
        operator delete(this);
}

Object008afda0::~Object008afda0() {}

void *Object008afda0::FUN_008afdc0()
{
    return &stored;
}
