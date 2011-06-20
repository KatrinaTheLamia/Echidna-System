/*

*/

#ifndef __ECHIDNA_MONSTER_H__
#define __ECHIDNA_MONSTER_H__

#ifdef __cplusplus
extern "c" {
#endif

enum dna_status {
    clear = 0,
    cleanup = 1,
    standby = 2,
    locked = 4,
};


typedef struct {
    dna_symbol *name;
    void *__self;
    dna_status my_status;
    float cpu_throttle;
} dna_monster_dat dna_monster;


#ifdef __cplusplus
};
#endif




#endif /* __ECHIDNA_MONSTER_H__  */




