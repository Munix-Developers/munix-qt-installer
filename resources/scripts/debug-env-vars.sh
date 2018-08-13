#!/bin/sh

# This script is used to debug the env variables used by the installations
# scripts.

# $MDEVICE	The device where munix will be installed
# $MLANG	A string describing the lang (en, pt) etc...
# $MCOUNTRY	A string describing the COUNTRY (US, BR) etc...
# $MLOCALE	A string used for localeCode (en_US, pt_BR) etc...

echo "MDEVICE: ${MDEVICE}"
echo "MLANG: ${MLANG}"
echo "MCOUNTRY: ${MCOUNTRY}"
echo "MLOCALE: ${MLOCALE}"
