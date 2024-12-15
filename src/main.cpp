#include <ESP32Servo.h>
#include <ezButton.h>

// Definições de pinos
#define BUTTON1_PIN 26 // Botão 1
#define BUTTON2_PIN 27 // Botão 2
#define BUTTON3_PIN 14 // Botão 3

#define SERVO1_PIN 21  // Servo 1
#define SERVO2_PIN 22  // Servo 2
#define SERVO3_PIN 23  // Servo 3

// Instâncias de botões e servos
ezButton button1(BUTTON1_PIN);
ezButton button2(BUTTON2_PIN);
ezButton button3(BUTTON3_PIN);

Servo servo1;
Servo servo2;
Servo servo3;

int angle1 = 0; // Ângulo inicial para servo 1
int angle2 = 0; // Ângulo inicial para servo 2
int angle3 = 0; // Ângulo inicial para servo 3

void setup() {
  Serial.begin(9600);

  // Configuração de debounce para os botões
  button1.setDebounceTime(100);
  button2.setDebounceTime(100);
  button3.setDebounceTime(100);

  // Configuração dos pinos dos servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);

  // Posicionar os servos inicialmente no ângulo 0
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
}

void loop() {
  // Atualizar o estado dos botões
  button1.loop();
  button2.loop();
  button3.loop();

  // Verificar se o botão 1 foi pressionado
  if (button1.isPressed()) {
    angle1 = (angle1 == 0) ? 180 : 0; // Alternar entre 0° e 180°
    Serial.print("Botão 1 pressionado => Rotacionar servo 1 para ");
    Serial.print(angle1);
    Serial.println("°");
    servo1.write(angle1);
  }

  // Verificar se o botão 2 foi pressionado
  if (button2.isPressed()) {
    angle2 = (angle2 == 0) ? 180 : 0; // Alternar entre 0° e 180°
    Serial.print("Botão 2 pressionado => Rotacionar servo 2 para ");
    Serial.print(angle2);
    Serial.println("°");
    servo2.write(angle2);
  }

  // Verificar se o botão 3 foi pressionado
  if (button3.isPressed()) {
    angle3 = (angle3 == 0) ? 180 : 0; // Alternar entre 0° e 180°
    Serial.print("Botão 3 pressionado => Rotacionar servo 3 para ");
    Serial.print(angle3);
    Serial.println("°");
    servo3.write(angle3);
  }
}
