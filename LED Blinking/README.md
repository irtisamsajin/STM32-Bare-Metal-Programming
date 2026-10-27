Prerequisites:
<code>arm-none-eabi-gcc</code>, <code>openocd</code>, <code>make</code>
<br>
<br>
Navigate to the <code>LED Blinking/</code> directly, and run the following commands:
- Build firmware (compilation and linking)::
```
make
```

- Clean generated build files:
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
