#ifndef SOLDIERV2_H_INCLUDED
#define SOLDIERV2_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include <iomanip>

using namespace std;

class soldier
{
public:
    soldier(){next = NULL;}   ///default constructor
    soldier(int i){id = i;}
    ///accessors and mutators (gets and sets)
    void setid(int i){id = i;}
    void settype(char t){type = t;}
    void setspeed(int s){speed = s;}
    void setinitiative (int b){initiative = b;}
    void setatk (int a){atk = a;}
    void setdef (int d){def = d;}
    void setlocation (int x, int y){location[0] = x; location[1] = y;}

    int getid(){return id;}
    char gettype(){return type;}
    int getspeed(){return speed;}
    int getinitiative(){return initiative;}
    int getatk (){return atk;}
    int getdef (){return def;}

    double* getlocation (){
     double loc[2];
      loc[0]=location[0];
      loc[1]=location[1];

      return loc;
      }

    int rate;
    int getrate(){return rate;}
    void setrate(int r){rate = r;}
    void setnext(soldier * n){next = n;}
    soldier * getnext(){return next;}

    void display(){

        std::cout << "Soldier #" << id << " is part of the ";

        if(type=='I') {cout << "infantry " << endl;}
        else{cout << "calvary " << endl;}
        cout << "Soldier speed is " << speed << endl;
        cout << "Soldier initiative is " << initiative << endl;
        cout << "Soldier ATK is " << atk << endl;
        cout << "Soldier DEF is " << def << endl;
        cout << "Soldier location is = (" << location[0] << ", " << location[1] << ")" << endl;
        cout << "Soldier rate is " << rate << endl << endl;

        }

private:
    int id;
    char type;
    int speed;
    int initiative;
    int atk;
    int def;
    double location[2];
    soldier * next;
};

class unit
{
public:
    void setforce(char f){force = f;}
    char getforce(){return force;}

    int X;
    int Y;
    int getAttackStrength(){
    int attackStrength=0;
    soldier *curr=roster;
      while(curr!=NULL){
        attackStrength=attackStrength+curr->getatk();
      curr=curr->getnext();
      }

      return attackStrength;
    }

    int getDefenseStrength(){
    int defenseStrength=0;
    soldier *curr=roster;
    int i=1;
      while(curr!=NULL){
        defenseStrength=defenseStrength+ curr->getdef();

        curr=curr->getnext();
        i++;
      }

      return defenseStrength;
    }

    void setdesignation(string desig){
      designation=desig;
      }

    string getdesignation(){
    return designation;
    }

    int getspeed(){
    int speed=32767;//saving the maximum value
    soldier * curr;
    curr=roster;

    while(curr!=NULL){
    if(speed>curr->getspeed())
    {
      speed=curr->getspeed();
    }
    curr=curr->getnext();
    }

    return speed;
    }

    int getinitiative(){
    int initiative=0;//saving the minimum value
    soldier * curr;
    curr=roster;

    while(curr!=NULL){
    if(initiative<curr->getinitiative())
    {
      initiative=curr->getinitiative();
    }
    curr=curr->getnext();
    }

    return initiative;
    }

    unit(string n)
    {
        designation = n;
        roster=NULL;
        int hash = 0;
        int offset = 'a' - 1;
    for(string::const_iterator it=n.begin(); it!=n.end(); ++it)
        {
        hash = hash << 1 | (*it - offset);

    X=hash%200;
    Y=(hash*260)%200;
    X=(X-100)%100;
    Y=(Y-100)%100;

        }
    }

      unit(int i){
          ID = i;
      }

    void setnext(unit * n){next = n;}

      void addsoldier(soldier * s)
          {
            change(s);
          if(roster==NULL)
          {
            roster=s;
          }
           else{
             s->setnext(roster);
             roster=s;
             }
          }

        void addunit(unit * u)
            {
                change(u);
                if(unit==NULL){unit=u;}
                else{u->setnext(unit);
                     unit=u;}
            }

        void change(unit *temp1)
        {
          unit * curr=temp1;
              curr->id;
              curr->getspeed();
              curr->getinitiative();
              curr->getAttackStrength();
              curr->getDefenseStrength();
              curr->getlocation(location[0], location[1]);

        }

          void moved_soldier(soldier * s)
          {
          if(roster==NULL)
          {
            roster=s;
          }
           else{
             s->setnext(roster);
             roster=s;
             }

          }

        void display()
            {
              soldier * curr;
                cout << designation << endl << endl;

                curr = roster;
                while(curr!=NULL)
                {
                    curr->display();
                    curr=curr->getnext();
                }
            }

        soldier * getsoldier(int i){
                 soldier* c=roster;
          soldier* prev=NULL;
          if(roster->getid()==i)
          {
            soldier* temp=roster;
            roster=roster->getnext();
            temp->setnext(NULL);
            return temp;
          }
          soldier* temp=NULL;

        while(c!=NULL){
            if(c->getid()==i)
          {
            soldier* temp=c;
            prev->setnext(c->getnext());
            temp->setnext(NULL);
            return temp;
          }
          prev=c;
          c=c->getnext();
          }

        return temp;

        while(c!=NULL){
            if(c->getid()==i)
          {
            prev->setnext(c->getnext());
            return temp;
          }
          prev=c;
          c=c->getnext();
          }
        }


        int getID(){
          return ID;
        }

        void change(soldier *temp1)
        {
          soldier * curr=temp1;

              int temp;
              temp = (rand() % 2);
              if (temp == 0)
              {
                  curr->settype('I');
              }
              if (temp == 1)
              {
                  curr->settype('C');
              }
              curr->setid(rand()%10000);
              curr->setspeed(rand()% 6);
              curr->setinitiative(rand()% 6);
              curr->setatk(rand()% 6);
              curr->setdef(rand()% 6);
              curr->setrate(rand()% 11);
              curr->setlocation(X,Y);

        }

        soldier * getnext(){

          return NULL;
            }

private:
    string designation;
    soldier *roster;
    int ID;
    char force;
    unit *next;
};


class cell
{
    public:
    cell(){uptr=NULL;}
    bool addunit(unit * u)
        {
            if (uptr==NULL){uptr = u;
            return true;
            }
            else{
                    cout << "Already Occupied" << endl;
            return false;
            }
        }

    unit * moveunit()
        {
            unit * m;
            m = uptr;
            uptr = NULL;
            return m;
        }

    void setunit(unit * u)
        {
            uptr=u;
        }

    /*void display(HANDLE *hptr)
            {char f;
                if(uptr==NULL){cout<<setw(5)<<" ";}
                else{f=uptr->getforce();
                    if(f=='R'){
                    SetConsoleTextAttribute(*hptr, 11);}
                    else{
                    SetConsoleTextAttribute(*hptr, 5);}
                    cout<<setw(5)<<uptr->getID();
                      SetConsoleTextAttribute(*hptr,6);}

            }*/

    void display(HANDLE *hptr)
            {
                if(uptr==NULL){cout << setw(5) << " ";}
                else{cout << setw(5)<< uptr->getID();}

            }
    int getID(){if(uptr!=NULL) {return uptr->getID();}
                else {return -1;}}
    unit * getunit()
        {
          return uptr;
        }
    /*unit* getUnit(){
       return uptr;
    }*/
private:
    unit * uptr;
};

class world
{
    public:
    world(){ }
    void display(HANDLE * hptr)
        {
        SetConsoleTextAttribute(*hptr, 7);
            cout<<"                                    World"<<endl;
            SetConsoleTextAttribute(*hptr,6);
            cout<<"  ------------------------------------------------------------------------"<<endl;
            for(int row=0; row<11; row++)
            {   cout<<"  |";
                for(int col=0; col<12; col++)
                {
                    W[row][col].display(hptr);
                    cout<<"|";
                }
            cout<<endl;
            cout<<"  ------------------------------------------------------------------------"<<endl;

            }
        }
    /*void display()
        {
            cout << "                      World" << endl;
            cout << "  ------------------------------------------------------------------------" << endl;
            for(int row=0; row<12; row++)
            {   cout << "  |";
                for(int col=0; col<12; col++)
                {
                    W[row][col].display();
                    cout << "|";
                }
            cout << endl;
            cout << "  ------------------------------------------------------------------------"<<endl;

            }
        }*/
    void addunit(int x, int y, unit * u)
            {
                W[x][y].addunit(u);
            }

    void moveunit(int id)
        {   bool free=false;
            unit * uptr;
            int delta, deltamax;
            int d;
            for(int i=0; i<12; i++)
            {
                for(int j=0; j<12; j++)
                {
                    if (W[i][j].getID()==id)
                    {
                        uptr=W[i][j].getunit();
                        deltamax = uptr->getspeed();
                        cout << "Move which direction? (North=8, East=6, South=2, West=4) ";
                        cin >> d;
                        cout << "How far out of " << deltamax << "?      "; cin >> delta;
                        if(delta>deltamax){cout << "Sorry, you are cheating" << endl; return;}
                        switch(d)
                            {
                            case 8:{if(W[i-delta][j].getunit()==NULL)
                                    {free=true;
                                    W[i-delta][j].setunit(uptr);}}break;
                            case 6:{if(W[i][j+delta].getunit()==NULL)
                                    {free=true;
                                    W[i][j+delta].setunit(uptr);}}break;
                            case 4:{if(W[i][j-delta].getunit()==NULL)
                                    {free=true;
                                    W[i][j-delta].setunit(uptr);}}break;
                            case 2:{if(W[i+delta][j].getunit()==NULL)
                                    {free=true;
                                    W[i+delta][j].setunit(uptr);}}break;
                            }
                        if(free){W[i][j].setunit(NULL);}
                        i=12; j=12;
                    }

                }
            }
        }

private:
   cell W[12][12];
};


#endif
