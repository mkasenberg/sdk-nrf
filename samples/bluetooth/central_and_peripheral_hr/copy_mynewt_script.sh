#!/bin/bash

echo "HELLO"

netcore_app="/home/magda/ncs/v2.7.0/nrf/samples/bluetooth/central_and_peripheral_hr/build/empty_net_core/zephyr"

current_dir=$(pwd)

# Check if the current directory is /home/magda/work
if [ "$current_dir" = "$netcore_app" ]; then
    echo "MERGING MY HEX"

    mergehex -m zephyr.hex /home/magda/mynewt/bin/zephyr.hex -o my_zephyr_merged.hex
    cp zephyr.hex zephyr.hex.org
    cp my_zephyr_merged.hex zephyr.hex
fi
