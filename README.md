📊 Sorting Algorithm Visualizer in C (Raylib)
A lightweight, real-time Sorting Visualizer built in C using the Raylib graphics and audio library. This project visually demonstrates the Selection Sort algorithm by rendering array elements as vertical blocks and triggering audio feedback pitched according to each element's height.

✨ Features
Visual Sorting Process: Displays real-time array comparisons and swaps using colored bars (White = Unsorted, Red = Current Comparison, Green = Selected/Sorted).

Audio Feedback: Dynamically plays sound effects (beep.wav) with pitch adjusted according to the height of the elements being sorted.

Procedural Generation: Generates random array datasets on startup.

Custom Graphics Rendering: Custom bar alignment and ground placement powered by Raylib.

🛠️ Tech Stack & Prerequisites
Language: C (C99)

Graphics & Audio Library: Raylib

Platform: Linux / macOS (uses <unistd.h> for usleep)

🚀 Getting Started
1. Prerequisites
Ensure you have a C compiler (gcc or clang) and Raylib installed on your system.

macOS (via Homebrew):

Bash
brew install raylib
Ubuntu/Debian:

Bash
sudo apt install libraylib-dev
2. Assets
Make sure you have an audio file named beep.wav in the root directory of the project, as the sorting sound effects depend on it.

3. Compilation & Execution
Compile the code linking the Raylib library:

Bash
# Using GCC
gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o sort_visualizer

# Execute the binary
./sort_visualizer
(Note: On macOS, you can simply run gcc main.c -lraylib -o sort_visualizer)
