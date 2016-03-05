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
    int X,Y,j,ID;
    double x, y;
    char cont='Z';
    world W;
    unit * uptr;

    HANDLE  hConsole;
    HANDLE * hptr;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hptr=&hConsole;
    SetConsoleTextAttribute(hConsole, 6);

    srand(time(NULL));

    unit * U;
    unit * U2;

    /*soldier * newsol;
    U = new unit("BLUE UNIT");
    U2 = new unit("RED UNIT");

    for(int m=1; m<11; m++)
    {
       newsol = new soldier;
       U->addsoldier(newsol);
       newsol = new soldier;
       U2->addsoldier(newsol);
    }*/

    bool w=true;
    while(w){
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
    //unit * U;
    soldier * newsol;
    U = new unit("BLUE UNIT");
    for(int i=1; i<11; i++)
    {
       newsol = new soldier;
       U->addsoldier(newsol);
    /*for(int i=0; i<1; i++)
    {
    uptr = new unit(i*10+i+1);
    uptr->getspeed();
    uptr->getID();
    uptr->getinitiative();
    uptr->getAttackStrength();
    uptr->getDefenseStrength();
    uptr->setforce('B');
    uptr->getlocation();*/
    //W.addunit(i+5,i+6, uptr);
    }
    }

    else if(a=='R')
    //create a red unit
    {
    //unit * U2;
    soldier * newsol;
    U2 = new unit("RED UNIT");
    for(int i=1; i<11; i++)
    {
       newsol = new soldier;
       U2->addsoldier(newsol);
    /*for(int i=1; i<1; i++)
    {
    uptr = new unit(i*10+i+1);
    uptr->getspeed();
    uptr->getID();
    uptr->getinitiative();
    uptr->getAttackStrength();
    uptr->getDefenseStrength();
    uptr->setforce('R');
    uptr->getlocation();*/
    //W.addunit(i,i+1, uptr);
    }
    }

    else if(a=='b'){
    //Display current blue unit
    U->display();
    cout << "BLUE UNIT: " << U->getID() << endl << endl;
    cout << "Speed is " << U->getspeed() << endl;
    cout << "Initiative is " << U->getinitiative() << endl;
    cout << "ATK is " << U->getAttackStrength() << endl;
    cout << "DEF is " << U->getDefenseStrength() << endl << endl;
    cout << "Location is = " << U->getlocation() << endl;
    }
    else if(a=='r'){
    U2->display();
    cout << "RED UNIT: " << U2->getID() << endl << endl;
    cout << "Speed is " << U2->getspeed() << endl;
    cout << "Initiative is " << U2->getinitiative() << endl;
    cout << "ATK is " << U2->getAttackStrength() << endl;
    cout << "DEF is " << U2->getDefenseStrength() << endl << endl;
    cout << "Location is = " << U2->getlocation()<< endl;
    }
    else if (a=='S'){
    unit * uptr1;
    for(int i=0;i<20;i++)
    {
    int j=0;
    int x1,y1;
    x1=rand() %12;
    y1=rand()%12;
    j=rand()%10000;
    uptr1 = new unit(j);
    W.addunit(x1,y1, uptr1);
    }

    W.display(hptr);
    w=false;
    }
    }


    bool w2=true;
    while(w2){
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
    cout<<"Enter the ID of the unit you would like to move "; cin >> ID;
    W.moveunit(ID);
    W.display(hptr);
    }
    else if(a=='R')
    {
    //move a red unit to a different cell
    cout<<"Enter the ID of the unit you would like to move "; cin >> ID;
    W.moveunit(ID);
    W.display(hptr);
    }
    else if(a=='D'){
    //Displaying the world chart
    W.display(hptr);
    }
    else if(a=='Q'){
        w2=false;
    }
    }

    return 0;
}

