#
# Copyright (c) 2022 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)

set(DTC_OVERLAY_FILE "./nrf54.overlay")
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(empty_net_core)

target_include_directories(app PRIVATE ./src)
# NORDIC SDK APP START
target_sources(app PRIVATE
        src/main.c
        )
# NORDIC SDK APP END
