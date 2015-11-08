#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <sstream>
//#include <regex>

using namespace std;

void gotoxy(int x, int y) {
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
} // Fin de añadir GoToXY

int main() {
  system("cls");
  cout << "Repite contrase"<<char(164)<<"a:" << endl;
  cout << "allahuakbar164" << endl;
  cout << "__________________" << endl;
} // Fin de programa