#!/bin/sh

# WARNING UNDER NO CIRCUNSTANCES RUN THIS SCRIPT ON A WORKING ARCH LINUX/VARIANT INSTALLATION
# THIS SCRIPT CAN DELETE EVERYTHING ON YOUR SYSTEM ***WITHOUT WARNING***.
#
# This script is called by the Munix installer at runtime,
# to work, it needs the following environmment variables:
#
# $MDEVICE	The device where munix will be installed
# $MCOUNTRY	A string describing the COUNTRY (US, BR) etc...
#
# Requirements include:
#
# 1. Root privileges
# 2. A active Internet connection


#########################
#	VARIABLES	#
#########################

# Pacman mirror based on the country
export MPACMIRROR=http://www.archlinux.org/mirrorlist/?country=${MCOUNTRY}

# ERASES THE DISK WARNING: THIS IS DANGEROUS
wipefs -a "/dev/${MDEVICE}"

# Creates a 2GB partition for SWAP
# Creates a another partition for the rest of the disk
echo "o
n
p
1

+2G
n
p
2



w
" | fdisk "/dev/${MDEVICE}"

# Create the swap partition
mkswap -L munix-swap "/dev/${MDEVICE}1"

# Create the root filesystem
# TODO: maybe f2fs for SSD's here?
mkfs.ext4 -L munix-root "/dev/${MDEVICE}2"

# Mount the root filesystem
mount "/dev/${MDEVICE}2" /mnt

# Finds the fastest pacman mirrors based on the country
cd /etc/pacman.d
wget ${MPACMIRROR} -O mirrorlist
sed -i 's/^#//' mirrorlist
cd ~

# Base install
pacman -Syy
pacstrap /mnt base

# Generate fstab
genfstab -U -p /mnt >> /mnt/etc/fstab
