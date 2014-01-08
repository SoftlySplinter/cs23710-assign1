.\" Man Page for the Relocating Aberystwyth Dairy Company program.
.TH RELOCATE 1.0 "NOVEMBER 2010" "Alexander Brown" "User Manual"
.SH NAME
relocate \- relocate a company to a more profitable location
.SH SYNOPSIS
.B relocate [-c|-s] 
.I file
.SH DESCRIPTION
.B relocate
Runs the relocation program using the `Company Description File'
.SH OPTIONS
.IP "-c --complex"
relocates the company specified by the `Company Description File' taking into account the weight of deliveries
.IP "-s --simple"
relocates the company specified by the `Company Description File' without taking into account the weight of deliveries
.IP "-h --help"
display this help and exit
.IP "-v --version"
output version information and exit
.SH AVAILABILITY
This program will only run on Solaris machines with Sparc processors.
.SH AUTHOR
Alexander Brown
