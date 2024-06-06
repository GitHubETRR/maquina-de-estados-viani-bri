//Se define los pines de tanto el boton y los leds (led 1 y led2)
//estadoRebote_t estadoActual es la variale para almacenar el estado actual

int BOTON = 2; 
int LED_1 = 9;  
int LED_2 = 10; 

typedef enum {
  BOTON_LIBRE,
  BOTON_CAYENDO,
  BOTON_PRESIONADO,
  BOTON_SUBIENDO
} estadoRebote_t;

estadoRebote_t estadoActual; 
int ULTIMO_TIEMPO_REBOTE = 0; 
int RETARDO_REBOTE = 40; 

void setup() {
  pinMode(BOTON, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  inicio();
}

void loop() {
void inicio() {
  estadoActual = BOTON_LIBRE; 
}

void actualizarFSM() {
  bool ESTADO_BOTON = digitalRead(BOTON);
  int TIEMPO_ACTUAL = millis();

  switch (estadoActual) {
    case BOTON_LIBRE:
      if (ESTADO_BOTON == LOW) {
        ESTADO_ACTUAL = BOTON_CAYENDO;
        ULTIMO_TIEMPO_REBOTE = TIEMPO_ACTUAL;
      }
      break;

    case BOTON_CAYENDO:
      if (TIEMPO_ACTUAL - ULTIMO_TIEMPO_REBOTE >= RETARDO_REBOTE) {
        if (BOTON == LOW) {
          ESTADO_ACTUAL = BOTON_PRESIONADO;
          BOTON_PRESIONADO();
        } else {
          ESTADO_ACTUAL = BOTON_LIBRE;
        }
      }
      break;

    case BOTON_PRESIONADO:
      if (ESTADO_BOTON == HIGH) {
        ESTADO_ACTUAL = BOTON_SUBIENDO;
        ULTIMO_TIEMPO_REBOTE = TIEMPO_ACTUAL;
      }
      break;

    case BOTON_SUBIENDO:
      if (TIEMPO_ACTUAL - ULTIMO_TIEMPO_REBOTE >= RETARDO_REBOTE) {
        if (ESTADO_BOTON == HIGH) {
          ESTADO_ACTUAL = BOTON_LIBRE;
          BOTO();
        } else {
          ESTADO_ACTUAL = BOTON_PRESIONADO;
        }
      }
      break;
  }
}

void BOTON_PRESIONADO() {
  // Invertir el estado del LED1
  digitalWrite(LED_1, !digitalRead(LED_2));
}

void BOTON() {
  // Invertir el estado del LED2
  digitalWrite(LED_2, !digitalRead(LED_2));
}
}
