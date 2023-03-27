#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace ariel;


TEST_CASE("object creation") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK(p1.stacksize()==26);// when the game created, the cards should spend equally
    CHECK(p2.stacksize()==26);
    CHECK(p1.cardesTaken()==0);// as far as no turn played, no cards taken
    CHECK(p2.cardesTaken()==0);
    CHECK(p1.stacksize()+p2.stacksize()==52);
}


TEST_CASE("play one turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();

    CHECK(p1.stacksize()<26);// players should spend some cards
    CHECK(p2.stacksize()<26);
    CHECK(p1.stacksize()==p2.stacksize());// players should spend an equal amount of cards
    CHECK(p1.stacksize()+p2.stacksize()<52);

    if(p1.cardesTaken()>p2.cardesTaken()){ // if true, p1 won the round
        // checking that there is no over\fewer cards after playTurn()
        CHECK(p1.stacksize()+p2.stacksize()+p1.cardesTaken()+p2.cardesTaken()==52);
        CHECK(p2.cardesTaken()==0);
        CHECK(p1.cardesTaken()>0);
    }
    if(p2.cardesTaken()>p1.cardesTaken()){ // if true, p2 won the round
        // checking that there is no over\fewer cards after playTurn()
        CHECK(p1.stacksize()+p2.stacksize()+p1.cardesTaken()+p2.cardesTaken()==52);
        CHECK(p1.cardesTaken()==0);
        CHECK(p2.cardesTaken()>0);
    }
    if(p2.cardesTaken()==p1.cardesTaken()) {// in this case, the game restarted due to 26 equal cards game
        CHECK(p1.stacksize()==26);
        CHECK(p2.stacksize()==26);
    }
}

TEST_CASE("play all turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize()==0);// after playing all turns, no cards left on stack
    CHECK(p2.stacksize()==0);
    bool a=p1.cardesTaken()>p2.cardesTaken();
    bool b=p2.cardesTaken()>p1.cardesTaken();
    bool res=a||b;
    CHECK(res);// someone needs to win the game
}

TEST_CASE("play all turns looped") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i=0;i<26;i++) {
        if(p1.stacksize()>0) {// equal to "p2.stacksize()>0"
            game.playTurn();
            CHECK(p1.stacksize() == p2.stacksize());// players should spend an equal amount of cards
        }
    }
    CHECK(p1.stacksize()==0);// after playing all turns, no cards left on stack
    CHECK(p2.stacksize()==0);
    bool a=p1.cardesTaken()>p2.cardesTaken();
    bool b=p2.cardesTaken()>p1.cardesTaken();
    bool res=a||b;
    CHECK(res);// someone needs to win the game
}

TEST_CASE("exception check") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printWiner());// there is no winner yet
    CHECK_THROWS(game.printLastTurn());// there is no last turn
    CHECK_THROWS(game.printStats());
    game.playAll();
    CHECK_THROWS(game.playTurn());// there is no cards
    CHECK_THROWS(game.playAll());
}


