#include <iostream>
#include <list>
#include "Trie.h"

TNode::TNode()
{
    isFinish = 0;
    parent = NULL;
    symbol = '+';
}

TNode::TNode(char in_symbol, TNode *in_parent)
{
    isFinish = 0;
    parent = in_parent;
    symbol = in_symbol;
}

int TNode::GetFinish()
{
    return isFinish;
}

void TNode::SetFinish()
{
    isFinish = 1;
}

void TNode::AddNode(TNode *newNode)
{
    keys.push_back(newNode);
}

TNode *TNode::GetParent()
{
    return parent;
}

std::list<TNode *> *TNode::GetKeys()
{
    return &this->keys;
}

TNode *TNode::Search(char symbol)
{
    std::list<TNode *>::iterator iter;
    for (iter = keys.begin(); iter != keys.end(); iter++)
        if (symbol == (*iter)->GetSymbol())
            return *iter;
    return NULL;
}

char TNode::GetSymbol()
{
    return symbol;
}

Trie::Trie()
{
    root = CreateNode();
}

TNode *Trie::CreateNode()
{
    TNode *node = new TNode{};
    return node;
}

TNode *Trie::CreateNode(char symbol, TNode *in_parent)
{
    TNode *node = new TNode(symbol, in_parent);
    return node;
}

void Trie::Add(std::string word)
{
    std::string::iterator iter = word.begin();
    Add(&word, &iter, root);
}

void Trie::Add(std::string *word, std::string::iterator *symbol, TNode *node)
{
    if (*symbol == word->end())
    {
        node->SetFinish();
        return;
    }
    TNode *next = node->Search(**symbol);
    if (next == NULL)
    {
        next = CreateNode(**symbol, node);
        node->AddNode(next);
    }
    Add(word, &(++(*symbol)), next);
}

TNode *Trie::GetRoot()
{
    return root;
}

std::ostream &operator<<(std::ostream &s, Trie &trie)
{
    std::list<TNode *>::iterator iter;
    for (iter = trie.GetRoot()->GetKeys()->begin();
         iter != trie.GetRoot()->GetKeys()->end(); iter++)
        s << **iter;
    return s;
}

std::ostream &operator<<(std::ostream &s, TNode &node)
{
    std::list<TNode *> *templ = node.GetKeys();
    std::list<TNode *>::iterator iter;
    if (node.GetFinish())
        node.PrintWord(&node, s);
    for (iter = templ->begin(); iter != templ->end(); iter++)
        s << **iter;
    return s;
}

std::ostream &TNode::PrintWord(TNode *node, std::ostream &s)
{
    std::string word;
    return node->PrintWord(node, &word, s);
}

std::ostream &TNode::PrintWord(TNode *node, std::string *word, std::ostream &s)
{
    if (node->GetParent() == NULL)
    {
        std::string::reverse_iterator iter;
        for (iter = word->rbegin(); iter != word->rend(); iter++)
            s << *iter;
        s << std::endl;
        return s;
    }
    else
    {
        word->push_back(node->GetSymbol());
        return node->PrintWord(node->GetParent(), word, s);
    }
}

void Trie::Search(std::string Str, std::list<std::string> *result)
{
    Search(root, &Str, Str.begin(), result);
}

void Trie::Search(TNode *node, std::string *Str, std::string::iterator iter, std::list<std::string> *result)
{
    if (iter == Str->end())
        AppendWord(node, result);
    else
    {
        if (node->GetSymbol() == *iter)
            iter++;
        else
            iter = Str->begin();
        std::list<TNode *> *keys = node->GetKeys();
        std::list<TNode *>::iterator k_iter;
        for (k_iter = keys->begin(); k_iter != keys->end(); k_iter++)
            Search(*k_iter, Str, iter, result);
    }
}

void Trie::AppendWord(TNode *node, std::list<std::string> *Result)
{
    if (node->GetFinish())
        AddWordToResult(node, Result);
    std::list<TNode *> *List_kyes = node->GetKeys();
    std::list<TNode *>::iterator iter;
    for (iter = List_kyes->begin(); iter != List_kyes->end(); iter++)
        AppendWord(*iter, Result);
}

void Trie::AddWordToResult(TNode *node, std::list<std::string> *Result)
{
    std::string word;
    AddWordToResult(node, &word, Result);
}
void Reverse_string(std::string *);

void Trie::AddWordToResult(TNode *node, std::string *word, std::list<std::string> *Result)
{
    if (node->GetParent() == NULL)
    {
        Reverse_string(word);
        Result->push_back(*word);
    }
    else
    {
        word->push_back(node->GetSymbol());
        AddWordToResult(node->GetParent(), word, Result);
    }
}
void Reverse_string(std::string *word)
{
    std::string::reverse_iterator riter;
    std::string temp;
    for (riter = word->rbegin(); riter != word->rend(); riter++)
        temp.push_back(*riter);
    *word = temp;
}

Trie::~Trie()
{
    TrieDestr(root);
}

void Trie::TrieDestr(TNode *node)
{
    std::list<TNode *>::iterator iter;
    for (iter = node->GetKeys()->begin();
         iter != node->GetKeys()->end(); iter++)
        TrieDestr(*iter);
    delete node;
}