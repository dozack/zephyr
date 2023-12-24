/**
 * Texas Instruments Hercules MCU Family
 *
 * Copyright (c) 2023 Texas Instruments Incorporated
 * Copyright (C) 2023 Zoltan Dolensky
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>

#include <zephyr/fatal.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <zephyr/drivers/interrupt_controller/intc_vim.h>

static int tms570lc43x_init(void) { return 0; }

unsigned int z_soc_irq_get_active(void) { return z_vim_irq_get_active(); }

void z_soc_irq_eoi(unsigned int irq) { z_vim_irq_eoi(irq); }

void z_soc_irq_init(void) { z_vim_irq_init(); }

void z_soc_irq_priority_set(unsigned int irq, unsigned int prio,
                            uint32_t flags) {
  /* Configure interrupt type and priority */
  z_vim_irq_priority_set(irq, prio, flags);
}

void z_soc_irq_enable(unsigned int irq) {
  /* Enable interrupt */
  z_vim_irq_enable(irq);
}

void z_soc_irq_disable(unsigned int irq) {
  /* Disable interrupt */
  z_vim_irq_disable(irq);
}

int z_soc_irq_is_enabled(unsigned int irq) {
  /* Check if interrupt is enabled */
  return z_vim_irq_is_enabled(irq);
}

SYS_INIT(tms570lc43x_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);