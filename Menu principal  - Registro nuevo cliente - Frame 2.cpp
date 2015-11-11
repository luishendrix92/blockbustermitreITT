#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();
void dibujarInteriores();

void main(){

dibujarBordes();
dibujarInteriores();

gotoxy(26,2);cout<<"MENU PRINCIPAL BLOCKBUSTER";
gotoxy(5,5);cout<<"Bienvenido al sistema de rentas y compras virtual de Blockbuster.";
gotoxy(5,6);cout<<"Si eres nuevo en este sistema, elige la opcion 'Crear cuenta', si";
gotoxy(5,7);cout<<"ya tienes una cuenta de cliente o eres empleado de Blockbuster y";
gotoxy(5,8);cout<<"deseas realizar cambios a la base de datos, elige 'Ingresar'.";
gotoxy(7,11);cout<<"CREAR CUENTA";
gotoxy(7,13);cout<<"INGRESAR";
gotoxy(5,16);cout<<"Presione <ESC>";
gotoxy(5,17);cout<<"para volver";
gotoxy(5,18);cout<<"atras";
gotoxy(23,11);cout<<"Nombre de usuario: ";
gotoxy(23,16);cout<<"Contrase"<<char(164)<<"a:";
gotoxy(50,11);cout<<"Repite contrase"<<char(164)<<"a:";
gotoxy(60,17);cout<<"LISTO";
gotoxy(5,23);cout<<"Utiliza las teclas de direccion para moverte entre campos.";



//Como se veria el boton de LISTO
    //Lado superior boton LISTO
gotoxy(57,16);cout<<"-";
gotoxy(58,16);cout<<"-";
gotoxy(59,16);cout<<"-";
gotoxy(60,16);cout<<"-";
gotoxy(61,16);cout<<"-";
gotoxy(62,16);cout<<"-";
gotoxy(63,16);cout<<"-";
gotoxy(64,16);cout<<"-";
gotoxy(65,16);cout<<"-";
gotoxy(66,16);cout<<"-";
gotoxy(67,16);cout<<"-";

	 //Lados derecho e izquierdo boton LISTO
gotoxy(57,17);cout<<"|";
gotoxy(67,17);cout<<"|";
gotoxy(57,18);cout<<"-";

    //Lado inferior boton LISTO
gotoxy(58,18);cout<<"-";
gotoxy(59,18);cout<<"-";
gotoxy(60,18);cout<<"-";
gotoxy(61,18);cout<<"-";
gotoxy(62,18);cout<<"-";
gotoxy(63,18);cout<<"-";
gotoxy(64,18);cout<<"-";
gotoxy(65,18);cout<<"-";
gotoxy(66,18);cout<<"-";
gotoxy(67,18);cout<<"-";









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

//Lineas interiores del menu Frame 2
void dibujarInteriores(){
for(int x=5;x<70;x++){
gotoxy(x,10);cout<<"-";}
for(int x=20;x<70;x++){
gotoxy(x,20);cout<<"-";}
for(int x=5;x<20;x++){
gotoxy(x,14);cout<<"-";}
for(int x=5;x<20;x++){
gotoxy(x,12);cout<<"-";}
for(int y=11;y<14;y++){
gotoxy(5,y);cout<<"|";}
for(int y=12;y<20;y++){
gotoxy(20,y);cout<<"|";}
for(int y=11;y<20;y++){
gotoxy(69,y);cout<<"|";}
for(int x=23;x<40;x++){
gotoxy(x,13);cout<<"-";}
for(int x=23;x<40;x++){
gotoxy(x,18);cout<<"-";}
for(int x=50;x<67;x++){
gotoxy(x,13);cout<<"-";}
}
//Fin dibujar lineas interiores





