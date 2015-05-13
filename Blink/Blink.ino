#define     LED             8
#define     LED_ON          HIGH
#define     LED_OFF         LOW

#define     DELAY_LONG      500
#define     DELAY_SHORT     250

void setup()
{
    pinMode(LED, OUTPUT);
}

//-------------------------------------------
// Loop
// Main function of Blink sketch.
// param:   none
// return:  none
//-------------------------------------------
void loop()
{
    digitalWrite(LED, LED_ON); 
    delay(DELAY_LONG);
    digitalWrite(LED, LED_OFF);
    delay(DELAY_LONG);
    digitalWrite(LED, LED_ON);
    delay(DELAY_SHORT);
    digitalWrite(LED, LED_OFF);
    delay(DELAY_SHORT);
}

