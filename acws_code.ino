#define HIGH 0x1
#define LOW  0x0
const int ir_stage1 = 10;
const int ir_stage2 = 11;
const int ir_stage3 = 12;
const int ir_stage4 = 13;
int water_pump1 = 0; //stage1 watering/foam
int dc_motor2 = 2; //stage2 brush
int dc_motor3 = 3; //stage2 brush
int water_pump2 = 4; // stage3 clean watering
int dc_motor4 = 5; //stage4 fan
void setup() {
//Serial.begin(9600);
pinMode(ir_stage1, INPUT);
//Serial.begin(9600);
pinMode(ir_stage2, INPUT);
////Serial.begin(9600);
pinMode(ir_stage3, INPUT);
////Serial.begin(9600);
pinMode(ir_stage4, INPUT);
////Serial.begin(9600);
pinMode(dc_motor2, OUTPUT);
pinMode(dc_motor3, OUTPUT);
pinMode(dc_motor4, OUTPUT);
pinMode(water_pump1, OUTPUT);
pinMode(water_pump2, OUTPUT);
}
void loop() {
int stage1 = digitalRead(ir_stage1);
int stage2 = digitalRead(ir_stage2);
int stage3 = digitalRead(ir_stage3);
int stage4 = digitalRead(ir_stage4);
digitalWrite(water_pump1, LOW);
digitalWrite(dc_motor2, LOW);
digitalWrite(dc_motor3, LOW);
digitalWrite(water_pump2, LOW);
digitalWrite(dc_motor4, LOW);
if (stage1 == HIGH)
{
    digitalWrite(water_pump1, HIGH);
    delay(2000);
    digitalWrite(water_pump1, LOW);
}
if (stage2 == HIGH)
{
    digitalWrite(dc_motor2, HIGH);
    digitalWrite(dc_motor3, HIGH);
    delay(2000);
    digitalWrite(dc_motor2, LOW);
    digitalWrite(dc_motor3, LOW);
}
if (stage3 == HIGH)
{
    digitalWrite(water_pump2, HIGH);
    delay(2000);
    digitalWrite(water_pump2, LOW);
}
if (stage4 == HIGH)
{
    digitalWrite(dc_motor4, HIGH);
    delay(2000);
    digitalWrite(dc_motor4, LOW);
}

}
