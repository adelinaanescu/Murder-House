//
// Created by AsuszA on 27/05/2021.
//

#ifndef PS_MURDERHOUSE_GAME_H
#define PS_MURDERHOUSE_GAME_H


class Game {

    class House
    {
        const int hall;
        const int living;
        const int kitchen;
        const int office;
        const int bedroom;
        const int storageroom;
        const int bathroom;
        const int closet;
        int key;
    public:
        House();
        int getKeyh();
    };
    class Killer
    {
        int position;
    public:
        Killer();
        int getPositionk();
        void setPositionk(int);
    };

    class Player
    {
        char* name;
        int position;
        bool key;
    public:
        Player(const char*);
        void go_to_room(int);
        const char* getName();
        void setPosition(int);
        int getPosition();
        bool getKey();
        void setKey(bool);
    };

public:
   Game(const char*);
    House h;
    Player p;
    Killer k;
};


#endif //PS_MURDERHOUSE_GAME_H
