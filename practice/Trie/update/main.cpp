#include <iostream>
#include <list>
#include <string>
#include "Trie.h"

int main()
{
    Trie tree;
    tree.AddWord("word");
    tree.AddWord("words");
    tree.AddWord("warhammer");
    tree.AddWord("Play");
    tree.AddWord("Enemy");
    tree.AddWord("Enemy");
    std::cout << tree;

    std::list<std::string> Result;
    std::list<std::string>::iterator iter;
    std::cout << "Search: " << std::endl;
    tree.SearchWords("w", &Result);
    for (iter = Result.begin(); iter != Result.end(); iter++)
        std::cout << *iter << std::endl;

    return 0;
}