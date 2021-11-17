#include <MatesController.h>
#define RESET_PIN 18

MatesController mates = MatesController(Serial2, RESET_PIN);   //Hardware Serial2 is connected to GPIO 16 and 17 pins of esp32 internally

void setup() 
{
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
