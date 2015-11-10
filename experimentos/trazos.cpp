#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

void gotoxy(int x, int y) {
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
} // Fin de añadir GoToXY

void rectangulo(int x1, int y1, int x2, int y2, string relleno) {
  for (int renglon=y1; renglon <= y2; renglon+=1) {
    for(int x=x1, y=renglon; x <= x2; x+=1) {
      gotoxy(x, y); cout << relleno;
    } // Fin de trazar renglón
  } // Fin de trazar rectángulo
} // Fin de trazar líneas horizontales

int main() {
  system("cls");
  rectangulo(4,2,76,21,"@");rectangulo(4,2,76,21,"/");rectangulo(4,2,76,21,"6");
  getch();
} // Fin de programa