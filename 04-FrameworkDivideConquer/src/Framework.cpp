
#include "Framework.h"

Framework::Framework() {}

Framework::~Framework() {}

void Framework::divideyVenceras(Problema* p, Solucion* s) {
  if (p->isCasoMinimo()) {
    p->solver(s);
  } else {
    std::pair<Problema*, Problema*> subProblemas;
    std::pair<Solucion*, Solucion*> subSoluciones;
    subProblemas = p->descomponer();
    subSoluciones.first = s->getInstance();
    subSoluciones.second = s->getInstance();
    divideyVenceras(subProblemas.first, subSoluciones.first);    //.1
    divideyVenceras(subProblemas.second, subSoluciones.second);  //.2
    s->mezcla(subSoluciones);
  }
};
