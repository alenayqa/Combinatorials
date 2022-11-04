#include <iostream>
#include <fstream>
#include <wchar.h>
#include "yaml-cpp/yaml.h"
#include "huffman_tree.hpp"
#include <memory>

using namespace std;

int main()
{

    YAML::Node config = YAML::LoadFile("../config.yaml");
    cout<<config["IO"]["freq-path"].as<string>()<<endl;

    double freqs[256];

    auto pq = load_characters(config["IO"]["freq-path"].as<string>());
    double sum = 0;
    while (pq.size()>0)
    {
        character C = pq.top();
        // std::cout<<(C.symbol)<<": "<<C.freq<<std::endl;
        sum+= C.freq;
        pq.pop();
    }
    cout<<sum<<endl;

}