#!/bin/bash

mkdir -p libs
cd libs

# CPR
git clone --branch 1.12.0 --depth 1 https://github.com/libcpr/cpr.git

# simdjson
git clone --branch v3.13.0 --depth 1 https://github.com/simdjson/simdjson.git

# libxlsxwriter
git clone --branch v1.2.3 --depth 1 https://github.com/jmcnamara/libxlsxwriter.git
