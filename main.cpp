#include <cstdlib>
#include <iostream>
#include "world_hh.h"
#include <fstream>

using namespace std;


int main()
{   
    double time = 0;
    double maxheight = 0;
    double distance = 0;
    ofstream output;
    output.open("data.txt");
    output << "0 0\n";
    
    int tv1, tv5;
    double tv2, tv3, tv4;
    cout << "-Build a World-\n";
    cout << "  Atmosphere Type:\n     1. Earth-like\n     2. Moon-like\n       Option: ";
    cin >> tv1;
    cout << "  Gravity (0- Space, 9.81- Earth, 25- Jupiter): ";
    cin >> tv2;
    worldDetails world_1(tv2, tv1);
    cout << "\n-Build an Object-";
    cout << "  \nObject type:\n     1. Simple Cube     2. Simple Sphere    3.  Streamlined";
    cout << "       \nOption: ";
    cin >> tv1;
    cout << "  \nSurface area (0.001- Bullet, 0.15- Bowling Ball, 1- Shipping Crate): ";
    cin >> tv2; 
    cout << "  \nWeight (0.007- Bullet, 7.15- Bowling Ball, 80- Human): ";
    cin >> tv3;
    cout << "  \nVelcoity (15- Avg. Throw, 270- Bullet): ";
    cin >> tv4;
    cout << "  \nAngle (0-180): ";
    cin >> tv5;
    objectDetails object_1(tv1, tv3, tv4, tv5);
    object_1.setArea(tv2);
    cout << "\n\n\n\n\n\n";
    
    while(time < 1 || object_1.YPos() > 0){
       object_1.addPos();
       object_1.setAcceleration(world_1);
       if(maxheight < object_1.YPos()){maxheight = object_1.YPos();}
       object_1.setVelocity(object_1.XAcc(), object_1.YAcc());
       //DEBUG
       //cout << "X Pos: " << object_1.XPos() << "  Y Pos: " << object_1.YPos();
       //cout << "\nX Vel: " << object_1.XVel() << "  Y Vel: " << object_1.YVel();
       //cout << "\nX Acc: " << object_1.XAcc() << "  Y Acc: " << object_1.YAcc();
       //cout << "\n\n\n";
       //output.precision(2);
       output << object_1.XPos() << " " << object_1.YPos() << "\n";
       time++;
    }
    
    cout << "\nMax Height was: " << maxheight;
    cout << "\nTime traveled: " << time/100;
    cout << "\nDistance: " << object_1.XPos();
    cout << "\n\n";
    //output << "}";
    output.close();
    system("PAUSE");
    return 0;
}
