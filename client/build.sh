#!/bin/bash

# Client - Software Challenge 2022
# Copyright (c) 2022-2023 Moritz Kaufmann, Leon Schmitz
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#

# Makes sure that the script was executed over the /client.sh file
if ! [ "$1" == "iamasecret" ]; then
    echo "This script is not intended to be executed directly."
    exit
fi

# Make client
cd client && make

echo "Build successfull"
