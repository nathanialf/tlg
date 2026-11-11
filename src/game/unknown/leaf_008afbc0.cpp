/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af690 (stored by FUN_008afad0 FUN_008afb10): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008afbc0 /* derived name */
{
  public:
    virtual Object008afbc0 *FUN_008afad0(void *where); /* derived name */
    virtual Object008afbc0 *FUN_008afb10(void *where); /* derived name */
    virtual void FUN_008afb50(void *argument);         /* derived name */
    virtual const void *FUN_008afb80();                /* derived name */
    virtual void FUN_008afb90(bool deallocate);        /* derived name */
    virtual ~Object008afbc0();
    virtual void *FUN_008afbe0(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008afbc0::FUN_008afb90(bool deallocate)
{
    this->~Object008afbc0();
    if (deallocate)
        operator delete(this);
}

Object008afbc0::~Object008afbc0() {}

void *Object008afbc0::FUN_008afbe0()
{
    return &stored;
}
