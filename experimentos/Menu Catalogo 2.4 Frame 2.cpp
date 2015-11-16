#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();
void dibujarLinea2();


void main(){

dibujarBordes();
dibujarLinea2();

gotoxy(31,2);cout<<"CATALOGO: ";
gotoxy(4,4);cout<<">";
gotoxy(57,4);cout<<"Precio: ";
gotoxy(57,6);cout<<"Duraci"<<char(162)<<"n: ";
gotoxy(57,8);cout<<"G"<<char(130)<<"nero: ";
gotoxy(57,10);cout<<"Disponibilidad: ";
gotoxy(57,12);cout<<"A"<<char(164)<<"o: ";
gotoxy(69,12);cout<<"ID: ";
gotoxy(4,16);cout<<"|||||  Utilice las teclas <ARRIBA> y <ABAJO>   |||||";
gotoxy(63,16);cout<<"Sinopsis";
gotoxy(5,23);cout<<"Para volver al men"<<char(163)<<" anterior, presiona <ESC>.";






getch();
}

void dibujarBordes() {

for(int x=3;x<78;x++){
gotoxy(x,22);cout<<"_";}
for(int x=3;x<78;x++){
gotoxy(x,3);cout<<"_";}
for(int x=3;x<78;x++){
gotoxy(x,1);cout<<"_";}
for(int y=2;y<23;y++){
gotoxy(77,y);cout<<"|";}
for(int y=2;y<23;y++){
gotoxy(3,y);cout<<"|";}
}//Fin dibujar bordes

void dibujarLinea2(){

for(int x=4;x<56;x++){
gotoxy(x,15);cout<<"_";}
for(int x=4;x<60;x++){
gotoxy(x,17);cout<<"_";}
for(int x=60;x<75;x++){
gotoxy(x,15);cout<<"_";}
for(int x=75;x<77;x++){
gotoxy(x,17);cout<<"_";}
for(int y=4;y<18;y++){
gotoxy(56,y);cout<<"|";}
for(int y=16;y<18;y++){
gotoxy(60,y);cout<<"|";}
for(int y=16;y<18;y++){
gotoxy(74,y);cout<<"|";}





}
