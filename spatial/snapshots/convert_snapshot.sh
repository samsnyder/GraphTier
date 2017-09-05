#!/bin/bash

cd "${0%/*}"

spatial project history snapshot convert --input $1 --input-format text --output $2 --output-format binary
