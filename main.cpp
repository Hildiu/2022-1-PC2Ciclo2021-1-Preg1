#include <iostream>
using namespace std;

string * dimensionaArray(int n);
bool esta(string nombre, string *pA,int num);
void leeNombres(string * pA, int nd);
void imprimir(string * pA, int n);
void  imprimirParejas(string *aDamas,int nd,string *aVarones,int nv);
void eliminarMemoria(string * &pA);

int main()
{
  int nd, nv;
  string *aDamas= nullptr, *aVarones= nullptr;

  cout << "Numero de damas : "; cin>>nd;
  cout << "Numero de varones : "; cin>>nv;
  cout << "\n";
  cout << "Nombre de Damas: "<< "\n";
  aDamas=dimensionaArray(nd);
  leeNombres(aDamas,nd);
  cout << "\n";
  cout << "Nombre de Varones: "<< "\n";
  aVarones=dimensionaArray(nv);
  leeNombres(aVarones,nv);
  cout << "\nNombres registrados:\n";
  imprimir(aDamas,nd);
  cout << "\nNombres registrados:\n";
  imprimir(aVarones,nv);
  cout << "\nParejas posibles:\n";
  imprimirParejas(aDamas,nd,aVarones,nv);
  eliminarMemoria(aDamas);
  eliminarMemoria(aVarones);
  return 0;
}

string * dimensionaArray(int n)
{
  return new string[n];
}

bool esta(string nombre, string *pA,int num)
{
  for(int i=0; i<num; i++)
    if (nombre == pA[i])
      return true;
  return false;
}

void leeNombres(string * pA, int nd)
{ int i;
  string nombre;

  i=0;
  while(i<nd) {
    do {
      cout << "Nombre  " << i+1<< ": ";
      cin >> nombre;
    } while (esta(nombre, pA, i));
    pA[i] = nombre;
    i++;
  }
}

void imprimir(string * pA, int n)
{
  for(int i=0; i<n; i++)
    cout << pA[i] << "\n";
}

void  imprimirParejas(string *aDamas,int nd,string *aVarones,int nv)
{
  for(int id=0; id<nd;id++)
    for(int iv=0;iv<nv;iv++ )
      cout << aDamas[id] << "  " << aVarones[iv] << "\n";
}

void eliminarMemoria(string * &pA)
{
  delete []pA;
  pA= nullptr;
}


