#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD address 0x27 (try 0x3F if blank)

int bjp = 0, con = 0, aap = 0;  // vote count

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);  // BJP
  pinMode(3, INPUT_PULLUP);  // Congress
  pinMode(4, INPUT_PULLUP);  // AAP
  pinMode(6, INPUT_PULLUP);  // show\reset

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Voting Machine");
  lcd.setCursor(0, 1);
  lcd.print("Cast your vote");
}

void loop() {
  if (digitalRead(2) == LOW) {           // count for bjp
    bjp++;
    Serial.println("Voted to BJP! \n PRESS again to proceed......\n");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voted to BJP!");
    lcd.setCursor(0, 1);
    lcd.print("Press to proceed");
    while (digitalRead(2) == LOW) delay(500);
  }

  if (digitalRead(3) == LOW) {           // count for congress
    con++;
    Serial.println("Voted to Congress! \n PRESS again to proceed......\n");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voted Congress!");
    lcd.setCursor(0, 1);
    lcd.print("Press to proceed");
    while (digitalRead(3) == LOW) delay(500);
  }

  if (digitalRead(4) == LOW) {           // count for AAP
    aap++;
    Serial.println("Voted to AAP! \n PRESS again to proceed......\n");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voted to AAP!");
    lcd.setCursor(0, 1);
    lcd.print("Press to proceed");
    while (digitalRead(4) == LOW) delay(500);
  }

  if (digitalRead(6) == LOW) {            // to show
    Serial.println("\n Vote Counts- ");
    Serial.print("BJP: ");
    Serial.print(bjp);
    Serial.print(" Congress: ");
    Serial.print(con);
    Serial.print("  AAP: ");
    Serial.print(aap);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BJP:");
    lcd.print(bjp);
    lcd.print(" CON:");
    lcd.print(con);
    lcd.setCursor(0, 1);
    lcd.print("AAP:");
    lcd.print(aap);

    while (digitalRead(6) == LOW) delay(500);
  }
}
