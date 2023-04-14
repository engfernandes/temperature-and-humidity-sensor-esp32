#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int temperature;
int humidity;

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("Iniciando medição de temperatura e umidade utilizando o sensor DHT11...");
}

void loop() {
  delay(10);

  temperature = dht.readTemperature(false);
  humidity = dht.readHumidity();

  if(temperature > 30) {
    Serial.print("A temperatura está ficando desagradavel.")
  }

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print("*C");
  Serial.print("         ");
  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.print("%");
  Serial.println();

  delay(5000);
}
