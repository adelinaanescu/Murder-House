#include <iostream>
#include<string.h>
#include"game.h"

using namespace std;

int checkWin(int positionp,int positionk,bool key)
{
    if(positionp==1 && positionk!=positionp && key==true)
        return 1;
    return 0;
}
int checkLose(int positionp,int positionk)
{
   if(positionp==positionk)
       return 1;
   return 0;
}


void peek(int* l,int size, int positionk, int nextpositionk) {
    int ok=0;

    for(int i=0;i<size;i++)
        if (l[i] == positionk || l[i] == nextpositionk) {
            cout << "The killer is in room " << positionk << " and he is going to room " << nextpositionk << endl;
            ok = 1;
        }

    if(ok==0)
        cout<<"The rooms around you are safe!"<<endl;
}
void makePeek(int position, int positionk, int newpositionk){

    if(position==1){
       int a[1] = {2};
        peek(a,1,positionk,newpositionk);
    }

    if(position==2){
        int a[5] = {1,3,4,5,7};
        peek(a,4,positionk,newpositionk);
    }

    if(position==3){
        int a[2] = {2,6};
        peek(a,2,positionk,newpositionk);
    }

    if(position==4){
        int a[1] = {2};
        peek(a,1,positionk,newpositionk);
    }

    if(position==5){
        int a[3] = {2,7,8};
        peek(a,3,positionk,newpositionk);
    }

    if(position==6){
        int a[1] = {3};
        peek(a,1,positionk,newpositionk);
    }

    if(position==7){
        int a[2] = {2,5};
        peek(a,1,positionk,newpositionk);
    }

    if(position==8){
        int a[1] = {5};
        peek(a,1,positionk,newpositionk);
    }

}

int main() {

    char name[25];
    cout<<"Player's name:";
    cin.getline(name,24);
    Game g(name);
    int ch;
    cout<<"You are in the bedroom. From here, you can go to:"<<endl<<"(2)Living Room\n(7)Bathroom\n(8)Dressing Room\n";

    cin>>ch;
    int path[18]={1,2,3,6,3,2,5,7,5,2,7,5,2,3,6,2,7,2};
    int i = 1;
    int ok=0;
    while(checkLose(g.p.getPosition(),g.k.getPositionk())==0 && checkWin(g.p.getPosition(),g.k.getPositionk(),g.p.getKey())==0)
    {
        if(i==18)
            i=0;


        switch(ch){
            case 0:
                makePeek(g.p.getPosition(),g.k.getPositionk(),path[i]);
                break;

            case 1:
                g.p.setPosition(1);
                g.k.setPositionk(path[i]);
                if(g.p.getKey()==true)
                    cout<<"Congrats! You survived!";
                else
                    if(ok!=2) {
                        cout << "Oh no! The killer stole your key. Your spare key is in room " << g.h.getKeyh() << ".";
                        ok = 1;
                    }
                i++;
                break;

            case 2:
                g.p.setPosition(2);
                g.k.setPositionk(path[i]);
                cout<<"You are in the Living Room. From here, you can go to:\n(1)Hallway\n(3)Kitchen\n(4)Office\n(5)Bedroom\n(7)Bathroom\n";
                i++;
                break;
            case 3:
                g.p.setPosition(3);
                g.k.setPositionk(path[i]);
                cout<<"You are in the Kitchen. From here, you can go to:\n(2)Living Room\n(6)Storage Room\n";
                i++;
                break;
            case 4:
                g.p.setPosition(4);
                g.k.setPositionk(path[i]);
                cout<<"You are in the Office. From here, you can go to:\n(2)Living Room\n";
                i++;
                break;
            case 5:
                g.p.setPosition(5);
                g.k.setPositionk(path[i]);
                cout<<"You are in the Bedroom. From here, you can go to:\n(2)Living Room\n(7)Bathroom\n(8)Dressing Room\n";
                i++;
                break;

            case 6:
                g.p.setPosition(6);
                g.k.setPositionk(path[i]);
                cout<<"You are in the Storage Room. From here, you can go to:\n(3)Kitchen\n";
                i++;
                break;

            case 7:
                g.p.setPosition(7);
                g.k.setPositionk(path[i]);
                cout<<"You are in the Bathroom. From here, you can go to:\n(5)Bedroom\n(7)Bathroom\n";
                i++;
                break;

            case 8:
                g.p.setPosition(8);
                g.k.setPositionk(path[i]);
                cout<<"You are in the Dressing Room. From here, you can go to:\n(5)Bedroom\n";
                i++;
                break;
        }

        if(g.p.getPosition()==g.h.getKeyh() && ok==1) {
            g.p.setKey(true);
            cout << "You have the key now. Hurry up!" << endl;
            ok=2;
        }
        if(checkLose(g.p.getPosition(),g.k.getPositionk())==0)
            cin>>ch;
    }

    if(checkLose(g.p.getPosition(),g.k.getPositionk())==1)
        cout<<"You died";
    else
        if(checkWin(g.p.getPosition(),g.k.getPositionk(),g.p.getKey())==1)
            cout<<"You survived";
}
