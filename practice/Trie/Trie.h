#ifndef __TRIE_CPP__
#define __TRIE_CPP__

#include <iostream>
#include <list>

class TNode
{
private:
    int isFinish;
    std::list<TNode *> keys;
    TNode *parent;
    char symbol;
    std::ostream &PrintWord(TNode *, std::string *, std::ostream &);

public:
    TNode();
    TNode(char, TNode *);
    ~TNode();

    void SetFinish();
    int GetFinish();
    TNode *GetParent();
    TNode *Search(char);
    char GetSymbol();
    void AddNode(TNode *);

    std::list<TNode *> *GetKeys();

    std::ostream &PrintWord(TNode *, std::ostream &);

    friend std::ostream &operator<<(std::ostream &, TNode &);
};

class Trie
{
private:
    TNode *root;
    TNode *CreateNode();
    TNode *CreateNode(char, TNode *);
    void Add(std::string *, std::string::iterator *, TNode *);
    void Search(TNode *, std::string *, std::string::iterator, std::list<std::string> *);
    void AppendWord(TNode *, std::list<std::string> *);
    void AddWordToResult(TNode *, std::list<std::string> *);
    void AddWordToResult(TNode *, std::string *, std::list<std::string> *);
    void TrieDestr(TNode *);

public:
    Trie();
    ~Trie();

    void Add(std::string);
    TNode *GetRoot();
    void Search(std::string, std::list<std::string> *);

    friend std::ostream &operator<<(std::ostream &, Trie &);
};

#endif