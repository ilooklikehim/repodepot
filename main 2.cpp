#include <iostream>
#include <string>

#include <time.h>
#include <stdlib.h>
#include "soldierV2.h"
#include <iomanip>
#include <windows.h>

using namespace std;
int main()
{
    int X,Y,j,id;
    char cont='Z';
    world W;
    unit * uptr;
///graphical interface junk....
    HANDLE  hConsole;
    HANDLE * hptr;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hptr=&hConsole;
    SetConsoleTextAttribute(hConsole, 6);

    srand(time(NULL));

    unit * U;
    unit * U2;

    soldier * newsol;
    U = new unit("BLUE UNIT");
    U2 = new unit("RED UNIT");

    for(int m=1; m<11; m++)
    {
       newsol = new soldier;
       U->addsoldier(newsol);
       newsol = new soldier;
       U2->addsoldier(newsol);
    }

    while(true){
    cout << "Select an action from the options below:" << endl;
    cout << "B) Create a blue unit" << endl;
    cout << "R) Create a red unit" << endl;
    cout << "b) Display current blue unit" << endl;
    cout << "r) Display current red unit" << endl;
    cout << "S) Start the simulation" << endl;

    char a;
    cin >> a;
    cout << "  ------------------------------------------------------------------------" << endl;
    unit * uptr;

    if(a=='B')
   //create a blue unit
    {
    uptr = new unit(i*1+i+1);
    uptr->setspd(i+1);
    uptr->setforce('B');
    W.addunit(i+5,i+6, uptr);
    }
    else if(a=='R'):
    //create a red unit
    {
    uptr = new unit(i*1+i+1);
    uptr->setspd(i+1);
    uptr->setforce('R');
    W.addunit(i,i+1, uptr);
    }
    else if(a=='b'){
    //Display current blue unit
    U->display();
    cout << "BLUE UNIT: " << id << endl << endl;
    cout << "Speed is " << U->getspeed() << endl;
    cout << "Initiative is " << U->getinitiative() << endl;
    cout << "ATK is " << U->getAttackStrength() << endl;
    cout << "DEF is " << U->getDefenseStrength() << endl << endl;
    }
    else if(a=='r'){
    U2->display();
    cout << "RED UNIT: " << id << endl << endl;
    cout << "Speed is " << U2->getspeed() << endl;
    cout << "Initiative is " << U2->getinitiative() << endl;
    cout << "ATK is " << U2->getAttackStrength() << endl;
    cout << "DEF is " << U2->getDefenseStrength() << endl << endl;
    }
    else if (a=='S'){
    unit * uptr1;
    for(int i=0;i<20;i++)
    {
    int j=0;
    int x1,y1;
    x1=rand() % 12;
    y1=rand()%12;
    j=rand()%10000;
    uptr1 = new unit(j);
    W.addunit(x1,y1, uptr1);
    }

    W.display(hptr);
    }
    }



    while(true){
    cout << "Select an action from the options below:" << endl;
    cout << "B) Move a Blue unit" << endl;
    cout << "R) Move a Red unit" << endl;
    cout << "D) Redisplay the World" << endl;
    cout << "Q) Quit the Program " << endl;

    char a;
    cin >> a;
    cout << "  ------------------------------------------------------------------------" << endl;
    unit * uptr;

    if(a=='B')
    {
    //move a blue unit to a different cell
    cout<<"Enter the ID of the unit you would like to move "; cin >> id;
    W.moveunit(id);
    W.display(hptr);
    }
    else if(a=='R')
    {
    //move a red unit to a different cell
    cout<<"Enter the ID of the unit you would like to move "; cin >> id;
    W.moveunit(id);
    W.display(hptr);
    }
    else if(a=='D'){
    //Displaying the world chart
    W.display(hptr);
    }
    else if(a=='Q'){
        break;
    }
    }

    return 0;
}

