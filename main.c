#include <msp430.h>
#include <GPIO_Driver.h>
void main(void)
{
WDTCTL = WDTPW | WDTHOLD;
/*
P1OUT &= ~BIT0;  //p1.0 red led
P6OUT &= ~BIT6; //p6.6 greenled
P1DIR |= BIT0;
P6DIR |= BIT6;


P4DIR &= ~BIT1;//clear P4.1(s1)
P4REN |= BIT1;//Enable pull up/down resistor
P4OUT |= BIT1;//Make resistor a pull up

P2DIR &= ~BIT3;//clear P2.3(s2)
P2REN |= BIT3;//Enable pull up/down resistor
P2OUT |= BIT3;//Make resistor a pull up
*/
PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings

gpioInitIn(4,BIT1);
gpioInitIn(2,BIT3);
gpioInitOut(1,BIT0);
gpioInitOut(6,BIT6);
unsigned char value = 0;
while(1){
    value = gpioInitStatus(4, BIT1);
        if(value == 0x00){
            _delay_cycles(5000);
            gpioWrite(1, BIT0, 1); }
            else{
            gpioWrite(1, BIT0, 0);
        _delay_cycles(5000);
}
return 0;
}
}

