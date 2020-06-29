#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846
float var_angle = 0;
void forward(double distance){
    float _x = getx();
    float _y = gety();
    lineto(_x+distance*cos(var_angle),_y+distance*sin(var_angle));
}

void turn(double angle){
    var_angle -= angle;
}

void move(double distance){
    float _x = getx();
    float _y = gety();
    moveto(_x+distance*cos(var_angle),_y+distance*sin(var_angle));
}

int main(){
    INITGRAPH(640,640);
    setcolor(GREEN);
    moveto(300,300);
    for(int i = 0,var_angle = PI/18;i < 18; i++){
            for(int j =0;j<6;j++){
                forward(100);
                turn(PI/3);
            }
            lineto(300,300);
        turn(PI/9);
    }
    getch();
    return 0;
}
