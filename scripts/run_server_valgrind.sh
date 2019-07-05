#!/usr/bin/env bash
cd server/
valgrind --show-leak-kinds=all --leak-check=full ./server_exe
cd ..
