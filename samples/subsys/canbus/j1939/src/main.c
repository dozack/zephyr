/*
 * Copyright (c) 2024 Zoltan Dolensky
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/canbus/j1939.h>

const struct device *can;

int main(void)
{
	int ret = 0;

	can = DEVICE_DT_GET(DT_CHOSEN(zephyr_canbus));
	if (!device_is_ready(can)) {
		printk("CAN: Device driver not ready.\n");
		return 0;
	}

	can_mode_t mode = CAN_MODE_NORMAL;
	ret = can_set_mode(can, mode);
	if (ret != 0) {
		printk("CAN: Failed to set mode [%d]", ret);
		return 0;
	}

	ret = can_start(can);
	if (ret != 0) {
		printk("CAN: Failed to start device [%d]\n", ret);
		return 0;
	}

	struct can_frame tx_frame = {.flags = 0, .id = 0xff, .dlc = 1};

	for (;;) {
		ret = can_send(can, &tx_frame, K_FOREVER, NULL, NULL);

		if (ret != 0) {
			printk("CAN: Failed to send frame [%d]\n", ret);
			break;
		}

		k_sleep(K_MSEC(100));
	}

	return 0;
}
