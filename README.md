# CSE-211s-GPS-Project
## Project Overview
This embedded system project calculates distances between saved location coordinates and the current GPS position, then displays the nearest location and its distance on an LCD screen.
## Description:
Upon turning on the tiva, it calculates the distances of five locations to the current location, then prints "The nearest location is:      distance =  m" on the LCD screen.
On reaching the nearest location with the distance less than 10 m, the LCD displays "Arrived at location:   " and the buzzer makes a sound for 1 second.
All the distances are sent to the mobile phone through the Bluetooth module.
## Components and Software
>> TM4C123 Tiva C Launchpad
>> Neo-6m GPS module
>> Bluetooth module
>> Buzzer
>> LCD Screen
>> Keil uVision 4 IDE  
