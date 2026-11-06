Two push buttons are used to control the PWM duty cycle, one button increasing the duty cycle and the other one reduces it.
<br>
<br>

- `drivers/gpio.c` : Configures GPIO pin.
- `drivers/timer.c` : Configures Timer PWM.
- `drivers/interrupt.c` : Configures EXTI interrupts.

<br>

Prerequisites:
<code>arm-none-eabi-gcc</code>, <code>openocd</code>, <code>make</code>

Navigate to the <code>Interrupt & PWM/</code> directory, and run the following commands:



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
