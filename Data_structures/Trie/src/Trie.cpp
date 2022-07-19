#include "../trie_headers/Trie.h"
#include "../trie_headers/Vertex.h"

using namespace std;

template<typename T>
Trie<T>::Trie()
{
    // Constructor. We need to have a root
    root = new Vertex<T>;
}

template<typename T>
Trie<T>::~Trie()
{
    // Destructor. Delete root, another vertices will be removed in root-destructor (root as a Vertex)
    delete root;
}