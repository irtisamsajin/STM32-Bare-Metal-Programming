<p>
  The goal of this repository is to understand how firmware is compiled, linked, flashed and debugged on an STM32 microcontroller,
  while exploring various on-chip peripherals including GPIO, Timers, Interrupts, ADC/DAC and communication protocols.
</p>
<p>
  This project uses the <b>STM32F446RE</b> Nucleo board, which features an integrated ST-LINK debugger,
  that allows firmware to be flashed and debugged directly without requiring an external debugging probe.
</p>
<p>
  Prerequisites:
  <ul>
    <li> <code>arm-none-eabi-gcc</code> : ARM GNU cross-compiler toolchain used to compile and link firmware for the microcontroller. </li>
    <li> <code>openocd</code>: Provides an interface between the host computer and the microcontroller through ST-LINK, enabling firmware flashing and on-chip debugging.</li>
    <li> <code>make</code>: GNU make automates the build and flashing processes using instructions defined in Makefile. </li>
    <li> <code>cortex-debug</code>: Optional VS Code extension that enables graphical debugging, including breakpoints, register inspection, and variable monitoring. </li>
  </ul>
</p>