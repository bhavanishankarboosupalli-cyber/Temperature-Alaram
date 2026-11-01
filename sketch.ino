#define LED_PIN 13
#define BUZZER_PIN 2

const float LIMIT_TEMP = 30.0;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  Serial.println("TEMPERATURE ALARM SYSTEM");
  Serial.println("------------------------");
  Serial.print("Temperature limit: ");
  Serial.print(LIMIT_TEMP);
  Serial.println(" C");
  Serial.println("Enter temperature and press Enter:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() == 0) {
      return;
    }

    // Convert the input into a temperature value
    float temperature = input.toFloat();

    Serial.print("Entered temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    if (temperature > LIMIT_TEMP) {
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 1000);

      Serial.println("WARNING! HIGH TEMPERATURE");
      Serial.println("LED ON - BUZZER ON");
    }
    else {
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);

      Serial.println("Temperature Normal");
      Serial.println("LED OFF - BUZZER OFF");
    }

    Serial.println("------------------------");
    Serial.println("Enter next temperature:");
  }
}