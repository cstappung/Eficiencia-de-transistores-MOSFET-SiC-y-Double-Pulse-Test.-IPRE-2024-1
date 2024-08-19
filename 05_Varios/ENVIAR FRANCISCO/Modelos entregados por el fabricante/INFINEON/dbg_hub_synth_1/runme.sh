#!/bin/sh

# 
# Vivado(TM)
# runme.sh: a Vivado-generated Runs Script for UNIX
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
# 

echo "This script was generated under a different operating system."
echo "Please update the PATH and LD_LIBRARY_PATH variables below, before executing this script"
exit

if [ -z "$PATH" ]; then
  PATH=D:/VIVADO/Vivado/2020.1/ids_lite/ISE/bin/nt64;D:/VIVADO/Vivado/2020.1/ids_lite/ISE/lib/nt64:D:/VIVADO/Vivado/2020.1/bin
else
  PATH=D:/VIVADO/Vivado/2020.1/ids_lite/ISE/bin/nt64;D:/VIVADO/Vivado/2020.1/ids_lite/ISE/lib/nt64:D:/VIVADO/Vivado/2020.1/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD='d:/Trabajos_UC/9 noveno semestre/SEP/Ayudantia 5/Arcchivos nuevos/AYUD_05/AYUD_05.runs/impl_1/.Xil/Vivado-46276-DESKTOP-A0CU7UE/dc_drv.0/dc/prj_ip.runs/dbg_hub_synth_1'
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

EAStep vivado -log dbg_hub.vds -m64 -product Vivado -mode batch -messageDb vivado.pb -notrace -source dbg_hub.tcl
