#!/bin/bash

sudo umount ./work/x86_64/airootfs/proc
sudo umount ./work
sudo rm -vR ./work
find ./customrepos -type f -not -name ".gitkeep" -exec rm -v {} \;

