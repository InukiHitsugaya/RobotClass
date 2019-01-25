#include <Wire.h>

#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte ROWS = 4; //число строк клавиатуры
const byte COLS = 3; //число столбцов клавиатуры

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; // к каким выводам подключаем управление строками
byte colPins[COLS] = {4, 3, 2}; // к каким выводам подключаем управление столбцами

char pass[4] = {'7', '3', '1', '5'}; // верный пароль
char buttons[5]; //массив нажатых кнопок
int k = 0; // счетчик нажатий
int t = 0; // счетчик совпадений кнопок
int i;

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);

  lcd.init(); // инициализируем экран
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0); //устанавливаем курсор на начало первой строки
  lcd.print("Enter password!");
  lcd.setCursor(0, 1); //устанавливаем курсор на начало второй строки
  char customKey = customKeypad.getKey();
  if (customKey)
  {
    buttons[k] = customKey; //сохраняем в массиве
    lcd.setCursor(k, 1);
    lcd.print('*');
    k = k + 1;
    if (k == 4)
    { if (buttons[0] == pass[0] && buttons[1] == pass[1] && buttons[2] == pass[2] && buttons[3] == pass[3])
      { lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Access granted!");
      }
      else {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Access denied!");
      }

      /*for (i = 0; i < 4; i++)
        { if (buttons[i] == pass[i])
          { t = t + 1;
          }
        }

        if (t == 4) //если все кнопки совпали, то доступ разрешён
        {
          lcd.clear();
          lcd.setCursor(0, 0); //устанавливаем курсор на начало первой строки
          lcd.print("Access!");
          k = 0;
          t = 0;
        } else {
          lcd.clear();
          lcd.setCursor(0, 0); //устанавливаем курсор на начало первой строки
          lcd.print("Fu!");
          k = 0;
          t = 0;
        }
      */
    }
  }
}

