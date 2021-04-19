#ifndef OPTIONS_H
#define OPTIONS_H

#include <ctype.h>
#include <stddef.h>
#include <limits>
#include <set>
#include <string.h>
#include <cctype>
#include <iostream>

struct options_t {
//    bool outputtrace = false;
    char* modelfile = NULL;
    char* queryfile = NULL;
    bool printstatistics = true;
    std::set<size_t> querynumbers;
    int queryReductionTimeout = 30;
    uint32_t cores = 1;

    //CTL Specific options
    
    std::string query_out_file;
    std::string model_out_file;

    
    //CPN Specific options
    bool cpnOverApprox = false;
    bool isCPN = false;
    uint32_t seed_offset = 0;

    //TACPN options
    bool outputVerifydtapnFormat = false;

    void print() {
        if (!printstatistics) {
            return;
        }
        
        std::string optionsOut;        
        
        if (queryReductionTimeout > 0) {
            optionsOut += ",Query_Simplication=ENABLED,QSTimeout=" + std::to_string(queryReductionTimeout);
        } else {
            optionsOut += ",Query_Simplication=DISABLED";
        }
        
        optionsOut += "\n";
        
        std::cout << optionsOut;
    }
};

#endif
