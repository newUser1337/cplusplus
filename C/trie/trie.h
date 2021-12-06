#ifndef __TRIE__
#define __TRIE__

#include "list.h"

typedef struct TRNode
{
    struct TRNode *parent;
    List *keys;
    int isFinish;
} TRNode;

typedef struct Trie
{
    TRNode *root;
} Trie;

typedef struct TRNData
{
    char symbol;
    TRNode *trie_next;
} TRNData;

Trie *trie_init();
void trie_add_word(Trie *, char *);
void trie_print(Trie *);

void trie_destr(Trie **);
#endif