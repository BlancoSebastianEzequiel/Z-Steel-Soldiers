#!/usr/bin/env bash

cd client/
valgrind --show-leak-kinds=all ./client_exe
cd ..