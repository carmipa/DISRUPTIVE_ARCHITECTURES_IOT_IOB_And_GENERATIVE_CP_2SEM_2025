// Questão 2A - CP5 Disruptive Architectures
// Autor: Paulo André Carminati - RM557881 - Turma 2TDSPZ

int led = 2;
int botao = 4;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  int estadoBotao = digitalRead(botao);

  if (estadoBotao == LOW) {  // Botão pressionado
    digitalWrite(led, HIGH);
    delay(700);
  } else {                   // Botão solto
    digitalWrite(led, LOW);
    delay(700);
  }
}
