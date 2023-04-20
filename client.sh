#!/bin/bash

# Client - Software Challenge 2022
# Copyright (c) 2022-2023 Moritz Kaufmann, Leon Schmitz
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#

# This File is the bootstrap for the Client. It builds the binary and executes it

# Colors
COLOR_RED="\033[0;31m"
COLOR_RESET="\033[0m"

# Messages
CODE_ERROR="${COLOR_RED}Achtung${COLOR_RESET}"
ERROR_NOMAKEFILE="${CODE_ERROR}: Es existiert kein Makefile im Server Ordner."

# Check if the Makefile exists
if ! test -f "./client/Makefile"; then
    echo -e ${ERROR_NOMAKEFILE}
    exit
fi

# Check if the Makefile succeded
if ! test -f "./client/Makefile"; then
    echo -e ${ERROR_NOMAKEFILE}
    exit
fi

# Start client
./client/build.sh iamasecret

# Execute binary
chmod +x ./clint/bin/SC_PENGUINS_STARTER
./clint/bin/SC_PENGUINS_STARTER
