/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c2c40 (stored by FUN_01270ea0 FUN_01270ee0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01270f70 /* derived name */
{
  public:
    virtual Object01270f70 *FUN_01270ea0(void *where); /* derived name */
    virtual Object01270f70 *FUN_01270ee0(void *where); /* derived name */
    virtual void FUN_01270f20(void *argument);         /* derived name */
    virtual const void *FUN_01270f30();                /* derived name */
    virtual void FUN_01270f40(bool deallocate);        /* derived name */
    virtual ~Object01270f70();
    virtual void *FUN_01270f90(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object01270f70::FUN_01270f40(bool deallocate)
{
    this->~Object01270f70();
    if (deallocate)
        operator delete(this);
}

Object01270f70::~Object01270f70() {}

void *Object01270f70::FUN_01270f90()
{
    return &stored;
}
