#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();



void main(){

dibujarBordes();


gotoxy(28,2);cout<<"CATALOGO DE PELICULAS";
gotoxy(5,5);cout<<"En este men"<<char(163)<<" podr"<<char(160)<<"s consultar todas las peliculas que tenemos y podr"<<char(160)<<"s";
gotoxy(5,6);cout<<"comprar o rentarlas desde aqu"<<char(161)<<". Desplazate utilizando las teclas de";
gotoxy(5,7);cout<<"direcci"<<char(162)<<"n y presiona <ENTER> cuando quieras consualtar esa categor"<<char(161)<<"a.";
gotoxy(5,10);cout<<"============  ------------  -----------  --------------  ------------ ";
gotoxy(5,11);cout<<"|| HORROR ||  |  SCI-FI  |  |  DRAMA  |  |  AVENTURA  |  |  ACCION  |";
gotoxy(5,12);cout<<"============  ------------  -----------  --------------  ------------ ";
gotoxy(9,14);cout<<"--------------  -------------  -------------  --------------- ";
gotoxy(9,15);cout<<"|  BIOGRAFIA |  |  COMEDIA  |  |  ROMANCE  |  |  DOCUMENTAL |";
gotoxy(9,16);cout<<"--------------  -------------  -------------  --------------- ";
gotoxy(25,18);cout<<"--------------  --------------- ";
gotoxy(25,19);cout<<"|  ESTRENOS  |  |  EN REMATE  |";
gotoxy(25,20);cout<<"--------------  --------------- ";
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

