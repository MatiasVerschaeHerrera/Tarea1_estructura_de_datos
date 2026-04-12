# SISTEMA DE GESTIÓN DE TAREAS

# Descripción

Este sistema permite a los usuarios registrar  y gestionar las tareas. Los usuarios pueden crear y eliminar categorías, 
ingresar las tareas por categoría y atender las tareas. Este programa fue diseñado para mejorar la eficiencia de las tareas de los usuarios,
asegurando que se atiendan según su orden de llegada.

# Como compilar y ejecutar

Este sistema fue desarrollado en lenguaje C y se puede ejecutar usando **Visual Studio Code** junto con una extension
para **C/C++ Extension Pack** de Microsfot.

Para comenzar a trabajar con el sistema, sigue estos pasos:

# Requisitos previos:

1. Tener instalado Visual Studio Code.
2. Instalar la extension C/C++ (Microsoft).
3. Tener instalado un compilador de C (como gcc).

# Pasos para compilar y ejecutar:

1. Descarga y comprime el archivo `.zip` en una carpeta de tu elección.
2. Abre el proyecto en Visual Studio Code.
- Inicia Visual Studio Code.
- Selecciona `Archivo > Abrir carpeta...` y elige la carpeta en la que descomprimiste el proyecto.
3. Compila el codigo:
- Abre el archivo principal (`tarea1.c`).
- Abre la terminal integrada (`terminal > Nueva terminal`).
- En la terminal, compila el programa con el siguiente comando:
```
gcc *.c -o tarea1
```
4. Ejecuta el programa:
- Una vez compilado, puedes ejecutar la aplicación con:
```
./tarea1
```

# Funcionalidades

# Funcionando Correctamente:
- Crear categorías.
- Eliminar categorías junto a las tareas que esten en ella.
- Mostrar todas las categorías creadas.
- Registrar tareas, guardando su nombre, descripción, categoría, hora y fecha de ingreso.
- Atender tareas según su orden de ingreso.
- Mostrar todas las tareas por realizar.
- Mostrar las tareas filtrando por categoría.

# A mejorar
- Permitir la personalización de tareas una vez creadas.
- Mejorar la interfaz para el usuario.

# Ejemplo de uso
 
# Paso 1: Registrar una nueva categoría
Se comienza creando una categoría para las tareas.
```
Opción seleccionada: 1) Nueva Categoría
Ingrese la categoría: Universidad
Categoría Agregada con Exito. 
```
El sistema registra la categoría Universidad. 

# Paso 2: Registrar una nueva tarea
Teniendo una categoría agregada, puede registrar tareas en esa categoría.
```
Opción seleccionada: 4) Registrar tarea
Ingresa el categoría de la tarea: Universidad
Categoría ingresa con éxito. 

Ingresa el nombre de la tarea: Tarea estructura de datos
Nombre ingresado con éxito.

Ingresa la descripción de la tarea: Entregar para el dia 12 de abril
Descripción ingresada con éxito.
```
El sistema va verificando, si se ingresó correctamente la información. Luego la ingresa en la categoría.

# Paso 3: Visualización de tareas
El usuario puede visualizar todas las tareas registradas.
```
Opción seleccionada: 6) Visualización de Tareas
1) nombre: Tarea estructura de datos
   categoría: Universidad
   Ingreso: 11:28 11/04/2026
   ```
El sistema muestra todas las tareas registradas en orden de ingreso.


# Paso 4: Atender siguiente tarea
El usuario informa si realizó la tarea
```
Opción seleccionada: 5) Atender Siguiente Tarea
Atendiendo: Tarea estructura de datos.
Descripción: entregar para el día 12 de abril.
Categoría: Universidad.
Hora y fecha de ingreso: 11:28 11/04/2026

¿Realizó la tarea? (Si/No): Si
Tarea realizada!!!
```
El sistema muestra la información de la tarea a realizar y pregunta si se completó, para eliminarla.