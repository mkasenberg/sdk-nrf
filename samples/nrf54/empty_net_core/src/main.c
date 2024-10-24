/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <errno.h>
//#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>

/* Access the Mynewt memory address and size */
#define MYNEWT_MEM_NODE DT_NODELABEL(mynewt_memory)

/* Get the starting address and size from the device tree */
#define MYNEWT_START_ADDR DT_REG_ADDR(MYNEWT_MEM_NODE)
#define MYNEWT_SIZE       DT_REG_SIZE(MYNEWT_MEM_NODE)

typedef void (*mynewt_entry_t)(void);
volatile int hello = 1;

int main(void)
{
    int err;

    mynewt_entry_t *mynewt_start = (mynewt_entry_t*)MYNEWT_START_ADDR;

    __set_PSPLIM(0);
    __set_MSPLIM(0);
    __set_MSP(mynewt_start[0]);
    mynewt_start[1]();

    while(hello);

	return 0; /* Dummy application. Unused main */
}
