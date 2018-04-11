#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

//#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif

void rutinaDeError();
void main (void){
   setup_oscillator(OSC_16MHZ);
#ifdef __DEBUG_SERIAL__ //Deberiamos de proteger nuestras depuraciones de esta forma o usar una macro ya protegida.
   printf("Hola Mundo\n");//Puedes usar putc o printf. Revisa la documentación de CCS para ver que mas puedes hacer.
#endif
   while(1){
      
   }
}	
void rutinaDeError(){
    for(int i = 0 ; i < 5 ; i++){
        output_a(0xFF);
        output_b(0x0F);
        output_e(0x07);
        delay_ms(150);
        output_a(0x00);
        output_b(0x00);
        output_e(0x00);
        delay_ms(150);
    }
}

