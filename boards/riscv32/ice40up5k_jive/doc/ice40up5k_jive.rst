.. _m2gl025-miv:

Microsemi M2GL025 Mi-V
######################

Overview
********

The Lattice Semiconductor iCE40UP5K-B-EVN board is an iCE40 FPGA based development board.
The JiVE RISC-V soft CPU can be deployed on the iCE40UP5K-B-EVN board.

Programming and debugging
*************************

Building
========

Applications for the ``ice40up5k_jive`` board configuration can be built as usual
(see :ref:`build_an_application`).
In order to build the application for ``ice40up5k_jive``, set the ``BOARD`` variable
to ``ice40up5k_jive``.

.. code-block:: bash

   export BOARD="ice40up5k_jive"

Flashing
========

In order to upload the application to the device, you'll need OpenOCD and GDB
with RISC-V support.
You can get them as a part of SoftConsole SDK.
Download and installation instructions can be found on
`Microsemi's SoftConsole website
<https://www.microsemi.com/product-directory/design-tools/4879-softconsole>`_.

With the necessary tools installed, you can connect to the board using OpenOCD.
To establish an OpenOCD connection run:

.. code-block:: bash

   sudo LD_LIBRARY_PATH=<softconsole_path>/openocd/bin \
   <softconsole_path>/openocd/bin/openocd  --file \
   <softconsole_path>/openocd/share/openocd/scripts/board/microsemi-riscv.cfg


Leave it running, and in a different terminal, use GDB to upload the binary to
the board. You can use the RISC-V GDB from a toolchain delivered with
SoftConsole SDK.

Here is the GDB terminal command to connect to the device
and load the binary:

.. code-block:: console

   <softconsole_path>/riscv-unknown-elf-gcc/bin/riscv64-unknown-elf-gdb \
   -ex "target extended-remote localhost:3333" \
   -ex "set mem inaccessible-by-default off" \
   -ex "set arch riscv:rv32" \
   -ex "set riscv use_compressed_breakpoints no" \
   -ex "load" <path_to_executable>

Debugging
=========

Refer to the detailed overview of :ref:`application_debugging`.

