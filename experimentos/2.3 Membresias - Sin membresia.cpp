#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();



void main(){

dibujarBordes();


gotoxy(33,2);cout<<"MEMBRES"<<char(161)<<"AS";
gotoxy(5,5);cout<<"Bienvenidos al programa de membres"<<char(161)<<"as de Blockbuster. Parece que a"<<char(163)<<"n no";
gotoxy(5,6);cout<<"est"<<char(160)<<"s afiliado al programa. Los beneficios son: ";
gotoxy(5,9);cout<<"1: Tienes derecho a 5 pel"<<char(161)<<"culas";
gotoxy(5,10);cout<<"rentadas como m"<<char(160)<<"ximo.";
gotoxy(5,12);cout<<"2: Recibir"<<char(160)<<"s un descuento";
gotoxy(5,13);cout<<"del 10% en tus compras.";
gotoxy(5,15);cout<<"3: Tickets a estrenos en el";
gotoxy(5,16);cout<<"cine durante festividades.";
gotoxy(5,18);cout<<"===============  ------------";
gotoxy(5,19);cout<<"|| AFILIARME ||  |  REGLAS  |";
gotoxy(5,20);cout<<"===============  ------------";
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
