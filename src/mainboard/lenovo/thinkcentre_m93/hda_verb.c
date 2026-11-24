/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	/* coreboot specific header: Intel Haswell HDMI (Address 0) */
	0x80862807,	/* Codec Vendor / Device ID: Intel Haswell HDMI */
	0x80860101,	/* Subsystem ID */
	4,		/* Number of 4 dword sets */
	AZALIA_SUBVENDOR(0, 0x80860101),

	/* Pin Widget Verb Table: Intel Haswell HDMI */
	AZALIA_PIN_CFG(0, 0x05, 0x18560010),
	AZALIA_PIN_CFG(0, 0x06, 0x18560020),
	AZALIA_PIN_CFG(0, 0x07, 0x58560030),

	/* coreboot specific header: Realtek ALC3239 / ALC283 (Address 2) */
	0x10ec0283,	/* Codec Vendor / Device ID: Realtek ALC3239 */
	0x17aa30a3,	/* Subsystem ID */
	11,		/* Number of 4 dword sets */
	AZALIA_SUBVENDOR(2, 0x17aa30a3),

	/* Pin Widget Verb Table: Realtek ALC3239 */
	AZALIA_PIN_CFG(2, 0x12, 0x40000000),
	AZALIA_PIN_CFG(2, 0x14, 0x90170120),
	AZALIA_PIN_CFG(2, 0x17, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x18, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x19, 0x02a19030),
	AZALIA_PIN_CFG(2, 0x1a, 0x01a19040),
	AZALIA_PIN_CFG(2, 0x1b, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x1d, 0x40400001),
	AZALIA_PIN_CFG(2, 0x1e, 0x411111f0),
	AZALIA_PIN_CFG(2, 0x21, 0x02214010),
};

const u32 pc_beep_verbs[0] = {};

AZALIA_ARRAY_SIZES;

