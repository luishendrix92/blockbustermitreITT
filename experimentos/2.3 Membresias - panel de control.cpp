#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();



void main(){

dibujarBordes();


gotoxy(31,2);cout<<"MEMBRES"<<char(161)<<"AS: DETALLES ";
gotoxy(5,5);cout<<"Bienvenid@ seas, a continuaci"<<char(162)<<"n se muestran los detalles de tu ";
gotoxy(5,6);cout<<"membres"<<char(161)<<"a, podr"<<char(160)<<"s consultar tus rentas, adeudos, d"<<char(161)<<"as restantes, etc.";
gotoxy(5,8);cout<<"Hola,                         Pel"<<char(161)<<"cula rentada #1 ";
gotoxy(5,10);cout<<"Te quedan [   ] d"<<char(161)<<"as a tu     -----------------------------------------";
gotoxy(5,11);cout<<"suscripci"<<char(162)<<"n. Puedes renovar ";
gotoxy(5,12);cout<<"cuantas veces quieras a un ";
gotoxy(5,13);cout<<"costo de $250 pesos.          Pel"<<char(161)<<"cula rentada #2";
gotoxy(5,15);cout<<"========================      ----------------------------------------- ";
gotoxy(5,16);cout<<"|| DEVOLVER PEL"<<char(161)<<"CULAS ||";
gotoxy(5,17);cout<<"========================";
gotoxy(35,18);cout<<"Pel"<<char(161)<<"cula rentada #3";
gotoxy(5,19);cout<<"----------  -------------";
gotoxy(5,20);cout<<"|  BAJA  |  |  RENOVAR  |     ----------------------------------------- ";
gotoxy(5,21);cout<<"----------  -------------";
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
