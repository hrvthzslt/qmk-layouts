# QMK Layouts

Collection of my qmk layouts.

## Install QMK

Install qmk firmware on Debian based systems, then run `qmk setup` to install the necessary dependencies.

```bash
make install
```

## Q8 ISO Encoder

Create a new layout called `hrvthzslt` for the `keychron/q8/iso_encoder` keyboard in qmk by symlinking the layout file to the qmk directory.

```bash
make q8-setup
```

Compile the keyboard firmware with the new layout.

```bash
make q8-compile
```

Flash the firmware to the keyboard. [Factory reset guide.](https://keychron.com.au/blogs/archived/how-to-factory-reset-or-flash-firmware-for-your-keychron-q8-keyboard)

```bash
make q8-flash
```
