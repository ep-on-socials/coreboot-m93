# ThinkCentre M93 Firmware Blobs

## Files in This Directory
* `descriptor.bin` — Intel Flash Descriptor (IFD)
* `me.bin` — Intel Management Engine firmware
* `gbe.bin` — **Sanitized** Intel I217-LM Gigabit Ethernet NVM image (contains a placeholder MAC address for reproducible/CI builds)

## Extracting Your Machine's Factory `gbe.bin`
Before flashing a full SPI image onto physical hardware, extract your board's unique `gbe.bin` so the onboard Intel I217-LM NIC retains its factory MAC address and valid NVM checksum.

### 1. Dump the Stock GbE Region
Boot Linux with `iomem=relaxed` (if reading internally) or attach an external SPI programmer, then read only the `gbe` region defined by the IFD:

```sh
# Internal programmer (requires iomem=relaxed kernel parameter)
flashrom -p internal --ifd -i gbe -r stock_gbe_dump.rom
```
*(Alternatively, if you already have a full 12 MB stock ROM dump `stock.rom`, skip `flashrom` and proceed directly to `ifdtool` below.)*

### 2. Extract `flashregion_3_gbe.bin` Using `ifdtool`
Build `ifdtool` from the coreboot tree if you haven't already, then unpack the regions:

```sh
make -C util/ifdtool
./util/ifdtool/ifdtool -x stock_gbe_dump.rom
```
This outputs `flashregion_3_gbe.bin` (8 KB) in the current directory.

### 3. Verify the Extracted MAC Address
Inspect the first 6 bytes of `flashregion_3_gbe.bin` to confirm your board's factory MAC address is intact:

```sh
hexdump -C -n 16 flashregion_3_gbe.bin
```

### 4. Configure coreboot to Use Your Local `gbe.bin`
Copy the extracted file to an untracked location (such as `build/gbe_local.bin`) so Git stays clean, and set `CONFIG_GBE_BIN_PATH` in your `.config`:

```sh
mkdir -p build
cp flashregion_3_gbe.bin build/gbe_local.bin
./util/scripts/config --set-str CONFIG_GBE_BIN_PATH "build/gbe_local.bin"
```
*(Note: If you update an existing coreboot installation by flashing only the `bios` region via `flashrom -p internal --ifd -i bios -w build/coreboot.rom`, the `gbe` region on your flash chip is left untouched.)*

