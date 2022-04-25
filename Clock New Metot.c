/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator

Project : Clok Whit Set Time by Push Buttom
Version : 3.0.1.1
Date    : 29/07/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 4.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/
#include <stdlib.h>
#include <mega16.h>
 #include <delay.h>
// Alphanumeric LCD Module functions
#include <alcd.h>

// Declare your global variables here
    int h,m,s,i=0;
unsigned char a[];
void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=P State6=P State5=P State4=P State3=P State2=P State1=P State0=P 
PORTA=0xFF;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0xFF;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);

while (1)
     { 

              lcd_gotoxy(0,0);
              itoa(i,a);
              lcd_puts(a);
              lcd_gotoxy(1,0);
              lcd_puts(a);
              lcd_gotoxy(2,0);
              lcd_putchar(':');
              lcd_gotoxy(3,0);
              lcd_puts(a);
              lcd_gotoxy(4,0);
              lcd_puts(a);
              lcd_gotoxy(5,0);
              lcd_putchar(':');
              lcd_gotoxy(6,0);
              lcd_puts(a);
              lcd_gotoxy(7,0);
              lcd_puts(a);
           //   lcd_gotoxy(9,0);
           //  lcd_putsf("AM");
           lcd_gotoxy(0,1);
           lcd_putsf("omrani");
            

      for(h=0;h<=23;h++)       //for Hour         
      { 
       for(m=0;m<=59;m++)  //for Min 
          {
          for(s=0;s<=59;s++)   //for Sec
           {               
                if(PINA.0==0)                //Reset Time
                     {
                     h=m=s=0; 
                      }  
                 if (PINA.1==0)             //Set Time Min
                       {
                        m++; 
                        }
                        if (m > 59)  
                        {
                        m = 0;
                        }      

                 if (PINA.2==0)              //Set Time Hour
                       {
                        h++; 
                        }
                        if (h > 23)  
                        {
                        h = 0;
                        }
                         
                 if (PINA.3==0)              //Set Puase
                       {
                            delay_ms(2000);
                        } 
                        
                // if (PINA.4 ==0)                    
                //        {                           
                //           // lcd_gotoxy(9,0);      
                //            lcd_putsf("PM");        
                //                                    
                //        }                           
                // if (PINA.5 ==0)                    
                //          {                         
                //           //lcd_gotoxy(9,0);       
                //           lcd_putsf("AM");         
                //           }                        
                        
                  if(h>=12)
                  {
                   lcd_gotoxy(9,0);
                   lcd_putsf("PM"); 
                   if(h>=12&&h<13)
                   {  
                    lcd_gotoxy(0,0);
                    itoa(h,a);
                    lcd_puts(a);
                   }                   if(h>=13)
                   {
                    h=h-12; 
                     if(h<=9)     
                       { 
                        lcd_gotoxy(0,0);
                        itoa(i,a);
                        lcd_puts(a);
                        lcd_gotoxy(1,0);
                        itoa(h,a);
                        lcd_puts(a);
                       }
                    else
                      {
                       lcd_gotoxy(0,0);
                       itoa(h,a);
                       lcd_puts(a);
                      }

                    h=h+12;    
                   }      
                  }        
               ////////////////////////// 
               else
                  {
                  lcd_gotoxy(9,0);
                  lcd_putsf("AM");
                   if(h<=9)     
                    { 
                     lcd_gotoxy(0,0);
                     itoa(i,a);
                     lcd_puts(a);
                     lcd_gotoxy(1,0);
                     itoa(h,a);
                     lcd_puts(a);
                    }
                  else
                   {
                   lcd_gotoxy(0,0);
                   itoa(h,a);
                   lcd_puts(a);
                   }                 
                  }     
                  //start for min DIM
              if(m<=9)     
               { 
                lcd_gotoxy(3,0);
                itoa(i,a);
                lcd_puts(a);   
                lcd_gotoxy(4,0);
                itoa(m,a);
                lcd_puts(a);
               }
               
              else
               {
                lcd_gotoxy(3,0);
                itoa(m,a);
                lcd_puts(a);
               }

                  //start for Sec DIM

               if(s<=9)     
                { 
                 lcd_gotoxy(6,0);
                 itoa(i,a);
                 lcd_puts(a);
                 lcd_gotoxy(7,0);
                 itoa(s,a);
                 lcd_puts(a);
                 delay_ms(30);
                }
               else
                {
                 lcd_gotoxy(6,0);
                 itoa(s,a);
                 lcd_puts(a);
                 delay_ms(30);
                } 
                LOOP:if(h==00,m==05,s==10)
                {
                PORTB=0x01;
                delay_ms(400);
                PORTB=0x00;}
                
           
                
                
                
           } //End of Sec
           goto LOOP;
          }  //End of Min    
         } //End of Hour
         
                 
      }
      
      
      
                  //End of While                                                        
 }   //End of intmain
 
