#!/bin/bash

# Sleep for 5 seconds
sleep 5

# Calculate end time (5 minutes from now)
END_TIME=$(($(date +%s) + 1200))

echo "Starting PageDown simulation..."
echo "Will send PageDown for 5 minutes (until $(date -d @$END_TIME '+%H:%M:%S'))"

# Check if wtype is available
if ! command -v wtype &>/dev/null; then
  echo "wtype not found. Installing..."
  echo "Please install wtype with: sudo apt install wtype  or  sudo pacman -S wtype"
  exit 1
fi

# Send PageDown every 2 seconds for 5 minutes
while [ $(date +%s) -lt $END_TIME ]; do
  # Send PageDown key (using wtype for Wayland)
  wtype -P Page_Down -p Page_Down
  sleep 0.5
done

echo "PageDown simulation completed."
