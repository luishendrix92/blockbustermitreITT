#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();



void main(){

dibujarBordes();


gotoxy(35,2);cout<<"$ CR"<<char(130)<<"DITO $ ";
gotoxy(5,5);cout<<"Desde aqu"<<char(161)<<" podr"<<char(160)<<"s consultar el cr"<<char(130)<<"dito con el que dispones. ";
gotoxy(5,6);cout<<"Si te acabas de registrar, tendr"<<char(160)<<"s $0 y necesitar"<<char(160)<<"s agregar dinero ";
gotoxy(5,7);cout<<"a tu cuenta. Sin cr"<<char(130)<<"dito no podr"<<char(160)<<"s comprar pel"<<char(161)<<"culas. ";
gotoxy(5,9);cout<<"Usuario: ";
gotoxy(5,10);cout<<"--------------------";
gotoxy(5,11);cout<<"|                  | ";
gotoxy(5,12);cout<<"|------------------|";
gotoxy(5,14);cout<<"Balance: ";
gotoxy(5,15);cout<<"-------------";
gotoxy(5,16);cout<<"|           |";
gotoxy(5,17);cout<<"-------------";
gotoxy(5,20);cout<<"L"<<char(161)<<"mite: $9999.0";
gotoxy(36,9);cout<<"Monto abonado:";
gotoxy(36,10);cout<<"$";
gotoxy(36,11);cout<<"--------------";
gotoxy(36,13);cout<<"*-*";
gotoxy(36,14);cout<<"| | Abonar a otra persona";
gotoxy(36,15);cout<<"*-*";
gotoxy(36,17);cout<<"============  --------------";
gotoxy(36,18);cout<<"|| ABONAR ||  |  CANCELAR  |";
gotoxy(36,19);cout<<"============  --------------";
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






