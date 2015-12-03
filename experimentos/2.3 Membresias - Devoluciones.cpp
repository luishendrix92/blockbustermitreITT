#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();



void main(){

dibujarBordes();


gotoxy(29,2);cout<<"MEMBRES"<<char(161)<<"AS: DEVOLUCI"<<char(162)<<"N";
gotoxy(5,5);cout<<"Si est"<<char(160)<<"s devolviendo pel"<<char(161)<<"culas por atraso, tendr"<<char(160)<<"s que primero ir";
gotoxy(5,6);cout<<"al men"<<char(163)<<" de 'Cr"<<char(130)<<"dito' y cubrir el saldo negativo (adeudo) abonando ";
gotoxy(5,7);cout<<"a tu cuenta el equivalente del adeudo.";
gotoxy(5,9);cout<<"Marca las pel"<<char(161)<<"culas que deseas devolver: ";
gotoxy(56,11);cout<<"--------------";
gotoxy(56,12);cout<<"|  DEVOLVER  |";
gotoxy(56,13);cout<<"--------------";
gotoxy(56,15);cout<<"--------------";
gotoxy(56,16);cout<<"|  CANCELAR  |";
gotoxy(56,17);cout<<"--------------";
gotoxy(5,23);cout<<"Utiliza las teclas direccionales para moverte.";






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