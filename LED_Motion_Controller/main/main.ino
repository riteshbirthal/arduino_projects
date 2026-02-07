

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

unsigned long lastTime = 0;

float pitch = 0;
float roll = 0;

//                8  
//                 
//    7  6  5         4  3  2
//                   
//               9    
const uint8_t D2=2, D3=3, D4=4, D5=5, D6=6, D7=7, D8=8, D9=9;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Device is up...");
  Wire.begin(9600);
  mpu.initialize();

  if(mpu.testConnection())
    Serial.println("MPU6050 connected!");
  else
    Serial.println("MPU6050 connection failed!");

  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);

  digitalWrite(D2, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t ax, ay, az, gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert accelerometer to g
  float accelX = ax / 16384.0;
  float accelY = ay / 16384.0;
  float accelZ = az / 16384.0;

  // Convert gyroscope to deg/sec
  float gyroX = gx / 131.0;
  float gyroY = gy / 131.0;

  // Time difference
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;
  lastTime = now;

  // Accelerometer angles
  float pitchAccel = atan2(accelY, accelZ) * 180 / PI;
  float rollAccel  = atan2(accelX, accelZ) * 180 / PI;

  // Gyro integration
  pitch += gyroX * dt;
  roll  += gyroY * dt;

  // Complementary filter
  pitch = 0.98 * pitch + 0.02 * pitchAccel;
  roll  = 0.98 * roll  + 0.02 * rollAccel;

  Serial.print("Pitch: ");
  Serial.print(pitch);
  Serial.print("  Roll: ");
  Serial.println(roll);

  digitalWrite(D2, pitch < -20 ? HIGH : LOW);
  digitalWrite(D3, pitch < -15 ? HIGH : LOW);
  digitalWrite(D4, pitch < -8 ? HIGH : LOW);
  digitalWrite(D5, pitch > -2 ? HIGH : LOW);
  digitalWrite(D6, pitch > 5 ? HIGH : LOW);
  digitalWrite(D7, pitch > 10 ? HIGH : LOW);
  digitalWrite(D8, roll > 10 ? HIGH : LOW);
  digitalWrite(D9, roll < -8 ? HIGH : LOW);

  delay(2);
}
