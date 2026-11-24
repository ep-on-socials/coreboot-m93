#!/bin/sh
set -eu

# Default to ../coreboot-upstream if no target directory is passed
TARGET_DIR="${1:-../coreboot-upstream}"
SCRIPT_DIR="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)"

if [ ! -d "$TARGET_DIR/src/mainboard/lenovo" ]; then
    echo "Error: '$TARGET_DIR' does not look like a valid coreboot tree." >&2
    echo "Usage: $0 [/path/to/coreboot]" >&2
    exit 1
fi

echo "Applying Lenovo ThinkCentre M93 overlay to: $TARGET_DIR"

# 1. Copy mainboard source files
mkdir -p "$TARGET_DIR/src/mainboard/lenovo"
cp -R "$SCRIPT_DIR/src/mainboard/lenovo/thinkcentre_m93" "$TARGET_DIR/src/mainboard/lenovo/"

# 2. Copy binary blobs
mkdir -p "$TARGET_DIR/3rdparty/blobs/mainboard/lenovo"
cp -R "$SCRIPT_DIR/3rdparty/blobs/mainboard/lenovo/thinkcentre_m93" "$TARGET_DIR/3rdparty/blobs/mainboard/lenovo/"

echo "Done! Overlay applied cleanly:"
echo "  - $TARGET_DIR/src/mainboard/lenovo/thinkcentre_m93"
echo "  - $TARGET_DIR/3rdparty/blobs/mainboard/lenovo/thinkcentre_m93"

