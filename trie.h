#pragma once

#include <unordered_map>
#include <iostream>

class Trie
{
    class TrieNode
    {
        friend class Trie;
        std::unordered_map<char, TrieNode *> edges;
        bool isEnd;

        TrieNode() : isEnd(false) {}
        ~TrieNode() {}

        void insert(TrieNode *node, std::string word)
        {
            auto currentNode = node;
            for (const auto c : word)
            {
                if (currentNode->edges.find(c) == currentNode->edges.end())
                {
                    currentNode->edges.insert({c, new TrieNode()});
                }
                currentNode = currentNode->edges.at(c);
            }
            currentNode->isEnd = true;
        }

        bool find(TrieNode *node, std::string word)
        {
            auto currentNode = node;
            for (const auto c : word)
            {
                if (currentNode->edges.find(c) == currentNode->edges.end())
                {
                    return false;
                }
                currentNode = currentNode->edges.at(c);
            }
            return currentNode->isEnd;
        }
    };

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
    }

    void insert(std::string word)
    {
        return root->insert(root, word);
    }

    bool find(std::string word)
    {
        return root->find(root, word);
    }
};