Using Timer to blink LED every 4s. Configured TIM5_CH2 to produce output at GPIOA_PIN1.
<br>
<br>

- `drivers/gpio.c` : Configures GPIO pin.
- `drivers/timer.c` : Configures Timer.

<br>

Prerequisites:
<code>arm-none-eabi-gcc</code>, <code>openocd</code>, <code>make</code>

Navigate to the <code>Timer/</code> directory, and run the following commands:



- Build firmware (compilation and linking):
```
make
```

- Remove generated build files:
```
make clean
```

Ensure the Nucleo board is connected to the host computer through its ST-LINK USB port for the below commands.


- Build and Flash to the microcontroller:
 ```
  make flash
 ```

- Start the OpenOCD debugging server:
```
make openocd
```
