# STM32 Driver for NT7108 / NT7107 128x64 Graphical LCD

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A robust and lightweight C driver for controlling 128x64 graphical LCDs based on the NT7108, NT7107, or compatible controllers using an STM32F4 microcontroller and HAL libraries.

This driver provides a complete set of functions for initializing the display, rendering text, drawing shapes, and displaying custom bitmaps.

---

## ## Demo 📸


The demo application showcases a simple H.V.A.C. monitoring interface, displaying static temperature and humidity data alongside custom icons.

---

## ## Features ✨

* **Easy Initialization**: Single function call to configure the display.
* **Text Rendering**: Display strings and characters at any X/Y coordinate using a built-in 5x8 pixel font.
* **Graphics Primitives**: Functions for drawing pixels, lines, and rectangles (both outlined and filled).
* **Bitmap Support**: Render custom monochrome bitmaps and icons stored in arrays.
* **Lightweight**: Written in standard C with minimal memory footprint, relying only on the STM32 HAL for GPIO operations.
* **Well-Documented**: Clear function prototypes and definitions.

---

## ## Hardware Requirements ⚙️

* An STM32F4 series development board (e.g., Nucleo-F446RE, Discovery).
* A 128x64 Graphical LCD Module with an NT7108/NT7107 compatible controller.
* Breadboard and connecting wires.

---

## ## Pinout & Wiring 🔌

The driver is configured with the following pin connections. You can modify these definitions in `nt710x_driver.h`.

| GLCD Pin | STM32 Pin | Description                |
| :------- | :-------- | :------------------------- |
| **RS** | `PB0`     | Register Select            |
| **RW** | `PB1`     | Read/Write Select          |
| **EN** | `PB2`     | Enable Signal              |
| **CS1** | `PB4`     | Chip Select 1 (Controller 1) |
| **CS2** | `PB3`     | Chip Select 2 (Controller 2) |
| **RST** | `PB5`     | Reset Pin                  |
| **D0-D7**| `PD0-PD7` | 8-bit Data Bus             |

---

## ## How to Use

1.  **Add Files**: Add the `Core/Inc` and `Core/Src` folders to your STM32CubeIDE project.
2.  **Include Header**: Include the main driver header in your `main.c` file.
    ```c
    #include "nt710x_driver.h"
    #include "data.h" // For custom bitmaps
    ```
3.  **Initialize and Draw**: Call the initialization function and then use the drawing functions.

    **Example `main.c` usage:**
    ```c
    int main(void)
    {
      /* MCU Configuration */
      HAL_Init();
      SystemClock_Config();
      MX_GPIO_Init();
      // NOTE: I2C is not needed for this GLCD driver demo

      /* Initialize the GLCD */
      GLCD_Init();

      /* --- Drawing Example --- */

      // 1. Clear the screen
      GLCD_Clear();

      // 2. Display a title string at coordinates (x=20, y=0)
      GLCD_DisplayString("Project Demo", 20, 0);

      // 3. Draw a line under the title
      GLCD_DrawLine(0, 10, 127, 10);

      // 4. Draw a rectangle
      GLCD_DrawRect(5, 15, 50, 20);

      // 5. Display the thermometer icon from data.h
      // Note: A function like GLCD_DrawBitmap would be needed here.
      // Assuming you have a GLCD_DrawBitmap(bitmap, x, y, w, h) function:
      // GLCD_DrawBitmap(thermometer_icon, 10, 40, 15, 15);

      while (1)
      {
        // Your main loop code here
      }
    }
    ```

---

## ## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
