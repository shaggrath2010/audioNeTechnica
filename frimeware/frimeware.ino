int curen_plus = A2;
int curen_minus = A3;
int voltage = A1;
int power = 7;

void setup() {
	pinMode(power, OUTPUT);
	Serial.begin(9600);
 	delay(5000);
	digitalWrite(power, 1);
	digitalWrite(13, 1);
	
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Current plus ");
  Serial.println(getCurrent(curen_plus));
  Serial.print ("Current minus ");
  Serial.println(getCurrent(curen_minus));
  Serial.print ("Voltage ");
  Serial.println(getVoltage(voltage));

  delay(1000);
}

int getCurrent(int sensor){
	int sensorValue = analogRead(sensor);
	int current = map(sensorValue, 511, 1023, 0, 20);
	return current;
}

float getVoltage(int sensor){
int sensorValue = analogRead(sensor);
	float voltage = map(sensorValue, 0, 1023, 0, 50);
	voltage = voltage + (voltage * 0.122);
	return voltage;	
}