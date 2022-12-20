
Compile el programa con: g++ *.cpp -o a
Para Valgrind:  valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./a
Dentro de la misma carpeta debe estar Autores.txt y Lecturas.txt
Corra el programa
Linux/macOS:  ./a


* Object Oriented Programming (OOP).
* Inheritance and polymorphism.
* Use of dynamic memory.
* Handling .TXT files (Autores.txt, Lecturas.txt)
* The management and temporary and dynamic storage of data is done through Lists, Graphs and Queues, the latter for the creation of the method next readings.
* Creates a reading list, on which both the read queue (for the next reads option) and the read graph (for the minimum spanning tree option) are based, along with the class Prim which is the class to be read. It is mainly responsible for executing Prim's algorithm.
* Create a Hash table for writer stores.
* The practical work was designed and implemented in Linux.
* Using the repository: github.com/liuvaneshka/tp3
