#pragma once
#include "string"
using namespace std;

namespace ariel{
    class Player {
        private:
            std::string name;
            int stackSize;
            int cardsTaken;
        public:
            Player(){}
            Player(std::string){}
            int stacksize(){return stackSize;}
            int cardesTaken(){return cardsTaken;}
    };

}
