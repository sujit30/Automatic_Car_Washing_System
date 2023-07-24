const int ir_stage0 = 9;
const int ir_stage1 = 10;
const int ir_stage2 = 11;
const int ir_stage3 = 12;
const int ir_stage4 = 13;

int dc_motor1 = 0; // conveyor belt
int water_pump1 = 6; // stage1 watering/foam
int dc_motor2 = 2; // stage2 brush
int dc_motor3 = 3; // stage2 brush
int water_pump2 = 4; // stage3 clean watering
int dc_motor4 = 5; // stage4 fan

unsigned long previousTime0 = 0;
unsigned long previousTime1 = 0;
unsigned long previousTime2 = 0;
unsigned long previousTime3 = 0;
unsigned long previousTime4 = 0;
const unsigned long pumpDelay = 2000; // 2 seconds delay for pump activation
const unsigned long cbDelay = 50000; // 12 seconds delay for keeping conveyor belt on

bool stage0Active = false; // Flag to indicate if stage 0 is active
unsigned long stage0StartTime = 0; // Store the start time of stage 0

void setup() {
  pinMode(ir_stage0, INPUT);
  pinMode(ir_stage1, INPUT);
  pinMode(ir_stage2, INPUT);
  pinMode(ir_stage3, INPUT);
  pinMode(ir_stage4, INPUT);
  Serial.begin(9600);
  pinMode(dc_motor1, OUTPUT);
  pinMode(dc_motor2, OUTPUT);
  pinMode(dc_motor3, OUTPUT);
  pinMode(dc_motor4, OUTPUT);
  pinMode(water_pump1, OUTPUT);
  pinMode(water_pump2, OUTPUT);
  if (digitalRead(ir_stage0) == HIGH) {
    digitalWrite(dc_motor1, HIGH);
  }
}

void loop() {
  int stage0 = digitalRead(ir_stage0);
  int stage1 = digitalRead(ir_stage1);
  int stage2 = digitalRead(ir_stage2);
  int stage3 = digitalRead(ir_stage3);
  int stage4 = digitalRead(ir_stage4);

  if (stage0 == HIGH && !stage0Active) {
    digitalWrite(dc_motor1, HIGH); // Turn on dc_motor1
    stage0Active = true; // Set the flag to true
    stage0StartTime = millis(); // Store the start time of stage 0
  }

  if (stage0Active) {
    // Check if stage 0 has been active for a desired duration
    if (millis() - stage0StartTime >= 5000) { // 5000 milliseconds = 5 seconds (adjust as needed)
      digitalWrite(dc_motor1, LOW); // Turn off dc_motor1 after 5 seconds (adjust as needed)
      stage0Active = false; // Clear the flag
    }
  }

  // Stage 1: Watering/Foam
  if (stage1 == HIGH) {
    digitalWrite(water_pump1, HIGH);
    if (millis() - previousTime1 >= pumpDelay) {
      digitalWrite(water_pump1, HIGH);
      previousTime1 = millis();
    }
  } else {
    digitalWrite(water_pump1, LOW);
  }

  // Stage 2: Brushing
  if (stage2 == HIGH) {
    digitalWrite(dc_motor2, HIGH);
    digitalWrite(dc_motor3, HIGH);
    if (millis() - previousTime2 >= pumpDelay) {
      digitalWrite(dc_motor2, HIGH);
      digitalWrite(dc_motor3, HIGH);
      previousTime2 = millis();
    }
  } else {
    digitalWrite(dc_motor2, LOW);
    digitalWrite(dc_motor3, LOW);
  }

  // Stage 3: Clean Watering
  if (stage3 == HIGH) {
    digitalWrite(water_pump2, HIGH);
    if (millis() - previousTime3 >= pumpDelay) {
      digitalWrite(water_pump2, HIGH); // Toggle water_pump2
      previousTime3 = millis();
    }
  } else {
    digitalWrite(water_pump2, LOW);
  }

  // Stage 4: Fan
  if (stage4 == HIGH) {
    digitalWrite(dc_motor4, HIGH);
    if (millis() - previousTime4 >= pumpDelay) {
      digitalWrite(dc_motor4, HIGH); // Toggle dc_motor4
      previousTime4 = millis();
    }
  } else {
    digitalWrite(dc_motor4, LOW);
  }
}
