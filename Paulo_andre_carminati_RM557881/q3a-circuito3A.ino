// Questão 3A - CP5 Disruptive Architectures
// Autor: Paulo André Carminati - RM557881 - Turma 2TDSPZ

const int LED = 2;
const int BOTAO = 4;

bool ledLigado = false;
int ultimo = HIGH;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP); // usa o resistor interno do Arduino
  digitalWrite(LED, LOW);
}

void loop() {
  int atual = digitalRead(BOTAO);

  if (ultimo == HIGH && atual == LOW) {  // botão pressionado
    ledLigado = !ledLigado;              // inverte o estado do LED
    digitalWrite(LED, ledLigado ? HIGH : LOW);
    delay(1000);                         // tempo exigido no enunciado
  }

  ultimo = atual;
  delay(20); // debounce simples
}
