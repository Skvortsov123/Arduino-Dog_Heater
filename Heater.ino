#include "Potentiometer.h"
#include "Heater.h"
#include "Heartbeat.h"
#include "Manager.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


Potentiometer potentiometer(A5);
Heartbeat heartbeat(13);
Manager manager;

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  heartbeat.beat();
  sensors.requestTemperatures();
  manager.manage(sensors.getTempCByIndex(0), potentiometer.getState());
}
