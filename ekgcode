float ecgFiltered = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
}

void loop() {
  int ecgRaw = analogRead(A0);
  ecgFiltered = 0.9 * ecgFiltered + 0.1 * ecgRaw;
  Serial.println(ecgFiltered);
  delay(2);
}
