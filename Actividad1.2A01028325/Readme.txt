Documentacion:
En este programa se incluyen diferentes clases, se incluye una clase que te permite hacer búsquedas en un vector de tipo T 
llamada busquedasE, también se incluyen unas clases que realizan ordenamientos de diferentes tipos estas clases se llaman 
BubbleSort, InsertionSort y QuickSort estas clases herdean de la clase padre Sorter. bubbleSort es un algoritmo que organisa 
un vector, prinsipalmente funciona intercambiando dos elemntos a lo largo de una lista, tiene una complejidad de O(n^2), 
ya que este algoritmo en el peor de los casos recorre toda la lista al cuadrado, ya que es un for loop anidado. insertion Sort 
es mejor en el medio y mejor de los casos ya que genra una lista de elementos ordenados y una de desordenados, por lo cual 
cuando encuntra la posicion adecada de un numero en la lista ordenada se detiene ya que el resto de la lista esta ordenada, 
en el peor de los casos va a tener una complejidad temporal O(n^2) porque si los numeros estan invertidos en la lista ordenada 
el nuevo numero va a ser menor a todos en la lista ordenada. QuickSort es un algoritmo de la clase divide y vencerás ya que este 
divide el input cada vez a la mitad hasta llegar a elementos únicos debido a esto normalmente tiene una complejidad de nlog(n) 
pero el peor de los casos va a tener una complejidad O(n^2).

Los algoritmos que se utilizaron para las búsquedas fue la búsqueda secuencial y la búsqueda binaria. La búsqueda secuencial 
tiene una complejidad de O(n), ya que este algoritmo compara todos los elementos de una lista al elemento buscado por lo cual 
siempre recorre todo el imput. La búsqueda es un algoritmo de tipo dibide y venceras  corta la lista a la mitad por cada 
secuencia que tiene y dependiendo de si el punto en el que se encuentra es mayor o menor al resultado que se está buscando 
va a escoger ir a la izquierda la derecha, cómo corta el input a la mitad cada vez que se ejecuta funciona con una complejidad 
temporal de O(log(n)) la cual si se busca en una tabla de complejidades temporales es una de las menores complejidades que hay.


casos de prueba:

caso 1:

De que tamaño queres la lista para trabajar
20
Cuantas veces quieres buscar
2
Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort.
1
tiempo de procesado con Bubble Sort time:       2.255e-05 seconds (3.75833e-07min)      2.255e-05 sec average across 1 runs.
0, 1, 2, 2, 6, 6, 8, 11, 12, 13, 14, 14, 15, 15, 15, 15, 15, 16, 17, 18, 

Que numero quieres busacar
2
indice en el que se encuentra con busqueda secuencial: 2
tiempo de procesado time:       7.1851e-05 seconds (1.19752e-06min)     7.1851e-05 sec average across 1 runs.

indice en el que se encuentra con busqueda binaria: 2
tiempo de procesado time:       9.549e-06 seconds (1.5915e-07min)       9.549e-06 sec average across 1 runs.

Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort.
2
tiempo de procesado con Incertion Sort time:    2.435e-06 seconds (4.05833e-08min)      2.435e-06 sec average across 1 runs.
0, 1, 2, 2, 6, 6, 8, 11, 12, 13, 14, 14, 15, 15, 15, 15, 15, 16, 17, 18, 

Que numero quieres busacar
11
indice en el que se encuentra con busqueda secuencial: 7
tiempo de procesado time:       0.000157704 seconds (2.6284e-06min)     0.000157704 sec average across 1 runs.

indice en el que se encuentra con busqueda binaria: 7
tiempo de procesado time:       4.026e-06 seconds (6.71e-08min) 4.026e-06 sec average across 1 runs.

caso 2:

De que tamaño queres la lista para trabajar
10
Cuantas veces quieres buscar
1
Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort.
2
tiempo de procesado con Incertion Sort time:    3.395e-06 seconds (5.65833e-08min)      3.395e-06 sec average across 1 runs.
1, 2, 2, 3, 4, 4, 4, 7, 7, 7, 

Que numero quieres busacar
7
indice en el que se encuentra con busqueda secuencial: 7
tiempo de procesado time:       3.3803e-05 seconds (5.63383e-07min)     3.3803e-05 sec average across 1 runs.

indice en el que se encuentra con busqueda binaria: 7
tiempo de procesado time:       9.272e-06 seconds (1.54533e-07min)      9.272e-06 sec average across 1 runs.

caso 3: 

De que tamaño queres la lista para trabajar
5
Cuantas veces quieres buscar
1
Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort.
3
tiempo de procesado con Quick Sort time:        2.815e-06 seconds (4.69167e-08min)      2.815e-06 sec average across 1 runs.
0, 1, 1, 2, 3, 

Que numero quieres busacar
5
indice en el que se encuentra con busqueda secuencial: -1
tiempo de procesado time:       3.475e-05 seconds (5.79167e-07min)      3.475e-05 sec average across 1 runs.

indice en el que se encuentra con busqueda binaria: -1
tiempo de procesado time:       8.2664e-05 seconds (1.37773e-06min)     8.2664e-05 sec average across 1 runs.

caso 4: 

De que tamaño queres la lista para trabajar
100
Cuantas veces quieres buscar
3
Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort.
1
tiempo de procesado con Bubble Sort time:       0.000565388 seconds (9.42313e-06min)    0.000565388 sec average across 1 runs.
1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 6, 7, 7, 7, 8, 9, 13, 14, 14, 15, 16, 19, 21, 22, 24, 25, 25, 28, 29, 31, 31, 32, 33, 33, 34, 
36, 37, 39, 39, 40, 40, 40, 42, 43, 43, 43, 45, 46, 46, 46, 47, 47, 49, 49, 50, 51, 51, 51, 53, 55, 55, 56, 57, 58, 58, 61, 63, 
63, 64, 64, 65, 65, 67, 68, 68, 69, 71, 73, 73, 74, 76, 77, 77, 78, 82, 82, 85, 88, 89, 90, 90, 92, 94, 94, 96, 96, 97, 98, 98, 

Que numero quieres busacar
4
indice en el que se encuentra con busqueda secuencial: 10
tiempo de procesado time:       5.8535e-05 seconds (9.75583e-07min)     5.8535e-05 sec average across 1 runs.

indice en el que se encuentra con busqueda binaria: 10
tiempo de procesado time:       8.213e-06 seconds (1.36883e-07min)      8.213e-06 sec average across 1 runs.

Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort.
2
tiempo de procesado con Incertion Sort time:    4.312e-06 seconds (7.18667e-08min)      4.312e-06 sec average across 1 runs.
1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 6, 7, 7, 7, 8, 9, 13, 14, 14, 15, 16, 19, 21, 22, 24, 25, 25, 28, 29, 31, 31, 32, 33, 33, 34, 
36, 37, 39, 39, 40, 40, 40, 42, 43, 43, 43, 45, 46, 46, 46, 47, 47, 49, 49, 50, 51, 51, 51, 53, 55, 55, 56, 57, 58, 58, 61, 63, 
63, 64, 64, 65, 65, 67, 68, 68, 69, 71, 73, 73, 74, 76, 77, 77, 78, 82, 82, 85, 88, 89, 90, 90, 92, 94, 94, 96, 96, 97, 98, 98, 

Que numero quieres busacar
20
indice en el que se encuentra con busqueda secuencial: -1
tiempo de procesado time:       8.7307e-05 seconds (1.45512e-06min)     8.7307e-05 sec average across 1 runs.

indice en el que se encuentra con busqueda binaria: -1
tiempo de procesado time:       1.2074e-05 seconds (2.01233e-07min)     1.2074e-05 sec average across 1 runs.

Por cual metodo quieres ordenar: 1) Bubble sort, 2) Incertion sort, 3) Quick sort.
3
tiempo de procesado con Quick Sort time:        0.000117813 seconds (1.96355e-06min)    0.000117813 sec average across 1 runs.
1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 6, 7, 7, 7, 8, 9, 13, 14, 14, 15, 16, 19, 21, 22, 24, 25, 25, 28, 29, 31, 31, 32, 33, 33, 34, 
36, 37, 39, 39, 40, 40, 40, 42, 43, 43, 43, 45, 46, 46, 46, 47, 47, 49, 49, 50, 51, 51, 51, 53, 55, 55, 56, 57, 58, 58, 61, 63, 
63, 64, 64, 65, 65, 67, 68, 68, 69, 71, 73, 73, 74, 76, 77, 77, 78, 82, 82, 85, 88, 89, 90, 90, 92, 94, 94, 96, 96, 97, 98, 98, 

Que numero quieres busacar
69
indice en el que se encuentra con busqueda secuencial: 76
tiempo de procesado time:       2.4348e-05 seconds (4.058e-07min)       2.4348e-05 sec average across 1 runs.

indice en el que se encuentra con busqueda binaria: 76
tiempo de procesado time:       6.907e-06 seconds (1.15117e-07min)      6.907e-06 sec average across 1 runs.