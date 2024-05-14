#include <Arduino.h>

// DEFINIÇÃO DOS PINOS DO SINAL DE VEÍCULOS (SV)
#define RED_SV_PIN 15
#define YELLOW_SV_PIN 2
#define GREEN_SV_PIN 0

// DEFINIÇÃO DE PINOS DO SINAL DE PEDESTRES (SP)
#define RED_SP_PIN 16
#define GREEN_SP_PIN 17

// DEFINIÇÃO DO PINO DO BOTÃO
#define BUTTON_SP_PIN 4

// DEFINIÇÃO DE PINOS DO DISPLAY DE 7 SEGMENTOS 2 DIGITOS
#define DISPLAY_A_PIN 5
#define DISPLAY_B_PIN 18
#define DISPLAY_C_PIN 19
#define DISPLAY_D_PIN 21
#define DISPLAY_E_PIN 22
#define DISPLAY_F_PIN 23
#define DISPLAY_G_PIN 13
#define DISPLAY_DP_PIN 12
#define DISPLAY_DG1_PIN 7
#define DISPLAY_DG2_PIN 8

// DEFINIÇÃO DE VARIÁVEIS CONSTANTES
#define TARGET (1000 / 2)  // tempo de execução 1000ms (1 segundo)
#define RED_SV_TARGET 20   // segundos
#define YELLOW_SV_TARGET 3 // segundos
#define GREEN_SV_TARGET 30 // segundos
#define BUTTON_TARGET 300

u_int8_t displayNumbers[10] = {
    0xFC, // 0
    0x60, // 1
    0xDA, // 2
    0xF2, // 3
    0x66, // 4
    0xB6, // 5
    0xBE, // 6
    0xE0, // 7
    0xFE, // 8
    0xF6  // 9
};
enum
{
  DIGIT_POS_0,
  DIGIT_POS_1,
  DIGIT_POS_ALL,
  DIGIT_ALL_OFF,
};

enum
{
  GREEN_MODE = 1,
  YELLOW_MODE,
  RED_MODE,
};

uint8_t cicly_counter = 0;
uint8_t flag_traffic_light = GREEN_MODE;
uint8_t display_counter = RED_SV_TARGET;
bool flag_button_press = false;
unsigned long run_timer = millis();
unsigned long button_timer = millis();

void traffic_light(int status);
void erase_SV_LEDs();
void erase_SP_LEDs();
void displayShow(int num = 8, int pos = DIGIT_POS_ALL);

void setup()
{
  // DECLARAÇÃO DE PINOS DOS LEDs DO SINAL DE VEÍCULOS COMO SAÍDA
  pinMode(RED_SV_PIN, OUTPUT);
  pinMode(YELLOW_SV_PIN, OUTPUT);
  pinMode(GREEN_SV_PIN, OUTPUT);

  // DECLARAÇÃO DE PINOS DOS LEDs DO SINAL DE PEDESTRES COMO SAÍDA
  pinMode(RED_SP_PIN, OUTPUT);
  pinMode(GREEN_SP_PIN, OUTPUT);

  // DECLARAÇÃO DE PINOS DO BOTÃO DO SINAL DE PEDESTRES COMO ENTRADA
  pinMode(BUTTON_SP_PIN, INPUT);

  // DECLARAÇÃO DE PINOS DO DISPLAY COMO SAÍDA
  pinMode(DISPLAY_DG1_PIN, OUTPUT);
  pinMode(DISPLAY_DG2_PIN, OUTPUT);
  pinMode(DISPLAY_A_PIN, OUTPUT);
  pinMode(DISPLAY_B_PIN, OUTPUT);
  pinMode(DISPLAY_C_PIN, OUTPUT);
  pinMode(DISPLAY_D_PIN, OUTPUT);
  pinMode(DISPLAY_E_PIN, OUTPUT);
  pinMode(DISPLAY_F_PIN, OUTPUT);
  pinMode(DISPLAY_G_PIN, OUTPUT);
  pinMode(DISPLAY_DP_PIN, OUTPUT);
}

void loop()
{
  traffic_light(flag_traffic_light);

  if (millis() - run_timer >= TARGET)
  {
    cicly_counter++;

    if (flag_traffic_light == RED_MODE)
    {
      display_counter--;
    }

    if (flag_traffic_light == GREEN_MODE && cicly_counter >= GREEN_SV_TARGET)
    {
      flag_traffic_light = YELLOW_MODE;
      cicly_counter = 0;
    }
    if (flag_traffic_light == YELLOW_MODE && cicly_counter >= YELLOW_SV_TARGET)
    {
      flag_traffic_light = RED_MODE;
      cicly_counter = 0;
    }
    if (flag_traffic_light == RED_MODE && cicly_counter >= RED_SV_TARGET)
    {
      flag_traffic_light = GREEN_MODE;
      display_counter = RED_SV_TARGET;
      flag_button_press = false;
      cicly_counter = 0;
    }

    run_timer = millis();
  }

  if (digitalRead(BUTTON_SP_PIN) &&
      flag_button_press == false &&
      millis() - button_timer >= BUTTON_TARGET)
  {
    flag_traffic_light = YELLOW_MODE;
    flag_button_press = true;
    cicly_counter = 0;
  }
  if (flag_traffic_light != GREEN_MODE)
  {
    displayShow(display_counter / 10, DIGIT_POS_0);
    displayShow(display_counter % 10, DIGIT_POS_1);
  }
}

void displayShow(int num, int pos)
{
  digitalWrite(DISPLAY_DG1_PIN, HIGH); // apaga o digito 1 do display
  digitalWrite(DISPLAY_DG2_PIN, HIGH); // apaga o digito 2 do display

  digitalWrite(DISPLAY_A_PIN, (displayNumbers[num] >> 7) & 0x1);
  digitalWrite(DISPLAY_B_PIN, (displayNumbers[num] >> 6) & 0x1);
  digitalWrite(DISPLAY_C_PIN, (displayNumbers[num] >> 5) & 0x1);
  digitalWrite(DISPLAY_D_PIN, (displayNumbers[num] >> 4) & 0x1);
  digitalWrite(DISPLAY_E_PIN, (displayNumbers[num] >> 3) & 0x1);
  digitalWrite(DISPLAY_F_PIN, (displayNumbers[num] >> 2) & 0x1);
  digitalWrite(DISPLAY_G_PIN, (displayNumbers[num] >> 1) & 0x1);
  digitalWrite(DISPLAY_DP_PIN, (displayNumbers[num] >> 0) & 0x1);

  switch (pos)
  {
  case DIGIT_POS_0:
    digitalWrite(DISPLAY_DG1_PIN, LOW);
    digitalWrite(DISPLAY_DG2_PIN, HIGH);
    break;
  case DIGIT_POS_1:
    digitalWrite(DISPLAY_DG2_PIN, LOW);
    digitalWrite(DISPLAY_DG1_PIN, HIGH);
    break;
  case DIGIT_POS_ALL:

    digitalWrite(DISPLAY_DG1_PIN, LOW);
    digitalWrite(DISPLAY_DG2_PIN, LOW);
    break;
  case DIGIT_ALL_OFF:
    digitalWrite(DISPLAY_DG1_PIN, HIGH);
    digitalWrite(DISPLAY_DG2_PIN, HIGH);
    break;

  default:
    break;
  }
}

void traffic_light(int status)
{

  switch (status)
  {
  case GREEN_MODE:
    erase_SV_LEDs();
    digitalWrite(GREEN_SV_PIN, HIGH);
    erase_SP_LEDs();
    digitalWrite(RED_SP_PIN, HIGH);
    break;
  case YELLOW_MODE:
    erase_SV_LEDs();
    digitalWrite(YELLOW_SV_PIN, HIGH);
    break;
  case RED_MODE:
    erase_SV_LEDs();
    digitalWrite(RED_SV_PIN, HIGH);
    erase_SP_LEDs();
    digitalWrite(GREEN_SP_PIN, HIGH);

    break;

  default:
    break;
  }
}

void erase_SV_LEDs()
{
  digitalWrite(RED_SV_PIN, LOW);
  digitalWrite(YELLOW_SV_PIN, LOW);
  digitalWrite(GREEN_SV_PIN, LOW);
}

void erase_SP_LEDs()
{
  digitalWrite(RED_SP_PIN, LOW);
  digitalWrite(GREEN_SP_PIN, LOW);
}
