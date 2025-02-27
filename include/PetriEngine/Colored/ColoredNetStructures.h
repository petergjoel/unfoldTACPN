/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColoredNetStructures.h
 * Author: Klostergaard
 *
 * Created on 17. februar 2018, 17:07
 */

#ifndef COLOREDNETSTRUCTURES_H
#define COLOREDNETSTRUCTURES_H

#include <vector>
#include <set>
#include "Colors.h"
#include "Expressions.h"
#include "Multiset.h"
#include "TimeInterval.h"
#include "TimeInvariant.h"

namespace PetriEngine {
    namespace Colored {
        
        struct Arc {
            uint32_t place;
            uint32_t transition;
            ArcExpression_ptr expr;
            bool input;
            bool inhibitor = false;
            bool transport;
            int weight;
            std::vector<Colored::TimeInterval> interval;
            std::string transportID;
        };

        struct TransportArc {
            uint32_t source;
            uint32_t transition;
            uint32_t destination;
            ArcExpression_ptr expr;
            std::vector<Colored::TimeInterval> interval;
        };
        
        struct Transition {
            std::string name;
            GuardExpression_ptr guard;
            bool urgent;
            std::vector<Arc> arcs;
            //bool inhibitor = false;
        };
        
        struct Place {
            std::string name;
            ColorType* type;
            Multiset marking;
            std::vector<Colored::TimeInvariant> invariants;
            //bool inhibitor = false;
        };
    }
}

#endif /* COLOREDNETSTRUCTURES_H */

