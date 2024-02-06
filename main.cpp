#include "trie.h"

int main()
{
    Trie *trie = new Trie();
    trie->insert("mundongo");
    trie->insert("mundo");
    trie->insert("mundial");
    std::cout << std::boolalpha << trie->find("mundito") << std::endl;
    std::cout << std::boolalpha << trie->find("mundo") << std::endl;
    return 0;
}
