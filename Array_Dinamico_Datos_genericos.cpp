#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename U> class BaseDinamicArray {
private:
  int tam;

public:
  U *lista;
  BaseDinamicArray();
  BaseDinamicArray(U[], int);
  BaseDinamicArray(const BaseDinamicArray &);
  int getTam() const;
  void setTam(int);
  void pushback(U valor);
  void insertar(int posicion, U valor);
  void remover(int posicion);
  void mostrar() {
    for (int i = 0; i < tam; i++) {
      cout << lista[i] << " ";
    }
    cout << endl;
  }
};
// C   O   N  S   T   R   U   C   T  O   R ---------------------------
template <typename U> BaseDinamicArray<U>::BaseDinamicArray() {
  this->tam = 0;
  this->lista = new U[tam];
}
template <typename U> BaseDinamicArray<U>::BaseDinamicArray(U l[], int t) {
  this->tam = t;
  this->lista = new U[tam];
  for (int i = 0; i < tam; i++) {
    lista[i] = l[i];
  }
}
template <typename U>
BaseDinamicArray<U>::BaseDinamicArray(const BaseDinamicArray &o) {
  this->tam = o.getTam();
  for (int i = 0; i < tam; i++) {
    this->lista[i] = o.lista[i];
  }
}
// G   E   T  &   S   E   T
template <typename U> int BaseDinamicArray<U>::getTam() const { return tam; }
template <typename U> void BaseDinamicArray<U>::setTam(int a) { this->tam = a; }
// P   R   O  C   E   D   I   M   I   E   N   T   O
template <typename U> void BaseDinamicArray<U>::pushback(U valor) {
  tam++;
  // copia auxiliar con el nuevo valor
  U *temp = new U[tam];
  for (int i = 0; i < tam - 1; i++) {
    temp[i] = this->lista[i];
  }
  temp[tam - 1] = valor;
  // liberando lista y dandole nuevos valores
  delete[] lista;
  lista = temp;
}

template <typename U>
void BaseDinamicArray<U>::insertar(int posicion, U valor) {
  tam++;
  // copia temporal con el nuevo valor
  U *temp = new U[tam];
  for (int i = 0; i < tam; i++) {
    if (i < posicion) {
      temp[i] = lista[i];
    } else if (i == posicion) {
      temp[i] = valor;
    } else {
      temp[i] = lista[i - 1];
    }
  }
  // liberando lista y dandole nuevos valores
  delete[] lista;
  lista = temp;
}

template <typename U> void BaseDinamicArray<U>::remover(int posicion) {
  tam--;
  // creamos la lista temporal con el dato removido
  U *temp = new U[tam];
  for (int i = 0; i < tam; i++) {
    if (i < posicion) {
      temp[i] = lista[i];
    } else {
      temp[i] = lista[i + 1];
    }
  }
  // liberamos y reemplazamos lista
  delete[] lista;
  lista = temp;
}
// // // // // // // // // // // // // // // // // // // // // //
class Punto {
private:
  int x;
  int y;

public:
  Punto() : x(0), y(0) {}
  Punto(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

  friend ostream &
  operator<<(ostream &os,
             Punto punto) { // friend para que pueda acceder a datos privados
    os << "(" << punto.x << " ; " << punto.y << ")";
    return os; // os es una referencia para que pueda devolver el valor
               // designado saliendo de la función
  }
};

int main(int argc, char *argv[]) {
  BaseDinamicArray<int> a;
  a.pushback(18);
  a.pushback(8);
  a.mostrar();
  cout << "añadimos 22 a la posición 1" << endl;
  a.insertar(1, 22);
  a.mostrar();
  cout << "eliminamos el valor de la posición 2 de la lista" << endl;
  a.remover(2);
  a.mostrar();
  delete[] a.lista;
  cout << "/ / / / / / / / / / / / / / / / / / / / / / / / / / / / " << endl;
  BaseDinamicArray<char> b;
  b.pushback('a');
  b.pushback('v');
  b.mostrar();
  cout << "añadimos 'b' a la posición 1" << endl;
  b.insertar(1, 'b');
  b.mostrar();
  cout << "eliminamos el valor de la posición 2 de la lista" << endl;
  b.remover(2);
  b.mostrar();
  delete[] b.lista;

  cout << "/ / / / / / / / / / / / / / / / / / / / / / / / / / / / " << endl;
  BaseDinamicArray<Punto> c;
  Punto m(1, 8);
  Punto n(12, 5);
  Punto o(-4, 9);
  c.pushback(m);
  c.pushback(n);
  c.mostrar();
  cout << "añadimos o(-4;9) a la posición 1" << endl;
  c.insertar(1, o);
  c.mostrar();
  cout << "eliminamos el valor de la posición 2 de la lista" << endl;
  c.remover(2);
  c.mostrar();
  delete[] c.lista;
  return 0;
}
