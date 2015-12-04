/*========================================================
    Renderizado de texto, marcos, ASCII Art y
    animaciones para la ventana de consola.
========================================================*/
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
    gotoxy(26,19);   cout<<"Presione <ESC> para salir.";
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
    // ASCII Art 'Millenial Falcon' -> http://www.chris.com/ascii/
    gotoxy(28,5);  cout<<"                c==o"                         ;
    gotoxy(28,6);  cout<<"              _/____\\_"                      ;
    gotoxy(28,7);  cout<<"       _.,--'\" ||^ || \"`z._"                ;
    gotoxy(28,8);  cout<<"      /_/^ ___\\||  || _/o\\ \"`-._"          ;
    gotoxy(28,9);  cout<<"    _/  ]. L_| || .||  \\_/_  . _`--._"       ;
    gotoxy(28,10); cout<<"   /_~7  _ . \" ||. || /] \\ ]. (_)  . \"`--.";
    gotoxy(28,11); cout<<"  |__7~.(_)_ []|+--+|/____T_____________L|"   ;
    gotoxy(28,12); cout<<"  |__|  _^(_) /^   __\\____ _   _|"           ;
    gotoxy(28,13); cout<<"  |__| (_){_) J ]K{__ L___ _   _]"            ;
    gotoxy(28,14); cout<<"  |__| . _(_) \v     /__________|________"    ;
    gotoxy(28,15); cout<<"  l__l_ (_). []|+-+-<\\^   L  . _   - ---L|"  ;
    gotoxy(28,16); cout<<"   \\__\\    __. ||^l  \\Y] /_]  (_) .  _,--'";
    gotoxy(28,17); cout<<"     \\~_]  L_| || .\\ .\\/~.    _,--'\""     ;
    gotoxy(28,18); cout<<"      \\_\\ . __/||  |\\  \\`-+-<'\""         ;
    gotoxy(28,19); cout<<"        \"`---._|J__L|X o~~|[\\"              ;
    gotoxy(28,20); cout<<"               \\____/ \\___|[//"             ;
    gotoxy(28,21); cout<<"                `--'   `--+-'"                ;
    // Renderizado de texto
    gotoxy(18,2);   cout << "BLOCKBUSTER: VENTA Y RENTA DE PELICULAS";
    gotoxy(5, 5);   cout << "Que es lo que deseas hacer?";
    gotoxy(5, 7);   cout << "Menu:";
    gotoxy(5, 9);   cout << "1.- Rentar peliculas";
    gotoxy(5, 11);  cout << "2.- Comprar peliculas";
    gotoxy(5, 13);  cout << "3.- Membresias";
    gotoxy(5, 15);  cout << "4.- Catalogo";
    gotoxy(5, 17);  cout << "5.- Credito";
    gotoxy(5, 19);  cout << "6.- Salir";
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
    gotoxy(35,2);   cout<<"MEMBRES"<<char(161)<<"AS";
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
    // Dibujo de ASCII Art 'Totoro' -> http://www.asciiworld.com/-Mangas,48-.html
    gotoxy(40,8);   cout<<"           !         !          "       ;
    gotoxy(40,9);   cout<<"          ! !       ! !          "      ;
    gotoxy(40,10);  cout<<"         ! . !     ! . !          "     ;
    gotoxy(40,11);  cout<<"            ^^^^^^^^^ ^            "    ;
    gotoxy(40,12);  cout<<"          ^             ^          "    ;
    gotoxy(40,13);  cout<<"        ^  (0)       (0)  ^       "     ;
    gotoxy(40,14);  cout<<"       ^        \"\"         ^       "  ;
    gotoxy(40,15);  cout<<"      ^   ***************    ^     "    ;
    gotoxy(40,16);  cout<<"    ^   *                 *   ^    "    ;
    gotoxy(40,17);  cout<<"   ^   *   /\\   /\\   /\\    *    ^   ";
    gotoxy(40,18);  cout<<"  ^   *                     *    ^"     ;
    gotoxy(40,19);  cout<<" ^   *   /\\   /\\   /\\   /\\   *    ^";
    gotoxy(40,20);  cout<<"^   *                         *    ^"   ;
    gotoxy(40,21);  cout<<"^  *                           *   ^"   ;
    // Renderizado de botones
    gotoxy(5, 18);  cout<<"===============";
    gotoxy(5, 19);  cout<<"|| AFILIARME ||";
    gotoxy(5, 20);  cout<<"===============";

    gotoxy(22,18);  cout<<"------------";
    gotoxy(22,19);  cout<<"|  REGLAS  |";
    gotoxy(22,20);  cout<<"------------";
    // Mover cursor al botón default (AFILIARME)
    gotoxy(8, 19);
  } else if(menu.compare("2.3_membresias_reglas")  == 0) {
    system("cls"); dibujarBordes();
    // Totoro por segunda vez, pero más arriba
    gotoxy(40,4);  cout<<"           !         !          "       ;
    gotoxy(40,5);  cout<<"          ! !       ! !          "      ;
    gotoxy(40,6);  cout<<"         ! . !     ! . !          "     ;
    gotoxy(40,7);  cout<<"            ^^^^^^^^^ ^            "    ;
    gotoxy(40,8);  cout<<"          ^             ^          "    ;
    gotoxy(40,9);  cout<<"        ^  (0)       (0)  ^       "     ;
    gotoxy(40,10); cout<<"       ^        \"\"         ^       "  ;
    gotoxy(40,11); cout<<"      ^   ***************    ^     "    ;
    gotoxy(40,12); cout<<"    ^   *                 *   ^    "    ;
    gotoxy(40,13); cout<<"   ^   *   /\\   /\\   /\\    *    ^   ";
    gotoxy(40,14); cout<<"  ^   *                     *    ^"     ;
    gotoxy(40,15); cout<<" ^   *   /\\   /\\   /\\   /\\   *    ^";
    gotoxy(40,16); cout<<"^   *                         *    ^"   ;
    gotoxy(40,17); cout<<"^  *                           *   ^"   ;
    gotoxy(40,18); cout<<"^  *                           *   ^"   ;
    gotoxy(40,19); cout<<" ^ *                           *  ^  "  ;
    gotoxy(40,20); cout<<"  ^*                           * ^ "    ;
    gotoxy(40,21); cout<<"   ^ *                        * ^"      ;
    // Renderizado de texto
    gotoxy(31,2);   cout<<"MEMBRESIAS: REGLAS";
    gotoxy(5, 5);   cout<<"1-Devolver las peliculas rentadas";
    gotoxy(7, 6);   cout<<"en tiempo y forma.";
    gotoxy(5, 8);   cout<<"2-Por cada dia de retraso se";
    gotoxy(7, 9);   cout<<"te descontara de tu credito.";
    gotoxy(5,11);   cout<<"3-Una vez que tu membresia expire";
    gotoxy(7,12);   cout<<"tendras que renovarla.";
    gotoxy(5,14);   cout<<"4-Si tienes adeudos o tienes 3";
    gotoxy(7,15);   cout<<"peliculas (limite de renta)";
    gotoxy(7,16);   cout<<"rentadas no podras rentar.";
    // Renderizado de botones
    gotoxy(13,18);  cout<<"===============";
    gotoxy(13,19);  cout<<"|| ENTENDIDO ||";
    gotoxy(13,20);  cout<<"===============";
    // Mover cursor al botón default (AFILIARME)
    gotoxy(16,19);
  } else if(menu.compare("2.3_membresias_afil")  == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de líneas
    gotoxy(6, 9);   cout << ".==============.";
    gotoxy(4,11);   cout << "__"; gotoxy(6,10);   cout << "||";
    gotoxy(6,11);   cout << "||"; gotoxy(20,10);  cout << "||";
    gotoxy(20,11);  cout << "||"; gotoxy(36,10);  cout << "|";
    gotoxy(48,10);  cout << "|";
    for(int x=22; x<=48; x++) {   gotoxy(x, 9);   cout <<"_"; }
    for(int x=22; x<=76; x++) {   gotoxy(x, 11);  cout <<"_"; }
    gotoxy(36,11);  cout << "|";  gotoxy(48,11);  cout << "|";
    // Renderizado de texto
    gotoxy(5, 5);   cout<<"La membresia Blockbuster tiene un costo de 250 pesos.";
    gotoxy(5, 6);   cout<<"Si no tienes suficiente dinero no podras afiliarte, sugerimos que";
    gotoxy(5, 7);   cout<<"vayas al menu 'credito' para agregar mas fondos a tu cuenta.";
    gotoxy(31,2);   cout<<"MEMBRESIAS: AFILIARSE";
    gotoxy(9, 10);  cout<<"EXPIRACION";
    gotoxy(23,10);  cout<<"INFORMACION";
    gotoxy(38,10);  cout<<"CONTRATO";
    gotoxy(19,14);  cout<<"Tu membresia durara seis meses y expirara el:";
    gotoxy(27,16);  cout<<"[  ] de [          ] del [    ]";
    // Renderizado de botones
    gotoxy(34,18);  cout<<"===============";
    gotoxy(34,19);  cout<<"|| ENTENDIDO ||";
    gotoxy(34,20);  cout<<"===============";
    // Mover cursor al botón default (AFILIARME)
    gotoxy(37,19);
  } else if(menu.compare("2.3_membresias_ctrl") == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(31,2);   cout<<"MEMBRES"<<char(161)<<"AS: DETALLES ";
    gotoxy(5, 5);   cout<<"Bienvenid@ seas, a continuaci"<<char(162)<<
    "n se muestran   los detalles de tu ";
    gotoxy(5, 6);   cout<<"membres"<<char(161)<<"a, podr"<<char(160)<<
    "s consultar tus rentas, adeudos, d"<<char(161)<<"as restantes, etc.";
    gotoxy(5, 8);   cout<<"Hola,                         Pel"<<
    char(161)<<"cula rentada #1 ";
    gotoxy(5,10);   cout<<"Le quedan [   ] d"<<char(161)<<"as a tu     -----------------------------------------";
    gotoxy(5,11);   cout<<"suscripci"<<char(162)<<"n. Puedes renovar ";
    gotoxy(5,12);   cout<<"cuantas veces quieras a un ";
    gotoxy(5,13);   cout<<"costo de $250 pesos.          Pel"<<char(161)<<"cula rentada #2";
    gotoxy(5,23);   cout<<"Para volver al men"<<char(163)<<" anterior, presiona <ESC>.";
    // Renderizado de botones
    gotoxy(5,15);   cout<<"========================      "<<"----------------------------------------- ";
    gotoxy(5,16);   cout<<"|| DEVOLVER PEL"<<char(161)<<"CULAS ||";
    gotoxy(5,17);   cout<<"========================";
    gotoxy(35,18);  cout<<"Pel"<<char(161)<<"cula rentada #3";
    gotoxy(5,19);   cout<<"----------  -------------";
    gotoxy(5,20);   cout<<"|  BAJA  |  |  RENOVAR  |     "<<"----------------------------------------- ";
    gotoxy(5,21);   cout<<"----------  -------------";
    // Colocar el puntero en el botón 'Devolver'
    gotoxy(8,16);
  } else if(menu.compare("2.3_membresias_devol")  == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(29,2);   cout<<"MEMBRES"<<char(161)<<"AS: DEVOLUCI"<<char(162)<<"N";
    gotoxy(5,5);    cout<<"Si est"<<char(160)<<"s devolviendo pel"<<
    char(161)<<"culas por atraso, tendr"<<char(160)<<"s que primero ir";
    gotoxy(5,6);    cout<<"al men"<<char(163)<<" de 'Cr"<<char(130)<<
    "dito' y cubrir el saldo negativo (adeudo) abonando ";
    gotoxy(5,7);    cout<<"a tu cuenta el equivalente del adeudo.";
    gotoxy(5,9);    cout<<"Marca las pel"<<char(161)<<
    "culas que deseas devolver presionando <ENTER>: ";
    gotoxy(5,23);   cout<<"Utiliza las teclas direccionales para moverte.";
    // Renderizado de botones
    gotoxy(56,11);  cout<<"--------------";
    gotoxy(56,12);  cout<<"|  DEVOLVER  |";
    gotoxy(56,13);  cout<<"--------------";
    gotoxy(56,15);  cout<<"--------------";
    gotoxy(56,16);  cout<<"|  CANCELAR  |";
    gotoxy(56,17);  cout<<"--------------";
    // Enfocar el botón default 'Devolver'
    gotoxy(6, 12);
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
    gotoxy(57,4);   cout<<"Precio: $";
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
  } else if (menu.compare("2.5_credito")  == 0) {
    system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(35,2);   cout<<"$ CR"<<char(144)<<"DITO $ ";
    gotoxy(5,5);    cout<<"Desde aqu"<<char(161)<<" podr"<<char(160)
    <<"s consultar el cr"<<char(130)<<"dito con el que dispones. ";
    gotoxy(5,6);    cout<<"Si te acabas de registrar, tendr"<<char(160)
    <<"s $0 y necesitar"<<char(160)<<"s agregar dinero ";
    gotoxy(5,7);    cout<<"a tu cuenta. Sin cr"<<char(130)<<"dito no podr"
    <<char(160)<<"s comprar pel"<<char(161)<<"culas. ";
    gotoxy(5,9);    cout<<"Usuario: ";
    gotoxy(5,14);   cout<<"Balance: ";
    gotoxy(5,20);   cout<<"L"<<char(161)<<"mite: $9999.00";
    gotoxy(5,23);   cout<<"Un saldo negativo significa adeudo"<<
    ", abona para eliminarlo.";
    // ASCII Art Dados http://www.chris.com/ascii/index.php?art=objects/dice
    gotoxy(32,14);  cout<<"   _______             _______          ";
    gotoxy(32,15);  cout<<"  /\\ o o o\\           /\\ o o o\\         ";
    gotoxy(32,16);  cout<<" /o \\ o o o\\_______  /o \\ o o o\\_______ ";
    gotoxy(32,17);  cout<<"*    *------*   o /|*    *------*   o /|";
    gotoxy(32,18);  cout<<" \\ o/  o   /_____/o| \\ o/  o   /_____/o|";
    gotoxy(32,19);  cout<<"  \\/______/     |oo|  \\/______/     |oo|";
    gotoxy(32,20);  cout<<"        |   o   |o/         |   o   |o/ ";
    gotoxy(32,21);  cout<<"        |_______|/          |_______|/  ";
    // Renderizado de botones y recuadros
    gotoxy(5,10);   cout<<"*------------------*";
    gotoxy(5,11);   cout<<"|                  |";
    gotoxy(5,12);   cout<<"*------------------*";
    gotoxy(5,15);   cout<<"*-----------*";
    gotoxy(5,16);   cout<<"|$          |";
    gotoxy(5,17);   cout<<"*-----------*";
    gotoxy(36,9);   cout<<"============  ------------------";
    gotoxy(36,10);  cout<<"|| ABONAR ||  |  VOLVER ATRAS  |";
    gotoxy(36,11);  cout<<"============  ------------------";
  } else if (menu.compare("2.5_credito_f2")  == 0) {
     system("cls"); dibujarBordes();
    // Renderizado de texto
    gotoxy(35,2);  cout<<"$ CR"<<char(144)<<"DITO $ ";
    gotoxy(5, 5);  cout<<"Desde aqu"<<char(161)<<" podr"<<char(160)<<
    "s consultar el cr"<<char(130)<<"dito con el que dispones. ";
    gotoxy(5, 6);  cout<<"Si te acabas de registrar, tendr"<<char(160)<<
    "s $0 y necesitar"<<char(160)<<"s agregar dinero ";
    gotoxy(5, 7);  cout<<"a tu cuenta. Sin cr"<<char(130)<<"dito no podr"<<
    char(160)<<"s comprar pel"<<char(161)<<"culas. ";
    gotoxy(5, 9);  cout<<"Usuario: ";
    gotoxy(5,14);  cout<<"Balance: ";
    gotoxy(5,20);  cout<<"L"<<char(161)<<"mite: $9999.0";
    gotoxy(36,9);  cout<<"Monto abonado:";
    gotoxy(36,10); cout<<"$";
    gotoxy(5,23);  cout<<"Utiliza las teclas direccionales para moverte.";
    // Renderizado de recuadros
    gotoxy(5,15);  cout<<"*-----------*";
    gotoxy(5,16);  cout<<"|$          |";
    gotoxy(5,17);  cout<<"*-----------*";
    gotoxy(5,10);  cout<<"*------------------*";
    gotoxy(5,11);  cout<<"|                  | ";
    gotoxy(5,12);  cout<<"*------------------*";
    gotoxy(36,11); cout<<"--------------";
    gotoxy(36,13); cout<<"---";
    gotoxy(36,14); cout<<"| | Abonar a otra persona";
    gotoxy(36,15); cout<<"---";
    // Renderizado de botones
    gotoxy(36,17); cout<<"------------  --------------";
    gotoxy(36,18); cout<<"|  ABONAR  |  |  CANCELAR  |";
    gotoxy(36,19); cout<<"------------  --------------";
  } else if (menu.compare("3_empleados")  == 0) {
    system("cls");
    cout << "Menu de empleados!" << endl;
  } else { // Default o error
    system("cls");
    cout << "Error al llamar la funcion dibujarMenu" << endl;
  } // Fin de dibujar menú indicado
} // Fin de mostrar menu principal

void limpiarZona(string menu, int zona) {
  if (menu.compare("2.4_catalogo_f2") == 0) {
    switch(zona) {
      case 0: // Lista de películas
        for(int x=4, y=4; y<=14; y+=1) {
          gotoxy(x,y);
          cout << "                          "
               << "                          ";
        } // Fin de llenar con espacio blanco
      break;

      case 1: // Área de punteros '>'
        for(int x=4, y=4; y<=14; y+=1) {
          gotoxy(x,y); cout << " ";
        } // Fin de llenar con espacio blanco
      break;

      case 2: // Detalles y sinopsis de película
        gotoxy(66, 4); cout << "      ";        // Precio
        gotoxy(67, 6); cout << "       ";       // Duración
        gotoxy(65, 8); cout << "            ";  // Género
        gotoxy(73,10); cout << "   ";           // Stock
        gotoxy(62,12); cout << "    ";          // Año
        gotoxy(73,12); cout << "   ";           // MovieID
        // Borrar sinopsis
        for(int x=4, y=18; y<=21; y+=1) {
          gotoxy(x,y);
          cout << "                                     "
          <<      "                                    ";
        } // Fin de llenar con espacio blanco
      break;
    } // Fin de detectar zona a limpiar
  } else if (menu.compare("2.3_membresias_afil") == 0) {
    int limiteY;
    switch(zona) {
      case 0: limiteY = 17; break; // Botón intacto
      case 1: limiteY = 21; break; // Se borra hasta el botón
    } // Fin de delimitar borrado
    for(int y = 13, x = 5; y <= limiteY; y+=1) {
      gotoxy(x,y);  cout<<"                                    ";
                    cout<<"                                   ";
    }
  } else if (menu.compare("2.5_credito") == 0) {
    switch(zona) {
      case 0: // Usuario y monto
        gotoxy(6,11); cout << "                  ";
        gotoxy(7,16); cout << "         ";
      break;
    }
  } // Fin de revisar en qué menú trabajar
} // Fin de borrar zonas de contenido

void enfocarElemento(string menu, int elemento) {
  if (menu.compare("1_principal")  == 0) {
    switch(elemento) {
      case 0: // Crear Cuenta
        gotoxy(22,13); cout << "==================";
        gotoxy(22,14); cout << "|| CREAR CUENTA ||";
        gotoxy(22,15); cout << "==================";
        gotoxy(41,13); cout << "--------------";
        gotoxy(41,14); cout << "|  INGRESAR  |";
        gotoxy(41,15); cout << "--------------";
        gotoxy(25,14); break;
      case 1: // Entrar 'Log-In'
        gotoxy(22,13); cout << "------------------";
        gotoxy(22,14); cout << "|  CREAR CUENTA  |";
        gotoxy(22,15); cout << "------------------";
        gotoxy(41,13); cout << "==============";
        gotoxy(41,14); cout << "|| INGRESAR ||";
        gotoxy(41,15); cout << "==============";
        gotoxy(44,14); break;
    }
  } else if (menu.compare("1_principal_login") == 0) {
    switch(elemento) {
      case 0: // Nombre de usuario
        gotoxy(23,12); cout<<"                  ";
        gotoxy(39,15); cout << "------------";
        gotoxy(39,16); cout << "|  ENTRAR  |";
        gotoxy(39,17); cout << "------------";
        gotoxy(23,12); break;
      case 1: // Contraseña
        gotoxy(49,12); cout<<"                  ";
        gotoxy(39,15); cout << "------------";
        gotoxy(39,16); cout << "|  ENTRAR  |";
        gotoxy(39,17); cout << "------------";
        gotoxy(49,12); break;
      case 2: // Botón 'Entrar'
        gotoxy(39,15); cout << "============";
        gotoxy(39,16); cout << "|| ENTRAR ||";
        gotoxy(39,17); cout << "============";
        gotoxy(42,16); break;
    }
  } else if (menu.compare("1_principal_registro") == 0) {
    switch(elemento) {
      case 0: // Nombre de usuario
        gotoxy(23,12); cout<<"                  ";
        gotoxy(57,16); cout << "-----------";
        gotoxy(57,17); cout << "|  LISTO  |";
        gotoxy(57,18); cout << "-----------";
        gotoxy(23,12); break;
      case 1: // Contraseña
        gotoxy(23,17); cout<<"                  ";
        gotoxy(57,16); cout << "-----------";
        gotoxy(57,17); cout << "|  LISTO  |";
        gotoxy(57,18); cout << "-----------";
        gotoxy(23,17); break;
      case 2: // Repetir contraseña
        gotoxy(50,12); cout<<"                  ";
        gotoxy(57,16); cout << "-----------";
        gotoxy(57,17); cout << "|  LISTO  |";
        gotoxy(57,18); cout << "-----------";
        gotoxy(50,12); break;
      case 3: // Botón 'Listo'
        gotoxy(57,16); cout << "===========";
        gotoxy(57,17); cout << "|| LISTO ||";
        gotoxy(57,18); cout << "===========";
        gotoxy(60,17); break;
    }
  } else if (menu.compare("2_clientes") == 0) {
    switch(elemento) {
      case 0: gotoxy(13,23);
        cout << "                                     ";
        gotoxy(13,23); break;
    }
  } else if (menu.compare("2.4_catalogo_f1") == 0) {
    // Volver a renderizar los botones (sin enfoque)
    gotoxy(5, 10);  cout<<"------------";
    gotoxy(5, 11);  cout<<"|  HORROR  |";
    gotoxy(5, 12);  cout<<"------------";
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
    // Enfocar el elemento adecuado
    switch(elemento) {
      case 0:
        gotoxy(5, 10);  cout<<"============";
        gotoxy(5, 11);  cout<<"|| HORROR ||";
        gotoxy(5, 12);  cout<<"============";
        gotoxy(8, 11);  break;
      case 1:
        gotoxy(19,10);  cout<<"============";
        gotoxy(19,11);  cout<<"|| SCI-FI ||";
        gotoxy(19,12);  cout<<"============";
        gotoxy(22,11);  break;
      case 2: 
        gotoxy(33,10);  cout<<"===========";
        gotoxy(33,11);  cout<<"|| DRAMA ||";
        gotoxy(33,12);  cout<<"===========";
        gotoxy(36,11);  break;
      case 3:
        gotoxy(46,10);  cout<<"==============";
        gotoxy(46,11);  cout<<"|| AVENTURA ||";
        gotoxy(46,12);  cout<<"==============";
        gotoxy(49,11);  break;
      case 4:
        gotoxy(62,10);  cout<<"============";
        gotoxy(62,11);  cout<<"|| ACCION ||";
        gotoxy(62,12);  cout<<"============";
        gotoxy(65,11);  break;
      case 5:
        gotoxy(9, 14);  cout<<"==============";
        gotoxy(9, 15);  cout<<"|| BIOGRAFIA||";
        gotoxy(9, 16);  cout<<"==============";
        gotoxy(12,15);  break;
      case 6:
        gotoxy(25,14);  cout<<"=============";
        gotoxy(25,15);  cout<<"|| COMEDIA ||";
        gotoxy(25,16);  cout<<"=============";
        gotoxy(28,15);  break;
      case 7:
        gotoxy(40,14);  cout<<"=============";
        gotoxy(40,15);  cout<<"|| ROMANCE ||";
        gotoxy(40,16);  cout<<"=============";
        gotoxy(43,15);  break;
      case 8:
        gotoxy(55,14);  cout<<"===============";
        gotoxy(55,15);  cout<<"|| DOCUMENTAL||";
        gotoxy(55,16);  cout<<"===============";
        gotoxy(58,15);  break;
      case 9:
        gotoxy(25,18);  cout<<"==============";
        gotoxy(25,19);  cout<<"|| ESTRENOS ||";
        gotoxy(25,20);  cout<<"==============";
        gotoxy(28,19);  break;
      case 10:
        gotoxy(41,18);  cout<<"===============";
        gotoxy(41,19);  cout<<"|| EN REMATE ||";
        gotoxy(41,20);  cout<<"===============";
        gotoxy(44,19);  break;
    }
  } else if (menu.compare("2.3_membresias_nuevo") == 0) {
    switch(elemento) {
      case 0: // Afiliarme
        gotoxy(5, 18);  cout<<"===============";
        gotoxy(5, 19);  cout<<"|| AFILIARME ||";
        gotoxy(5, 20);  cout<<"===============";
        gotoxy(22,18);  cout<<"------------";
        gotoxy(22,19);  cout<<"|  REGLAS  |";
        gotoxy(22,20);  cout<<"------------";
        gotoxy(8,19);   break;
      case 1: // Reglas
        gotoxy(5, 18);  cout<<"---------------";
        gotoxy(5, 19);  cout<<"|  AFILIARME  |";
        gotoxy(5, 20);  cout<<"---------------";
        gotoxy(22,18);  cout<<"============";
        gotoxy(22,19);  cout<<"|| REGLAS ||";
        gotoxy(22,20);  cout<<"============";
        gotoxy(25,19);  break;
    }
  } else if (menu.compare("2.3_membresias_afil") == 0) {
    // Renderizar pestaña activa
    switch(elemento) { // Pestaña
      case 1: // Pestaña de Información
        limpiarZona("2.3_membresias_afil", 0);
        // Re-renderización de pestaña activa
        gotoxy(6,9);   cout<<"______________.===============.____________";
        gotoxy(6,10);  cout<<"|  EXPIRACION || INFORMACION || CONTRATO  |";
        gotoxy(6,11);  cout<<"|_____________||             ||___________|";
        // Renderizado de texto
        gotoxy(19,14); cout<<"Solo podras sacar 3 peliculas rentadas, la";
        gotoxy(19,15); cout<<"renta durara 1 mes incluyendo fines de semana.";
        gotoxy(19,16); cout<<"Tu mismo te podras dar de baja posteriormente.";
        gotoxy(37,19); break;
      case 2: // Pestaña de Contrato
        limpiarZona("2.3_membresias_afil", 1);
        // Re-renderización de pestaña activa
        gotoxy(6,9);   cout<<"_____________________________.============.";
        gotoxy(6,10);  cout<<"|  EXPIRACION  | INFORMACION || CONTRATO ||";
        gotoxy(6,11);  cout<<"|______________|_____________||          ||";
        // Renderizado de texto
        gotoxy(19,14); cout<<"-Acepto que se me sustraigan $5 pesos por cada dia";
        gotoxy(19,15); cout<<" de atraso en mis rentas.";
        gotoxy(19,16); cout<<"-Entiendo que debo cubrir cualquier adeudo negativo.";
        // Renderizado de botones
        gotoxy(28,18); cout<<"===============  --------------";
        gotoxy(28,19); cout<<"|| AFILIARME ||  |  CANCELAR  |";
        gotoxy(28,20); cout<<"===============  --------------";
        // Enfocar el botón 'Afiliarme'
        gotoxy(31,19); break;
      case 3: // Botón de 'Afiliarme'
        gotoxy(28,18); cout<<"===============  --------------";
        gotoxy(28,19); cout<<"|| AFILIARME ||  |  CANCELAR  |";
        gotoxy(28,20); cout<<"===============  --------------";
        gotoxy(31,19); break;
      case 4: // Botón de 'Cancelar'
        gotoxy(28,18); cout<<"---------------  ==============";
        gotoxy(28,19); cout<<"|  AFILIARME  |  || CANCELAR ||";
        gotoxy(28,20); cout<<"---------------  ==============";
        gotoxy(48,19); break;
    }
  } else if (menu.compare("2.5_credito") == 0) {
    switch(elemento) {
      case 0: // Boton de abonar crédito
        gotoxy(36,9);  cout<<"============  ------------------";
        gotoxy(36,10); cout<<"|| ABONAR ||  |  VOLVER ATRAS  |";
        gotoxy(36,11); cout<<"============  ------------------";
        gotoxy(39,10); break;
      case 1: // Botón de volver atrás
        gotoxy(36,9);  cout<<"------------  ==================";
        gotoxy(36,10); cout<<"|  ABONAR  |  || VOLVER ATRAS ||";
        gotoxy(36,11); cout<<"------------  ==================";
        gotoxy(53,10); break;
    }
  } else if (menu.compare("2.5_credito_f2") == 0) {
    switch(elemento) {
      case 0: // Monto abonado
        gotoxy(37,10); break;
      case 1: // Beneficiario (Opcional)
        gotoxy(52,10); break;
      case 2: // Checkbox
        gotoxy(37,14); break;
      case 3: // Abonar
        gotoxy(39,18); break;
      case 4: // Cancelar
        gotoxy(53,18); break;
    }
  } // Fin de manejar elementos de cada menú
} // Fin de hacer focus en elemento de entrada

void mostrarAviso(string aviso, string datoExtra) {
  if (aviso.compare("suscripcion_exitosa") == 0) {
    system("cls"); system("color 3F"); dibujarBordes();
    // Renderizado de cena de cumpleaños http://www.chris.com/ascii/index.php?art=events/birthday
    gotoxy(4, 2); cout<<"                              : . /%O!!::::::::\\\\_\\. \\";
    gotoxy(4, 3); cout<<"                             [\"\"]/%%O!!:::::::::  : . \\                  ";
    gotoxy(4, 4); cout<<"                             |  |%%OO!!::::::::::: : . |";
    gotoxy(4, 5); cout<<"                             |  |%%OO!!:::::::::::::  :|";
    gotoxy(4, 6); cout<<"                             |  |%%OO!!!::::::::::::: :|";
    gotoxy(4, 7); cout<<"                    :       .'--`.%%OO!!!:::::::::::: :|";
    gotoxy(4, 8); cout<<"                  : .:     /`.__.'\\%%OO!!!::::::::::::/";
    gotoxy(4, 9); cout<<"                 :    .   /        \\%OO!!!!::::::::::/";
    gotoxy(4,10); cout<<"                ,-'``'-. ;          ;%%OO!!!!!!:::::'";
    gotoxy(4,11); cout<<"                |`-..-'| |   ,--.   |`%%%OO!!!!!!:'";
    gotoxy(4,12); cout<<"                | .   :| |_.','`.`._|  `%%%OO!%%'";
    gotoxy(4,13); cout<<"                | . :  | |--'    `--|    `%%%%'";
    gotoxy(4,14); cout<<"                |`-..-'| ||   | | | |     /__\\`-.";
    gotoxy(4,15); cout<<"                \\::::::/ ||)|/|)|)|\\|           /";
    gotoxy(4,16); cout<<"-----------------`::::'--|._ ~**~ _.|----------( -----------------------";
    gotoxy(4,17); cout<<"                   )(    |  `-..-'  |           \\    ______";
    gotoxy(4,18); cout<<"                   )(    |          |,--.       ____/ /  /\\\\ ,-._.-'";
    gotoxy(4,19); cout<<"                ,-')('-. |          |\\`;/   .-()___  :  |`.!,-'`'/`-._";
    gotoxy(4,20); cout<<"               (  '  `  )`-._    _.-'|;,|    `-,    \\_\\__\\`,-'>-.,-._";
    gotoxy(4,21); cout<<"                `-....-'     ````    `--'      `-._       (`- `-._`-.   ";
    // Renderizado de texto
    gotoxy(5,23); cout << "La suscripcion a la membresia Blockbuster fue un exito!";
    gotoxy(6, 3); cout << "FELICIDADES!";
    gotoxy(6, 4); cout << datoExtra;
    gotoxy(6, 9); cout << "Presiona";
    gotoxy(6,10); cout << "cualquier";
    gotoxy(6,11); cout << "tecla para";
    gotoxy(6,12); cout << "continuar";
    getch(); system("color 1F");
  } else if (aviso.compare("expiracion_membresia") == 0) {
    vector<string> fechaExpiracion;

    fechaExpiracion = separarLinea(datoExtra, '/');

    gotoxy(28,16); cout << fechaExpiracion[0];           // Dia
    gotoxy(36,16); cout << mesTexto(fechaExpiracion[1]); // Mes
    gotoxy(53,16); cout << fechaExpiracion[2];           // Año
    gotoxy(37,19); // Re-Enfocar Botón "Entendido"
  } else if (aviso.compare("registro_exitoso") == 0) {
    system("cls"); system("color 5F"); dibujarBordes();
    // Renderizado de nave futurama chris.com/ascii/index.php?art=television/futurama
    gotoxy(16,8);  cout<<"                     `. ___";
    gotoxy(16,9);  cout<<"                    __,' __`.                _..----....____";
    gotoxy(16,10); cout<<"        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'";
    gotoxy(16,11); cout<<"  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'";
    gotoxy(16,12); cout<<",'________________                          \\`-._`-','";
    gotoxy(16,13); cout<<" `._              ```````````------...___   '-.._'-:";
    gotoxy(16,14); cout<<"    ```--.._      ,.                     ````--...__\\-.";
    gotoxy(16,15); cout<<"            `.--. `-`                       ____    |  |`";
    gotoxy(16,16); cout<<"              `. `.                       ,'`````.  ;  ;`";
    gotoxy(16,17); cout<<"                `._`.        __________   `.      \\'__/`";
    gotoxy(16,18); cout<<"                   `-:._____/______/___/____`.     \\  `";
    gotoxy(16,19); cout<<"                               |       `._    `.    \\";
    gotoxy(16,20); cout<<"                               `._________`-.   `.   `.___";
    gotoxy(16,21); cout<<"                                             SSt  `------'`";
    // Renderizado de texto
    gotoxy(10,3);  cout<<"Bienvenid@ al sistema, "<<datoExtra<<"!";
    gotoxy(10,4);  cout<<"Haz sido registrada@ con exito en nuestro sistema.";
    gotoxy(10,5);  cout<<"Desde ahora podras entrar al menu de clientes.";
    gotoxy(5, 16); cout<<"Presiona"  ;
    gotoxy(5, 17); cout<<"cualquier" ;
    gotoxy(5, 18); cout<<"tecla para";
    gotoxy(5, 19); cout<<"continuar" ;
    getch(); system("color 1F");
  }
} // Fin de mostrar confirmaciones, pantallas y avisos

void mostrarError(string tipoError, string datoExtra) {
  if (tipoError.compare("clientes_opcion_equivocada") == 0) {
    gotoxy(13,23); cout<<"Opcion equivocada, elige entre 1 y 6!";
    Sleep(2500); enfocarElemento("2_clientes", 0);
  } else if (tipoError.compare("db_error") == 0) {
    system("cls"); system("color 4F"); // Pantalla roja
    dibujarBordes();
    // Libro ASCII: www.chris.com/ascii/index.php?art=objects/books
    gotoxy(10,13); cout<<"              .__=\\__                  .__==__,"              <<endl;
    gotoxy(10,14); cout<<"            jf'      ~~=\\,         _=/~'      `\\,"           <<endl;
    gotoxy(10,15); cout<<"        ._jZ'            `\\q,   /=~             `\\__"        <<endl;
    gotoxy(10,16); cout<<"       j5(/                 `\\./                  V\\\\,"     <<endl;
    gotoxy(10,17); cout<<"     .Z))' _____              |             .____, \\)/\\"     <<endl;
    gotoxy(10,18); cout<<"    j5(K=~~     ~~~~\\=_,      |      _/=~~~~'    `~~+K\\\\,"  <<endl;
    gotoxy(10,19); cout<<"  .Z)\\/                `~=L   |  _=/~                 t\\ZL"  <<endl;
    gotoxy(10,20); cout<<" j5(_/.__/===========\\__   ~q |j/   .__============___/\\J(N,"<<endl;
    gotoxy(10,21); cout<<"4L#XXXL_________________XGm, \\P  .mXL_________________JXXXW8L";
    // Renderizado de Texto
    gotoxy(30,2);  cout << "MENSAJE DE ERROR";
    gotoxy(10,5);  cout<<"Hubo un error al intentar abrir un archivo de texto para la";
    gotoxy(10,6);  cout<<"extraccion o insercion de informacion. Asegurese que en la";
    gotoxy(10,7);  cout<<"carpeta donde instalo este programa exista un archivo con el";
    gotoxy(10,8);  cout<<"nombre correcto: [              ]";
    gotoxy(10,10); cout<<"Presione cualquier tecla para salir del programa";
    // Imprimir el nombre del archivo problemático
    gotoxy(28,8); cout << datoExtra; gotoxy(58,10);
    getch();
  }
} // Fin de mostrar errores en pantalla

/* =======================================================
|||||||||||   COMPLEMENTOS DE MENÚ CATÁLOGO    |||||||||||
========================================================*/

void mostrarPagina(vector<string> pelis, int pag) {
  vector<vector<int> > paginas;
  vector<string> peli;

  /* ROL DE PÁGINAS:
  =============================================
  paginas[i] -> Número de página
  paginas[i][j] -> 0: Inicio - 1: Final 
  pag -> Página actual pasada como parámetro */

  paginas = paginacion(pelis.size(), 11);
  // Mostrar películas de la primera página
  for (int i=paginas[pag][0],y=4;i<=paginas[pag][1];i+=1) {
    peli = separarLinea(pelis[i], ';'); gotoxy(5, y);
    // Mostrar película y el año entre paréntesis
    cout << peli[1]<<" ("<<peli[2]<<")";
    peli.clear(); y += 1; // Siguiente línea
  } // Fin de búsqueda de películas

  gotoxy(4,4);
} // Fin de desplegar items de una página

void detallesDeLaPelicula(vector<string> pelicula) {
  //
} // Fin de listar los detalles de la película

/* =======================================================
|||||||||||    COMPLEMENTOS DE MENÚ CRÉDITO    |||||||||||
========================================================*/

void mostrarCredito(string usuario) {
  string credito = consultaRapida(
    "usuarios.txt", 0, usuario, 3
  ); // Fin de almacenar el crédito del usuario

  limpiarZona("2.5_credito", 0);

  gotoxy(6,11); cout << usuario;
  gotoxy(7,16); cout << credito;
} // Fin de mostrar dinero del usuario

/* ======================================================
||||||||||| ELEMENTOS DE ANIMACIÓN Y ADORNOS ||||||||||||
========================================================*/

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
  Sleep(velocidad*3); system("cls"); system("color 1F");
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

/*cout<<"            _.-'~~`~~'-._"          ;
cout<<"         .'`  B   E   R  `'."       ;
cout<<"        / I               T \\"     ;
cout<<"      /`       .-'~\"-.       `\\"  ;
cout<<"     ; L      / `-    \\      Y ;"  ;
cout<<"    ;        />  `.  -.|        ;"  ;
cout<<"    |       /_     '-.__)       |"  ;
cout<<"    |        |-  _.' \\ |        |" ;
cout<<"    ;        `~~;     \\\\        ;";
cout<<"     ;  INGODWE /      \\\\)P    ;" ;
cout<<"      \\  TRUST '.___.-'`\"     /"  ;
cout<<"       `\\                   /`"    ;
cout<<"         '._   1 9 9 7   _.'"       ;*/