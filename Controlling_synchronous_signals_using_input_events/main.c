/**
* \file main.c
*
* \brief Main source file.
*
(c) 2021 Microchip Technology Inc. and its subsidiaries.
    Subject to your compliance with these terms, you may use this software and
    any derivatives exclusively with Microchip products. It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*
*/
#define SETTLING_TIME_EXAMPLE_VALUE        (0x02)
#define DUTY_CYCLE_EXAMPLE_VALUE        (0xF6)

#include <avr/io.h>
/*Using default clock 3.3MHz */

void TCD0_init(void);
void TCD0_enableOutputChannels(void);
void EVENT_SYSTEM_init(void);
void PORT_init(void);

void TCD0_init(void)
{
    /* set the waveform mode */
    TCD0.CTRLB = TCD_WGMODE_FOURRAMP_gc;
    
    /* set channel D to match channel B */
    TCD0.CTRLC = TCD_CMPDSEL_bm;        
    
    /* set the settling time and duty cycle for the signals*/    
    TCD0.CMPASET = SETTLING_TIME_EXAMPLE_VALUE;    
    TCD0.CMPACLR = DUTY_CYCLE_EXAMPLE_VALUE;                    
    TCD0.CMPBSET = SETTLING_TIME_EXAMPLE_VALUE;                    
    TCD0.CMPBCLR = DUTY_CYCLE_EXAMPLE_VALUE;                
    
    TCD0.EVCTRLA = TCD_CFG_FILTER_gc        /* set the anti-spike filter */
                 | TCD_EDGE_FALL_LOW_gc        /* set the 'fault' state */
                 | TCD_TRIGEI_bm;            /* enable input channel A */
    
    /* set the input mode */             
    TCD0.INPUTCTRLA = TCD_INPUTMODE_WAIT_gc;
    
    /* ensure ENRDY bit is set */
    while(!(TCD0.STATUS & TCD_ENRDY_bm))
    {
        ;
    }
    
    TCD0.CTRLA = TCD_CLKSEL_20MHZ_gc        /* choose the timer's clock */
               | TCD_CNTPRES_DIV4_gc        /* choose the prescaler */
               | TCD_ENABLE_bm;                /* enable the timer */
}

void TCD0_enableOutputChannels(void)
{
    /* enable write protected register */
    CPU_CCP = CCP_IOREG_gc;
    
    TCD0.FAULTCTRL = TCD_CMPAEN_bm            /* enable channel A */
                   | TCD_CMPBEN_bm            /* enable channel B */
                   | TCD_CMPCEN_bm            /* enable channel C */
                   | TCD_CMPDEN_bm;            /* enable channel D */
} 

void EVENT_SYSTEM_init(void)
{
    EVSYS.ASYNCCH2 = EVSYS_ASYNCCH2_PORTC_PIN5_gc;
    
    EVSYS.ASYNCUSER6 = EVSYS_ASYNCUSER6_ASYNCCH2_gc;
}

void PORT_init(void)
{
    PORTA.DIR |= PIN4_bm            /* set pin 4 of port A as output */
              | PIN5_bm;            /* set pin 5 of port A as output */
        
    PORTC.DIR |= PIN0_bm            /* set pin 0 of port C as output */
              | PIN1_bm;            /* set pin 1 of port C as output */
              
    PORTC.DIR &= ~PIN5_bm;            /* set pin 5 of port C as input */
    
    /* enable pull-up resistor for pin 5 of port C */    
    PORTC.PIN5CTRL = PORT_PULLUPEN_bm;        
}

int main(void)
{    
    PORT_init();    

    EVENT_SYSTEM_init();
    
    TCD0_enableOutputChannels();
    
    TCD0_init();
    
    /* Replace with your application code */
    while (1) 
    {
        ;
    }
}
