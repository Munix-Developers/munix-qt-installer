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

# This is the post-install script, executed inside chroot
cat <<EOF > /mnt/post-install.sh
#!/bin/sh

# Uncomment the desired location
sed -i "s/^#${MLOCALE}\(\.*\)/${MLOCALE}\1/g" /etc/locale.gen
# Generate the locale
locale-gen

echo "LANG=${MLOCALE}.UTF-8" > /etc/locale.conf
export LANG=${MLOCALE}.UTF-8

exit
EOF

chmod +x /mnt/post-install.sh

# chroot to the pacman base created by the pre-installation.sh
arch-chroot /mnt /mnt/post-install.sh
