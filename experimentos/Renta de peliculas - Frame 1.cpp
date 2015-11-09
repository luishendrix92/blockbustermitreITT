#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();
void dibujarRentas();

void main(){

dibujarBordes();
dibujarRentas();

gotoxy(29,2);cout<<"RENTA DE PELICULAS";
gotoxy(5,5);cout<<"Que pelicula deseas rentar?";
gotoxy(5,9);cout<<"Cuando tengas los resultados";
gotoxy(5,10);cout<<"que buscas, presiona <ENTER>";
gotoxy(5,12);cout<<"Estas son las peliculas que";
gotoxy(5,13);cout<<"has rentado: ";
gotoxy(6,15);cout<<"1: ";
gotoxy(6,16);cout<<"2: ";
gotoxy(6,17);cout<<"3: ";
gotoxy(6,18);cout<<"4: ";
gotoxy(6,19);cout<<"5: ";
gotoxy(36,4);cout<<"ID";
gotoxy(41,4);cout<<"Titulo";
gotoxy(73,4);cout<<"A"<<char(164)<<"o";
gotoxy(45,12);cout<<"Los resultados de tu";
gotoxy(46,13);cout<<"busqueda van a ir";
gotoxy(46,14);cout<<"apareciendo aqui!";




gotoxy(5,23);cout<<"Para volver al menu anterior, presiona <ESC>.";

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

//Lineas interiores del menu de Rentas 2.1
void dibujarRentas(){

for(int x=5;x<31;x++){
gotoxy(x,7);cout<<"_";}
for(int x=5;x<32;x++){
gotoxy(x,14);cout<<"-";}
for(int x=5;x<32;x++){
gotoxy(x,20);cout<<"-";}
for(int x=35;x<77;x++){
gotoxy(x,5);cout<<"-";}
for(int y=15;y<20;y++){
gotoxy(5,y);cout<<"|";}
for(int y=15;y<20;y++){
gotoxy(32,y);cout<<"|";}
for(int y=4;y<22;y++){
gotoxy(35,y);cout<<"|";}
for(int y=4;y<22;y++){
gotoxy(39,y);cout<<"|";}
for(int y=4;y<22;y++){
gotoxy(72,y);cout<<"|";}


}
//Fin dibujar lineas de menu de Rentas 2.1