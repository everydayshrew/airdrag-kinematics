#include <cmath>
#define PI 3.14159265

class worldDetails{
      public:
          // Constructor Classes
          worldDetails(){worldType = 3; grav = 9.81;};
          worldDetails(double a, int b){worldType = b; grav = a;};
          
          void setGravConst(double g){grav = g;}
          void setDragConst(int wt){worldType = wt;}
          double gravConst(){return grav;};
          double dragConst(double height){
                 double value;
                 switch(worldType){
                     // Functions are approximate to real world scenarios.
                     case 1: drag = 1.24 - 0.11*log(height+0.001); break; // Logarithmic
                     case 2: drag = 1.01-0.0004*height; break;  // Linear
                     case 3: drag = (2*pow(10,-9)*pow(height,2)) - 0.0001*height + 1.2; break;
                 }
                 
                 return (drag*0.5);
          };
          
      private:
          double grav;
          double drag;
          int worldType;
};

class objectDetails{
      // Constructor Classes
      public:
          objectDetails(){weight = 1; objectType = 1;}
          objectDetails(int a, double m){weight = m; objectType = a;}
          objectDetails(int a, double m, double vel, int angle){weight = m; objectType = a; setVelocity(vel,angle);
                                                                area = PI; setPos(0,0); setAcceleration(0,0);}
          
          //Weight/Area functions
          void setArea(double a){area = a;}
          void setWeight(double w){weight = w;}
          double returnWeight(){return weight;}
          //Acceleration Functions
          void setAcceleration(double x, double y){accX = x; accY = y;}
          void setAcceleration(worldDetails& world){
               accX = -0.01*(area*returnDragCoef(posY,world)*fabs(velX)*velX)/weight;
               accY = -(0.01*(area*returnDragCoef(posY,world)*fabs(velY)*velY)/weight + 0.01*world.gravConst());
          } 
          double XAcc(){return accX;}
          double YAcc(){return accY;}   
          //Velocity Functions
          void setVelocity(double vel, int angle){velX = vel*cos(PI*angle/180.0); velY = vel*sin(PI*angle/180.0);}
          void setVelocity(double x, double y){velX += x; velY += y;}
          double XVel(){return velX;}
          double YVel(){return velY;}
          //Position Functions
          void setPos(double x, double y){posX = x; posY = y;}
          void addPos(){posX += 0.01*velX; posY += 0.01*velY;}
          double XPos(){return posX;}
          double YPos(){return posY;}
          //Drag Functions
          double returnDragCoef(double height, worldDetails& world){
                 switch(objectType){
                     case 1: return 1.03*world.dragConst(height)*0.5; break;
                     case 2: return 0.53*world.dragConst(height)*0.5; break;
                     case 3: return 0.09*world.dragConst(height)*0.5; break;
                 }
          };
      private:
          double velX;
          double velY;
          double accX;
          double accY;
          double posX;
          double posY;
          double area;
          double weight;
          int objectType;
};

