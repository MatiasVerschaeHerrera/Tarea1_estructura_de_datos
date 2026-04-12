#include "list.h"
#include "queue.h"
#include "extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("      Sistema de Gestión de Tareas");
  puts("========================================");

  puts("1) Nueva Categoría");
  puts("2) Eliminar Categoría");
  puts("3) Mostrar Categorías");
  puts("4) Registrar Tarea");
  puts("5) Atender Siguiente tarea");
  puts("6) Visualización De tareas");
  puts("7) Filtrado por Categoría");
  puts("8) Salir");
}

typedef struct{
  char nombre[101];
  char descripcion[201];
  char categoria[51];
  time_t horaRegistro;
} Tarea;

//caso 1
void registrar_categorias(List *categorias) {
  limpiarPantalla();
  printf("========================================\n");
  printf("       Registrar nueva Categoria\n");
  printf("========================================\n");
  
  char categoria[51];
  int valido;
  do{
    valido = 1;
    printf("Ingresa la categoria: ");
    if(fgets(categoria, sizeof(categoria), stdin)){
      // fgets lee hasta 50 caracteres + '\n', si no se encuentra '\n' significa que el usuario
      // escribio mas de 50 caracteres y el buffer se lleno
      if(strchr(categoria, '\n') == NULL){
        printf("Error: excede el maximo de caracteres permitidos.\n\n");
        int c;
        // elimino los caracteres sobrantes para que la proxima lectura no los lea
        while((c = getchar()) != '\n' && c != EOF);
        valido = 0;
      }
      else{
        // cambio el '\n' del fgets por un '\0' para eliminar el salto de linea
        categoria[strcspn(categoria, "\n")] = '\0';
        if(strlen(categoria) == 0){
          printf("Error: categoria vacia.\n");
          valido = 0;
        }
      }
    }
  }while(valido == 0);

  // Reviso la lista de categorias por completo, para no ingresar una categoria existente
  if(categorias != NULL){
    char *aux = list_first(categorias);

    while(aux != NULL){
      if(strcmp(aux, categoria) == 0){
        printf("Error: categoria existente.\n");
        return;
      }
      aux = list_next(categorias);
    }
  }

  // si es que la categoria a ingresar no existe, la agrego :)
  list_pushBack(categorias, strdup(categoria));
  printf("Categoria Agregada con Exito.\n");
}


//caso 2
void eliminar_categoria(List *categorias, List *listaTareas){
  limpiarPantalla();
  printf("========================================\n");
  printf("           Eliminar Categoria\n");
  printf("========================================\n");
  
  char *auxCategoria = list_first(categorias);
  if(auxCategoria == NULL){
    printf("La lista esta Vacia.\n");
    return;
  }

  char categoria[51];
  int valido;
  do{
    valido = 1;
    printf("Ingresa Categoria a Eliminar: ");
    if(fgets(categoria, sizeof(categoria), stdin)){
      // fgets lee hasta 50 caracteres + '\n', si no se encuentra '\n' significa que el usuario
      // escribio mas de 50 caracteres y el buffer se lleno
      if(strchr(categoria, '\n') == NULL){
        printf("Error: excede el maximo de caracteres permitidos.\n\n");
        int c;
        // elimino los caracteres sobrantes para que la proxima lectura no los lea
        while((c = getchar()) != '\n' && c != EOF);
        valido = 0;
      }
      else{
        // cambio el '\n' del fgets por un '\0' para eliminar el salto de linea
        categoria[strcspn(categoria, "\n")] = '\0';
        if(strlen(categoria) == 0){
          printf("Error: categoria vacia.\n");
          valido = 0;
        }
      }
    }
  }while(valido == 0);

  // recorro toda la lista para buscar si existe la categoria a elminar
  // el while termina cuando encuentra la categoria a eliminar o al recorrer la lista completa
  while(auxCategoria != NULL && strcmp(auxCategoria, categoria) != 0){
      auxCategoria = list_next(categorias);
  }

  // si no encuentra la categoria escribe un mensaje diciendo que no existe la categoria
  if(auxCategoria == NULL){
    printf("Error: no existe la categoria.\n");
    return;
  }
  // elimino la categoria y libero la memoria
  free(list_popCurrent(categorias));
  
  // ahora reviso si hay tareas con esa categoria
  if(listaTareas != NULL){
    Tarea *auxTareas = list_first(listaTareas);
    // recorro toda la lista de tareas
    while(auxTareas != NULL){
      // si encuentra una tarea con esa categoria la elimino y libero su memoria
      if(strcmp(categoria, auxTareas->categoria) == 0){
        free(list_popCurrent(listaTareas));
        // empiezo a recorrer nuevamente la lista
        auxTareas = list_first(listaTareas);
      }
      else auxTareas = list_next(listaTareas);
      
    }
  }
  printf("Categoria eliminada con exito.\n");
}


//caso 3
void mostrar_categorias(List *categorias) {
  limpiarPantalla();
  printf("========================================\n");
  printf("               Categorias\n");
  printf("========================================\n");
  
  char *aux = list_first(categorias);
  if(aux == NULL){
    printf("Error: no existen categorias.\n");
    return;
  }

  // muestra todas las categorias de la lista junto a un contador
  int cont = 1;
  while(aux != NULL){
    printf("%d) %s\n", cont, aux);
    aux = list_next(categorias);
    cont ++;
  }
}

//caso 4
void registrar_tarea(Queue *tareas, List *categorias){
  limpiarPantalla();
  printf("========================================\n");
  printf("         Registrar nueva Tarea\n");
  printf("========================================\n");

  Tarea *tarea = (Tarea *) malloc(sizeof(Tarea));

  //ingresar categoria
  char * auxCategoria;
  do{
    int valido;
    do{
      valido = 1;
      printf("Ingresa la categoria de la tarea: ");
      if(fgets(tarea->categoria, sizeof(tarea->categoria), stdin)){
        // fgets lee hasta 50 caracteres + '\n', si no se encuentra '\n' significa que el usuario
        // escribio mas de 50 caracteres y el buffer se lleno
        if(strchr(tarea->categoria, '\n') == NULL){
          printf("Error: excede el maximo de caracteres permitidos.\n\n");
          int c;
          // elimino los caracteres sobrantes para que la proxima lectura no los lea
          while((c = getchar()) != '\n' && c != EOF);
          valido = 0;
        }
        else{
          // cambio el '\n' del fgets por un '\0' para eliminar el salto de linea
          tarea->categoria[strcspn(tarea->categoria, "\n")] = '\0';
          if(strlen(tarea->categoria) == 0){
            printf("Error: categoria vacia.\n");
            valido = 0;
          }
        }
      }
    }while(valido == 0);

    // busco si existe la categoria a ingresar
    auxCategoria = list_first(categorias);
    while(auxCategoria != NULL){
      // recorro la lista por completo, si encuentra la categoria avanza al siguiente paso
      if(strcmp(auxCategoria, tarea->categoria) == 0){
        printf("Categoria ingresada con exito.\n");
        break;
      }
      auxCategoria = list_next(categorias);
    }
    // se recorrio por completo la lista y no se encontro la categoria
    if(auxCategoria == NULL){
      printf("Error: la categoria no existe.\n");
      printf("Ingrese una categoria existente.\n");
    }
  }while(auxCategoria == NULL);


  // ingresar nombre
  Tarea *auxNombre;
  do{
    int valido2;
    do{
      valido2 = 1;
      printf("\nIngresa el nombre de la tarea: ");
      if(fgets(tarea->nombre, sizeof(tarea->nombre), stdin)){
        // fgets lee hasta 100 caracteres + '\n', si no se encuentra '\n' significa que el usuario
        // escribio mas de 100 caracteres y el buffer se lleno
        if(strchr(tarea->nombre, '\n') == NULL){
          printf("Error: excede el maximo de caracteres permitidos.\n\n");
          int c;
          // elimino los caracteres sobrantes para que la proxima lectura no los lea
          while((c = getchar()) != '\n' && c != EOF);
          valido2 = 0;
        }
        else{
          // cambio el '\n' del fgets por un '\0' para eliminar el salto de linea
          tarea->nombre[strcspn(tarea->nombre, "\n")] = '\0';
          if(strlen(tarea->nombre) == 0){
            printf("Error: nombre vacio.\n");
            valido2 = 0;
          }
        }
      }
    }while(valido2 == 0);

    auxNombre = queue_front(tareas);
    // recorro la lista de tareas
    while(auxNombre != NULL){
      // reviso si ya existe una tarea con el mismo nombre en la categoria
      if((strcmp(auxNombre->nombre, tarea->nombre) == 0) && (strcmp(tarea->categoria, auxNombre->categoria) == 0)){
        printf("Error: la tarea ya existe.\n");
        printf("Ingrese otro nombre.\n");
        break;
      }
        auxNombre = queue_next(tareas);
    }
  }while(auxNombre != NULL);
  // si no existe una tarea con el mismo nombre en la categoria, avanzo al siguiente paso
  printf("Nombre ingresado con exito.\n");

  //ingresar descripcion
  int valido3;
  do{
    valido3 = 1;
    printf("\nIngresa la descripcion de la tarea: ");
    if(fgets(tarea->descripcion, sizeof(tarea->descripcion), stdin)){
      // fgets lee hasta 200 caracteres + '\n', si no se encuentra '\n' significa que el usuario
      // escribio mas de 200 caracteres y el buffer se lleno
      if(strchr(tarea->descripcion, '\n') == NULL){
        printf("Error: excede el maximo de caracteres permitidos.\n\n");
        int c;
        // elimino los caracteres sobrantes para que la proxima lectura no los lea
        while((c = getchar()) != '\n' && c != EOF);
        valido3 = 0;
      }
      else{
        // cambio el '\n' del fgets por un '\0' para eliminar el salto de linea
        tarea->descripcion[strcspn(tarea->descripcion, "\n")] = '\0';
        if(strlen(tarea->descripcion) == 0){
          printf("Error: descripcion vacia.\n");
          valido3 = 0;
        }
      }
    }
  }while(valido3 == 0);
  printf("Descripcion ingresado con exito.\n");

  // ingreso la hora
  tarea->horaRegistro = time(NULL);

  // guardo la tarea en la Lista de tareas
  queue_insert(tareas, tarea);
}

//caso 5
void atender_tarea(Queue *listaTareas){
  limpiarPantalla();
  printf("========================================\n");
  printf("             Atender Tarea\n");
  printf("========================================\n");
  
  Tarea *tareaActual = queue_front(listaTareas);

  // si la lista de tareas no contiene datos, escribo el mensaje de libre de pendientes
  if(tareaActual == NULL){
    printf("¡Libre de pendientes!\n");
    return;
  }
  // seteo el formato de la hora y fecha para verlo
  char bufferHora[26];
  // el formato es: hora:minutos dia/mes/año
  strftime(bufferHora, 26, "%H:%M %d/%m/%Y", localtime(&tareaActual->horaRegistro));

  // imprimo los datos de la tarea
  printf("\nAtendiendo: %s.\n", tareaActual->nombre);
  printf("Descripcion: %s.\n", tareaActual->descripcion);
  printf("Categoría: %s.\n", tareaActual->categoria);
  printf("Hora y fecha de ingreso: %s\n", bufferHora);

  // pregunto si se realizo la tarea
  // esta con un do para que solo se pueda responder con un "Si" o un "No"
  char respuesta[10];
  do{
    printf("\n¿Realizo la tarea? (Si/No): ");
    if(fgets(respuesta, sizeof(respuesta), stdin)){
      if(strchr(respuesta, '\n') == NULL){
        int c;
        while((c = getchar()) != '\n' && c != EOF);
      }
      respuesta[strcspn(respuesta, "\n")] = '\0';
    }
  }while(strcmp(respuesta, "Si") != 0 && strcmp(respuesta, "No") != 0);

  // si la respuesta es "Si" elimino la tarea
  if(strcmp(respuesta, "Si") == 0){
    free(queue_remove(listaTareas));
    printf("Tarea realizada!!!.\n");
    return;
  }
  // si la respuesta es "No", digo que vuelva cuando este hecha
  else{
    printf("Vuelva cuando realice la tarea.\n");
    return;
  }
}

//caso 6
void ver_tareas(Queue *listaTareas){
  limpiarPantalla();
  printf("========================================\n");
  printf("           Tareas sin realizar\n");
  printf("========================================\n");

  // el contador es para enumerar las tareas y para saber si existen tareas
  int cont = 1;
  Tarea *auxTarea = queue_front(listaTareas);
  char bufferHora[26];

  // recorro la lista para imprimir las tareas faltantes
  while(auxTarea != NULL){
    strftime(bufferHora, 26, "%H:%M %d/%m/%Y", localtime(&auxTarea->horaRegistro));
    printf("%d) nombre: %s\n   categoria: %s\n   Ingreso: %s\n\n", cont, auxTarea->nombre, auxTarea->categoria, bufferHora);
    cont++;
    auxTarea = queue_next(listaTareas);
  }
  // si el contador no aumenta, significa que no hay tareas
  if(cont-1 == 0) printf("No hay tareas a realizar.\n");
}

//caso 7
void ver_por_categoria(List *listaCategorias, Queue *listaTareas){
  limpiarPantalla();
  printf("========================================\n");
  printf("            Ver por categoria\n");
  printf("========================================\n");

  // si la lista de categorias esta vacia, informo que no existen categorias
  if(listaCategorias == NULL){
    printf("No extisten categorias");
    return;
  }
  
  char *auxCategoria;
  char categoriaVer[51];
  do{
    int valido;
    do{
      valido = 1;
      printf("Ingresa la categoria: ");
      if(fgets(categoriaVer, sizeof(categoriaVer), stdin)){
        // fgets lee hasta 50 caracteres + '\n', si no se encuentra '\n' significa que el usuario
        // escribio mas de 50 caracteres y el buffer se lleno
        if(strchr(categoriaVer, '\n') == NULL){
          printf("Error: excede el maximo de caracteres permitidos.\n\n");
          int c;
          // elimino los caracteres sobrantes para que la proxima lectura no los lea
          while((c = getchar()) != '\n' && c != EOF);
          valido = 0;
        }
        else{
          // cambio el '\n' del fgets por un '\0' para eliminar el salto de linea
          categoriaVer[strcspn(categoriaVer, "\n")] = '\0';
          if(strlen(categoriaVer) == 0){
            printf("Error: categoria vacia.\n");
            valido = 0;
          }
        }
      }
    }while(valido == 0);

    // recorro la lista de categorias, para ver contiene la categoria a revisar
    auxCategoria = list_first(listaCategorias);
    while(auxCategoria != NULL){
      // encuentro la categoria a revisar
      if(strcmp(categoriaVer, auxCategoria) == 0) break;
      auxCategoria = list_next(listaCategorias);
    }
    if(auxCategoria == NULL){
      printf("Error: la categoria no existe.\n");
      printf("Escriba una categoria existente\n");
    }
  }while(auxCategoria == NULL);

  Tarea *auxTarea = queue_front(listaTareas);
  int cont = 1;
  // reviso si existe una tarea con esa categoria y la imprimo con un contador
  while(auxTarea != NULL){
    if(strcmp(auxTarea->categoria, categoriaVer) == 0){
    printf("%d) nombre de la tarea: %s\n", cont, auxTarea->nombre);
    cont++;
    }
    auxTarea = queue_next(listaTareas);
  }
  if(cont - 1 == 0) printf("No hay tareas con esta categoria.\n");
}

int main() {
  // setear hora del programa a la de chile
  // esto lo tuve que hacer, ya que, replit esta seteado en otra zona horaria
  setenv("TZ", "America/Santiago", 1);
  tzset();
  
  char opcion;
  List *categorias = list_create(); // Lista para almacenar categorías
  Queue *tareas = queue_create(NULL); // Cola para almacenar las tareas
  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    // limpia el buffer de entrada despues de leer la opcion del menu con scanf
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    switch (opcion) {
    case '1':
      registrar_categorias(categorias);
      break;
    case '2':
      eliminar_categoria(categorias, tareas);
      break;
    case '3':
      mostrar_categorias(categorias); 
      break;
    case '4':
      registrar_tarea(tareas, categorias);
      break;
    case '5':
      atender_tarea(tareas);
      break;
    case '6':
      ver_tareas(tareas);
      break;
    case '7':
      ver_por_categoria(categorias, tareas);
      break;
    case '8':
      puts("Saliendo del sistema de gestión de Tareas...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '8');

  // Libero la memoria de cada dato de la lista de categorias y libero la memoria de la lista
  char *categoria = list_first(categorias);
  while(categoria != NULL){
    free(categoria);
    categoria = list_next(categorias);
  }
  list_clean(categorias);

  // Libero la memoria de cada dato de la cola de tareas y libero la memoria de la cola
  Tarea *tarea = queue_front(tareas);
  while(tarea != NULL){
    free(tarea);
    tarea = queue_next(tareas);
  }
  queue_clean(tareas);

  return 0;
}
