#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

//ejercicios de punteros y arreglos

/*
Ejercicio 1.
Programe la función void swap(int *a, int *b), la cual
intercambia los valores de las variables apuntadas por a y b.
*/
void swap(int *a, int *b) 
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

/*
Ejercicio 2.
Programe la función void arrayMaxMin(int *a, int n, int *max, int *min),
la cual encuentra el máximo y el mínimo valor del arreglo a y los
almacena en las variables apuntadas por max y min.
*/
void arrayMaxMin(int *a, int n, int *max, int *min) 
{
   *max = a[0];
   *min = a[0];

   for (size_t k = 0 ; k < n ; k++)
   {
      if (a[k] > *max)
      {
         *max = a[k];
      }
      if (a[k] < *min)
      {
         *min = a[k];
      }
   } 
 
}


/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos ingresados como parámetros y retorna un puntero 
al dato recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
   Persona * p = (Persona *) malloc(sizeof(Persona));
   //asignar valores de entrada a los campos de p
   strcpy(p->nombre, nombre);
   strcpy(p->rut, rut);
   p->edad = edad;

   return p;
}

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int *datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector * crearVector(int n)
{
   Vector *vector = (Vector *) malloc(sizeof(Vector));
   vector->datos = (int *) calloc(n, sizeof(int));
   vector->capacidad = n; 
   return vector;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor)
{
   /*if (i < 0 || i >= v->capacidad)
   {
      printf("error: la posicion esta fuera del tamaño del vector");
      return;
   }*/
   v->datos[i] = valor; //asumiendo que el "indice" esta dentro del tamaño del vector, sino descomentar el codigo superior

}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i)
{
   return v->datos[i]; //el mismo comentario de arriba
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) {

}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1+b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c)
{
   Vector* a = crearVector(2);
   Vector* b = crearVector(2);//creamos vectores

   asignarValor (a, 0, a1); //usamos la funcion asignar valores para...asignar valores
   asignarValor (a, 1, a2);
   asignarValor (b, 0, b1);
   asignarValor (b, 1, b2);

   sumaV (a, b, c);

   free(a->datos); //liberamos memoria del arreglo dinámico "a"
   free(a); //liberamos memoria de a
   free(b->datos); // "" b
   free(b); // "" b
}
