/*  Rendereado de texto y marcos
    para la ventana de consola.
================================================= */
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

void dibujarMenu(string menu) {
  if (menu.compare("1_principal") == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(26,2);    cout<<"MENU PRINCIPAL BLOCKBUSTER\n\n";
    gotoxy(5, 5);    cout<<"Bienvenido al sistema de rentas y compras virtual de Blockbuster.";
    gotoxy(5, 6);    cout<<"Si eres nuevo en este sistema, elige una opcion 'Crear cuenta', si";
    gotoxy(5, 7);    cout<<"ya tienes una cuenta de cliente o eres empleado de Blockbuster y";
    gotoxy(5, 8);    cout<<"deseas realizar cambios a la base de datos, elige 'Ingresar'.";
    gotoxy(22,19);   cout<<"Presione <ESC> para volver atras.";
    gotoxy(5, 23);   cout<<"Utiliza las teclas <IZQ> y <DER> para elegir una opcion y pulsa <ENTER>";
    // Renderizado de botones
    gotoxy(22, 13);  cout << "==================";
    gotoxy(22, 14);  cout << "|| CREAR CUENTA ||";
    gotoxy(22, 15);  cout << "==================";

    gotoxy(41, 13);  cout << "--------------";
    gotoxy(41, 14);  cout << "|  INGRESAR  |";
    gotoxy(41, 15);  cout << "--------------";
    // Mover cursor al botón default (CREAR CUENTA)
    gotoxy(25, 14);
  } else if (menu.compare("1_principal_registro") == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(26,2);    cout<<"MENU PRINCIPAL BLOCKBUSTER";
    gotoxy(5, 5);    cout<<"Bienvenido al sistema de rentas y compras virtual de Blockbuster.";
    gotoxy(5, 6);    cout<<"Si eres nuevo en este sistema, elige la opcion \"Crear cuenta\", si";
    gotoxy(5, 7);    cout<<"ya tienes una cuenta de cliente o eres empleado de Blockbuster y";
    gotoxy(5, 8);    cout<<"deseas realizar cambios a la base de datos, elige \"Ingresar\".";
    gotoxy(7, 11);   cout<<"CREAR CUENTA";
    gotoxy(7, 13);   cout<<"INGRESAR";
    gotoxy(5, 16);   cout<<"Presione <ESC>";
    gotoxy(5, 17);   cout<<"para volver";
    gotoxy(5, 18);   cout<<"atras.";
    gotoxy(23,11);   cout<<"Nombre de usuario:";
    gotoxy(23,16);   cout<<"Contrase"<<char(164)<<"a:";
    gotoxy(50,11);   cout<<"Repite contrase"<<char(164)<<"a:";
    gotoxy(5, 23);   cout<<"Utiliza las teclas de direccion para moverte entre campos.";
    // Renderizado de líneas
    for(int x=5; x<=69;x++)   { gotoxy(x, 10); cout<<"-"; }
    for(int x=20;x<=69;x++)   { gotoxy(x, 20); cout<<"-"; }
    for(int x=5; x<=19;x++)   { gotoxy(x, 14); cout<<"-"; }
    for(int x=5; x<=20;x++)   { gotoxy(x, 12); cout<<"-"; }
    for(int y=11;y<=13;y++)   { gotoxy(5, y);  cout<<"|"; }
    for(int y=13;y<=19;y++)   { gotoxy(20,y);  cout<<"|"; }
    for(int y=11;y<=19;y++)   { gotoxy(69,y);  cout<<"|"; }
    for(int x=23;x<=40;x++)   { gotoxy(x, 13); cout<<"-"; }
    for(int x=23;x<=40;x++)   { gotoxy(x, 18); cout<<"-"; }
    for(int x=50;x<=67;x++)   { gotoxy(x, 13); cout<<"-"; }
    // Renderizado de botones
    gotoxy(57, 16); cout << "-----------";
    gotoxy(57, 17); cout << "|  LISTO  |";
    gotoxy(57, 18); cout << "-----------";
    // Mover cursor al input default (Nombre de usuario)
    gotoxy(23, 12);
  } else if (menu.compare("1_principal_login") == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(26,2);    cout<<"MENU PRINCIPAL BLOCKBUSTER";
    gotoxy(5, 5);    cout<<"Bienvenido al sistema de rentas y compras virtual de Blockbuster.";
    gotoxy(5, 6);    cout<<"Si eres nuevo en este sistema, elige la opcion \"Crear cuenta\", si";
    gotoxy(5, 7);    cout<<"ya tienes una cuenta de cliente o eres empleado de Blockbuster y";
    gotoxy(5, 8);    cout<<"deseas realizar cambios a la base de datos, elige \"Ingresar\".";
    gotoxy(7, 11);   cout<<"CREAR CUENTA";
    gotoxy(7, 13);   cout<<"INGRESAR";
    gotoxy(5, 16);   cout<<"Presione <ESC>";
    gotoxy(5, 17);   cout<<"para volver";
    gotoxy(5, 18);   cout<<"atras";
    gotoxy(23,11);   cout<<"Nombre de usuario:";
    gotoxy(49,11);   cout<<"Contrase"<<char(164)<<"a:";
    gotoxy(5, 23);   cout<<"Utiliza las teclas de direccion para moverte entre campos.";
    // Renderizado de líneas
    for(int x=5; x<=69;x++)   { gotoxy(x, 10); cout<<"-"; }
    for(int x=20;x<=69;x++)   { gotoxy(x, 20); cout<<"-"; }
    for(int x=5; x<=20;x++)   { gotoxy(x, 14); cout<<"-"; }
    for(int x=6; x<=20;x++)   { gotoxy(x, 12); cout<<"-"; }
    for(int y=11;y<=13;y++)   { gotoxy(5, y);  cout<<"|"; } 
    for(int y=15;y<=19;y++)   { gotoxy(20,y);  cout<<"|"; }
    for(int y=11;y<=19;y++)   { gotoxy(69,y);  cout<<"|"; }
    for(int x=23;x<=40;x++)   { gotoxy(x, 13); cout<<"-"; }
    for(int x=49;x<=66;x++)   { gotoxy(x, 13); cout<<"-"; }
    gotoxy(20,11);cout<<"|";
    // Renderizado de botones
    gotoxy(39, 15); cout << "------------";
    gotoxy(39, 16); cout << "|  ENTRAR  |";
    gotoxy(39, 17); cout << "------------";
    // Mover cursor al input default (Nombre de usuario)
    gotoxy(23, 12);
  } else if (menu.compare("2_clientes")  == 0) {
    system("cls"); dibujarBordes();
    gotoxy(18,2);   cout << "BLOCKBUSTER: VENTA Y RENTA DE PELICULAS";
    gotoxy(27,5);   cout << "Que es lo que deseas hacer?";
    gotoxy(5, 9);   cout << "Menu:";
    gotoxy(5, 12);  cout << "1.- Rentar peliculas";
    gotoxy(5, 14);  cout << "2.- Comprar peliculas";
    gotoxy(5, 16);  cout << "3.- Membresias";
    gotoxy(5, 18);  cout << "4.- Salir";
    gotoxy(5, 23);  cout << "Opcion: ";
  } else if (menu.compare("2.1_renta_f1")  == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(29,2);   cout<<"RENTA DE PELICULAS";
    gotoxy(5, 5);   cout<<"Que pelicula deseas rentar?";
    gotoxy(5, 9);   cout<<"Cuando tengas los resultados";
    gotoxy(5, 10);  cout<<"que buscas, presiona <ENTER>";
    gotoxy(5, 12);  cout<<"Estas son las peliculas que";
    gotoxy(5, 13);  cout<<"has rentado: ";
    gotoxy(6, 15);  cout<<"1:";
    gotoxy(6, 16);  cout<<"2:";
    gotoxy(6, 17);  cout<<"3:";
    gotoxy(6, 18);  cout<<"4:";
    gotoxy(6, 19);  cout<<"5:";
    gotoxy(36,4);   cout<<"ID";
    gotoxy(41,4);   cout<<"Titulo";
    gotoxy(73,4);   cout<<"A"<<char(164)<<"o";
    gotoxy(45,12);  cout<<"Los resultados de tu";
    gotoxy(46,13);  cout<<"busqueda van a ir";
    gotoxy(46,14);  cout<<"apareciendo aqui!";
    gotoxy(5, 23);  cout<<"Para volver al menu anterior, presiona <ESC>.";
    // Renderlizado de líneas
    for(int x=5; x<=31;x++)    { gotoxy(x, 7);  cout<<"_"; }
    for(int x=5; x<=32;x++)    { gotoxy(x, 14); cout<<"-"; }
    for(int x=5; x<=32;x++)    { gotoxy(x, 20); cout<<"-"; }
    for(int x=36;x<=76;x++)    { gotoxy(x, 5);  cout<<"-"; }
    for(int y=15;y<=19;y++)    { gotoxy(5, y);  cout<<"|"; }
    for(int y=15;y<=19;y++)    { gotoxy(32,y);  cout<<"|"; }
    for(int y=4; y<=22;y++)    { gotoxy(35,y);  cout<<"|"; }
    for(int y=4; y<=22;y++)    { gotoxy(39,y);  cout<<"|"; }
    for(int y=4; y<=22;y++)    { gotoxy(72,y);  cout<<"|"; }
    // Mover cursor al input default (Película a buscar)
    gotoxy(5, 6);
  } else if(menu.compare("2.3_membresias_nuevo")  == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(33,2);   cout<<"MEMBRES"<<char(161)<<"AS";
    gotoxy(5, 5);   cout<<"Bienvenidos al programa de membres"<<char(161);
    gotoxy(39,5);   cout<<"as de Blockbuster. Parece que a"<<char(163)<<"n no";
    gotoxy(5, 6);   cout<<"est"<<char(160)<<"s afiliado al programa. Los beneficios son: ";
    gotoxy(5, 9);   cout<<"1: Tienes derecho a 5 pel"<<char(161)<<"culas";
    gotoxy(5, 10);  cout<<"rentadas como m"<<char(160)<<"ximo.";
    gotoxy(5, 12);  cout<<"2: Recibir"<<char(160)<<"s un descuento";
    gotoxy(5, 13);  cout<<"del 10% en tus compras.";
    gotoxy(5, 15);  cout<<"3: Tickets a estrenos en el";
    gotoxy(5, 16);  cout<<"cine durante festividades.";
    gotoxy(5, 23);  cout<<"Para volver al men"<<char(163)<<" anterior, presiona <ESC>.";
    // Renderizado de botones
    gotoxy(5, 18);  cout<<"===============";
    gotoxy(5, 19);  cout<<"|| AFILIARME ||";
    gotoxy(5, 20);  cout<<"===============";

    gotoxy(22,18);  cout<<"------------";
    gotoxy(22,19);  cout<<"|  REGLAS  |";
    gotoxy(22,20);  cout<<"------------";
    // Mover cursor al botón default (CREAR CUENTA)
    gotoxy(8, 19);
  } else if(menu.compare("2.4_catalogo_f1")  == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(28,2);   cout<<"CATALOGO DE PELICULAS";
    gotoxy(5, 5);   cout<<"En este men"<<char(163)<<" podr"<<char(160)<<"s consultar";
    gotoxy(35,5);   cout<<"todas las peliculas que tenemos y podr"<<char(160)<<"s";
    gotoxy(5, 6);   cout<<"comprar o rentarlas desde aqu"<<char(161);
    gotoxy(35,6);   cout<<". Desplaz"<<char(160)<<"te utilizando las teclas de";
    gotoxy(5, 7);   cout<<"direcci"<<char(162)<<"n y presiona <ENTER>";
    gotoxy(34,7);   cout<<"cuando quieras consultar esa categor"<<char(161)<<"a.";
    gotoxy(5, 23);  cout<<"Para volver al men"<<char(163)<<" anterior, presiona <ESC>.";
    // Renderizado de botones
    gotoxy(5, 10);  cout<<"============";
    gotoxy(5, 11);  cout<<"|| HORROR ||";
    gotoxy(5, 12);  cout<<"============";
    gotoxy(19,10);  cout<<"------------";
    gotoxy(19,11);  cout<<"|  SCI-FI  |";
    gotoxy(19,12);  cout<<"------------";
    gotoxy(33,10);  cout<<"-----------";
    gotoxy(33,11);  cout<<"|  DRAMA  |";
    gotoxy(33,12);  cout<<"-----------";
    gotoxy(46,10);  cout<<"--------------";
    gotoxy(46,11);  cout<<"|  AVENTURA  |";
    gotoxy(46,12);  cout<<"--------------";
    gotoxy(62,10);  cout<<"------------";
    gotoxy(62,11);  cout<<"|  ACCION  |";
    gotoxy(62,12);  cout<<"------------";
    gotoxy(9, 14);  cout<<"--------------";
    gotoxy(9, 15);  cout<<"|  BIOGRAFIA |";
    gotoxy(9, 16);  cout<<"--------------";
    gotoxy(25,14);  cout<<"-------------";
    gotoxy(25,15);  cout<<"|  COMEDIA  |";
    gotoxy(25,16);  cout<<"-------------";
    gotoxy(40,14);  cout<<"-------------";
    gotoxy(40,15);  cout<<"|  ROMANCE  |";
    gotoxy(40,16);  cout<<"-------------";
    gotoxy(55,14);  cout<<"---------------";
    gotoxy(55,15);  cout<<"|  DOCUMENTAL |";
    gotoxy(55,16);  cout<<"---------------";
    gotoxy(25,18);  cout<<"--------------";
    gotoxy(25,19);  cout<<"|  ESTRENOS  |";
    gotoxy(25,20);  cout<<"--------------";
    gotoxy(41,18);  cout<<"---------------";
    gotoxy(41,19);  cout<<"|  EN REMATE  |";
    gotoxy(41,20);  cout<<"---------------";
    // Mover cursor al botón default (CREAR CUENTA)
    gotoxy(8, 11);
  } else if (menu.compare("2.4_catalogo_f2")  == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(31,2);   cout<<"CATALOGO:";
    gotoxy(4, 4);   cout<<">";
    gotoxy(57,4);   cout<<"Precio:";
    gotoxy(57,6);   cout<<"Duraci"<<char(162)<<"n:";
    gotoxy(57,8);   cout<<"G"<<char(130)<<"nero:";
    gotoxy(57,10);  cout<<"Disponibilidad:";
    gotoxy(57,12);  cout<<"A"<<char(164)<<"o:";
    gotoxy(69,12);  cout<<"ID:";
    gotoxy(4, 16);  cout<<"|||||  Utilice las teclas <ARRIBA> y <ABAJO>   |||||";
    gotoxy(63,16);  cout<<"Sinopsis";
    gotoxy(5, 23);  cout<<"Para volver al men"<<char(163)<<" anterior, presiona <ESC>.";
    // Renderlizado de líneas
    for(int x=4; x<=55;x++)    { gotoxy(x, 15);  cout<<"_"; }
    for(int x=4; x<=59;x++)    { gotoxy(x, 17);  cout<<"_"; }
    for(int x=60;x<=74;x++)    { gotoxy(x, 15);  cout<<"_"; }
    for(int x=75;x<=76;x++)    { gotoxy(x, 17);  cout<<"_"; }
    for(int y=4; y<=17;y++)    { gotoxy(56,y);   cout<<"|"; }
    for(int y=16;y<=17;y++)    { gotoxy(60,y);   cout<<"|"; }
    for(int y=16;y<=17;y++)    { gotoxy(74,y);   cout<<"|"; }
    // Mover cursor al input default (Película a buscar)
    gotoxy(4, 4);
  } else { // Default o error
    system("cls");
    cout << "Error al llamar la funcion dibujarMenu" << endl;
  } // Fin de dibujar menú indicado
} // Fin de mostrar menu principal

void seleccionarBoton(string menu, int btn) {
  if (menu.compare("1_principal")  == 0) {
    if (btn == 1) {
      gotoxy(22, 13);  cout << "==================";
      gotoxy(22, 14);  cout << "|| CREAR CUENTA ||";
      gotoxy(22, 15);  cout << "==================";

      gotoxy(41, 13);  cout << "--------------";
      gotoxy(41, 14);  cout << "|  INGRESAR  |";
      gotoxy(41, 15);  cout << "--------------";
    } else if (btn == 2) {
      gotoxy(22, 13);  cout << "------------------";
      gotoxy(22, 14);  cout << "|  CREAR CUENTA  |";
      gotoxy(22, 15);  cout << "------------------";

      gotoxy(41, 13);  cout << "==============";
      gotoxy(41, 14);  cout << "|| INGRESAR ||";
      gotoxy(41, 15);  cout << "==============";
    }
  }
} // Fin de seleccionar botones

void focusInput() {
  //
} // Fin de hacer focus en input de texto

void intro(int velocidad) {
  // Colorear pantalla azul y letra amarilla
  system("cls"); system("color 16");

  // Fotograma 1 - BLO
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

  // Fotograma 2 - LOC
  cout<<"\n\n\n\n";
  cout<<"\tLLLLLLLLLLL                  OOOOOOOOO             CCCCCCCCCCCCC"<<endl;
  cout<<"\tL:::::::::L                OO:::::::::OO        CCC::::::::::::C"<<endl;
  cout<<"\tL:::::::::L              OO:::::::::::::OO    CC:::::::::::::::C"<<endl;
  cout<<"\tLL:::::::LL             O:::::::OOO:::::::O  C:::::CCCCCCCC::::C"<<endl;
  cout<<"\t  L:::::L               O::::::O   O::::::O C:::::C       CCCCCC"<<endl;
  cout<<"\t  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  L:::::L               O:::::O     O:::::OC:::::C              "<<endl;
  cout<<"\t  L:::::L         LLLLLLO::::::O   O::::::O C:::::C       CCCCCC"<<endl;
  cout<<"\tLL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::O  C:::::CCCCCCCC::::C"<<endl;
  cout<<"\tL::::::::::::::::::::::L OO:::::::::::::OO    CC:::::::::::::::C"<<endl;
  cout<<"\tL::::::::::::::::::::::L   OO:::::::::OO        CCC::::::::::::C"<<endl;
  cout<<"\tLLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO             CCCCCCCCCCCCC"<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 3 - OCK
  cout<<"\n\n\n\n";
  cout<<"\t     OOOOOOOOO             CCCCCCCCCCCCCKKKKKKKKK    KKKKKKK"<<endl;
  cout<<"\t   OO:::::::::OO        CCC::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\t OO:::::::::::::OO    CC:::::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\tO:::::::OOO:::::::O  C:::::CCCCCCCC::::CK:::::::K   K::::::K"<<endl;
  cout<<"\tO::::::O   O::::::O C:::::C       CCCCCCKK::::::K  K:::::KKK"<<endl;
  cout<<"\tO:::::O     O:::::OC:::::C                K:::::K K:::::K   "<<endl;
  cout<<"\tO:::::O     O:::::OC:::::C                K::::::K:::::K    "<<endl;
  cout<<"\tO:::::O     O:::::OC:::::C                K:::::::::::K     "<<endl;
  cout<<"\tO:::::O     O:::::OC:::::C                K:::::::::::K     "<<endl;
  cout<<"\tO:::::O     O:::::OC:::::C                K::::::K:::::K    "<<endl;
  cout<<"\tO:::::O     O:::::OC:::::C                K:::::K K:::::K   "<<endl;
  cout<<"\tO::::::O   O::::::O C:::::C       CCCCCCKK::::::K  K:::::KKK"<<endl;
  cout<<"\tO:::::::OOO:::::::O  C:::::CCCCCCCC::::CK:::::::K   K::::::K"<<endl;
  cout<<"\t OO:::::::::::::OO    CC:::::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\t   OO:::::::::OO        CCC::::::::::::CK:::::::K    K:::::K"<<endl;
  cout<<"\t     OOOOOOOOO             CCCCCCCCCCCCCKKKKKKKKK    KKKKKKK"<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 4 - CKB
  cout<<"\n\n\n\n";
  cout<<"\t        CCCCCCCCCCCCCKKKKKKKKK    KKKKKKKBBBBBBBBBBBBBBBBB   "<<endl;
  cout<<"\t     CCC::::::::::::CK:::::::K    K:::::KB::::::::::::::::B  "<<endl;
  cout<<"\t   CC:::::::::::::::CK:::::::K    K:::::KB::::::BBBBBB:::::B "<<endl;
  cout<<"\t  C:::::CCCCCCCC::::CK:::::::K   K::::::KBB:::::B     B:::::B"<<endl;
  cout<<"\t C:::::C       CCCCCCKK::::::K  K:::::KKK  B::::B     B:::::B"<<endl;
  cout<<"\tC:::::C                K:::::K K:::::K     B::::B     B:::::B"<<endl;
  cout<<"\tC:::::C                K::::::K:::::K      B::::BBBBBB:::::B "<<endl;
  cout<<"\tC:::::C                K:::::::::::K       B:::::::::::::BB  "<<endl;
  cout<<"\tC:::::C                K:::::::::::K       B::::BBBBBB:::::B "<<endl;
  cout<<"\tC:::::C                K::::::K:::::K      B::::B     B:::::B"<<endl;
  cout<<"\tC:::::C                K:::::K K:::::K     B::::B     B:::::B"<<endl;
  cout<<"\t C:::::C       CCCCCCKK::::::K  K:::::KKK  B::::B     B:::::B"<<endl;
  cout<<"\t  C:::::CCCCCCCC::::CK:::::::K   K::::::KBB:::::BBBBBB::::::B"<<endl;
  cout<<"\t   CC:::::::::::::::CK:::::::K    K:::::KB:::::::::::::::::B "<<endl;
  cout<<"\t     CCC::::::::::::CK:::::::K    K:::::KB::::::::::::::::B  "<<endl;
  cout<<"\t        CCCCCCCCCCCCCKKKKKKKKK    KKKKKKKBBBBBBBBBBBBBBBBB   "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 5 - KBU
  cout<<"\n\n\n\n";
  cout<<"\tKKKKKKKKK    KKKKKKKBBBBBBBBBBBBBBBBB   UUUUUUUU     UUUUUUUU"<<endl;
  cout<<"\tK:::::::K    K:::::KB::::::::::::::::B  U::::::U     U::::::U"<<endl;
  cout<<"\tK:::::::K    K:::::KB::::::BBBBBB:::::B U::::::U     U::::::U"<<endl;
  cout<<"\tK:::::::K   K::::::KBB:::::B     B:::::BUU:::::U     U:::::UU"<<endl;
  cout<<"\tKK::::::K  K:::::KKK  B::::B     B:::::B U:::::U     U:::::U "<<endl;
  cout<<"\t  K:::::K K:::::K     B::::B     B:::::B U:::::D     D:::::U "<<endl;
  cout<<"\t  K::::::K:::::K      B::::BBBBBB:::::B  U:::::D     D:::::U "<<endl;
  cout<<"\t  K:::::::::::K       B:::::::::::::BB   U:::::D     D:::::U "<<endl;
  cout<<"\t  K:::::::::::K       B::::BBBBBB:::::B  U:::::D     D:::::U "<<endl;
  cout<<"\t  K::::::K:::::K      B::::B     B:::::B U:::::D     D:::::U "<<endl;
  cout<<"\t  K:::::K K:::::K     B::::B     B:::::B U:::::D     D:::::U "<<endl;
  cout<<"\tKK::::::K  K:::::KKK  B::::B     B:::::B U::::::U   U::::::U "<<endl;
  cout<<"\tK:::::::K   K::::::KBB:::::BBBBBB::::::B U:::::::UUU:::::::U "<<endl;
  cout<<"\tK:::::::K    K:::::KB:::::::::::::::::B   UU:::::::::::::UU  "<<endl;
  cout<<"\tK:::::::K    K:::::KB::::::::::::::::B      UU:::::::::UU    "<<endl;
  cout<<"\tKKKKKKKKK    KKKKKKKBBBBBBBBBBBBBBBBB         UUUUUUUUU      "<<endl;
  Sleep(velocidad); system("cls");
  
  // Fotograma 6 - BUS
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

  // Fotograma 7 - UST
  cout<<"\n\n\n\n";
  cout<<"\tUUUUUUUU     UUUUUUUU   SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTT"<<endl;
  cout<<"\tU::::::U     U::::::U SS:::::::::::::::ST:::::::::::::::::::::T"<<endl;
  cout<<"\tU::::::U     U::::::US:::::SSSSSS::::::ST:::::::::::::::::::::T"<<endl;
  cout<<"\tUU:::::U     U:::::UUS:::::S     SSSSSSST:::::TT:::::::TT:::::T"<<endl;
  cout<<"\t U:::::U     U:::::U S:::::S            TTTTTT  T:::::T  TTTTTT"<<endl;
  cout<<"\t U:::::D     D:::::U S:::::S                    T:::::T        "<<endl;
  cout<<"\t U:::::D     D:::::U  S::::SSSS                 T:::::T        "<<endl;
  cout<<"\t U:::::D     D:::::U   SS::::::SSSSS            T:::::T        "<<endl;
  cout<<"\t U:::::D     D:::::U     SSS::::::::SS          T:::::T        "<<endl;
  cout<<"\t U:::::D     D:::::U        SSSSSS::::S         T:::::T        "<<endl;
  cout<<"\t U:::::D     D:::::U             S:::::S        T:::::T        "<<endl;
  cout<<"\t U::::::U   U::::::U             S:::::S        T:::::T        "<<endl;
  cout<<"\t U:::::::UUU:::::::U SSSSSSS     S:::::S      TT:::::::TT      "<<endl;
  cout<<"\t  UU:::::::::::::UU  S::::::SSSSSS:::::S      T:::::::::T      "<<endl;
  cout<<"\t    UU:::::::::UU    S:::::::::::::::SS       T:::::::::T      "<<endl;
  cout<<"\t      UUUUUUUUU       SSSSSSSSSSSSSSS         TTTTTTTTTTT      "<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 8 - STE
  cout<<"\n\n\n\n";
  cout<<"\t   SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEE"<<endl;
  cout<<"\t SS:::::::::::::::ST:::::::::::::::::::::TE::::::::::::::::::::E"<<endl;
  cout<<"\tS:::::SSSSSS::::::ST:::::::::::::::::::::TE::::::::::::::::::::E"<<endl;
  cout<<"\tS:::::S     SSSSSSST:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::E"<<endl;
  cout<<"\tS:::::S            TTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE"<<endl;
  cout<<"\tS:::::S                    T:::::T          E:::::E             "<<endl;
  cout<<"\t S::::SSSS                 T:::::T          E::::::EEEEEEEEEE   "<<endl;
  cout<<"\t  SS::::::SSSSS            T:::::T          E:::::::::::::::E   "<<endl;
  cout<<"\t    SSS::::::::SS          T:::::T          E:::::::::::::::E   "<<endl;
  cout<<"\t       SSSSSS::::S         T:::::T          E::::::EEEEEEEEEE   "<<endl;
  cout<<"\t            S:::::S        T:::::T          E:::::E             "<<endl;
  cout<<"\t            S:::::S        T:::::T          E:::::E       EEEEEE"<<endl;
  cout<<"\tSSSSSSS     S:::::S      TT:::::::TT      EE::::::EEEEEEEE:::::E"<<endl;
  cout<<"\tS::::::SSSSSS:::::S      T:::::::::T      E::::::::::::::::::::E"<<endl;
  cout<<"\tS:::::::::::::::SS       T:::::::::T      E::::::::::::::::::::E"<<endl;
  cout<<"\t SSSSSSSSSSSSSSS         TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEE"<<endl;
  Sleep(velocidad); system("cls");

  // Fotograma 9 - TER
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

void despedida() {
  // Crédito: http://www.asciiworld.com/
  system("cls"); system("color 0F");
  cout <<".     .       .  .   . .   .   . .    +  ."<< endl;
  cout <<"  .     .  :     .    .. :. .___---------___."<< endl;
  cout <<"       .  .   .    .  :.:. _\".^ .^ ^.  '.. :\"-_. ."<< endl;
  cout <<"    .  :       .  .  .:../:            . .^  :.:\\."<< endl;
  cout <<"        .   . :: +. :.:/: .   .    .        . . .:\\"<< endl;
  cout <<" .  :    .     . _ :::/:               .  ^ .  . .:\\"<< endl;
  cout <<"  .. . .   . - : :.:./.                        .  .:\\"<< endl;
  cout <<"  .      .     . :..|:                    .  .  ^. .:|"<< endl;
  cout <<"    .       . : : ..||        .                . . !:|"<< endl;
  cout <<"  .     . . . ::. ::\\(                           . :)/"<< endl;
  cout <<" .   .     : . : .:.|. ######              .#######::|"<< endl;
  cout <<"  :.. .  :-  : .:  ::|.#######           ..########:|"<< endl;
  cout <<" .  .  .  ..  .  .. :\\ ########          :######## :/"<< endl;
  cout <<"  .        .+ :: : -.:\\ ########       . ########.:/"<< endl;
  cout <<"    .  .+   . . . . :.:\\. #######       #######..:/"<< endl;
  cout <<"      :: . . . . ::.:..:.\\           .   .   ..:/"<< endl;
  cout <<"   .   .   .  .. :  -::::.\\.       | |     . .:/"<< endl;
  cout <<"      .  :  .  .  .-:.\":.::.\\             ..:/"<< endl;
  cout <<" .      -.   . . . .: .:::.:.\\.           .:/"<< endl;
  cout <<".   .   .  :      : ....::_:..:\\   ___.  :/"<< endl;
  cout <<"   .   .  .   .:. .. .  .: :.:.:\\       :/"<< endl;
  cout <<"     +   .   .   : . ::. :.:. .:.|\\  .:/|"<< endl;
  cout <<"     .         +   .  .  ...:: ..|  --.:|"<< endl;
  cout <<".      . . .   .  .  . ... :..:..\"(  ..)\""<< endl;
  cout <<" .   .       .      :  .   .: ::/  .  .::\\"<< endl;
  Sleep(2000);
} // Fin de ticket de despedida