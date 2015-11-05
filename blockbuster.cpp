#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
//#include "ayudas.cpp"
#include "render.cpp"

using namespace std;

void gotoxy(int x,int y){  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
} // Fin de añadir GoToXY

int main() {
	/*
    1. Rentar Peliculas
    2. Comprar Pelicula --> 
    3. Membresias
    4. Salir
  */
  
  logo();
  getch();
} // Fin del programa
