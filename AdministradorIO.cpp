#include "AdministradorPuertos.h"

AdministradorIO::AdministradorIO(int n_digital_pins, unsigned int * _pines_digitales, unsigned int * _funcion_digitales,
                                 int n_analog_pins, unsigned int * _pines_analogicos, unsigned int * _funcion_analogicos){

  this->init(n_digital_pins, n_analog_pins);
  for(int i = 0; i < this->n_digitales; i++)
    this->establecerFuncionPin(i, _pines_digitales[i], true, _funcion_digitales[i]);

  for(int i = 0; i < this->n_digitales; i++)
    this->establecerFuncionPin(i, _pines_digitales[i], true, _funcion_digitales[i]);
}

AdministradorIO::AdministradorIO(int n_digital_pins, int n_analog_pins){
  this->init(n_digital_pins, n_analog_pins);
}

void AdministradorIO::init(int n_digital_pins, int n_analog_pins){
  this->n_digitales = n_digital_pins;
  this->n_analogicos = n_analog_pins;

  this->digital_pins_values = new int[this->n_digitales];
  this->x_digitales = new unsigned int[this->n_digitales];
  this->digital_pins_function = new int[this->n_digitales];

  this->analog_pins_values = new int[this->n_analogicos];
  this->x_analogicos = new unsigned int[this->n_analogicos];
  this->analog_pins_function = new int[this->n_analogicos];

}

AdministradorIO::~AdministradorIO(){
  /* DIGITAL */

  if(this->digital_pins_values)
    delete this->digital_pins_values;

  if(this->x_digitales)
    delete this->x_digitales;

  if(this->digital_pins_function)
    delete this->digital_pins_function;

  /* ANALOG */

  if(this->analog_pins_values)
    delete this->analog_pins_values;

  if(this->x_analogicos)
    delete this->x_analogicos;

  if(this->analog_pins_function)
    delete this->analog_pins_function;
}

/*
  nPin -> posicion del pin en el arreglo de pines digitales o analogicos.
  pin -> numero del pin analogico o digital.
  tipo_pin -> true si es digital, false para analogico.
  funcion -> true para salida, false para entrada.
*/

void AdministradorIO::setFunctionPin(int nPin,int pin, bool tipo_pin, bool funcion){
  if(tipo_pin){
      if(funcion)
        pinMode(pin, OUTPUT);
      else
        pinMode(pin INPUT);

      this->digital_pins_function[nPin] = funcion;
      this->x_digitales[nPin] = pin;
      this->digital_pins_values[nPin] = 0;

  }else{
      this->analog_pins_function[nPin] = funcion;
      this->x_analogicos[nPin] = pin;
      this->analog_pins_values[nPin] = 0;
  }
}

/* Sirve para leer todos los valores de los pines digitales en un instante dado */
void AdministradorIO::readDigitalPins(){
  for(int i = 0; i < this->n_digitales; i++)
    if(!this->digital_pins_function[i]) /* Lo pongo negado porque arriba la entrada es cuando funcion es false */
      this->digital_pins_values[i] = digitalRead(this->x_digitales[i]);
}

/* Sirve para escribir todos los valores de los pines digitales en un instante dado */
void AdministradorIO::writeDigitalPins(){
  for(int i = 0; i < this->n_digitales; i++)
    if(this->digital_pins_function[i]) /* Lo pongo así porque arriba la salida es cuando funcion es true */
      digitalWrite(this->x_digitales[i], (this->digital_pins_values[i]) ? HIGH : LOW );
}

/* Sirve para leer todos los valores de los pines analogicos en un instante dado */
void AdministradorIO::readAnalogPins(){
  for(int i = 0; i < this->n_analogicos; i++)
    if(!this->analog_pins_function[i]) /* Lo pongo negado porque arriba la entrada es cuando funcion es false */
      this->analog_pins_values[i] = analogRead(this->x_analogicos[i]);
}

/* Sirve para escribir todos los valores de los pines analógicos en un instante dado */
void AdministradorIO::writeAnalogPins(){
  for(int i = 0; i < this->n_analogicos; i++)
    if(this->analog_pins_function[i]) /* Lo pongo así porque arriba la salida es cuando funcion es true */
      analogWrite(this->x_analogicos[i], this->analog_pins_values[i]);

}
