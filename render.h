/*  Rendereado de texto y marcos
    para la ventana de consola.
================================================= */
#ifndef dibujoRender
#define dibujoRender
using namespace std;

void dibujarBordes() {
  int tamHorizontal = 110, tamVertical = 28;

  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, (tamVertical-1)); cout<<"_";
  } // Borde inferior
  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, 3); cout<<"_";
  } // Borde de titulo superior
  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, 1); cout<<"_";
  } // Borde de titulo inferior
  for(int y = 2; y < tamVertical; y+=1) {
    gotoxy((tamHorizontal-1), y); cout<<"|";
  } // Borde lateral derecho
  for(int y = 2; y < tamVertical; y+=1) {
    gotoxy(3, y); cout<<"|";
  } // Borde lateral izquierdo
} // Fin de dibujar bordes

void dibujarMenu(string menu) {
  int opcion;
  if (strcmp(menu, "principal") == 0) {
    opcion = 1;
  } else if (strcmp(menu, "clientes") == 0) {
    opcion = 2;
  } else if (strcmp(menu, "admins") == 0) {
    // Opcion
  } else if (strcmp(menu, "nuevoMenu") == 0) {
    // Opcion
  } else if (strcmp(menu, "nuevoMenu") == 0) {
    // Opcion
  } // Fin de dar valor a opcion

  dibujarBordes();
  gotoxy(18,2); cout << "BLOCKBUSTER: VENTA Y RENTA DE PELICULAS";
  gotoxy(27,5); cout << "Que es lo que deseas hacer?";
  gotoxy(5,9);  cout << "Menu:";
  gotoxy(5,12); cout << "1.- Rentar peliculas";
  gotoxy(5,14); cout << "2.- Comprar peliculas";
  gotoxy(5,16); cout << "3.- Membresias";
  gotoxy(5,18); cout << "4.- Salir";
  gotoxy(5,24); cout << "Opcion: ";
} // Fin de mostrar menu principal

void intro() {
  int velocidad = 280;

  // Colorear pantalla azul y letra amarilla
  system("cls");
  system("color 16");

  // Fotograma 1 - B
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   "<<endl;
  cout<<"\tB::::::::::::::::B  "<<endl;
  cout<<"\tB::::::BBBBBB:::::B "<<endl;
  cout<<"\tBB:::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::BBBBBB:::::B "<<endl;
  cout<<"\t  B:::::::::::::BB  "<<endl;
  cout<<"\t  B::::BBBBBB:::::B "<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\tBB:::::BBBBBB::::::B"<<endl;
  cout<<"\tB:::::::::::::::::B "<<endl;
  cout<<"\tB::::::::::::::::B  "<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB   "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 2 - BL
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLL             "<<endl;
  cout<<"\tB::::::::::::::::B  L:::::::::L             "<<endl;
  cout<<"\tB::::::BBBBBB:::::B L:::::::::L             "<<endl;
  cout<<"\tBB:::::B     B:::::BLL:::::::LL             "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               "<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               "<<endl;
  cout<<"\t  B:::::::::::::BB    L:::::L               "<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L         LLLLLL"<<endl;
  cout<<"\tBB:::::BBBBBB::::::BLL:::::::LLLLLLLLL:::::L"<<endl;
  cout<<"\tB:::::::::::::::::B L::::::::::::::::::::::L"<<endl;
  cout<<"\tB::::::::::::::::B  L::::::::::::::::::::::L"<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLLLLLLLLLLLLLLL"<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 3 - BLO
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLL                  OOOOOOOOO     "<<endl;
  cout<<"\tB::::::::::::::::B  L:::::::::L                OO:::::::::OO   "<<endl;
  cout<<"\tB::::::BBBBBB:::::B L:::::::::L              OO:::::::::::::OO "<<endl;
  cout<<"\tBB:::::B     B:::::BLL:::::::LL             O:::::::OOO:::::::O"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O::::::O   O::::::O"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::O"<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::O"<<endl;
  cout<<"\t  B:::::::::::::BB    L:::::L               O:::::O     O:::::O"<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::O"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::O"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::O"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L         LLLLLLO::::::O   O::::::O"<<endl;
  cout<<"\tBB:::::BBBBBB::::::BLL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::O"<<endl;
  cout<<"\tB:::::::::::::::::B L::::::::::::::::::::::L OO:::::::::::::OO "<<endl;
  cout<<"\tB::::::::::::::::B  L::::::::::::::::::::::L   OO:::::::::OO   "<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO     "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 4 - BLOC
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLL                  OOOOOOOOO             CCCCCCCCCCCCC"<<endl;
  cout<<"\tB::::::::::::::::B  L:::::::::L                OO:::::::::OO        CCC::::::::::::C"<<endl;
  cout<<"\tB::::::BBBBBB:::::B L:::::::::L              OO:::::::::::::OO    CC:::::::::::::::C"<<endl;
  cout<<"\tBB:::::B     B:::::BLL:::::::LL             O:::::::OOO:::::::O  C:::::CCCCCCCC::::C"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O::::::O   O::::::O C:::::C       CCCCCC"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  B:::::::::::::BB    L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L         LLLLLLO::::::O   O::::::O C:::::C       CCCCCC"<<endl;
  cout<<"\tBB:::::BBBBBB::::::BLL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::O  C:::::CCCCCCCC::::C"<<endl;
  cout<<"\tB:::::::::::::::::B L::::::::::::::::::::::L OO:::::::::::::OO    CC:::::::::::::::C"<<endl;
  cout<<"\tB::::::::::::::::B  L::::::::::::::::::::::L   OO:::::::::OO        CCC::::::::::::C"<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO             CCCCCCCCCCCCC"<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 5 - BLOCK
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLL                  OOOOOOOOO             CCCCCCCCCCCCCKKKKKKKKK    KKKKKKK"<<endl;
  cout<<"\tB::::::::::::::::B  L:::::::::L                OO:::::::::OO        CCC::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\tB::::::BBBBBB:::::B L:::::::::L              OO:::::::::::::OO    CC:::::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\tBB:::::B     B:::::BLL:::::::LL             O:::::::OOO:::::::O  C:::::CCCCCCCC::::CK:::::::K   K::::::K"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O::::::O   O::::::O C:::::C       CCCCCCKK::::::K  K:::::KKK"<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::OC:::::C                K:::::K K:::::K   "<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::OC:::::C                K::::::K:::::K    "<<endl;
  cout<<"\t  B:::::::::::::BB    L:::::L               O:::::O     O:::::OC:::::C                K:::::::::::K     "<<endl;
  cout<<"\t  B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::OC:::::C                K:::::::::::K     "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::OC:::::C                K::::::K:::::K    "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L               O:::::O     O:::::OC:::::C                K:::::K K:::::K   "<<endl;
  cout<<"\t  B::::B     B:::::B  L:::::L         LLLLLLO::::::O   O::::::O C:::::C       CCCCCCKK::::::K  K:::::KKK"<<endl;
  cout<<"\tBB:::::BBBBBB::::::BLL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::O  C:::::CCCCCCCC::::CK:::::::K   K::::::K"<<endl;
  cout<<"\tB:::::::::::::::::B L::::::::::::::::::::::L OO:::::::::::::OO    CC:::::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\tB::::::::::::::::B  L::::::::::::::::::::::L   OO:::::::::OO        CCC::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB   LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO             CCCCCCCCCCCCCKKKKKKKKK    KKKKKKK"<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 6 - B
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   "<<endl;
  cout<<"\tB::::::::::::::::B  "<<endl;
  cout<<"\tB::::::BBBBBB:::::B "<<endl;
  cout<<"\tBB:::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::BBBBBB:::::B "<<endl;
  cout<<"\t  B:::::::::::::BB  "<<endl;
  cout<<"\t  B::::BBBBBB:::::B "<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\t  B::::B     B:::::B"<<endl;
  cout<<"\tBB:::::BBBBBB::::::B"<<endl;
  cout<<"\tB:::::::::::::::::B "<<endl;
  cout<<"\tB::::::::::::::::B  "<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB   "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 7 - Letra BU
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   UUUUUUUU     UUUUUUUU"<<endl;
  cout<<"\tB::::::::::::::::B  U::::::U     U::::::U"<<endl;
  cout<<"\tB::::::BBBBBB:::::B U::::::U     U::::::U"<<endl;
  cout<<"\tBB:::::B     B:::::BUU:::::U     U:::::UU"<<endl;
  cout<<"\t  B::::B     B:::::B U:::::U     U:::::U "<<endl;
  cout<<"\t  B::::B     B:::::B U:::::D     D:::::U "<<endl;
  cout<<"\t  B::::BBBBBB:::::B  U:::::D     D:::::U "<<endl;
  cout<<"\t  B:::::::::::::BB   U:::::D     D:::::U "<<endl;
  cout<<"\t  B::::BBBBBB:::::B  U:::::D     D:::::U "<<endl;
  cout<<"\t  B::::B     B:::::B U:::::D     D:::::U "<<endl;
  cout<<"\t  B::::B     B:::::B U:::::D     D:::::U "<<endl;
  cout<<"\t  B::::B     B:::::B U::::::U   U::::::U "<<endl;
  cout<<"\tBB:::::BBBBBB::::::B U:::::::UUU:::::::U "<<endl;
  cout<<"\tB:::::::::::::::::B   UU:::::::::::::UU  "<<endl;
  cout<<"\tB::::::::::::::::B      UU:::::::::UU    "<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB         UUUUUUUUU      "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 8 - Letra BUS
  cout<<"\n\n\n\n";
  cout<<"\tBBBBBBBBBBBBBBBBB   UUUUUUUU     UUUUUUUU   SSSSSSSSSSSSSSS "<<endl;
  cout<<"\tB::::::::::::::::B  U::::::U     U::::::U SS:::::::::::::::S"<<endl;
  cout<<"\tB::::::BBBBBB:::::B U::::::U     U::::::US:::::SSSSSS::::::S"<<endl;
  cout<<"\tBB:::::B     B:::::BUU:::::U     U:::::UUS:::::S     SSSSSSS"<<endl;
  cout<<"\t  B::::B     B:::::B U:::::U     U:::::U S:::::S            "<<endl;
  cout<<"\t  B::::B     B:::::B U:::::D     D:::::U S:::::S            "<<endl;
  cout<<"\t  B::::BBBBBB:::::B  U:::::D     D:::::U  S::::SSSS         "<<endl;
  cout<<"\t  B:::::::::::::BB   U:::::D     D:::::U   SS::::::SSSSS    "<<endl;
  cout<<"\t  B::::BBBBBB:::::B  U:::::D     D:::::U     SSS::::::::SS  "<<endl;
  cout<<"\t  B::::B     B:::::B U:::::D     D:::::U        SSSSSS::::S "<<endl;
  cout<<"\t  B::::B     B:::::B U:::::D     D:::::U             S:::::S"<<endl;
  cout<<"\t  B::::B     B:::::B U::::::U   U::::::U             S:::::S"<<endl;
  cout<<"\tBB:::::BBBBBB::::::B U:::::::UUU:::::::U SSSSSSS     S:::::S"<<endl;
  cout<<"\tB:::::::::::::::::B   UU:::::::::::::UU  S::::::SSSSSS:::::S"<<endl;
  cout<<"\tB::::::::::::::::B      UU:::::::::UU    S:::::::::::::::SS "<<endl;
  cout<<"\tBBBBBBBBBBBBBBBBB         UUUUUUUUU       SSSSSSSSSSSSSSS   "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 9 - Letra T
  cout<<"\n\n\n\n";
  cout<<"\tTTTTTTTTTTTTTTTTTTTTTTT"<<endl;
  cout<<"\tT:::::::::::::::::::::T"<<endl;
  cout<<"\tT:::::::::::::::::::::T"<<endl;
  cout<<"\tT:::::TT:::::::TT:::::T"<<endl;
  cout<<"\tTTTTTT  T:::::T  TTTTTT"<<endl;
  cout<<"\t        T:::::T        "<<endl;
  cout<<"\t        T:::::T        "<<endl;
  cout<<"\t        T:::::T        "<<endl;
  cout<<"\t        T:::::T        "<<endl;
  cout<<"\t        T:::::T        "<<endl;
  cout<<"\t        T:::::T        "<<endl;
  cout<<"\t        T:::::T        "<<endl;
  cout<<"\t      TT:::::::TT      "<<endl;
  cout<<"\t      T:::::::::T      "<<endl;
  cout<<"\t      T:::::::::T      "<<endl;
  cout<<"\t      TTTTTTTTTTT      "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 10 - Letra TE
  cout<<"\n\n\n\n";
  cout<<"\tTTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEE"<<endl;
  cout<<"\tT:::::::::::::::::::::TE::::::::::::::::::::E"<<endl;
  cout<<"\tT:::::::::::::::::::::TE::::::::::::::::::::E"<<endl;
  cout<<"\tT:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::E"<<endl;
  cout<<"\tTTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE"<<endl;
  cout<<"\t        T:::::T          E:::::E             "<<endl;
  cout<<"\t        T:::::T          E::::::EEEEEEEEEE   "<<endl;
  cout<<"\t        T:::::T          E:::::::::::::::E   "<<endl;
  cout<<"\t        T:::::T          E:::::::::::::::E   "<<endl;
  cout<<"\t        T:::::T          E::::::EEEEEEEEEE   "<<endl;
  cout<<"\t        T:::::T          E:::::E             "<<endl;
  cout<<"\t        T:::::T          E:::::E       EEEEEE"<<endl;
  cout<<"\t      TT:::::::TT      EE::::::EEEEEEEE:::::E"<<endl;
  cout<<"\t      T:::::::::T      E::::::::::::::::::::E"<<endl;
  cout<<"\t      T:::::::::T      E::::::::::::::::::::E"<<endl;
  cout<<"\t      TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEE"<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 11 - Letra TER
  cout<<"\n\n\n\n";
  cout<<"\tTTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR   "<<endl;
  cout<<"\tT:::::::::::::::::::::TE::::::::::::::::::::ER::::::::::::::::R  "<<endl;
  cout<<"\tT:::::::::::::::::::::TE::::::::::::::::::::ER::::::RRRRRR:::::R "<<endl;
  cout<<"\tT:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::ERR:::::R     R:::::R"<<endl;
  cout<<"\tTTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE  R::::R     R:::::R"<<endl;
  cout<<"\t        T:::::T          E:::::E               R::::R     R:::::R"<<endl;
  cout<<"\t        T:::::T          E::::::EEEEEEEEEE     R::::RRRRRR:::::R "<<endl;
  cout<<"\t        T:::::T          E:::::::::::::::E     R:::::::::::::RR  "<<endl;
  cout<<"\t        T:::::T          E:::::::::::::::E     R::::RRRRRR:::::R "<<endl;
  cout<<"\t        T:::::T          E::::::EEEEEEEEEE     R::::R     R:::::R"<<endl;
  cout<<"\t        T:::::T          E:::::E               R::::R     R:::::R"<<endl;
  cout<<"\t        T:::::T          E:::::E       EEEEEE  R::::R     R:::::R"<<endl;
  cout<<"\t      TT:::::::TT      EE::::::EEEEEEEE:::::ERR:::::R     R:::::R"<<endl;
  cout<<"\t      T:::::::::T      E::::::::::::::::::::ER::::::R     R:::::R"<<endl;
  cout<<"\t      T:::::::::T      E::::::::::::::::::::ER::::::R     R:::::R"<<endl;
  cout<<"\t      TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR"<<endl;
  Sleep(velocidad*3); system("cls");
} // Fin de intro con logo
#endif