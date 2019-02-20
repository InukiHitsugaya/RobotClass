    // Контакты TCS230 или TCS3200 для подключения к Arduino:
    #define S0 4
    #define S1 5
    #define S2 6
    #define S3 7
    #define sensorOut 8
     
    // для хранения частоты, считанной фотодиодами:
    int redFrequency = 0;
    int greenFrequency = 0;
    int blueFrequency = 0;
     
    // для хранения данных о красном, зеленом и синем цветах:
    int redColor = 0;
    int greenColor = 0;
    int blueColor = 0;

    const byte rPin = 9;
    const byte gPin = 10;
    const byte bPin = 11;
     
    void setup() {
      // выставляем контакты S0, S1, S2 и S3 в режим OUTPUT:
      pinMode(S0, OUTPUT);
      pinMode(S1, OUTPUT);
      pinMode(S2, OUTPUT);
      pinMode(S3, OUTPUT);

      pinMode(rPin, OUTPUT);
      pinMode(gPin, OUTPUT);
      pinMode(bPin, OUTPUT);
     
      // выставляем контакт sensorOut в режим INPUT:
      pinMode(sensorOut, INPUT);
     
      // задаем масштабирование частоты на 20%:
      digitalWrite(S0,HIGH);
      digitalWrite(S1,LOW);
     
      // запускаем последовательную коммуникацию:
      Serial.begin(9600);
    }
     
    void loop() {
      // настраиваем датчик таким образом, чтобы считывать данные
      // с фотодиодов с красным фильтром:
      digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
     
      // считываем выходную частоту:
      redFrequency = pulseIn(sensorOut, LOW);
      // подгоняем считанное значение к диапазону 0-255;
      // вместо «XX» нужно поставить собственные значения; например, так:
      // redColor = map(redFrequency, 70, 120, 255,0):
      redColor = map(redFrequency, 70, 120, 255,0);
     
      // печатаем значение для красного цвета:
      Serial.print("R = ");
      Serial.print(redColor);
      delay(100);
     
      // настраиваем датчик таким образом, чтобы считывать данные
      // с фотодиодов с зеленым фильтром:
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
     
      // считываем выходную частоту:
      greenFrequency = pulseIn(sensorOut, LOW);
      // подгоняем считанное значение к диапазону 0-255;
      // вместо «XX» нужно поставить собственные значения; например, так:
      // greenColor = map(greenFrequency, 100, 199, 255,0):
      greenColor = map(greenFrequency, 100, 199, 255, 0);
     
      // печатаем значение для зеленого цвета:
      Serial.print(" G = ");
      Serial.print(greenColor);
      delay(100);
     
      // настраиваем датчик таким образом, чтобы считывать данные
      // с фотодиодов с синим фильтром:
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
     
      // считываем выходную частоту:
      blueFrequency = pulseIn(sensorOut, LOW);
      // подгоняем считанное значение к диапазону 0-255;
      // вместо «XX» нужно поставить собственные значения; например, так:
      // blueColor = map(blueFrequency, 38, 84, 255,0):
      blueColor = map(blueFrequency, 38, 84, 255, 0);
     
      // печатаем значение для синего цвета:
      Serial.print(" B = ");
      Serial.print(blueColor);
      delay(100);
     
      // смотрим, какой цвет определился и печатаем
      // соответствующее сообщение в мониторе порта:
      if(redColor > greenColor && redColor > blueColor){
          digitalWrite( bPin, LOW );
          digitalWrite( gPin, LOW );
          digitalWrite( rPin, HIGH );
          Serial.println(" - RED detected!");  //  " - это КРАСНЫЙ!"
      }
      if(greenColor > redColor && greenColor > blueColor){
        digitalWrite( rPin, LOW );
        digitalWrite( bPin, LOW );
        digitalWrite( gPin, HIGH );
        Serial.println(" - GREEN detected!");  //  " - это ЗЕЛЕНЫЙ!"
      }
      if(blueColor > redColor && blueColor > greenColor){
        digitalWrite( gPin, LOW );
        digitalWrite( rPin, LOW );
        digitalWrite( bPin, HIGH );
        Serial.println(" - BLUE detected!");  //  " - это СИНИЙ!"
      }
    }
