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
#define SIGNAL_PERIOD_EXAMPLE_VALUE            (0xC8)
#define SIGNAL_DUTY_CYCLE_EXAMPLE_VALUE        (0x64)

#include <avr/io.h>
/*Using default clock 3.3MHz */

void TCD0_init(void);
void TCD0_enableOutputChannels(void);
void PORT_init(void);

void TCD0_init(void)
{    
    /* set the waveform mode */
    TCD0.CTRLB = TCD_WGMODE_DS_gc;
    
    /* set the signal period */
    TCD0.CMPBCLR = SIGNAL_PERIOD_EXAMPLE_VALUE;    
    
    /* the signals are alternatively active and a small
       symmetric dead time is needed */
    TCD0.CMPBSET = SIGNAL_DUTY_CYCLE_EXAMPLE_VALUE + 1;                                        
    TCD0.CMPASET = SIGNAL_DUTY_CYCLE_EXAMPLE_VALUE - 1;    
    
    /* ensure ENRDY bit is set */
    while(!(TCD0.STATUS & TCD_ENRDY_bm))
    {
        ;
    }
    
    TCD0.CTRLA = TCD_CLKSEL_20MHZ_gc        /* choose the timer's clock */
               | TCD_CNTPRES_DIV1_gc        /* choose the prescaler */
               | TCD_ENABLE_bm;                /* enable the timer */
}

void TCD0_enableOutputChannels(void)
{
    /* enable write protected register */
    CPU_CCP = CCP_IOREG_gc;    
    
    TCD0.FAULTCTRL = TCD_CMPAEN_bm            /* enable channel A */
                   | TCD_CMPBEN_bm;            /* enable channel B */
}

void PORT_init(void)
{
    PORTA.DIR |= PIN4_bm            /* set pin 4 as output */
              | PIN5_bm;        /* set pin 5 as output */
}

int main(void)
{
    PORT_init();
    
    TCD0_enableOutputChannels();
    
    TCD0_init();
    
    /* Replace with your application code */
    while (1) 
    {
        ;
    }
}
