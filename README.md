
## Vending Machine

This project utilizes a GSM900A SIM module in conjunction with an Arduino board to perform various tasks. It also incorporates additional small devices such as a stepper motor, LCD display, and I2C adapters.

The main feature of this project is the acceptance of money through an online payment system called bkash. The text message sent by the bkash operator is received by the SIM module and subsequently read. After verifying the text message to determine the operator and amount, the desired item is dispensed.

## Installation
- Clone the repository
- install the necessary libraries and dependencies.
- Connect the GSM900A SIM module to the Arduino board.
- Connect the stepper motor, LCD display, and any other required devices to the Arduino board.
## Initial Design
![vending_machine](https://github.com/Ankon0048/Vending-Machine-pheripheral-project/blob/main/vending_machine.jpg)
## some pin markdowns
- gsm red connected to aruidno 10
- gsm brown connected to arduino 9
- gsm black connected to arduino gnd
- arduino 5v connected to breadboard
- i2c adapter vcc and gnd are connected to breadboard and arduino
- i2c SDA connected to arduino a4
- i2c SCL connected to arduino a5
- servo motor set to arduino 3
## Usage
- Upload the code to the Arduino board.
- Power on the system.
- Ensure that the Arduino is connected to the internet.
- Receive the text message from the bkash operator.
- The SIM module will read the text message and verify the operator and amount.
- Once verified, the desired item will be dispensed by the system.
## Future Updates
- Stay tuned for future updates and enhancements to the project.Feel free to contact the project owner for any further information or inquiries.
