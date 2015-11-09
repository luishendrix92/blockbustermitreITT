#include <conio.h>
#include <iostream.h>
#include <windows.h>

void dibujarBordes();
void dibujarInteriores2();

void main(){

dibujarBordes();
dibujarInteriores2();

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
gotoxy(49,11);cout<<"Contrase"<<char(164)<<"a:";
gotoxy(42,16);cout<<"ENTRAR";


gotoxy(5,23);cout<<"Utiliza las teclas de direccion para moverte entre campos.";



//Como se veria el boton de ENTRAR
    //Lado superior boton ENTRAR
gotoxy(39,15);cout<<"-";
gotoxy(40,15);cout<<"-";
gotoxy(41,15);cout<<"-";
gotoxy(42,15);cout<<"-";
gotoxy(43,15);cout<<"-";
gotoxy(44,15);cout<<"-";
gotoxy(45,15);cout<<"-";
gotoxy(46,15);cout<<"-";
gotoxy(47,15);cout<<"-";
gotoxy(48,15);cout<<"-";
gotoxy(49,15);cout<<"-";
gotoxy(50,15);cout<<"-";

	 //Lados derecho e izquierdo boton ENTRAR
gotoxy(39,16);cout<<"|";
gotoxy(50,16);cout<<"|";

	//Lado inferior boton ENTRAR
gotoxy(39,17);cout<<"-";
gotoxy(40,17);cout<<"-";
gotoxy(41,17);cout<<"-";
gotoxy(42,17);cout<<"-";
gotoxy(43,17);cout<<"-";
gotoxy(44,17);cout<<"-";
gotoxy(45,17);cout<<"-";
gotoxy(46,17);cout<<"-";
gotoxy(47,17);cout<<"-";
gotoxy(48,17);cout<<"-";
gotoxy(49,17);cout<<"-";
gotoxy(50,17);cout<<"-";









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

//Lineas interiores del menu Frame 3
void dibujarInteriores2(){
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
for(int y=15;y<20;y++){
gotoxy(20,y);cout<<"|";}
for(int y=11;y<20;y++){
gotoxy(69,y);cout<<"|";}
for(int x=23;x<40;x++){
gotoxy(x,13);cout<<"-";}
for(int x=49;x<67;x++){
gotoxy(x,13);cout<<"-";}
gotoxy(20,11);cout<<"|";
}
//Fin dibujar lineas interiores2 (dibujarInteriores2 es unicamente para el Frame 3)