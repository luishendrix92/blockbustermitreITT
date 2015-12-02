namespace menu {
void rentas() {
  dibujarMenu("2.1_renta_f1");
  getch();
  dibujarMenu("2_clientes");
} // Fin de rentar películas

void comprar() {
  // quitar pelicula si 'stock = 0'
}

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
              // Si se pudo cobrar $250.00, afiliar y mensaje
              nuevaMembresia(usuario, expiracion);
              mostrarAviso("suscripcion_exitosa", usuario);
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
  dibujarMenu("2.3_membresias_nuevo");
  // Variables para los valores del input
  char tecla; int dir, btn = 0;
  /* 0: Botón 'Afiliarme' - 1: Botón 'Reglas'*/
  int orden[4][2] = {{1,0},{1,0},{1,0},{1,0}};

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

void miCredito() {
  dibujarMenu("2.5_credito");
  getch();
  dibujarMenu("2_clientes");
} // Fin de manejar dinero en la cuenta

void catalogoFrame2(string usuario, int gnrId) {
  dibujarMenu("2.4_catalogo_f2");
  /*-------------------------------------------------*\
  |  0 => Horror    3  => Aventura    6 => Comedia    |
  |  1 => Sci-Fi    4  => Acción      7 => Romance    |
  |  2 => Drama     5  => Biografía   8 => Documental |
  |  9 => Estrenos  10 => En remate                   |
  \*-------------------------------------------------*/
  vector<string> peliculas; /* Tabla filtrada */
  string genero = obtenerGenero(gnrId); int pagActual = 0;
  peliculas = filtrarRegistros("peliculas.txt", 3, genero);
  int puntero = 0, direccion; char tecla;
  /*------------- FIN DE VARIABLES NECESARIAS ------------*/

  // Poner género en el título
  gotoxy(41,2); cout << genero; gotoxy(4,4);

  // Mostrar las películas en pantalla
  if (peliculas.size() > 0) {
    // Desplegar la primera página
    mostrarPagina(peliculas, pagActual);
    vector<vector<int> > pags=paginacion(peliculas.size(),11);
    // Manejo de teclas 'ESC', Arriba', 'Abajo' y 'ENTER'
    while(tecla != 27) { // Tecla NO es 'ESC'
      tecla = getch(); int direccion;
      if (tecla == 0) { tecla = getch(); } else {
        if (esDireccional(tecla)) {
          direccion = obtenerDireccion(tecla);
          short int inicio = 0, final;
          final  = pags[pags.size() - 1][1];
          switch(direccion) {
            case 0: // Derecha
            case 3: // Abajo
              if (puntero == final) {
                // Limpiar la zona de muestreo
                limpiarZona("2.4_catalogo_f2", 0);
                /* Última película en la lista, ir
                hacia abajo te lleva a la primera
                página y película del listado   */
                puntero = inicio; pagActual = 0;
                mostrarPagina(peliculas, pagActual);
              } else if (puntero == pags[pagActual][1]) {
                // Limpiar la zona de muestreo
                limpiarZona("2.4_catalogo_f2", 0);
                /* Última película en la página, al
                presionar abajo te lleva a la primer
                peli del menú siguiente           */
                puntero = pags[pagActual + 1][0];
                pagActual += 1;
                mostrarPagina(peliculas, pagActual);
              } else {
                /* La película no es ni la primera
                ni la última en la lista        */
                limpiarZona("2.4_catalogo_f2", 1);
                puntero += 1;
              } // Fin de actuar conforme al puntero
            break;

            case 1: // Izquierda
            case 2: // Arriba
              if (puntero == 0) {
                // Limpiar la zona de muestreo
                limpiarZona("2.4_catalogo_f2", 0);
                /* Primer película en la lista, ir
                hacia arriba te lleva a la última
                película y a la última página   */
                puntero = final; pagActual = pags.size()-1;
                mostrarPagina(peliculas, pagActual);
              } else if (puntero == pags[pagActual][0]) {
                // Limpiar la zona de muestreo
                limpiarZona("2.4_catalogo_f2", 0);
                /* Primer película en la página, al
                presionar arriba te lleva a la última
                peli del menú anterior             */
                puntero = pags[pagActual - 1][1];
                pagActual -= 1;
                mostrarPagina(peliculas, pagActual);
              } else {
                /* La película no es ni la primera
                ni la última en la lista        */
                limpiarZona("2.4_catalogo_f2", 1);
                puntero -= 1;
              } // Fin de actuar conforme al puntero
            break;
          } // Fin de controlar flechas
          // Localizar y enfocar  el puntero '>'
          limpiarZona("2.4_catalogo_f2", 2);
          gotoxy(4,4+puntero-(11*pagActual)); cout << ">";
          gotoxy(4,4+puntero-(11*pagActual));
        } else if (tecla == 13) { // 'ENTER'
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
} // Parte del menú 'catalogo' [Frame 2]

void catalogo(string usuario) {
  dibujarMenu("2.4_catalogo_f1");
  // Variables para los valores del input
  char tecla; int dir, boton = 0;
  /*-------------------------------------------------*\
  |  0 => Horror    3  => Aventura    6 => Comedia    |
  |  1 => Sci-Fi    4  => Acción      7 => Romance    |
  |  2 => Drama     5  => Biografía   8 => Documental |
  |  9 => Estrenos  10 => En remate                   |
  |---------------------------------------------------|
  |  0: Der   -   1: Izq   -   2: Arr   -   3: Abj    |
  \*-------------------------------------------------*/
  int orden[4][11] = {{1,2,3,4,5,6,7,8,9,10,0},
  {10,0,1,2,3,4,5,6,7,8,9},{5,9,9,10,8,0,1,3,4,6,7},
  {5,6,7,7,8,9,9,10,10,1,3}};

  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) { // Der-Izq-Tab
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento("2.4_catalogo_f1", orden[dir][boton]);
        boton = orden[dir][boton];
      } else if (tecla == 13) { // 'ENTER'
        menu::catalogoFrame2(usuario, boton); boton = 0;
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de catálogo de películas

void clientes(string usuario, string credito) {
  dibujarMenu("2_clientes");
  // Variables necesarias
  int dinero = atoi(credito.c_str()), opcion;

  while(true) {
    enfocarElemento("2_clientes", 0);
    cin >> opcion;
    if (opcion >= 1 && opcion <= 5) {
      switch(opcion) {
        case 1: menu::rentas();             break;
        case 2: menu::comprar();            break;
        case 3: menu::membresias(usuario);  break;
        case 4: menu::catalogo(usuario);    break;
        case 5: menu::miCredito();          break;
      } // Fin de lanzar menú correspondiente
    } else if (opcion == 6) {
      break; // Salir del ciclo infinito
    } else { // Opción inválida
      mostrarError("clientes_opcion_equivocada", "");
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
  string usuario, password; char tecla;
  vector<string> credenciales;
  /* input 0 => Usuario
     input 1 => Contraseña
     input 2 => Botón 'Entrar'
     orden => [0: der - 1: izq] */
  int input = 0, // Selector de botón o caja de texto
      orden[4][3] = {{1,2,0},{2,0,1},{2,0,1},{1,2,0}},
      dir /* Dirección */; bool tienePermiso;

  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if ( /* Direccional o ENTER sin estar en el botón */
        esDireccional(tecla) ||
        (tecla == 13 && input != 2)
      ) {  /* Direccional o ENTER sin estar en el botón */
        dir = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento("1_principal_login", orden[dir][input]);
        input = orden[dir][input];
        // Limpiar cadenas de texto
        if (input == 0){ usuario.clear(); }
        else if (input == 1){ password.clear(); }
      } else if (esAlfaNum(tecla) // Tecla es alfanumérica
      && input != 2 // No es el botón 'Entrar'
      && usuario.length() < 18 && password.length() < 18) {
        switch(input) {
          case 0: // Usuario
            gotoxy(23,12); usuario += tecla; cout << usuario;
            gotoxy(23+usuario.length(),12); break;
          case 1: // Contraseña
            gotoxy(49,12); password += tecla; cout << asteriscos(password);
            gotoxy(49+password.length(),12); break;
        } // Fin de capturar datos
      } else if (tecla == 8 || tecla == 224) { // 'BCKSP'-'DEL'
        switch(input) {
          case 0: // Usuario
            enfocarElemento("1_principal_login", 0);
            usuario.clear(); break;
          case 1: // Contraseña
            enfocarElemento("1_principal_login", 1);
            password.clear(); break;
        } // Fin de resetear inputs actuales
      } else if (tecla == 13 && input == 2) {
        // Al presionar 'ENTER' validar y loguear
        tienePermiso = autenticar(usuario, password);
        if(tienePermiso) {
          vector<string> usuariosTemporales;
          usuariosTemporales = filtrarRegistros("usuarios.txt", 0, usuario);
          credenciales = separarLinea(usuariosTemporales[0], ';');

          if(credenciales[2].compare("empleado") == 0) {
            menu::empleados(); break;
          } else if (credenciales[2].compare("cliente") == 0) {
            menu::clientes(credenciales[0], credenciales[3]);
            break; // Salir de la función
          } // Fin de llevar al menú correspondiente

          credenciales.clear(); usuariosTemporales.clear();
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

  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if ( /* Direccional o ENTER sin estar en el botón */
        esDireccional(tecla) ||
        (tecla == 13 && input != 3)
      ) {  /* Direccional o ENTER sin estar en el botón */
        dir = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento("1_principal_registro", orden[dir][input]);
        input = orden[dir][input];
        switch(input) {
          case 0: usuario.clear();       break;
          case 1: clave.clear();         break;
          case 2: claveRepetida.clear(); break;
        } // Fin de limpiar cadenas
      } else if (esAlfaNum(tecla) // Tecla es alfanumérica
      && input != 3 // No es el botón 'Listo'
      && usuario.length() < 18 && clave.length() < 18
      && claveRepetida.length() < 18 /* Limitar longitud */) {
        switch(input) {
          case 0: // Usuario
            gotoxy(23,12); usuario += tecla; cout << usuario;
            gotoxy(23+usuario.length(),12);       break;
          case 1: // Contraseña
            gotoxy(23,17); clave += tecla; cout << asteriscos(clave);
            gotoxy(23+clave.length(),17);         break;
          case 2: // Repetir contraseña
            gotoxy(50,12); claveRepetida += tecla;
            cout << asteriscos(claveRepetida);
            gotoxy(50+claveRepetida.length(),12); break;
        } // Fin de capturar datos
      } else if (tecla == 8 || tecla == 224) { // 'BCKSP'-'DEL'
        switch(input) {
          case 0: // Usuario
            enfocarElemento("1_principal_registro", 0);
            usuario.clear();       break;
          case 1: // Contraseña
            enfocarElemento("1_principal_registro", 1);
            clave.clear();         break;
          case 2: // Contraseña
            enfocarElemento("1_principal_registro", 2);
            claveRepetida.clear(); break;
        } // Fin de resetear inputs actuales
      } else if (tecla == 13 && input == 3) {
        // Al presionar 'ENTER' registrar al nuevo usuario
        registroValido = /* validar formulario */
          ( nombreDisponible(usuario) &&
            clave.compare(claveRepetida) == 0 &&
            usuario.length() >= 6 &&
            clave.length() >= 6 );

        // Si el formulario es válido, registrar usuario
        if (registroValido) {
          // Ensamblar el nuevo registro
          nuevoUsuario = usuario + ";" + clave + ";cliente;0";
          // Insertarlo en la base de datos
          insertarRegistro("usuarios.txt", nuevoUsuario);
          system("cls"); cout << "Registro completado";
        } else {
          system("cls"); cout << "Registro invalido";
        } // Fin de verificar el envío de datos
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de agregar nuevos clientes
} // Fin de namespace menu::función