# LoRa_IoT
microphone sensor node using LoRa technology.
This project consists of two nodes: one that acts as a sender, and the other acts as a receiver.
The microcontroller used in this project is: Arduino Mega Board.

## The Goal
Using the Client Node to sense microphone values and send them to the server node, and then sends the data through Serial part to Python code that prints the data to CSV file.

## Building the end-node
The sender sensor node has a microphone and sensor, in addition to LoRa shield that allows the node to communicate with the receiver. 
Consider the Dragino LoRa Shield provided in the following picture:
![LoRa Shield](https://i.imgur.com/ZjvqmTH.png)
[Full Reference to LoRa Shield](http://www.dragino.com/products/module/item/102-lora-shield.html).

## Needed Libraries
  * **LoRa Library:** You will add this library to your Arduino IDE in order to be able to use client-server examples included in the library.
    You can download LoRa lib directly from the Library Manager in Arduino IDE, just go to **Sketch > Include Library > Manage Libraries**
    and search for `LoRa`, then choose the library shown in the following pic:
    ![](https://i.imgur.com/EHhlSVX.png)
    
    **You can also download it from GitHub [repo](https://github.com/sandeepmistry/arduino-LoRa)** 
    Now, in the IDE go to **File > Examples > LoRa** you should scroll down to see it under **Examples From Custom Libraries** section.
    Through this project we will use two examples snippets: LoRaSender, and LoRaReceiver
    
  * **ArduinoJson:** you also can download it from Library manager, just type json in the search and choose the lib written by Bennoit Blanchon.  **NOTE**: make sure to download the version `5.13.2`, so are able to follow up with the official 
  docs [here](https://arduinojson.org/v5/doc/)
  
  **ADDITIONAL INFORMATION ARE FOUND IN THE PRESENTATION FILE**
  
  
