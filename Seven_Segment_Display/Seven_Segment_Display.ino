//------------------------------------------------------------------------------
// Seven Segment Display
// PROGRAM DESCRIPTION
//
// Software Interface:
// - IN:    NA
// - OUT:   NA
//
// Hardware Interface:
// - IN:    NA
// - OUT:   NA
//
// Author:  Carey Norslien
//------------------------------------------------------------------------------

//PRIVATE MACROS****************************************************************
#define     SEG_A_PIN           4u
#define     SEG_B_PIN           3u
#define     SEG_C_PIN           2u
#define     SEG_D_PIN           11u
#define     SEG_E_PIN           10u
#define     SEG_F_PIN           8u
#define     SEG_G_PIN           9u

#define     SEG_OFF             LOW
#define     SEG_ON              HIGH

#define     NUM_SEG             7u

//**CUSTOM TYPES****************************************************************
typedef unsigned char   uint8_t;
typedef unsigned int    uint16_t;
typedef unsigned char   segPin_t;

enum segmentDisplayIdentifier
{
    SEG_A = 0,
    SEG_B,
    SEG_C,
    SEG_D,
    SEG_E,
    SEG_F,
    SEG_G
};


//**FILE VARIABLES**************************************************************
segPin_t segDispl[] = {
    SEG_A_PIN,
    SEG_B_PIN,
    SEG_C_PIN,
    SEG_D_PIN,
    SEG_E_PIN,
    SEG_F_PIN,
    SEG_G_PIN
};

//**FUNCTION DEFINITIONS********************************************************
//------------------------------------------------------------------------------
// Setup
// Initializes the software.
// param:   none
// return:  none
//------------------------------------------------------------------------------
void setup()
{
    for (uint8_t i = SEG_A; i < NUM_SEG; i++)
    {
        pinMode(segDispl[i], OUTPUT);
        digitalWrite(segDispl[i], SEG_OFF);
    }
}

//------------------------------------------------------------------------------
// Loop
// Main function of the program.
// param:   none
// return:  none
//------------------------------------------------------------------------------
void loop() 
{
    for (uint8_t i = 0; i < 10; i++)
    {
        displayNumber(i);
        delay(500);
    }
}

//------------------------------------------------------------------------------
// Display Number
// FUNC DECRIPTION
// param:   num     
// return:  none
//------------------------------------------------------------------------------
void displayNumber(uint8_t num)
{
    if (num == 0)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_ON);
        digitalWrite(segDispl[SEG_E], SEG_ON);
        digitalWrite(segDispl[SEG_F], SEG_ON);
        digitalWrite(segDispl[SEG_G], SEG_OFF);
    }
    else if (num == 1)
    {
        digitalWrite(segDispl[SEG_A], SEG_OFF);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_OFF);
        digitalWrite(segDispl[SEG_E], SEG_OFF);
        digitalWrite(segDispl[SEG_F], SEG_OFF);
        digitalWrite(segDispl[SEG_G], SEG_OFF);
    }
    else if (num == 2)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_OFF);
        digitalWrite(segDispl[SEG_D], SEG_ON);
        digitalWrite(segDispl[SEG_E], SEG_ON);
        digitalWrite(segDispl[SEG_F], SEG_OFF);
        digitalWrite(segDispl[SEG_G], SEG_ON);
    }
    else if (num == 3)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_ON);
        digitalWrite(segDispl[SEG_E], SEG_OFF);
        digitalWrite(segDispl[SEG_F], SEG_OFF);
        digitalWrite(segDispl[SEG_G], SEG_ON);
    }
    else if (num == 4)
    {
        digitalWrite(segDispl[SEG_A], SEG_OFF);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_OFF);
        digitalWrite(segDispl[SEG_E], SEG_OFF);
        digitalWrite(segDispl[SEG_F], SEG_ON);
        digitalWrite(segDispl[SEG_G], SEG_ON);
    }
    else if (num == 5)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_OFF);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_ON);
        digitalWrite(segDispl[SEG_E], SEG_OFF);
        digitalWrite(segDispl[SEG_F], SEG_ON);
        digitalWrite(segDispl[SEG_G], SEG_ON);
    }
    else if (num == 6)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_OFF);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_ON);
        digitalWrite(segDispl[SEG_E], SEG_ON);
        digitalWrite(segDispl[SEG_F], SEG_ON);
        digitalWrite(segDispl[SEG_G], SEG_ON);
    }
    else if (num == 7)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_OFF);
        digitalWrite(segDispl[SEG_E], SEG_OFF);
        digitalWrite(segDispl[SEG_F], SEG_OFF);
        digitalWrite(segDispl[SEG_G], SEG_OFF);
    }
    else if (num == 8)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_ON);
        digitalWrite(segDispl[SEG_E], SEG_ON);
        digitalWrite(segDispl[SEG_F], SEG_ON);
        digitalWrite(segDispl[SEG_G], SEG_ON);
    }
    else if (num == 9)
    {
        digitalWrite(segDispl[SEG_A], SEG_ON);
        digitalWrite(segDispl[SEG_B], SEG_ON);
        digitalWrite(segDispl[SEG_C], SEG_ON);
        digitalWrite(segDispl[SEG_D], SEG_ON);
        digitalWrite(segDispl[SEG_E], SEG_OFF);
        digitalWrite(segDispl[SEG_F], SEG_ON);
        digitalWrite(segDispl[SEG_G], SEG_ON);
    }
    else
    {
        digitalWrite(segDispl[SEG_A], SEG_OFF);
        digitalWrite(segDispl[SEG_B], SEG_OFF);
        digitalWrite(segDispl[SEG_C], SEG_OFF);
        digitalWrite(segDispl[SEG_D], SEG_OFF);
        digitalWrite(segDispl[SEG_E], SEG_OFF);
        digitalWrite(segDispl[SEG_F], SEG_OFF);
        digitalWrite(segDispl[SEG_G], SEG_OFF);
    }
}

//------------------------------------------------------------------------------
// Clear Display
// FUNC DECRIPTION
// param:   none
// return:  none
//------------------------------------------------------------------------------
void clearDisplay()
{
    for (uint8_t i = SEG_A; i < NUM_SEG; i++)
    {
        digitalWrite(segDispl[i], SEG_OFF);
    }
}




