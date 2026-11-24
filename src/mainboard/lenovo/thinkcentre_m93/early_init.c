/* SPDX-License-Identifier: GPL-2.0-only */

#include <bootblock_common.h>
#include <device/pnp_ops.h>
#include <superio/ite/common/ite.h>
#include <superio/ite/it8728f/it8728f.h>

#define SUPERIO_BASE 0x2e
#define SIO_EC       PNP_DEV(SUPERIO_BASE, IT8728F_EC)
#define SIO_GPIO     PNP_DEV(SUPERIO_BASE, IT8728F_GPIO)
#define SERIAL_DEV   PNP_DEV(SUPERIO_BASE, IT8728F_SP1)

void bootblock_mainboard_early_init(void)
{
	/* Initialize SuperIO serial port */
	ite_enable_serial(SERIAL_DEV, CONFIG_TTYS0_BASE);

	/* Kill watchdog first to prevent reboot */
	ite_kill_watchdog(SIO_GPIO);

	/* Disable SIO reboot */
	ite_reg_write(SIO_GPIO, 0xef, 0x7e);

	/* Configure LDN 0x07 multi-function pin muxing for PWM/tach/PECI */
	ite_reg_write(SIO_GPIO, 0x25, 0x01);
	ite_reg_write(SIO_GPIO, 0x28, 0xd7);
	ite_reg_write(SIO_GPIO, 0x29, 0x80);
	ite_reg_write(SIO_GPIO, 0x2a, 0x02);
	ite_reg_write(SIO_GPIO, 0x2c, 0x8a);
	ite_reg_write(SIO_GPIO, 0x2d, 0x04);

	/* Configure GPIO base address to 0x0a00 */
	ite_reg_write(SIO_GPIO, 0x62, 0x0a);

	/* Clear watchdog timeout */
	ite_reg_write(SIO_GPIO, 0x72, 0x20);
	ite_reg_write(SIO_GPIO, 0x73, 0x00);

	/* Activate LDN 0x04 Environment Controller at 0x0a40 / 0x0a30 */
	ite_reg_write(SIO_EC, 0x60, 0x0a);
	ite_reg_write(SIO_EC, 0x61, 0x40);
	ite_reg_write(SIO_EC, 0x62, 0x0a);
	ite_reg_write(SIO_EC, 0x63, 0x30);
	ite_reg_write(SIO_EC, 0xf0, 0x80);
	ite_reg_write(SIO_EC, 0xf6, 0xf0);
	ite_reg_write(SIO_EC, 0x30, 0x01);
}
