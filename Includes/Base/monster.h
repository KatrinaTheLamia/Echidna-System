/*
= %(Echidna System-Includes)path/Base/monster.h
Author := %(TheLamia)user
Group := %(NIMHLabs)group
License := Artistic
Project := %(Echidna System)project
Creation := 3177-3-23 ???
Contributors := None... you bastards

Basic monster information for running Echidna Gaming Framework Operating
System.

Policy is still, put something up--even if it is a ridiculous place holder
that will make you want to stab my eyes out (as you had to see it, but 
you'd still like use of your own eyes... so you do the whole empathic pain
thing). Either way, the notion is to just keep putting code out on this...
even if the code is complete and total PoC code. I am going to guess it
likely will not be Proof of Concept that PoC stands for. Not at first 
anyways.

== Revisions
+ 3177-3-26 more fleshed out file stuffs
+ 3177-3-26 silly documentation
+ 3177-3-26 documentation structure
+ 3177-3-26 incomplete code prototyping

== TODO
+ 3177-3-26 create checksum system
! 3177-3-26 actually read the utf api docs.
! 3177-3-26 remove that horrible function pointer in monster setup.
! 3177-3-26 make this code not commit seppuku on compile and run
! 3177-3-26 make certain to have good documentation
! 3177-3-26 less lazy attempt to comment this.
+ 3177-3-26 create logging system
+ 3177-3-26 create monster protection service
+ 3177-3-26 create memory encryption system (for when stuff is not 
  being checked on, it can be encrypted into memory and removed the 
  unencrypted versions)
! 3177-3-26 sound less convincing on this being a gaming FlOSS FWOS 
  to get news stories about this being a set of terrorist tools for
  tooling with terrorism... because... TERRORISM! RAR! (honestly, the 
  sales for that is, if terrorists can use this system without worry,
  it means your software is not likely to be pirated)
+ 3177-3-26 JIT service thingy
?+& 3177-3-26 maybe JIT cache of this gaming FlOSS FWOS to the Z80 target
   might do something good (instead of hilariously horrid looking fail... 
   which is also good).
! 3177-3-26 Echidna does not add enough Science! To computer science.

*/

/*
Standard header file watches. I'd be silly for explaining each. You 
do not want me to be silly, do you? DO YOU?!?
 */
#ifndef __ECHIDNA_MONSTER_H__
#define __ECHIDNA_MONSTER_H__

#ifdef __cplusplus
extern "c" {
#endif

/*
 * We are now into full on delicious tasty c code. This is mostly 
 * to allow the actual system to compile onto nearly anything. Except 
 * older Sinclair Spectrum ZX, C=64, Timex Radio Shack PC (z80) and 
 * 6580a... even those are the ultimate gaming systems, I am not clever
 * enough to code the ultimate Game Framework OS (FWOS) onto them... 
 * yet (maybe get a few "standards" on this stuff, and then port from 
 * C into Z80, 6580a and SH Assembler... and then have a mental health 
 * support team show up at my door, because at which point, I will have 
 * demonstrated several symptoms in the DSM-V to indicate I am certifiable
 * just by trying that).
 */


/*

Echidna Type & Echidna Shortcut += wildcard_obj_p << """
a void pointer, to make structure definitions a little easier to read. This
means we have no clue what this will point to. Keep stuff open.
"""

Echidna Type & Echnida Shortcut += selfobj_p << """
a void pointer, that means the contents should be this own objects stuff.
If not, it will do all sorts of mean and evil things to this program. So
try not to be mean, okay?
"""

Echidna Type & Echidna Shortcut += side_effect << """
just another way to say void function. This more specifically means, this
function can and will cause a side effect in the arguments present.

If your function does not return anything, and does not do a side effect...
you may need to ask, why are you making use of it? Side Effects can be
view items added, memory checked for a piece of data, log file entry 
added, process or thread starting, or just a need to change panties due to 
a ... sushi smell.
"""


 */
typedef void * wildcard_obj_p;
typedef void * selfobj_p;
typedef void side_effect;

/*

Echidna Flags += dna_statu << """
What is the current monster (process) doing for its abilites.

clear (lit: 0) means the process should be running
cleanup (lit: 1) means marked for garbage collect, doing, zoom!
standby (lit: 2) means process is asleep, or not suppose to be running.
locked (lit: 4) means the process is not allowed to be modified... except
   by another process that has locked it. Please, unlock processes when done.
corrupt (lit: 8) means various systems to check if the current process 
   is running ship shape and bristle fashion have shown a few misgivings.
   monster protection services will be sent to check this stuff, outside
   this process (for outside interference).
"""

*/

enum dna_status {
    clear = 0,
    cleanup = 1,
    standby = 2,
    locked = 4,
    corrupt = 8,
};

/*

Echidna Flags += stack_error << """
If we are having stack issues... it means a lot more is wrong that 
probably suspected.

okay (lit: 0) hey, look, its all awesome
stack_overflow (lit: 1) hey, we're really stacked here (other option is
   to return the letter Z)
null_stack (lit: 2) okay, our stack object does not appear to be properly 
   set up, or we have gotten a stack underflow.
strange_stack (lit: 4) one of these "all encompassing" errors these 
   new fangled kids have created. I wish they'd take this and their polio 
   vaccine off my front lawn. Either way, usually means the stack has 
   failled a checksum check.

"""

*/

enum stack_error {
    okay = 0,
    stack_overflow = 1,
    null_stack = 2,
    strange_stack = 4,
};

/*
Echidna Objects += dna_symbol << """
just a simple symbole object. Contains a string indicating our current
locale. The contents of how the symbol can be called by something 
readable.

We have prev and next, to do our stacked heap thing (we also have heap
stacks... because that is how we roll).

Oh yes... and the symbol is checksummed. As a FlOSS FWOS for video 
gaming, we take memory content as serious businesses.

"""

Echidna Shortcut & Echidna Type += dna_symbol_p <<< """
Oh, hey, rather than having those little ugly asterisks all over your
code, we just have an ever hunger coder (I think that is what hungarian 
notion would mean... anything else would not make sense).
"""

*/

/*
 * Note: utfchar is not a real UTF type. I am fully aware of that.
 * This is just to be in here, until after I have looked at those 
 * wonder documents on using UTF in C programs, that I have been
 * delightfully putting off until now.
 *
 * So, rage away at how silly that code is.
 */
typedef struct {
    utfchar *locale;
    utfchar *contents;
    wildcard_obj_p next;
    wildcard_obj_p prev;
    dna_checksum_p sum;
} dna_symbol_dat, dna_symbol;
typedef dna_symbol* dna_symbol_p;

/*
Echidna Objects & Echidna Shortcut += dna_symbol_equiv << """
Because, we need a simple area in memory to say, "okay, fellas, all 
of these symbols in this other weird moonspeak (I think it might be Polish,
who let the Poles onto the computers?) can be quickly converted into a 
real language for us... like Swahili."

This is something that requires programs to use locales ideas. Hear that
THIS REQUIRES YOU TO USE IT!

Echidna Types & Echidna Shortcute += dna_symbol_equiv_p << """
Because your asterisks are not cute like mine... or something.
"""

 */
typedef struct {
    dna_symbol_p sore;
    dna_symbol_p kore;
    wildcard_obj_p next;
    wildcard_obj_p prev;
    dna_checksum_p sum;
} dna_symbol_equiv_dat, dna_symbol_equiv;
typedef dna_symbol_equiv* dna_symbol_equiv_p;

/*
Echidna Objects += dna_object << """
Oh, hey, stuff that should be kept track of as a base universal, 
object object. ShapedLikeItself and all. As this project gets more 
mature (it still giggles at jiggly chests... so not soon) this object
will likely have more useful features...

Right now it has the object's calling symbol. The pointer to the 
actual object itself (for fun, have it recursively point to itself!)

The usually stacked heap setup, with next, prev in nearly everything--
especially if it typically is not something that needs it is here.

Oh, right, and out checksum little bit. Because, memory integrity is 
serious businesses!

"""

Echidna Shortcuts & Echidna Type += dna_object << """
Your asterisk is ugly.. yeah, I said it.
"""

*/
\
typedef struct {
    dna_symbol_p name;
    wildcard_obj_p __self;
    wildcard_obj_p next;
    wildcard_obj_p prev;
    dna_checksum_p sum;
} dna_object_dat dna_object;
typedef dna_object* dna_object_p;

typedef stuct {
    dna_object_p __parent;
    wildcard_obj_p __self;
    unsigned long long max_length;
    unsigned char *stack;
    dna_checksum_p *sum;
} dna_stack_dat dna_stack;
typedef dna_stack* dna_stack_p;

typedef struct {
    dna_object_p __parent;
    dna_symbol_p process_name;
    wildcard_obj_p __self;
    dna_status my_status;
    float cpu_throttle;
    dna_object_p head_heap;
    dna_stack_p my_stack;
    dna_error_p abomination;
    dna_checksum_p sum;
} dna_monster_dat dna_monster;
typedef dna_monster* dna_monster_p;

typedef (inline void)(defaults*)(void);

dna_symbol_p dna_symbol(dna_monster_p, utfchar *, utfchar *);

/*
 * I honestly doubt this is not a very evil thing to do with 
 * something such as this. That is, try to have an inline function
 * enter into this, as though it were nuttin. It exists as a placeholder.
 * That is my story, and when the authorities show up, I am sticking with 
 * it.
 */
dna_monster_p initiate_monster(defaults,dna_symbol_p);

side_effect change_process_name(dna_monster_p, dna_symbol_p);
side_effect change_status(dna_monster_p, dna_status);
side_effect chamge_throttle(dna_monster_p, float);

unsigned char pop(dna_stack_p);
stack_error push(dna_stack_p, unsigned char);
stack_error shift(dna_stack_p, unsigned char);
unsigned char unshift(dna_stack_p);

side_effect local_equiv(dna_symbol_equiv_p, dna_symbol_p, dna_symbol_p);


#ifdef __cplusplus
};
#endif




#endif /* __ECHIDNA_MONSTER_H__  */




