#include <iostream>
#include <list>
#include "Trie.h"

TNode::TNode()
{
    symbol = ' ';
    parent = NULL;
    isFinish = 0;
}

TNode::TNode(char in_symbol, TNode *in_parent)
{
    symbol = in_symbol;
    parent = in_parent;
    isFinish = 0;
}

TNode::~TNode()
{
}

int TNode::GetFinish()
{
    return isFinish;
}

void TNode::SetFinish()
{
    isFinish = 1;
}

TNode *TNode::GetParent()
{
    return parent;
}

std::list<TNode *> *TNode::GetKeys()
{
    return &this->keys;
}

char TNode::GetSymbol()
{
    return symbol;
}

void TNode::AddNode(TNode *node)
{
    keys.push_back(node);
}

TNode *TNode::SearchKey(char in_symbol)
{
    for (std::list<TNode *>::iterator iter = keys.begin();
         iter != keys.end(); iter++)
        if ((*iter)->GetSymbol() == in_symbol)
            return *iter;
    return NULL;
}

std::ostream &operator<<(std::ostream &s, TNode &node)
{
    if (node.GetFinish())
        s << node.GetWord() << std::endl;

    std::list<TNode *> *keys = node.GetKeys();
    std::list<TNode *>::iterator iter;
    for (iter = keys->begin(); iter != keys->end(); iter++)
        s << **iter;

    return s;
}

std::string TNode::GetWord()
{
    std::string word;
    GetWord(&word);
    return word;
}

void TNode::GetWord(std::string *word)
{
    if (this->GetParent() == NULL)
        return;
    this->GetParent()->GetWord(word);
    word->push_back(this->GetSymbol());
}

Trie::Trie()
{
    root = CreateNode();
}

Trie::~Trie()
{
    TrieDestr(root);
}

void Trie::TrieDestr(TNode *node)
{
    std::list<TNode *>::iterator iter;
    for (iter = node->GetKeys()->begin();
         iter != node->GetKeys()->end();
         iter++)
        TrieDestr(*iter);
    delete node;
}

TNode *Trie::CreateNode()
{
    TNode *node = new TNode();
    return node;
}

TNode *Trie::CreateNode(char in_symbol, TNode *in_parent)
{
    TNode *node = new TNode(in_symbol, in_parent);
    in_parent->AddNode(node);
    return node;
}

void Trie::AddWord(std::string word)
{
    AddWord(root, &word, word.begin());
}

void Trie::AddWord(TNode *node, std::string *word, std::string::iterator iter)
{
    if (iter == word->end())
        node->SetFinish();
    else
    {
        TNode *next = node->SearchKey(*iter);
        if (next == NULL)
            next = CreateNode(*iter, node);
        AddWord(next, word, ++iter);
    }
}

TNode *Trie::GetRoot()
{
    return root;
}

std::ostream &operator<<(std::ostream &s, Trie &trie)
{
    TNode *root = trie.GetRoot();
    for (std::list<TNode *>::iterator iter = root->GetKeys()->begin();
         iter != root->GetKeys()->end(); iter++)
        s << **iter;
    return s;
}

void Trie::SearchWords(std::string str, std::list<std::string> *result)
{
    SearchWords(root, &str, str.begin(), result);
}

void Trie::SearchWords(TNode *node, std::string *str, std::string::iterator iter, std::list<std::string> *result)
{
    iter = (node->GetSymbol() == *iter) ? ++iter : str->begin();
    if (iter == str->end())
        AppendWord(node, result);
    else
    {
        std::list<TNode *> *keys = node->GetKeys();
        std::list<TNode *>::iterator k_iter;
        for (k_iter = keys->begin(); k_iter != keys->end(); k_iter++)
            SearchWords(*k_iter, str, iter, result);
    }
}

void Trie::AppendWord(TNode *node, std::list<std::string> *result)
{
    if (node->GetFinish())
        result->push_back(node->GetWord());

    for (std::list<TNode *>::iterator iter = node->GetKeys()->begin();
         iter != node->GetKeys()->end(); iter++)
        AppendWord(*iter, result);
}