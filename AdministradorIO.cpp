#include "AdministradorPuertos.h"

AdministradorIO::AdministradorIO(int cantidad_pines_digitales, unsigned int * _pines_digitales, unsigned int * _funcion_digitales,
                                 int cantidad_pines_analogicos, unsigned int * _pines_analogicos, unsigned int * _funcion_analogicos){

  this->init(cantidad_pines_digitales, cantidad_pines_analogicos);
  for(int i = 0; i < this->n_digitales; i++)
    this->establecerFuncionPin(i, _pines_digitales[i], true, _funcion_digitales[i]);

  for(int i = 0; i < this->n_digitales; i++)
    this->establecerFuncionPin(i, _pines_digitales[i], true, _funcion_digitales[i]);
}

AdministradorIO::AdministradorIO(int cantidad_pines_digitales, int cantidad_pines_analogicos){
  this->init(cantidad_pines_digitales, cantidad_pines_analogicos);
}

void AdministradorIO::init(int cantidad_pines_digitales, int cantidad_pines_analogicos){
  this->n_digitales = cantidad_pines_digitales;
  this->n_analogicos = cantidad_pines_analogicos;

  this->valores_pines_digitales = new int[this->n_digitales];
  this->x_digitales = new unsigned int[this->n_digitales];
  this->funcion_pines_digitales = new int[this->n_digitales];

  this->valores_pines_analogicos = new int[this->n_analogicos];
  this->x_analogicos = new unsigned int[this->n_analogicos];
  this->funcion_pines_analogicos = new int[this->n_analogicos];

}

AdministradorIO::~AdministradorIO(){
  /* DIGITAL */

  if(this->valores_pines_digitales)
    delete this->valores_pines_digitales;

  if(this->x_digitales)
    delete this->x_digitales;

  if(this->funcion_pines_digitales)
    delete this->funcion_pines_digitales;

  /* ANALOG */

  if(this->valores_pines_analogicos)
    delete this->valores_pines_analogicos;

  if(this->x_analogicos)
    delete this->x_analogicos;

  if(this->funcion_pines_analogicos)
    delete this->funcion_pines_analogicos;
}

/*
  nPin -> posicion del pin en el arreglo de pines digitales o analogicos.
  pin -> numero del pin analogico o digital.
  tipo_pin -> true si es digital, false para analogico.
  funcion -> true para salida, false para entrada.
*/

void AdministradorIO::establecerFuncionPin(int nPin,int pin, bool tipo_pin, bool funcion){
  if(tipo_pin){
      if(funcion)
        pinMode(pin, OUTPUT);
      else
        pinMode(pin INPUT);

      this->funcion_pines_digitales[nPin] = funcion;
      this->x_digitales[nPin] = pin;
      this->valores_pines_digitales[nPin] = 0;

  }else{
      this->funcion_pines_analogicos[nPin] = funcion;
      this->x_analogicos[nPin] = pin;
      this->valores_pines_analogicos[nPin] = 0;
  }
}

/* Sirve para leer todos los valores de los pines digitales en un instante dado */
void AdministradorIO::leerPinesDigitales(){
  for(int i = 0; i < this->n_digitales; i++)
    if(!this->funcion_pines_digitales[i]) /* Lo pongo negado porque arriba la entrada es cuando funcion es false */
      this->valores_pines_digitales[i] = digitalRead(this->x_digitales[i]);
}

/* Sirve para escribir todos los valores de los pines digitales en un instante dado */
void AdministradorIO::escribirPinesDigitales(){
  for(int i = 0; i < this->n_digitales; i++)
    if(this->funcion_pines_digitales[i]) /* Lo pongo así porque arriba la salida es cuando funcion es true */
      digitalWrite(this->x_digitales[i], (this->valores_pines_digitales[i]) ? HIGH : LOW );
}

/* Sirve para leer todos los valores de los pines analogicos en un instante dado */
void AdministradorIO::leerPinesAnalogicos(){
  for(int i = 0; i < this->n_analogicos; i++)
    if(!this->funcion_pines_analogicos[i]) /* Lo pongo negado porque arriba la entrada es cuando funcion es false */
      this->valores_pines_analogicos[i] = analogRead(this->x_analogicos[i]);
}

/* Sirve para escribir todos los valores de los pines analógicos en un instante dado */
void AdministradorIO::escribirPinesAnalogicos(){
  for(int i = 0; i < this->n_analogicos; i++)
    if(this->funcion_pines_analogicos[i]) /* Lo pongo así porque arriba la salida es cuando funcion es true */
      analogWrite(this->x_analogicos[i], this->valores_pines_analogicos[i]);

}
