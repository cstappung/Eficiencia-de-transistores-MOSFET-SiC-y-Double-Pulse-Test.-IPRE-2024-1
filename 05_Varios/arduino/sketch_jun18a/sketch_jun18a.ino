/*
 Creado: Luis del Valle (ldelvalleh@programarfacil.com)
 https://programarfacil.com
*/
 
// Declaracion de variables globales
float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = 0; // Variable del pin de entrada del sensor (A0)
int pin_switch = 3; // Variable del pin de entrada del sensor (A3)
float temp_set = 70.0;
float ventana = 0.2;
int estado = 0;
 
void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
  pinMode(pin_switch, OUTPUT);
  digitalWrite(pin_switch, LOW);
 
}
 
void loop() {
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(pinLM35); 
   
  // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0)/1024.0; 
 

  // Esperamos un tiempo para repetir el loop
  if (estado == 0 & tempC > temp_set + ventana){
    digitalWrite(pin_switch, HIGH);
    estado = 1;
  } else if (estado == 1 & tempC < temp_set - ventana){
    digitalWrite(pin_switch, LOW);
    estado = 0;
  }

  delay(50);
}