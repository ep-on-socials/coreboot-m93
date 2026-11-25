# Lenovo ThinkCentre M93 SFF Coreboot Port

> [!WARNING]
> THIS HAS NOT YET BEEN COMPILED OR TESTED. USE AT YOUR OWN RISK.

 
The m93 (aka m93 sff) is smaller than the m93p which is a mini tower. It still has a PCI riser but it can only fit a small card e.g. network. There's neither space nor thermals for a dGPU as faras I know.

With many, many thanks to [jamesy0ung/coreboot-m93p](https://github.com/jamesy0ung/coreboot-m93p) and a wide variety of tools like demidecode, acpidump, flashrom, asl, superiotool, inteltool, etc upon which this rests. Investigating the hardware I have and creating this patch was heavily LLM driven and these changes have not yet been compiled, nevermind tested.


This is a standalone mainboard overlay and extracted firmware blobs (`descriptor.bin`, `gbe.bin`, `me.bin`, `vbt.bin`) for the Lenovo ThinkCentre M93 SFF.

## Apply this repo to a copy of upsteam coreboot

1. Clone upstream Coreboot:
   ```sh
   git clone https://github.com/coreboot/coreboot.git
   ```
2. Apply this overlay to your Coreboot checkout:
   ```sh
   ./apply_overlay.sh /path/to/coreboot
   ```
3. Configure and build inside the Coreboot directory:
   ```sh
   cd /path/to/coreboot
   make menuconfig   # Select Mainboard -> Lenovo -> ThinkCentre M93
   make
   ```

# Build

I *think* this config yanked from m93p repo should work. Needs testing

```
CONFIG_VENDOR_LENOVO=y
CONFIG_BOARD_LENOVO_THINKCENTRE_M93=y
CONFIG_CBFS_SIZE=0x00680000
CONFIG_USE_NATIVE_RAMINIT=y
CONFIG_HAVE_IFD_BIN=y
CONFIG_IFD_BIN_PATH="3rdparty/blobs/mainboard/lenovo/thinkcentre_m93/descriptor.bin"
CONFIG_HAVE_ME_BIN=y
CONFIG_ME_BIN_PATH="3rdparty/blobs/mainboard/lenovo/thinkcentre_m93/me.bin"
CONFIG_STRIP_ME_BIN=y
CONFIG_HAVE_GBE_BIN=y
CONFIG_GBE_BIN_PATH="3rdparty/blobs/mainboard/lenovo/thinkcentre_m93/gbe.bin"
CONFIG_MAINBOARD_USE_LIBGFXINIT=y
CONFIG_GENERIC_LINEAR_FRAMEBUFFER=y
CONFIG_INTEL_GMA_ADD_VBT=y
CONFIG_INTEL_GMA_VBT_FILE="3rdparty/blobs/mainboard/lenovo/thinkcentre_m93/vbt.bin"
CONFIG_DRIVERS_UART_8250IO=y
CONFIG_CONSOLE_SERIAL=y
CONFIG_BOOTBLOCK_CONSOLE=y
CONFIG_POSTCAR_CONSOLE=y
CONFIG_SQUELCH_EARLY_SMP=y
# CONFIG_CONSOLE_SPI_FLASH is not set
```

## License and Third-Party Notices
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Third-Party Content
This repository contains third-party code, libraries, or assets in [3rdparty](3rdparty/blobs/mainboard/lenovo/thinkcentre_m93) that may be governed by their own respective licenses. 
