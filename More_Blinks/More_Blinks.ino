//------------------------------------------------------------------------------
// More Blinks
// Tutorial program for manipulating 4 LEDs. The LEDs are lit to create the 
// following animation:
//      - (5x) Sequentially turn on all LEDs, then sequentially turn off all LEDs.
//      - (2x) Blink all LEDs
//      - (5x) Light every other LED
//      - (5x) Light every pair of LEDs
//      - (5x) Bounce a light back and forth.
//
// Software Interface:
// - IN:    None
// - OUT:   None
//
// Hardware Interface:
// - IN:    None
// - OUT:   LED_1 - pin 2
//          LED_2 - pin 3
//          LED_3 - pin 4
//          LED_4 - pin 5
//
// Author:              Carey Norslien
// Additional Credit:   .:oomlout:.
//------------------------------------------------------------------------------

//PRIVATE MACROS****************************************************************
#define     LED_1_pin       2u
#define     LED_2_pin       3u
#define     LED_3_pin       4u
#define     LED_4_pin       5u

#define     LED_1           0u
#define     LED_2           1u
#define     LED_3           2u
#define     LED_4           3u

#define     NUM_LED         4u

#define     LED_ON          HIGH
#define     LED_OFF         LOW

#define     LED_FWD         0u
#define     LED_REV         1u

#define     DELAY_LONG      250u
#define     DELAY_SHORT     100u

#define     REPETITIONS     5u
#define     EVERY_OTHER     2u
#define     EVERY_PAIR      4u

//**CUSTOM TYPES****************************************************************
typedef unsigned char   led_pin_t;
typedef unsigned char   uint8_t;
typedef unsigned int    uint16_t;

//**FILE VARIABLES**************************************************************
led_pin_t ledPins[] = {LED_1_pin, LED_2_pin, LED_3_pin, LED_4_pin};


//------------------------------------------------------------------------------
// Setup
// Initializes the software.
// param:   none
// return:  none
//------------------------------------------------------------------------------
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
    for (uint8_t i = 0; i < REPETITIONS; i++)
    {
        displaySequence(DELAY_SHORT, LED_FWD);
        displaySequence(DELAY_SHORT, LED_REV);
    }
    
    displayAll(DELAY_LONG);
    displayAll(DELAY_LONG);
    
    for (uint8_t i = 0; i < REPETITIONS; i++)
    {
        displayEveryOther(DELAY_LONG);
    }
    for (uint8_t i = 0; i < REPETITIONS; i++)
    {
        displayPair(DELAY_LONG);
    }
    for (uint8_t i = 0; i < REPETITIONS; i++)
    {
        displayTravel(DELAY_SHORT, LED_FWD);
        displayTravel(DELAY_SHORT, LED_REV);
    }
}

//------------------------------------------------------------------------------
// Display Sequence
// Turns on all LEDs sequentially, then turns them off sequentially.
// param:   inDelay - time in ms to delay
// return:  none
//------------------------------------------------------------------------------
void displaySequence(uint16_t inDelay, uint8_t direction)
{
    if (direction == LED_FWD)
    {
        for (uint8_t i = LED_1; i < NUM_LED; i++)
        {
            digitalWrite(ledPins[i], LED_ON); 
            delay(inDelay);
        }
        for (uint8_t i = LED_1; i < NUM_LED; i++)
        {
            digitalWrite(ledPins[i], LED_OFF); 
            delay(inDelay);
        }
    }
    else if (direction == LED_REV)
    {
        for (uint8_t i = LED_4 ; i > LED_1; i--)
        {
            digitalWrite(ledPins[i], LED_ON); 
            delay(inDelay);
        }
        for (uint8_t i = LED_4; i > LED_1; i--)
        {
            digitalWrite(ledPins[i], LED_OFF); 
            delay(inDelay);
        }
    }
    else
    {
        ;   //defensive
    }
}

//------------------------------------------------------------------------------
// Display All
// Turns on all LEDs at once, then turns them off all at once.
// param:   inDelay - time in ms to delay
// return:  none
//------------------------------------------------------------------------------
void displayAll(uint16_t inDelay)
{
    delay(inDelay);
    for (uint8_t i = 0; i < NUM_LED; i++)   //turn on LEDs
    {
        digitalWrite(ledPins[i], LED_ON);
    }
    delay(inDelay);
    for (uint8_t i = 0; i < NUM_LED; i++)
    {
        digitalWrite(ledPins[i], LED_OFF);
    }
    delay(inDelay);
}

//------------------------------------------------------------------------------
// Display Every Other
// Activates every other LED.
// param:   inDelay - time in ms to delay
// return:  none
//------------------------------------------------------------------------------
void displayEveryOther(uint16_t inDelay)
{
    for (uint8_t i = LED_1; i < NUM_LED; i += EVERY_OTHER)
    {
        digitalWrite(ledPins[i], LED_ON);
    }
    delay(inDelay);
    for (uint8_t i = LED_1; i < NUM_LED; i += EVERY_OTHER)
    {
        digitalWrite(ledPins[i], LED_OFF);
    }
    delay(inDelay);
    for (uint8_t i = LED_2; i < NUM_LED; i += EVERY_OTHER)
    {
        digitalWrite(ledPins[i], LED_ON);
    }
    delay(inDelay);
    for (uint8_t i = LED_2; i < NUM_LED; i += EVERY_OTHER)
    {
        digitalWrite(ledPins[i], LED_OFF);
    }
    delay(inDelay);
}

//------------------------------------------------------------------------------
// Display Pair
// Activates LEDs in pairs.
// param:   inDelay - time in ms to delay
// return:  none
//------------------------------------------------------------------------------
void displayPair(uint16_t inDelay)
{
    for (uint8_t i = LED_1; i < NUM_LED; i += EVERY_PAIR)
    {
        digitalWrite(ledPins[i], LED_ON);
        digitalWrite(ledPins[++i], LED_ON);
    }
    delay(inDelay);
    for (uint8_t i = LED_1; i < NUM_LED; i += EVERY_PAIR)
    {
        digitalWrite(ledPins[i], LED_OFF);
        digitalWrite(ledPins[++i], LED_OFF);
    }
    delay(inDelay);
    for (uint8_t i = LED_3; i < NUM_LED; i += EVERY_PAIR)
    {
        digitalWrite(ledPins[i], LED_ON);
        digitalWrite(ledPins[++i], LED_ON);
    }
    delay(inDelay);
    for (uint8_t i = LED_3; i < NUM_LED; i += EVERY_PAIR)
    {
        digitalWrite(ledPins[i], LED_OFF);
        digitalWrite(ledPins[++i], LED_OFF);
    }
    delay(inDelay);
}

//------------------------------------------------------------------------------
// Display Travel
// Activates the LEDs such that only one is lit at a time, creating an animation
// of a single light bouncing between two walls.
// param:   inDelay - time in ms to delay
// return:  none
//------------------------------------------------------------------------------
void displayTravel(uint16_t inDelay, uint8_t direction)
{
    if (direction == LED_FWD)
    {
        for (uint8_t i = LED_1; i < NUM_LED; i++)
        {
            digitalWrite(ledPins[i], LED_ON);
            delay(inDelay);
            digitalWrite(ledPins[i], LED_OFF);
            delay(inDelay);
        }
    }
    else if (direction == LED_REV)
    {
        for (uint8_t i = LED_4; i > LED_1; i--)
        {
            digitalWrite(ledPins[i], LED_ON);
            delay(inDelay);
            digitalWrite(ledPins[i], LED_OFF);
            delay(inDelay);
        }
    }
    else
    {
        ;   //defensive
    }
}