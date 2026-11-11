/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c2b00 (stored by FUN_01270a40 FUN_01270a90): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01270b40 /* derived name */
{
  public:
    virtual Object01270b40 *FUN_01270a40(void *where); /* derived name */
    virtual Object01270b40 *FUN_01270a90(void *where); /* derived name */
    virtual void FUN_01270ae0(void *argument);         /* derived name */
    virtual const void *FUN_01270b00();                /* derived name */
    virtual void FUN_01270b10(bool deallocate);        /* derived name */
    virtual ~Object01270b40();
    virtual void *FUN_01270b60(); /* derived name */

  private:
    unsigned char stored[16]; /* +0x8, 16 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object01270b40::FUN_01270b10(bool deallocate)
{
    this->~Object01270b40();
    if (deallocate)
        operator delete(this);
}

Object01270b40::~Object01270b40() {}

void *Object01270b40::FUN_01270b60()
{
    return &stored;
}
