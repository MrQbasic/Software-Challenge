#!/bin/bash

# Server - Software Challenge 2022
# Copyright (c) 2022-2023 Moritz Kaufmann, Leon Schmitz
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#

# This File is the bootstrap for the Server Binary. It verifies that Java is valid and then starts the server located at server/server.jar

# Colors
COLOR_RED="\033[0;31m"
COLOR_RESET="\033[0m"

# Messages
ERROR="${COLOR_RED}Achtung${COLOR_RESET}"
ERROR_NOJAVA="${CODE_ERROR}: Das OpenJDK ist nicht installiert. Bitte installiere OpenJDK oder gebe als Argument einen Pfad zu einer validen Java Binary an."
ERROR_WRONGJAVA="${CODE_ERROR}: Die OpenJDK Installation ist fehlerhaft. Bitte überprüfe sie."
ERROR_NOSERVER="${CODE_ERROR}: Die 'server/server.jar' Datei existiert nicht. Bitte stellt sicher, dass sie noch existiert und eine valide Java Binary ist."
SUCCESS_START="Starte Server..."

# Commands
CMD_JAVA="java"

# Util Functions
beginswith() { case $2 in "$1"*) true;; *) false;; esac; }

# Check if a Java Installation was provided
if ! [ $# -eq 1 ]; then        
    if ! command -v ${CMD_JAVA} > /dev/null; then # No Argument, is there a Java command in PATH?
        echo -e ${ERROR_NOJAVA}
        exit
    fi
else
    # Set the Java Command to the user's argument
    CMD_JAVA=$1
fi

# Check if the Java Installation is working
version_output="$(${CMD_JAVA} --version)"
if ! beginswith openjdk "${version_output}"; then
    echo -e ${ERROR_WRONGJAVA}
    exit
fi

# Check if the Server exists
if ! test -f "server/server.jar"; then
    echo -e ${ERROR_NOSERVER}
    exit
fi

# Start server
command ${CMD_JAVA} -jar server/server.jar
