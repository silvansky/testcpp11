#!/bin/sh

PROJ=testcpp11

echo "Building project ${PROJ}..."
make && echo "Running project ${PROJ}..." && ./${PROJ}
