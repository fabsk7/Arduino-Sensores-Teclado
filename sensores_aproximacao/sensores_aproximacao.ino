#include <Keyboard.h>

const int numEntradas = 8; // Número de entradas de sensores
int pinosEntrada[numEntradas] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pinos dos sensores

void setup() {
  Keyboard.begin(); // Inicializa a comunicação com o teclado virtual
  for (int i = 0; i < numEntradas; i++) {
    pinMode(pinosEntrada[i], INPUT_PULLUP); // Define os pinos como entrada com pull-up interno
  }
}

void loop() {
  for (int i = 0; i < numEntradas; i++) {
    int estadoSensor = digitalRead(pinosEntrada[i]); // Lê o estado do sensor

    // Se o sensor estiver ativo (HIGH), envia o valor correspondente como tecla
    if (estadoSensor == HIGH) {
      pressionaTecla(i + 1); // Envia o valor do sensor como tecla (de 1 a 8)
      delay(100); // Pequeno atraso para evitar envios repetidos
    }
  }
}

void pressionaTecla(int tecla) {
  switch (tecla) {
    case 1:
      Keyboard.write('1');
      break;
    case 2:
      Keyboard.write('2');
      break;
    case 3:
      Keyboard.write('3');
      break;
    case 4:
      Keyboard.write('4');
      break;
    case 5:
      Keyboard.write('5');
      break;
    case 6:
      Keyboard.write('6');
      break;
    case 7:
      Keyboard.write('7');
      break;
    case 8:
      Keyboard.write('8');
      break;
    default:
      break;
  }
}
