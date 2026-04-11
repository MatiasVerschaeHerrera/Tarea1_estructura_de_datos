# SISTEMA DE GESTION DE TAREAS

# Descripcion

Este sistema permite a los usuarios registrar  y gestionar las tareas. Los usuarios pueden crear y eliminar categorias, 
ingresar las tareas por categoria y atender las tareas. Este programa fue diseño para mejorar la eficiencia de las tareas de los usuarios,
asegurando que atiendan todas las tareas por orden de llegada.

# Como compilar y ejecutar

Este sistema fue desarrollado en lenguaje C, se puede ejecutar usando **Visual Studio Code** junto con una extension
para **C/C++ Extension Pack** de Microsfot.
Para comenzar a trabajar con el sistema, sigue estos pasos:

# Requisitos previos:

1. Tener instalado Visual Studio Code.
2. Instalar la extension C/C++ (Microsoft).
3. Tener instalado un compilador de C (como gcc).

# Pasos para compilar y ejecutar:

1. Descarga y comprime el archivo `.zip` en una carpeta de tu eleccion.
2. Abre el proyecto en Visual Studio Code.
- Incia Visual Studio Code.
- Selecciona `Archivo > Abrir carpeta...` y elige la carpeta donde descomprimiste el proyecto.
3. Compila el codigo:
- Abre el archivo principal (`tarea1.c`).
- Abre la terminal integrada (`terminal > Nueva terminal`).
- En la terminal, compila el programa con el siguiente comando:
```
gcc *.c -0 tarea1
```
4. Ejecuta el programa:
- Una vez compilado, puedes ejecutar la aplicacion con:
```
./tarea1
```

# Funcionalidades

# Funcionando Correctamente:
- Crear categorias.
- Eliminar categorias junto a las tareas que esten en ella.
- Mostrar todas las categorias creadas.
- Registrar tareas, guardando su nombre, descripcion, categoria, hora y fecha de ingreso.
- Atender tareas en orden de primera ingresada.
- Mostrar todas las tareas por realizar.
- Mostrar las tareas filtrando por categoria.

# problemas conocidos
- Si me paso de los caracteres permitidos al momento de ingresar los datos, el programa suelta error.

# A mejorar
- Permitir la personalizacion de tareas una vez creadas.
- Mejorar la interfaz para el usuario.

# Ejemplo de uso
 
# Paso 1: Registrar una nueva categoria
Se comienza creando una categoria para las tareas.
```
Opcion seleccionada: 1) Nueva Categoria
Ingrese la categoria: Universidad
Categoria Agregada con Exito. 
```
El sistema registra la categoria Universidad. 

# Paso 2: Registar una nueva tarea
Teniendo una categoria agregada, puedo registar tareas en esa categoria.
```
Opcion seleccionada: 4) Registrar tarea
Ingresa el categoria de la tarea: Universidad
Categoria ingresa con exito. 
Ingresa el nombre de la tarea: Tarea estructura de datos
Nombre ingresado con exito.
Ingresa la descripcion de la tarea: Entregar para el dia 12 de abril
Descripcion ingresada con exito.
```
El sistema va verificando, si se ingreso correctamente la informacion. Luego la ingresa en la categoria.

# Paso 3: Visualizacion de tareas
El usuario puede visualizar todas las tareas registras.
```
Opcion seleccionada: 6) Visualizacion de Tareas
1) nombre: Tarea estructura de datos
   categoria: Universidad
   Ingreso: 11:28 11/04/2026
   ```


# paso 4: Atender siguiente tarea
El usuario informa si realizo la tarea
```
Opcion seleccionada: 5) Atender Siguiente Tarea
Atendiendo: Tarea estructura de datos.
Descripcion: entregar para el dia 12 de abriil.
Categoria: Universidad.
Hora y fecha de ingreso: 11:28 11/04/2026

¿Realizo la tarea? (Si/No): Si
Tarea realizada!!!
```
El sistema muestra la informacion de la tarea a realiazar y pregunta si se completo, para eliminarla

