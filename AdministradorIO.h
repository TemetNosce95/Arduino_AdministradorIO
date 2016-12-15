
#ifndef ADMINISTRADORIO_H
#define ADMINISTRADORIO_H

#include "Arduino.h"

class AdministradorIO{

  int * digital_pins_values;
  int * analog_pins_values;

  int * digital_pins_function;
  int * analog_pins_function;

  unsigned int * x_digitales;
  unsigned int * x_analogicos;

  int n_digitales;
  int n_analogicos;

  public:

    AdministradorIO(int n_digital_pins, int n_analog_pins);
    AdministradorIO(int n_digital_pins, unsigned int * _pines_digitales, unsigned int * _funcion_digitales, int n_analog_pins, unsigned int * _pines_analogicos, unsigned int * _funcion_analogicos);
    ~AdministradorIO();

    void init(int n_digital_pins, int n_analog_pins);
    void setFunctionPin(int pin, bool tipo_pin, bool funcion);

    void readAllDigitalPins();
    void writeAllDigitalPins();

    void readAllAnalogPins();
    void writeAllAnalogPins();

    void updateIndividualOutputPin(int type, int offset, int value);

    int getAnalogPinValue(int offset);
    bool getDigitalPinValue(int offset);
}

#endif
