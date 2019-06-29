#!/usr/bin/env bash

make_report () {
    cd docs/$1
    pdflatex report.tex
    pdflatex report.tex
    rm report.aux
    rm report.log
    rm report.toc
    rm report.out
    mv report.pdf $1.pdf
    cd ..
    cd ..
    clear
}

make_report project_manual
make_report technical_documentation
make_report user_manual
