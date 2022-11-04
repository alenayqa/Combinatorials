#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include <iostream>
#include <queue>

const wchar_t FIRST_CYRYLLIC = 1040;
const wchar_t LAST_LATIN = 122;

struct character
{
    char symbol;
    double freq;
};

class CharacterCompare
{
public:
    bool operator() (character x, character y)
    {
        return x.freq > y.freq;
    }
};

bool compare_characters(character x, character y);

std::priority_queue<character, std::vector<character>, CharacterCompare> load_characters(std::string freq_path);

wchar_t linearize_wchar(wchar_t c);

#endif