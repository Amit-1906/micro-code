# Arduino Voting Machine (EVM)

An Electronic Voting Machine (EVM) prototype built with Arduino Uno and a 16x2 I2C LCD display.

## Components Used
- Arduino Uno
- 16x2 I2C LCD Display (Default I2C Address: `0x27`, or `0x3F`)
- 4x Push Buttons (using internal pull-up resistors)
- Breadboard & Jumper Wires

## Pin Configuration
- **Pin 2**: Vote button for BJP (Input with internal pullup)
- **Pin 3**: Vote button for Congress (Input with internal pullup)
- **Pin 4**: Vote button for AAP (Input with internal pullup)
- **Pin 6**: Show results / tally button (Input with internal pullup)
- **SDA**: Arduino A4 (or dedicated SDA pin)
- **SCL**: Arduino A5 (or dedicated SCL pin)
- **VCC**: 5V
- **GND**: GND

## How It Works
1. When powered on, the LCD displays a welcome message and prompts voters to cast their vote.
2. Pressing button 2, 3, or 4 registers a vote for the corresponding candidate/party and shows a confirmation message on the LCD and Serial Monitor.
3. Pressing button 6 displays the total vote counts for all candidates both on the LCD and over the Serial Monitor (9600 baud rate).
