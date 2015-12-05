namespace menu {
void rentas() {
  dibujarMenu("2.1_renta_f1");
  getch();
  dibujarMenu("2_clientes");
} // Fin de rentar películas

void comprar() {
  // quitar pelicula si 'stock = 0'
}

void membresiasControl(string usuario) {
  dibujarMenu("2.3_membresias_ctrl");
  getch();
} // Fin de panel de control de membresía

void membresiasAfiliacion(string usuario) {
  dibujarMenu("2.3_membresias_afil");
  // Variables necesarias
  char tecla; int dir; short int duracionMemb = 6;
  int boton = 3; // 3: Afiliarme - 4: Cancelar
  int orden[4][2] = {{3,4},{3,4},{3,4},{3,4}};

  // Paso 1: Mostrar la expiración y almacenarla
  string expiracion = cuandoExpira(duracionMemb);
  mostrarAviso("expiracion_membresia", expiracion);

  // Paso 2: ENTER -> Información
  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (tecla == 13) { // 'ENTER'
        enfocarElemento("2.3_membresias_afil", 1);
        break;
      } // Fin de esperar 'ENTER'
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'

  // Paso 3: ENTER -> Contrato
  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (tecla == 13) { // 'ENTER'
        enfocarElemento("2.3_membresias_afil", 2);
        break;
      } // Fin de esperar 'ENTER'
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'

  // Paso 4: ENTER -> Afiliarse!
  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (tecla == 13) { // 'ENTER'
        switch(boton) {
          case 3: // Afiliarme
            if (realizarGasto(usuario, 250)) {
              // Si se pudo cobrar $250.00, afiliarse
              nuevaMembresia(usuario, expiracion);
              mostrarAviso("suscripcion_exitosa", usuario);
              finalFantasy(0.7);
              tecla = 27; // Volver al menú clientes
            } else {
              // Mostrar error, saldo, costo y diferencia

            } // Fin de comprobar gasto exitoso
          break;
          case 4: // Cancelar
            tecla = 27; // Volver al menú clientes
          break;
        } // Fin de presionar botón
      } else if (esDireccional(tecla)) {
        dir = obtenerDireccion(tecla);
        enfocarElemento("2.3_membresias_afil", orden[dir][boton]);
        boton = orden[dir][boton];
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
} // Fin de complemento menu::membresias

void membresias(string usuario) {
  // Variables para los valores del input
  int dir, btn = 0; char tecla;
  /* 0: 'Afiliarme' - 1: 'Reglas' */
  int orden[4][2] = {{1,0},{1,0},{1,0},{1,0}};

  if (tieneMembresia(usuario)) {
     menu::membresiasControl(usuario);
     tecla = 27; // Previene mostrar opción de afiliarse
  } else { // No está afiliado aún
    dibujarMenu("2.3_membresias_nuevo");
  } // Fin de revisar si ya está afiliado

  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) { // Der-Izq-Tab
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento("2.3_membresias_nuevo", orden[dir][btn]);
        btn = orden[dir][btn];
      } else if (tecla == 13) { // 'ENTER'
        switch(btn) {
          case 0: // Afiliarme
            menu::membresiasAfiliacion(usuario);
            tecla = 27; // Volver al menú anterior
          break;

          case 1: // Reglas
            dibujarMenu("2.3_membresias_reglas");
            tecla = 0; // Para entrar en el ciclo
            while(tecla != 13) {
              tecla = getch();
              if (tecla == 13) {
                dibujarMenu("2.3_membresias_nuevo");
                btn = 0; // Resetear elección
              } // Fin de aceptar
            } // Fin de esperar tecla ENTER
          break;
        } // Fin de lanzar sub-menú
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de suscribirse a membresía

void abonar(string usuario) {
  dibujarMenu("2.5_credito_f2");
  // variables necesarias
  int dir, input = 0, abono = 0; char tecla;
  bool beneficiario = false; string destinatario, monto;
  int orden[4][5] = {{1,2,3,4,0}, {4,0,1,2,3},
  {3,4,0,2,1}, {2,4,3,0,1}};

  // Mostrar el usuario y su crédito en pantalla
  mostrarCredito(usuario); gotoxy(37,10);

  while (tecla != ESC) {
    tecla = getch();
    if(tecla == 0) { tecla = getch(); } else {
      if ( /* Direccional o ENTER sin estar en botones */
        esDireccional(tecla) ||
        (tecla == ENTER && // ENTER en los cuadros de texto
        (input != 4 && input != 3 && input != 2))
      ) {  /* Direccional o ENTER sin estar en botones */
        dir = obtenerDireccion(tecla);
        /* Prevenir el enfoque del campo de texto
        'beneficiario' si no se ha marcado esa opción */
        if (!beneficiario && orden[dir][input] == 1) {
          /* Saltarse el siguiente input en caso de que
          el siguiente sea el campo 'Beneficiario' */
          input = orden[dir][input];
        } // Fin de comprobar el checkbox
        enfocarElemento(
          "2.5_credito_f2", orden[dir][input]
        ); // Fin de enfocar inputs
        input = orden[dir][input];
        switch(input) {
          case 0: monto.clear();         break;
          case 1: destinatario.clear();  break;
        } // Fin de resetear inputs
      } else if (esAlfaNum(tecla) && // Tecla es alfanumérica
      input != 2 && input != 3 & input != 4 /* NO botón */) {
        switch(input) {
          case 0: // Cuadro de texto: Monto abonado
            if (monto.length() < 4 && esNumerica(tecla)) {
              gotoxy(37,10); monto += tecla; cout << monto;
              gotoxy(37+monto.length(),10);
            } break;
          case 1: // Cuadro de texto: Beneficiario
            if (destinatario.length() < 18) {
              gotoxy(52,10); destinatario += tecla;
              cout << destinatario;
              gotoxy(52+destinatario.length(),10);
            } break;
        } // Fin de capturar datos
      } else if (tecla == BCKSP || tecla == DEL) {
        // Limpiar cuadros de texto
        enfocarElemento("2.5_credito_f2", input);
        switch(input) {
          case 0: monto.clear();         break;
          case 1: destinatario.clear();  break;
        } // Fin de resetear inputs
      } else if (tecla == ENTER) { // 'ENTER'
        switch(input) {
          case 2: // Checkbox 'Regalar Crédito'
            // Activar/Desactivar la opción de abonar a otro
            activarRegalo(beneficiario);
            beneficiario = !beneficiario;
            destinatario.clear(); break;
          case 3: // Botón 'Abonar'
            abono = atoi(monto.c_str());
            if (beneficiario) {
              abonarCredito(destinatario, abono);
              mostrarAviso("abono_regalo", destinatario);
              tecla = 0; // Permite entrar al ciclo
              while (tecla != ENTER) {
                tecla = getch();
                if (tecla == ENTER) {
                  dibujarMenu("2.5_credito_f2");
                } // Fin de aceptar
              } // Fin de esperar ENTER
              destinatario.clear();
            } else { // El crédito es para el usuario
              abonarCredito(usuario, abono);
            } // Fin de ver a quién abonar el crédito
            mostrarCredito(usuario); input = 0;
            // Volver al primer textbox
            enfocarElemento("2.5_credito_f2", input);
            beneficiario = false;
            abono        = 0;
            monto.clear(); break;
          case 4: // Botón 'Cancelar'
            tecla = ESC;    break; // Salir
        } // Fin de asignar comportamiento a botones
      } // Fin de reaccionar a teclas
    } // Fin de selección de tecla
  } // Fin de pedir tecla y terminar al presionar 'ESC'
} // Fin de abonar a mi cuenta o la de otros

void miCredito(string usuario) {
  dibujarMenu("2.5_credito");
  // Variables necesarias
  int orden[4][2] = {{1,0},{1,0},{1,0},{1,0}};
  int dir, boton = 0; char tecla;

  // Mostrar el usuario y su crédito en pantalla
  mostrarCredito(usuario); gotoxy(39,10);

  while (tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if(tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) { // Der-Izq-Tab
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento("2.5_credito", orden[dir][boton]);
        boton = orden[dir][boton];
      } else if (tecla == 13) { // 'ENTER'
        switch(boton) {
          case 0: menu::abonar(usuario);     boton=0;
          tecla = 27;                        break;
          case 1: tecla = 27;                break;
        } // Fin de lanzar menú adecuado
      } // Fin de reaccionar a teclas
    } // Fin de selección de tecla
  } // Fin de pedir tecla y terminar al presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de manejar dinero en la cuenta

void catalogoFrame2(string usuario, int gnrId) {
  dibujarMenu("2.4_catalogo_f2");
  /*-------------------------------------------------*/
  #define GENERO   3
  #define FILAS    11
  #define INICIO   0
  #define LISTA    0
  #define PUNTEROS 1
  #define DETALLES 2
  /*-------------------------------------------------*/
  vector<string> peliculas; /* Tabla filtrada */
  string genero = obtenerGenero(gnrId);
  peliculas = filtrarRegistros(
    "peliculas.txt", GENERO, genero
  ); // Consulté la dB para traer las pelis del género
  int puntero = 0, direccion, pagActual = 0; char tecla;
  /*------------- FIN DE VARIABLES NECESARIAS ------------*/

  // Poner género en el título del menú
  gotoxy(41,2); cout << genero; gotoxy(4,4);

  // Mostrar las películas en pantalla
  if (peliculas.size() > 0) { // Hay películas
    // Desplegar la primera página
    mostrarPagina(peliculas, pagActual);
    vector<vector<int> > pags = paginacion(
      peliculas.size(), FILAS
    ); // Fin de obtener rol de páginas

    // Manejo de teclas 'ESC', Arriba', 'Abajo' y 'ENTER'
    while(tecla != ESC) { // Tecla NO es 'ESC'
      tecla = getch(); int direccion;
      if (tecla == 0) { tecla = getch(); } else {
        if (esDireccional(tecla))  {
          int final = pags[pags.size()-1][1];
          direccion = obtenerDireccion(tecla);

          switch(direccion) {
            case 0: // Derecha
            case 3: // Abajo
              if (puntero == final)                     {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Última película en la lista, te lleva a
                la primera página y película del listado */
                puntero = INICIO; pagActual = 0;
                mostrarPagina(peliculas, pagActual);
              } else if (puntero == pags[pagActual][1]) {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Última película en la página, te lleva
                a la primer peli del menú siguiente    */
                puntero = pags[pagActual + 1][0];
                pagActual += 1;
                mostrarPagina(peliculas, pagActual);
              } else                                    {
                /* La película no es ni la primera
                ni la última en la lista        */
                limpiarZona("2.4_catalogo_f2", PUNTEROS);
                puntero += 1;
              } // Fin de actuar conforme al puntero
            break;

            case 1: // Izquierda
            case 2: // Arriba
              if (puntero == 0)                         {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Primer película en la lista, te lleva a
                la última película y a la última página */
                puntero=final; pagActual = pags.size()-1;
                mostrarPagina(peliculas, pagActual);
              } else if (puntero == pags[pagActual][0]) {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Primer película en la página, te lleva
                a la última peli del menú anterior     */
                puntero = pags[pagActual-1][1];
                pagActual -= 1;
                mostrarPagina(peliculas, pagActual);
              } else                                    {
                /* La película no es ni la primera
                ni la última en la lista        */
                limpiarZona("2.4_catalogo_f2", PUNTEROS);
                puntero -= 1;
              } // Fin de actuar conforme al puntero
            break;
          } // Fin de controlar flechas
          // Localizar y enfocar  el puntero '>'
          limpiarZona("2.4_catalogo_f2", DETALLES);
          detallesDeLaPelicula(peliculas[puntero]);
          moverPuntero(puntero, pagActual)        ;
        } else if (tecla == ENTER) {
          // Dar opción de comprar o rentar
        } // Fin de reaccionar a teclas
      } // Fin de detectar tecla válida
    } // Fin de ciclar hasta presionar 'ESC'
  } else { // No hay películas
    gotoxy(5,4);
    cout << "No se encontro ninguna pelicula.";
    gotoxy(5,5);
    cout << "Presione cualquier tecla para volver al catalogo";
    getch();
  } // Fin de ver si hay películas

  dibujarMenu("2.4_catalogo_f1");
} // Fin de detalles de películas

void catalogo(string usuario) {
  dibujarMenu("2.4_catalogo_f1");
  // Variables para los valores del input
  char tecla; int dir, boton = 0;
  /*-------------------------------------------------*\
  |  0 => Horror    3  => Aventura    6 => Comedia    |
  |  1 => Sci-Fi    4  => Acción      7 => Romance    |
  |  2 => Drama     5  => Biografía   8 => Documental |
  |  9 => Estrenos  10 => En remate                   |
  \*-------------------------------------------------*/
  int orden[4][11] = {{1,2,3,4,5,6,7,8,9,10,0},
  {10,0,1,2,3,4,5,6,7,8,9},{5,9,9,10,8,0,1,3,4,6,7},
  {5,6,7,7,8,9,9,10,10,1,3}};

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) { // Der-Izq-Tab
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento(
          "2.4_catalogo_f1", orden[dir][boton]
        ); // Fin de enfocar elemento
        boton = orden[dir][boton];
      } else if (tecla == ENTER) {
        menu::catalogoFrame2(usuario, boton);
        boton = 0;
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de catálogo de películas

void clientes(string usuario) {
  dibujarMenu("2_clientes"); int opcion;

  while(true) {
    enfocarElemento("2_clientes", 0);
    cin >> opcion;
    if (opcion >= 1 && opcion <= 5) {
      switch(opcion) {
        case 1: menu::rentas();             break;
        case 2: menu::comprar();            break;
        case 3: menu::membresias(usuario);  break;
        case 4: menu::catalogo(usuario);    break;
        case 5: menu::miCredito(usuario);   break;
      } // Fin de lanzar menú correspondiente
    } else if (opcion == 6) {
      break; // Salir del ciclo infinito
    } else { // Opción inválida
      mostrarError("clientes_opcion_equivocada");
    } // Fin de comprobar error de capa 8
  } // Fin de ciclo infinito
} // Fin de menú de clientes

void empleados() {
  dibujarMenu("3_empleados");
  getch();
} // Fin de menú de empleados

void login() {
  dibujarMenu("1_principal_login");
  // Variables para los valores del input
  string usuario, password, credenciales; char tecla;
  int input = 0, // Selector de botón o caja de texto
      orden[4][3] = {{1,2,0},{2,0,1},{2,0,1},{1,2,0}},
      dir /* Dirección */; bool tienePermiso;

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if ( /* Direccional o ENTER sin estar en el botón */
        esDireccional(tecla) ||
        (tecla == ENTER && input != 2)
      ) {  /* Direccional o ENTER sin estar en el botón */
        dir = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento(
          "1_principal_login", orden[dir][input]
        ); // Fin de enfocar inputs
        input = orden[dir][input];
        // Limpiar cadenas de texto
        switch(input) {
          case 0: usuario.clear();           break;
          case 1: password.clear();          break;
        } // Fin de limpiar cadenas
      } else if (esAlfaNum(tecla) && input != 2 ){
        switch(input) {
          case 0: // Usuario
            if (usuario.length() < 18)  {
              gotoxy(23,12);
              usuario += tecla; cout << usuario;
              gotoxy(23+usuario.length(),12);
            } break;
          case 1: // Contraseña
            if (password.length() < 18) {
              gotoxy(49,12);
              password += tecla;
              cout << asteriscos(password);
              gotoxy(49+password.length(),12);
            } break;
        } // Fin de capturar datos
      } else if (tecla == BCKSP || tecla == DEL) {
        // Resetea y re-enfoca el cuadro de texto
        enfocarElemento("1_principal_login", input);
        switch(input) {
          case 0: usuario.clear();   break;
          case 1: password.clear();  break;
        } // Fin de resetear inputs actuales
      } else if (tecla == ENTER && input == 2)   {
        // Al presionar 'ENTER' validar y loguear
        tienePermiso = autenticar(usuario, password);
        if(tienePermiso) {
          credenciales = consultaRapida(
            "usuarios.txt", NOMBRE, usuario, ROL
          ); // Fin de almacenar el rol del usuario

          if (credenciales        == "empleado") {
            menu::empleados();       break;
          } else if (credenciales == "cliente")  {
            menu::clientes(usuario); break;
          } // Fin de llevar al menú correspondiente
        } else { // No tiene permiso
          //
        } // Fin de dar pase si tiene permiso
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de autenticar usuario

void registro() {
  dibujarMenu("1_principal_registro");
  // Variables para los valores del input
  string usuario, clave, claveRepetida, nuevoUsuario;
  /* input 0 => Usuario             input 1 => Contraseña
     input 2 => Repetir clave       input 3 => Btn 'Listo'
     orden   => [0: der - 1: izq - 2: arr - 3: abj]     */
  int orden[4][4] = {{1,2,3,0},{3,0,1,2},{1,0,3,2},{1,0,3,2}},
      dir, input = 0; bool registroValido; char tecla;

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if ( /* Direccional o ENTER sin estar en el botón */
        esDireccional(tecla) ||
        (tecla == ENTER && input != 3)
      ) {  /* Direccional o ENTER sin estar en el botón */
        dir = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento(
          "1_principal_registro", orden[dir][input]
        ); // Fin de enfocar inputs
        input = orden[dir][input];
        switch(input) {
          case 0: usuario.clear();       break;
          case 1: clave.clear();         break;
          case 2: claveRepetida.clear(); break;
        } // Fin de resetear inputs
      } else if (esAlfaNum(tecla) && input != 3) {
        switch(input) {
          case 0: // Usuario
            if (usuario.length() < 18) {
              gotoxy(23,12);
              usuario += tecla;
              cout << usuario;
              gotoxy(23+usuario.length(),12);
            } break;
          case 1: // Contraseña
            if (clave.length() < 18) {
              gotoxy(23,17);
              clave += tecla;
              cout << asteriscos(clave);
              gotoxy(23+clave.length(),17);
            } break;
          case 2: // Repetir contraseña
            if (claveRepetida.length() < 18) {
              gotoxy(50,12);
              claveRepetida += tecla;
              cout << asteriscos(claveRepetida);
              gotoxy(50+claveRepetida.length(),12);
            } break;
        } // Fin de capturar datos
      } else if (tecla == BCKSP || tecla == DEL) {
        // Limpiar cuadros de texto
        enfocarElemento("1_principal_registro", input);
        switch(input) {
          case 0: usuario.clear();       break;
          case 1: clave.clear();         break;
          case 2: claveRepetida.clear(); break;
        } // Fin de resetear inputs actuales
      } else if (tecla == ENTER && input == 3) {
        registroValido = (
          nombreDisponible(usuario) &&
          clave.compare(claveRepetida) == 0 &&
          usuario.length() >= 6 &&
          clave.length() >= 6
        ); // Fin de validar formulario

        // Si el formulario es válido, registrar usuario
        if (registroValido) {
          // Ensamblar el nuevo registro
          nuevoUsuario = usuario + ";"+clave+";cliente;0";
          // Insertarlo en la base de datos
          insertarRegistro("usuarios.txt", nuevoUsuario);
          mostrarAviso("registro_exitoso", usuario);
          finalFantasy(0.7);
          break; // Salir de este menú
        } else {
          system("cls"); cout << "Registro invalido";
          getch(); break; // Salir de este menú
        } // Fin de verificar el envío de datos
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de agregar nuevos clientes
} // Fin de namespace menu::función