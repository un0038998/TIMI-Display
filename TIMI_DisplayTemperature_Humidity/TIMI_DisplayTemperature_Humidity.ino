#include <MatesController.h>
#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 5     // Digital pin connected to the DHT sensor
DHT dht(DHTPIN, DHT11);

SoftwareSerial matesSerial(2, 3);  //Pin 4 is used as reset pin by TIMI display
MatesController mates = MatesController(matesSerial);

void setup() 
{
  matesSerial.begin(9600);
  mates.begin();
  dht.begin();
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(2000);

  int h = dht.readHumidity();
  int t = dht.readTemperature();

  mates.setPage(0);
  //Display temperature
  mates.setWidgetValue(MATES_LED_DIGITS, 0, t*10);
  mates.setWidgetValue(MATES_MEDIA_GAUGE_C, 0, t);  

  //Display humidity
  mates.setWidgetValue(MATES_LED_DIGITS, 1, h);
  mates.setWidgetValue(MATES_MEDIA_GAUGE_C, 1, h); 

}
