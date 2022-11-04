#include <iostream>
#include <wchar.h>
#include <fstream>
#include "huffman_tree.hpp"

bool compare_characters(character x, character y)
{
    return x.freq > y.freq;
}

std::priority_queue<character, std::vector<character>, CharacterCompare> load_characters(std::string freq_path)
{
    
    std::ifstream fin(freq_path);
    character c;

    std::priority_queue<character, std::vector<character>, CharacterCompare> pq;

    c.symbol = 'a';
    fin>>c.freq;
    pq.push(c);
    std::cout<<(c.symbol)<<": "<<c.freq<<std::endl;
    c.symbol = 'a';
    fin>>c.freq;
    pq.push(c);
    std::cout<<(c.symbol)<<": "<<c.freq<<std::endl;

    while (fin>>c.symbol)
    {
        fin>>c.freq;
        std::cout<<(c.symbol)<<": "<<c.freq<<std::endl;
        pq.push(c);
    }
    fin.close();
    return pq;
}

wchar_t linearize_wchar(wchar_t c)
{
    if (c >= FIRST_CYRYLLIC)
        return c - FIRST_CYRYLLIC + LAST_LATIN + 1;
    else
        return c;
}
