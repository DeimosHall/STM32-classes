#define val0 500
#define val1 1000
#define val2 2000

typedef enum{
medio_seg=val0,
uno_seg=val1,
dos_seg=val2
}retardo;

#define LED_PIN GPIO_PIN_13 //Ajustamos el pin del puerto
#define LED_PORT GPIOC //Ajustamos el puerto

void LED_init(void);
void my_delay(retardo tiempo);
