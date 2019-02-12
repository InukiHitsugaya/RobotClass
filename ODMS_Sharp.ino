//
// SHARP IR sensor testing
//

int V0 = 0;                           // аналоговый пин для подключения выхода V0
float v;
float dist;

void setup() {
  Serial.begin(9600);                 // старт последовательного порта
}

void loop() {
  v = analogRead(V0)*0.0048828125;   // считываем значение сенсора и переводим в напряжение
  dist = 65*pow(v, -1.10);           // вычисление расстояния
  Serial.println(dist);              // выдаём в порт
  delay(1000);                                     
}
