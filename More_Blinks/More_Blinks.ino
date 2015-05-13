//PRIVATE MACROS****************************************************************
#define     LED_1_pin       2
#define     LED_2_pin       3
#define     LED_3_pin       4
#define     LED_4_pin       5

#define     LED_1           0
#define     LED_2           1
#define     LED_3           2
#define     LED_4           3

#define     NUM_LED         4

#define     LED_ON          HIGH
#define     LED_OFF         LOW

#define     DELAY_LONG      500
#define     DELAY_SHORT     100

//**CUSTOM TYPES****************************************************************
typedef unsigned char   led_pin_t;
typedef unsigned char   uint8_t;
typedef unsigned int    uint16_t;

//**FILE VARIABLES**************************************************************
led_pin_t ledPins[] = {LED_1_pin, LED_2_pin, LED_3_pin, LED_4_pin};

void setup()
{
    uint8_t i = 0;
    for ( ; i < NUM_LED; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

//------------------------------------------------------------------------------
// Loop
// Main function of Blink sketch.
// param:   none
// return:  none
//------------------------------------------------------------------------------
void loop()
{
    uint16_t count = 0;
    
    for (count = 0; count < 2; count++)
    {
        displayLEDs(DELAY_SHORT);
    }
    for (count = 0; count < 2; count++)
    {
        displayLEDs(DELAY_LONG);
    }
}

//------------------------------------------------------------------------------
// Display LEDs
// Turns on all LEDs sequentially, then turns them off sequentially.
// param:   inDelay - time in ms to delay
// return:  none
//------------------------------------------------------------------------------
void displayLEDs(uint8_t inDelay)
{
    uint8_t i = 0;
    
    for ( ; i < NUM_LED; i++)   //turn on LEDs
    {
        digitalWrite(ledPins[i], LED_ON); 
        delay(inDelay);
    }
    for (i = 0; i < NUM_LED; i++)
    {
        digitalWrite(ledPins[i], LED_OFF); 
        delay(inDelay);
    }
}


