#ifndef EITI_Driver_H
#define EITI_Driver_H
#include "GPIO.h"
#include<stdlib.h>
#include<stdint.h>

void MCAL_GPIO_INIT(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);


/*************************************
 * Peripheral instant
 ************************************/
//=====================================================================================

/*************************************
 * Pin Config Macros
 ************************************/

/* GPIO PINS DEF ref */
#define GPIO_PIN0				((uint16_t)0x0001) //Pin 0 Selected
#define GPIO_PIN1				((uint16_t)0x0002) //Pin 1 Selected
#define GPIO_PIN2				((uint16_t)0x0004) //Pin 2 Selected
#define GPIO_PIN3				((uint16_t)0x0008) //Pin 3 Selected
#define GPIO_PIN4				((uint16_t)0x0010) //Pin 4 Selected
#define GPIO_PIN5				((uint16_t)0x0020) //Pin 5 Selected
#define GPIO_PIN6				((uint16_t)0x0040) //Pin 6 Selected
#define GPIO_PIN7				((uint16_t)0x0080) //Pin 7 Selected
#define GPIO_PIN8				((uint16_t)0x0100) //Pin 8 Selected
#define GPIO_PIN9				((uint16_t)0x0200) //Pin 9 Selected
#define GPIO_PIN10				((uint16_t)0x0400) //Pin 10 Selected
#define GPIO_PIN11				((uint16_t)0x0800) //Pin 11 Selected
#define GPIO_PIN12				((uint16_t)0x1000) //Pin 12 Selected
#define GPIO_PIN13				((uint16_t)0x2000) //Pin 13 Selected
#define GPIO_PIN14				((uint16_t)0x4000) //Pin 14 Selected
#define GPIO_PIN15				((uint16_t)0x8000) //Pin 15 Selected
#define GPIO_PORT				((uint16_t)0xffff) //Port Selected

/* GPIO PIN STATUS DEF */
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0
/*Base Addresses for AHB Peripheral*/
//GPIO
#define GPIOA_BASE                             0x40010800
#define GPIOB_BASE                             0x40010C00
#define GPIOC_BASE                             0x40011000
#define GPIOD_BASE                             0x40011400
#define GPIOE_BASE                             0x40011800
#define GPIOF_BASE                             0x40011C00
#define GPIOG_BASE                             0x40012000


#define GPIOA					((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB					((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC					((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD					((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE					((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF					((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG					((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOA					((GPIO_TypeDef *)GPIOA_BASE)
#define RCC						((RCC_TypeDef  *)RCC_BASE)
#define EXTI					((EXTI_TypeDef *)EXTI_BASE)
#define AFIO					((AFIO_TypeDef *)AFIO_BASE)
//=====================================================================================
//=====================================================================================
//=====================================================================================


// macros for adresses
//NVIC
#define NVIC_BASE							   0xE000E100
#define NVIC_ISER0				*(volatile uint16_t*)(NVIC_BASE + 0x00)
#define NVIC_ISER1				*(volatile uint16_t*)(NVIC_BASE + 0x04)
#define NVIC_ISER2				*(volatile uint16_t*)(NVIC_BASE + 0x08)
#define NVIC_ICER0				*(volatile uint16_t*)(NVIC_BASE + 0x80)
#define NVIC_ICER1				*(volatile uint16_t*)(NVIC_BASE + 0x84)
#define NVIC_ICER2				*(volatile uint16_t*)(NVIC_BASE + 0x88)
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;
//EXTI
#define EXTI_BASE							   0x40010400

//AFIO
#define AFIO_BASE                              0x40010000

//EXTI
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40


//NVIC
#define NVIC_IRQ6_EXTI0_Enable 			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable 			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable 			(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable 			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable 			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable 			(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable 		(NVIC_ISER1 |= 1<<8)  //40 - 32 = 8

#define NVIC_IRQ6_EXTI0_Disable			    (NVIC_ICER0 |= (1<<6)
#define NVIC_IRQ7_EXTI1_Disable			    (NVIC_ICER0 |= (1<<7)
#define NVIC_IRQ8_EXTI2_Disable			(NVIC_ICER0 |= (1<<8)
#define NVIC_IRQ9_EXTI3_Disable			(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable		(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable      (NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable	(NVIC_ICER1 |= 1<<8)  //40 - 32 = 8


//=======================================================================================




typedef struct
{
	uint16_t  EXI_Inputline_number;
	GPIO_TypeDef*   GPIO_Port;
	uint16_t   GPIO_PIN;
	uint8_t IVT_IRQ_Number ;


}EXTI_GPIO_Maping_t;

typedef struct
{
	EXTI_GPIO_Maping_t EXIT_PIN;

	uint8_t    Trigger_Case ;

	uint8_t    IQR_EN ;

	void (* P_IQR_CallBack)(void);

}EXIT_PinConfig_t;


#define EXTI0 0

#define EXTI0_IQR	 6
#define EXTI1_IRQ	 7
#define EXTI2_IRQ	 8
#define EXTI3_IRQ	 9
#define EXTI4_IRQ    10
#define EXTI5_IRQ	 23
#define EXTI6_IRQ	 23
#define EXTI7_IRQ	 23
#define EXTI8_IRQ	 23
#define EXTI9_IRQ 	 23
#define EXTI10_IRQ	  40
#define EXTI11_IRQ	  40
#define EXTI12_IRQ	  40
#define EXTI13_IRQ	  40
#define EXTI14_IRQ 	  40
#define EXTI15_IRQ    40




//micors
#define EXTI0PA0  (EXTI_GPIO_Maping_t){EXTI0,GPIOA ,PIN_0,EXTI0_IRQ}
#define EXTI0PB0  (EXTI_GPIO_Maping_t){EXTI0, GPIOB,PIN_0,EXTI0_IRQ}
#define EXTI0PC0  (EXTI_GPIO_Maping_t){EXTI0, GPIOC,PIN_0,EXTI0_IRQ}
#define EXTI0PD0  (EXTI_GPIO_Maping_t){EXTI0, GPIOD,PIN_0,EXTI0_IRQ}
#define EXTI1PA1  (EXTI_GPIO_Maping_t){EXTI1,GPIOA ,PIN_1,EXTI1_IRQ}
#define EXTI1PB1  (EXTI_GPIO_Maping_t){EXTI1, GPIOB,PIN_1,EXTI1_IRQ}
#define EXTI1PC1  (EXTI_GPIO_Maping_t){EXTI1, GPIOC,PIN_1,EXTI1_IRQ}
#define EXTI1PD1  (EXTI_GPIO_Maping_t){EXTI1, GPIOD,PIN_1,EXTI1_IRQ}
#define EXTI2PA2  (EXTI_GPIO_Maping_t){EXTI2,GPIOA ,PIN_2,EXTI2_IRQ}
#define EXTI2PB2  (EXTI_GPIO_Maping_t){EXTI2, GPIOB,PIN_2,EXTI2_IRQ}
#define EXTI2PC2  (EXTI_GPIO_Maping_t){EXTI2, GPIOC,PIN_2,EXTI2_IRQ}
#define EXTI2PD2  (EXTI_GPIO_Maping_t){EXTI2, GPIOD,PIN_2,EXTI2_IRQ}
#define EXTI3PA3  (EXTI_GPIO_Maping_t){EXTI3,GPIOA ,PIN_3,EXTI3_IRQ}
#define EXTI3PB3  (EXTI_GPIO_Maping_t){EXTI3, GPIOB,PIN_3,EXTI3_IRQ}
#define EXTI3PC3  (EXTI_GPIO_Maping_t){EXTI3, GPIOC,PIN_3,EXTI3_IRQ}
#define EXTI3PD3  (EXTI_GPIO_Maping_t){EXTI3, GPIOD,PIN_3,EXTI3_IRQ}
#define EXTI4PA4  (EXTI_GPIO_Maping_t){EXTI4,GPIOA ,PIN_4,EXTI4_IRQ}
#define EXTI4PB4  (EXTI_GPIO_Maping_t){EXTI4, GPIOB,PIN_4,EXTI4_IRQ}
#define EXTI4PC4  (EXTI_GPIO_Maping_t){EXTI4, GPIOC,PIN_4,EXTI4_IRQ}
#define EXTI4PD4  (EXTI_GPIO_Maping_t){EXTI4, GPIOD,PIN_4,EXTI4_IRQ}
#define EXTI5PA5  (EXTI_GPIO_Maping_t){EXTI5,GPIOA ,PIN_5,EXTI5_IRQ}
#define EXTI5PB5  (EXTI_GPIO_Maping_t){EXTI5, GPIOB,PIN_5,EXTI5_IRQ}
#define EXTI5PC5  (EXTI_GPIO_Maping_t){EXTI5, GPIOC,PIN_5,EXTI5_IRQ}
#define EXTI5PD5  (EXTI_GPIO_Maping_t){EXTI5, GPIOD,PIN_5,EXTI5_IRQ}
#define EXTI6PA6  (EXTI_GPIO_Maping_t){EXTI6,GPIOA ,PIN_6,EXTI6_IRQ}
#define EXTI6PB6  (EXTI_GPIO_Maping_t){EXTI6, GPIOB,PIN_6,EXTI6_IRQ}
#define EXTI6PC6  (EXTI_GPIO_Maping_t){EXTI6, GPIOC,PIN_6,EXTI6_IRQ}
#define EXTI6PD6  (EXTI_GPIO_Maping_t){EXTI6, GPIOD,PIN_6,EXTI6_IRQ}
#define EXTI7PA7  (EXTI_GPIO_Maping_t){EXTI7,GPIOA ,PIN_7,EXTI7_IRQ}
#define EXTI7PB7  (EXTI_GPIO_Maping_t){EXTI7, GPIOB,PIN_7,EXTI7_IRQ}
#define EXTI7PC7  (EXTI_GPIO_Maping_t){EXTI7, GPIOC,PIN_7,EXTI7_IRQ}
#define EXTI7PD7  (EXTI_GPIO_Maping_t){EXTI7, GPIOD,PIN_7,EXTI7_IRQ}
#define EXTI8PA8  (EXTI_GPIO_Maping_t){EXTI8,GPIOA ,PIN_8,EXTI8_IRQ}
#define EXTI8PB8  (EXTI_GPIO_Maping_t){EXTI8, GPIOB,PIN_8,EXTI8_IRQ}
#define EXTI8PC8  (EXTI_GPIO_Maping_t){EXTI8, GPIOC,PIN_8,EXTI8_IRQ}
#define EXTI8PD8  (EXTI_GPIO_Maping_t){EXTI8, GPIOD,PIN_8,EXTI8_IRQ}
#define EXTI9PA9  (EXTI_GPIO_Maping_t){EXTI9,GPIOA ,PIN_9,EXTI9_IRQ}
#define EXTI9PB9  (EXTI_GPIO_Maping_t){EXTI9, GPIOB,PIN_9,EXTI9_IRQ}
#define EXTI9PC9  (EXTI_GPIO_Maping_t){EXTI9, GPIOC,PIN_9,EXTI9_IRQ}
#define EXTI9PD9  (EXTI_GPIO_Maping_t){EXTI9, GPIOD,PIN_9,EXTI9_IRQ}
#define EXTI10PA10  (EXTI_GPIO_Maping_t){EXTI10,GPIOA ,PIN_10,EXTI10_IRQ}
#define EXTI10PB10  (EXTI_GPIO_Maping_t){EXTI10, GPIOB,PIN_10,EXTI10_IRQ}
#define EXTI10PC10  (EXTI_GPIO_Maping_t){EXTI10, GPIOC,PIN_10,EXTI10_IRQ}
#define EXTI10PD10  (EXTI_GPIO_Maping_t){EXTI10, GPIOD,PIN_10,EXTI10_IRQ}
#define EXTI11PA11  (EXTI_GPIO_Maping_t){EXTI11,GPIOA ,PIN_11,EXTI11_IRQ}
#define EXTI11PB11  (EXTI_GPIO_Maping_t){EXTI11, GPIOB,PIN_11,EXTI11_IRQ}
#define EXTI11PC11  (EXTI_GPIO_Maping_t){EXTI11, GPIOC,PIN_11,EXTI11_IRQ}
#define EXTI11PD11  (EXTI_GPIO_Maping_t){EXTI11, GPIOD,PIN_11,EXTI11_IRQ}
#define EXTI12PA12  (EXTI_GPIO_Maping_t){EXTI12,GPIOA ,PIN_12,EXTI12_IRQ}
#define EXTI12PB12  (EXTI_GPIO_Maping_t){EXTI12, GPIOB,PIN_12,EXTI12_IRQ}
#define EXTI12PC12  (EXTI_GPIO_Maping_t){EXTI12, GPIOC,PIN_12,EXTI12_IRQ}
#define EXTI12PD12  (EXTI_GPIO_Maping_t){EXTI12, GPIOD,PIN_12,EXTI12_IRQ}
#define EXTI13PA13  (EXTI_GPIO_Maping_t){EXTI13,GPIOA ,PIN_13,EXTI13_IRQ}
#define EXTI13PB13  (EXTI_GPIO_Maping_t){EXTI13, GPIOB,PIN_13,EXTI13_IRQ}
#define EXTI13PC13  (EXTI_GPIO_Maping_t){EXTI13, GPIOC,PIN_13,EXTI13_IRQ}
#define EXTI13PD13  (EXTI_GPIO_Maping_t){EXTI13, GPIOD,PIN_13,EXTI13_IRQ}
#define EXTI14PA14  (EXTI_GPIO_Maping_t){EXTI14,GPIOA ,PIN_14,EXTI14_IRQ}
#define EXTI14PB14  (EXTI_GPIO_Maping_t){EXTI14, GPIOB,PIN_14,EXTI14_IRQ}
#define EXTI14PC14  (EXTI_GPIO_Maping_t){EXTI14, GPIOC,PIN_14,EXTI14_IRQ}
#define EXTI14PD14  (EXTI_GPIO_Maping_t){EXTI14, GPIOD,PIN_14,EXTI14_IRQ}
#define EXTI15PA15  (EXTI_GPIO_Maping_t){EXTI15,GPIOA ,PIN_15,EXTI15_IRQ}
#define EXTI15PB15  (EXTI_GPIO_Maping_t){EXTI15, GPIOB,PIN_15,EXTI15_IRQ}
#define EXTI15PC15  (EXTI_GPIO_Maping_t){EXTI15, GPIOC,PIN_15,EXTI15_IRQ}
#define EXTI15PD15  (EXTI_GPIO_Maping_t){EXTI15, GPIOD,PIN_15,EXTI15_IRQ}

//EXTI_Trigger
#define EXTI_Trigger_RISING       0
#define EXTI_Trigger_FALLING      1
#define EXTI_Trigger_BOTH         2

// EXTI_IQR_define
#define EXTI_IQR_Disable	 0
#define EXTI_IQR_Enable      1
//API's
void MCAL_EXTI_GPIO_Init (EXIT_PinConfig_t* EXIT_Config);
void MCAL_GPIO_INIT(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_EXTI_GPIO_DeInit (void);
void MCAL_EXTI_GPIO_Upate (EXIT_PinConfig_t* EXIT_Config);



#endif
