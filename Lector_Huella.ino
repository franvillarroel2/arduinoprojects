#define Led 3
#define Lector 4

void setup() {
  pinMode(Led,OUTPUT);
  pinMode(Lector,INPUT);
}

void loop() {
if(digitalRead(Lector) == HIGH){
  digitalWrite(Led, HIGH);
  } else{
  digitalWrite(Led, LOW);
  }
  delay(50);
}
