#include <conio.h>
#include <iostream.h>
#include <windows.h>


void menu();
void render();




void main(){

int opc;

render();
gotoxy(18,2);cout<<"Blockbuster: Venta/Renta/Prestamos de Peliculas\n\n";
gotoxy(27,5);cout<<"Que es lo que desea hacer?";
gotoxy(5,9);cout<<"Menu: ";
gotoxy(5,12);cout<<"1.- Rentar peliculas ";
gotoxy(5,14);cout<<"2.- Comprar peliculas ";
gotoxy(5,16);cout<<"3.- Membresias ";
gotoxy(5,18);cout<<"4.- Salir ";

gotoxy(5,24);cout<<"Opcion: ";

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

void render(){

for(int x=3;x<80;x++){
gotoxy(x,25);cout<<"_";}
for(int x=3;x<80;x++){
gotoxy(x,3);cout<<"_";}
for(int x=3;x<80;x++){
gotoxy(x,1);cout<<"_";}
for(int y=2;y<26;y++){
gotoxy(79,y);cout<<"|";}
for(int y=2;y<26;y++){
gotoxy(3,y);cout<<"|";}

}
