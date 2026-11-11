/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c10d8 (stored by FUN_01061610 FUN_01064210 FUN_01064250): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object01064340 /* derived name */
{
  public:
    virtual Object01064340 *FUN_01064210(void *where); /* derived name */
    virtual Object01064340 *FUN_01064250(void *where); /* derived name */
    virtual void FUN_01064290(void *argument);         /* derived name */
    virtual const void *FUN_01064300();                /* derived name */
    virtual void FUN_01064310(bool deallocate);        /* derived name */
    virtual ~Object01064340();
    virtual void *FUN_01064360(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object01064340::FUN_01064310(bool deallocate)
{
    this->~Object01064340();
    if (deallocate)
        operator delete(this);
}

Object01064340::~Object01064340() {}

void *Object01064340::FUN_01064360()
{
    return &stored;
}
