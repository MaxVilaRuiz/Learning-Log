// Llegeix temperatura i la posa pel port sèrie

#include <OneWire.h>
#include <DallasTemperature.h>

// Pin on es connecta el bus 1-Wire
const byte pinDadesDQ = D5;// D1;

// Instància a les classes OneWire i DallasTemperature
OneWire oneWireObjecte(pinDadesDQ);
DallasTemperature sensorDS18B20(&oneWireObjecte);

// Temporitzador
unsigned long ultimaTemp = 0;
unsigned long tempsTemp = 5000; // Cada 5 segons

void setup() {
  // Iniciem la comunicació sèrie
  Serial.begin(115200);
  // Iniciem el bus 1-Wire
  sensorDS18B20.begin();

  // Inici temporitzador
  ultimaTemp = millis();
}

void loop() {

  // Protecció overflow
  if (ultimaTemp > millis()) {
    ultimaTemp = millis();
  }

  // Comprovar si ha passat el temps
  if (millis() - ultimaTemp > tempsTemp) {
    // Marca de temps
    ultimaTemp = millis();
    
    // Enviem comandes als sensors per a la presa de temperatura
    sensorDS18B20.requestTemperatures();

    // Llegim i mostrem les dades dels sensors DS18B20 pel port sèrie
    Serial.print("Temperatura sensor: ");
    Serial.print(sensorDS18B20.getTempCByIndex(0));
    Serial.println(" ºC");
  }
}
