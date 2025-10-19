# 🧠 Check Point 5 - Disruptive Architectures IoT
## 📚 Teoria - Conceitos Fundamentais

<div align="center">

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![IoT](https://img.shields.io/badge/IoT-FF6B6B?style=for-the-badge&logo=iot&logoColor=white)
![Electronics](https://img.shields.io/badge/Electronics-FFD700?style=for-the-badge&logo=electronics&logoColor=black)

**Desenvolvido por:** Paulo André Carminati | **RM:** 557881 | **Turma:** 2TDSPZ  
**Data:** 19/10/2025 | **Semestre:** 2/2025

</div>

---

## 📋 Índice de Navegação

- [🧩 Questão 1A - Estado Flutuante](#-questão-1a---estado-flutuante)
- [⚙️ Questão 1B - Resistor Pull-Up](#️-questão-1b---resistor-pull-up)
- [⚡ Questão 1C - Resistor Pull-Down](#-questão-1c---resistor-pull-down)
- [📊 Resumo Comparativo](#-resumo-comparativo)
- [🔧 Aplicações Práticas](#-aplicações-práticas)

---

## 🧩 Questão 1A - Estado Flutuante

### ❓ **Pergunta:**
Quando utilizamos acionadores (ex: botões) em entradas digitais de dispositivos IoT, podemos sofrer de um problema de **estado flutuante**.  
Como resolvemos esse problema em montagens convencionais? E como podemos facilitar isso no Arduino?

### ✅ **Resposta:**

O **estado flutuante** é um problema crítico em eletrônica digital que ocorre quando um pino de entrada não está conectado a nenhum nível lógico definido (VCC ou GND), causando leituras instáveis e imprevisíveis.

#### 🔍 **O que acontece:**
- O pino fica "flutuando" entre 0V e 5V
- O Arduino fica "confuso" sobre se o sinal é **0** ou **1**
- Leituras aleatórias e instáveis
- Comportamento errático do sistema

#### 🛠️ **Soluções Convencionais:**
- **Resistores Pull-Up:** Conectam o pino ao VCC (5V)
- **Resistores Pull-Down:** Conectam o pino ao GND (0V)
- **Buffer Schmitt:** Circuito que "limpa" o sinal digital
- **Valores típicos:** 10kΩ para Pull-Up/Pull-Down

#### 🚀 **Facilitação no Arduino:**
O Arduino possui **resistores Pull-Up internos** (~20kΩ) que podem ser ativados facilmente:

```cpp
pinMode(pino, INPUT_PULLUP);  // Ativa Pull-Up interno
```

**Vantagens:**
- ✅ Elimina necessidade de componentes externos
- ✅ Reduz complexidade do circuito
- ✅ Economiza espaço na protoboard
- ✅ Configuração via software

---

## ⚙️ Questão 1B - Resistor Pull-Up

### ❓ **Pergunta:**
Descreva o que é uma entrada conectada a um resistor Pull-Up. Como funciona e qual o estado "não acionado" da chave?

### ✅ **Resposta:**

#### 🔌 **Definição:**
Um **resistor Pull-Up** conecta o pino de entrada digital ao **VCC (5V)** através de um resistor, garantindo um nível lógico definido quando a chave não está acionada.

#### ⚡ **Funcionamento:**

| Estado da Chave | Conexão | Nível Lógico | Tensão no Pino |
|----------------|---------|--------------|----------------|
| **Solto** | Pino → VCC (via resistor) | **HIGH (1)** | ~5V |
| **Pressionado** | Pino → GND (via chave) | **LOW (0)** | ~0V |

#### 🔍 **Detalhes Técnicos:**
- **Valor do resistor:** 10kΩ (típico)
- **Corrente limitada:** O resistor protege contra curto-circuito
- **Estado padrão:** **HIGH** quando não acionado
- **Lógica invertida:** Pressionar = LOW, Soltar = HIGH

#### 📊 **Diagrama Conceitual:**
```
VCC (5V) ----[10kΩ]---- Pino Digital
                           |
                        [Chave]
                           |
                         GND
```

#### 💡 **Estado "Não Acionado":**
- A entrada fica em nível **ALTO (HIGH)**
- Corrente flui do VCC através do resistor para o pino
- Tensão no pino ≈ 5V
- O Arduino lê **1** (HIGH)

---

## ⚡ Questão 1C - Resistor Pull-Down

### ❓ **Pergunta:**
E um Pull-Down? Como funciona e qual o estado "não acionado" da chave?

### ✅ **Resposta:**

#### 🔌 **Definição:**
Um **resistor Pull-Down** conecta o pino de entrada digital ao **GND (0V)** através de um resistor, garantindo um nível lógico definido quando a chave não está acionada.

#### ⚡ **Funcionamento:**

| Estado da Chave | Conexão | Nível Lógico | Tensão no Pino |
|----------------|---------|--------------|----------------|
| **Solto** | Pino → GND (via resistor) | **LOW (0)** | ~0V |
| **Pressionado** | Pino → VCC (via chave) | **HIGH (1)** | ~5V |

#### 🔍 **Detalhes Técnicos:**
- **Valor do resistor:** 10kΩ (típico)
- **Corrente limitada:** O resistor protege contra curto-circuito
- **Estado padrão:** **LOW** quando não acionado
- **Lógica direta:** Pressionar = HIGH, Soltar = LOW

#### 📊 **Diagrama Conceitual:**
```
VCC (5V) ----[Chave]---- Pino Digital
                           |
                        [10kΩ]
                           |
                         GND
```

#### 💡 **Estado "Não Acionado":**
- A entrada fica em nível **BAIXO (LOW)**
- Corrente flui do pino através do resistor para o GND
- Tensão no pino ≈ 0V
- O Arduino lê **0** (LOW)

---

## 📊 Resumo Comparativo

### 🔄 **Tabela Comparativa:**

| **Aspecto** | **Pull-Up** | **Pull-Down** |
|-------------|-------------|---------------|
| **Conexão** | Pino → VCC | Pino → GND |
| **Estado Solto** | HIGH (1) | LOW (0) |
| **Estado Pressionado** | LOW (0) | HIGH (1) |
| **Lógica** | Invertida | Direta |
| **Uso Comum** | Botões, switches | Sensores ativos |
| **Vantagem** | Menos ruído | Lógica intuitiva |

### 🎯 **Quando Usar Cada Um:**

#### **Pull-Up:**
- ✅ Botões e switches
- ✅ Sensores que ativam quando conectados ao GND
- ✅ Quando você quer lógica invertida
- ✅ Arduino (Pull-Up interno disponível)

#### **Pull-Down:**
- ✅ Sensores que ativam quando conectados ao VCC
- ✅ Quando você quer lógica direta
- ✅ Circuitos que precisam de estado LOW por padrão

---

## 🔧 Aplicações Práticas

### 💻 **Código Arduino - Pull-Up Interno:**
```cpp
const int BOTAO_PIN = 4;
const int LED_PIN = 2;

void setup() {
  pinMode(BOTAO_PIN, INPUT_PULLUP);  // Ativa Pull-Up interno
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int estadoBotao = digitalRead(BOTAO_PIN);
  
  if (estadoBotao == LOW) {  // Botão pressionado (lógica invertida)
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Botão pressionado!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

### 🔌 **Código Arduino - Pull-Down Externo:**
```cpp
const int SENSOR_PIN = 4;
const int LED_PIN = 2;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int estadoSensor = digitalRead(SENSOR_PIN);
  
  if (estadoSensor == HIGH) {  // Sensor ativo (lógica direta)
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Sensor ativo!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

---

## 🎯 **Conclusão**

Essas configurações de **Pull-Up** e **Pull-Down** são fundamentais para:

- ✅ **Eliminar ruídos** e leituras erráticas
- ✅ **Garantir estabilidade** nas entradas digitais
- ✅ **Simplificar circuitos** (especialmente com Pull-Up interno do Arduino)
- ✅ **Melhorar confiabilidade** dos sistemas IoT
- ✅ **Facilitar debugging** e manutenção

**📘 Lembre-se:** Sempre use resistores Pull-Up ou Pull-Down em entradas digitais para evitar o problema do estado flutuante e garantir funcionamento estável do seu projeto Arduino!

---

<div align="center">

**🎓 FIAP - Faculdade de Informática e Administração Paulista**  
*Disruptive Architectures IoT - Semestre 2/2025*

![Made with ❤️](https://img.shields.io/badge/Made%20with-❤️-red?style=for-the-badge)

</div>