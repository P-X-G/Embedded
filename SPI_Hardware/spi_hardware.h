#include "stm32f10x.h"
#include "stm32f10x_spi.h"

#define SPIx_RCC				RCC_APB2Periph_SPI1
#define SPIx						SPI1
#define SPI_GPIO_RCC		RCC_APB2Periph_GPIOA
#define SPI_GPIO				GPIOA
#define SPI_PIN_MOSI		GPIO_Pin_7
#define SPI_PIN_MISO		GPIO_Pin_6
#define SPI_PIN_SCK			GPIO_Pin_5
#define SPI_PIN_SS			GPIO_Pin_4

#define DISABLE_SPIx		SPI_Cmd(SPIx, DISABLE); \
												RCC_APB2PeriphClockCmd(SPIx_RCC, DISABLE);  \
												RCC_APB2PeriphClockCmd(SPI_GPIO_RCC, DISABLE)

#define E_OK 				(Std_ReturnType)0
#define E_NOT_OK 		(Std_ReturnType)1

GPIO_InitTypeDef GPIO_InitStruct;

typedef SPI_InitTypeDef Spi_ConfigType;

typedef uint8_t Std_ReturnType;

typedef uint8_t Spi_ChannelType;

typedef uint8_t Spi_DataBufferType;


void Spi_Init(Spi_ConfigType* ConfigPtr);

Std_ReturnType Spi_DeInit(void);

Std_ReturnType Spi_WriteIB (Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPtr);

Std_ReturnType Spi_ReadIB (Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPointer);