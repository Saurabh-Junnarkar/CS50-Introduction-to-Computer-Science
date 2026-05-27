# Secure Access System (Scratch)

An event-driven security simulation built for CS50x. This project demonstrates state management, custom block procedures, and synchronized sprite interaction.

## 🛠 System Architecture

The project is organized into five functional modules that coordinate via broadasted signals:

### 1. The Researcher (`Elf`)
* **Movement:** Interactive movement via arrow keys.
* **Proximity Logic:** Detects collision with the `Laptop` to trigger the security handshake.
* **Exit Protocol:** Listens for the `I am GROOT!` broadcast to trigger a final "I am ELF!" response before the program terminates.

### 2. The Gateway (`Laptop`)
* **State Management:** Uses an `Is_Active` variable as a **Mutex**. When a challenge starts, it sets `Is_Active` to 'Yes', blocking new inputs until the Elf moves away.
* **Validation Logic:** Processes user input against a `Passcode` variable. It then broadcasts either `Valid Key` or `Invalid Key`.

### 3. The Sentinel (`Sprite3`)
* **Modular Logic:** Features a custom `Process Security Result` block with a `Status` parameter.
* **Feedback:** * **Pass:** Sets color effect to 70 (Green) and plays the 'Connect' sound.
    * **Fail:** Sets color effect to 25 (Red) and plays the 'C2 Bass' sound.

### 4. The Portal (`Picture1`)
* **Listener:** Acts as a physical barrier. Upon receiving the `Valid Key` signal, it glides to an open position and broadcasts `Open door` to reveal the hidden guardian.

### 5. The Guardian (`Dinosaur5`)
* **Reveal Logic:** Remains hidden until the `Open door` signal is received.
* **Interaction:** Glides toward the Researcher and initiates the `I am GROOT!` broadcast sequence.

## 🚀 How to Run
1. Download `project.sb3` from this repository.
2. Load the file into the [Scratch Web Editor](https://scratch.mit.edu/projects/editor/).
3. Click the **Green Flag** to initialize the variables and starting positions.
