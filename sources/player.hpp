#pragma once
#include "string"
#include "card.hpp"

namespace ariel{
    class Player {
        private:
            std::string name;
            int stackSize;
            int cardsTaken;
            Card * stackCards; // array of stack cards
            Card * takenCards; // array of taken cards
        public:
            Player(){}
            Player(std::string){}
            int stacksize(){return stackSize;}
            int cardesTaken(){return cardsTaken;}
    };

}
