#!/usr/bin/env bash
cd server/
valgrind --show-leak-kinds=all ./server_exe
cd ..
