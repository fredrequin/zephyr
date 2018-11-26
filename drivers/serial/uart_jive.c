/*
 * Copyright (c) 2018 Frédéric REQUIN
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <arch/cpu.h>
#include <uart.h>
#include <sys_io.h>
//#include <board.h>

#define DEV_CFG(dev) \
((const struct uart_device_config * const)(dev)->config->config_info)

static unsigned char uart_jive_poll_out(struct device *dev, unsigned char ch)
{
    sys_write8(ch, DEV_CFG(dev)->regs);

    return ch;
}

static int uart_jive_poll_in(struct device *dev, unsigned char *p_ch)
{
    *p_ch = sys_read8(DEV_CFG(dev)->regs);
    
    return 0;
}

static int uart_jive_init(struct device *dev)
{
    ARG_UNUSED(dev);

    /* Nothing to do */

    return 0;
}

static const struct uart_driver_api uart_jive_driver_api =
{
    .poll_in   = uart_jive_poll_in,
    .poll_out  = uart_jive_poll_out,
    .err_check = NULL,
};

static const struct uart_device_config uart_jive_dev_cfg_0 =
{
    .regs      = RISCV_JIVE_UART_BASE,
};

DEVICE_AND_API_INIT(uart_jive0, CONFIG_UART_JIVE_PORT_0_NAME,
                    uart_jive_init, NULL,
                    &uart_jive_dev_cfg_0,
                    PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
                    (void *)&uart_jive_driver_api);
