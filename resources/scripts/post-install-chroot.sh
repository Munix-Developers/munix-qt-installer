#!/bin/sh

# WARNING UNDER NO CIRCUNSTANCES RUN THIS SCRIPT ON A WORKING ARCH LINUX/VARIANT INSTALLATION
# THIS SCRIPT CAN DELETE EVERYTHING ON YOUR SYSTEM ***WITHOUT WARNING***.
#
# The post-install script, executed inside chroot
# This script is called by the Munix installer at runtime,
# to work, it needs the following environmment variables:
#
# $MLANG	A string describing the lang (en_US, pt_BR) etc...
# $MCOUNTRY	A string describing the COUNTRY (US, BR) etc...
#
# Requirements include:
#
# 1. /munix-vars for variables
# 2. /syslinux.cfg for syslinux config
# 3. Root privileges
# 4. A active Internet connection

#########################
#	VARIABLES	#
#########################
source /munix-vars

# TODO SysLinux config file
# TODO User and pass
# TODO Keyboard mapping
# TODO Time sync

# Uncomment the desired location
sed -i "s/^#${MLOCALE}\(\.*\)/${MLOCALE}\1/g" /etc/locale.gen

# Generate the locale
locale-gen

echo "LANG=${MLOCALE}.UTF-8" > /etc/locale.conf
export LANG=${MLOCALE}.UTF-8

# Sys linux
pacman -S --noconfirm syslinux

keytab-lilo /user/share/jbd/keymaps/i386/qwerty/us.map.gz /usr/share/kbd/keymaps

syslinux-install_update -iam
cp /syslinux.cfg /boot/syslinux/syslinux.cfg

exit
