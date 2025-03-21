#
# Copyright (c) 2024 Zoltan Dolensky
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_J1939 j1939.c)
