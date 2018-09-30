#!/bin/sh

# WARNING UNDER NO CIRCUNSTANCES RUN THIS SCRIPT ON A WORKING ARCH LINUX/VARIANT INSTALLATION
# THIS SCRIPT CAN DELETE EVERYTHING ON YOUR SYSTEM ***WITHOUT WARNING***.
#
# This script is called by the Munix installer at runtime,
# to work, it needs the following environmment variables:
#
# $MLANG	A string describing the lang (en_US, pt_BR) etc...
# $MCOUNTRY	A string describing the COUNTRY (US, BR) etc...
#
# Requirements include:
#
# 1. Root privileges
# 2. A active Internet connection

chmod +x /mnt/post-install-chroot.sh

# chroot to the pacman base created by the pre-installation.sh
arch-chroot /mnt /post-install-chroot.sh

read
