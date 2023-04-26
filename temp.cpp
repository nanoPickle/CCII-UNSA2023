#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class DinamicIntegerArray {
public:
  int pos;
  int *lista;
  int tam;
  DinamicIntegerArray(int primer_elemento);
  void pushback(int valor);
  void insertar(int posicion, int valor);
  void remover(int posicion);
  void mostrar() {
    for (int i = 0; i < tam; i++) {
      cout << lista[i] << " ";
    }
    cout << endl;
  }
};
DinamicIntegerArray::DinamicIntegerArray(int primer_elemento) {
  tam = 1;
  lista = new int[tam];
  lista[0] = primer_elemento;
}
void DinamicIntegerArray::pushback(int valor) {
  tam++;
  // copia auxiliar
  int temp[tam];
  for (int i = 0; i < tam - 1; i++) {
    temp[i] = lista[i];
  }
  // liberando lista y dandole nuevo tamaño
  delete lista;
  lista = new int[tam];
  // reasignando valores a la lista
  for (int j = 0; j < tam; j++) {
    if (j == tam - 1) {
      lista[j] = valor; // se añade el nuevo valor
    } else {
      lista[j] = temp[j];
    }
  }
}

void DinamicIntegerArray::insertar(int posicion, int valor) {
  tam++;
  // copia temporal con el valor insertado
  int temp[tam];
  for (int i = 0; i < tam; i++) {
    if (i < posicion) {
      temp[i] = lista[i];
    } else if (i == posicion) {
      temp[i] = valor;
    } else {
      temp[i] = lista[i - 1];
    }
  }
  // liberando lista y dandole nuevo tamaño
  delete lista;
  lista = new int[tam];
  // reasignando valores a la lista
  for (int j = 0; j < tam; j++) {
    lista[j] = temp[j];
  }
}

void DinamicIntegerArray::remover(int posicion) {
  tam--;
  // creamos la lista temporal con el dato removido
  int temp[tam];
  for (int i = 0; i < tam; i++) {
    if (i < posicion) {
      temp[i] = lista[i];
    } else {
      temp[i] = lista[i + 1];
    }
  }
  // liberamos y reespaciamos lista
  delete lista;
  lista = new int[tam];
  // reasignamos valores
  for (int j = 0; j < tam; j++) {
    lista[j] = temp[j];
  }
}

int main(int argc, char *argv[]) {
  DinamicIntegerArray a(7);
  a.pushback(18);
  a.pushback(8);
  a.mostrar();
  cout << "añadimos 22 a la posición 1" << endl;
  a.insertar(1, 22);
  a.mostrar();
  cout << "eliminamos el valor de la posición 2 de la lista" << endl;
  a.remover(2);
  a.mostrar();
  delete a.lista;

  return 0;
}
