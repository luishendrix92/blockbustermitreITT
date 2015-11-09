#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <sstream>
using namespace std;

void gotoxy(int x, int y) {
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
} // Fin de añadir GoToXY

void dibujarBordes();

int main() {
  system("cls");
  dibujarBordes();

  gotoxy(26,2);cout<<"MENU PRINCIPAL BLOCKBUSTER\n\n";
  gotoxy(5,5);cout<<"Bienvenido al sistema de rentas y compras virtual de Blockbuster.";
  gotoxy(5,6);cout<<"Si eres nuevo en este sistema, elige una opcion 'Crear cuenta', si";
  gotoxy(5,7);cout<<"ya tienes una cuenta de cliente o eres empleado de Blockbuster y";
  gotoxy(5,8);cout<<"deseas realizar cambios a la base de datos, elige 'Ingresar'.";
  gotoxy(22,19);cout<<"Presione <ESC> para volver atras.";
  gotoxy(5,23);cout<<"Utiliza las teclas <IZQ> y <DER> para elegir una opcion y pulsa <ENTER>";

  gotoxy(25,14);cout<<"CREAR CUENTA";
  gotoxy(44,14);cout<<"INGRESAR";
  //Aqui ''serian'' los botones, pero solo los pongo asi para ver como se verian//

  //Boton CREAR CUENTA//
  gotoxy(22,14);cout<<"|";
  gotoxy(23,14);cout<<"|";
  gotoxy(38,14);cout<<"|";
  gotoxy(39,14);cout<<"|";

  //Linea superior boton ''Crear cuenta''//
  gotoxy(22,13);cout<<"=";
  gotoxy(23,13);cout<<"=";
  gotoxy(24,13);cout<<"=";
  gotoxy(25,13);cout<<"=";
  gotoxy(26,13);cout<<"=";
  gotoxy(27,13);cout<<"=";
  gotoxy(28,13);cout<<"=";
  gotoxy(29,13);cout<<"=";
  gotoxy(30,13);cout<<"=";
  gotoxy(31,13);cout<<"=";
  gotoxy(32,13);cout<<"=";
  gotoxy(33,13);cout<<"=";
  gotoxy(34,13);cout<<"=";
  gotoxy(35,13);cout<<"=";
  gotoxy(36,13);cout<<"=";
  gotoxy(37,13);cout<<"=";
  gotoxy(38,13);cout<<"=";
  gotoxy(39,13);cout<<"=";

  //Linea inferior boton ''Crear cuenta''//
  gotoxy(22,15);cout<<"=";
  gotoxy(23,15);cout<<"=";
  gotoxy(24,15);cout<<"=";
  gotoxy(25,15);cout<<"=";
  gotoxy(26,15);cout<<"=";
  gotoxy(27,15);cout<<"=";
  gotoxy(28,15);cout<<"=";
  gotoxy(29,15);cout<<"=";
  gotoxy(30,15);cout<<"=";
  gotoxy(31,15);cout<<"=";
  gotoxy(32,15);cout<<"=";
  gotoxy(33,15);cout<<"=";
  gotoxy(34,15);cout<<"=";
  gotoxy(35,15);cout<<"=";
  gotoxy(36,15);cout<<"=";
  gotoxy(37,15);cout<<"=";
  gotoxy(38,15);cout<<"=";
  gotoxy(39,15);cout<<"=";

  //Boton ''INGRESAR''//
  gotoxy(41,14);cout<<"|";
  gotoxy(54,14);cout<<"|";

  //Linea superior boton INGRESAR//
  gotoxy(41,13);cout<<"-";
  gotoxy(42,13);cout<<"-";
  gotoxy(43,13);cout<<"-";
  gotoxy(44,13);cout<<"-";
  gotoxy(45,13);cout<<"-";
  gotoxy(46,13);cout<<"-";
  gotoxy(47,13);cout<<"-";
  gotoxy(48,13);cout<<"-";
  gotoxy(49,13);cout<<"-";
  gotoxy(50,13);cout<<"-";
  gotoxy(51,13);cout<<"-";
  gotoxy(52,13);cout<<"-";
  gotoxy(53,13);cout<<"-";
  gotoxy(54,13);cout<<"-";

  //Linea inferior boton INGRESAR//

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
  gotoxy(51,15);cout<<"-";
  gotoxy(52,15);cout<<"-";
  gotoxy(53,15);cout<<"-";
  gotoxy(54,15);cout<<"-";

  getch();
}

void dibujarBordes() {
  int tamHorizontal = 78, tamVertical = 23;

  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, (tamVertical-1)); cout<<"_";
  } // Borde inferior
  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, 3); cout<<"_";
  } // Borde de titulo inferior
  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, 1); cout<<"_";
  } // Borde de titulo superior
  for(int y = 2; y < tamVertical; y+=1) {
    gotoxy((tamHorizontal-1), y); cout<<"|";
  } // Borde lateral derecho
  for(int y = 2; y < tamVertical; y+=1) {
    gotoxy(3, y); cout<<"|";
  } // Borde lateral izquierdo
} // Fin de dibujar bordes


