<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Water Level Meter with Ultrasonic Sensor and LCD Display</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      line-height: 1.6;
      margin: 20px;
      background-color: #f9f9f9;
      color: #333;
    }
    h1, h2, h3 {
      color: #2c3e50;
    }
    code {
      background-color: #eaeaea;
      padding: 2px 5px;
      border-radius: 3px;
      font-family: "Courier New", monospace;
    }
    ul {
      list-style-type: square;
      padding-left: 20px;
    }
    .container {
      max-width: 800px;
      margin: 0 auto;
      background: #fff;
      padding: 20px;
      border-radius: 8px;
      box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
    }
    .section {
      margin-bottom: 30px;
    }
    .section h2 {
      border-bottom: 2px solid #2c3e50;
      padding-bottom: 5px;
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>Water Level Meter with Ultrasonic Sensor and LCD Display</h1>
    <div class="section">
      <p>
        This project uses an ultrasonic sensor to measure the water level in a tank and displays the results on an I2C LCD screen. The system calculates the water level percentage, water height, and water volume, and displays them on the LCD along with a progress bar.
      </p>
    </div>

    <div class="section">
      <h2>Components</h2>
      <ul>
        <li><strong>Arduino Uno</strong> (or compatible microcontroller)</li>
        <li><strong>Ultrasonic Sensor (HC-SR04)</strong></li>
        <li><strong>I2C LCD Display (16x2)</strong></li>
        <li><strong>Jumper wires</strong></li>
        <li><strong>Breadboard</strong> (optional)</li>
      </ul>
    </div>

    <div class="section">
      <h2>Connections</h2>
      <h3>Ultrasonic Sensor:</h3>
      <ul>
        <li><code>VCC</code> → <code>5V</code> on Arduino</li>
        <li><code>GND</code> → <code>GND</code> on Arduino</li>
        <li><code>Trig</code> → <code>Digital Pin 8</code> on Arduino</li>
        <li><code>Echo</code> → <code>Digital Pin 9</code> on Arduino</li>
      </ul>
      <h3>I2C LCD:</h3>
      <ul>
        <li><code>VCC</code> → <code>5V</code> on Arduino</li>
        <li><code>GND</code> → <code>GND</code> on Arduino</li>
        <li><code>SDA</code> → <code>A4</code> on Arduino (or <code>SDA</code> pin)</li>
        <li><code>SCL</code> → <code>A5</code> on Arduino (or <code>SCL</code> pin)</li>
      </ul>
    </div>

    <div class="section">
      <h2>Setup Instructions</h2>
      <ol>
        <li>Connect the components as per the wiring diagram.</li>
        <li>Upload the provided code to your Arduino.</li>
        <li>Ensure the I2C address of the LCD is correct (<code>0x27</code> or <code>0x3F</code>).</li>
        <li>Place the ultrasonic sensor at the top of the tank, facing downward.</li>
      </ol>
    </div>

    <div class="section">
      <h2>Code Overview</h2>
      <ul>
        <li><strong>LiquidCrystal_I2C Library:</strong> Used to control the I2C LCD.</li>
        <li><strong>Ultrasonic Sensor:</strong> Measures the distance to the water surface.</li>
        <li><strong>Tank Dimensions:</strong> Configured in the code (<code>tankHeight</code>, <code>tankLength</code>, <code>tankBreadth</code>).</li>
        <li><strong>Water Level Calculation:</strong> Converts the ultrasonic sensor reading into water level percentage, height, and volume.</li>
        <li><strong>LCD Display:</strong> Shows the water level percentage, volume, and a progress bar.</li>
      </ul>
    </div>

    <div class="section">
      <h2>Features</h2>
      <ul>
        <li><strong>Real-Time Water Level Measurement:</strong> Continuously measures and updates the water level.</li>
        <li><strong>Error Handling:</strong> Displays an error message if the ultrasonic sensor fails to detect a response.</li>
        <li><strong>Progress Bar:</strong> Visual representation of the water level on the LCD.</li>
        <li><strong>Customizable Tank Dimensions:</strong> Adjust the tank dimensions in the code to match your setup.</li>
      </ul>
    </div>

    <div class="section">
      <h2>Customization</h2>
      <ul>
        <li><strong>Tank Dimensions:</strong> Update <code>tankHeight</code>, <code>tankLength</code>, and <code>tankBreadth</code> in the code to match your tank's dimensions.</li>
        <li><strong>Sensor Calibration:</strong> Adjust <code>tankEmptyDepth</code> and <code>tankFullDepth</code> to calibrate the sensor readings for your specific setup.</li>
        <li><strong>I2C Address:</strong> If the LCD doesn't work, try changing the I2C address to <code>0x3F</code>.</li>
      </ul>
    </div>

    <div class="section">
      <h2>Acknowledgments</h2>
      <ul>
        <li><strong>LiquidCrystal_I2C Library:</strong> For simplifying I2C LCD control.</li>
        <li><strong>Arduino Community:</strong> For providing resources and inspiration.</li>
      </ul>
    </div>
  </div>
</body>
</html>
