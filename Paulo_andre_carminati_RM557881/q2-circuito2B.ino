// Questão 2B - CP5 Disruptive Architectures
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
  } else {                   // Botão solto
    digitalWrite(led, LOW);
  }
}
