# teensyLasers
A Teensy-based laser modulation source.

Outputs square waves on desired pins at a given freqency and duty cycle.

# Functions
* **setupPin(pin, freq, bits):** Performs setup routine on output pins; called once for each laser.
    *  *pin:* The pin to setup (int).
    *  *freq:* The frequency (in Hz) to initialize the pin to (int).
    *  *bits:* The maximum number of bits to use in calculating the duty cycle (int, default 4095).
*  **setFreq:** Set the frequency of a given laser based on serial input.
    *  *laser:* A string containing the laser to set the frequency for and the freqeuncy at which to set it; for example, `"b.1370"` sets the blue (405nm) laser to 1370 Hz.  The function recognizes `b.XXXX`, `g.XXXX`, and `r.XXXX`.
    *  *pin:* The pin on which to set the frequncy.
*  Sending a serial command of `s` will activate a motor to perform a frequency "sweep" and measure the resonance frequency.

Serial commands should be sent with a "newline" (`\n`) EOL character.
