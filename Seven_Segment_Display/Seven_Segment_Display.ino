//------------------------------------------------------------------------------
// Seven Segment Display
// Counts up from 0-9 on a seven segment LCD display.
//
// Software Interface:
// - IN:    None
// - OUT:   None
//
// Hardware Interface:
// - IN:    None
// - OUT:   Arduino Pin 4   <-> LDS-C302RI Pin 13 (Segment A)
//          Arduino Pin 3   <-> LDS-C302RI Pin 12 (Segment B)
//          Arduino Pin 2   <-> LDS-C302RI Pin 11 (Segment C)
//          Arduino Pin 11  <-> LDS-C302RI Pin 6  (Segment D)
//          Arduino Pin 10  <-> LDS-C302RI Pin 5  (Segment E)
//          Arduino Pin 8   <-> LDS-C302RI Pin 3  (Segment F)
//          Arduino Pin 9   <-> LDS-C302RI Pin 4  (Segment G)
//
// Author:  Carey Norslien
// Date:    5/15/15
//------------------------------------------------------------------------------

//PRIVATE MACROS****************************************************************
#define     SEG_A_PIN           4u
#define     SEG_B_PIN           3u
#define     SEG_C_PIN           2u
#define     SEG_D_PIN           11u
#define     SEG_E_PIN           10u
#define     SEG_F_PIN           8u
#define     SEG_G_PIN           9u

#define     DISPL_0             0x7Eu
#define     DISPL_1             0x30u
#define     DISPL_2             0x6Du
#define     DISPL_3             0x79u
#define     DISPL_4             0x33u
#define     DISPL_5             0x5Bu
#define     DISPL_6             0x5Fu
#define     DISPL_7             0x70u
#define     DISPL_8             0x7Fu
#define     DISPL_9             0x7Bu
#define     DISPL_NONE          0x00u

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
segPin_t segDispl[] = 
{
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
// Counts up from 0 to 10. Only digits 0-9 will be displayed, number 10 will be
// an invalid digit.
// param:   none
// return:  none
//------------------------------------------------------------------------------
void loop() 
{
    for (uint8_t i = 0; i < 11; i++)
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
        activateSegments(DISPL_0);
    }
    else if (num == 1)
    {
        activateSegments(DISPL_1);
    }
    else if (num == 2)
    {
        activateSegments(DISPL_2);
    }
    else if (num == 3)
    {
        activateSegments(DISPL_3);
    }
    else if (num == 4)
    {
        activateSegments(DISPL_4);
    }
    else if (num == 5)
    {
        activateSegments(DISPL_5);
    }
    else if (num == 6)
    {
        activateSegments(DISPL_6);
    }
    else if (num == 7)
    {
        activateSegments(DISPL_7);
    }
    else if (num == 8)
    {
        activateSegments(DISPL_8);
    }
    else if (num == 9)
    {
        activateSegments(DISPL_9);
    }
    else
    {
        activateSegments(DISPL_NONE);
    }
}

//------------------------------------------------------------------------------
// Activate Segments
// Given an 8 bit number representing the activated segments, a digit can be 
// formed on the LCD display. 
// The 7 bit number is as follows:
//      "0ABCDEFG", where bit 6 is segment A, bit 0 is G, etc...
// param:   inSegForm     8 bit number representing the activated segments
// return:  none
//------------------------------------------------------------------------------
void activateSegments(uint8_t inSegForm)
{
    uint8_t shiftReg = inSegForm;
    uint8_t segmentStatus = 0;
    
    //use bit manipulation to get the status of the desired LCD segment
    for (int8_t i = SEG_G; i > -1; i--)
    {
        segmentStatus = shiftReg & 1;
        if (segmentStatus == SEG_ON)
        {
            digitalWrite(segDispl[i], SEG_ON);
        }
        else
        {
            digitalWrite(segDispl[i], SEG_OFF);
        }
        shiftReg = shiftReg >> 1;
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





















