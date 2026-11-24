## SPDX-License-Identifier: GPL-2.0-only

bootblock-y += bootblock.c
bootblock-y += early_init.c
bootblock-y += gpio.c

romstage-y += early_init.c
romstage-y += gpio.c
romstage-y += romstage.c

ramstage-$(CONFIG_MAINBOARD_USE_LIBGFXINIT) += gma-mainboard.ads
