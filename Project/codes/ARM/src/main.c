#include "Fw_global_config.h"   // This defines application specific charactersitics

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "RtosTask.h"

/*    Include the generic headers required for QORC */
#include "eoss3_hal_gpio.h"
#include "eoss3_hal_rtc.h"
#include "eoss3_hal_timer.h"
#include "eoss3_hal_fpga_usbserial.h"
#include "ql_time.h"
#include "s3x_clock_hal.h"
#include "s3x_clock.h"
#include "s3x_pi.h"
#include "dbg_uart.h"
#include "eoss3_hal_uart.h"
#define PI 3.14
#include "cli.h"


extern const struct cli_cmd_entry my_main_menu[];


const char *SOFTWARE_VERSION_STR;


/*
 * Global variable definition
 */


extern void qf_hardwareSetup();
static void nvic_init(void);

#define GPIO_OUTPUT_MODE (1)
#define GPIO_INPUT_MODE (0)
void PyHal_GPIO_SetDir(uint8_t gpionum,uint8_t iomode);
int PyHal_GPIO_GetDir(uint8_t gpionum);
int PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval);
int PyHal_GPIO_Get(uint8_t gpionum);
float lowpass(float c[50],float wc, int n);
void print_float(float* num);
float* convolutionfun(float a[50],float b[50]);

int main(void)
{
    uint32_t i=0,j=0,k=0;
    SOFTWARE_VERSION_STR = "qorc-onion-apps/qf_hello-fpga-gpio-ctlr";

    qf_hardwareSetup();
    nvic_init();

    dbg_str("\n\n");
    dbg_str( "##########################\n");
    dbg_str( "Quicklogic QuickFeather FPGA GPIO CONTROLLER EXAMPLE\n");
    dbg_str( "SW Version: ");
    dbg_str( SOFTWARE_VERSION_STR );
    dbg_str( "\n" );
    dbg_str( __DATE__ " " __TIME__ "\n" );
    dbg_str( "##########################\n\n");

    dbg_str( "\n\nHello GPIO!!\n\n");	// <<<<<<<<<<<<<<<<<<<<<  Change me!

    CLI_start_task( my_main_menu );
	HAL_Delay_Init();
    int count = 2;
    int r;
    while(1)
    {
        //Reading the samples from ESP32 using UART communication
        char buffer[200];
        uint8_t ind = 0;
        r = 0;
        while (r!=10)
        {
            if(!(UART->UART_TFR & UART_TFR_RX_FIFO_EMPTY)) {
                r = UART->UART_DR;
                r = r & 0x0ff;
                buffer[ind] = (char)r;
                ind++;
            }
        }

        //Parsing the received samples in string form into float array for processing.
        char* pEnd;
        char toPrint[20];
        float wc;
        wc = strtof((const char*)buffer,&pEnd);
        int i;
        float in;
        float h;
        float* o;
        int m = 24;
        int n=11;

          for(i=0;i<m;i++)
          {
              in[i] = 3*(sin(PI/2))+ 2*(sin(2*PI/3)) + sin(5*PI/6);
          }  
        //low pass filter
        lowpass(h,wc,n);

        o = convolutionfun(in,h);

        //Sending the output samples back to ESP32 using UART communiaction
        float *x = o;
        while((n+m-1)--) {
            print_float(x);
            x++;
        }
        dbg_str("x\n");
        HAL_DelayUSec(500000);
    }
}

static void nvic_init(void)
 {
    // To initialize system, this interrupt should be triggered at main.
    // So, we will set its priority just before calling vTaskStartScheduler(), not the time of enabling each irq.
    NVIC_SetPriority(Ffe0_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(SpiMs_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(CfgDma_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(Uart_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(FbMsg_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
 }

//needed for startup_EOSS3b.s asm file
void SystemInit(void)
{

}

//gpionum --> 0 --> 31 corresponding to the IO PADs
//gpioval --> 0 or 1
#define FGPIO_DIRECTION_REG (0x40024008)
#define FGPIO_OUTPUT_REG (0x40024004)
#define FGPIO_INPUT_REG (0x40024000)
//Set GPIO(=gpionum) Mode: Input(iomode = 0) or Output(iomode = 1)
//Before Set/Get GPIO value, the direction must be correctly set
void PyHal_GPIO_SetDir(uint8_t gpionum,uint8_t iomode)
{
    uint32_t tempscratch32;

    if (gpionum > 31)
        return;

    tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);
    if (iomode)
        *(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 | (0x1 << gpionum);
    else
        *(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 & (~(0x1 << gpionum));

}


//Get current GPIO(=gpionum) Mode: Input(iomode = 0) or Output(iomode = 1)
int PyHal_GPIO_GetDir(uint8_t gpionum)
{
    uint32_t tempscratch32;
    int result = 0;

    if (gpionum > 31)
        return -1;

    tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);

    result = ((tempscratch32 & (0x1 << gpionum)) ? GPIO_OUTPUT_MODE : GPIO_INPUT_MODE);

    return result;
}

//Set GPIO(=gpionum) to 0 or 1 (= gpioval)
//The direction must be set as Output for this GPIO already
//Return value = 0, success OR -1 if error.
int PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval)
{
    uint32_t tempscratch32;

    if (gpionum > 31)
        return -1;

    tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);

    //Setting Direction moved out as separate API, we will only check
    //*(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 | (0x1 << gpionum);
    if (!(tempscratch32 & (0x1 << gpionum)))
    {
        //Direction not Set to Output
        return -1;
    }

    tempscratch32 = *(uint32_t*)(FGPIO_OUTPUT_REG);

    if(gpioval > 0)
    {
        *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 | (0x1 << gpionum);
    }
    else
    {
        *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 & ~(0x1 << gpionum);
    }

    return 0;
}
//Get GPIO(=gpionum): 0 or 1 returned (or in erros -1)
//The direction must be set as Input for this GPIO already
int PyHal_GPIO_Get(uint8_t gpionum)
{
    uint32_t tempscratch32;
    uint32_t gpioval_input;

    if (gpionum > 31)
        return -1;

    tempscratch32 = *(uint32_t*)(FGPIO_INPUT_REG);
    gpioval_input = (tempscratch32 >> gpionum) & 0x1;

    return ((int)gpioval_input);
}

float lowpass(float c[50], float wc, int n)
                        {                 
                            int i;   
                            float a[50], b[50];
                             for(i=0;i<n;i++)
                                    {
                                                 if(i==(n-1)/2)                  
                                                          {                                      
                                                         a[i]=wc/PI; 
                                                          }
                        else                              {                        
                                                                a[i]=(sin(wc*(i-((n-1)/2)))/(PI*(i-(n-1)/2)));
                                                         }
                        //hamming window
                        b[i]= (0.54-0.46*(cos((2*PI)/(n-1))));
                        c[i] = a[i]*b[i];
                                    }
                        }

void print_float(float* num)
{
    float a = *num;
    if(a<0 && a>-1) dbg_str("-");
    dbg_int((int)a);
    dbg_str(".");
    int afterDecimal = (int)((a - (int)a)*100);
    if(afterDecimal<0)
        dbg_int(-afterDecimal);
    else
        dbg_int(afterDecimal);
    dbg_str(" ");
}


float* convolutionfun(float a[50],float b[50])
    {
		int m,n,i,j;
		// padding of zeors
		m=24;
		n=11;
        float* c= (float*) calloc(n, sizeof(float));
		for(i=m;i<=m+n-1;i++)
		{
			a[i]=0;
		}
		for(i=n;i<=m+n-1;i++)
		{
			b[i]=0;
		for(i=0;i<m+n-1;i++)
        	{
			c[i]=0;
            for(j=0;j<=i;j++)
            {
				c[i]=c[i]+(a[j]*b[i-j]);
            }
         	}
	}
    return c;
}