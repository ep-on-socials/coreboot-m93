/* SPDX-License-Identifier: GPL-2.0-only */

#include <arch/io.h>
#include <stdint.h>
#include <northbridge/intel/haswell/haswell.h>
#include <southbridge/intel/lynxpoint/pch.h>

#define EC_BASE_ADDR	0x0a40
#define EC_INDEX_PORT	(EC_BASE_ADDR + 5)
#define EC_DATA_PORT	(EC_BASE_ADDR + 6)

static void it8733f_ec_write(uint8_t reg, uint8_t val)
{
	outb(reg, EC_INDEX_PORT);
	outb(val, EC_DATA_PORT);
}

static void it8733f_init_smartguardian(void)
{
	/* Enable fan tachometers 1-3 and configure 23.43 kHz active-high PWM */
	it8733f_ec_write(0x00, 0x19);
	it8733f_ec_write(0x0c, 0x10);
	it8733f_ec_write(0x13, 0x77);
	it8733f_ec_write(0x14, 0xc0);
	it8733f_ec_write(0x15, 0x00);
	it8733f_ec_write(0x16, 0x00);
	it8733f_ec_write(0x17, 0x00);
	it8733f_ec_write(0x51, 0x05);
	it8733f_ec_write(0x5c, 0x60);

	/* Fan 1-3 SmartGuardian temperature thresholds & PWM duty cycle */
	it8733f_ec_write(0x60, 0x7f);
	it8733f_ec_write(0x61, 0x7f);
	it8733f_ec_write(0x62, 0x7f);
	it8733f_ec_write(0x63, 0x47);
	it8733f_ec_write(0x64, 0x00);
	it8733f_ec_write(0x66, 0x0f);
	it8733f_ec_write(0x67, 0xff);

	it8733f_ec_write(0x68, 0x7f);
	it8733f_ec_write(0x69, 0x7f);
	it8733f_ec_write(0x6a, 0x7f);
	it8733f_ec_write(0x6b, 0xff);
	it8733f_ec_write(0x6c, 0x00);
	it8733f_ec_write(0x6e, 0x0f);
	it8733f_ec_write(0x6f, 0xff);

	it8733f_ec_write(0x70, 0x7f);
	it8733f_ec_write(0x71, 0x7f);
	it8733f_ec_write(0x72, 0x7f);
	it8733f_ec_write(0x73, 0xff);
	it8733f_ec_write(0x74, 0x00);
	it8733f_ec_write(0x76, 0x0f);

	/* PECI / secondary thermal curve bank (0x89-0x9f) */
	it8733f_ec_write(0x89, 0x30);
	it8733f_ec_write(0x8a, 0x05);
	it8733f_ec_write(0x8b, 0x05);
	it8733f_ec_write(0x8c, 0xa1);
	it8733f_ec_write(0x8e, 0x00);
	it8733f_ec_write(0x8f, 0x40);
	it8733f_ec_write(0x98, 0x02);
	it8733f_ec_write(0x99, 0x97);
	it8733f_ec_write(0x9c, 0x40);
	it8733f_ec_write(0x9d, 0x96);
	it8733f_ec_write(0x9e, 0xc0);
	it8733f_ec_write(0x9f, 0x01);
}

void mainboard_config_rcba(void)
{
}

void mb_late_romstage_setup(void)
{
	/* LPC generic decode 0x0a00-0x0a7f is active here */
	it8733f_init_smartguardian();
}

const struct usb2_port_config mainboard_usb2_ports[MAX_USB2_PORTS] = {
	/* Length, Enable, OCn#, Location */
	{ 0x0080, 1, 0, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, 0, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, 1, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, 1, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 2, USB_PORT_BACK_PANEL },
	{ 0x0040, 1, 3, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, USB_OC_PIN_SKIP, USB_PORT_FLEX },
	{ 0x0080, 1, USB_OC_PIN_SKIP, USB_PORT_FLEX },
	{ 0x0080, 1, 5, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, 5, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, 6, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, 6, USB_PORT_BACK_PANEL },
	{ 0x0080, 1, USB_OC_PIN_SKIP, USB_PORT_FLEX },
	{ 0x0040, 1, USB_OC_PIN_SKIP, USB_PORT_FLEX },
};

const struct usb3_port_config mainboard_usb3_ports[MAX_USB3_PORTS] = {
	{ 1, 0 },
	{ 1, 0 },
	{ 1, 1 },
	{ 1, 1 },
	{ 1, 6 },
	{ 1, 6 },
};
