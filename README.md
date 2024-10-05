# QMK Layouts

Automating the installation and setup of QMK on **Debian**-based systems, and flashing firmware with my own **custom keymap** layouts.

## Install QMK

Install QMK firmware, then run `qmk setup` to install the necessary dependencies.

```bash
make install
```

## Keychron Q8-F1 (ISO Encoder)

![Keyhcron Q8-F1](assets/q8-f1.png)

Create a new layout called `hrvthzslt` for the `keychron/q8/iso_encoder` keyboard in QMK by symlinking the layout file to the QMK directory.

```bash
make q8-setup
```

Compile the keyboard firmware with the new layout.

```bash
make q8-compile
```

Flash the firmware to the keyboard. [Factory reset guide](https://keychron.com.au/blogs/archived/how-to-factory-reset-or-flash-firmware-for-your-keychron-q8-keyboard).

```bash
make q8-flash
```

## Keychron Q11-M3 (ISO Encoder)

![Keyhcron Q11-M3](assets/q11-m3.png)

Create a new layout called `hrvthzslt` for the `keychron/q11/iso_encoder` keyboard in QMK by symlinking the layout file to the QMK directory.

```bash
make q11-setup
```

Compile the keyboard firmware with the new layout.

```bash
make q11-compile
```

Flash the firmware to the keyboard. [Factory reset guide](https://keychron.ca/pages/how-to-factory-reset-or-flash-firmware-for-your-keychron-q11-keyboard).

```bash
make q11-flash
```
