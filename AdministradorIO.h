
#ifndef ADMINISTRADORIO_H
#define ADMINISTRADORIO_H

#include "Arduino.h"

class AdministradorIO{

  int * valores_pines_digitales;
  int * valores_pines_analogicos;

  int * funcion_pines_digitales;
  int * funcion_pines_analogicos;

  unsigned int * x_digitales;
  unsigned int * x_analogicos;

  int n_digitales;
  int n_analogicos;

  public:

    AdministradorIO(int cantidad_pines_digitales, int cantidad_pines_analogicos);
    AdministradorIO(int cantidad_pines_digitales, unsigned int * _pines_digitales, unsigned int * _funcion_digitales, int cantidad_pines_analogicos, unsigned int * _pines_analogicos, unsigned int * _funcion_analogicos);
    ~AdministradorIO();

    void init(int cantidad_pines_digitales, int cantidad_pines_analogicos);
    void establecerFuncionPin(int pin, bool tipo_pin, bool funcion);

    void leerPinesDigitales();
    void escribirPinesDigitales();

    void leerPinesAnalogicos();
    void escribirPinesAnalogicos();
}

#endif
