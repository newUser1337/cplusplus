#ifndef __TRIE_CPP__
#define __TRIE_CPP__

#include <iostream>
#include <list>

class TNode
{
private:
    int isFinish;
    TNode *parent;
    std::list<TNode *> keys;
    char symbol;
    void GetWord(std::string *);

public:
    TNode();
    TNode(char, TNode *);
    ~TNode();

    int GetFinish();
    TNode *GetParent();
    std::list<TNode *> *GetKeys();
    char GetSymbol();

    void SetFinish();
    void AddNode(TNode *);
    TNode *SearchKey(char);

    std::string GetWord();

    friend std::ostream &operator<<(std::ostream &, TNode &);
};

class Trie
{
private:
    TNode *root;

    void TrieDestr(TNode *);
    TNode *CreateNode();
    TNode *CreateNode(char, TNode *);
    void AddWord(TNode *, std::string *, std::string::iterator);
    void SearchWords(TNode *, std::string *, std::string::iterator, std::list<std::string> *);
    void AppendWord(TNode *, std::list<std::string> *);

public:
    Trie();
    ~Trie();

    void AddWord(std::string);
    TNode *GetRoot();

    void SearchWords(std::string, std::list<std::string> *);

    friend std::ostream &operator<<(std::ostream &, Trie &);
};

#endif