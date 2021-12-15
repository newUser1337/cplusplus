#include <iostream>
#include <list>
#include <string>
#include "Trie.h"

int main()
{
    Trie tree;
    tree.Add("word");
    tree.Add("words");
    tree.Add("warhammer");
    tree.Add("Play");
    tree.Add("Enemy");
    tree.Add("Enemy");
    std::cout << tree;

    std::list<std::string> Result;
    std::list<std::string>::iterator iter;
    std::cout << "Search: " << std::endl;
    tree.Search("n", &Result);
    for (iter = Result.begin(); iter != Result.end(); iter++)
        std::cout << *iter << std::endl;

    return 0;
}