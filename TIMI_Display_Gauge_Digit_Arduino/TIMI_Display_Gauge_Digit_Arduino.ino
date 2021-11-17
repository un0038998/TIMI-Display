#include <MatesController.h>
#include <SoftwareSerial.h>

SoftwareSerial matesSerial(2, 3);  // Pin 4 is used as reset pin by TIMI 
MatesController mates = MatesController(matesSerial);

void setup() 
{
  matesSerial.begin(9600);
  mates.begin();
}

int value = 0;
void loop() 
{
  mates.setPage(0);
  mates.setWidgetValue(MATES_LED_DIGITS, 0, value);
  mates.setWidgetValue(MATES_MEDIA_GAUGE_B, 0, value);
  delay(50); 
  value++;
  if (value > 100 )
  {
    value = 0;
  }
}
