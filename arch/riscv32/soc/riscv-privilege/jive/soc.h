#ifndef __RISCV32_JIVE_SOC_H_
#define __RISCV32_JIVE_SOC_H_

#include <soc_common.h>

/* UART peripheral */
#define RISCV_JIVE_UART_BASE         0x00020000

/* Timer configuration */
#define RISCV_MTIME_BASE             0x0001C000
#define RISCV_MTIMECMP_BASE          0x00014000

/* lib-c hooks required RAM defined variables */
#define RISCV_RAM_BASE               CONFIG_RISCV_RAM_BASE_ADDR
#define RISCV_RAM_SIZE               CONFIG_RISCV_RAM_SIZE

#endif /* __RISCV32_JIVE_SOC_H_ */
