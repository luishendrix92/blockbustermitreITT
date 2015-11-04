#include <conio.h>
#include <iostream.h>
#include <windows.h>

void main(){
  int opc;

  mostrarMenu();

  cin>>opc;
  clrscr();

  switch(opc){

  	case 1:
     gotoxy(28,2);cout<<"Blockbuster: Rentar peliculas";
     render();

     getch();
     break;

  	case 2:
     gotoxy(26,2);cout<<"Blockbuster: Venta de Peliculas\n\n";
     render();


     getch();
     break;

     case 3:
     gotoxy(30,2);cout<<"Blockbuster: Membresias\n\n";
     render();


     getch();
     break;

     
     case 4:
     	exit(0);
     break;
  	default:
     	cout<<"Esa opcion no existe. ENTER para salir del programa.\n";
        getch();
        clrscr();
        void main();
  }

  getch();
}