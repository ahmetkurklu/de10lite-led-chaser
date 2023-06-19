# kurklu_lab1

# Introduction

As part of our joint design course in GE5A at Polytech Clermont, we are required to apply the theoretical knowledge gained during practical work. These tasks are performed on a Terasic DE10-Lite board based on an Altera MAX 10 FPGA. For this first project, our goal is to familiarize ourselves with the tools discussed in class and implement a LED chaser using interrupts, utilizing the LEDs, switches, and buttons present on the board.

# Architecture
Here is the architecture I created using Paint:

[![Lab1-jpeg.jpg](https://i.postimg.cc/76V6y378/Lab1-jpeg.jpg)](https://postimg.cc/PpChW822)

First, I included the components to rebuild my basic system:
* A clock
* A RAM
* A NIOS-2
* A JTAG

Then, I added PIOs to manage my I/O:
* An 8-bit PIO for the LEDs
* A 2-bit PIO for the keys
* A 9-bit PIO for the switches

Here is the system initialized in Qsys:

[![Lab1-qsys.jpg](https://i.postimg.cc/y6LC91zT/Lab1-qsys.jpg)](https://postimg.cc/yW3GCzxJ)

Next, I created my "kurklu_lab1.vdh" file, performed pin assignments, and compiled my system in Quartus to move on to the software part.

My objective is to implement the LED chaser on the LEDs, activate and deactivate the LED chaser using button interrupts, and finally manage the speed using switch interrupts.

# Progress

I created three C files: "led_chaser.c," "led_chaser_polling.c," and "led_chaser_interrupt.c" for the different versions.

## Simple LED chaser
To implement the LED chaser, I simply performed left bit shifts in a loop, starting from LED 0 to LED 7, and then right bit shifts from LED 7 to LED 0. With each write, I added a delay using the "usleep()" function, which also allows me to control the speed of the LED chaser in the polling stage.

## Polling LED chaser
For the polling version, I added a switch case at the beginning of my loop. This switch case checks the activated switches and modifies the "time" variable used by the "usleep()" function. This allows me to increase or decrease the wait time between each write and, therefore, modify the speed.

## Interrupt-driven LED chaser
For the interrupt-driven version, I implemented different functions to handle the interrupts. "key_interrupt()" handles the buttons, and "sw_interrupt()" handles the switches. In my main function, I initialized the interrupts by specifying the masks, edge captures, and interrupt registrations. In the "key_interrupt()" function, I check the pressed button. Depending on the button, I either start the LED chaser or reset it by also resetting the variables used to control it.

[Video link for key interrupt demonstration](https://user-images.githubusercontent.com/24780090/211770355-d795e951-f325-4e74-9b45-989a813e43c5.mov)

In the "sw_interrupt()" function, I first read the register where the switches are written. Then, I call my "nombre_bits_a_1()" function, which returns the number of bits set to 1 in the register. Based on this number, I modify the "time" variable to adjust the speed of the LED chaser.

[Video link for switch interrupt demonstration](https://user-images.githubusercontent.com/24780090/211770309-

9cf0fed9-7302-426b-9a08-b7b0f3c441d1.mov)

# Conclusion

I successfully completed lab1 without major difficulty. It was my first time working on a real target. This initial practical work allowed me to regain control of the different tools for working on both the hardware and software aspects. The only point where I lost time during this lab was with the interrupts. The syntax of the functions used in the course gave me warnings and did not work. By reading the documentation provided on Moodle, I realized that "ALT_ENHANCED_INTERRUPT_API_PRESENT" was defined in my "system.h" file. Therefore, I used the alternative syntax to define the interrupts, which worked.