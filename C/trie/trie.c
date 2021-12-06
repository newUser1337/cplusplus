#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trie.h"
#include "list.h"

TRNode *_trie_create_node();
void _trie_add_word_rec(TRNode *, char *, int);
TRNData *_trie_create_list_data(char);

void _trie_print_words(TRNode *);
void _trie_print_word(TRNode *);

void _trie_destr_node_rec(TRNode *);
void _trie_search_rec(TRNode *, char *, size_t, List *);

void print_symbol(void *);
int cmp_symbol(void *, void *);

Trie *trie_init()
{
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = _trie_create_node();

    return trie;
}

TRNode *_trie_create_node()
{
    TRNode *node = (TRNode *)malloc(sizeof(TRNode));
    node->keys = NULL;
    node->parent = NULL;
    node->isFinish = 0;

    return node;
}

void trie_add_word(Trie *trie, char *word)
{
    _trie_add_word_rec(trie->root, word, 0);
}

void _trie_add_word_rec(TRNode *node, char *word, int pos)
{
    if (word[pos] == '\0')
    {
        node->isFinish = 1;
        return;
    }

    LNode *lnode;
    TRNData search, *newdata;
    search.symbol = word[pos];

    if (node->keys == NULL)
        node->keys = list_init(cmp_symbol, print_symbol);
    lnode = list_search(node->keys, &search);
    if (lnode == NULL)
    {
        newdata = _trie_create_list_data(word[pos]);
        newdata->trie_next = _trie_create_node();
        newdata->trie_next->parent = node;
        lnode = list_insert(node->keys, newdata);
    }
    _trie_add_word_rec(((TRNData *)lnode->data)->trie_next, word, ++pos);
}

TRNData *_trie_create_list_data(char symbol)
{
    TRNData *newdata = (TRNData *)malloc(sizeof(TRNData));
    newdata->symbol = symbol;
    newdata->trie_next = NULL;

    return newdata;
}

void trie_print(Trie *trie)
{
    if (trie->root->keys == NULL || trie->root->keys->first == NULL)
        printf("Trie is empty\n");
    else
        _trie_print_words(trie->root);
}

void _trie_print_words(TRNode *node)
{
    if (node->isFinish)
    {
        _trie_print_word(node);
        printf("\n");
    }
    if (node->keys == NULL)
        return;
    LNode *lnode = node->keys->first;
    while (lnode != NULL)
    {
        _trie_print_words(((TRNData *)lnode->data)->trie_next);
        lnode = lnode->next;
    }
}

void _trie_print_word(TRNode *node)
{
    if (node->parent == NULL)
        return;
    _trie_print_word(node->parent);
    LNode *lnode = node->parent->keys->first;
    while (((TRNData *)lnode->data)->trie_next != node)
        lnode = lnode->next;
    printf("%c", ((TRNData *)lnode->data)->symbol);
}

void print_symbol(void *data)
{
    printf("%c", ((TRNData *)data)->symbol);
}
int cmp_symbol(void *data_1, void *data_2)
{
    TRNData *A = data_1, *B = data_2;
    if (A->symbol < B->symbol)
        return -1;
    else if (A->symbol > B->symbol)
        return 1;
    else
        return 0;
}

void trie_destr(Trie **trie)
{
    _trie_destr_node_rec((*trie)->root);
    free(*trie);
    *trie = NULL;
}

void _trie_destr_node_rec(TRNode *node)
{
    if (node->keys != NULL)
    {
        LNode *lnode = node->keys->first;
        while (lnode != NULL)
        {
            _trie_destr_node_rec(((TRNData *)lnode->data)->trie_next);
            free(lnode->data);
            lnode = lnode->next;
        }
        list_destr(&node->keys);
    }
    free(node);
}

void trie_search(Trie *trie, char *str, List *result)
{
    _trie_search_rec(trie->root, str, 0, result);
}

void _trie_search_rec(TRNode *node, char *str, size_t cur, List *result)
{
    if (node->keys == NULL)
        return;

    size_t next_pos;
    LNode *lnode = node->keys->first;
    while (lnode != NULL)
    {
        next_pos = (str[cur] == ((TRNData *)lnode->data)->symbol) ? cur + 1 : 0;
        if (str[next_pos] == '\0')
        {
            _trie_get_words(((TRNData *)lnode->data)->trie_next, result);
            next_pos = 0;
        }
        _trie_search_rec(((TRNData *)lnode->data)->trie_next, str, next_pos, result);
        lnode = lnode->next;
    }
}