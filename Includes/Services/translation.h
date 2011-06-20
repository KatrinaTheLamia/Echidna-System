/*
 *
 */

#ifndef __Echidna_Translation_H__
#define __Echidna_Translation_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    dna_monster *__self;
    dna_monster *system_target;
    unsigned char *block;
} dna_codeblock_dat dna_codeblock;

typedef struct{
   dna_monster *__self;
   unsigned long sys_flagset;
   dna_codeblock *code_in;
   dna_code_block *code_out;
} dna_code_equivilencies_dat dna_code_equivilencies;


#ifdef __cplusplu
};
#endif


#endif /* __Echidna_Translation_H__ */


