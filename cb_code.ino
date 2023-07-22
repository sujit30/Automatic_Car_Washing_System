#define HIGH 0x1
#define LOW  0x0
const int stage0 = 9;
int cb = 3;
void setup() {
  pinMode(stage0, INPUT);
  pinMode(cb, OUTPUT);
}

void loop() {
  int s1=digitalRead(stage0);
  if (s1 == HIGH)
  {
    digitalWrite(cb, HIGH);
    delay(2000);
    digitalWrite(cb, LOW);
    delay(2000);
  }

}
