#pragma once
#include "player.hpp"
namespace ariel {
    class Game {
        private:
            Player p1;
            Player p2;
        public:
            Game(Player, Player){}
            void playTurn(){}
            void printLastTurn(){}
            void playAll(){}
            void printWiner(){}
            void printLog(){}
            void printStats(){}
        };

}