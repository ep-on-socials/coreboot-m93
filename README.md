# Lenovo ThinkCentre M93 SFF Coreboot Port

> [!WARNING]
> THIS HAS NOT YET BEEN COMPILED OR TESTED. USE AT YOUR OWN RISK.

 
The m93 (aka m93 sff) is smaller than the m93p which is a mini tower. It still has a PCI riser but it can only fit a small card e.g. network. There's neither space nor thermals for a dGPU as faras I know.

With many, many thanks to [jamesy0ung/coreboot-m93p](https://github.com/jamesy0ung/coreboot-m93p) and a wide variety of tools like demidecode, acpidump, flashrom, asl, superiotool, inteltool, etc upon which this rests. Investigating the hardware I have and creating this patch was heavily LLM driven and these changes have not yet been compiled, nevermind tested.


This is a standalone mainboard overlay and extracted firmware blobs (`descriptor.bin`, `gbe.bin`, `me.bin`, `vbt.bin`) for the Lenovo ThinkCentre M93 SFF.

## Apply this repo to a copy of upsteam coreboot

1. Clone upstream Coreboot:
   ```sh
   git clone https://coreboot.org
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

## License and Third-Party Notices
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Third-Party Content
This repository contains third-party code, libraries, or assets in [3rdparty](3rdparty/blobs/mainboard/lenovo/thinkcentre_m93) that may be governed by their own respective licenses. 
